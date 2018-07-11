package condition;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
public class NewTime {
private String nowTime;
public String getnowTime() {
	return this.nowTime;
}

public NewTime()
{
	//SelectNewTime();
}

public void setnowTime(String nowTime) {
	this.nowTime=nowTime;
}
public String SelectNewTime() {
	Connection conn=null;
	String Time="";
	try {
		conn = DatabaseConnection.getCon();
		Statement stmt = conn.createStatement();
	NewTime nowtime=new NewTime();
	String sql1 = "select max(StopTime)as nowTime from tbRoomState";
	ResultSet rt = stmt.executeQuery(sql1);

	while(rt.next()) {
		String s=rt.getString("nowTime");
		String[] time = s.split(" ");
		nowtime.setnowTime(time[0]);
		 //System.out.println(time[0]);  
		Time=nowtime.getnowTime();
		}
	
	}catch (Exception e) {
        e.printStackTrace();
  } finally {
      try {
           conn.close();                                         //πÿ±’¡¨Ω”
   } catch (SQLException e) {
           // TODO Auto-generated catch block
            e.printStackTrace();
       }
   }
	return Time;
	
}
}
