package com.example.experiment2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class Health : AppCompatActivity() {
    private val verticalNews = ArrayList<vertical_news>()

    private val titleMenu = ArrayList<TitleMenu>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_health)
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
        val recyclerView: RecyclerView = findViewById(R.id.recyclerViewForHealth)
        recyclerView.layoutManager = layoutManager
        val adapter = vertical_newsAdapter(verticalNews)
        recyclerView.adapter = adapter
    }

    private fun initVerticalNewsMenu() {
        repeat(1) {
            verticalNews.add(
                vertical_news(
                    R.drawable.healthnews1,
                    "武汉展示抗疫成果",
                    "www.jkb.com.cn",
                    "2020-10-22 11:35:53",
                    "http://www.jkb.com.cn/news/publicHealth/2020/1020/479035.html",
                    " 10月18日，“人民至上 生命至上——抗击新冠肺炎疫情专题展览”在湖北省武汉客厅·中国文化展览中心A馆举行，现场还原了全国各地援鄂医疗队员支援武汉的场景。人民图片供图"
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.healthnews2,
                    "抗疫队员回访",
                    "www.jkb.com.cn",
                    "2020-10-20 01:38:08",
                    "http://www.jkb.com.cn/news/publicHealth/2020/1018/478991.html",
                    ""
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.healthnews3,
                    "防疫物资博览会开幕",
                    "www.jkb.com.cn",
                    "2020-10-16 02:18:54",
                    "http://www.jkb.com.cn/news/publicHealth/2020/1016/478974.html",
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