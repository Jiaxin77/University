package condition;
import java.sql.*;
import software.*;
public class DatabaseConnection {
	private static Connection conn = null;
	     public static Connection getCon() {
	          try {
	        	String ip=Setting.getDatabaseIP();
	            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver"); //加载数据库连接驱动
	            String user = "sa";
	            String psw = "ly520741";  //XXX为自己的数据库的密码
	            String url = "jdbc:sqlserver://"+ip+":1433;DatabaseName=condition_system";                   //ZZZ为连接的名字
	             conn = DriverManager.getConnection(url, user, psw);  //获取连接
	        } catch (Exception e) {
	            System.out.println("连接数据库失败");
	             e.printStackTrace();
	         }
	         return conn;
	     }

}
