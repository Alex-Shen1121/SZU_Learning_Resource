package com.example.finalproject.Main

import android.content.Context
import android.content.Intent
import android.net.Uri
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.example.finalproject.R
import kotlin.system.exitProcess

class place_Adapter(val place_List: List<String>) :
    RecyclerView.Adapter<place_Adapter.ViewHolder>() {
    inner class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val placeName: TextView = view.findViewById(R.id.placeName)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.place_item, parent, false)
        val viewHolder = ViewHolder(view)
        viewHolder.itemView.setOnClickListener() {
            val position: Int = viewHolder.layoutPosition
            val placeName = place_List[position]
            val prefs = parent.context.getSharedPreferences("current_place", Context.MODE_PRIVATE)
            val editor = prefs.edit()
            editor.putString("place", placeName)
            editor.apply()
            Toast.makeText(parent.context,"已成功修改为$placeName",Toast.LENGTH_SHORT).show()
        }
        return viewHolder
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        val placename = place_List[position]
        holder.placeName.text = placename
    }

    override fun getItemCount() = place_List.size


}