package com.example.finalproject.Main.Fragment

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import com.example.finalproject.R
import kotlinx.android.synthetic.main.fragment.*

class Fragment2 : Fragment() {

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)
        picture.setImageResource(R.drawable.frag3)
        title1.text="干垃圾是指"
        task1.text="即其他垃圾，是指可回收物、有害垃圾、湿垃圾之外的其他生活废弃物"
        title2.text="干垃圾投放要求"
        task2.text="1. 尽量沥干水分\n2. 难以辨别类别的生活垃圾投入干垃圾容器内"
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return inflater.inflate(R.layout.fragment,container,false)
    }
}
