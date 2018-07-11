package homework7;

import java.util.*;

public class _15211484_Áõ¼ÑöÎ_7_Sale implements  _15211484_Áõ¼ÑöÎ_7_Subject{
	private ArrayList<_15211484_Áõ¼ÑöÎ_7_SaleLineItem> items;
	private final List<_15211484_Áõ¼ÑöÎ_7_Observer> observers;

	public double getTotal()
	{
		double total=0;
		for(_15211484_Áõ¼ÑöÎ_7_SaleLineItem item:items)
		{
			total+=item.getSubTotal();
		}
		return total;
	}
	 _15211484_Áõ¼ÑöÎ_7_Sale() {
	        items = new ArrayList<_15211484_Áõ¼ÑöÎ_7_SaleLineItem>();
	        observers = new ArrayList<_15211484_Áõ¼ÑöÎ_7_Observer>();
	 }
	 
	 public void addSaleLineItem(_15211484_Áõ¼ÑöÎ_7_SaleLineItem item) {
	         items.add(item);
	         notifyObservers();
	    }
	 
	 public _15211484_Áõ¼ÑöÎ_7_SaleLineItem getSaleLineItem(int index)
	 {
		 return items.get(index);
	 }
	 
	 public int getTotalnum()
	 {
		 return items.size();
	 }
	 
	 @Override
	 public void removeObserver(final _15211484_Áõ¼ÑöÎ_7_Observer ob)
	 {
		 if(observers.indexOf(ob)>=0)
		 {
			observers.remove(ob); 
		 }
	 }
	 
	 
	 @Override
	  public void registerObserver(final _15211484_Áõ¼ÑöÎ_7_Observer o)
	  {
	        observers.add(o);
	  }
	 @Override
	 public void notifyObservers()
	    {
	        for (final _15211484_Áõ¼ÑöÎ_7_Observer ob : observers)
	        {
	        	
	           ob.update();
	        }
	    }
}
