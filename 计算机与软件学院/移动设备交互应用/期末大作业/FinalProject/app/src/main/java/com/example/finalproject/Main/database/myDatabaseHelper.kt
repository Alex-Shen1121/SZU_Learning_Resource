package com.example.finalproject.Main.database

import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

class myDatabaseHelper(val context: Context,name:String,version:Int):
    SQLiteOpenHelper(context,name,null,version){

    private val createTrashTable="create table TrashTable ("+
            " name text primary key,"+
            "type text)"

    override fun onCreate(db: SQLiteDatabase?) {
        db?.execSQL(createTrashTable)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        TODO("Not yet implemented")
    }
}