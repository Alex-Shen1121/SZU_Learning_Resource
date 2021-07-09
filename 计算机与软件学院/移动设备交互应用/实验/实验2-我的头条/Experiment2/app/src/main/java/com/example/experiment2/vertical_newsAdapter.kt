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

class vertical_newsAdapter(val vertical_newsList: List<vertical_news>) :
    RecyclerView.Adapter<vertical_newsAdapter.ViewHolder>() {
    inner class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val newsImage: ImageView = view.findViewById(R.id.verticalNewsImage)
        val newsTitle: TextView = view.findViewById(R.id.verticalNewsTitle)
        val newsURL: TextView = view.findViewById(R.id.verticalNewsURL)
        val newsTime: TextView = view.findViewById(R.id.verticalNewsTime)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.vertical_news_item, parent, false)
        val viewHolder = ViewHolder(view)
        viewHolder.itemView.setOnClickListener() {
            val position: Int = viewHolder.layoutPosition
            val verticalNews = vertical_newsList[position]
            when (position) {
                //本地文本查看
                0 -> {
                    val intent = Intent(parent.context, LocalNews::class.java)
                    intent.putExtra("Title", verticalNews.newsTitle)
                    intent.putExtra("Content", verticalNews.content)
                    parent.context.startActivity(intent)
                }
                //调用系统浏览器
                1 -> {
                    val intent = Intent(Intent.ACTION_VIEW)
                    intent.data = Uri.parse(verticalNews.URL)
                    parent.context.startActivity(intent)
                }
                //使用WebView
                2 -> {
                    val intent = Intent(parent.context, WebView::class.java)
                    intent.putExtra("URL", verticalNews.URL)
                    parent.context.startActivity(intent)
                }
                else->{
                    val intent = Intent(parent.context, WebView::class.java)
                    intent.putExtra("URL", verticalNews.URL)
                    parent.context.startActivity(intent)
                }
            }
        }
        return viewHolder
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        val verticle_news = vertical_newsList[position]
        holder.newsImage.setImageResource(verticle_news.imageID)
        holder.newsTitle.text = verticle_news.newsTitle
        holder.newsTime.text = verticle_news.newsTime
        holder.newsURL.text = verticle_news.newsURL
    }

    override fun getItemCount() = vertical_newsList.size


}