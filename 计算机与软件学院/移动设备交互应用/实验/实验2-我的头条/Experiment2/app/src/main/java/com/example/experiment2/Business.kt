package com.example.experiment2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class Business : AppCompatActivity() {

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
        repeat(3){
            verticalNews.add(
                vertical_news(
                    R.drawable.businessnew1,
                    "富士康的两难境地：美国工厂难产 中国市场竞争压力剧增",
                    "finance.sina.com.cn",
                    "2020年10月24日 07:13",
                    "https://finance.sina.com.cn/chanjing/gsnews/2020-10-24/doc-iiznezxr7762539.shtml",
                    "  曾经被美国总统特朗普誉为“世界第八大奇迹”的2017年富士康赴美国100亿美元投资计划几经缩水，投资规模不及预期的十分之一。近日，富士康向美国申请税收补贴也被拒绝。\n" +
                            "\n" +
                            "　　这一投资曾被视为美国制造业回流标杆工程，也是富士康全球供应链布局关键一子。但此后富士康与当地政府多次谈崩，投资规模和提供岗位也不断缩水。\n" +
                            "\n" +
                            "　　10月20日，富士康创始人郭台铭不得不亲自出来喊话：“富士康再次重申，将会继续与美国总统特朗普和地方官员合作，为威斯康星州创造更多职位，吸引更多新投资。如果谁将富士康当成伙伴看待，我们也会以伙伴的身份与它们合作。”\n" +
                            "\n" +
                            "　　与在美国的境遇形成鲜明对比的是，随着苹果iPhone 12、iPhone 12 Pro等预售火爆，作为苹果手机最大代工厂的富士康在中国加班加点和大量招人。\n" +
                            "\n" +
                            "　　不过，《中国经营报》记者注意到，苹果产品的中国代工开始更多向内地代工厂倾斜，富士康“一家独大”的局面正面临挑战。“富士康想摆脱对中国内地的单一依赖，相关国家也提供了很丰厚的优惠政策，跟随苹果等布局美国、印度等全球供应链很正常，不过目前多地的投资未达预期。”商务部国际经贸研究院跨国公司研究中心主任何曼青告诉记者，“不过兜了一圈回来发现，像立讯精密(56.750, -0.84, -1.46%)、比亚迪(138.670, -5.12, -3.56%)等代工厂也开始崛起，开始和它抢地盘。”\n" +
                            "\n" +
                            "　　富士康美国囧途\n" +
                            "\n" +
                            "　　按照富士康2017年宣布的投资计划来看，在美国威斯康星州当地工厂投资共计100亿美元建设10.5代液晶显示屏（LCD）工厂，并为当地至少增添1.3万个工作岗位。在这种情况之下，当地政府为了激励发展，特意为富士康批准了一笔高达40亿美元的税收优惠和补贴。\n" +
                            "\n" +
                            "　　不过这个计划不到一年就变卦了。2019年3月，富士康提出他们准备建设的工厂并非10.5代LCD液晶显示屏工厂，而是一个规模和就业岗位都要大幅度缩水的6代工厂。\n" +
                            "\n" +
                            "　　可能考虑到威斯康星州的经济就业情况，当时州政府同意了富士康对合同的变动，但相应的税收优惠就要减少，要和富士康的真实投资规模和雇佣人数挂钩。而富士康则拒绝了威斯康星州政府提出的要求，并提出他们应该获得最初承诺的40亿美元补贴。\n" +
                            "\n" +
                            "　　以此来看，看起来像是富士康违约在先，导致当地政府借此驳回富士康的巨额补贴。但富士康有何难言之隐？对记者投资缩水背后缘由的询问，富士康并未正面回应。\n" +
                            "\n" +
                            "　　“事情可能没有这么简单，上面多是从美国媒体和当地企业单方面曝出的消息和声音，富士康作为全球知名代工巨头，对违反合同承诺的后果和影响不可能不清楚且全面评估。”一位接近富士康的分析师告诉记者，富士康的投资计划肯定遭遇了现实困难，或者综合评估后，这个投资计划不合理或很难执行。\n" +
                            "\n" +
                            "　　就此，目前富士康和当地政府方面并没有透露，不过也是有迹可循的。\n" +
                            "\n" +
                            "　　富士康在美国设厂的地址可能本身不合理。当地不仅缺乏大量熟练的工人，而且该地区也缺乏与富士康产业相关的上下游供应商，谈不上产业集聚，导致投产成本和难度大幅增加。\n" +
                            "\n" +
                            "　　同时，美国的人工成本较高，而且富士康还要面临与难缠的美国工会打交道。习惯了中国国内的相对宽松的用工环境，富士康在美国的投资布局之路注定不会一帆风顺。\n" +
                            "\n" +
                            "　　无论是对当地政府还是富士康，这个大项目落地本身存在诸多困难。据何曼青的初步研究测算，如果按原计划当地政府给予40亿美元的税收优惠，当地政府需要等到2043年前后才能收回补贴成本，在这20多年间存在诸多不确定性，还要额外增加当地民众税收负担。\n" +
                            "\n" +
                            "　　“而对于富士康来说，除大家熟悉的产业链配套、产业工人缺乏的问题外，很现实的困难就是工厂大块征地和随之而来的环保压力问题。”何曼青对记者表示。\n" +
                            "\n" +
                            "　　据悉，富士康正致力于通过不同供应链，分别服务全球不同市场，并逐渐降低中国内地产能比例并转移到境外。不想，作为全球布局关键一子的美国布局却出师不利，陷入当前进退两难的尴尬境地。\n" +
                            "\n" +
                            "　　中国加班加点抢人生产\n" +
                            "\n" +
                            "　　与美国工厂的困境形成鲜明对比的是，富士康在中国内地的工厂正在抓紧招人、加班加点生产。\n" +
                            "\n" +
                            "　　10月13日，iPhone 12、iPhone12 Pro等苹果5G新机正式发布，且预售火爆，苹果官网还一度宕机，加上传统的生产旺季，作为全球最大的iPhone代工生产厂商，富士康、和硕等代工厂全面开工之外，开始四处“抢人”。\n" +
                            "\n" +
                            "　　返费是富士康、和硕等工厂吸引工人的主要手段。据媒体报道，除每月工资外，额外发放奖金，要求其就职时间满足一定天数，目的是招来并留住产线上的人。其中，富士康郑州厂区的返费金额从7月底的5500元一路上升，奖金越来越高，一度达1万元。由于苹果公司年年发布新机，8月至11月是富士康传统的生产旺季，上万元的返费年年都有，但高返费去得也快，通常不超过两周。可今年不同，9月中旬以后，富士康郑州厂区开出的返费价码虽小有波动，却再没跌下8000元。\n" +
                            "\n" +
                            "　　一家向富士康输送人力的中介公司公开许诺，工厂缺工人，急招大量招临时工、正式工，入职条件也较往常放宽。\n" +
                            "\n" +
                            "　　此前还有媒体报道富士康为加紧生产iPhone12，决定取消厂区国庆和中秋假期。不过富士康方面回应称，“所谓厂区取消假期为不实消息”。此前富士康郑州厂区发布中秋国庆假期安排显示，4天为假期，实行3倍薪资，2天为补休日，实行2倍薪资。\n" +
                            "\n" +
                            "　　独霸地位受挑战\n" +
                            "\n" +
                            "　　作为劳动密集型的iPhone代工厂正在向更具性价比的地区转移。2017年开始，富士康、和硕等代工厂将在印度、印尼、越南建厂的消息就不断传出，2020年10月8日，彭博社报道称，印度政府为16家国内外电子公司提供4500亿卢比（约合人民币416.7亿元）的激励措施，富士康、纬创、和硕——iPhone的全球三大代工厂无一例外均入围该计划。\n" +
                            "\n" +
                            "　　“目前看主要有三点考量，一是中美贸易摩擦的背景下，全球供应链合理布局的需要；二是相关国家都给出了优厚的政策；三是中国的人工成本上升较快，作为劳动密集型的代工业来说，比较优势下降。”上述分析师对记者表示，富士康等代工厂向印度、越南等地部分转移应该是长期和战略性的。\n" +
                            "\n" +
                            "　　研究机构欧睿国际数据显示，中国制造业的平均每小时工资在2005年至2016年间涨了3倍，达到每小时3.6美元，约24.71元人民币，已相当于较弱欧元区成员国70%的水平。\n" +
                            "\n" +
                            "　　据悉，富士康已申请在印度投资约400亿卢比（约合人民币36.8亿元），纬创、和硕也有相应投资，绝大多数投资都将专注于扩大iPhone在印度的生产。此前还传出富士康高薪补助中国员工去印度教印度工人操作的消息。富士康对此表示，不会对具体运营或客户相关问题发表评论。\n" +
                            "\n" +
                            "　　不过，到目前为止，从印度尼西亚的智能工厂到巴西，再到最近的美国建厂，富士康们的境外工厂计划都并不顺利。中国作为世界工厂，有完善的产业上下游链条和配套的公路、港口基础设施，还有大量训练有素的产业工人，目前看，这些优势还是很难替代的。\n" +
                            "\n" +
                            "　　这个可以从苹果发布的全球200大供应商名单窥见一斑，中国工厂的数量和占比近年来仍在增加。2018年，苹果的778家供应商工厂中有356家位于中国大陆，比例为45.76%，2019年，这一数字增长为383家，占比47.46%。\n" +
                            "\n" +
                            "　　但出乎富士康意料的是，曾排在富士康身后的内地代工厂正迅速弥补其转移产能带来的空缺，并开始与其抢市场。\n" +
                            "\n" +
                            "　　今年，苹果将两亿iPhone订单交给了立讯精密，然后又将iPad的大量订单交给了比亚迪。“工厂代工的技术门槛本身并不高，而且立讯精密和比亚迪都是领域内的龙头企业，同时，从苹果角度来说，适当发展更多的大陆代工厂，承接中国市场订单，也算是向中国市场示好信号，同时也有助于其降低风险和减少对富士康的依赖。”何曼青表示。\n" +
                            "\n" +
                            "　　但这对富士康而言却不是好消息，而且在富士康迁厂美国、印度等国时，越来越多国产手机厂商开始选择比亚迪、立讯精密等国内代工厂商。在国内手机厂商长期占据着大半壁江山的背景下，面对国产手机厂商如此巨大的手机需求量，接下来全球代工市场格局或将重新洗牌。"
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.businessnew2,
                    "华为Mate40秒光：机构预测销量千万量级 又要加价买？",
                    "finance.sina.com.cn",
                    "2020年10月24日 09:04 ",
                    "https://finance.sina.com.cn/chanjing/gsnews/2020-10-24/doc-iiznctkc7356663.shtml",
                    "22"
                )
            )
            verticalNews.add(
                vertical_news(
                    R.drawable.businessnew3,
                    "债务违约超4亿 又有“首富”被限制高消费了",
                    "finance.sina.com.cn",
                    "2020年10月24日 08:28 ",
                    "https://finance.sina.com.cn/stock/s/2020-10-24/doc-iiznezxr7773062.shtml",
                    "2222"
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