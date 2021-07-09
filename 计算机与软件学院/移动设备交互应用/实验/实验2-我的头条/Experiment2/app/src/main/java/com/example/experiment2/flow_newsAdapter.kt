package com.example.experiment2

import android.app.Activity
import android.app.AlertDialog
import android.content.Intent
import android.net.Uri
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView

class flow_newsAdapter(val flow_newsList: List<flow_news>) :
        RecyclerView.Adapter<flow_newsAdapter.ViewHolder>() {
    inner class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val newsImage: ImageView = view.findViewById(R.id.flowNewsImage)
        val newsTitle: TextView = view.findViewById(R.id.flowNewsTitle)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context)
                .inflate(R.layout.flow_news_item, parent, false)
        val viewHolder = ViewHolder(view)
        viewHolder.itemView.setOnClickListener() {
            val position: Int = viewHolder.layoutPosition
            val flowNews = flow_newsList[position]
            when (position) {
                //本地文本查看
                0 -> {
                    val intent = Intent(parent.context, LocalNews::class.java)
                    intent.putExtra("Title", flowNews.newsTitle)
                    intent.putExtra("Content", flowNews.content)
                    parent.context.startActivity(intent)
                }
                //调用系统浏览器
                1 -> {
                    val intent = Intent(Intent.ACTION_VIEW)
                    intent.data = Uri.parse(flowNews.URL)
                    parent.context.startActivity(intent)
                }
                //使用WebView
                2 -> {
                    val intent = Intent(parent.context, WebView::class.java)
                    intent.putExtra("URL", flowNews.URL)
                    parent.context.startActivity(intent)
                }
                else->{
                    val intent = Intent(parent.context, WebView::class.java)
                    intent.putExtra("URL", flowNews.URL)
                    parent.context.startActivity(intent)
                }
            }
        }
        return viewHolder
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        val flow_news = flow_newsList[position]
        holder.newsImage.setImageResource(flow_news.imageID)
        holder.newsTitle.text = flow_news.newsTitle
    }

    override fun getItemCount() = flow_newsList.size


}