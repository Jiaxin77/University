package software;


public class ComputingStrategy {

	public static void calculate_cost(Room room,int sec)
	{	
		float cost = 0;
		//0是普通用户，1是VIP
		if(room.getIdentify()== CmdConstant.COMMON)
		{
			if(room.getSpeed()==Windspeed.H_speed)
			{
				cost = Setting.getHPremium_rate()*sec* Setting.gettime();
				System.out.println("H_speed compute");
			}
			else if(room.getSpeed()==Windspeed.M_speed)
			{
				cost =  Setting.getMPremium_rate()*sec* Setting.gettime();
				System.out.println("M_speed compute");
			}
			else
			{
				cost =  Setting.getLPremium_rate()*sec* Setting.gettime();
				System.out.println("L_speed compute");
			}	 
		}
		else
		{
			if(room.getSpeed() == Windspeed.H_speed)
			{
				cost =  Setting.getHVPremium_rate()*sec* Setting.gettime();
			}
			else if(room.getSpeed() == Windspeed.M_speed)
			{
				cost =  Setting.getMVPremium_rate()*sec* Setting.gettime();
			}
			else
			{
				cost =  Setting.getLVPremium_rate()*sec* Setting.gettime();
			}
		}
		room.setSubcost(room.getSubcost()+cost);
		room.setCost(room.getCost()+cost);
		room.setOpenCost(room.getOpenCost()+cost);
	}
	
	public static void calculate_temp(Room room,int sec)//温度
	{//0是制冷，1是制热
		float temp = 0;
		if(Setting.getMode()==CmdConstant.COLD)
		{
			if(room.getSpeed() == Windspeed.H_speed)
			{
				temp = room.getCur_temp()-  Setting.getHspeed_temp()*sec;
			}
			else if(room.getSpeed()==Windspeed.M_speed)
			{
				temp = room.getCur_temp()- Setting.getMspeed_temp()*sec;
			}
			else
			{
				temp = room.getCur_temp()- Setting.getLspeed_temp()*sec;
			}
			
		}
		else
		{
			if(room.getSpeed()==Windspeed.H_speed)
			{
				temp = room.getCur_temp() + Setting.getHspeed_temp()*sec;
			}
			else if(room.getSpeed()==Windspeed.M_speed)
			{
				temp = room.getCur_temp() + Setting.getMspeed_temp()*sec;
			}
			else
			{
				temp = room.getCur_temp() + Setting.getLspeed_temp()*sec;
			}
		}
		room.setCur_temp(temp);
	}
	
	public static void calculate_energy(Room room,int sec)//功耗
	{	
		float energy = 0;
		if(room.getSpeed()==Windspeed.H_speed)
		{
			energy = Setting.getHspeed_energy()*sec;
		}
		else if(room.getSpeed()==Windspeed.M_speed)
		{
			energy = Setting.getMspeed_energy()*sec;
		}
		else
		{
			energy = Setting.getLspeed_energy()*sec;
		}
		room.setEnergy(room.getEnergy()+energy);
		
	}

}

