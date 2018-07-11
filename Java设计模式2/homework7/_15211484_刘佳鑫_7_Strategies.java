package homework7;

public abstract class _15211484_刘佳鑫_7_Strategies implements  _15211484_刘佳鑫_7_IPricingStrategy{
	private String number;
	private String StrategyName;
	private int type;//策略类型
	
	private int bookType;//适用于图书类型
	
	_15211484_刘佳鑫_7_Strategies(String number,String name,int type,int bookType){
		this.number=number;
		this.StrategyName=name;
		this.type=type;
	
		this.bookType=bookType;
	}

	public String getStrategynum()
	{
		return number;
	}
	public String getStrategyname()
	{
		return StrategyName;
	}
	public String getType()
	{
		switch(type)
		{
			case 1:return "绝对值策略";
			case 2:return "百分比策略";
			case 4:return "组合策略";
			default:return "无优惠策略";
		}
	}
	public int getTypenum()
	{
		return type;
	}
	
	public int getBookTypenum()
	{
		return bookType;
	}

	
}
