package condition;
import java.sql.*;
  
public class test {
	/*public boolean add_state(String roomid,int mode,int speed,float current_temp,float target_temp,String start_time,String stop_time,float fee)
	{
		boolean result = false;
		Connection conn = null;
		try {
			conn=
		} 

	}*/
	public static void main(String [] args)
 {
  String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=condition_system";
  String userName="sa";
  String userPwd="ly520741";
  Statement statement=null; 
  Connection conn=null;
  ResultSet rs=null;  
  String Room_id="312A";
  String time="2018-09-28 12:30";
  //String sql="insert into in_out(room_id,in_time,out_time)values(11,'"+time+"','"+time+"') ";   //sql���
  String sql1="update in_out set out_time='"+time+"' where in_time='2018-05-28 12:00'";
  String sql2="select* from in_out";
  String sql="select vip from room where room_id='"+Room_id+"'";
  try
  {
   Class.forName(driverName);
   conn=DriverManager.getConnection(dbURL,userName,userPwd);
   statement=conn.createStatement();//����Statement���Է��ͼ򵥵�SQL���  
   rs=statement.executeQuery(sql);      //����ResultSet����
  // int r= statement.executeUpdate(sql1);    //���ظ�������
 // boolean s= statement.execute(sql1);    //�����Ƿ��н����
 // System.out.println(s);
  /* while(rs.next()) {  
	   System.out.println("room_id:"+rs.getString("room_id")+"\t"+"in_time:"+ rs.getInt("vip"));
	   //+"\t"+"out_time:"+rs.getString("out_time"));  
	   } */
 
  } catch (ClassNotFoundException e) {  
	// TODO Auto-generated catch block  
	  e.printStackTrace();  
	  } catch (SQLException e) {  
	  // TODO Auto-generated catch block  
	  e.printStackTrace();  
	  }finally {  
	  if(conn!=null) {  
	  try {  
	   //�����Ϊ��˵�����ӳɹ��ˣ��ر�����  
	  conn.close();  
	  } catch (SQLException e) {  
	  // TODO Auto-generated catch block  
	  e.printStackTrace();  
	                 }  
	           }  
	       } 
 		}
	}


 