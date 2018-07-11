package homework7;

public class _15211484_Áõ¼ÑöÎ_7_FlatRateStrategy extends _15211484_Áõ¼ÑöÎ_7_Strategies implements _15211484_Áõ¼ÑöÎ_7_IPricingStrategy {
//°´Ã¿±¾ÓÅ»İxÔªµÄ²ßÂÔ
	private double discountPerBook;
	
	_15211484_Áõ¼ÑöÎ_7_FlatRateStrategy(String number,String name, int type, int bookType,double discountPerBook) {
		super(number,name, type, bookType);
		this.discountPerBook=discountPerBook;
	
	}
	@Override
	public double getSubTotal(_15211484_Áõ¼ÑöÎ_7_SaleLineItem item)
	{
		return item.getCopies()*(item.getProSpec().getPrice()-discountPerBook);
	}
	
	public double getdiscountPerBook()
	{
		return discountPerBook;
	}
}
