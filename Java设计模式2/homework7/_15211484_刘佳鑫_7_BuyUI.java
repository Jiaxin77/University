package homework7;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.table.AbstractTableModel;

import java.awt.*;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class _15211484_刘佳鑫_7_BuyUI extends JDialog{
	private JTextField isbnText;
	private JTextField numberText;
	private JTable detailsTable;
	private JButton buybutton;
	private static _15211484_刘佳鑫_7_Controller controller;
	
	  public _15211484_刘佳鑫_7_BuyUI(Frame parent,_15211484_刘佳鑫_7_BookCatalog bookcatalog) 
	  {
		  _15211484_刘佳鑫_7_Controller controller=new  _15211484_刘佳鑫_7_Controller();
		  setTitle("buybook");
		
		JPanel inputPanel = new JPanel();
		JPanel buttonPanel = new JPanel();
		JPanel tablePanel = new JPanel();
		inputPanel.setLayout(new GridLayout(4,2));

		
		inputPanel.add(new JLabel("ISBN:"));
		isbnText = new JTextField();
		isbnText.setColumns(10);
		inputPanel.add(isbnText);
		numberText=new JTextField();
		numberText.setColumns(10);
		inputPanel.add(new JLabel("number:"));
		inputPanel.add(numberText);
	
		 buybutton=new JButton("购买");  
		    buybutton.addActionListener(new ActionListener() {
		      @Override
		      public void actionPerformed(ActionEvent e) {
		    	  
		        controller.buyBook(isbnText.getText(), Integer.parseInt(numberText.getText()));
		
		      }
		      });
		  buttonPanel.add(buybutton);  
		
		    
		detailsTable = new JTable();
		
		// 设置TableModel使表格能从 employees 对象数组中获取数据
		detailsTable.setModel(new AbstractTableModel() {
			// 列名称方法
			@Override
			public String getColumnName(int column) {
		        switch(column) {
		        case 0:
		        	return "ISBN";
				case 1:
		        	return "BookName";
				case 2:
		        	return "Price";
				default:
		        	return super.getColumnName(column); // 默认列名称方法
		        }
		    }
			// 返回单元格实际内容
			
			public Object getValueAt(int rowIndex, int columnIndex) {
				switch(columnIndex) {
		        case 0:
		        	return bookcatalog.getBookSpecification(rowIndex).getISBN();
				case 1:
		        	return bookcatalog.getBookSpecification(rowIndex).getBookName();
				case 2:
		        	return bookcatalog.getBookSpecification(rowIndex).getPrice();
				default:
					return null;
		        	}
		        	
			}
			// 获取行数方法，即 count 成员变量
			
			
		
			
			public int getColumnCount() {
				return 3;
			}
			@Override
			public int getRowCount() {
				
				return bookcatalog.getTotalNumber();
			}
		});
		
		// 设置填充视图高度
	
		detailsTable.setFillsViewportHeight(true);
		// 将表格放在一个可滚动面板中
		JScrollPane detailsScrollPane = new JScrollPane(detailsTable);
		// 设置需要时显示滚动条
		detailsScrollPane.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		// 将可滚动面板添加到详细信息面板中
		
		tablePanel.add(detailsScrollPane);
	
		
		setLayout(new BorderLayout());
		getContentPane().add(inputPanel,BorderLayout.NORTH);
		getContentPane().add(buttonPanel,BorderLayout.SOUTH);
		
		getContentPane().add(tablePanel,BorderLayout.CENTER);
		
	
	}

}
