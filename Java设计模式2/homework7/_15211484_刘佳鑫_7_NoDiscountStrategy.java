package homework7;

public class _15211484_Áõ¼ÑöÎ_7_NoDiscountStrategy  implements _15211484_Áõ¼ÑöÎ_7_IPricingStrategy  {
	
	@Override
	    public double getSubTotal(_15211484_Áõ¼ÑöÎ_7_SaleLineItem item) {
	        return item.getCopies() * item.getProSpec().getPrice();
	    }
}
