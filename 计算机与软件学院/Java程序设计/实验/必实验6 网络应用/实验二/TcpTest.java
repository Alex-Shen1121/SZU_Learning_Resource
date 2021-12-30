package 实验二;

public class TcpTest {
    public static void main(String[] args) throws Exception {
        Server server=new Server(6666);
        MainFrame mainFrame = new MainFrame("127.0.0.1",6666);
        mainFrame.init();
        new Thread(mainFrame).start();
        server.Send();

    }
}
