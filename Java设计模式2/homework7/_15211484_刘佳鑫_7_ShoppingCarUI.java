package homework7;
import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.*;
import javax.swing.table.AbstractTableModel;

public class _15211484_刘佳鑫_7_ShoppingCarUI extends JDialog implements _15211484_刘佳鑫_7_Observer{
	
	private JTable detailsTable;
	private JPanel tablePanel;
	private JPanel pricePanel;
	private JTextField totalprice;
	
	private static _15211484_刘佳鑫_7_Controller controller;
	_15211484_刘佳鑫_7_ShoppingCarUI()
	{
		 setTitle("ShoppingCar");
		 controller=new _15211484_刘佳鑫_7_Controller();
		 controller.getSale().registerObserver(this);
		pricePanel = new JPanel();
		pricePanel.setLayout(new GridLayout(1,2));
		pricePanel.add(new JLabel("总价(元)："));
		
		totalprice=new JTextField();
		totalprice.setColumns(10);
		totalprice.setText(Double.toString(controller.getSale().getTotal()));
		
		pricePanel.add(totalprice);
		
		
			detailsTable = new JTable();
			JPanel tablePanel = new JPanel();
	// 设置TableModel使表格能从 employees 对象数组中获取数据
	detailsTable.setModel(new AbstractTableModel() {
		// 列名称方法
		@Override
		public String getColumnName(int column) {
	        switch(column) {
	        case 0:
	        	return "书名";
			case 1:
	        	return "数量（本）";
			default:
	        	return super.getColumnName(column); // 默认列名称方法
	        }
	    }
		// 返回单元格实际内容
		
		public Object getValueAt(int rowIndex, int columnIndex) {
			switch(columnIndex) {
	        case 0:
	        	return controller.getSale().getSaleLineItem(rowIndex).getProSpec().getBookName();
			case 1:
	        	return controller.getSale().getSaleLineItem(rowIndex).getCopies();

			default:
				return null;
	        	}
	        	
		}
		// 获取行数方法，即 count 成员变量
		
		
	
		
		public int getColumnCount() {
			return 2;
		}
		@Override
		public int getRowCount() {
			// TODO Auto-generated method stub
			return controller.getSale().getTotalnum();
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
	
	getContentPane().add(tablePanel,BorderLayout.CENTER);
	getContentPane().add(pricePanel,BorderLayout.SOUTH);
	}
	
	@Override
	public void update()
	{
		////
		
		detailsTable.updateUI();
		
		pricePanel.updateUI();
		
		totalprice.setText(String.format("%.2f", controller.getSale().getTotal()));
		
	}
}
