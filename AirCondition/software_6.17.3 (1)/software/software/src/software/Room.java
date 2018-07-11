package software;

import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

public class Room {
	private String room_id;//房号
	private int speed;//风速
	private float cur_temp;//当前温度
	private float dst_temp;//目标温度
	private float cost;//花费
	private float subcost;//每阶段的花费
	private float opencost;
	private float energy;//耗能
	private int identify;//vip还是普通房间
	private boolean empty;//房间是否为空 这个没啥用
	private Socket sock;//通信的socket
	private boolean exit;
	private int state;//房间状态
	private String starttime = "";//房间开始调度的时间
	
	public Room(Socket sock) {
		this.speed = Setting.getDefault_speed(); 
		this.dst_temp = Setting.getDefault_dst_temp(); 
		this.cost = 0;
		this.subcost = 0;
		this.opencost = 0;
		this.energy = 0;
		this.empty = false;
		this.sock = sock;
		this.exit = false;
		this.state = CmdConstant.CLOSE;
	}
	
	public Room(Room room) {
		this.room_id = room.getRoom_id();
		this.speed = room.getSpeed();
		this.cur_temp = room.getCur_temp();
		this.dst_temp = room.getDst_temp();
		this.cost = room.getCost();
		this.energy = room.getEnergy();
		this.identify = room.getIdentify();
		this.empty = room.getEmpty();
		this.state = room.getState();
		this.subcost = 0;
		this.opencost = 0;
	}
	
	public void setState(int state) {
		this.state = state;
	}
	
	public int getState() {
		return this.state;
	}
	
	public void setStarttime(String time) {
		this.starttime = time;
	}
	
	public String getStarttime() {
		return this.starttime;
	}
	
	public void setExitTrue() {
		this.exit = true;
	}
	
	public boolean getExit() {
		return this.exit;
	}
	
	public void setRoom_id(String room_id) {
		this.room_id = room_id;
	}
	public String getRoom_id() {
		return this.room_id;
	}
	
	public void setSpeed(int speed) {
		this.speed = speed;
	}
	public int getSpeed() {
		return this.speed;
	}
	
	public void setCur_temp(float cur_temp) {
		this.cur_temp = cur_temp;
	}
	public float getCur_temp() {
		return this.cur_temp;
	}
	
	public void setDst_temp(float dst_temp) {
		this.dst_temp = dst_temp;
	}
	public float getDst_temp() {
		return this.dst_temp;
	}
	
	public void setCost(float cost) {
		this.cost = cost;
	}
	public float getCost() {
		return this.cost;
	}
	
	public void setOpenCost(float cost) {
		this.opencost = cost;
	}
	public float getOpenCost() {
		return this.opencost;
	}
	
	public void setSubcost(float cost) {
		this.subcost = cost;
	}
	public float getSubcost() {
		return this.subcost;
	}
	
	public void setEnergy(float energy) {
		this.energy = energy;
	}
	public float getEnergy() {
		return this.energy;
	}
	
	public void setIdentify(int identify) {
		this.identify = identify;
	}
	public int getIdentify() {
		return this.identify;
	}
	
	public void setEmpty(boolean empty) {
		this.empty = empty;
	}
	public boolean getEmpty() {
		return this.empty;
	}
	
	public void setSock(Socket sock) {
		this.sock = sock;
	}
	public Socket getSock() {
		return this.sock;
	}
	
}


class TempRoomInfo{
	public static Map<String,Room> roominfo = new HashMap<String,Room>();
	
	public static void updateRoomInfo(Room room) {
		if(roominfo.containsKey(room.getRoom_id())) {
			Room room_in_list = roominfo.get(room.getRoom_id());
			room_in_list.setSpeed(room.getSpeed());
			room_in_list.setCur_temp(room.getCur_temp());
			room_in_list.setDst_temp(room.getDst_temp());
			room_in_list.setCost(room.getCost());
			room_in_list.setEnergy(room.getEnergy());
			room_in_list.setIdentify(room.getIdentify());
			room_in_list.setState(room.getState());
		}
		else {
			roominfo.put(room.getRoom_id(), new Room(room));
		}
	}
	
	public static void removeRoom(Room room) {
		if(roominfo.containsKey(room.getRoom_id())) {
			roominfo.remove(room.getRoom_id());
		}
	}
	
	public static void getOldInfo(Room room) {
		if(roominfo.containsKey(room.getRoom_id())) {
			Room oldroom = roominfo.get(room.getRoom_id());
			room.setCost(oldroom.getCost());
			room.setEnergy(oldroom.getEnergy());
		}
	}
	
	
}
