package condition;
import java.sql.*;
public class DatabaseConnection {
	private static Connection conn = null;
	     public static Connection getCon() {
	          try {
	        	String ip=Setting.getDatabaseIP();
	            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver"); //�������ݿ���������
	            String user = "sa";
	            String psw = "ly520741";  //XXXΪ�Լ������ݿ������
	            String url = "jdbc:sqlserver://"+ip+":1433;DatabaseName=condition_system";                   //ZZZΪ���ӵ�����
	             conn = DriverManager.getConnection(url, user, psw);  //��ȡ����
	        } catch (Exception e) {
	            System.out.println("�������ݿ�ʧ��");
	             e.printStackTrace();
	         }
	         return conn;
	     }

}
