package testWB;

import javax.swing.*;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import condition.*;
public class speedtable extends JDialog{

	//private JFrame frame;
	private JTable table;
	private JButton button;
	private String RoomID;
	private int logID;
	public SpeedState speed=new SpeedState();
	public ArrayList<SpeedState> SpeedList;
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
	public speedtable() {
		
	}

	/**
	 * Initialize the contents of the frame.
	 */
	public void initialize(String roomid,int logID) {
		//frame = new JFrame();
		//long start0=System.currentTimeMillis();
		RoomID=roomid;
		//frame = new JFrame();
		setBounds(100, 100, 900, 344);
		setDefaultCloseOperation(JDialog.HIDE_ON_CLOSE);
		SpeedList=speed.select_SpeedState(logID, roomid);
		final String[] columnNames = {"房间号","调整时间","调整后风速","费率"};
		Object [][] rowData= new Object[SpeedList.size()+1][11];
		int j=-1;
		for(int i=0;i<SpeedList.size();i++)
		{	
			if(SpeedList.get(i).getRoomId().equals(roomid))
			{	j++;	
				rowData[j][0]=SpeedList.get(i).getRoomId();
				rowData[j][1]=SpeedList.get(i).getModifyTime();
				int WindSpeed=SpeedList.get(i).getSpeed();
				if (WindSpeed==1)
					{rowData[j][2]="low";}
				else if(WindSpeed==2)
					{rowData[j][2]="medium";}
				else if(WindSpeed==3)
					{rowData[j][2]="high";}
				rowData[j][3]=SpeedList.get(i).getCostRate();
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
		

		panel.setVisible(true);
		
	}
	

}
