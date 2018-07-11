package testWB;

import javax.swing.*;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import condition.*;
public class everyPrice extends JDialog{

	//private JFrame frame;
	private JTable table;
	private JButton button;
	private JButton buttonMore;
	private String RoomID;
	public speedtable speedTable;
	/**
	 * Launch the application.
	 */
	/*public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					everyPrice window = new everyPrice("0");
					window.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
*/
	/**
	 * Create the application.
	 */
	public everyPrice() {
		
	}

	/**
	 * Initialize the contents of the frame.
	 */
	public void initialize(String roomid) {
		//frame = new JFrame();
		long start0=System.currentTimeMillis();
		RoomID=roomid;
		//frame = new JFrame();
		setBounds(100, 100, 900, 344);
		setDefaultCloseOperation(JDialog.HIDE_ON_CLOSE);
		
		final String[] columnNames = {"序号","房间号","当前状态","调度时间","结束时间","费用"};
 		//Object [][] rowData = {{"2018-4-20-18:00","2018-4-21 7:00","温度","15","30.12"},{"2018-4-20-18:00","2018-4-21 7:00","风速","15","30.12"}};
		//int dataLine=
		
		int i;
		Room_state rs=new Room_state();
	//	long start1 = System.currentTimeMillis();
		 
		ArrayList<Room_state> roomList=rs.select_RoomState();
	//	long end1 = System.currentTimeMillis(); 
		
	//	System.out.println("select:"+(end1-start1));
		
	//	OnOff ooff=new OnOff();
		//ArrayList<OnOff> on_off=ooff.select();
		String change = null;
		int dataLine=roomList.size();
		Object [][] rowData= new Object[dataLine+1][6];
/*		for(i=0;i<roomList.size();i++)
		{
			if(roomList.get(i).getRoom_id().equals(roomid))
			{
				
			}
		}
	*/	
		//System.out.println(roomList.size());
		int j = -1 ;
	//	long start2=System.currentTimeMillis();
		for(i=0;i<roomList.size();i++)
		{	//System.out.println(roomList.size());
			if(roomList.get(i).getRoomId().equals(roomid))
			{	j++;
				//System.out.println(roomid);
				rowData[j][0] = roomList.get(i).getSeq();
				rowData[j][1] = roomList.get(i).getRoomId();
				int State =  roomList.get(i).getState();
				if(State==0) 
				{rowData[j][2] = "stop";}
				else if(State==2)
				{rowData[j][2]="halt";}
				else if(State==1)
				{rowData[j][2]="run";}
				 
				rowData[j][3] = roomList.get(i).getStartTime();
				rowData[j][4] = roomList.get(i).getStopTime();//结束时间
				rowData[j][5] = roomList.get(i).getCost();
		
			}
		
		}
		getContentPane().setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(0, 0, 663, 218);
		getContentPane().add(panel);
		panel.setLayout(null);
		
		
		table = new JTable(rowData,columnNames);
		table.setBounds(70, 5, 300, 32);
		//panel.add(table);
		table.setBackground(Color.WHITE);
		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		//setBounds(100, 100, 450, 300);
		//setDefaultCloseOperation(JDialog.HIDE_ON_CLOSE);
		
		JScrollPane scrollPane = new JScrollPane(table);
		scrollPane.setBounds(10, 10, 643, 177);
		
		panel.add(scrollPane);
		
		button = new JButton("\u5173\u95ED");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
				
				//System.exit(0);
			}
		});
		button.setBounds(296, 249, 93, 23);
		getContentPane().add(button);
		
		System.out.println("more");
		buttonMore = new JButton("More");
		buttonMore.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println("seq:"+table.getValueAt(table.getSelectedRow(), 0).toString());
				int seq=Integer.parseInt(table.getValueAt(table.getSelectedRow(), 0).toString());
				
				speedTable=new speedtable();
				speedTable.initialize(roomid, seq);
				speedTable.setVisible(true);
				speedTable.setBounds(100, 100, 536, 382);
							//System.exit(0);
			}
		});
		buttonMore.setBounds(396, 249, 93, 23);
		//System.out.println("more");
		getContentPane().add(buttonMore);
		//System.out.println("more");
		panel.setVisible(true);
		long end0=System.currentTimeMillis();
		//System.out.println("allep"+(end0-start0));
	}
	

}
