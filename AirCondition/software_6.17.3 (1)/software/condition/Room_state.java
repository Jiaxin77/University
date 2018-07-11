package condition;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.awt.List;
import java.util.ArrayList;
import java.util.*;
/*class state{
	public static final int stop=0;  //stop
	public static final int run=1;   //on
	public static final int halt=2;  //halt
}*/
public class Room_state {
	private int seq;
	private String RoomId;
	private String StartTime;
	private String StopTime;
	private int state;
	private float cost;
	public Room_state() {}
	public int getSeq() {
		return this.seq;
	}
	public void setSeq(int seq) {
		this.seq=seq;
	}
	public String getRoomId() {
		return this.RoomId;
	}
	public void setRoomId(String RoomId) {
		this.RoomId=RoomId;
	}
	
	public String getStartTime() {
		return this.StartTime;
	}
	public void setStartTime(String StartTime) {
		this.StartTime=StartTime;
	}
	public String getStopTime() {
		return this.StopTime;
	}
	public void setStopTime(String StopTime) {
		this.StopTime=StopTime;
	}
	public float getCost() {
		return this.cost;
	}
	public void setFee(float cost) {
		this.cost=cost;
	}
	public int getState() {
		return this.state;
	}
	public void setState(int state) {
		this.state=state;
	}
	public ArrayList<Room_state> select_OnOff(){
		ArrayList<Room_state> OnOffList = new ArrayList<Room_state>();
		Connection conn=null;
		try {
			conn = DatabaseConnection.getCon();
			Statement stmt = conn.createStatement();
	//		String sql="select room_id,on_time,off_time from room_state" ;
			
			String sql="select RoomId,StartTime as off_time,StopTime as on_time from tbRoomState where RoomState=0 " ;
			ResultSet rs = stmt.executeQuery(sql);
			while(rs.next()) {
				Room_state room_state=new Room_state();
				room_state.setRoomId(rs.getString("RoomId"));
				room_state.setStartTime(rs.getString("off_time"));
				room_state.setStopTime(rs.getString("on_time"));
				//room_state.setTarget_temp(rs.getFloat("target_temp"));
				OnOffList.add(room_state);
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
			         return OnOffList;   
	}
	public ArrayList<Room_state> select_RoomState(){
		ArrayList<Room_state> roomList = new ArrayList<Room_state>();
		Connection conn=null;
		try {
			conn = DatabaseConnection.getCon();
			Statement stmt = conn.createStatement();
	//		String sql="select room_id,on_time,off_time from room_state" ;
			
			String sql="select seq,RoomId,RoomState,cost,StartTime,state,StopTime from tbRoomState " ;
			ResultSet rs = stmt.executeQuery(sql);
			while(rs.next()) {
				Room_state room_state=new Room_state();
				/*room_state.setChange_time(rs.getString("change_time"));
				room_state.setCurrent_temp(rs.getFloat("current_temp"));*/
				room_state.setSeq(rs.getInt("seq"));
				room_state.setFee(rs.getFloat("cost"));
				//room_state.setMode(rs.getInt("mode"));
				//room_state.setFee_rate(rs.getFloat("fee_rate"));
				room_state.setRoomId(rs.getString("RoomId"));
				//room_state.setSpeed(rs.getInt("speed"));
				room_state.setStartTime(rs.getString("StartTime"));
				room_state.setState(rs.getInt("RoomState"));
				room_state.setStopTime(rs.getString("StoptTime"));
				//room_state.setTarget_temp(rs.getFloat("target_temp"));
				roomList.add(room_state);
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
			         return roomList;   
	}

	
	
		
	
	/*public void readBill() 
	{
		Connection conn = null;
		Statement statement=null; 
		ResultSet rs=null;
		try {
			conn=DatabaseConnection.getCon();
			statement=conn.createStatement();//创建Statement用以发送简单的SQL语句  
			String sql="with on_table(room_id,start_time) as (select room_id, start_time from room_state where start_time is not null )" + 
					"off_table(room_id,stop_time) as (select room_id,stop_time from room_state where stop_time is not null)\r\n" + 
					"select room_state.room_id,room_state.start_time,room_state.stop_time,fee\r\n" + 
					"from room_state,on_table,off_table\r\n" + 
					"where room_state.room_id=on_table.room_id and room_state.room_id=off_table.room_id";
			//String sql1="select room_id,count(stop_time)as sun from room_state group by room_id" ;
			String sql2="select room_id,count(stop_time)as sun\r\n" + 
					"from room_state\r\n" + 
					"group by room_id";
			rs=statement.executeQuery(sql);
			 System.out.print("room_id:"+"\t"+"start_time:"+ '\t'+"stop_time");
			  while(rs.next()) {  
				   System.out.println("room_id:"+rs.getString("room_id")+"\t"+"speed:"+  
				      rs.getString("speed")+"\t"+"mode:"+rs.getString("mode")+"\t"+"current_temp:"+rs.getString("current_temp")); 
				  System.out.println(rs.getString("room_id")+"\t\t"+ rs.getString("sun"));
				   } 
			
		} catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } finally { //finally的用处是不管程序是否出现异常，都要执行finally语句，所以在此处关闭连接
              try {
                conn.close(); //打开一个Connection连接后，最后一定要调用它的close（）方法关闭连接，以释放系统资源及数据库资源
              } catch(SQLException e) {
                 e.printStackTrace();
            }
        }
	}*/
	
}
