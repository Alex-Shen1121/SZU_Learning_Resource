package com.example.finalproject.Main

import android.content.Context
import android.content.Intent
import android.net.Uri
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AlertDialog
import androidx.recyclerview.widget.RecyclerView
import com.example.finalproject.R
import kotlin.system.exitProcess

class search_Adapter(val search_List: List<search_result>) :
    RecyclerView.Adapter<search_Adapter.ViewHolder>() {
    inner class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val name: TextView = view.findViewById(R.id.name)
        val type: TextView = view.findViewById(R.id.type)
        val typeimage: ImageView = view.findViewById(R.id.typeimage)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.search_item, parent, false)
        val viewHolder = ViewHolder(view)
        viewHolder.itemView.setOnClickListener() {
            val position: Int = viewHolder.layoutPosition
            val Name = search_List[position].name
            val Type = search_List[position].type
            AlertDialog.Builder(parent.context).apply {
                setTitle("$Name 属于 $Type")
                if(Type=="干垃圾")
                    setMessage("干垃圾投放要求：\n尽量沥干水分\n难以辨识类别的生活垃圾投入干垃圾容器内")
                else if (Type=="可回收物")
                    setMessage("可回收物投放要求：\n轻投轻放\n清洁干燥，避免污染\n废纸尽量平整\n立体包装物请清空内容物，清洁后压扁投放\n有尖锐边角的，应包裹后投放")
                else if (Type=="湿垃圾")
                    setMessage("湿垃圾投放要求：\n流质的食物垃圾，如牛奶等，应直接倒进下水口\n有包装物的湿垃圾应将包装物去除后分类投放\n包装物请投放到对应的可回收物或干垃圾容器")
                else if (Type=="有害垃圾")
                    setMessage("有害垃圾投放要求：\n投放时请注意轻放\n已破损的请连带包装或包裹后轻放\n如易挥发，请密封后投放")
                setCancelable(false)
                setPositiveButton("OK") { _, _ -> }
                show()
            }
        }
        return viewHolder
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        val Name = search_List[position].name
        val Type = search_List[position].type
        holder.name.text=Name
        holder.type.text=Type
        when(Type){
            "可回收物"->holder.typeimage.setImageResource(R.drawable.trash1)
            "湿垃圾"->holder.typeimage.setImageResource(R.drawable.trash2)
            "干垃圾"->holder.typeimage.setImageResource(R.drawable.trash3)
            "有害垃圾"->holder.typeimage.setImageResource(R.drawable.trash4)
        }
    }

    override fun getItemCount() = search_List.size


}