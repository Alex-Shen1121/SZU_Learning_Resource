package com.example.experiment2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class Sport : AppCompatActivity() {
    private val verticalNews = ArrayList<vertical_news>()

    private val titleMenu = ArrayList<TitleMenu>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_sport)
        supportActionBar?.hide()

        //菜单栏配置
        initTitleMenu()
        val layoutManager1 = LinearLayoutManager(this)
        val recyclerView1: RecyclerView = findViewById(R.id.recyclerViewForTitle)
        layoutManager1.orientation = LinearLayoutManager.HORIZONTAL
        recyclerView1.layoutManager = layoutManager1
        val adapter1 = TitleMenuAdapter(titleMenu)
        recyclerView1.adapter = adapter1

        //新闻栏配置
        initVerticalNewsMenu()
        val layoutManager = LinearLayoutManager(this)
        val recyclerView: RecyclerView = findViewById(R.id.recyclerViewForSport)
        recyclerView.layoutManager = layoutManager
        val adapter = vertical_newsAdapter(verticalNews)
        recyclerView.adapter = adapter
    }

    private fun initVerticalNewsMenu() {
        repeat(2) {
            verticalNews.add(
                vertical_news(
                    R.drawable.sportnews1,
                    "新浪直击苏宁全队疯狂庆祝",
                    "sports.sina.com.cn",
                    "2020.11.02 18:49:04",
                    "http://slide.sports.sina.com.cn/n_j/slide_2_789_256958.html#p=1",
                    "\n" +
                            "2020年11月2日，中超联赛，上海上港迎战江苏苏宁，比赛在苏州市体育中心举行。新浪体育李欣/摄（发自苏州）"
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.sportnews2,
                    "中超-朱建荣救主姚翰林失点 点球大战黄海8-7卓尔",
                    "sports.sina.com.cn",
                    "2020年11月02日 17:31",
                    "https://sports.sina.com.cn/china/j/2020-11-02/doc-iiznezxr9495102.shtml",
                    ""
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.sportnews3,
                    "富保罗客户聚会！詹眉领衔追梦特雷杨在列 这要凑成一队真无敌了",
                    "sports.sina.com.cn",
                    "2020.10.31 08:23:28",
                    "http://slide.sports.sina.com.cn/k/slide_2_786_256798.html#p=1",
                    ""
                )
            )
        }
    }

    private fun initTitleMenu() {
        titleMenu.add(TitleMenu("Business", R.drawable.business))
        titleMenu.add(TitleMenu("Entertainment", R.drawable.entertainment))
        titleMenu.add(TitleMenu("Health", R.drawable.health))
        titleMenu.add(TitleMenu("Science", R.drawable.science))
        titleMenu.add(TitleMenu("Sport", R.drawable.sport))
        titleMenu.add(TitleMenu("Game", R.drawable.game))
    }
}