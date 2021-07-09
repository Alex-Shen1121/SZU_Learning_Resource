package com.example.experiment3.Admin

import android.content.Intent
import android.graphics.Color
import android.os.Bundle
import android.view.Gravity
import android.view.View
import android.widget.AdapterView
import android.widget.AdapterView.OnItemSelectedListener
import android.widget.ArrayAdapter
import android.widget.TextView
import com.example.experiment3.BaseActivity
import com.example.experiment3.R
import kotlinx.android.synthetic.main.activity_admin_menu.*


class AdminMenu : BaseActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_admin_menu)
        supportActionBar?.hide()
        //设置个人信息
        var user_name = "用户名:"
        var user_identity = "身份:"
        /*user_name += intent.getStringExtra("userName")
        user_identity += intent.getStringExtra("userIdentity")*/
        val prefs=getSharedPreferences("LoginUI.LoginActivity", MODE_PRIVATE)
        user_name+=prefs.getString("account","null")
        user_identity+=prefs.getString("identity","null")
        userName.text = user_name
        userIdentity.text = user_identity

        //设置强制下线
        ForceOffline.setOnClickListener() {
            val intent = Intent("com.example.experiment3.FORCE_OFFLINE")
            intent.setPackage(packageName)
            sendBroadcast(intent)
        }

        val mItems = arrayOf("重要通知", "学术讲座", "深大新闻")
        val adapter = ArrayAdapter(this, android.R.layout.simple_spinner_item, mItems)
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        spinner.adapter = adapter

        spinner.onItemSelectedListener = object : OnItemSelectedListener {
            override fun onItemSelected(parent: AdapterView<*>?, view: View, pos: Int, id: Long) {
                // TODO
                val tv = view as TextView
                tv.setTextColor(Color.BLUE)
                tv.textSize = 20f
                tv.gravity = Gravity.CENTER
            }

            override fun onNothingSelected(parent: AdapterView<*>) {
                // TODO

            }
        }

        addInform.setOnClickListener() {
            val intent = Intent(this, AdminAddInform::class.java)
            intent.putExtra("column", spinner.selectedItem.toString())
            intent.putExtra("userName", user_name)
            intent.putExtra("userIdentity", user_identity)
            startActivity(intent)
        }

    }

}
