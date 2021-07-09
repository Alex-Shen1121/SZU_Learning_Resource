package com.example.experiment3.LoginUI

import android.content.Context
import android.content.Intent
import android.os.Bundle
import android.widget.Toast
import androidx.appcompat.app.AlertDialog
import com.example.experiment3.Admin.AdminMenu
import com.example.experiment3.BaseActivity
import com.example.experiment3.R
import com.example.experiment3.Student.StudentMenu
import kotlinx.android.synthetic.main.activity_login.*
import java.io.*

class LoginActivity : BaseActivity() {

    val accountList = mutableMapOf<String, String>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_login)
        supportActionBar?.hide()
        //记住密码功能
        val prefs=getPreferences(Context.MODE_PRIVATE)
        val isRemember=prefs.getBoolean("remember_password",false)
        if(isRemember){
            val account=prefs.getString("account","")
            val password=prefs.getString("password","")
            accountEdit.setText(account)
            passwordEdit.setText(password)
            rememberPass.isChecked=true
        }

        //加入默认账号密码
        //管理员账号：admin 密码：123456
        //学生账号：admin 密码：123456
        addDefaultAccount()
        addDefaultNews()

        login.setOnClickListener() {
            //设置正确账号密码Map
            setAccountList()
            val account = accountEdit.text.toString()
            val password = passwordEdit.text.toString()
            //账号密码匹配成功
            if (accountList[account] == password) {
                Toast.makeText(this, "登陆成功", Toast.LENGTH_SHORT).show()
                val editor=prefs.edit()
                if(rememberPass.isChecked){
                    editor.putBoolean("remember_password",true)
                    editor.putString("account",account)
                    editor.putString("password",password)
                }else{
                    editor.clear()
                }
                //进入管理员界面
                //有且仅有一个管理员账号
                if (account == "admin") {
                    editor.putString("identity","管理员")
                    editor.apply()
                    val intent = Intent(this, AdminMenu::class.java)
                    startActivity(intent)
                    finish()
                }
                //其他全部进入学生界面
                else {
                    editor.putString("identity","学生")
                    editor.apply()
                    val intent = Intent(this, StudentMenu::class.java)
                    startActivity(intent)
                    finish()
                }
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
        val file = File("/data/data/com.example.experiment3/files/account_password.txt")
        if (!file.exists()) {
            val output = openFileOutput("account_password.txt", MODE_APPEND)
            val writer = BufferedWriter(OutputStreamWriter(output))
            writer.use {
                it.write("admin")
                it.newLine()
                it.write("123456")
                it.newLine()
                it.write("student")
                it.newLine()
                it.write("123456")
                it.newLine()
            }
        }
    }


    private fun addDefaultNews() {
        //初始化《重要通知》
        var file = File("/data/data/com.example.experiment3/files/important_information.txt")
        if (!file.exists()) {
            val output = openFileOutput("important_information.txt", MODE_APPEND)
            val writer = BufferedWriter(OutputStreamWriter(output))
            writer.use {
                it.write("行政\n")
                it.write("2020年预聘-长聘制教师岗位晋升各学科评议组推荐人选申报材料公示\n")
                it.write("教务\n")
                it.write("关于本科生火车票优惠卡补办的通知\n")
                it.write("行政\n")
                it.write("关于参加深圳大学博物馆（筹）聘任仪式暨馆藏艺术作品展活动开幕式的通知\n")
                it.write("教务\n")
                it.write("关于2020级本科新生登陆“学信网”查询学籍注册信息的通知\n")
                it.write("行政\n")
                it.write("2020年度职称评聘各学科评议组推荐人选申报材料公示\n")
                it.write("学工\n")
                it.write("关于学分学费第二次银行批扣时间安排的通知\n")
                it.write("行政\n")
                it.write("2020年度博士后职称评审学科评议组推荐人选申报材料公示\n")
            }
        }
        //初始化《学术讲座》
        file = File("/data/data/com.example.experiment3/files/academic_lecture.txt")
        if (!file.exists()) {
            val output = openFileOutput("academic_lecture.txt", MODE_APPEND)
            val writer = BufferedWriter(OutputStreamWriter(output))
            writer.use {
                it.write("2020/12/4\n")
                it.write("2020年高水平学术报告二十四：【大师讲座】中国工程院杨永斌院士学术报告\n")
                it.write("致工楼\n")
                it.write("2020/12/4\n")
                it.write("深圳大学城乡规划系列—名师讲堂|国土空间规划再思考\n")
                it.write("建规学院\n")
                it.write("2020/12/4\n")
                it.write("高等研究院数学报告--Contour integral solutions of linear......\n")
                it.write("其他\n")
                it.write("2020/12/6\n")
                it.write("深大讲学计划第3讲 港澳论坛第27讲\n")
                it.write("其他\n")
            }
        }
        //初始化《深大新闻》
        file = File("/data/data/com.example.experiment3/files/szu_news.txt")
        if (!file.exists()) {
            val output = openFileOutput("szu_news.txt", MODE_APPEND)
            val writer = BufferedWriter(OutputStreamWriter(output))
            writer.use {
                it.write("校党委理论学习中心组召开理论学习会 学习传达习近平总书记近期重要讲话精神及重要会议精神\n")
                it.write("校党委书记刘洪一出席深圳青年发展型城市建设学术研讨会暨课题开题会并作主旨发言\n")
                it.write("深圳大学召开学习贯彻习近平总书记出席深圳经济特区建立40周年庆祝大会和视察广东、深圳重要讲话和重要指示精神宣讲大会\n")
                it.write("深圳大学中国特色社会主义先行示范区残疾人事业发展研究中心（基地）揭牌成立\n")
                it.write("深大微众金融科技学院成立一周年 金融科技实验室揭牌 12名学子获首届“微众奖学金”，21位专家获聘“业界导师”\n")
                it.write("教育部直属机关党员干部“不忘初心、牢记使命”专题实践培训班在我校开班\n")
                it.write("探索交叉学科建设 激发学生跨界思考能力 深圳大学艺术与科技跨界创新实验室揭牌成立\n")
                it.write("我校聘任全国政协委员、中国职业技术教育学会会长、教育部原副部长鲁昕为客座教授、首席经济学家\n")
                it.write("喜讯！我校在第六届中国国际“互联网+”大学生创新创业大赛总决赛中成绩创新高！\n")
            }
        }
    }
}