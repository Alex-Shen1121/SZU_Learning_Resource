package com.example.experiment2

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.webkit.WebViewClient
import kotlinx.android.synthetic.main.activity_web_view.*

class WebView : AppCompatActivity() {
    @SuppressLint("SetJavaScriptEnabled")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_web_view)
        supportActionBar?.hide()
        val URL: String? =intent.getStringExtra("URL")
        setContentView(R.layout.activity_web_view)
        webView.settings.javaScriptEnabled=true
        webView.webViewClient= WebViewClient()
        if (URL != null) {
            webView.loadUrl(URL)
        }

    }
}