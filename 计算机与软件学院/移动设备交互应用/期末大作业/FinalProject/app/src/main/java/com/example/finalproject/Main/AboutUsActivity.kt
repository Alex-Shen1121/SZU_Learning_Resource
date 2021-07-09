package com.example.finalproject.Main

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.finalproject.BaseActivity
import com.example.finalproject.R
import kotlinx.android.synthetic.main.activity_about_us.*

class AboutUsActivity : BaseActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_about_us)
        supportActionBar?.hide()

        back.setOnClickListener(){
            finish()
        }
    }
}