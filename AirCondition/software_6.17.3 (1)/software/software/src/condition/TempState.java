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
public class TempState {
	private int seq;
	private String RoomId;
	private float Temp;
	private String ModifyTime;
	
	public TempState() {}
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
	
	public float getTemp() {
		return this.Temp;
	}
	public void setTemp(float Temp) {
		this.Temp=Temp;
	}
	
	
	
	public ArrayList<TempState> select_TempState(int seq,String RoomId){
		ArrayList<TempState> tempList = new ArrayList<TempState>();
		Connection conn=null;
		try {
			conn = DatabaseConnection.getCon();
			Statement stmt = conn.createStatement();
			String sql="select seq,RoomId,temp,ModifyTime from tbTempModify where RoomId='"+RoomId+"' and seq='"+seq+"'" ;
			ResultSet rs = stmt.executeQuery(sql);
			while(rs.next()) {
				TempState temp_state=new TempState();
				temp_state.setSeq(rs.getInt("seq"));
				temp_state.setRoomId(rs.getString("RoomId"));
				temp_state.setTemp(rs.getFloat("Temp"));
				temp_state.setModifyTime(rs.getString("ModifyTime"));
				tempList.add(temp_state);
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
			         return tempList;   
	}
}
