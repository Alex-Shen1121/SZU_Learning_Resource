package com.example.finalproject.Main.Fragment

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import com.example.finalproject.R
import kotlinx.android.synthetic.main.fragment.*

class Fragment3 : Fragment() {

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)
        picture.setImageResource(R.drawable.frag1)
        title1.text="有害垃圾是指"
        task1.text="废电池、废灯泡、废药品、废油漆及其容器对人体健康或者自然环境造成直接或者潜在危害的生活废弃物"
        title2.text="可回收物投放要求"
        task2.text="1. 投放时请注意轻放\n2. 易破损的请连带包装或包裹后轻放\n3. 如易挥发，请密封后投放"
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return inflater.inflate(R.layout.fragment,container,false)
    }
}
