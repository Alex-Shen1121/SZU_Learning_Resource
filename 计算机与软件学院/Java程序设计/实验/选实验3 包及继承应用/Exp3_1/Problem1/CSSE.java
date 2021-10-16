package Exp3_1.Problem1;

public class CSSE {
    Teacher[] teacherName;

    public CSSE() {
        // 名单初始化
        teacherName = new Teacher[]{
                new Teacher("FOURNIER-VIGER PHILIPPE", "特聘教授 博士"),
                new Teacher("JIANBIN QIN", "特聘教授 博士"),
                new Teacher("黄惠", "特聘教授"),
                new Teacher("黄哲学", "特聘教授"),
                new Teacher("贾森", "特聘教授"),
                new Teacher("江健民", "特聘教授 哲学博士学位"),
                new Teacher("石大明", "特聘教授 博士"),
                new Teacher("伍楷舜", "特聘教授")
        };

    }

    public void getTeacherNames() {
        System.out.println("深圳大学特聘教授名单：");
        for (int i = 1; i <= teacherName.length; i++) {
            System.out.println(i + ":" + teacherName[i - 1].name + "   " + teacherName[i - 1].title);
        }
    }
}
