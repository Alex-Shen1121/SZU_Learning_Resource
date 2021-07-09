package com.example.finalproject.WelcomePage

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import androidx.core.view.ViewCompat
import androidx.core.view.ViewPropertyAnimatorListener
import com.example.finalproject.Login.LoginActivity
import com.example.finalproject.R
import kotlinx.android.synthetic.main.activity_welcome.*

class WelcomeActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_welcome)
        supportActionBar?.hide()

        //设置图片动画
        ViewCompat.animate(imageView).apply {
            //缩放，变成1.0倍
            scaleX(1.0f)
            scaleY(1.0f)
            //动画时常1秒
            duration = 1000
            //动画监听
            setListener(object : ViewPropertyAnimatorListener {
                override fun onAnimationEnd(view: View?) { //动画结束
                    //进入主界面，并结束掉该页面
                    startActivity(Intent(this@WelcomeActivity, LoginActivity::class.java))
                    finish()
                }

                override fun onAnimationCancel(view: View?) {
                }

                override fun onAnimationStart(view: View?) {
                }
            })
        }
    }
}