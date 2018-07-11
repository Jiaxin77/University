package homework7;

import javax.swing.*;;

public class _15211484_刘佳鑫_7_Controller {
	private static _15211484_刘佳鑫_7_BookCatalog bookcatalog=new _15211484_刘佳鑫_7_BookCatalog();
	private static _15211484_刘佳鑫_7_StrategyCatalog strategycatalog=new _15211484_刘佳鑫_7_StrategyCatalog();
	private static _15211484_刘佳鑫_7_Sale sale=new _15211484_刘佳鑫_7_Sale();
	_15211484_刘佳鑫_7_Controller(){
		
	}
	public void addBook(String isbn,double price,String title,int type)
	{
		if(type<0||type>5)//书的类型错误
		{
			JOptionPane.showMessageDialog(null, "添加图书失败！图书类型错误！", "Failed", JOptionPane.ERROR_MESSAGE); 
		}
		else
		{
			_15211484_刘佳鑫_7_BookSpecification Abook=new _15211484_刘佳鑫_7_BookSpecification(isbn,price,title,type);
			boolean flag=false;
		
			flag=bookcatalog.addBooks(Abook);
			if(flag==true)
			{
				JOptionPane.showMessageDialog(null, "添加图书成功！", "Success", JOptionPane.INFORMATION_MESSAGE); 
			}
			else
			{
				JOptionPane.showMessageDialog(null, "添加图书失败！", "Failed", JOptionPane.ERROR_MESSAGE); 
			}
		}
	}
	
	
	public void addSimpleStrategy(String number,String Sname,int Stype,double count,int Booktype)
	{
		
		switch(Stype) {
			case 1://绝对值优惠策略
				
				_15211484_刘佳鑫_7_FlatRateStrategy s1=new _15211484_刘佳鑫_7_FlatRateStrategy(number,Sname,Stype,Booktype,count);
				strategycatalog.addStrategy(s1);
				JOptionPane.showMessageDialog(null, "添加绝对值优惠策略成功！", "Success", JOptionPane.INFORMATION_MESSAGE); 
				break;
			case 2://百分比优惠策略
			
				int countInt=(int)count;
				_15211484_刘佳鑫_7_PercentageStrategy s2=new _15211484_刘佳鑫_7_PercentageStrategy(number,Sname,Stype,Booktype,countInt);
				strategycatalog.addStrategy(s2);
				JOptionPane.showMessageDialog(null, "添加百分比策略成功！", "Success", JOptionPane.INFORMATION_MESSAGE); 
				break;
			default:
				JOptionPane.showMessageDialog(null, "添加策略失败！策略类型错误！", "Failed", JOptionPane.ERROR_MESSAGE); 
				break;
				
		}

	}
	
	
	public void addCompositeStrategy(String number,String SName, String chooseS, int Btype) {
		
		  String[] strArray = null;   
	      strArray = chooseS.split("\\|"); //拆分字符为"|" ,然后把结果交给数组strArray 
	      //组合类的Type是4
	      _15211484_刘佳鑫_7_CompositeBestForCustomer str4=new _15211484_刘佳鑫_7_CompositeBestForCustomer(number,SName,4,Btype);
	      for(int i=0;i<strArray.length;i++)
	      {		
	    	  _15211484_刘佳鑫_7_Strategies str= strategycatalog.StrategiesHM.get(strArray[i]);
	    	  if(str!=null)
	    	  {
	    		  str4.add(str);
	    	  }
	    	  else
	    	  {
	    		  JOptionPane.showMessageDialog(null, "添加组合策略失败！", "error", JOptionPane.ERROR_MESSAGE); 
	    	  }
	      }
	      strategycatalog.addStrategy(str4);
	      JOptionPane.showMessageDialog(null, "添加组合策略成功！", "Success", JOptionPane.INFORMATION_MESSAGE); 
	}
	
	public void deleteStrategy(String key)
	{
		strategycatalog.StrategiesHM.remove(key);
		 JOptionPane.showMessageDialog(null, "删除成功！", "Success", JOptionPane.INFORMATION_MESSAGE); 
	}
	
	public void updateSimpleStrategy(String key,String Sname,int Stype,double count,int Booktype)
	{
		switch(Stype)
		{
			case 1://绝对值优惠策略
				
				_15211484_刘佳鑫_7_FlatRateStrategy s1=new _15211484_刘佳鑫_7_FlatRateStrategy(key,Sname,Stype,Booktype,count);
				strategycatalog.editStrategy(s1);
				JOptionPane.showMessageDialog(null, "修改绝对值优惠策略成功！", "Success", JOptionPane.INFORMATION_MESSAGE); 
				break;
			case 2://百分比优惠策略
			
				int countInt=(int)count;
				_15211484_刘佳鑫_7_PercentageStrategy s2=new _15211484_刘佳鑫_7_PercentageStrategy(key,Sname,Stype,Booktype,countInt);
				strategycatalog.editStrategy(s2);
				JOptionPane.showMessageDialog(null, "修改百分比策略成功！", "Success", JOptionPane.INFORMATION_MESSAGE); 
				break;
			default:
				JOptionPane.showMessageDialog(null, "修改策略失败！策略类型错误！", "Failed", JOptionPane.ERROR_MESSAGE); 
				break;
			
		}
	}
	
	public void updateComStrategy(String key,String SName, String chooseS, int Btype)
	{
		  String[] strArray = null;   
	      strArray = chooseS.split("\\|"); //拆分字符为"|" ,然后把结果交给数组strArray 
	      
	      _15211484_刘佳鑫_7_CompositeBestForCustomer  str4=new _15211484_刘佳鑫_7_CompositeBestForCustomer (key,SName,4,Btype);
	      for(int i=0;i<strArray.length;i++)
	      {		
	    	  _15211484_刘佳鑫_7_Strategies str= strategycatalog.StrategiesHM.get(strArray[i]);
	    	  if(str!=null)
	    	  {
	    		  str4.add(str);
	    	  }
	    	  else
	    	  {
	    		  JOptionPane.showMessageDialog(null, "修改组合策略失败！", "error", JOptionPane.ERROR_MESSAGE); 
	    	  }
	      }
	      strategycatalog.editStrategy(str4);
	      JOptionPane.showMessageDialog(null, "修改组合策略成功！", "Success", JOptionPane.INFORMATION_MESSAGE); 
	}
	
	
	public void buyBook(String isbn,int copies)
	{
		
		_15211484_刘佳鑫_7_BookSpecification book=bookcatalog.getBookSpecification(isbn);
		if(book==null)
		{
			 JOptionPane.showMessageDialog(null, "购买图书失败！未找到该图书！", "error", JOptionPane.ERROR_MESSAGE); 
		}
		else
		{
			_15211484_刘佳鑫_7_IPricingStrategy str=_15211484_刘佳鑫_7_PricingStrategyFactory.getInstance().getPricingStrategy(book.getType());
			_15211484_刘佳鑫_7_SaleLineItem sli=new _15211484_刘佳鑫_7_SaleLineItem(copies,book,str);
		
			sale.addSaleLineItem(sli);
		}
	}
	
	public _15211484_刘佳鑫_7_Sale getSale()
	{
		return sale;
	}
	

}
