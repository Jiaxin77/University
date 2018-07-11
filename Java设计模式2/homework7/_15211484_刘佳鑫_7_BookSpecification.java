package homework7;

public class _15211484_Áõ¼ÑöÎ_7_BookSpecification {
	public static final int BOOK_NONTEXTBOOK_CS = 1;
    public static final int BOOK_TEXTBOOK = 2;
    public static final int BOOK_CARTOON = 3;
    public static final int BOOK_HEALTH = 4;
    public static final int OTHERS = 5;
	
	private String isbn;
	private double price;
	private String title;
	private int type;
	
	_15211484_Áõ¼ÑöÎ_7_BookSpecification(String isbn,double price,String title,int type)
	{
		this.isbn=isbn;
		this.price=price;
		this.title=title;
		this.type=type;
	}
	public String getISBN()
	{
		return isbn;
	}
	public String getBookName()
	{
		return title;
	}
	public double getPrice()
	{
		return price;
	}
	
	public int getType()
	{
		return type;
	}
	
}
