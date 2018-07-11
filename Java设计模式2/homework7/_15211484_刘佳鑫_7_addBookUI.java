package homework7;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;






public class _15211484_Áõ¼ÑöÎ_7_addBookUI  extends JDialog{

	private JTextField isbnText;
	private JTextField nameText;
	private JTextField priceText;
	private JTextField typeText;
	private JButton okButton;
	private JButton cancelButton;
	private int count=0;
    private static _15211484_Áõ¼ÑöÎ_7_Controller controller;
    
	public _15211484_Áõ¼ÑöÎ_7_addBookUI(Frame parent,_15211484_Áõ¼ÑöÎ_7_BookCatalog bookcatalog)
	{
		
		controller=new _15211484_Áõ¼ÑöÎ_7_Controller();
		setTitle("addbook");
		JPanel inputPanel = new JPanel();
		JPanel buttonPanel = new JPanel();
		inputPanel.setLayout(new GridLayout(4,2));
		inputPanel.add(new JLabel("ISBN:"));
		isbnText = new JTextField();
		isbnText.setColumns(5);
		inputPanel.add(isbnText);
		nameText=new JTextField();
		nameText.setColumns(5);
		inputPanel.add(new JLabel("BookName:"));
		inputPanel.add(nameText);
		priceText=new JTextField();
		priceText.setColumns(5);
		inputPanel.add(new JLabel("Price:"));
		inputPanel.add(priceText);
		typeText=new JTextField();
		typeText.setColumns(5);
		inputPanel.add(new JLabel("BookType:"));
		inputPanel.add(typeText);
		
		okButton= new JButton("OK");
		okButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				
				controller.addBook(isbnText.getText(), 
				Float.parseFloat(priceText.getText()),
				nameText.getText(),Integer.parseInt(typeText.getText()));

			
				setVisible(false);			}
		});
		  cancelButton = new JButton("Cancel");
		    cancelButton.addActionListener(new ActionListener() {
		      @Override
		      public void actionPerformed(ActionEvent e) {
		        setVisible(false);
		      }
		      });
		buttonPanel.add(okButton);
		buttonPanel.add(cancelButton);
		setLayout(new BorderLayout());
	    getContentPane().add(inputPanel, BorderLayout.NORTH);
	    getContentPane().add(buttonPanel, BorderLayout.SOUTH);
	    
	}

}














