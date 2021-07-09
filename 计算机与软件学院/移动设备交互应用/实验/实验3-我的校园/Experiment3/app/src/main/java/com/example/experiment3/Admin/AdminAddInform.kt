package com.example.experiment3.Admin

import android.content.Intent
import android.graphics.Color
import android.os.Bundle
import android.view.Gravity
import android.view.View
import android.widget.AdapterView
import android.widget.ArrayAdapter
import android.widget.TextView
import android.widget.Toast
import com.example.experiment3.BaseActivity
import com.example.experiment3.R
import kotlinx.android.synthetic.main.activity_admin_add_inform.*
import kotlinx.android.synthetic.main.activity_admin_menu.*
import kotlinx.android.synthetic.main.activity_admin_menu.userIdentity
import kotlinx.android.synthetic.main.activity_admin_menu.userName
import java.io.BufferedWriter
import java.io.OutputStreamWriter

class AdminAddInform : BaseActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_admin_add_inform)
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
        ForceOffline1.setOnClickListener() {
            val intent = Intent("com.example.experiment3.FORCE_OFFLINE")
            intent.setPackage(packageName)
            sendBroadcast(intent)
        }

        //设置栏目
        var column_title = "修改栏目："
        column_title += intent.getStringExtra("column")
        columnTitle.text = column_title

        //编辑布局
        when (intent.getStringExtra("column")) {
            "重要通知" -> {
                informType.visibility = View.VISIBLE
                informTitle.visibility = View.VISIBLE
                blank3.visibility = View.VISIBLE
                //设置通知类别下拉框
                val mItems = arrayOf("教务", "科研", "行政", "学工", "生活")
                val adapter = ArrayAdapter(this, android.R.layout.simple_spinner_item, mItems)
                adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
                informType.adapter = adapter
                informType.onItemSelectedListener = object : AdapterView.OnItemSelectedListener {
                    override fun onItemSelected(
                        parent: AdapterView<*>?,
                        view: View,
                        pos: Int,
                        id: Long
                    ) {
                        // TODO
                        val tv = view as TextView
                        tv.setTextColor(Color.BLACK)
                        tv.textSize = 20f
                        tv.gravity = Gravity.LEFT
                    }

                    override fun onNothingSelected(parent: AdapterView<*>) {
                        // TODO
                    }
                }

            }
            "学术讲座" -> {
                dateTime.visibility = View.VISIBLE
                place.visibility = View.VISIBLE
                blank.visibility = View.VISIBLE
                blank2.visibility = View.VISIBLE
                informTitle.visibility = View.VISIBLE
            }
            "深大新闻" -> {
                informTitle.visibility = View.VISIBLE
            }
        }

        //设置提交事件
        //修改文档
        submitInform.setOnClickListener() {
            when (intent.getStringExtra("column")) {
                "重要通知" -> {
                    val output = openFileOutput("important_information.txt", MODE_APPEND)
                    val writer = BufferedWriter(OutputStreamWriter(output))
                    val type = informType.selectedItem.toString()
                    val content = informTitle.text.toString()
                    //如果未填写，做出反馈
                    if (content == "") {
                        Toast.makeText(this, "请正确输入内容", Toast.LENGTH_SHORT).show()
                        return@setOnClickListener
                    }
                    writer.use {
                        it.write(type)
                        it.newLine()
                        it.write(content)
                        it.newLine()
                    }
                    val intent = Intent(this, AdminMenu::class.java)
                    startActivity(intent)
                    finish()
                }
                "学术讲座" -> {
                    val output = openFileOutput("academic_lecture.txt", MODE_APPEND)
                    val writer = BufferedWriter(OutputStreamWriter(output))
                    val date = dateTime.text.toString()
                    val title = informTitle.text.toString()
                    val place = place.text.toString()
                    //如果未填写，做出反馈
                    if (date == "" || title == "" || place == "") {
                        Toast.makeText(this, "请正确输入内容", Toast.LENGTH_SHORT).show()
                        return@setOnClickListener
                    }
                    writer.use {
                        it.write(date)
                        it.newLine()
                        it.write(title)
                        it.newLine()
                        it.write(place)
                        it.newLine()
                    }
                    val intent = Intent(this, AdminMenu::class.java)
                    startActivity(intent)
                    finish()
                }
                "深大新闻" -> {
                    val output = openFileOutput("szu_news.txt", MODE_APPEND)
                    val writer = BufferedWriter(OutputStreamWriter(output))
                    val title = informTitle.text.toString()
                    //如果未填写，做出反馈
                    if (title == "") {
                        Toast.makeText(this, "请正确输入内容", Toast.LENGTH_SHORT).show()
                        return@setOnClickListener
                    }
                    writer.use {
                        it.write(title)
                        it.newLine()
                    }
                    val intent = Intent(this, AdminMenu::class.java)
                    startActivity(intent)
                    finish()
                }
            }
        }


    }
}