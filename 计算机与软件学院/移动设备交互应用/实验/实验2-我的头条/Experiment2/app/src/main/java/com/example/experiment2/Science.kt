package com.example.experiment2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class Science : AppCompatActivity() {
    private val verticalNews = ArrayList<vertical_news>()

    private val titleMenu = ArrayList<TitleMenu>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_science)
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
        val recyclerView: RecyclerView = findViewById(R.id.recyclerViewForScience)
        recyclerView.layoutManager = layoutManager
        val adapter = vertical_newsAdapter(verticalNews)
        recyclerView.adapter = adapter
    }

    private fun initVerticalNewsMenu() {
        repeat(3) {
            verticalNews.add(
                vertical_news(
                    R.drawable.sciencenews1,
                    "未来在火星如何上网？马斯克：星链卫星可能用得",
                    "tech.163.com",
                    "2020-10-24 18:07:34",
                    "https://tech.163.com/20/1024/18/FPNLK69Q00097U81.html",
                    "肖特维尔称，马斯克希望在这颗红色星球上建造大型城市，但他也知道生活在这个太空殖民地的人们可能会想要上网。她补充说：“当我们把人们带到火星后，他们将需要一种交流方式。事实上，我认为在火星周围有个像星链这样的空中互联网将更加关键。”\n" +
                            "\n" +
                            "肖特维尔称：“连接这两颗行星要确保火星和地球之间有强大的通讯。”这将意味着火星和地球之间将有某种“互联网桥梁”。\n" +
                            "\n" +
                            "这位SpaceX首席运营官还解释说，该公司不会仅仅因为想要瞄准火星就放弃地球。\n" +
                            "\n" +
                            "马斯克创立SpaceX的目的就是将人类送上其他星球，而星际飞船有朝一日可把地球人送上火星。为了实现这个目标，马斯克称他需要由1000艘星际飞船组成的船队，以在火星上建设能够自给自足的可持续发展城市。\n" +
                            "\n" +
                            "马斯克此前誓言要在2050年之前将100万人送上火星。根据他的说法，SpaceX的目标是在10年内在德克萨斯州南部的设施中建造1000艘星际飞船，这相当于每年建造100艘。鉴于该公司到目前为止还没有建造出任何功能齐全的星际飞船，这是个相当大的挑战。\n" +
                            "\n" +
                            "马斯克的最终目标是每年发射1000次前往火星的星际飞船航班，平均每天3次。每次每艘飞船都会将100名乘客送往这颗红色星球，让他们成为火星大城市的公民。"
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.sciencenews2,
                    "瑞德西韦在美获批 吉利德：世卫中期结果不能否",
                    "tech.163.com",
                    "2020-10-24 14:03:44",
                    "https://tech.163.com/20/1024/14/FPN7LN5H00097U81.html",
                    ""
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.sciencenews3,
                    "SpaceX星际飞船SN8原型机鼻锥安装完成 接近最终",
                    "tech.163.com",
                    "2020-10-24 11:54:13",
                    "https://tech.163.com/20/1024/11/FPN08I3T00097U81.html",
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