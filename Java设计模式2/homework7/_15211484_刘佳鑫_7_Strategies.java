package homework7;

public abstract class _15211484_������_7_Strategies implements  _15211484_������_7_IPricingStrategy{
	private String number;
	private String StrategyName;
	private int type;//��������
	
	private int bookType;//������ͼ������
	
	_15211484_������_7_Strategies(String number,String name,int type,int bookType){
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
			case 1:return "����ֵ����";
			case 2:return "�ٷֱȲ���";
			case 4:return "��ϲ���";
			default:return "���Żݲ���";
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
