Promise = require 'bluebird'

friendly = (total, display, current) ->
  left = 1
  right = total
  pages = []
  if total >= display + 1
    half = Math.ceil display / 2
    if current > half and current < total - (half - 1)
      if display % 2 is 0
        left = current - half
      else
        left = current - half + 1
      right = current + half - 1
    else
      if current <= half
        left = 1
        right = display
      else
        right = total
        left = total - (display - 1)
  while left <= right
    pages.push left
    left++
  return pages

class Pagnation

    __size__: 20
    __display__: 0
    __size_name__: 'size'
    __page_name__: 'page'
    __light__: false
    __infinite__: false

    config: (conf) ->
      Pagnation.__size__ = conf.size or 20
      Pagnation.__display__ = conf.display or 0
      Pagnation.__size_name__ = conf.size_name or 'size'
      Pagnation.__page_name__ = conf.page_name or 'page'
      Pagnation.__light__ = conf.light or false
      return

    constructor: (@model) ->

    find: (@condition) -> @

    select: (@selection) -> @

    populate: (population...) ->
      @populations ?= []
      @populations.push population
      return @

    sort: (@sorting) -> @

    page: (@index) -> @

    size: (@count) -> @

    display: (@friend) -> @

    simple: (@light) -> @

    extend: (name, params...) ->
      @extends?= []
      @extends.push
        name: name
        params: params
      @

    inject: (o) ->
      @index = +o[Pagnation.__page_name__]
      @count = +o[Pagnation.__size_name__]
      @

    infinite: (no_limit) ->
      @no_limit = no_limit
      @

    exec: (fn)->
      @no_limit ?= Pagnation.__infinite__
      @index ?= 1
      @count ?= Pagnation.__size__
      @friend ?= Pagnation.__display__
      @light ?= Pagnation.__light__
      @condition ?= {}
      skip = (+@index - 1) * +@count
      promiseCount = @model
        .where @condition
        .count()
        .exec()

      if @no_limit
        promiseRecords = @model
          .find @condition
      else
        promiseRecords = @model
          .find @condition
          .skip skip
          .limit +@count

      if @extends?
        for extend in @extends
          if @model[extend.name]? then promiseRecords = promiseRecords[extend.name] extend.params...

      if @selection? then promiseRecords = promiseRecords.select @selection

      if @sorting? then promiseRecords = promiseRecords.sort @sorting

      if @populations?
        for population in @populations
          promiseRecords = promiseRecords.populate population...

      unless @light
        Promise
          .all [ promiseCount, promiseRecords.exec() ]
          .bind @
          .then ([total, records]) ->
              final =
                page: +@index
                size: +@count
                total: total
                records: records
                pages: Math.ceil total / +@count

              unless +@friend is 0 then final.display = friendly final.pages, +@friend, +@index
              if fn? and typeof fn is 'function'
                fn null, final
              else
                final
          .catch (err) ->
            if fn? and typeof fn is 'function'
              fn err, null
            else
              throw err
      else
        promiseRecords
          .then (records) ->
            if fn? and typeof fn is 'function'
              fn null, records
            else
              records
          .catch (err) ->
            if fn? and typeof fn is 'function'
              fn err, null
            else
              throw err

module.exports = Pagnation
