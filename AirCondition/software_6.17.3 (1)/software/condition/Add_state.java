package condition;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

class state{
public static final int stop=0;  //stop
public static final int run=1;   //on
public static final int halt=2;  //halt
}
public class Add_state {

	public static boolean add_state(String room_id,int state,String start_time)
	{
		boolean result = false;
		Connection conn = null;
		try {
			conn=DatabaseConnection.getCon(); //�������ݿ�����
			String sqlInsert = "insert into tbRoomState(RoomId,RoomState,StartTime) values(?, ?, ?)";
			//String sql="update room_state set stop_time='"+stop_time+"' where room_id='"+room_id+"' and state_change=2";        
			PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //���׳��쳣
			        stmt.setString(1, room_id);         //����SQL����һ����������ֵ
			        stmt.setInt(2, state);    //����SQL���ڶ�����������ֵ
			        stmt.setString(3, start_time);        //����SQL����������������ֵ
			        int i = stmt.executeUpdate();            //ִ�в������ݲ���������Ӱ�������
			         if (i == 1) {
			             result = true;
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
		        
			        return result;
	
	}
	public static boolean update(String room_id,String stop_time,float cost) {
		boolean result = false;
		Connection conn = null;
		try {
			conn=DatabaseConnection.getCon(); //�������ݿ�����
			//String sqlInsert = "update set StopTime='"+stop_time+"' RoomState(RoomId,RoomState,StartTime) values(?, ?, ?)";
			String sql="update tbRoomState set StopTime='"+stop_time+"',Cost='"+cost+"' where RoomId='"+room_id+"' and StopTime is null";        
			PreparedStatement stmt = conn.prepareStatement(sql);   //���׳��쳣
			        int i = stmt.executeUpdate();            //ִ�в������ݲ���������Ӱ�������
			         if (i == 1) {
			             result = true;
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
		        
			        return result;
	
	}
	public static boolean add_speed(String room_id,int speed,String ModifyTime,float CostRate) {
		boolean result = false;
		Connection conn = null;
		try {
			conn=DatabaseConnection.getCon(); //�������ݿ�����
			String sql="select seq from tbRoomState where RoomId='"+room_id+"' and RoomState<>0 and StopTime is not null";
			Statement stmt1 = conn.createStatement();
			ResultSet rs = stmt1.executeQuery(sql);
			int Seq=rs.getInt("seq");
			String sqlInsert = "insert into tbSpeedModify(seq,RoomId,speed,ModifyTime,CostRate) values(?, ?, ?, ?, ?)";
			//String sql="update room_state set stop_time='"+stop_time+"' where room_id='"+room_id+"' and state_change=2";        
			PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //���׳��쳣
					stmt.setInt(1,Seq);
			        stmt.setString(2, room_id);         //����SQL����һ����������ֵ
			        stmt.setInt(3, speed);    //����SQL���ڶ�����������ֵ
			        stmt.setString(4, ModifyTime);        //����SQL����������������ֵ
			        stmt.setFloat(5, CostRate);
			        int i = stmt.executeUpdate();            //ִ�в������ݲ���������Ӱ�������
			         if (i == 1) {
			             result = true;
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
		        
			        return result;
	}
	public static boolean add_temp(String room_id,int temp,String ModifyTime) {
		boolean result = false;
		Connection conn = null;
		try {
			conn=DatabaseConnection.getCon(); //�������ݿ�����
			String sql="select seq from tbRoomState where RoomId='"+room_id+"' and RoomState<>0 and StopTime is not null";
			Statement stmt1 = conn.createStatement();
			ResultSet rs = stmt1.executeQuery(sql);
			int Seq=rs.getInt("seq");
			String sqlInsert = "insert into tbTempModify(seq,RoomId,Temp,ModifyTime) values(?, ?, ?, ?)";
			//String sql="update room_state set stop_time='"+stop_time+"' where room_id='"+room_id+"' and state_change=2";        
			PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //���׳��쳣
					stmt.setInt(1,Seq);
			        stmt.setString(2, room_id);         //����SQL����һ����������ֵ
			        stmt.setInt(3, temp);    //����SQL���ڶ�����������ֵ
			        stmt.setString(4, ModifyTime);        //����SQL����������������ֵ
			        int i = stmt.executeUpdate();            //ִ�в������ݲ���������Ӱ�������
			         if (i == 1) {
			             result = true;
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
		        
			        return result;
	}
	/*public boolean add_on_off(String room_id,String on_time,String off_time,float fee) 
	{//����������ػ�ʱ���ÿգ����ػ����򿪻�ʱ���ÿգ�
		boolean result = false;
		Connection conn = null;
		try {
			conn=DatabaseConnection.getCon(); //�������ݿ�����
			if(on_time!=null) {
			String sqlInsert = "insert into room_state(room_id,on_time,fee) values(?, ?, ?)";
			        PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //���׳��쳣
			        stmt.setString(1, room_id);         //����SQL����һ����������ֵ
			        stmt.setString(2, on_time);    //����SQL���ڶ�����������ֵ
			        stmt.setFloat(3, fee);
			        int i = stmt.executeUpdate();            //ִ�в������ݲ���������Ӱ�������
			         if (i == 1) {
			             result = true;
			          }}
				if(off_time!=null) {
				String sqlInsert = "insert into room_state(room_id,off_time,fee) values(?, ?, ?)";
		        PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //���׳��쳣
		        stmt.setString(1, room_id);         //����SQL����һ����������ֵ
		        stmt.setString(2, off_time);  //����SQL���ڶ�����������ֵ
		        stmt.setFloat(3, fee);
		        int i = stmt.executeUpdate();            //ִ�в������ݲ���������Ӱ�������
		         if (i == 1) {
		             result = true;
		          }}
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
		        
			        return result;
				}*/



	public boolean isVIP(String Room_id) {
		Connection conn = null;
		boolean result=false;
		
			try {
				int i = 0 ;
				conn=DatabaseConnection.getCon(); //�������ݿ�����
				Statement stmt = conn.createStatement();  
				String sql="select vip from room where room_id='"+Room_id+"'";
				ResultSet rs = stmt.executeQuery(sql);
				if(rs.next()) {  
		            i=rs.getInt("vip");  
		        }  
				if (i==1) {
		            result = true;
		          }
		        
		         //System.out.println(i);
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
		return result;
	}
	/*public boolean add_in_out(String room_id,String in_time,String out_time)   //��ס���˷�ʱ����Ϣ
	{
		boolean result = false;
		Connection conn = null;
		try {
			conn=DatabaseConnection.getCon(); //�������ݿ�����
			if(in_time!=null) {
			String sqlInsert = "insert into in_out(room_id,in_time) values(?, ?)";
			        PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //���׳��쳣
			        stmt.setString(1, room_id);         //����SQL����һ����������ֵ
			        stmt.setString(2, in_time);    //����SQL���ڶ�����������ֵ
			      
			        int i = stmt.executeUpdate();            //ִ�в������ݲ���������Ӱ�������
			         if (i == 1) {
			             result = true;
			          }}
			if(out_time!=null)
			{
				String sqlInsert = "insert into in_out(room_id,out_time) values(?, ?)";
				PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //���׳��쳣
				stmt.setString(1, room_id);         //����SQL����һ����������ֵ
				stmt.setString(2, out_time);    //����SQL���ڶ�����������ֵ
	      
	        int i = stmt.executeUpdate();            //ִ�в������ݲ���������Ӱ�������
	         if (i == 1) {
	             result = true;
	          }}
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
		        
			        return result;
				}*/
	

		

}