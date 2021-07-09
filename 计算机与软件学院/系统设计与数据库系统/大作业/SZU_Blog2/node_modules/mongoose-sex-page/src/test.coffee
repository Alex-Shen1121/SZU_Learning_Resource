assert        = require 'assert'
Promise       = require 'bluebird'
mongoose      = require 'mongoose'
deepPopulate  = require('mongoose-deep-populate')(mongoose)
P             = require '../index'
{ ObjectId }  = mongoose.Schema.Types

mongoose.Promise = Promise

ASchema = new mongoose.Schema
  name: String
  age: Number
A = mongoose.model 'A', ASchema

BSchema = new mongoose.Schema
  name: String
  age: Number
B = mongoose.model 'B', BSchema

CSchema = new mongoose.Schema
  name: String
  age: Number
  b: type: ObjectId, ref: 'B'
C = mongoose.model 'C', CSchema

TestSchema = new mongoose.Schema
  name: String
  age: Number
  a: type: ObjectId, ref: 'A'
  c: type: ObjectId, ref: 'C'
TestSchema.plugin deepPopulate
Test = mongoose.model 'Test', TestSchema

TEST_CASES =

  infinite: ->
    P Test
      .infinite true
      .exec()

  config: ->
    P()
      .config
        size: 8
        display: 3
        size_name: 'size'
        page_name: 'page'
        light: false

  simple: ->
    P Test
      .simple true
      .exec()

  inject: ->
    o = # like req.query
      page: 5
      size: 10
    P Test
      .inject o
      .exec()

  extend: ->
    P Test
      .find()
      .select 'name a c' # exclude 'age'
      .page 1
      .size 5
      .sort age: -1
      .extend 'deepPopulate', ['a', 'c', 'c.b'], populate: 'c.b': select: 'name'

  populate: ->
    P Test
      .find()
      .select 'name a c'
      .page 1
      .size 10
      .display 5
      .sort age: -1
      .populate 'a', 'name' # let a only select name
      .populate 'c'

logger = (m) ->
   console.log "[mongoose-sex-page]: #{m}"

mongoose
  .connect 'mongodb://localhost/pagnation', useMongoClient: true
  .then (db) ->
     A.create name: 'A', age: 1
      .bind {}
      .then (@a) ->
        B.create name: 'B', age: 2
      .then (b) ->
        C.create name: 'C', age: 3, b: b.id
      .then (c) ->
        tests = for i in [1..100] # [1, 100]
           name: "Test#{i}", age: i, a: @a, c: c
        Test.create tests
      .then ->
        TEST_CASES.extend().exec()
          .then ({page, size, total, records, pages}) ->
            assert.equal page, 1
            assert.equal size, 5
            assert.equal total, 100
            assert.equal records.length, 5
            assert.equal pages, 100/5
            assert.equal typeof records[0].a, 'object'
            assert.equal typeof records[0].c, 'object'
            assert.equal typeof records[0].c.b, 'object'
            assert.equal records[0].c.b.age, undefined
      .then ->
        TEST_CASES.populate().exec()
          .then ({page, size, total, records, pages}) ->
            assert.equal page, 1
            assert.equal size, 10
            assert.equal total, 100
            assert.equal records.length, 10
            assert.equal pages, 100/10
            assert.equal typeof records[0].a, 'object'
            assert.equal typeof records[0].c, 'object'
            assert.equal records[0].a.age, undefined
      .then ->
        TEST_CASES
          .extend()
          .exec (e, {page, size, total, records, pages}) ->
            throw e if e?
            assert.equal page, 1
            assert.equal size, 5
            assert.equal total, 100
            assert.equal records.length, 5
            assert.equal pages, 100/5
            assert.equal typeof records[0].a, 'object'
            assert.equal typeof records[0].c, 'object'
            assert.equal typeof records[0].c.b, 'object'
            assert.equal records[0].c.b.age, undefined
      .then ->
        TEST_CASES
          .populate()
          .exec (e, {page, size, total, records, pages}) ->
            throw e if e?
            assert.equal page, 1
            assert.equal size, 10
            assert.equal total, 100
            assert.equal records.length, 10
            assert.equal pages, 100/10
            assert.equal typeof records[0].a, 'object'
            assert.equal typeof records[0].c, 'object'
            assert.equal records[0].a.age, undefined
      .then ->
        TEST_CASES
          .config()
        TEST_CASES
          .simple()
          .then (results) ->
            assert.equal results.length == 8, true
            assert.equal results.length > 0, true
      .then ->
        TEST_CASES
          .inject()
          .then (result) ->
            assert.equal result.records.length == 10, true
            assert.equal result.page == 5, true
            assert.equal result.display.length == 3, true
      .then ->
        TEST_CASES
          .infinite()
          .then (result) ->
            assert.equal result.records.length, 100
      .then ->
         logger 'tests passed'
      .catch (e) ->
        throw e
      .finally ->
        Test.remove()
          .then ->
            A.remove()
          .then ->
            B.remove()
          .then ->
            C.remove()
          .then ->
            db.close()
          .catch (e)->
            db.close()
            throw e
  .catch (e) ->
    throw e
