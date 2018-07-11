#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h> 
#include"Define.h"
#include"funtion.h"
#include"input.h"
#include"output.h"
#include"priority.h"
#include"traincontrol.h"
#include"varible.h"
#include"egg.h"
/*控制火车画布移动的函数*/ 
/*A火车*/ 
void TrainAmove()
{	
if(A.Circle==0)//A为顺时针 
	{	if(A.location>=0&&A.location<=50)
		{	SetActiveEgg(aLeft);
		    ShowEgg(0);
			SetActiveEgg(aUp);
			ShowEgg(0);
			SetActiveEgg(aDown);
			ShowEgg(0);
			SetActiveEgg(aRight);
			ShowEgg(1);	
			
			
			
			Adx=A.location*5.6+70;
			Ady=350;
			MoveEgg(Adx,Ady);

		}
		if(A.location>=51&&A.location<=70)
		{	SetActiveEgg(aLeft);
	   		ShowEgg(0);
	    	SetActiveEgg(aRight);
	   		ShowEgg(0);
	    	SetActiveEgg(aUp);
	    	ShowEgg(0);
	    	SetActiveEgg(aDown);
	    	ShowEgg(1);
	    	
	    	Adx=350;
	    	Ady=350-(A.location-50)*5.6;
			MoveEgg(Adx,Ady);

			
		}
		if(A.location>=71&&A.location<=125)
		{
			SetActiveEgg(aDown);
	    	ShowEgg(0);
	    	SetActiveEgg(aRight);
	    	ShowEgg(0);
	    	SetActiveEgg(aUp);
	    	ShowEgg(0);
	    	SetActiveEgg(aLeft);
	    	ShowEgg(1);
	    	
	    	Ady=210;
	    	Adx=350-(A.location-70)*5.6;
	    	MoveEgg(Adx,Ady);

		}
		if(A.location>125&&A.location<150)
		{	SetActiveEgg(aLeft);
	   		ShowEgg(0);
	    	SetActiveEgg(aRight);
	    	ShowEgg(0);
	    	SetActiveEgg(aDown);
	    	ShowEgg(0);
	    	SetActiveEgg(aUp);
	    	ShowEgg(1);
	    	
	  		Adx=70;
	  		Ady=210+5.6*(A.location-125);
	  		MoveEgg(Adx,Ady);
			 

		}
	}
if(A.Circle==1)//A为逆时针 
	{
		if(A.location>=0&&A.location<=50)
		{	SetActiveEgg(aRight);
		    ShowEgg(0);
			SetActiveEgg(aUp);
			ShowEgg(0);
			SetActiveEgg(aDown);
			ShowEgg(0);
			SetActiveEgg(aLeft);
			ShowEgg(1);
				
			Adx=5.6*A.location+70;
			Ady=350;
			MoveEgg(Adx,Ady);
			

	}
		if(A.location>=51&&A.location<=75)
		{	SetActiveEgg(aLeft);
	   	 	ShowEgg(0);
	   	 	SetActiveEgg(aRight);
	    	ShowEgg(0);
	    	SetActiveEgg(aDown);
	    	ShowEgg(0);
	    	SetActiveEgg(aUp);
	    	ShowEgg(1);
	    	
			Adx=350;
	    	Ady=350-(A.location-50)*5.6;
	    	MoveEgg(Adx,Ady);
	

			
	}
		if(A.location>75&&A.location<=125)
		{
			SetActiveEgg(aDown);
	  		ShowEgg(0);
	    	SetActiveEgg(aLeft);
	   	 	ShowEgg(0);
	   		SetActiveEgg(aUp);
	    	ShowEgg(0);
	    	SetActiveEgg(aRight);
	    	ShowEgg(1);
	    	
	    	Ady=210;
	    	Adx=350-(A.location-75)*5.6;
	    	MoveEgg(Adx,Ady);

		}
		if(A.location>125&&A.location<150)
		{	SetActiveEgg(aLeft);
	   		ShowEgg(0);
	    	SetActiveEgg(aRight);
	    	ShowEgg(0);
	    	SetActiveEgg(aUp);
	    	ShowEgg(0);
	    	SetActiveEgg(aDown);
	    	ShowEgg(1);
	    	
	    	Adx=70;
	  		Ady=210+5.6*(A.location-125);
	  		MoveEgg(Adx,Ady);
	  

		}
	}

}


/*B火车*/ 
void TrainBmove()
{	
	if(B.Circle==1)//B为逆时针 
	{
			
		if(B.location<=25&&B.location>=0)
		{	SetActiveEgg(bRight);
	   		ShowEgg(0);
	    	SetActiveEgg(bDown);
	    	ShowEgg(0);
	    	SetActiveEgg(bUp);
	    	ShowEgg(0);
	    	SetActiveEgg(bLeft);
	    	ShowEgg(1);
	    	
	    	Bdy=350;
	    	Bdx=490-5.6*B.location;
	    	MoveEgg(Bdx,Bdy);

		}
		if(B.location>25&&B.location<=75)
		{	SetActiveEgg(bRight);
	   		ShowEgg(0);
	    	SetActiveEgg(bLeft);
	    	ShowEgg(0);
	    	SetActiveEgg(bUp);
	    	ShowEgg(0);
	    	SetActiveEgg(bDown);
	    	ShowEgg(1);
		 
			Bdx=350;
			Bdy=322-5.6*(B.location-30);
			MoveEgg(Bdx,Bdy);
}
		if(B.location>75&&B.location<=100)
		{	SetActiveEgg(bDown);
	   		ShowEgg(0);
	    	SetActiveEgg(bLeft);
	    	ShowEgg(0);
	    	SetActiveEgg(bUp);
	    	ShowEgg(0);
	    	SetActiveEgg(bRight);
	    	ShowEgg(1);
	    	
			Bdy=70;
			Bdx=350+5.6*(B.location-75);
			MoveEgg(Bdx,Bdy);
		
	
		}
		if(B.location>100&&B.location<=149)
		{	SetActiveEgg(bDown);
	   		ShowEgg(0);
	    	SetActiveEgg(bLeft);
	    	ShowEgg(0);
	    	SetActiveEgg(bRight);
	    	ShowEgg(0);
	    	SetActiveEgg(bUp);
	    	ShowEgg(1);
		
		Bdx=490;
		Bdy=70+5.6*(B.location-100);
		MoveEgg(Bdx,Bdy);
		

		}
	}
		
	if(B.Circle==0)//B为顺时针 
	{	
		if(B.location<=25&&B.location>=0)
		{	SetActiveEgg(bLeft);
	   		ShowEgg(0);
	    	SetActiveEgg(bDown);
	    	ShowEgg(0);
	    	SetActiveEgg(bUp);
	    	ShowEgg(0);
	    	SetActiveEgg(bRight);
	    	ShowEgg(1);
	    	
	    	Bdy=350;
	    	Bdx=490-5.6*B.location;
			MoveEgg(Bdx,Bdy);

		}
		if(B.location>25&&B.location<=75)
		{	SetActiveEgg(bRight);
	   		ShowEgg(0);
	    	SetActiveEgg(bLeft);
	    	ShowEgg(0);
	    	SetActiveEgg(bDown);
	    	ShowEgg(0);
	    	SetActiveEgg(bUp);
	    	ShowEgg(1);
		 
		 Bdx=350;
		 Bdy=322-5.6*(B.location-30);
		 MoveEgg(Bdx,Bdy);
		
	
		}
		if(B.location>75&&B.location<=100)
		{	SetActiveEgg(bDown);
	   		ShowEgg(0);
	    	SetActiveEgg(bRight);
	    	ShowEgg(0);
	    	SetActiveEgg(bUp);
	    	ShowEgg(0);
	    	SetActiveEgg(bLeft);
	    	ShowEgg(1);
	    	
	    	Bdy=70;
			Bdx=350+5.6*(B.location-75);
			MoveEgg(Bdx,Bdy);
		
	
		}
		if(B.location>100&&B.location<=149)
		{	SetActiveEgg(bUp);
	   		ShowEgg(0);
	    	SetActiveEgg(bLeft);
	    	ShowEgg(0);
	    	SetActiveEgg(bRight);
	    	ShowEgg(0);
	    	SetActiveEgg(bDown);
	    	ShowEgg(1);
	    	
	    Bdx=490;
		Bdy=70+5.6*(B.location-100);
		MoveEgg(Bdx,Bdy);
		
		

		}
	}
		
		
}



/*C火车*/ 
void TrainCmove()
{	if(C.Circle==1)//C为逆时针 
	{	if(C.location>=0&&C.location<=35)
		{	SetActiveEgg(cUp);
	   		ShowEgg(0);
	    	SetActiveEgg(cLeft);
	    	ShowEgg(0);
	    	SetActiveEgg(cDown);
	    	ShowEgg(0);
	    	SetActiveEgg(cRight);
	    	ShowEgg(1);
	    	
	    	Cdy=70;
	    	Cdx=70+5.6*C.location;
	    	MoveEgg(Cdx,Cdy);
	    	

		}
		if(C.location>35&&C.location<=65)//
		{	SetActiveEgg(cRight);
	   		ShowEgg(0);
	    	SetActiveEgg(cLeft);
	    	ShowEgg(0);
	    	SetActiveEgg(cDown);
	    	ShowEgg(0);
	    	SetActiveEgg(cUp);
	    	ShowEgg(1);
		
			Cdx=266;
			Cdy=70+5.6*(C.location-35);
			MoveEgg(Cdx,Cdy);

	    }
	    if(C.location>65&&C.location<=95)
		{	SetActiveEgg(cRight);
	   		ShowEgg(0);
	    	SetActiveEgg(cUp);
	    	ShowEgg(0);
	    	SetActiveEgg(cDown);
	    	ShowEgg(0);
	    	SetActiveEgg(cLeft);
	    	ShowEgg(1);
	    	
	    	Cdx=266-5.6*(C.location-60);
	    	Cdy=210;
	    	MoveEgg(Cdx,Cdy);

	    }
	    if(C.location>95&&C.location<=119)
		{	SetActiveEgg(cRight);
	   		ShowEgg(0);
	    	SetActiveEgg(cUp);
	    	ShowEgg(0);
	    	SetActiveEgg(cLeft);
	    	ShowEgg(0);
	    	SetActiveEgg(cDown);
	    	ShowEgg(1);
	    	
	    	Cdx=70;
	    	Cdy=210-5.6*(C.location-95);
	    	MoveEgg(Cdx,Cdy);

		}
	}
	if(C.Circle==0)//C为顺时针 
	{	if(C.location>=0&&C.location<=35)
		{	SetActiveEgg(cUp);
	   		ShowEgg(0);
	    	SetActiveEgg(cRight);
	    	ShowEgg(0);
	    	SetActiveEgg(cDown);
	    	ShowEgg(0);
	    	SetActiveEgg(cLeft);
	    	ShowEgg(1);
	    	
			Cdy=70;
	    	Cdx=70+5.6*C.location;
	    	MoveEgg(Cdx,Cdy);
	    	

		}
		if(C.location>35&&C.location<=65)
		{	SetActiveEgg(cRight);
	   		ShowEgg(0);
	    	SetActiveEgg(cLeft);
	    	ShowEgg(0);
	    	SetActiveEgg(cUp);
	    	ShowEgg(0);
	    	SetActiveEgg(cDown);
	    	ShowEgg(1);
		
			Cdx=266;
			Cdy=70+5.6*(C.location-35);
			MoveEgg(Cdx,Cdy);
			
	    		
	    }
	    if(C.location>65&&C.location<=95)
		{	SetActiveEgg(cLeft);
	   		ShowEgg(0);
	    	SetActiveEgg(cUp);
	    	ShowEgg(0);
	    	SetActiveEgg(cDown);
	    	ShowEgg(0);
	    	SetActiveEgg(cRight);
	    	ShowEgg(1);
	    	
	    	Cdx=266-5.6*(C.location-60);
	    	Cdy=210;
	    	MoveEgg(Cdx,Cdy);
	    	

	    }
	    if(C.location>95&&C.location<=119)
		{	SetActiveEgg(cLeft);
	   		ShowEgg(0);
	    	SetActiveEgg(cUp);
	    	ShowEgg(0);
	    	SetActiveEgg(cLeft);
	    	ShowEgg(0);
	    	SetActiveEgg(cUp);
	    	ShowEgg(1);
	    	
	    	Cdx=70;
	    	Cdy=210-5.6*(C.location-95);
	    	MoveEgg(Cdx,Cdy);

		
		}
	}
}
