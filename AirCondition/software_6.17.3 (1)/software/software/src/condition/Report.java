package condition;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class Report {
	private float comm_temp;
	private int comm_speed;
	private int use_count;
	private int schedule_count;
	private  String StartTime;
	private  String StopTime;
	
	public void setStartTime(String StartTime) {
		//以2018-05-19形式传入
		String s=StartTime+' '+"00:00";
		this.StartTime=s;
		
	}
	public String getStartTime() {
		return this.StartTime;
	}
	public void setStopTime(String StopTime) {
		String t=StopTime+' '+"23:59";
		this.StopTime=t;
	}
	public String getStopTime() {
		return this.StopTime;
	}
	public ArrayList<Room_state> dayList;
	public Report() {}
	public float getComm_temp() {
		return this.comm_temp;
	}
	public void setComm_temp(float comm_temp) {
		this.comm_temp=comm_temp;
	}
	public int getComm_speed() {
		return this.comm_speed;
	}
	public void setComm_speed(int comm_speed) {
		this.comm_speed=comm_speed;
	}
	public int getUse_count() {
		return this.use_count;
	}
	public void setUse_count(int use_count) {
		this.use_count=use_count;
	}
	public int getSchedule_count() {
		return this.schedule_count;
	}
	public void setSchedule_count(int schedule_count) {
		this.schedule_count=schedule_count;
	}
	
	
	public void select(String start_time,String stop_time){
	//public static void main(String[] args) {
		//ArrayList<Report> reportList=new ArrayList<Report>();
		Connection conn=null;
		try {
			//Report report=new Report();
			conn = DatabaseConnection.getCon();
			Statement stmt = conn.createStatement();
			String sql1="select count(*) as num from tbRoomState\r\n" + 
					"where (StartTime between '"+start_time+"' and '"+stop_time+"')\r\n" + 
					"and RoomState = 1\r\n" ;
			String sql2="select count(*) as num from tbRoomState\r\n" + 
					"where (StopTime between '"+start_time+"' and '"+stop_time+"')\r\n" + 
					"and RoomState = 0";
			String sql3="select temp,count(temp) as comm_temp from tbTempModify  group by temp order by comm_temp desc";
			String sql4="select speed,count(speed) as comm_speed from tbSpeedModify  group by speed order by comm_speed desc";
			
			ResultSet rs1 = stmt.executeQuery(sql1);
			if(rs1.next()) {  
	            //report.setSchedule_count(rs1.getInt("schedule_count"));
				schedule_count=rs1.getInt("num");
	        }  
			ResultSet rs2 = stmt.executeQuery(sql2);
			if(rs2.next()) {  
	            use_count=rs2.getInt("num");
	        }  
			ResultSet rs3=stmt.executeQuery(sql3);
			if(rs3.next()) {
				comm_temp=rs3.getFloat("temp");
			}
			ResultSet rs4=stmt.executeQuery(sql4);
			if(rs4.next()) {
				comm_speed=rs4.getInt("speed");
				//System.out.print(rs4.getInt("speed"));
			}
			
		}catch (Exception e) {
			              e.printStackTrace();
			        } finally {
			            try {
			                 conn.close();                                         //关闭连接
		             } catch (SQLException e) {
			                 // TODO Auto-generated catch block
			                  e.printStackTrace();
			             }
			         }
			     
	}
	
	
	
	
	
}
