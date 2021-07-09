package com.example.experiment2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.StaggeredGridLayoutManager

class Game : AppCompatActivity() {
    private val flowNews = ArrayList<flow_news>()

    private val titleMenu = ArrayList<TitleMenu>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_game)
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
        initFlowNewsMenu()
        var layoutManager=StaggeredGridLayoutManager(3,StaggeredGridLayoutManager.VERTICAL)
        val recyclerView: RecyclerView = findViewById(R.id.recyclerViewForGame)
        recyclerView.layoutManager = layoutManager
        val adapter = flow_newsAdapter(flowNews)
        recyclerView.adapter = adapter
    }

    private fun initFlowNewsMenu() {
        repeat(5) {
            flowNews.add(
                    flow_news(
                    R.drawable.gamenews1,
                    "《黑神话：悟空》游戏早期概念图 猴子和白龙亮相\n《黑神话：悟空》游戏早期概念图 猴子和白龙亮相\n《黑神话：悟空》游戏早期概念图 猴子和白龙亮相",
                    "www.3dmgame.com",
                    "2020-10-22 11:35:53",
                    "https://www.3dmgame.com/news/202010/3800200.html",
                    "  近日《黑神话：悟空》主美杨奇在Artstation上分享了游戏早期概念图。图中出现了猴子、白龙以及其他妖怪，一起来欣赏下吧！\n" +
                            "\n" +
                            "杨奇表示在该作项目起始阶段，尝试着快速创作了一批概念图。从微观到宏观，描绘出游戏氛围和风格，并将它们剪辑成有背景音乐的视频，此次展示的只是其中的一部分。\n" +
                            "\n" +
                            "《黑神话：悟空》是由游戏科学制作的一款西游题材单机动作RPG，目前仍在制作中。游戏灵感部分来自于《西游记》，将有一个黑暗、粗矿的基调。游戏时长超15小时，敌人类型超百种。\n" +
                            "\n" +
                            "《黑神话：悟空》发售日期尚未公布，未来将登陆PC和主流主机平台，也不排斥可以流畅运行端游的云游戏平台。本作将采用一次性买断制的经典单机付费模式，但未来不排除会有DLC和非数值向的内购。"
                )
            )
            flowNews.add(
                    flow_news(
                    R.drawable.gamenews2,
                    "《战争机器5》XSX输入延迟大幅降低 最高达57%\n《战争机器5》XSX输入延迟大幅降低 最高达57%",
                    "baijiahao.baidu.com",
                    "2020-10-22 08:29:47",
                    "https://baijiahao.baidu.com/s?id=1681212969147287593&wfr=spider&for=pc",
                    ""
                )
            )
            flowNews.add(
                    flow_news(
                    R.drawable.gamenews3,
                    "《赛博朋克2077》角色使用各种语言都能实现口型同步",
                    "www.3dmgame.com",
                    "2020-10-21 00:02:28",
                    "https://www.3dmgame.com/news/202010/3800061.html",
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