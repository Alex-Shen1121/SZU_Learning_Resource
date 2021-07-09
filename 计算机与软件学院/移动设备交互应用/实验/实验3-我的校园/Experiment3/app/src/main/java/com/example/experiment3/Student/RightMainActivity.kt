package com.example.experiment3.Student

import android.os.Bundle
import com.example.experiment3.BaseActivity
import com.example.experiment3.R
import kotlinx.android.synthetic.main.activity_right_main.*

class RightMainActivity : BaseActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_right_main)
        val fragment = RightMainFrag as RightFragment
        supportActionBar?.hide()
        fragment.refresh()
    }
}