package com.example.experiment2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_local_news.*

class LocalNews : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_local_news)
        supportActionBar?.hide()
        val Title: String? =intent.getStringExtra("Title")
        val Content: String?=intent.getStringExtra("Content")
        LocalTitle.text=Title
        LocalContent.text=Content
    }
}