package software;

import java.io.DataOutputStream;
import java.io.IOException;
import java.util.LinkedList;
import condition.*;

public class SchedulingStrategy extends Thread{
	public static final int rr_interval = 2;
	public static final int send_interval = 1;
	public static int sev_num;
	public static LinkedList<Room> que = new LinkedList<Room>();//���쳣�˳�ʱ����������Ӧ��roomҪ�����
	private ServerThread sth = new ServerThread();
	
	public void accept(Room room) {//�����ȼ������жϿ��Ƿ�Ҫ��ӷ���vip�����ŶӶ��е�ͷ
		if(que.contains(room)) {
			return;
		}
		
		if(room.getIdentify() == CmdConstant.VIP) {
			que.addFirst(room);
		}
		else {
			que.add(room);
		}
		
		room.setState(CmdConstant.WAIT);
		
	}
	
	public void run() {//�������߳���new
		LinkedList<Room> sevlist = new LinkedList<Room>();//�������
		Room room = null;
		DataOutputStream out = null;
		boolean computeFlag = true;
		
		while(true) {
			try {
				Thread.sleep(60000);
				System.out.println("sev_num:"+sev_num);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			int sevlen = sevlist.size();
			//System.out.println("sevlen:"+sevlen);
			for(;sevlen < SchedulingStrategy.sev_num && !que.isEmpty();) {
				room = que.poll();
				sevlist.add(room);
				room.setState(CmdConstant.COMPUTE);
				sevlen++;
				
			}
			
			if(sevlist.size() <= 0) {
				computeFlag = false;//�޷����ʱ���ṩ����
				//System.out.println("sevlist <= 0");
			}
			
			if(computeFlag) {
				System.out.println("into compute");
				/*
				try {
					Thread.sleep(000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}*/
				
				
				while(!sevlist.isEmpty()) {
					room = sevlist.poll();
					System.out.println("put state code sevlist:"+sevlist);
					System.out.println("compute room:"+room.getRoom_id());
					if(TcpServer.roomlist.contains(room)) {
						try {
							out =  new DataOutputStream(room.getSock().getOutputStream());
						} catch (IOException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}

						
						if(Setting.getMode() == CmdConstant.COLD && room.getDst_temp() >= room.getCur_temp()||Setting.getMode() == CmdConstant.HOT && room.getDst_temp() <= room.getCur_temp()) {
							sth.msgEncode_state(out,room.getRoom_id(),room.getCur_temp(),room.getDst_temp(),room.getSpeed(),room.getEnergy(),room.getCost());
							//�����¶�,��֪ͨ ͣ��֪ͨ ��״̬��Ϣ 
							sth.msgEncode_Halt(out,CmdConstant.HALT_CODE,room.getRoom_id());
							room.setState(CmdConstant.SLEEP);//�����޸�Ϊ����̬
							room.setStarttime("");//��շ�����ȿ�ʼʱ��
							//sevlist.remove(room);
							String stoptime = Time.timeChange();//�����ݿ�дͣ��ʱ�� 
							Add_state.update(room.getRoom_id(),stoptime,room.getSubcost());
							System.out.println("room:"+room.getRoom_id()+"before subcost:"+room.getSubcost());
							Add_state.add_state(room.getRoom_id(), CmdConstant.halt, stoptime,-1);
							System.out.println("room:"+room.getRoom_id()+"after subcost:"+room.getSubcost());
							room.setSubcost(0);
						}
						else {
							//���㻨�ѡ����ٺ��ܺ�
							ComputingStrategy.calculate_cost(room, 1);
							ComputingStrategy.calculate_temp(room, 1);
							ComputingStrategy.calculate_energy(room, 1);
							sth.msgEncode_state(out,room.getRoom_id(),room.getCur_temp(),room.getDst_temp(),room.getSpeed(),room.getEnergy(),room.getCost());
							//��״̬��Ϣ
							room.setState(CmdConstant.WAIT);
							accept(room);
							
						}
					}
					
				}
				
			
			}
			
			computeFlag = true;
		}
	
	}
	
	public void removeList(Room room) {
		que.remove(room);
	}
}
