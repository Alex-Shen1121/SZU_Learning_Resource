package com.example.experiment3.Student

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.recyclerview.widget.LinearLayoutManager
import com.example.experiment3.R
import com.example.experiment3.Student.RecyclerView.academic_lecture
import com.example.experiment3.Student.RecyclerView.important_inform
import com.example.experiment3.Student.RecyclerView.szu_news
import kotlinx.android.synthetic.main.left_frag.*
import java.io.BufferedReader
import java.io.InputStreamReader

class LeftFragment : Fragment() {

    private var isTwoPane = false

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return inflater.inflate(R.layout.left_frag, container, false)
    }

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)
        isTwoPane = activity?.findViewById<View>(R.id.StudentRightLayout) != null
        //设置重要通知
        val layoutManager = LinearLayoutManager(activity)
        importantInformRecyclerView.layoutManager = layoutManager
        val adapter1 = StudentMenu.ImportantInformAdapter(getInform1())
        importantInformRecyclerView.adapter = adapter1

        //设置学术讲座
        val layoutManager2 = LinearLayoutManager(activity)
        academicLectureRecyclerView.layoutManager = layoutManager2
        val adapter2 = StudentMenu.AcademicLectureAdapter(getInform2())
        academicLectureRecyclerView.adapter = adapter2

        //设置学术讲座
        val layoutManager3 = LinearLayoutManager(activity)
        szuNewsRecyclerView.layoutManager = layoutManager3
        val adapter3 = StudentMenu.SzuNewsAdapter(getInform3())
        szuNewsRecyclerView.adapter = adapter3
    }

    //读取重要通知文件
    private fun getInform1(): ArrayList<important_inform> {
        val informList = ArrayList<important_inform>()
        val input = activity?.openFileInput("important_information.txt")
        val reader = BufferedReader(InputStreamReader(input))
        var line = 0
        val type = ArrayList<String>()
        val title = ArrayList<String>()
        reader.use {
            reader.forEachLine {
                line += 1
                if (line % 2 == 1) {
                    var str = "[$it]"
                    type.add(str)
                } else if (line % 2 == 0)
                    title.add(it)
            }
        }
        for (i in type.indices) {
            informList.add(important_inform(type[i], title[i]))
        }
        return informList
    }

    //读取学术讲座文件
    private fun getInform2(): ArrayList<academic_lecture> {
        val informList = ArrayList<academic_lecture>()
        val input = activity?.openFileInput("academic_lecture.txt")
        val reader = BufferedReader(InputStreamReader(input))
        var line = 0
        val date = ArrayList<String>()
        val title = ArrayList<String>()
        val place = ArrayList<String>()
        reader.use {
            reader.forEachLine {
                line += 1
                if (line % 3 == 1)
                    date.add(it)
                else if (line % 3 == 0) {
                    place.add(it)
                } else if (line % 3 == 2)
                    title.add(it)
            }
        }
        for (i in date.indices) {
            informList.add(academic_lecture(date[i], title[i], place[i]))
        }
        return informList
    }

    //读取深大新闻文件
    private fun getInform3(): ArrayList<szu_news> {
        val informList = ArrayList<szu_news>()
        val input = activity?.openFileInput("szu_news.txt")
        val reader = BufferedReader(InputStreamReader(input))
        val title = ArrayList<String>()
        reader.use {
            reader.forEachLine {
                title.add(it)
            }
        }
        for (i in title.indices) {
            informList.add(szu_news(title[i]))
        }
        return informList
    }

}