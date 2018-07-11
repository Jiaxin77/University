package homework7;

import java.util.ArrayList;



public abstract class _15211484_Áõ¼ÑöÎ_7_CopositeStrategy extends _15211484_Áõ¼ÑöÎ_7_Strategies{
	
	protected ArrayList< _15211484_Áõ¼ÑöÎ_7_Strategies> strategies;
	
	_15211484_Áõ¼ÑöÎ_7_CopositeStrategy(String number,String name, int type,int bookType) {
		super(number,name, type, bookType);
		
		strategies=new ArrayList< _15211484_Áõ¼ÑöÎ_7_Strategies>();
		
	}

	
	
	public void add(_15211484_Áõ¼ÑöÎ_7_Strategies Strategy)
	{	if(Strategy!=null)
		{
			strategies.add(Strategy);
		}
	}
	
	@Override
	public abstract double getSubTotal(_15211484_Áõ¼ÑöÎ_7_SaleLineItem item);
	
		
	
	
	public String getstrategiesNum()
	{	String num = strategies.get(0).getStrategynum();
		
		for(int index=1;index<strategies.size();index++)
		{
			num=num+","+strategies.get(index).getStrategynum();
		}
		return num;
	}

}
