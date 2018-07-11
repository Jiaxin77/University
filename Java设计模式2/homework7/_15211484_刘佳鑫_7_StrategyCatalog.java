package homework7;

import java.util.HashMap;



public class _15211484_Áõ¼ÑöÎ_7_StrategyCatalog {
	public static HashMap< String,_15211484_Áõ¼ÑöÎ_7_Strategies> StrategiesHM
    = new HashMap<String, _15211484_Áõ¼ÑöÎ_7_Strategies>();
    static int Strategycount=0;
    public void addStrategy(_15211484_Áõ¼ÑöÎ_7_Strategies strategy)
    //Ìí¼Ó²ßÂÔ
    {
    	Strategycount++;
    	StrategiesHM.put(strategy.getStrategynum(), strategy);
    	
    }
    public int getTotal()
    {
    	return Strategycount;
    }
    public void editStrategy(_15211484_Áõ¼ÑöÎ_7_Strategies strategy)
    //±à¼­²ßÂÔ
    {
    
    	StrategiesHM.put(strategy.getStrategynum(), strategy);
    	
    }
    
  
}
