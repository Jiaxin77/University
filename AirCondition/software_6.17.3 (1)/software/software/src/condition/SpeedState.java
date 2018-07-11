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
public class SpeedState {
	private int seq;
	private String RoomId;
	private int speed;
	private String ModifyTime;
	private float CostRate;
	
	//public  static ArrayList<Room_state> roomList;
	
	public SpeedState() {}
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
	
	public String getModifyTime() {
		return this.ModifyTime;
	}
	public void setModifyTime(String ModifyTime) {
		this.ModifyTime=ModifyTime;
	}
	
	public int getSpeed() {
		return this.speed;
	}
	public void setSpeed(int speed) {
		this.speed=speed;
	}
	
	
	public float getCostRate() {
		return this.CostRate;
	}
	public void setCostRate(float CostRate) {
		this.CostRate=CostRate;
	}
	
	
	 
	public ArrayList<SpeedState> select_SpeedState(int seq,String RoomId){
		ArrayList<SpeedState> speedList = new ArrayList<SpeedState>();
		Connection conn=null;
		try {
			conn = DatabaseConnection.getCon();
			Statement stmt = conn.createStatement();
	//		String sql="select room_id,on_time,off_time from room_state" ;
			
			String sql="select seq,RoomId,speed,CostRate,ModifyTime from tbSpeedModify where RoomId='"+RoomId+"' and seq='"+seq+"'" ;
			ResultSet rs = stmt.executeQuery(sql);
			while(rs.next()) {
				SpeedState speed_state=new SpeedState();
				speed_state.setSeq(rs.getInt("seq"));
				speed_state.setCostRate(rs.getFloat("CostRate"));
				speed_state.setRoomId(rs.getString("RoomId"));
				speed_state.setSpeed(rs.getInt("speed"));
				speed_state.setModifyTime(rs.getString("ModifyTime"));
				speedList.add(speed_state);
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
			         return speedList;   
	}
}