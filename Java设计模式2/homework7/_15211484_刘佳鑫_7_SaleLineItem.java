package homework7;

public class _15211484_Áõ¼ÑöÎ_7_SaleLineItem {

	private int copies;
	private _15211484_Áõ¼ÑöÎ_7_BookSpecification bookSpec;
	private _15211484_Áõ¼ÑöÎ_7_IPricingStrategy strategy;
	
	_15211484_Áõ¼ÑöÎ_7_SaleLineItem(int copies,_15211484_Áõ¼ÑöÎ_7_BookSpecification bookSpec,_15211484_Áõ¼ÑöÎ_7_IPricingStrategy strategy)
	{
		this.copies=copies;
		this.bookSpec=bookSpec;
		if(strategy!=null)
		{
			this.strategy=strategy;
		}
		else
		{
			_15211484_Áõ¼ÑöÎ_7_NoDiscountStrategy strategy1=new _15211484_Áõ¼ÑöÎ_7_NoDiscountStrategy();
			this.strategy=strategy1;
		}
		
	}
	
	
	public double getSubTotal()
	{
		return strategy.getSubTotal(this);
	}
	
	public int getCopies()
	{
		return copies;
	}
	
	public  _15211484_Áõ¼ÑöÎ_7_BookSpecification getProSpec()
	{
		return bookSpec;
	}
}
