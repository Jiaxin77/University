package condition;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class OnOff {
	private String room_id;
	private String on_time;  //开机时间
	private String off_time;//关机时间
	private float fee;
	public OnOff() {}
	public String getOn_time() {
		return this.on_time;
	}
	public void setOn_time(String on_time) {
		this.on_time=on_time;
	}
	public String getOff_time() {
		return this.off_time;
	}
	public void setOff_time(String f) {
		this.off_time=f;
	}
	public void setRoom_id(String room_id) {
		this.room_id=room_id;
	}
	public String getRoom_id() {
		return room_id;
	}
	public void setFee(float fee) {
		this.fee=fee;
	}
	public float getFee() {
		return this.fee;
	}
	public ArrayList<OnOff> on_off;
	public ArrayList<OnOff> select(){
		ArrayList<OnOff> on_off=new ArrayList<OnOff>();
		Connection conn=null;
		try {
			conn = DatabaseConnection.getCon();
			Statement stmt = conn.createStatement();
			String sql="select room_id,on_time,off_time,fee from on_off";
			
			ResultSet rs = stmt.executeQuery(sql);
			
			while(rs.next()) {
				OnOff onoff=new OnOff();
				onoff.setOn_time(rs.getString("on_time"));
				onoff.setOff_time(rs.getString("off_time"));
				onoff.setRoom_id(rs.getString("room_id"));
				onoff.setFee(rs.getFloat("fee"));
				on_off.add(onoff);
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
			         return on_off;   
	}
}
