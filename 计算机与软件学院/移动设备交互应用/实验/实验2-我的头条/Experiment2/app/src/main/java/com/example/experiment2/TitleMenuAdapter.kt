package com.example.experiment2

import android.app.Activity
import android.content.Intent
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView

class TitleMenuAdapter(val titleMenuList: List<TitleMenu>) :
    RecyclerView.Adapter<TitleMenuAdapter.ViewHolder>() {


    inner class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val titleMenuImage: ImageView = view.findViewById(R.id.titleMenuImage)
        val titleMenuName: TextView = view.findViewById(R.id.titleMenuName)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view =
            LayoutInflater.from(parent.context).inflate(R.layout.titlemenu_item, parent, false)
        //点击事件
        val viewHolder = ViewHolder(view)
        viewHolder.titleMenuImage.setOnClickListener() {
            val position: Int = viewHolder.layoutPosition
            when(position){
                0->{
                    val intent = Intent(parent.context, Business::class.java)
                    parent.context.startActivity(intent)
                    if (parent.context !is MainActivity && parent.context !is Business){
                        (parent.context as Activity).finish()
                    }
                }
                1->{
                    val intent = Intent(parent.context, Entertainment::class.java)
                    parent.context.startActivity(intent)
                    if (parent.context !is MainActivity && parent.context !is Entertainment){
                        (parent.context as Activity).finish()
                    }
                }
                2->{
                    val intent = Intent(parent.context, Health::class.java)
                    parent.context.startActivity(intent)
                    if (parent.context !is MainActivity && parent.context !is Health){
                        (parent.context as Activity).finish()
                    }
                }
                3->{
                    val intent = Intent(parent.context, Science::class.java)
                    parent.context.startActivity(intent)
                    if (parent.context !is MainActivity && parent.context !is Science){
                        (parent.context as Activity).finish()
                    }
                }
                4->{
                    val intent = Intent(parent.context, Sport::class.java)
                    parent.context.startActivity(intent)
                    if (parent.context !is MainActivity && parent.context !is Sport){
                        (parent.context as Activity).finish()
                    }
                }
                5->{
                    val intent = Intent(parent.context, Game::class.java)
                    parent.context.startActivity(intent)
                    if (parent.context !is MainActivity && parent.context !is Game){
                        (parent.context as Activity).finish()
                    }
                }
            }
        }
        return viewHolder
    }


    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        val titleMenu = titleMenuList[position]
        holder.titleMenuImage.setImageResource(titleMenu.imageID)
        holder.titleMenuName.text = titleMenu.name
    }

    override fun getItemCount() = titleMenuList.size
}