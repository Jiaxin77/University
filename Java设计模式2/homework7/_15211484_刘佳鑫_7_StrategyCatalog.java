package homework7;

import java.util.HashMap;



public class _15211484_������_7_StrategyCatalog {
	public static HashMap< String,_15211484_������_7_Strategies> StrategiesHM
    = new HashMap<String, _15211484_������_7_Strategies>();
    static int Strategycount=0;
    public void addStrategy(_15211484_������_7_Strategies strategy)
    //��Ӳ���
    {
    	Strategycount++;
    	StrategiesHM.put(strategy.getStrategynum(), strategy);
    	
    }
    public int getTotal()
    {
    	return Strategycount;
    }
    public void editStrategy(_15211484_������_7_Strategies strategy)
    //�༭����
    {
    
    	StrategiesHM.put(strategy.getStrategynum(), strategy);
    	
    }
    
  
}
