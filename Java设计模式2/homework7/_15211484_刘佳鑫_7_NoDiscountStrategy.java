package homework7;

public class _15211484_������_7_NoDiscountStrategy  implements _15211484_������_7_IPricingStrategy  {
	
	@Override
	    public double getSubTotal(_15211484_������_7_SaleLineItem item) {
	        return item.getCopies() * item.getProSpec().getPrice();
	    }
}
