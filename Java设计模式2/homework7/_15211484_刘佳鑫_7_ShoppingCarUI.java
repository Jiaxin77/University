package homework7;
import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.*;
import javax.swing.table.AbstractTableModel;

public class _15211484_������_7_ShoppingCarUI extends JDialog implements _15211484_������_7_Observer{
	
	private JTable detailsTable;
	private JPanel tablePanel;
	private JPanel pricePanel;
	private JTextField totalprice;
	
	private static _15211484_������_7_Controller controller;
	_15211484_������_7_ShoppingCarUI()
	{
		 setTitle("ShoppingCar");
		 controller=new _15211484_������_7_Controller();
		 controller.getSale().registerObserver(this);
		pricePanel = new JPanel();
		pricePanel.setLayout(new GridLayout(1,2));
		pricePanel.add(new JLabel("�ܼ�(Ԫ)��"));
		
		totalprice=new JTextField();
		totalprice.setColumns(10);
		totalprice.setText(Double.toString(controller.getSale().getTotal()));
		
		pricePanel.add(totalprice);
		
		
			detailsTable = new JTable();
			JPanel tablePanel = new JPanel();
	// ����TableModelʹ����ܴ� employees ���������л�ȡ����
	detailsTable.setModel(new AbstractTableModel() {
		// �����Ʒ���
		@Override
		public String getColumnName(int column) {
	        switch(column) {
	        case 0:
	        	return "����";
			case 1:
	        	return "����������";
			default:
	        	return super.getColumnName(column); // Ĭ�������Ʒ���
	        }
	    }
		// ���ص�Ԫ��ʵ������
		
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
		// ��ȡ������������ count ��Ա����
		
		
	
		
		public int getColumnCount() {
			return 2;
		}
		@Override
		public int getRowCount() {
			// TODO Auto-generated method stub
			return controller.getSale().getTotalnum();
		}
	});
	
	// ���������ͼ�߶�

	detailsTable.setFillsViewportHeight(true);
	// ��������һ���ɹ��������
	JScrollPane detailsScrollPane = new JScrollPane(detailsTable);
	// ������Ҫʱ��ʾ������
	detailsScrollPane.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
	// ���ɹ��������ӵ���ϸ��Ϣ�����
	
	
	
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
