package software;

public class CmdConstant {
	//�����
	public static final int OPEN_CODE = 1;
	public static final int OPEN_ACK_CODE = 2;
	public static final int CLOSE_CODE = 3;
	public static final int CLOSE_ACK_CODE = 4;
	public static final int SPEED_CODE = 5;
	public static final int SPEED_ACK_CODE = 6;
	public static final int TEMP_CODE = 7;
	public static final int TEMP_ACK_CODE = 8;
	public static final int State_Resp_CODE = 9;
	public static final int HALT_CODE = 10;
	public static final int TEMP_BACK_CODE = 11;
	/*
	public static final int SWAP_OUT_CODE = 12;
	public static final int ASKFOR_TEMP_CODE = 13;
	public static final int ASK_ACK_CODE = 14;
	*/
	public static final char DELIMITER = '|' ;
	
	//�յ�ģʽ
	public static final int COLD = 0;
	public static final int HOT = 1;
	
	//��������״̬
	public static final int FAIL = 0;
	public static final int SUCCESS = 1;
	
	//����״̬
	public static final int SLEEP = 0; 
	public static final int COMPUTE = 1;
	public static final int WAIT = 2;
	public static final int CLOSE = 3;
	public static final int OPEN = 4;	
	
	//�û�״̬
	public static final int COMMON = 0;
	public static final int VIP = 1;
	
	//���ݿ�״̬
	public static final int stop=0;  //stop
	public static final int run=1;   //on
	public static final int halt=2;  //halt
}

class Windspeed
{		//�����
		public static final int H_speed = 3;
		public static final int M_speed = 2;
		public static final int L_speed = 1;				
} 

