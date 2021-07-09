package com.example.finalproject.Main.Fragment

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import com.example.finalproject.R
import kotlinx.android.synthetic.main.fragment.*

class Fragment0 : Fragment() {

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)
        picture.setImageResource(R.drawable.frag1)
        title1.text="可回收物是指"
        task1.text="废纸张、废塑料、废玻璃制品、废金属、废织物等适宜回收、可循环利用的生活废弃品。"
        title2.text="可回收物投放要求"
        task2.text="1. 轻投轻放\n2. 清洁干燥，避免污染\n3. 废纸尽量平整\n4. 立体包装物请清空内容物，清洁后压扁投放\n5. 有尖锐边角的，应包裹后投放"
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return inflater.inflate(R.layout.fragment,container,false)
    }
}
