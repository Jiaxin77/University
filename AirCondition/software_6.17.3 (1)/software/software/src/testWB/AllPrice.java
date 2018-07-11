package testWB;

import java.awt.EventQueue;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import javax.swing.table.DefaultTableModel;

import java.awt.Color;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.awt.event.ActionEvent;
import condition.*;
public class AllPrice extends JDialog{

	//private JFrame frame;
	private JTable table;
	private JButton button;
	private String RoomID;
	public ArrayList<Room_state> on_off;
	public Room_state rs=new Room_state();
	public JLabel totalPrice_t;
	public JLabel totalPrice;
	/**
	 * Launch the application.
	 */
	/*public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					AllPrice window = new AllPrice("0");
					
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
	public AllPrice() {
		
		
	}

	/**
	 * Initialize the contents of the frame.
	 */
	public void initialize(String roomid) {
		RoomID=roomid;
		//frame = new JFrame();
		setBounds(100, 100, 450, 300);
		setDefaultCloseOperation(JDialog.HIDE_ON_CLOSE);
		on_off=rs.select_OnOff(roomid);
		final String[] columnNames = {"房号","开机时间","关机时间","费用"};
 		//Object [][] rowData = {{"2018-4-20-18:00","2018-4-21 7:00","15","30.12"},{"2018-4-20-18:00","2018-4-21 7:00","15","30.12"}};
		Object [][] rowData= new Object[on_off.size()+1][4];
		int i;
		Room_state rs=new Room_state();
		ArrayList<Room_state> roomList=rs.select_RoomState();
		
		
		int j=-1;
		for(i=0;i<on_off.size();i++)
		{
			if(roomid.equals(on_off.get(i).getRoomId()))
			{	j++;
				rowData[j][0] = on_off.get(i).getRoomId();
				rowData[j][1] = on_off.get(i).getStartTime();
			//	rowData[i][1] = roomList.get(i).getstart_time();
				rowData[j][2] = on_off.get(i).getStopTime();
				rowData[j][3] = on_off.get(i).getCost();
			}
		}
		
		getContentPane().setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(0, 0, 550, 166);
		getContentPane().add(panel);
		panel.setLayout(null);
		
		
		table = new JTable(rowData,columnNames);
		table.setBounds(70, 5, 300, 32);
		//panel.add(table);
		table.setBackground(Color.WHITE);
		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

		JScrollPane scrollPane = new JScrollPane(table);
		scrollPane.setBounds(10, 10, 434, 157);
		panel.add(scrollPane);
		
		button = new JButton("\u5173\u95ED");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
				
				//System.exit(0);
			}
		});
		button.setBounds(173, 206, 93, 23);
		getContentPane().add(button);
		
		totalPrice_t=new JLabel("总价");
		//JLabel label_6 = new JLabel("\u7ED3\u675F\u65F6\u95F4");
 		totalPrice_t.setBounds(373, 206, 93, 23);
 		getContentPane().add(totalPrice_t);
 		
 		rs.SumCost(roomid);
 		String sum=Float.toString(rs.sum);
 		System.out.println(rs.sum);
		System.out.println(sum);
 		totalPrice=new JLabel(sum);
		//JLabel label_6 = new JLabel("\u7ED3\u675F\u65F6\u95F4");
 		totalPrice.setBounds(473, 206, 93, 23);
 		getContentPane().add(totalPrice);
 		
		panel.setVisible(true);
	}
}
