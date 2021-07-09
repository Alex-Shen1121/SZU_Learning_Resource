package com.example.experiment3.Student

import android.content.Intent
import android.graphics.Color
import android.net.Uri
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.experiment3.BaseActivity
import com.example.experiment3.R
import com.example.experiment3.Student.RecyclerView.academic_lecture
import com.example.experiment3.Student.RecyclerView.important_inform
import com.example.experiment3.Student.RecyclerView.szu_news
import kotlinx.android.synthetic.main.activity_admin_menu.*
import kotlinx.android.synthetic.main.activity_student_menu.*
import kotlinx.android.synthetic.main.left_frag.*
import kotlinx.android.synthetic.main.left_frag.ForceOffline
import kotlinx.android.synthetic.main.left_frag.userIdentity
import kotlinx.android.synthetic.main.left_frag.userName
import kotlinx.android.synthetic.main.right_frag.*
import java.text.SimpleDateFormat
import java.util.*

class StudentMenu : BaseActivity() {

    var isTwoPane = false

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_student_menu)
        supportActionBar?.hide()
        isTwoPane = findViewById<View>(R.id.StudentRightLayout) != null
        //设置个人信息
        var user_name = "用户名:"
        var user_identity = "身份:"
        /*user_name += intent.getStringExtra("userName")
        user_identity += intent.getStringExtra("userIdentity")*/
        val prefs=getSharedPreferences("LoginUI.LoginActivity", MODE_PRIVATE)
        user_name+=prefs.getString("account", "null")
        user_identity+=prefs.getString("identity", "null")
        userName.text = user_name
        userIdentity.text = user_identity

        //
        important_inform_button.setBackgroundColor(Color.BLUE)
        important_inform_button.setTextColor(Color.WHITE)


        val simpleDateFormat = SimpleDateFormat("yyyy年MM月dd日") // HH:mm:ss
        val date = Date(System.currentTimeMillis())
        leftdate.setText(simpleDateFormat.format(date)+"  本学期第13周（查看校历）")

        //设置强制下线
        ForceOffline.setOnClickListener() {
            val intent = Intent("com.example.experiment3.FORCE_OFFLINE")
            intent.setPackage(packageName)
            sendBroadcast(intent)
        }



        //切换重要通知
        important_inform_button.setOnClickListener() {
            important_inform_button.setBackgroundColor(Color.BLUE)
            important_inform_button.setTextColor(Color.WHITE)
            academic_lecture_button.setBackgroundColor(Color.TRANSPARENT)
            academic_lecture_button.setTextColor(Color.RED)
            szu_news_button.setBackgroundColor(Color.TRANSPARENT)
            szu_news_button.setTextColor(Color.RED)
            importantInformRecyclerView.visibility = View.VISIBLE
            academicLectureRecyclerView.visibility = View.GONE
            szuNewsRecyclerView.visibility = View.GONE
        }


        //切换学术讲座
        academic_lecture_button.setOnClickListener() {
            important_inform_button.setBackgroundColor(Color.TRANSPARENT)
            important_inform_button.setTextColor(Color.RED)
            academic_lecture_button.setBackgroundColor(Color.BLUE)
            academic_lecture_button.setTextColor(Color.WHITE)
            szu_news_button.setBackgroundColor(Color.TRANSPARENT)
            szu_news_button.setTextColor(Color.RED)
            importantInformRecyclerView.visibility = View.GONE
            academicLectureRecyclerView.visibility = View.VISIBLE
            szuNewsRecyclerView.visibility = View.GONE
        }

        //切换深大新闻
        szu_news_button.setOnClickListener() {
            important_inform_button.setBackgroundColor(Color.TRANSPARENT)
            important_inform_button.setTextColor(Color.RED)
            academic_lecture_button.setBackgroundColor(Color.TRANSPARENT)
            academic_lecture_button.setTextColor(Color.RED)
            szu_news_button.setBackgroundColor(Color.BLUE)
            szu_news_button.setTextColor(Color.WHITE)
            importantInformRecyclerView.visibility = View.GONE
            academicLectureRecyclerView.visibility = View.GONE
            szuNewsRecyclerView.visibility = View.VISIBLE
        }

        //进入内部网
        szu_website_button.setOnClickListener() {
            //手机版
            if (!isTwoPane) {
                val intent = Intent(this, RightMainActivity::class.java)
                startActivity(intent)
            }
            //平板版
            else {
                contentLayout.visibility=View.VISIBLE
                right1.textSize = 15F
                right2.textSize = 15F
                right3.textSize = 15F
                right4.textSize = 15F
            }

        }

    }

    //重要通知RecyclerViewAdapter
    class ImportantInformAdapter(private val informList: List<important_inform>) :
        RecyclerView.Adapter<ImportantInformAdapter.ViewHolder>() {

        inner class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
            val importantInformType: TextView = view.findViewById(R.id.type)
            val importantInformTitle: TextView = view.findViewById(R.id.title)
        }

        override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
            val view = LayoutInflater.from(parent.context)
                .inflate(R.layout.important_inform_item, parent, false)
            return ViewHolder(view)
        }

        override fun getItemCount() = informList.size

        override fun onBindViewHolder(holder: ViewHolder, position: Int) {
            var inform = informList[position]
            holder.importantInformTitle.text = inform.title
            holder.importantInformType.text = inform.type
        }
    }

    //学术讲座RecyclerViewAdapter
    class AcademicLectureAdapter(private val informList: List<academic_lecture>) :
        RecyclerView.Adapter<AcademicLectureAdapter.ViewHolder>() {

        inner class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
            val AcademicLectureDate: TextView = view.findViewById(R.id.lecturedate)
            val AcademicLectureTitle: TextView = view.findViewById(R.id.lecturetitle)
            val AcademicLecturePlace: TextView = view.findViewById(R.id.lectureplace)
        }

        override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
            val view = LayoutInflater.from(parent.context)
                .inflate(R.layout.academic_lecture_item, parent, false)
            return ViewHolder(view)
        }

        override fun getItemCount() = informList.size

        override fun onBindViewHolder(holder: ViewHolder, position: Int) {
            var inform = informList[position]
            holder.AcademicLectureTitle.text = inform.title
            holder.AcademicLectureDate.text = inform.date
            holder.AcademicLecturePlace.text = inform.place
        }
    }

    //深大新闻RecyclerViewAdapter
    class SzuNewsAdapter(private val informList: List<szu_news>) :
        RecyclerView.Adapter<SzuNewsAdapter.ViewHolder>() {

        inner class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
            val SzuNewsTitle: TextView = view.findViewById(R.id.newstitle)
        }

        override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
            val view = LayoutInflater.from(parent.context)
                .inflate(R.layout.szu_news_item, parent, false)
            return ViewHolder(view)
        }

        override fun getItemCount() = informList.size

        override fun onBindViewHolder(holder: ViewHolder, position: Int) {
            var inform = informList[position]
            holder.SzuNewsTitle.text = inform.title
        }
    }
}