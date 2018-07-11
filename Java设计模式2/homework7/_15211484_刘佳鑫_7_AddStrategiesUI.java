package homework7;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class _15211484_������_7_AddStrategiesUI extends JDialog {

	private JTextField numberText;
	private JTextField nameText;
	private JTextField StypeText;
	private JTextField BtypeText;
	private JTextField countText;
	private JTextField chooseSText;//��ϲ�����ѡ���ļ���������ϵ�
	private JButton OKbutton;
	private JButton cancelButton;
	
    private static _15211484_������_7_Controller controller;
    



	
    
	public _15211484_������_7_AddStrategiesUI(_15211484_������_7_StrategyCatalog strategies,int Flag)
	{
		//super(parent,true);
		controller=new _15211484_������_7_Controller();
		setTitle("addStrategy");
		JPanel inputPanel = new JPanel();
		JPanel buttonPanel = new JPanel();
		
		inputPanel.setLayout(new GridLayout(6,2));
		
		inputPanel.add(new JLabel("Number:"));
		numberText = new JTextField();
		numberText.setColumns(10);
		inputPanel.add(numberText);
	
		inputPanel.add(new JLabel("StrategyName:"));
		nameText=new JTextField();
		nameText.setColumns(10);
		inputPanel.add(nameText);

		
		inputPanel.add(new JLabel("BookType:"));
		BtypeText=new JTextField();
		BtypeText.setColumns(10);
		inputPanel.add(BtypeText);
		
		if(Flag==0)//�򵥲���
		{
					
			inputPanel.add(new JLabel("StrategyType:"));
			StypeText=new JTextField();
			StypeText.setColumns(10);
			inputPanel.add(StypeText);
			
			
			inputPanel.add(new JLabel("count:"));
			countText=new JTextField();
			countText.setColumns(10);
			inputPanel.add(countText);
		
			
			OKbutton= new JButton("OK");
			OKbutton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				controller.addSimpleStrategy(numberText.getText(),nameText.getText(),Integer.parseInt(StypeText.getText()),
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
		
		else//��ϲ���
		{
			inputPanel.add(new JLabel("Strategy numbers:"));
			chooseSText=new JTextField();
			chooseSText.setColumns(10);
			inputPanel.add(chooseSText);
			
			OKbutton= new JButton("OK");
			OKbutton.addActionListener(new ActionListener() {
		
			public void actionPerformed(ActionEvent e) {
				controller.addCompositeStrategy(numberText.getText(),nameText.getText(),
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







