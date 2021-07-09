package com.example.experiment2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class Entertainment : AppCompatActivity() {
    private val verticalNews = ArrayList<vertical_news>()

    private val titleMenu = ArrayList<TitleMenu>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_business)
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
        val recyclerView: RecyclerView = findViewById(R.id.recyclerViewForBusiness)
        recyclerView.layoutManager = layoutManager
        val adapter = vertical_newsAdapter(verticalNews)
        recyclerView.adapter = adapter
    }

    private fun initVerticalNewsMenu() {
        repeat(2){
            verticalNews.add(
                vertical_news(
                    R.drawable.entertainmentnews1,
                    "黄磊大女儿多多近照曝光 穿白衬衣牛仔裤化淡妆气质超好",
                    "ent.sina.com.cn",
                    "2020.10.24 12:08:43",
                    "http://slide.ent.sina.com.cn/z/v/slide_4_704_347172.html#p=1",
                    "新浪娱乐讯 近日，黄磊大女儿黄多多近照曝光，身穿白衬衣牛仔裤，化着小淡妆，气质超好。"
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.entertainmentnews2,
                    "娜扎白色羊绒大衣干净素雅 长发红唇阳光下灿笑美成画",
                    "ent.sina.com.cn",
                    "2020.10.24 09:09:32",
                    "http://slide.ent.sina.com.cn/star/slide_4_704_347156.html#p=1",
                    "新浪娱乐讯 10月23日，娜扎最新写真曝光，穿白色羊绒大衣干净素雅，长发红唇阳光下灿笑美成画。"
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.entertainmentnews3,
                    "金瀚张芷溪官宣恋情：没偶像包袱没什么不敢承认",
                    "ent.sina.com.cn",
                    "2020年10月24日 15:13",
                    "https://ent.sina.com.cn/w/2020-10-24/doc-iiznctkc7420253.shtml",
                    "新浪娱乐讯 10月24日，金瀚[微博]发文承认与张芷溪[微博]的恋情：“没什么偶像包袱，没什么不敢承认。”女方也转发微博大胆认爱：“当我听你说的那句，跟着我吧，就决定一直走下去。”此前两人外出吃饭被拍，男方搂住女方肩膀，还用手上下揉捏其手臂，动作相当亲密，恋情疑似曝光。祝福！"
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.entertainmentnews4,
                    "王一博《风起洛阳》官宣，再演古装剧，虽男二却力压男主",
                    "www.dzyule.com",
                    "2020-10-23 11:30:50",
                    "http://news.dzyule.com/nd/2020/1023/34284.html",
                    ""
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.entertainmentnews5,
                    "明明是一部喜剧，却看到眼泪止不住啊",
                    "www.dzyule.com",
                    "2020-10-16 11:19:23",
                    "http://news.dzyule.com/rb/2020/1016/34232.html",
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