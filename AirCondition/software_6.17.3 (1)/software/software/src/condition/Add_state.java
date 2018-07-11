package condition;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

import software.Time;

import java.sql.PreparedStatement;
import java.sql.ResultSet;

class state{
public static final int stop=0;  //stop
public static final int run=1;   //on
public static final int halt=2;  //halt
}

public class Add_state {
	public static void InitDatabase() {
		Connection conn = null;
		try {
			conn=DatabaseConnection.getCon(); //建立数据库连接
			String sqlInit="if not exists (select RoomId from tbRoomState where RoomID='311A') insert into tbRoomState(RoomId,RoomState,StartTime)values('311A',0,getdate())\r\n" + 
					"if not exists (select RoomId from tbRoomState where RoomID='311B') insert into tbRoomState(RoomId,RoomState,StartTime)values('311B',0,getdate())\r\n" + 
					"if not exists (select RoomId from tbRoomState where RoomID='312A') insert into tbRoomState(RoomId,RoomState,StartTime)values('312A',0,getdate())\r\n" + 
					"if not exists (select RoomId from tbRoomState where RoomID='312B') insert into tbRoomState(RoomId,RoomState,StartTime)values('312B',0,getdate())\r\n" + 
					"if not exists (select RoomId from tbRoomState where RoomID='313A') insert into tbRoomState(RoomId,RoomState,StartTime)values('313A',0,getdate())\r\n" + 
					"if not exists (select RoomId from tbRoomState where RoomID='313B') insert into tbRoomState(RoomId,RoomState,StartTime)values('313B',0,getdate())\r\n" + 
					"if not exists (select RoomId from tbRoomState where RoomID='314A') insert into tbRoomState(RoomId,RoomState,StartTime)values('314A',0,getdate())\r\n" + 
					"if not exists (select RoomId from tbRoomState where RoomID='315A') insert into tbRoomState(RoomId,RoomState,StartTime)values('315A',0,getdate())";
			PreparedStatement stmt1 = conn.prepareStatement(sqlInit); 
			stmt1.executeUpdate();
			conn.setAutoCommit(true);
			   
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
	
	}
	
	
	public static boolean add_state(String room_id,int state,String start_time,float cost)
	{
		boolean result = false;
		Connection conn = null;
		try {
				conn=DatabaseConnection.getCon(); //建立数据库连接
				if(cost == -1) {//不插入费用
					String sqlInsert = "insert into tbRoomState(RoomId,RoomState,StartTime) values(?, ?, ?)";
					//String sql="update room_state set stop_time='"+stop_time+"' where room_id='"+room_id+"' and state_change=2";        
					PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //会抛出异常
					conn.setAutoCommit(true); 
							stmt.setString(1, room_id);         //设置SQL语句第一个“？”的值
					        stmt.setInt(2, state);    //设置SQL语句第二个“？”的值
					        stmt.setString(3, start_time);        //设置SQL语句第三个“？”的值
					        int i = stmt.executeUpdate();            //执行插入数据操作，返回影响的行数
					         if (i == 1) {
					             result = true;
					          }
				}
				else {
					System.out.println("sql insert cost:"+cost+"time:"+Time.timeChange());
					String sqlInsert = "insert into tbRoomState(RoomId,RoomState,StartTime,Cost) values(?, ?, ?, ?)";
					//String sql="update room_state set stop_time='"+stop_time+"' where room_id='"+room_id+"' and state_change=2";        
					PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //会抛出异常
					        stmt.setString(1, room_id);         //设置SQL语句第一个“？”的值
					        stmt.setInt(2, state);    //设置SQL语句第二个“？”的值
					        stmt.setString(3, start_time);        //设置SQL语句第三个“？”的值
					        stmt.setFloat(4,cost);        //设置SQL语句第三个“？”的值
					        int i = stmt.executeUpdate();            //执行插入数据操作，返回影响的行数
					         if (i == 1) {
					             result = true;
					          }
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
		        
			        return result;
	
	}
	public static boolean update(String room_id,String stop_time,float cost) {
		boolean result = false;
		Connection conn = null;
		try {
			conn=DatabaseConnection.getCon(); //建立数据库连接
			//String sqlInsert = "update set StopTime='"+stop_time+"' RoomState(RoomId,RoomState,StartTime) values(?, ?, ?)";
			if(cost == -1) {
				String sql="update tbRoomState set StopTime='"+stop_time+"' where RoomId='"+room_id+"' and StopTime is null";        
				PreparedStatement stmt = conn.prepareStatement(sql);   //会抛出异常
				        int i = stmt.executeUpdate();            //执行插入数据操作，返回影响的行数
				         if (i == 1) {
				             result = true;
				          }
			}
			else {
				String sql="update tbRoomState set StopTime='"+stop_time+"',Cost='"+cost+"' where RoomId='"+room_id+"' and StopTime is null";        
				PreparedStatement stmt = conn.prepareStatement(sql);   //会抛出异常
				        int i = stmt.executeUpdate();            //执行插入数据操作，返回影响的行数
				         if (i == 1) {
				             result = true;
				          }
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
		        
			        return result;
	
	}
	public static boolean add_speed(String room_id,int speed,String ModifyTime,float CostRate) {
		boolean result = false;
		Connection conn = null;
		int Seq=0;
		try {
			conn=DatabaseConnection.getCon(); //建立数据库连接
			String sql="select seq from tbRoomState where RoomId='"+room_id+"' and RoomState<>0 and StopTime is  null";
			Statement stmt1 = conn.createStatement();
			ResultSet rs = stmt1.executeQuery(sql);
			if(rs.next()) {
				Seq=rs.getInt("seq");
			}
			
			String sqlInsert = "insert into tbSpeedModify(seq,RoomId,speed,ModifyTime,CostRate) values(?, ?, ?, ?, ?)";
			//String sql="update room_state set stop_time='"+stop_time+"' where room_id='"+room_id+"' and state_change=2";        
			PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //会抛出异常
					stmt.setInt(1,Seq);
			        stmt.setString(2, room_id);         //设置SQL语句第一个“？”的值
			        stmt.setInt(3, speed);    //设置SQL语句第二个“？”的值
			        stmt.setString(4, ModifyTime);        //设置SQL语句第三个“？”的值
			        stmt.setFloat(5, CostRate);
			        int i = stmt.executeUpdate();            //执行插入数据操作，返回影响的行数
			         if (i == 1) {
			             result = true;
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
		        
			        return result;
	}
	public static boolean add_temp(String room_id,float temp,String ModifyTime) {
		boolean result = false;
		Connection conn = null;
		int Seq=0;
		try {
			conn=DatabaseConnection.getCon(); //建立数据库连接
			String sql="select seq from tbRoomState where RoomId='"+room_id+"' and RoomState<>0 and StopTime is null";
			Statement stmt1 = conn.createStatement();
			ResultSet rs = stmt1.executeQuery(sql);
			if(rs.next()) {
				Seq=rs.getInt("seq");
				System.out.println("seq:"+Seq);
			}
			
			String sqlInsert = "insert into tbTempModify(seq,RoomId,Temp,ModifyTime) values(?, ?, ?, ?)";
			//String sql="update room_state set stop_time='"+stop_time+"' where room_id='"+room_id+"' and state_change=2";        
			PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //会抛出异常
					stmt.setInt(1,Seq);
			        stmt.setString(2, room_id);         //设置SQL语句第一个“？”的值
			        stmt.setFloat(3, temp);    //设置SQL语句第二个“？”的值
			        stmt.setString(4, ModifyTime);        //设置SQL语句第三个“？”的值
			        int i = stmt.executeUpdate();            //执行插入数据操作，返回影响的行数
			         if (i == 1) {
			             result = true;
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
		        
			        return result;
	}
	/*public boolean add_on_off(String room_id,String on_time,String off_time,float fee) 
	{//若开机，则关机时间置空；若关机，则开机时间置空；
		boolean result = false;
		Connection conn = null;
		try {
			conn=DatabaseConnection.getCon(); //建立数据库连接
			if(on_time!=null) {
			String sqlInsert = "insert into room_state(room_id,on_time,fee) values(?, ?, ?)";
			        PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //会抛出异常
			        stmt.setString(1, room_id);         //设置SQL语句第一个“？”的值
			        stmt.setString(2, on_time);    //设置SQL语句第二个“？”的值
			        stmt.setFloat(3, fee);
			        int i = stmt.executeUpdate();            //执行插入数据操作，返回影响的行数
			         if (i == 1) {
			             result = true;
			          }}
				if(off_time!=null) {
				String sqlInsert = "insert into room_state(room_id,off_time,fee) values(?, ?, ?)";
		        PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //会抛出异常
		        stmt.setString(1, room_id);         //设置SQL语句第一个“？”的值
		        stmt.setString(2, off_time);  //设置SQL语句第二个“？”的值
		        stmt.setFloat(3, fee);
		        int i = stmt.executeUpdate();            //执行插入数据操作，返回影响的行数
		         if (i == 1) {
		             result = true;
		          }}
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
		        
			        return result;
				}*/



	public static boolean isVIP(String Room_id) {
		Connection conn = null;
		boolean result=false;
		
			try {
				int i = 0 ;
				conn=DatabaseConnection.getCon(); //建立数据库连接
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
			        } finally { //finally的用处是不管程序是否出现异常，都要执行finally语句，所以在此处关闭连接
			              try {
			                conn.close(); //打开一个Connection连接后，最后一定要调用它的close（）方法关闭连接，以释放系统资源及数据库资源
			           } catch(SQLException e) {
			                 e.printStackTrace();
			            }
			       }
		return result;
	}
	/*public boolean add_in_out(String room_id,String in_time,String out_time)   //入住与退房时间信息
	{
		boolean result = false;
		Connection conn = null;
		try {
			conn=DatabaseConnection.getCon(); //建立数据库连接
			if(in_time!=null) {
			String sqlInsert = "insert into in_out(room_id,in_time) values(?, ?)";
			        PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //会抛出异常
			        stmt.setString(1, room_id);         //设置SQL语句第一个“？”的值
			        stmt.setString(2, in_time);    //设置SQL语句第二个“？”的值
			      
			        int i = stmt.executeUpdate();            //执行插入数据操作，返回影响的行数
			         if (i == 1) {
			             result = true;
			          }}
			if(out_time!=null)
			{
				String sqlInsert = "insert into in_out(room_id,out_time) values(?, ?)";
				PreparedStatement stmt = conn.prepareStatement(sqlInsert);   //会抛出异常
				stmt.setString(1, room_id);         //设置SQL语句第一个“？”的值
				stmt.setString(2, out_time);    //设置SQL语句第二个“？”的值
	      
	        int i = stmt.executeUpdate();            //执行插入数据操作，返回影响的行数
	         if (i == 1) {
	             result = true;
	          }}
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
		        
			        return result;
				}*/
	

		

}