package com.example.finalproject.Main

import android.content.Context
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import com.example.finalproject.BaseActivity
import com.example.finalproject.R
import kotlinx.android.synthetic.main.activity_login.*
import kotlinx.android.synthetic.main.activity_main_page.*
import kotlinx.android.synthetic.main.activity_place.*

class PlaceActivity : BaseActivity() {

    private val placeList = ArrayList<String>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_place)
        supportActionBar?.hide()
        initPlaceList()


        val layoutManager = LinearLayoutManager(this)
        recyclerView.layoutManager = layoutManager
        val adapter1 = place_Adapter(placeList)
        recyclerView.adapter = adapter1

        back.setOnClickListener() {
            val prefs = getSharedPreferences("current_place", Context.MODE_PRIVATE)
            val current_place = prefs.getString("place", null)
            currentPlace.text = current_place
            finish()
        }
    }

    private fun initPlaceList() {
        placeList.add("北京市")
        placeList.add("上海市")
        placeList.add("广州市")
        placeList.add("深圳市")
        placeList.add("成都市")
        placeList.add("杭州市")
        placeList.add("武汉市")
        for (i in 1..100) {
            placeList.add(i.toString() + "号城市")
        }
    }
}