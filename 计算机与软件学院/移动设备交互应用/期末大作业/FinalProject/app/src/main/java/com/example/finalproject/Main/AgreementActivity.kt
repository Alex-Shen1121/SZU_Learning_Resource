
package com.example.finalproject.Main

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.finalproject.BaseActivity
import com.example.finalproject.R
import kotlinx.android.synthetic.main.activity_about_us.*

class AgreementActivity : BaseActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_agreement)
        supportActionBar?.hide()

        back.setOnClickListener(){
            finish()
        }
    }
}