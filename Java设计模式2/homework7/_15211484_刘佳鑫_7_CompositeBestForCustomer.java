package homework7;

public class _15211484_Áõ¼ÑöÎ_7_CompositeBestForCustomer  extends _15211484_Áõ¼ÑöÎ_7_CopositeStrategy implements _15211484_Áõ¼ÑöÎ_7_IPricingStrategy{
	_15211484_Áõ¼ÑöÎ_7_CompositeBestForCustomer(String number, String name, int type, int bookType) {
		super(number,name, type,bookType);
		
	}

	@Override
	public double getSubTotal(_15211484_Áõ¼ÑöÎ_7_SaleLineItem item)
	{
	
	double price=strategies.get(0).getSubTotal(item);
		
		for(int i=1;i<strategies.size();i++)
		{
			if(price>strategies.get(i).getSubTotal(item))
			{
				price=strategies.get(i).getSubTotal(item);
			}
		}
		return price;
	}
}
