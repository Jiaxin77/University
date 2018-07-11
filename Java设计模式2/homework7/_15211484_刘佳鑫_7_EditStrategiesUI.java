package homework7;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class _15211484_刘佳鑫_7_EditStrategiesUI extends JDialog {

	private JTextField nameText;
	private JTextField StypeText;
	private JTextField BtypeText;
	private JTextField countText;
	private JTextField chooseSText;//组合策略中选择哪几个策略组合的
	private JButton OKbutton;
	private JButton cancelButton;
	
    private static _15211484_刘佳鑫_7_Controller controller;
    

	public _15211484_刘佳鑫_7_EditStrategiesUI(String key,_15211484_刘佳鑫_7_StrategyCatalog strategies,int Flag)
	{
		
		controller=new _15211484_刘佳鑫_7_Controller();
		setTitle("editStrategy");
		JPanel inputPanel = new JPanel();
		JPanel buttonPanel = new JPanel();
		
		inputPanel.setLayout(new GridLayout(6,2));

		inputPanel.add(new JLabel("StrategyName:"));
		nameText=new JTextField();
		nameText.setColumns(10);
		inputPanel.add(nameText);
		
		inputPanel.add(new JLabel("StrategyType:"));
		StypeText=new JTextField();
		StypeText.setColumns(10);
		inputPanel.add(StypeText);
		
		inputPanel.add(new JLabel("BookType:"));
		BtypeText=new JTextField();
		BtypeText.setColumns(10);
		inputPanel.add(BtypeText);
		
		if(Flag==0)//简单策略
		{
			inputPanel.add(new JLabel("count:"));
			countText=new JTextField();
			countText.setColumns(10);
			inputPanel.add(countText);
		
			
			OKbutton= new JButton("OK");
			OKbutton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				controller.updateSimpleStrategy(key,nameText.getText(),Integer.parseInt(StypeText.getText()),
						Float.parseFloat(countText.getText()),Integer.parseInt(BtypeText.getText()));
				setVisible(false);			}
			});
			cancelButton = new JButton("Cancel");
		    cancelButton.addActionListener(new ActionListener() {
		      @Override
		      public void actionPerformed(ActionEvent e) {
		        setVisible(false);
		      }
		      });
		    

			buttonPanel.add(OKbutton);
			buttonPanel.add(cancelButton);
			setLayout(new BorderLayout());
		    getContentPane().add(inputPanel, BorderLayout.NORTH);
		    getContentPane().add(buttonPanel, BorderLayout.SOUTH);
		}
		
		else//组合策略
		{
			inputPanel.add(new JLabel("Strategy numbers:"));
			chooseSText=new JTextField();
			chooseSText.setColumns(10);
			inputPanel.add(chooseSText);
			
			OKbutton= new JButton("OK");
			OKbutton.addActionListener(new ActionListener() {
		
			public void actionPerformed(ActionEvent e) {
				controller.updateComStrategy(key,nameText.getText(),
						chooseSText.getText(),Integer.parseInt(BtypeText.getText()));
				setVisible(false);			}
			});
			cancelButton = new JButton("Cancel");
		    cancelButton.addActionListener(new ActionListener() {
		      @Override
		      public void actionPerformed(ActionEvent e) {
		        setVisible(false);
		      }
		      });
		    
		    
		buttonPanel.add(OKbutton);
		buttonPanel.add(cancelButton);
		setLayout(new BorderLayout());
	    getContentPane().add(inputPanel, BorderLayout.NORTH);
	    getContentPane().add(buttonPanel, BorderLayout.SOUTH);
	    
		
		    
		}
	}


	
	
}
