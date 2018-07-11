package homework7;
import java.util.*;
public class _15211484_������_7_PricingStrategyFactory {

	private static _15211484_������_7_PricingStrategyFactory instance=new _15211484_������_7_PricingStrategyFactory();
	private  _15211484_������_7_StrategyCatalog catalog;
	public static _15211484_������_7_PricingStrategyFactory getInstance()
	{
		return instance;
	}
	public _15211484_������_7_IPricingStrategy getPricingStrategy(int bookType)
	{	_15211484_������_7_IPricingStrategy strategy;
		String key =null;
		for(String getKey:catalog.StrategiesHM.keySet())
		{
			if(catalog.StrategiesHM.get(getKey).getBookTypenum()==bookType)
			{	
				strategy=(_15211484_������_7_IPricingStrategy) catalog.StrategiesHM.get(getKey);
				return strategy;
			}
		}
		return null;
	}

	
	}
	

