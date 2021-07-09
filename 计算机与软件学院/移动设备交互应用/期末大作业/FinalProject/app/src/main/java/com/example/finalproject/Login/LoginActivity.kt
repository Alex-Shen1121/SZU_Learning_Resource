package com.example.finalproject.Login

import android.content.Context
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toast
import androidx.appcompat.app.AlertDialog
import com.example.finalproject.BaseActivity
import com.example.finalproject.Main.MainPage
import com.example.finalproject.R
import kotlinx.android.synthetic.main.activity_login.*
import java.io.*

class LoginActivity : BaseActivity() {

    private val accountList = mutableMapOf<String, String>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_login)
        supportActionBar?.hide()
        //记住密码功能
        val prefs = getPreferences(Context.MODE_PRIVATE)
        val isRemember = prefs.getBoolean("remember_password", false)
        if (isRemember) {
            val account = prefs.getString("account", "")
            val password = prefs.getString("password", "")

            accountEdit.setText(account)
            passwordEdit.setText(password)
            rememberPass.isChecked = true
        }

        //加入默认账号密码
        //账号：admin 密码：123456
        addDefaultAccount()

        login.setOnClickListener() {
            //设置正确账号密码Map
            setAccountList()
            val account = accountEdit.text.toString()
            val password = passwordEdit.text.toString()
            //账号密码匹配成功
            if (accountList[account] == password) {
                Toast.makeText(this, "登陆成功", Toast.LENGTH_SHORT).show()
                val editor = prefs.edit()
                if (rememberPass.isChecked) {
                    editor.putBoolean("remember_password", true)
                    editor.putString("account", account)
                    editor.putString("password", password)
                } else {
                    editor.clear()
                }
                val intent = Intent(this, MainPage::class.java)
                startActivity(intent)
                editor.apply()
                finish()

            } else {
                AlertDialog.Builder(this).apply {
                    setTitle("登陆失败")
                    setMessage("请重新检查用户名与密码。\n或者联系管理员。")
                    setCancelable(false)
                    setPositiveButton("OK") { _, _ -> }
                    show()
                }
                passwordEdit.text = null
            }
        }

        register.setOnClickListener() {
            val intent = Intent(this, RegisterActivity::class.java)
            startActivity(intent)
        }
    }

    //设置正确账号map表
    private fun setAccountList() {
        val input = openFileInput("account_password.txt")
        val reader = BufferedReader(InputStreamReader(input))
        var line = 0
        val account = ArrayList<String>()
        val password = ArrayList<String>()
        reader.use {
            reader.forEachLine {
                line += 1
                if (line % 2 == 1)
                    account.add(it)
                else if (line % 2 == 0)
                    password.add(it)
            }
        }
        for (i in account.indices) {
            accountList[account[i]] = password[i]
        }
    }

    //初始化默认账号
    private fun addDefaultAccount() {
        //判断文件是否存在
        val file = File("/data/data/com.example.finalproject/files/account_password.txt")
        if (!file.exists()) {
            val output = openFileOutput("account_password.txt", MODE_APPEND)
            val writer = BufferedWriter(OutputStreamWriter(output))
            writer.use {
                it.write("admin\n")
                it.write("123456\n")
            }
        }
    }

}