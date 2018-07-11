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

public class _15211484_������_7_StrategiesUI extends JDialog{
	
	
	private JTable detailsTable;
	private JButton deletebutton;
	private JButton addSimplebutton;
	private JButton addCombutton;
	private JButton editbutton;
	private JButton renewbutton;
    private static _15211484_������_7_Controller controller;
    
	public  _15211484_������_7_StrategyCatalog strategycatalog=new  _15211484_������_7_StrategyCatalog();
	
	  public _15211484_������_7_StrategiesUI(Frame parent) 
	  {
		  controller=new _15211484_������_7_Controller();
		  setTitle("Strategy");
		
	
		JPanel buttonPanel = new JPanel();
		JPanel tablePanel = new JPanel();
	
		renewbutton=new JButton("ˢ��");
	    renewbutton.addActionListener(new ActionListener() {
		      @Override
		      public void actionPerformed(ActionEvent e) {
		    	  tablePanel.updateUI();
		      }
		      });
		    buttonPanel.add(renewbutton);  
		
	 
		 addSimplebutton=new JButton("�����ͨ����");  
		    addSimplebutton.addActionListener(new ActionListener() {
		      @Override
		      public void actionPerformed(ActionEvent e) {
		    		_15211484_������_7_AddStrategiesUI  addWindow=new _15211484_������_7_AddStrategiesUI(strategycatalog,0);
					addWindow.setVisible(true);
					addWindow.setSize(500,500);
					addWindow.setLocation(100,50);
		      }
		      });
		    buttonPanel.add(addSimplebutton);  
		

			 addCombutton=new JButton("�����ϲ���");  
			    addCombutton.addActionListener(new ActionListener() {
			      @Override
			      public void actionPerformed(ActionEvent e) {
			    		_15211484_������_7_AddStrategiesUI  addWindow=new _15211484_������_7_AddStrategiesUI(strategycatalog,1);
						addWindow.setVisible(true);
						addWindow.setSize(500,500);
						addWindow.setLocation(100,50);
			      }
			      });
			    buttonPanel.add(addCombutton);  
	
		detailsTable = new JTable();
		
		// ����TableModelʹ����ܴ� employees ���������л�ȡ����
		detailsTable.setModel(new AbstractTableModel() {
			// �����Ʒ���
			@Override
			public String getColumnName(int column) {
		        switch(column) {
		        case 0:
		        	return "���Ա��";
				case 1:
		        	return "��������";
				case 2:
		        	return "��������";
				case 3:
					return "����ͼ������";
				case 4:
					return "�ۿ۰ٷֱ�/ÿ���Żݶ��";
				default:
		        	return super.getColumnName(column); // Ĭ�������Ʒ���
		        }
		    }
			// ���ص�Ԫ��ʵ������
			
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
						if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1)) instanceof _15211484_������_7_FlatRateStrategy)
						{
							return ((_15211484_������_7_FlatRateStrategy)strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))).getdiscountPerBook();
						}
						if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1)) instanceof  _15211484_������_7_PercentageStrategy)
						{
							return ((_15211484_������_7_PercentageStrategy)strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))).getdiscountPercentage();
						}
						if(strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1)) instanceof _15211484_������_7_CopositeStrategy )
						{
							return ((_15211484_������_7_CopositeStrategy)strategycatalog.StrategiesHM.get("Discount"+(rowIndex+1))).getstrategiesNum();
						}
					}
				default:
					return null;
		        	}
		        	
			}
			// ��ȡ������������ count ��Ա����
			
			
		
			
			public int getColumnCount() {
				return 5;
			}
			@Override
			public int getRowCount() {
				// TODO Auto-generated method stub
				return strategycatalog.getTotal();
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
		
		  deletebutton=new JButton("ɾ��");
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
			
		 editbutton=new JButton("�޸�");
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
		    	  if(type.equals("��ϲ���"))
		    	  {
		    		  flag=1;
		    	  }
		    	  else
		    	  {
		    		  flag=0;
		    	  }
		    	  _15211484_������_7_EditStrategiesUI editWindow=new _15211484_������_7_EditStrategiesUI(key,strategycatalog,flag);
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
