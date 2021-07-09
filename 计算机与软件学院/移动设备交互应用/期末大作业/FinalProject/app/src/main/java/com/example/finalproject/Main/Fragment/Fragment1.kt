package com.example.finalproject.Main.Fragment

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import com.example.finalproject.R
import kotlinx.android.synthetic.main.fragment.*

class Fragment1 : Fragment() {

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)
        picture.setImageResource(R.drawable.frag2)
        title1.text="湿垃圾是指"
        task1.text="即易腐垃圾，是指食材废料、剩饭剩菜、过期食品、瓜皮果核、花卉绿植、中药药渣等生物质、生活废弃物"
        title2.text="湿垃圾投放要求"
        task2.text="1. 流质的食物垃圾，如牛奶等，应直接倒进下水口\n2. 有包装物的湿垃圾应将包装物去除后分类投放\n3. 包装物请投放到对应的可回收物或干垃圾容器"
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return inflater.inflate(R.layout.fragment,container,false)
    }
}
