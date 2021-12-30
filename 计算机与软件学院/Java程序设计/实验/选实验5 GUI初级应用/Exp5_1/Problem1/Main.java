package Exp5_1.Problem1;

import com.baidu.translate.demo.TransApi;

public class Main {

    // 在平台申请的APP_ID 详见 http://api.fanyi.baidu.com/api/trans/product/desktop?req=developer
    private static final String APP_ID = "20211208001021977";
    private static final String SECURITY_KEY = "D4sednFFWcS8CLBBOJfx";

    public static void main(String[] args) {
        TransApi api = new TransApi(APP_ID, SECURITY_KEY);
        String query = "今天天气怎么样";
        System.out.println(api.getTransResult(query, "auto", "en"));
    }

}
