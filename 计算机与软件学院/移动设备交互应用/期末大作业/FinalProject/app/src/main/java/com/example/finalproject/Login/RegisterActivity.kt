package com.example.finalproject.Login

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toast
import com.example.finalproject.BaseActivity
import com.example.finalproject.R
import kotlinx.android.synthetic.main.activity_register.*
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

class RegisterActivity : BaseActivity() {
    private val accountList = ArrayList<String>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_register)
        supportActionBar?.hide()

        setAccountList()

        register.setOnClickListener() {
            val name = accountEdit.text.toString()
            val password1 = passwordEdit.text.toString()
            val password2 = passwordCheckEdit.text.toString()
            if (name == "" || password1 == "" || password2 == "") {
                passwordEdit.text = null
                passwordCheckEdit.text = null
                Toast.makeText(this, "请正确输入信息", Toast.LENGTH_SHORT).show()
            } else if (accountList.contains(name)) {
                Toast.makeText(this, "该用户名已存在，请重新输入", Toast.LENGTH_SHORT).show()
                passwordEdit.text = null
                passwordCheckEdit.text = null
                accountEdit.text = null
            }
            else if(password1!=password2){
                Toast.makeText(this, "两次密码不一致，请重新输入", Toast.LENGTH_SHORT).show()
                passwordEdit.text = null
                passwordCheckEdit.text = null
            }
            else{
                val output = openFileOutput("account_password.txt", MODE_APPEND)
                val writer = BufferedWriter(OutputStreamWriter(output))
                writer.use {
                    it.write(name+'\n')
                    it.write(password1+'\n')
                }
                Toast.makeText(this, "注册成功", Toast.LENGTH_SHORT).show()
                finish()
            }
        }
    }

    private fun setAccountList() {
        val input = openFileInput("account_password.txt")
        val reader = BufferedReader(InputStreamReader(input))
        var line = 0
        reader.use {
            reader.forEachLine {
                line += 1
                if (line % 2 == 1)
                    accountList.add(it)
            }
        }
    }
}