package software;


import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

public class Setting {
	private static int mode;//模式 制冷0还是制热1
	private static int default_speed;//缺省风速
	private static float default_dst_temp;//缺省目标温度
	private static float low_temp_cold;//制冷时的最低温度
	private static float high_temp_cold;//制冷时的最高温度
	private static float low_temp_hot;//制热时的最低温度
	private static float high_temp_hot;//制热时的最高温度
	private static float HPremium_rate;//普通用户三个风速档对应的费率
	private static float MPremium_rate;
	private static float LPremium_rate;
	private static float HVPremium_rate;//VIP用户三个风速档对应的费率
	private static float MVPremium_rate;
	private static float LVPremium_rate;
	private static float VIP_basic;//VIP用户的基准费用
	private static int time;//一秒对应几分钟
	private static float Hspeed_temp;//高中低风速对应的降温
	private static float Mspeed_temp;
	private static float Lspeed_temp;
	private static float Hspeed_energy;//高中低风速对应的耗能
	private static float Mspeed_energy;
	private static float Lspeed_energy;
	private static int port;
	private static String DatabaseIP;
	private static int sev_num ;

	
	public static void init() {
		Properties prop = new Properties();
		try {
			String rootPath = System.getProperty("user.dir").replace("\\", "/");
			FileInputStream input = new FileInputStream(rootPath+"/config.properties");
			System.out.println(rootPath+"/config.properties");
			prop.load(input);
			mode = Integer.parseInt(prop.getProperty("mode"));
			default_speed = Integer.parseInt(prop.getProperty("default_speed"));
			default_dst_temp = Float.parseFloat(prop.getProperty("default_dst_temp"));
			low_temp_cold = Float.parseFloat(prop.getProperty("low_temp_cold"));
			high_temp_cold = Float.parseFloat(prop.getProperty("high_temp_cold"));
			low_temp_hot = Float.parseFloat(prop.getProperty("low_temp_hot"));
			high_temp_hot = Float.parseFloat(prop.getProperty("high_temp_hot"));
			HPremium_rate = Float.parseFloat(prop.getProperty("HPremium_rate"));
			MPremium_rate = Float.parseFloat(prop.getProperty("MPremium_rate"));
			LPremium_rate = Float.parseFloat(prop.getProperty("LPremium_rate"));	
			HVPremium_rate = Float.parseFloat(prop.getProperty("HVPremium_rate"));
			MVPremium_rate = Float.parseFloat(prop.getProperty("MVPremium_rate"));
			LVPremium_rate = Float.parseFloat(prop.getProperty("LVPremium_rate"));
			VIP_basic = Float.parseFloat(prop.getProperty("VIP_basic"));
			time = Integer.parseInt(prop.getProperty("time"));
			Hspeed_temp = Float.parseFloat(prop.getProperty("Hspeed_temp"));
			Mspeed_temp = Float.parseFloat(prop.getProperty("Mspeed_temp"));
			Lspeed_temp = Float.parseFloat(prop.getProperty("Lspeed_temp"));
			Hspeed_energy = Float.parseFloat(prop.getProperty("Hspeed_energy"));
			Mspeed_energy = Float.parseFloat(prop.getProperty("Mspeed_energy"));
			Lspeed_energy = Float.parseFloat(prop.getProperty("Lspeed_energy"));
			port = Integer.parseInt(prop.getProperty("port"));
			DatabaseIP = prop.getProperty("DatabaseIP");
			sev_num = Integer.parseInt(prop.getProperty("sev_num"));
			//System.out.println("sev_num setting:"+sev_num);
		}catch(IOException e) {
			e.printStackTrace();
		}	
	}

	public static int getSevnum() {
		return Setting.sev_num;
	}
	
	public static String getDatabaseIP() {
		return Setting.DatabaseIP;
	}
	
	public static int getPort() {
		return Setting.port;
	}
	
	public static int getMode() {
		return Setting.mode;
	}
	
	public static int getDefault_speed() {
		return Setting.default_speed;
	}
	
	public static float getDefault_dst_temp(){
		return Setting.default_dst_temp;
	}
	
	public static float getLow_temp() {
		if(mode == CmdConstant.HOT) {
			return Setting.low_temp_hot;
		}
		else {
			return Setting.low_temp_cold;	
		}
	}
	
	public static float getHigh_temp() {
		if(mode == CmdConstant.HOT) {
			return Setting.high_temp_hot;
		}
		else {
			return Setting.high_temp_cold;	
		}
	}
	
	public static float getFeeRate(int speed,int identify) {
		float feerate = 0;
		if(identify == CmdConstant.VIP) {
			switch(speed) {
				case Windspeed.L_speed:
					feerate = Setting.LVPremium_rate;
					break;
				case Windspeed.M_speed:
					feerate = Setting.MVPremium_rate;
					break;
				case Windspeed.H_speed:
					feerate = Setting.HVPremium_rate;
					break;
				default:break;
			}
		}
		else if(identify == CmdConstant.COMMON) {
			switch(speed) {
				case Windspeed.L_speed:
					feerate = Setting.LPremium_rate;
					break;
				case Windspeed.M_speed:
					feerate = Setting.MPremium_rate;
					break;
				case Windspeed.H_speed:
					feerate = Setting.HPremium_rate;
					break;
				default:break;
			}
		}
		return feerate;	
	}
	
	
	//get HPremium_rate 的值	
		public static float getHPremium_rate()
		{
			return Setting.HPremium_rate;
		}
		
		//get MPremium_rate 的值	
		public static float getMPremium_rate()
		{
			return Setting.MPremium_rate;
		}
		
		//get LPremium_rate 的值	
		public static float getLPremium_rate()
		{
			return Setting.LPremium_rate;
		}

		//get HVPremium_rate 的值
		public static float getHVPremium_rate()
		{
			return Setting.HVPremium_rate;
		}

		//get MVPremium_rate 的值
		public static float getMVPremium_rate()
		{
			return Setting.MVPremium_rate;
		}

		//get,set LVPremium_rate 的值
		public static float getLVPremium_rate()
		{
			return Setting.LVPremium_rate;
		}

		//get,set VIP_basic 的值
		public static float getVIP_basic()
		{
			return Setting.VIP_basic;
		}

		
		public static void setHPremium_rate(float HPremium_rate)
		{
			Setting.HPremium_rate = HPremium_rate;
		}
		
		
		public static void setMPremium_rate(float MPremium_rate)
		{
			Setting.MPremium_rate = MPremium_rate;
		}
		
		public static void setLPremium_rate(float LPremium_rate)
		{
			Setting.LPremium_rate = LPremium_rate;
		}
		
		public static void setHVPremium_rate(float HVPremium_rate)
		{
			Setting.HVPremium_rate = HVPremium_rate;
		}
		
		public static void setMVPremium_rate(float MVPremium_rate)
		{
			Setting.MVPremium_rate = MVPremium_rate;
		}
		
		public static void setLVPremium_rate(float LVPremium_rate)
		{
			Setting.LVPremium_rate = LVPremium_rate;
		}
		
		public static void setVIP_basic(float VIP_basic)
		{
			Setting.VIP_basic = VIP_basic;
		}

	
		public static int gettime()
		{
			return Setting.time;
		}	
		
		public static float getHspeed_temp()
		{
			return Setting.Hspeed_temp;
		}
	
		public static float getMspeed_temp()
		{
			return Setting.Mspeed_temp;
		}
	
		public static float getLspeed_temp()
		{
			return Setting.Lspeed_temp;
		}
	
		public static float getHspeed_energy()
		{
			return Setting.Hspeed_energy;
		}
	
		public static float getMspeed_energy()
		{
			return Setting.Mspeed_energy;
		}
	
		public static float getLspeed_energy()
		{
			return Setting.Lspeed_energy;
		}
		

}
