package testWB;

import javax.swing.*;
import java.awt.EventQueue;

import javax.swing.JFrame;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.ActionEvent;

import software.*;
public class priceSet extends JDialog {
	private JTextField Low_set;
	private JTextField High_set;
	private JTextField Med_set;
	private JTextField basicC_text;
	private server1 serverMainP;
	public Setting Setting=new Setting();
	//private JFrame frame;

	/**
	 * Launch the application.
	 */
/*	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					priceSet window = new priceSet();
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
	public priceSet() {
		setTitle("费率");
		//initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	public void initialize() {
		//frame = new JFrame();
		//setBounds(100, 100, 539, 463);
		setDefaultCloseOperation(JDialog.HIDE_ON_CLOSE);
		getContentPane().setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(44, 10, 200, 310);
		getContentPane().add(panel);
		panel.setLayout(null);
		
		JLabel label = new JLabel("\u5F53\u524D\u8D39\u7387");
		label.setBounds(74, 10, 54, 15);
		panel.add(label);
		
		JLabel label_2 = new JLabel("\u98CE\u901F");
		label_2.setBounds(10, 48, 54, 15);
		panel.add(label_2);
		
		JLabel label_3 = new JLabel("\u4E2D");
		label_3.setBounds(20, 102, 33, 15);
		panel.add(label_3);
		
		JLabel High_now = new JLabel("3");
		High_now.setBounds(74, 127, 20, 15);
		panel.add(High_now);
		
		JLabel label_5 = new JLabel("\u5143/\u5206\u949F");
		label_5.setBounds(120, 102, 49, 15);
		panel.add(label_5);
		
		JLabel label_6 = new JLabel("\u4F4E");
		label_6.setBounds(20, 77, 33, 15);
		panel.add(label_6);
		
		JLabel label_7 = new JLabel("\u5143/\u5206\u949F");
		label_7.setBounds(120, 77, 49, 15);
		panel.add(label_7);
		
		JLabel Low_now = new JLabel("1");
		Low_now.setBounds(74, 77, 20, 15);
		panel.add(Low_now);
		
		JLabel label_9 = new JLabel("\u9AD8");
		label_9.setBounds(20, 127, 33, 15);
		panel.add(label_9);
		
		JLabel Medium_now = new JLabel("2");
		Medium_now.setBounds(74, 102, 20, 15);
		panel.add(Medium_now);
		
		JLabel label_11 = new JLabel("\u5143/\u5206\u949F");
		label_11.setBounds(120, 127, 49, 15);
		panel.add(label_11);
		
		JLabel label_8 = new JLabel("\u666E\u901A");
		label_8.setBounds(84, 34, 34, 15);
		panel.add(label_8);
		
		JLabel lblVip = new JLabel("VIP");
		lblVip.setBounds(84, 157, 34, 15);
		panel.add(lblVip);
		
		JLabel label_19 = new JLabel("\u98CE\u901F");
		label_19.setBounds(10, 171, 54, 15);
		panel.add(label_19);
		
		JLabel label_20 = new JLabel("\u4F4E");
		label_20.setBounds(20, 200, 33, 15);
		panel.add(label_20);
		
		JLabel label_21 = new JLabel("\u4E2D");
		label_21.setBounds(20, 225, 33, 15);
		panel.add(label_21);
		
		JLabel label_22 = new JLabel("\u9AD8");
		label_22.setBounds(20, 250, 33, 15);
		panel.add(label_22);
		
		JLabel v_Low_now = new JLabel("1.5");
		v_Low_now.setBounds(74, 200, 20, 15);
		panel.add(v_Low_now);
		
		JLabel v_Med_now = new JLabel("2.5");
		v_Med_now.setBounds(74, 225, 20, 15);
		panel.add(v_Med_now);
		
		JLabel v_High_now = new JLabel("3.5");
		v_High_now.setBounds(74, 250, 20, 15);
		panel.add(v_High_now);
		
		JLabel label_26 = new JLabel("\u5143/\u5206\u949F");
		label_26.setBounds(120, 200, 49, 15);
		panel.add(label_26);
		
		JLabel label_27 = new JLabel("\u5143/\u5206\u949F");
		label_27.setBounds(120, 225, 49, 15);
		panel.add(label_27);
		
		JLabel label_28 = new JLabel("\u5143/\u5206\u949F");
		label_28.setBounds(120, 250, 49, 15);
		panel.add(label_28);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBounds(283, 10, 209, 310);
		getContentPane().add(panel_1);
		panel_1.setLayout(null);
		
		JLabel label_1 = new JLabel("\u8C03\u6574\u8D39\u7387");
		label_1.setBounds(88, 10, 54, 15);
		panel_1.add(label_1);
		
		JLabel label_12 = new JLabel("\u98CE\u901F");
		label_12.setBounds(10, 45, 54, 15);
		panel_1.add(label_12);
		
		JLabel label_13 = new JLabel("\u4F4E");
		label_13.setBounds(20, 77, 33, 15);
		panel_1.add(label_13);
		
		JLabel label_14 = new JLabel("\u4E2D");
		label_14.setBounds(20, 102, 33, 15);
		panel_1.add(label_14);
		
		JLabel label_15 = new JLabel("\u9AD8");
		label_15.setBounds(20, 127, 33, 15);
		panel_1.add(label_15);
		
		JLabel label_16 = new JLabel("\u5143/\u5206\u949F");
		label_16.setBounds(131, 77, 49, 15);
		panel_1.add(label_16);
		
		JLabel label_17 = new JLabel("\u5143/\u5206\u949F");
		label_17.setBounds(131, 102, 49, 15);
		panel_1.add(label_17);
		
		JLabel label_18 = new JLabel("\u5143/\u5206\u949F");
		label_18.setBounds(131, 127, 49, 15);
		panel_1.add(label_18);
		
		Low_set = new JTextField();
		Low_set.setBounds(63, 75, 49, 18);
		panel_1.add(Low_set);
		Low_set.setColumns(10);
		
		High_set = new JTextField();
		High_set.setColumns(10);
		High_set.setBounds(63, 125, 49, 18);
		panel_1.add(High_set);
		
		Med_set = new JTextField();
		Med_set.setColumns(10);
		Med_set.setBounds(63, 100, 49, 18);
		panel_1.add(Med_set);
		
		Low_now.setText(Float.toString(Setting.getLPremium_rate()));
		Medium_now.setText(Float.toString(Setting.getMPremium_rate()));
		High_now.setText(Float.toString(Setting.getHPremium_rate()));
		
		v_Low_now.setText(Float.toString(Setting.getLVPremium_rate()));
		v_Med_now.setText(Float.toString(Setting.getMVPremium_rate()));
		v_High_now.setText(Float.toString(Setting.getHVPremium_rate()));
		
		JRadioButton Ord_RB = new JRadioButton("\u666E\u901A");
		Ord_RB.setBounds(29, 159, 60, 23);
		panel_1.add(Ord_RB);
		
		JRadioButton VIP_RB = new JRadioButton("VIP");
		VIP_RB.setBounds(120, 159, 60, 23);
		panel_1.add(VIP_RB);
		//加到同一个button组中，只能单选
		ButtonGroup btnGroup = new ButtonGroup();
		btnGroup.add(Ord_RB);
		btnGroup.add(VIP_RB);
		
		JButton submit = new JButton("\u63D0\u4EA4\u8C03\u6574");
		submit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
			
				 
				if(Ord_RB.isSelected()==true)
				{	if(Low_set.getText().equals("")||Float.parseFloat(Low_set.getText())<0)
						{}
					else
						{Setting.setLPremium_rate(Float.parseFloat(Low_set.getText()));}
					if(Med_set.getText().equals("")||Float.parseFloat(Med_set.getText())<0)
						{}
					else
						{Setting.setMPremium_rate(Float.parseFloat(Med_set.getText()));}
					if(High_set.getText().equals("")||Float.parseFloat(High_set.getText())<0)
						{}
					else
						{Setting.setHPremium_rate(Float.parseFloat(High_set.getText()));}
				}
				else if(VIP_RB.isSelected()==true)
				{
					if(Low_set.getText().equals("")||Float.parseFloat(Low_set.getText())<0)
						{}
					else
						{Setting.setLVPremium_rate(Float.parseFloat(Low_set.getText()));}
					if(Med_set.getText().equals("")||Float.parseFloat(Med_set.getText())<0)
						{}
					else
						{Setting.setMVPremium_rate(Float.parseFloat(Med_set.getText()));}
					if(Med_set.getText().equals("")||Float.parseFloat(Med_set.getText())<0)
						{}
					else
						{Setting.setHVPremium_rate(Float.parseFloat(High_set.getText()));}
				}
				
				if(basicC_text.getText().equals("")||Float.parseFloat(basicC_text.getText())<0)
					{}
				else
					{Setting.setVIP_basic(Float.parseFloat(basicC_text.getText()));}
		
				
				Low_now.setText(Float.toString(Setting.getLPremium_rate()));
				Medium_now.setText(Float.toString(Setting.getMPremium_rate()));
				High_now.setText(Float.toString(Setting.getHPremium_rate()));
				
				v_Low_now.setText(Float.toString(Setting.getLVPremium_rate()));
				v_Med_now.setText(Float.toString(Setting.getMVPremium_rate()));
				v_High_now.setText(Float.toString(Setting.getHVPremium_rate()));
				
				
			}
		});
		submit.setBounds(49, 258, 93, 23);
		panel_1.add(submit);
		
		JLabel Vipbasic_t = new JLabel("VIP\u57FA\u51C6\u4EF7\u683C");
		Vipbasic_t.setBounds(10, 190, 79, 15);
		panel_1.add(Vipbasic_t);
		
		basicC_text = new JTextField();
		basicC_text.setColumns(10);
		basicC_text.setBounds(63, 215, 49, 18);
		panel_1.add(basicC_text);
		
		JLabel label_4 = new JLabel("\u5143");
		label_4.setBounds(131, 217, 33, 15);
		panel_1.add(label_4);
		

		
		

	}
	

}
