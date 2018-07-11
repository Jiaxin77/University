package homework7;

import javax.swing.*;;

public class _15211484_������_7_Controller {
	private static _15211484_������_7_BookCatalog bookcatalog=new _15211484_������_7_BookCatalog();
	private static _15211484_������_7_StrategyCatalog strategycatalog=new _15211484_������_7_StrategyCatalog();
	private static _15211484_������_7_Sale sale=new _15211484_������_7_Sale();
	_15211484_������_7_Controller(){
		
	}
	public void addBook(String isbn,double price,String title,int type)
	{
		if(type<0||type>5)//������ʹ���
		{
			JOptionPane.showMessageDialog(null, "���ͼ��ʧ�ܣ�ͼ�����ʹ���", "Failed", JOptionPane.ERROR_MESSAGE); 
		}
		else
		{
			_15211484_������_7_BookSpecification Abook=new _15211484_������_7_BookSpecification(isbn,price,title,type);
			boolean flag=false;
		
			flag=bookcatalog.addBooks(Abook);
			if(flag==true)
			{
				JOptionPane.showMessageDialog(null, "���ͼ��ɹ���", "Success", JOptionPane.INFORMATION_MESSAGE); 
			}
			else
			{
				JOptionPane.showMessageDialog(null, "���ͼ��ʧ�ܣ�", "Failed", JOptionPane.ERROR_MESSAGE); 
			}
		}
	}
	
	
	public void addSimpleStrategy(String number,String Sname,int Stype,double count,int Booktype)
	{
		
		switch(Stype) {
			case 1://����ֵ�Żݲ���
				
				_15211484_������_7_FlatRateStrategy s1=new _15211484_������_7_FlatRateStrategy(number,Sname,Stype,Booktype,count);
				strategycatalog.addStrategy(s1);
				JOptionPane.showMessageDialog(null, "��Ӿ���ֵ�Żݲ��Գɹ���", "Success", JOptionPane.INFORMATION_MESSAGE); 
				break;
			case 2://�ٷֱ��Żݲ���
			
				int countInt=(int)count;
				_15211484_������_7_PercentageStrategy s2=new _15211484_������_7_PercentageStrategy(number,Sname,Stype,Booktype,countInt);
				strategycatalog.addStrategy(s2);
				JOptionPane.showMessageDialog(null, "��ӰٷֱȲ��Գɹ���", "Success", JOptionPane.INFORMATION_MESSAGE); 
				break;
			default:
				JOptionPane.showMessageDialog(null, "��Ӳ���ʧ�ܣ��������ʹ���", "Failed", JOptionPane.ERROR_MESSAGE); 
				break;
				
		}

	}
	
	
	public void addCompositeStrategy(String number,String SName, String chooseS, int Btype) {
		
		  String[] strArray = null;   
	      strArray = chooseS.split("\\|"); //����ַ�Ϊ"|" ,Ȼ��ѽ����������strArray 
	      //������Type��4
	      _15211484_������_7_CompositeBestForCustomer str4=new _15211484_������_7_CompositeBestForCustomer(number,SName,4,Btype);
	      for(int i=0;i<strArray.length;i++)
	      {		
	    	  _15211484_������_7_Strategies str= strategycatalog.StrategiesHM.get(strArray[i]);
	    	  if(str!=null)
	    	  {
	    		  str4.add(str);
	    	  }
	    	  else
	    	  {
	    		  JOptionPane.showMessageDialog(null, "�����ϲ���ʧ�ܣ�", "error", JOptionPane.ERROR_MESSAGE); 
	    	  }
	      }
	      strategycatalog.addStrategy(str4);
	      JOptionPane.showMessageDialog(null, "�����ϲ��Գɹ���", "Success", JOptionPane.INFORMATION_MESSAGE); 
	}
	
	public void deleteStrategy(String key)
	{
		strategycatalog.StrategiesHM.remove(key);
		 JOptionPane.showMessageDialog(null, "ɾ���ɹ���", "Success", JOptionPane.INFORMATION_MESSAGE); 
	}
	
	public void updateSimpleStrategy(String key,String Sname,int Stype,double count,int Booktype)
	{
		switch(Stype)
		{
			case 1://����ֵ�Żݲ���
				
				_15211484_������_7_FlatRateStrategy s1=new _15211484_������_7_FlatRateStrategy(key,Sname,Stype,Booktype,count);
				strategycatalog.editStrategy(s1);
				JOptionPane.showMessageDialog(null, "�޸ľ���ֵ�Żݲ��Գɹ���", "Success", JOptionPane.INFORMATION_MESSAGE); 
				break;
			case 2://�ٷֱ��Żݲ���
			
				int countInt=(int)count;
				_15211484_������_7_PercentageStrategy s2=new _15211484_������_7_PercentageStrategy(key,Sname,Stype,Booktype,countInt);
				strategycatalog.editStrategy(s2);
				JOptionPane.showMessageDialog(null, "�޸İٷֱȲ��Գɹ���", "Success", JOptionPane.INFORMATION_MESSAGE); 
				break;
			default:
				JOptionPane.showMessageDialog(null, "�޸Ĳ���ʧ�ܣ��������ʹ���", "Failed", JOptionPane.ERROR_MESSAGE); 
				break;
			
		}
	}
	
	public void updateComStrategy(String key,String SName, String chooseS, int Btype)
	{
		  String[] strArray = null;   
	      strArray = chooseS.split("\\|"); //����ַ�Ϊ"|" ,Ȼ��ѽ����������strArray 
	      
	      _15211484_������_7_CompositeBestForCustomer  str4=new _15211484_������_7_CompositeBestForCustomer (key,SName,4,Btype);
	      for(int i=0;i<strArray.length;i++)
	      {		
	    	  _15211484_������_7_Strategies str= strategycatalog.StrategiesHM.get(strArray[i]);
	    	  if(str!=null)
	    	  {
	    		  str4.add(str);
	    	  }
	    	  else
	    	  {
	    		  JOptionPane.showMessageDialog(null, "�޸���ϲ���ʧ�ܣ�", "error", JOptionPane.ERROR_MESSAGE); 
	    	  }
	      }
	      strategycatalog.editStrategy(str4);
	      JOptionPane.showMessageDialog(null, "�޸���ϲ��Գɹ���", "Success", JOptionPane.INFORMATION_MESSAGE); 
	}
	
	
	public void buyBook(String isbn,int copies)
	{
		
		_15211484_������_7_BookSpecification book=bookcatalog.getBookSpecification(isbn);
		if(book==null)
		{
			 JOptionPane.showMessageDialog(null, "����ͼ��ʧ�ܣ�δ�ҵ���ͼ�飡", "error", JOptionPane.ERROR_MESSAGE); 
		}
		else
		{
			_15211484_������_7_IPricingStrategy str=_15211484_������_7_PricingStrategyFactory.getInstance().getPricingStrategy(book.getType());
			_15211484_������_7_SaleLineItem sli=new _15211484_������_7_SaleLineItem(copies,book,str);
		
			sale.addSaleLineItem(sli);
		}
	}
	
	public _15211484_������_7_Sale getSale()
	{
		return sale;
	}
	

}
