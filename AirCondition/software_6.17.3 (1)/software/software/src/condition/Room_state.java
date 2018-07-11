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
	public static float sum;
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
	
	public void SumCost(String room_id) {
		Connection conn=null;
		try {
			conn = DatabaseConnection.getCon();
			Statement stmt = conn.createStatement();
			String sql1 = "select sum(Cost)as sumcost from tbRoomState where RoomId='"+room_id+"'and RoomState=0" ;
			ResultSet rt = stmt.executeQuery(sql1);

		if(rt.next()) {
			sum=rt.getFloat("sumcost");
		}
		
		}catch (Exception e) {
	        e.printStackTrace();
	  } finally {
	      try {
	           conn.close();                                         //�ر�����
	   } catch (SQLException e) {
	           // TODO Auto-generated catch block
	            e.printStackTrace();
	       }
	   }
	
	}
	
	public ArrayList<Room_state> select_OnOff(String room_id){
		ArrayList<Room_state> OnOffList = new ArrayList<Room_state>();
		Connection conn=null;
		try {
			conn = DatabaseConnection.getCon();
			Statement stmt = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY );
	//		String sql="select room_id,on_time,off_time from room_state" ;
			
			String sql="select RoomId,StartTime as off_time,StopTime as on_time,cost from tbRoomState where RoomState=0 and RoomId='"+room_id+"' " ;
			ResultSet rs = stmt.executeQuery(sql);
			while(rs.next()) {
				Room_state room_state=new Room_state();
				room_state.setRoomId(rs.getString("RoomId"));
				room_state.setStartTime(rs.getString("on_time"));
				//System.out.println(rs.getString("on_time"));
				if(rs.next()) {
					room_state.setStopTime(rs.getString("off_time"));
					room_state.setFee(rs.getFloat("cost"));
					OnOffList.add(room_state);
					rs.previous();
				}
				

				
			}
		}catch (Exception e) {
			              e.printStackTrace();
			        } finally {
			            try {
			                 conn.close();                                         //�ر�����
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
			
			String sql="select seq,RoomId,RoomState,cost,StartTime,StopTime from tbRoomState  " ;
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
				room_state.setStopTime(rs.getString("StopTime"));
				//room_state.setTarget_temp(rs.getFloat("target_temp"));
				roomList.add(room_state);
			}
		}catch (Exception e) {
			              e.printStackTrace();
			        } finally {
			            try {
			                 conn.close();                                         //�ر�����
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
			statement=conn.createStatement();//����Statement���Է��ͼ򵥵�SQL���  
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
        } finally { //finally���ô��ǲ��ܳ����Ƿ�����쳣����Ҫִ��finally��䣬�����ڴ˴��ر�����
              try {
                conn.close(); //��һ��Connection���Ӻ����һ��Ҫ��������close���������ر����ӣ����ͷ�ϵͳ��Դ�����ݿ���Դ
              } catch(SQLException e) {
                 e.printStackTrace();
            }
        }
	}*/
	
}
