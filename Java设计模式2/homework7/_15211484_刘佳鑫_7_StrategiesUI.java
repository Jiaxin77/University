package homework7;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.ScrollPaneConstants;
import javax.swing.table.AbstractTableModel;

public class _15211484_刘佳鑫_7_StrategiesUI extends JDialog{
	
	
	private JTable detailsTable;
	private JButton deletebutton;
	private JButton addSimplebutton;
	private JButton addCombutton;
	private JButton editbutton;
	private JButton renewbutton;
    private static _15211484_刘佳鑫_7_Controller controller;
    
	public  _15211484_刘佳鑫_7_StrategyCatalog strategycatalog=new  _15211484_刘佳鑫_7_StrategyCatalog();
	
	  public _15211484_刘佳鑫_7_StrategiesUI(Frame parent) 
	  {
		  controller=new _15211484_刘佳鑫_7_Controller();
		  setTitle("Strategy");
		
	
		JPanel buttonPanel = new JPanel();
		JPanel tablePanel = new JPanel();
	
		renewbutton=new JButton("刷新");
	    renewbutton.addActionListener(new ActionListener() {
		      @Override
		      public void actionPerformed(ActionEvent e) {
		    	  tablePanel.updateUI();
		      }
		      });
		    buttonPanel.add(renewbutton);  
		
	 
		 addSimplebutton=new JButton("添加普通策略");  
		    addSimplebutton.addActionListener(new ActionListener() {
		      @Override
		      public void actionPerformed(ActionEvent e) {
		    		_15211484_刘佳鑫_7_AddStrategiesUI  addWindow=new _15211484_刘佳鑫_7_AddStrategiesUI(strategycatalog,0);
					addWindow.setVisible(true);
					addWindow.setSize(500,500);
					addWindow.setLocation(100,50);
		      }
		      });
		    buttonPanel.add(addSimplebutton);  
		

			 addCombutton=new JButton("添加组合策略");  
			    addCombutton.addActionListener(new ActionListener() {
			      @Override
			      public void actionPerformed(ActionEvent e) {
			    		_15211484_刘佳鑫_7_AddStrategiesUI  addWindow=new _15211484_刘佳鑫_7_AddStrategiesUI(strategycatalog,1);
						addWindow.setVisible(true);
						addWindow.setSize(500,500);
						addWindow.setLocation(100,50);
			      }
			      });
			    buttonPanel.add(addCombutton);  
	
		detailsTable = new JTable();
		
		// 设置TableModel使表格能从 employees 对象数组中获取数据
		detailsTable.setModel(new AbstractTableModel() {
			// 列名称方法
			@Override
			public String getColumnName(int column) {
		        switch(column) {
		        case 0:
		        	return "策略编号";
				case 1:
		        	return "策略名称";
				case 2:
		        	return "策略类型";
				case 3:
					return "适用图书类型";
				case 4:
					return "折扣百分比/每本优惠额度";
				default:
		        	return super.getColumnName(column); // 默认列名称方法
		        }
		    }
			// 返回单元格实际内容
			
			public Object getValueAt(int rowIndex, int columnIndex) {
				switch(columnIndex) {
		        case 0:
		        	if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))==null)
					{
						return null;
					}
					else
					{
						return "Discount"+(rowIndex+1);
					}
				case 1:
					if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))==null)
					{
						return null;
					}
					else
					{
						return strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1)).getStrategyname();
					}
		        	
				case 2:
					if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))==null)
					{
						return null;
					}
					else
					{
						return strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1)).getType();
					}
				case 3:
					if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))==null)
					{
						return null;
					}
					else
					{
						return strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1)).getBookTypenum();
					}
				case 4:
					if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))==null)
					{
						return null;
					}
					else
					{
						if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1)) instanceof _15211484_刘佳鑫_7_FlatRateStrategy)
						{
							return ((_15211484_刘佳鑫_7_FlatRateStrategy)strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))).getdiscountPerBook();
						}
						if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1)) instanceof  _15211484_刘佳鑫_7_PercentageStrategy)
						{
							return ((_15211484_刘佳鑫_7_PercentageStrategy)strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))).getdiscountPercentage();
						}
						if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1)) instanceof _15211484_刘佳鑫_7_CopositeStrategy )
						{
							return ((_15211484_刘佳鑫_7_CopositeStrategy)strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))).getstrategiesNum();
						}
					}
				default:
					return null;
		        	}
		        	
			}
			// 获取行数方法，即 count 成员变量
			
			
		
			
			public int getColumnCount() {
				return 5;
			}
			@Override
			public int getRowCount() {
				// TODO Auto-generated method stub
				return strategycatalog.getTotal();
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
		
		  deletebutton=new JButton("删除");
		   deletebutton.addActionListener(new ActionListener() {
			      @Override
			      public void actionPerformed(ActionEvent e) {
			    	  int row=detailsTable.getSelectedRow();
			    	  int col=0;
			    	  String key=(String)detailsTable.getValueAt(row, col);
			    	  controller.deleteStrategy(key);
			    	  tablePanel.updateUI();
			      }
			      });
			    buttonPanel.add(deletebutton);  
			
		 editbutton=new JButton("修改");
		 editbutton.addActionListener(new ActionListener() {
		      @Override
		      public void actionPerformed(ActionEvent e) {
		    	  int row=detailsTable.getSelectedRow();
		    	  int col=0;
		    	  String key=(String)detailsTable.getValueAt(row, col);
		    	   row=detailsTable.getSelectedRow();
		    	  col=2;
		    	  String type=(String)detailsTable.getValueAt(row, col);
		    	  int flag;
		    	  if(type.equals("组合策略"))
		    	  {
		    		  flag=1;
		    	  }
		    	  else
		    	  {
		    		  flag=0;
		    	  }
		    	  _15211484_刘佳鑫_7_EditStrategiesUI editWindow=new _15211484_刘佳鑫_7_EditStrategiesUI(key,strategycatalog,flag);
		    	  editWindow.setVisible(true);
		    	  editWindow.setSize(500,500);
		    	  editWindow.setLocation(100,50);
		    	  tablePanel.updateUI();
		      }
		      });
		    buttonPanel.add(editbutton);  	
		
		setLayout(new BorderLayout());
		
		
		getContentPane().add(buttonPanel,BorderLayout.SOUTH);
		
		getContentPane().add(tablePanel,BorderLayout.CENTER);
	
	}

}
