package testWB;

import javax.swing.*;
import java.awt.EventQueue;
import java.awt.Choice;
import java.awt.Color;
import java.awt.Checkbox;
import java.awt.Button;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import condition.*;
public class AllTable extends JDialog {

	//private JFrame frame;
	private JTable table;
	private static int new_year;
	/**
	 * Launch the application.
	 */
	/*public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					AllTable window = new AllTable();
					window.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
*/	/*public static void main(String[] args)
	{
	AllTable window = new AllTable();
	window.setVisible(true);
	}*/
	
	/**
	 * Create the application.
	 */
	public AllTable() {
		//initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	public void initialize() {
		//frame = new JFrame();
		setBounds(100, 100, 536, 382);
		setDefaultCloseOperation(JDialog.HIDE_ON_CLOSE);
		getContentPane().setLayout(null);
		Report re=new Report();
		
		final String[] columnNames = {"最常用温度","最常用风速","使用次数","调度次数"};
 		Object [][] rowData=new Object[1][5];
 		
		
		
		JLabel label = new JLabel("\u8D77\u59CB\u65F6\u95F4");
		label.setBounds(20, 274, 51, 15);
		getContentPane().add(label);
		//System.out.println("1");
		NewTime nt=new NewTime();
		//System.out.println("2");
		String newtime=nt.SelectNewTime();
		//System.out.println(newtime);
		String newyear=newtime.substring(0,4);
		//System.out.println(newyear);
		new_year=Integer.parseInt(newyear);
		//System.out.println(new_year);
		//new_year=2018;//从李叶处拿到
		Choice year_begin = new Choice();
		year_begin.setBounds(77, 268, 58, 15);
		for(int year_count=2018;year_count<=new_year;year_count++)
		{
			year_begin.add(Integer.toString(year_count));
		}
		getContentPane().add(year_begin);
		
 		Choice month_begin = new Choice();
 		month_begin.setBounds(164, 268, 44, 21);
		for(int month_count=1;month_count<=12;month_count++)
		{
			month_begin.add(Integer.toString(month_count));
		}
 		getContentPane().add(month_begin);
 		
 		Choice day_begin = new Choice();
 		day_begin.setBounds(240, 268, 44, 21);
 		int select=Integer.parseInt(month_begin.getSelectedItem());
 		if(select==1||select==3||select==5||select==7||select==8||select==10||select==12)
 		{
 			for(int day_count=1;day_count<=31;day_count++)
 			{
 				day_begin.add(Integer.toString(day_count));
 			}
 		}
 		else
 		{
 			for(int day_count=1;day_count<=30;day_count++)
 			{
 				day_begin.add(Integer.toString(day_count));
 			}
 		}
 			getContentPane().add(day_begin);
 		
		
	
		
		JPanel panel = new JPanel();
		panel.setBounds(10, 5, 500, 253);
		getContentPane().add(panel);
 		panel.setLayout(null);
 		//scrollPane.setViewportView(table);
 		//System.out.println(re.getComm_temp());

 		table = new JTable(rowData,columnNames);
 		table.setBounds(280, 10, -265, 263);
 		//panel.add(table);
 		table.setBackground(Color.WHITE);
 		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		//setBounds(100, 100, 450, 300);
		//setDefaultCloseOperation(JDialog.HIDE_ON_CLOSE);
 		//panel.setLayout(null);
 		
 		JScrollPane scrollPane = new JScrollPane(table);
 		scrollPane.setBounds(0, 5, 500, 220);
 		panel.add(scrollPane);
 		
 		JLabel label_1 = new JLabel("\u5E74");
 		label_1.setBounds(147, 274, 20, 15);
 		getContentPane().add(label_1);
 		


 		
 		
 		JLabel lblNewLabel = new JLabel("\u6708");
 		lblNewLabel.setBounds(214, 274, 20, 15);
 		getContentPane().add(lblNewLabel);
 		
 		JLabel label_2 = new JLabel("\u65E5");
 		label_2.setBounds(298, 274, 26, 15);
 		getContentPane().add(label_2);
 		
 		Choice year_end = new Choice();
 		year_end.setBounds(77, 296, 58, 21);
		for(int year_count=2018;year_count<=new_year;year_count++)
		{
			year_end.add(Integer.toString(year_count));
		}
 		getContentPane().add(year_end);
 		
 		JLabel label_3 = new JLabel("\u5E74");
 		label_3.setBounds(147, 302, 15, 15);
 		getContentPane().add(label_3);
 		
 		Choice month_end = new Choice();
 		month_end.setBounds(164, 296, 44, 21);
		for(int month_count=1;month_count<=12;month_count++)
		{
			month_end.add(Integer.toString(month_count));
		}
 		getContentPane().add(month_end);
 		
 		JLabel label_4 = new JLabel("\u6708");
 		label_4.setBounds(214, 302, 20, 15);
 		getContentPane().add(label_4);
 		
 		Choice day_end = new Choice();
 		day_end.setBounds(240, 296, 44, 21);
 		int select2=Integer.parseInt(month_end.getSelectedItem());
 		if(select2==1||select2==3||select2==5||select2==7||select2==8||select2==10||select2==12)
 		{
 			for(int day_count=1;day_count<=31;day_count++)
 			{
 				day_end.add(Integer.toString(day_count));
 			}
 		}
 		else
 		{
 			for(int day_count=1;day_count<=30;day_count++)
 			{
 				day_end.add(Integer.toString(day_count));
 			}
 		}
 		getContentPane().add(day_end);
 		
 		
 		JLabel label_5 = new JLabel("\u65E5");
 		label_5.setBounds(298, 302, 26, 15);
 		getContentPane().add(label_5);
 		
 	
 		
 		Button button = new Button("\u67E5\u770B\u62A5\u8868");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
	 	 		int SelectYear_begin=Integer.parseInt(year_begin.getSelectedItem());
	 	 		int SelectMonth_begin=Integer.parseInt(month_begin.getSelectedItem());
	 	 		int SelectDay_begin=Integer.parseInt(day_begin.getSelectedItem());	
	 	 		int SelectYear_end=Integer.parseInt(year_end.getSelectedItem());
	 	 		int SelectMonth_end=Integer.parseInt(month_end.getSelectedItem());
	 	 		int SelectDay_end=Integer.parseInt(day_end.getSelectedItem());
	 	 		String GiveDatabasebegin=SelectYear_begin+"-"+SelectMonth_begin+"-"+SelectDay_begin;
	 	 		String GiveDatabaseend=SelectYear_end+"-"+SelectMonth_end+"-"+SelectDay_end;
				System.out.print(GiveDatabasebegin);
				System.out.print(GiveDatabaseend);
				//re.setStartTime(GiveDatabasebegin);
				//re.setStopTime(GiveDatabaseend);
				
				re.select(GiveDatabasebegin, GiveDatabaseend);
		 		rowData[0][0]=Float.toString(re.getComm_temp());
		 		rowData[0][1]=Integer.toString(re.getComm_speed());
		 		rowData[0][2]=Integer.toString(re.getUse_count());
		 		rowData[0][3]=Integer.toString(re.getSchedule_count());
		 		
		 		
			}
		});
		button.setBounds(414, 294, 76, 23);
		getContentPane().add(button);
 		
 		JLabel label_6 = new JLabel("\u7ED3\u675F\u65F6\u95F4");
 		label_6.setBounds(20, 299, 51, 15);
 		getContentPane().add(label_6);
 		//scrollPane.setLayout(null);
 		
 		
 		
 		
 		panel.setVisible(true);
	}
}
