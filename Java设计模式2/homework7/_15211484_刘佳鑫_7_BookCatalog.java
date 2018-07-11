package homework7;
import java.util.*;


public class _15211484_������_7_BookCatalog {
	private static ArrayList<_15211484_������_7_BookSpecification> books = new ArrayList<_15211484_������_7_BookSpecification>();
	_15211484_������_7_BookCatalog() {
	
	}
	//ͨ��isbnѡ��ͼ��
	public static _15211484_������_7_BookSpecification getBookSpecification(String isbn)
	{	_15211484_������_7_BookSpecification temp;
	
		for(int i=0;i<books.size();i++)
		{
			if(isbn.equals(books.get(i).getISBN()))
			{
				temp=books.get(i);
				return temp ;
			}
		}
		return null;
	}
	public static _15211484_������_7_BookSpecification getBookSpecification(int index)
	{//ͨ��λ��ѡ��ͼ��
		_15211484_������_7_BookSpecification temp;
		if(index<0||index>books.size())
		{
			return null;
		}
		else
		{
			temp=books.get(index);
			return temp;
		}
	}
	public static int getTotalNumber()
	{
		return books.size();
	}
	public boolean addBooks(_15211484_������_7_BookSpecification abook)
	{	if(books.isEmpty())
		{
			books.add(abook);
			return true;
		}
		else
		{
			_15211484_������_7_BookSpecification samebook=getBookSpecification(abook.getISBN());
		
			if(samebook==null)
			{
				books.add(abook);
				return true;
			}
			else
			{
				return false;
			}
		}
		
	}
}
