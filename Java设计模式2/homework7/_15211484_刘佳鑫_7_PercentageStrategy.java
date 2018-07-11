package homework7;

public class _15211484_Áõ¼ÑöÎ_7_PercentageStrategy extends _15211484_Áõ¼ÑöÎ_7_Strategies implements _15211484_Áõ¼ÑöÎ_7_IPricingStrategy  {
	private int discountPercentage;
	_15211484_Áõ¼ÑöÎ_7_PercentageStrategy(String number, String name, int type, int bookType,int discountPercentage) {
		super(number,name, type, bookType);
		this.discountPercentage=discountPercentage;
		
	}

	@Override
	public double getSubTotal(_15211484_Áõ¼ÑöÎ_7_SaleLineItem item)
	{
		return item.getCopies()*(item.getProSpec().getPrice()*(1.0-(discountPercentage/100.0)));
	}
	
	public int getdiscountPercentage()
	{
		return discountPercentage;
	}
}
