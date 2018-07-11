package testWB;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JInternalFrame;
import java.awt.BorderLayout;
import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.border.EtchedBorder;



import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowStateListener;
import java.math.BigDecimal;
import java.awt.event.ActionEvent;
import javax.swing.JScrollPane;
import java.awt.*;

import software.*;

public class server1 extends JFrame {

	public static JFrame frame;
//	private static JLabel wind5;
	public static JTextField textField;

	public static JPanel Rooms;
	public static JPanel room1;
	public static JLabel target1;
	public static JLabel targetTemp1;
	public static JLabel targetTemp1_c;
	public static JLabel now1;
	public static JLabel temp1;
	public static JLabel temp1_c;
	public static JLabel wind1_f;
	public static JLabel wind1;
	public static JLabel Room1_ct;
	public static JLabel Room1_cost;
	public static JPanel room2;
	public static JLabel targetTemp2;
	public static JLabel targetTemp2_c;
	public static JLabel temp2;
	public static JLabel temp2_c;
	public static JLabel wind2_f;
	public static JLabel wind2;
	public static JLabel Room2_ct;
	public static JLabel Room2_cost;
	public static JPanel room3;
	public static JLabel targetTemp3;
	public static JLabel targetTemp3_c;
	public static JLabel temp3;
	public static JLabel temp3_c;
	public static JLabel wind3_f;
	public static JLabel wind3;
	public static JLabel Room3_ct;
	public static JLabel Room3_cost;
	public static JPanel room4;
	public static JLabel targetTemp4;
	public static JLabel targetTemp4_c;
	public static JLabel temp4;
	public static JLabel temp4_c;
	public static JLabel wind4_f;
	public static JLabel wind4;
	public static JLabel Room4_ct;
	public static JLabel Room4_cost;
	public static JPanel room5;
	public static JLabel targetTemp5;
	public static JLabel targetTemp5_c;
	public static JLabel temp5;
	public static JLabel temp5_c;
	public static JLabel wind5_f;
	public static JLabel wind5;
	public static JLabel Room5_ct;
	public static JLabel Room5_cost;
	public static JPanel room6;
	public static JLabel targetTemp6;
	public static JLabel targetTemp6_c;
	public static JLabel temp6;
	public static JLabel temp6_c;
	public static JLabel wind6_f;
	public static JLabel wind6;
	public static JLabel Room6_ct;
	public static JLabel Room6_cost;
	public static JPanel room7;
	public static JLabel targetTemp7;
	public static JLabel targetTemp7_c;
	public static JLabel temp7;
	public static JLabel temp7_c;
	public static JLabel wind7_f;
	public static JLabel wind7;
	public static JLabel Room7_ct;
	public static JLabel Room7_cost;	
	public static JLabel Room1_t;
	public static JLabel Room2_t;
	public static JLabel Room3_t;
	public static JLabel Room4_t;
	public static JLabel Room5_t;
	public static JLabel Room6_t;
	public static JLabel Room7_t;
	public static JLabel Room1_O;
	public static JLabel Room2_O;
	public static JLabel Room3_O;
	public static JLabel Room4_O;
	public static JLabel Room5_O;
	public static JLabel Room6_O;
	public static JLabel Room7_O;
	public static JButton AllPrice_bt;
	public static JButton EveryPrice_bt;
	public static JButton priceSet_bt;
	public static JButton close_bt;
	public static JLabel label;//房间号
	public static JLabel label0;//多余
	public static JButton AllTable;
	
	public everyPrice ep;
	public AllPrice ap;
	public priceSet ps;
	public AllTable at;
	
	public static int i;
	//static Thread t;
	public static server1 window=new server1();
	//public static  server1 server11;  
	/**
	 * Launch the application.
	 */
	/*public static void main(String[] args) {
		window = new server1();
		//initialize();
	/*	window.setVisible(true);
	
		window.setBounds(100, 100, 814, 459);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.getContentPane().setLayout(null);
	*/	
	//}
	public static serverUI UIThread;

	public void newThread()
	{
		UIThread=new serverUI();
		UIThread.start();
	}
	public void initialize()
	{
		//setBackground(new Color(135,206,250));
		Rooms=new JPanel();
		Rooms.setBounds(21, 10, 710, 195);
		//Rooms.setBackground(new Color(225,255,255));
		Rooms.setBorder(new EtchedBorder(EtchedBorder.RAISED));
		window.getContentPane().add(Rooms);
		Rooms.setLayout(null);
		
		room1 = new JPanel();
		room1.setBounds(10, 10, 86, 104);
		room1.setBorder(new EtchedBorder(EtchedBorder.RAISED));
		Rooms.add(room1);
		room1.setLayout(null);
		
		room2 = new JPanel();
		room2.setBounds(110, 10, 86, 104);
		room2.setBorder(new EtchedBorder(EtchedBorder.RAISED));
		Rooms.add(room2);
		room2.setLayout(null);
		
		room3 = new JPanel();
		room3.setBounds(210, 10, 86, 104);
		room3.setBorder(new EtchedBorder(EtchedBorder.RAISED));
		Rooms.add(room3);
		room3.setLayout(null);
		
		room4 = new JPanel();
		room4.setBounds(310, 10, 86, 104);
		room4.setBorder(new EtchedBorder(EtchedBorder.RAISED));
		Rooms.add(room4);
		room4.setLayout(null);
		
		
		room5 = new JPanel();
		room5.setBounds(410, 10, 86, 104);
		room5.setBorder(new EtchedBorder(EtchedBorder.RAISED));
		Rooms.add(room5);
		room5.setLayout(null);
		
		room6 = new JPanel();
		room6.setBounds(510, 10, 86, 104);
		room6.setBorder(new EtchedBorder(EtchedBorder.RAISED));
		Rooms.add(room6);
		room6.setLayout(null);
		
		room7 = new JPanel();
		room7.setBounds(610, 10, 86, 104);
		room7.setBorder(new EtchedBorder(EtchedBorder.RAISED));
		Rooms.add(room7);
		room7.setLayout(null);
		
	/*	
		target1 = new JLabel("target");
		target1.setBounds(10, 9, 22, 24);
		target1.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		//temp1.setFont(new Font("Rockwell", Font.PLAIN, 20));
	room1.add(target1);
	*/	
		targetTemp1 = new JLabel("null");
		targetTemp1.setBounds(22, 9, 22, 24);
		targetTemp1.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		//temp1.setFont(new Font("Rockwell", Font.PLAIN, 20));
		room1.add(targetTemp1);

		targetTemp1_c = new JLabel("\u2103");
		targetTemp1_c.setBounds(55, 16, 21, 15);
		room1.add(targetTemp1_c);
		
		
		
		temp1 = new JLabel("null");
		temp1.setBounds(22, 24, 30, 24);//////////////////////////////////////
		temp1.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		//temp1.setFont(new Font("Rockwell", Font.PLAIN, 20));
		room1.add(temp1);

		temp1_c = new JLabel("\u2103");
		temp1_c.setBounds(55, 31, 21, 15);
		room1.add(temp1_c);
		
		wind1_f = new JLabel("\u98CE\u901F");
		wind1_f.setBounds(22, 58, 30, 15);
		room1.add(wind1_f);
		
		wind1 = new JLabel("null");
		wind1.setBounds(54, 58, 22, 15);
		room1.add(wind1);
		
		Room1_ct = new JLabel("\u8D39\u7528");
		Room1_ct.setBounds(10, 83, 30, 15);
		room1.add(Room1_ct);
		
		Room1_cost = new JLabel("null");
		Room1_cost.setBounds(46, 83, 30, 15);
		Room1_cost.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		room1.add(Room1_cost);
		

		
		targetTemp2 = new JLabel("null");
		targetTemp2.setBounds(21, 8, 22, 24);
		targetTemp2.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		//temp1.setFont(new Font("Rockwell", Font.PLAIN, 20));
		room2.add(targetTemp2);

		targetTemp2_c = new JLabel("\u2103");
		targetTemp2_c.setBounds(53, 15, 21, 15);
		room2.add(targetTemp2_c);
		
		temp2 = new JLabel("null");
		//temp2.setFont(new Font("Rockwell", Font.PLAIN, 20));
		temp2.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		temp2.setBounds(21, 23, 30, 24);/////////////////////////////////////////////
		room2.add(temp2);
		
		temp2_c = new JLabel("\u2103");
		temp2_c.setBounds(53, 30, 21, 15);
		room2.add(temp2_c);
		
		wind2_f = new JLabel("\u98CE\u901F");
		wind2_f.setBounds(21, 57, 30, 15);
		room2.add(wind2_f);
		
		wind2 = new JLabel("null");
		wind2.setBounds(53, 57, 22, 15);
		room2.add(wind2);
		
		Room2_ct = new JLabel("\u8D39\u7528");
		Room2_ct.setBounds(13, 82, 30, 15);
		room2.add(Room2_ct);
		
		Room2_cost = new JLabel("null");
		Room2_cost.setBounds(44, 82, 30, 15);
		Room2_cost.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		room2.add(Room2_cost);
			

		
		targetTemp3 = new JLabel("null");
		targetTemp3.setBounds(22, 8, 22, 24);
		targetTemp3.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		//temp1.setFont(new Font("Rockwell", Font.PLAIN, 20));
		room3.add(targetTemp3);

		targetTemp3_c = new JLabel("\u2103");
		targetTemp3_c.setBounds(54, 15, 21, 15);
		room3.add(targetTemp3_c);
		
		temp3 = new JLabel("null");
		//temp3.setFont(new Font("Rockwell", Font.PLAIN, 20));
		temp3.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		temp3.setBounds(22, 23, 30, 24);
		room3.add(temp3);
		
		temp3_c = new JLabel("\u2103");
		temp3_c.setBounds(54, 30, 21, 15);
		room3.add(temp3_c);
		
		wind3_f = new JLabel("\u98CE\u901F");
		wind3_f.setBounds(14, 57, 30, 15);
		room3.add(wind3_f);
		
		wind3 = new JLabel("null");
		wind3.setBounds(54, 57, 22, 15);
		room3.add(wind3);
		
		Room3_ct = new JLabel("\u8D39\u7528");
		Room3_ct.setBounds(10, 79, 30, 15);
		room3.add(Room3_ct);
		
		Room3_cost = new JLabel("null");
		Room3_cost.setBounds(50, 79, 30, 15);
		Room3_cost.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		room3.add(Room3_cost);

		
		targetTemp4 = new JLabel("null");
		targetTemp4.setBounds(20, 8, 22, 24);
		targetTemp4.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		//temp1.setFont(new Font("Rockwell", Font.PLAIN, 20));
		room4.add(targetTemp4);

		targetTemp4_c = new JLabel("\u2103");
		targetTemp4_c.setBounds(52, 15, 21, 15);
		room4.add(targetTemp4_c);
		
		
		temp4 = new JLabel("null");
		//temp4.setFont(new Font("Rockwell", Font.PLAIN, 20));
		temp4.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		temp4.setBounds(20, 23, 30, 24);
		room4.add(temp4);
		
		temp4_c = new JLabel("\u2103");
		temp4_c.setBounds(52, 30, 21, 15);
		room4.add(temp4_c);
		
		wind4_f = new JLabel("\u98CE\u901F");
		wind4_f.setBounds(12, 57, 30, 15);
		room4.add(wind4_f);
		
		wind4 = new JLabel("null");
		wind4.setBounds(51, 57, 22, 15);
		room4.add(wind4);
		
		Room4_ct = new JLabel("\u8D39\u7528");
		Room4_ct.setBounds(12, 82, 30, 15);
		room4.add(Room4_ct);
		
		Room4_cost = new JLabel("null");
		Room4_cost.setBounds(52, 82, 30, 15);
		Room4_cost.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		room4.add(Room4_cost);
		
		
		targetTemp5 = new JLabel("null");
		targetTemp5.setBounds(23, 6, 22, 24);
		targetTemp5.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		//temp1.setFont(new Font("Rockwell", Font.PLAIN, 20));
		room5.add(targetTemp5);

		targetTemp5_c = new JLabel("\u2103");
		targetTemp5_c.setBounds(55, 13, 21, 15);
		room5.add(targetTemp5_c);
		
		
		temp5 = new JLabel("null");
		//temp5.setFont(new Font("Rockwell", Font.PLAIN, 20));
		temp5.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		temp5.setBounds(23, 21, 30, 24);
		room5.add(temp5);
		
		
		
		wind5_f = new JLabel("\u98CE\u901F");
		wind5_f.setBounds(10, 55, 30, 15);
		room5.add(wind5_f);
		
		wind5 = new JLabel("null");
		wind5.setBounds(43, 55, 22, 15);
		room5.add(wind5);
		
		temp5_c = new JLabel("\u2103");
		temp5_c.setBounds(55, 28, 21, 15);
		room5.add(temp5_c);
		
		Room5_ct = new JLabel("\u8D39\u7528");
		Room5_ct.setBounds(15, 79, 30, 15);
		room5.add(Room5_ct);
		
		Room5_cost = new JLabel("null");
		Room5_cost.setBounds(53, 80, 30, 15);
		Room5_cost.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		room5.add(Room5_cost);
		

		
		targetTemp6 = new JLabel("null");
		targetTemp6.setBounds(10, 8, 22, 24);
		targetTemp6.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		//temp1.setFont(new Font("Rockwell", Font.PLAIN, 20));
		room6.add(targetTemp6);

		targetTemp6_c = new JLabel("\u2103");
		targetTemp6_c.setBounds(42,15, 21, 15);
		room6.add(targetTemp6_c);
		
		
		temp6 = new JLabel("null");
		//temp6.setFont(new Font("Rockwell", Font.PLAIN, 20));
		temp6.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		temp6.setBounds(10, 23, 30, 24);
		room6.add(temp6);
		
		wind6_f = new JLabel("\u98CE\u901F");
		wind6_f.setBounds(10, 57, 30, 15);
		room6.add(wind6_f);
		
		wind6 = new JLabel("null");
		wind6.setBounds(50, 57, 22, 15);
		room6.add(wind6);
		
		temp6_c = new JLabel("\u2103");
		temp6_c.setBounds(42, 30, 21, 15);
		room6.add(temp6_c);
		
		Room6_ct = new JLabel("\u8D39\u7528");
		Room6_ct.setBounds(10, 82, 30, 15);
		room6.add(Room6_ct);
		
		Room6_cost = new JLabel("null");
		Room6_cost.setBounds(42, 82, 30, 15);
		Room6_cost.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		room6.add(Room6_cost);
		

		
		targetTemp7 = new JLabel("null");
		targetTemp7.setBounds(21, 9, 22, 24);
		targetTemp7.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		//temp1.setFont(new Font("Rockwell", Font.PLAIN, 20));
		room7.add(targetTemp7);

		targetTemp7_c = new JLabel("\u2103");
		targetTemp7_c.setBounds(53, 17, 21, 15);
		room7.add(targetTemp7_c);
		
		temp7 = new JLabel("null");
		//temp7.setFont(new Font("Rockwell", Font.PLAIN, 20));
		temp7.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		temp7.setBounds(21, 24, 30, 24);
		room7.add(temp7);
		
		wind7_f = new JLabel("\u98CE\u901F");
		wind7_f.setBounds(10, 58, 30, 15);
		room7.add(wind7_f);
		
		wind7 = new JLabel("null");
		wind7.setBounds(50, 58, 22, 15);
		room7.add(wind7);
		
		temp7_c = new JLabel("\u2103");
		temp7_c.setBounds(53, 31, 21, 15);
		room7.add(temp7_c);
		
		Room7_ct = new JLabel("\u8D39\u7528");
		Room7_ct.setBounds(13, 83, 30, 15);
		room7.add(Room7_ct);
		
		Room7_cost = new JLabel("null");
		Room7_cost.setBounds(46, 83, 30, 15);
		Room7_cost.setFont(new Font(Font.DIALOG,Font.BOLD,10));
		room7.add(Room7_cost);
		
		Room1_t = new JLabel("Room1");
		Room1_t.setBounds(42, 124, 54, 15);
		Rooms.add(Room1_t);
		
		Room2_t = new JLabel("Room2");
		Room2_t.setBounds(138, 124, 54, 15);
		Rooms.add(Room2_t);
		
		Room3_t = new JLabel("Room3");
		Room3_t.setBounds(234, 124, 54, 15);
		Rooms.add(Room3_t);
		
		Room4_t = new JLabel("Room4");
		Room4_t.setBounds(330, 124, 54, 15);
		Rooms.add(Room4_t);
		
		Room5_t = new JLabel("Room5");
		Room5_t.setBounds(434, 124, 54, 15);
		Rooms.add(Room5_t);
		
		Room6_t = new JLabel("Room6");
		Room6_t.setBounds(530, 124, 54, 15);
		Rooms.add(Room6_t);
		
		Room7_t = new JLabel("Room7");
		Room7_t.setBounds(626, 124, 54, 15);
		Rooms.add(Room7_t);
		
		Room1_O = new JLabel("\u5173\u673A");
		Room1_O.setBounds(42, 149, 31, 15);
		Rooms.add(Room1_O);
		
		Room2_O = new JLabel("\u5173\u673A");
		Room2_O.setBounds(142, 149, 31, 15);
		Rooms.add(Room2_O);
		
		Room3_O = new JLabel("\u5173\u673A");
		Room3_O.setBounds(242, 149, 31, 15);
		Rooms.add(Room3_O);
		
		Room4_O = new JLabel("\u5173\u673A");
		Room4_O.setBounds(342, 149, 31, 15);
		Rooms.add(Room4_O);
		
		Room5_O = new JLabel("\u5173\u673A");
		Room5_O.setBounds(442, 149, 31, 15);
		Rooms.add(Room5_O);

		
		Room6_O = new JLabel("\u5173\u673A");
		Room6_O.setBounds(542, 149, 31, 15);
		Rooms.add(Room6_O);
		
		Room7_O = new JLabel("\u5173\u673A");
		Room7_O.setBounds(642, 149, 31, 15);
		Rooms.add(Room7_O);
		
		AllPrice_bt = new JButton("\u67E5\u770B\u8D26\u5355");
		
		AllPrice_bt.setBounds(210, 226, 93, 23);
		window.getContentPane().add(AllPrice_bt);
		
		textField = new JTextField();
		textField.setBounds(110, 227, 66, 21);
		window.getContentPane().add(textField);
		textField.setColumns(10);
		
		EveryPrice_bt = new JButton("\u67E5\u770B\u8BE6\u5355");
		
		EveryPrice_bt.setBounds(320, 226, 93, 23);
		window.getContentPane().add(EveryPrice_bt);
		
		 priceSet_bt = new JButton("\u8D39\u7387\u8BBE\u7F6E");
			
			priceSet_bt.setBounds(320, 289, 93, 23);
			window.getContentPane().add(priceSet_bt);
			
			 AllTable = new JButton("\u7EDF\u8BA1\u62A5\u8868");
				
			AllTable.setBounds(210, 289, 93, 23);
			window.getContentPane().add(AllTable);
			
			label = new JLabel("\u623F\u95F4\u53F7");//房间号
			label.setBounds(46, 230, 54, 15);
			window.getContentPane().add(label);			
			
			close_bt = new JButton("\u670D\u52A1\u7AEF\u5173\u673A");
			close_bt.setBounds(565, 255, 118, 23);
			window.getContentPane().add(close_bt);
		
			label0 = new JLabel("\u623F\u95F4\u53F7");//多余的
			label0.setBounds(46, 330, 54, 15);
			window.getContentPane().add(label0);		
			
			
				
			window.setVisible(true);
				
			window.setBounds(100, 100, 814, 459);
			window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			window.getContentPane().setLayout(null);	
			//详单
			window.EveryPrice_bt.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					
						ep=new everyPrice();
						ep.setBounds(100, 100, 900, 300);
						ep.setVisible(true);
						ep.initialize(window.textField.getText());
						
						
						window.EveryPrice_bt.setEnabled(false);

					
				}
			});
			
			//账单
			window.AllPrice_bt.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					ap = new AllPrice();
					ap.setBounds(100, 100, 700, 300);
					ap.initialize(window.textField.getText());
					ap.setVisible(true);
					
					window.AllPrice_bt.setEnabled(false);
				//	ap.show()
		
				}
			});
		
			//费率设置
			window.priceSet_bt.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					ps=new priceSet();
					ps.setBounds(100, 100, 539, 463);
					ps.initialize();
					ps.setVisible(true);
					
					window.priceSet_bt.setEnabled(false);
				}
			});
			
			window.AllTable.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					at=new AllTable();
					at.initialize();
					at.setVisible(true);
					at.setBounds(100, 100, 536, 382);
					window.AllTable.setEnabled(false);
				}
			});
			
			window.close_bt.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					window.setVisible(false);
					System.exit(0);
				//	Setting.saveLastKey(Time.timeChange());

				}
			});
			
		//Thread t=new Thread(window);
		//t.start();
	}
	
	/*	EventQueue.invokeLater(new Runnable() {
			
			
			public void run() {
				
				//int i=	Integer.parseInt(temp1.getText())+1;
				//temp1.setText(Integer.toString(i));
				try {
				
					server1 window = new server1();
					window.frame.setVisible(true);
					//Thread.sleep(1000);
					
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});*/
	

	/**
	 * Create the application.
	 */
	public server1() {
		
	}

	/**
	 * Initialize the contents of the frame.
	 */
}

	class serverUI extends Thread
	{
		public server1 serverMain;
		
		//private int i;
		public everyPrice ep=new everyPrice();
		public AllPrice ap = new AllPrice();
		public priceSet ps=new priceSet();
		public AllTable at=new AllTable();
		
		public void run() {
		
		
		while(true)
		{
			
		/*	i=	Integer.parseInt(serverMain.temp1.getText())+1;
			serverMain.temp1.setText(Integer.toString(i));*/
			//详单
		/*	serverMain.EveryPrice_bt.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					
					
						ep.setBounds(100, 100, 900, 300);
						ep.setVisible(true);
						ep.initialize(serverMain.textField.getText());
						
						
						serverMain.EveryPrice_bt.setEnabled(false);

					
				}
			});
			
			//账单
			serverMain.AllPrice_bt.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					
					ap.setBounds(100, 100, 600, 300);
					ap.initialize(serverMain.textField.getText());
					ap.setVisible(true);
					
					serverMain.AllPrice_bt.setEnabled(false);
				//	ap.show()
		
				}
			});
			
			//费率设置
			serverMain.priceSet_bt.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					ps.setBounds(100, 100, 539, 463);
					ps.initialize();
					ps.setVisible(true);
					
					serverMain.priceSet_bt.setEnabled(false);
				}
			});
			
			//查看报表
			serverMain.AllTable.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					at.initialize();
					at.setVisible(true);
					at.setBounds(100, 100, 536, 382);
					serverMain.AllTable.setEnabled(false);
				}
			});*/
			
			if(ps.isShowing()==false)
			{
				serverMain.priceSet_bt.setEnabled(true);
			}
			if(at.isShowing()==false)
			{
				serverMain.AllTable.setEnabled(true);
			}
			if(ep.isShowing()==false)
			{
				serverMain.EveryPrice_bt.setEnabled(true);
			}
			if(ap.isShowing()==false)
			{
				serverMain.AllPrice_bt.setEnabled(true);
			}
			
	if(TcpServer.roomlist.size()>=1)
	{	if(TcpServer.roomlist.get(0)!=null)
		{	
			Room room1In=TcpServer.roomlist.get(0);
			if(room1In.getIdentify()==1)
			{
				serverMain.Room1_t.setText(room1In.getRoom_id()+" VIP");
			}
			else
			{serverMain.Room1_t.setText(room1In.getRoom_id());}
			serverMain.temp1.setText(new BigDecimal(room1In.getCur_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
			serverMain.targetTemp1.setText(new BigDecimal(room1In.getDst_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
			if(room1In.getSpeed()==1)
				serverMain.wind1.setText("低");
			else if(room1In.getSpeed()==2)
				serverMain.wind1.setText("中");
			else if(room1In.getSpeed()==3)
				serverMain.wind1.setText("高");
			serverMain.Room1_cost.setText(Float.toString(room1In.getCost()));
			if(room1In.getState()==0)
				serverMain.Room1_O.setText("休眠");
			else if(room1In.getState()==1)
				serverMain.Room1_O.setText("计算");
			else if(room1In.getState()==2)
				serverMain.Room1_O.setText("等待");
			else if(room1In.getState()==3)
				serverMain.Room1_O.setText("关机");
			else if(room1In.getState()==4)
				serverMain.Room1_O.setText("开机");
			
		}
		if(TcpServer.roomlist.size()>=2)
		{
			if(TcpServer.roomlist.get(1)!=null)
			{	
				Room room2In=TcpServer.roomlist.get(1);
				if(room2In.getIdentify()==1)
				{
					serverMain.Room2_t.setText(room2In.getRoom_id()+" VIP");
				}
				else
				{serverMain.Room2_t.setText(room2In.getRoom_id());};
				serverMain.temp2.setText(new BigDecimal(room2In.getCur_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
				serverMain.targetTemp2.setText(new BigDecimal(room2In.getDst_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
				if(room2In.getSpeed()==1)
					serverMain.wind2.setText("低");
				else if(room2In.getSpeed()==2)
					serverMain.wind2.setText("中");
				else if(room2In.getSpeed()==3)
					serverMain.wind2.setText("高");
				serverMain.Room2_cost.setText(Float.toString(room2In.getCost()));
				if(room2In.getState()==0)
					serverMain.Room2_O.setText("休眠");
				else if(room2In.getState()==1)
					serverMain.Room2_O.setText("计算");
				else if(room2In.getState()==2)
					serverMain.Room2_O.setText("等待");
				else if(room2In.getState()==3)
					serverMain.Room2_O.setText("关机");
				else if(room2In.getState()==4)
					serverMain.Room2_O.setText("开机");
				
			}
			if(TcpServer.roomlist.size()>=3)
			{
				if(TcpServer.roomlist.get(2)!=null)
				{	
					Room room3In=TcpServer.roomlist.get(2);
					if(room3In.getIdentify()==1)
					{
						serverMain.Room3_t.setText(room3In.getRoom_id()+" VIP");
					}
					else
					{serverMain.Room3_t.setText(room3In.getRoom_id());};
					serverMain.temp3.setText(new BigDecimal(room3In.getCur_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
					serverMain.targetTemp3.setText(new BigDecimal(room3In.getDst_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
					if(room3In.getSpeed()==1)
						serverMain.wind3.setText("低");
					else if(room3In.getSpeed()==2)
						serverMain.wind3.setText("中");
					else if(room3In.getSpeed()==3)
						serverMain.wind3.setText("高");
					serverMain.Room3_cost.setText(Float.toString(room3In.getCost()));
					if(room3In.getState()==0)
						serverMain.Room3_O.setText("休眠");
					else if(room3In.getState()==1)
						serverMain.Room3_O.setText("计算");
					else if(room3In.getState()==2)
						serverMain.Room3_O.setText("等待");
					else if(room3In.getState()==3)
						serverMain.Room3_O.setText("关机");
					else if(room3In.getState()==4)
						serverMain.Room3_O.setText("开机");
					
				}
				if(TcpServer.roomlist.size()>=4)
				{
					if(TcpServer.roomlist.get(3)!=null)
					{	
						Room room4In=TcpServer.roomlist.get(3);
						if(room4In.getIdentify()==1)
						{
							serverMain.Room4_t.setText(room4In.getRoom_id()+" VIP");
						}
						else
						{serverMain.Room4_t.setText(room4In.getRoom_id());};
						serverMain.temp4.setText(new BigDecimal(room4In.getCur_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
						serverMain.targetTemp4.setText(new BigDecimal(room4In.getDst_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
						if(room4In.getSpeed()==1)
							serverMain.wind4.setText("低");
						else if(room4In.getSpeed()==2)
							serverMain.wind4.setText("中");
						else if(room4In.getSpeed()==3)
							serverMain.wind4.setText("高");
						serverMain.Room4_cost.setText(Float.toString(room4In.getCost()));
						if(room4In.getState()==0)
							serverMain.Room4_O.setText("休眠");
						else if(room4In.getState()==1)
							serverMain.Room4_O.setText("计算");
						else if(room4In.getState()==2)
							serverMain.Room4_O.setText("等待");
						else if(room4In.getState()==3)
							serverMain.Room4_O.setText("关机");
						else if(room4In.getState()==4)
							serverMain.Room4_O.setText("开机");
						
					}
					
						if(TcpServer.roomlist.size()>=5)
						{
							if(TcpServer.roomlist.get(4)!=null)
							{	
								Room room5In=TcpServer.roomlist.get(4);
								if(room5In.getIdentify()==1)
								{
									serverMain.Room5_t.setText(room5In.getRoom_id()+" VIP");
								}
								else
								{serverMain.Room5_t.setText(room5In.getRoom_id());};
								serverMain.temp5.setText(new BigDecimal(room5In.getCur_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
								serverMain.targetTemp5.setText(new BigDecimal(room5In.getDst_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
								if(room5In.getSpeed()==1)
									serverMain.wind5.setText("低");
								else if(room5In.getSpeed()==2)
									serverMain.wind5.setText("中");
								else if(room5In.getSpeed()==3)
									serverMain.wind5.setText("高");
								serverMain.Room5_cost.setText(Float.toString(room5In.getCost()));
								if(room5In.getState()==0)
									serverMain.Room5_O.setText("休眠");
								else if(room5In.getState()==1)
									serverMain.Room5_O.setText("计算");
								else if(room5In.getState()==2)
									serverMain.Room5_O.setText("等待");
								else if(room5In.getState()==3)
									serverMain.Room5_O.setText("关机");
								else if(room5In.getState()==4)
									serverMain.Room5_O.setText("开机");
								
							}
							if(TcpServer.roomlist.size()>=6)
							{
								if(TcpServer.roomlist.get(5)!=null)
								{	
									Room room6In=TcpServer.roomlist.get(5);
									if(room6In.getIdentify()==1)
									{
										serverMain.Room6_t.setText(room6In.getRoom_id()+" VIP");
									}
									else
									{serverMain.Room6_t.setText(room6In.getRoom_id());};
									serverMain.temp6.setText(new BigDecimal(room6In.getCur_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
									serverMain.targetTemp6.setText(new BigDecimal(room6In.getDst_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
									if(room6In.getSpeed()==1)
										serverMain.wind6.setText("低");
									else if(room6In.getSpeed()==2)
										serverMain.wind6.setText("中");
									else if(room6In.getSpeed()==3)
										serverMain.wind6.setText("高");
									serverMain.Room6_cost.setText(Float.toString(room6In.getCost()));
									if(room6In.getState()==0)
										serverMain.Room6_O.setText("休眠");
									else if(room6In.getState()==1)
										serverMain.Room6_O.setText("计算");
									else if(room6In.getState()==2)
										serverMain.Room6_O.setText("等待");
									else if(room6In.getState()==3)
										serverMain.Room6_O.setText("关机");
									else if(room6In.getState()==4)
										serverMain.Room6_O.setText("开机");
									
								}
								if(TcpServer.roomlist.size()>=7)
								{
									if(TcpServer.roomlist.get(6)!=null)
									{	
										Room room7In=TcpServer.roomlist.get(6);
										if(room7In.getIdentify()==1)
										{
											serverMain.Room7_t.setText(room7In.getRoom_id()+" VIP");
										}
										else
										{serverMain.Room7_t.setText(room7In.getRoom_id());};
										serverMain.temp7.setText(new BigDecimal(room7In.getCur_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
										serverMain.targetTemp7.setText(new BigDecimal(room7In.getDst_temp()).setScale(1, BigDecimal.ROUND_HALF_UP).toString());
										if(room7In.getSpeed()==1)
											serverMain.wind7.setText("低");
										else if(room7In.getSpeed()==2)
											serverMain.wind7.setText("中");
										else if(room7In.getSpeed()==3)
											serverMain.wind7.setText("高");
										serverMain.Room7_cost.setText(Float.toString(room7In.getCost()));
										if(room7In.getState()==0)
											serverMain.Room7_O.setText("休眠");
										else if(room7In.getState()==1)
											serverMain.Room7_O.setText("计算");
										else if(room7In.getState()==2)
											serverMain.Room7_O.setText("等待");
										else if(room7In.getState()==3)
											serverMain.Room7_O.setText("关机");
										else if(room7In.getState()==4)
											serverMain.Room7_O.setText("开机");
										
									}
								}
								else {
									serverMain.Room7_t.setText("Room7");
									serverMain.temp7.setText("null");
									serverMain.targetTemp7.setText("null");
									serverMain.wind7.setText("null");
									serverMain.Room7_cost.setText("null");
									serverMain.Room7_O.setText("关机");
								}
							}
							else {
								serverMain.Room6_t.setText("Room6");
								serverMain.temp6.setText("null");
								serverMain.targetTemp6.setText("null");
								serverMain.wind6.setText("null");
								serverMain.Room6_cost.setText("null");
								serverMain.Room6_O.setText("关机");
							}
						}
						else {
							serverMain.Room5_t.setText("Room5");
							serverMain.temp5.setText("null");
							serverMain.targetTemp5.setText("null");
							serverMain.wind5.setText("null");
							serverMain.Room5_cost.setText("null");
							serverMain.Room5_O.setText("关机");
						}
				}
				else
				{
					serverMain.Room4_t.setText("Room4");
					serverMain.temp4.setText("null");
					serverMain.targetTemp4.setText("null");
					serverMain.wind4.setText("null");
					serverMain.Room4_cost.setText("null");
					serverMain.Room4_O.setText("关机");
					
				}
			}
			else {
				serverMain.Room3_t.setText("Room3");
				serverMain.temp3.setText("null");
				serverMain.targetTemp3.setText("null");
				serverMain.wind3.setText("null");
				serverMain.Room3_cost.setText("null");
				serverMain.Room3_O.setText("关机");
				
			}
			
		}
		else{
			serverMain.Room2_t.setText("Room2");
			serverMain.temp2.setText("null");
			serverMain.targetTemp2.setText("null");
			serverMain.wind2.setText("null");
			serverMain.Room2_cost.setText("null");
			serverMain.Room2_O.setText("关机");
			}
		
	}
	
		else {
				serverMain.Room1_t.setText("Room1");
				serverMain.temp1.setText("null");
				serverMain.targetTemp1.setText("null");
				serverMain.wind1.setText("null");
				serverMain.Room1_cost.setText("null");
				serverMain.Room1_O.setText("关机");
		}
		

		//还未加其他房间
	
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
	

	}

