package homework7;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;
import javax.swing.*;
import javax.swing.JButton;

public  class _15211484_¡ıº—ˆŒ_7_mainUI extends JFrame   {
		private JButton BuyBook;
		private JButton AddBook;
		private _15211484_¡ıº—ˆŒ_7_BookCatalog bookcatalog;
		private JButton Strategy;
		_15211484_¡ıº—ˆŒ_7_mainUI()
		{
			bookcatalog=new _15211484_¡ıº—ˆŒ_7_BookCatalog();
			JFrame frame = new JFrame("BookSale");
			frame.setSize(600, 400);
			frame.setLocation(250, 100);
			
	        JPanel contentPane=new JPanel();
	        frame.setContentPane(contentPane);
	     
		
		frame.setLayout(new FlowLayout(FlowLayout.CENTER));
		
		AddBook= new JButton("ÃÌº”Õº È");
		BuyBook= new JButton("π∫¬ÚÕº È");
		contentPane.add(AddBook);
		contentPane.add(BuyBook);
		
		//ÃÌº”Õº È
		AddBook.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				_15211484_¡ıº—ˆŒ_7_addBookUI  addBookWindow=new _15211484_¡ıº—ˆŒ_7_addBookUI(frame,bookcatalog);
				addBookWindow.setVisible(true);
				addBookWindow.setLocation(100,50);
				addBookWindow.setSize(500,500);
						}
		});
	
		//π∫¬ÚÕº È
		BuyBook.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				_15211484_¡ıº—ˆŒ_7_BuyUI  buyWindow=new _15211484_¡ıº—ˆŒ_7_BuyUI(frame,bookcatalog);
				buyWindow.setVisible(true);
				buyWindow.setSize(500,500);
				buyWindow.setLocation(100,50);
				 _15211484_¡ıº—ˆŒ_7_ShoppingCarUI shoppingcarWindow=new _15211484_¡ıº—ˆŒ_7_ShoppingCarUI ();
			     shoppingcarWindow.setVisible(true);
			      shoppingcarWindow.setLocation(600,50);
			      shoppingcarWindow.setSize(500,500);
				
						}
		});
		
		//≤ﬂ¬‘π‹¿Ì
		Strategy=new JButton("≤ﬂ¬‘π‹¿Ì");
		contentPane.add(Strategy);
		Strategy.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				_15211484_¡ıº—ˆŒ_7_StrategiesUI  strategyWindow=new _15211484_¡ıº—ˆŒ_7_StrategiesUI(frame);
				strategyWindow.setVisible(true);
				strategyWindow.setSize(500,500);
				strategyWindow.setLocation(100,50);
				
						}
		});
		
		
		frame.setVisible(true);
		}
		
		

	
		public static void main(String[] args) {
			_15211484_¡ıº—ˆŒ_7_mainUI firstUI = new _15211484_¡ıº—ˆŒ_7_mainUI();
		}

		
		
		
}
