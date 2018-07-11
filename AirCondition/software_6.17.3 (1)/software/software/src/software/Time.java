package software;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Time {
	
	public static String timeChange() {
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		String nowtime = df.format(new Date()); 
		return nowtime;
		
	}
	
}
