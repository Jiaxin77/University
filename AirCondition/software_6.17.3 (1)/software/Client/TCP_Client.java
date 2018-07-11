package Client;
import java.io.BufferedReader; 
import java.io.DataOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Properties;
import java.util.Scanner;

  
//import conditioner_control.CmdConstant;

public class TCP_Client {  
  
    public static final String IP = "10.213.26.230";//��������ַ  
    public static final int PORT = 8800;//�������˿ں�    
    public static float clientCurTemp = 30;//���䵱ǰ���¶�
    public static float clientTargetTemp = -1;//����Ŀ���¶�
    public static int clientCurSpeed = 1;//���䵱ǰ����
    public static float clientCurFee = 0;//���䵱ǰ����
    public static float clientMaxRoomTemp = 40;//�ɻ��µ�����¶�
    public static float clientMinRoomTemp = 10;//�ɵ��µ�����¶�
    public static float clientMinTargetTemp = 16;//���Ŀ���¶�
    public static float clientMaxTargetTemp = 30;//���Ŀ���¶�
    public static float clientTempReturn = 0;//��������
    public static int clientMode = 0;//�յ�ģʽ
    public static float clientEnergy = 0;
    public static Socket client = null;
    public static Boolean OffOn = false;//Ĭ���ǹػ�״̬
    public  PacketBuffer buffer = new PacketBuffer();
    public static Thread tempReturnHandler;
    public static Boolean haltState = true;//����������״̬��false��������ͣ״̬��true
    public static void main(String[] args) throws IOException {  
    	TCP_Client tcp = new TCP_Client();
    	TCP_Client.client = new Socket(IP, PORT);
    	//String bufferRoom = "";
        tempReturn();
        handler(tcp);  
        test t = new test(tcp);
        t.testProducePacket();
       
        
    }
    private static String tempReturn(){
        Properties prop = new Properties();
        String value = null;
        try {
        // ͨ�����뻺�������ж�ȡ�����ļ�
	         InputStream inputStream= TCP_Client.class.getResourceAsStream("config/config.properties");//new BufferedReader(new FileReader());
	        // ����������
	        prop.load(inputStream);
	        // ���ݹؼ��ֻ�ȡvalueֵ
	        value = prop.getProperty("tempFactor");
	        TCP_Client.clientTempReturn = Float.parseFloat(value);
	        System.out.println("�������ӣ�"+TCP_Client.clientTempReturn+"\n");
	        TCP_Client.tempReturnHandler = new Thread(new TempReturnHandlerThread());//���������߳�
	        TCP_Client.tempReturnHandler.start();
        } catch (Exception e) {				
        	e.printStackTrace();
        }
        return value;
     }
    
    private static void handler(TCP_Client tcp){  
        try {  
            //���������̣߳�һ���������һ������д  
            new Thread(new ReadHandlerThread(tcp)).start();  
            new Thread(new WriteHandlerThread(tcp)).start(); 
        } catch (Exception e) {  
            e.printStackTrace();  
        }  
    } 

}
/*
 * test
 */
class test{
	private TCP_Client tcp;
	public test(TCP_Client tcp) {
		this.tcp = tcp;
	}
public void testProducePacket() {
	@SuppressWarnings("resource")
	Scanner sc = new Scanner(System.in);
	float targetTemp = TCP_Client.clientTargetTemp;
	int targetSpeed = TCP_Client.clientCurSpeed;
	String fun = "";
	try {
		while(true) {
			targetTemp = TCP_Client.clientTargetTemp;
			targetSpeed = TCP_Client.clientCurSpeed;
			System.out.println("1.������2.�ػ���3.�������٣�4.����Ŀ���¶�\n");
			fun = sc.nextLine();
			switch(fun) {
				case"1":
					tcp.buffer.produceOffOnPacket(TCP_Client.OffOn);
					break;
				case"2":
					tcp.buffer.produceOffOnPacket(TCP_Client.OffOn);
					break;
				case"3":
					System.out.println("targetSpeed:");
					targetSpeed = sc.nextInt();
					tcp.buffer.produceModifyPacket(targetTemp, targetSpeed);
					break;
				case"4":
					System.out.println("targetTemp:");
					targetTemp = sc.nextInt();
					break;
				default:
					System.out.println("���������룺");
			
			}
			
		}
		
		
	} catch (Exception e) {
		// TODO: handle exception
		e.printStackTrace();
	}
}}
class PacketBuffer{
	private static String packetBuffer = "";//����һ�����Դ���������Ļ���������ʼ��Ϊ��
	private PacketHandler handler = new PacketHandler();
	private int lastTargetSpeed = 2;//��¼��һ�ε�Ŀ���¶Ⱥ�Ŀ�����
	private float lastTargetTemp = 26;
	public String getBuffer() {
		return packetBuffer;
			//System.out.println(packetBuffer+"\n");
		
	}
	public void setBuffer() {
		packetBuffer = "";
	}
	public Boolean produceOffOnPacket(Boolean OffOn) {//OffOn = true������
			packetBuffer = handler.encodeOffOnConditioner(OffOn);
			System.out.println("packetBuffer="+packetBuffer+"\n");
			CmdConstant.bufferRoom = packetBuffer;
			System.out.println("CmdConstant.bufferRoom="+CmdConstant.bufferRoom+"\n");
			CmdConstant.bufferReady = true;
			return CmdConstant.bufferReady;
	}
	public Boolean produceModifyPacket(float targetTemp,int targetSpeed) {
		if(targetSpeed != lastTargetSpeed) {
			packetBuffer = handler.encodeSpeed(targetSpeed);
			lastTargetSpeed = targetSpeed;
		}
		else if(targetTemp != lastTargetTemp){
			packetBuffer = handler.encodeTemp(targetTemp);
			lastTargetTemp = targetTemp;
		}
		else {
			packetBuffer = "";
		}
		if(packetBuffer != "") {
			System.out.println("packetBuffer="+packetBuffer+"\n");
			CmdConstant.bufferRoom = packetBuffer;
			CmdConstant.bufferReady = true;	
		}
		
		return CmdConstant.bufferReady;
	}
	public float getLastTargetTemp() {
		return lastTargetTemp;
	}
	public int getLastTargetSpeed() {
		return lastTargetSpeed;
	}
}
    /*  
     *���´����߳�
     */  
    class TempReturnHandlerThread extends Thread{  

        int send = 0;//����Ƿ�Ϊ��һ�η��ͻ�������
        
        public void run() {   
            try {  
            	PacketHandler packet = new PacketHandler();
            	System.out.println("�����߳̿���\n");
               while(true) {
            	   Thread.currentThread();
            	   Thread.sleep(1000);//�ȴ�1��
            	   if(TCP_Client.clientMode == 0 && TCP_Client.clientCurTemp < TCP_Client.clientMaxRoomTemp && TCP_Client.haltState == true) {//�¶�Ҫ��������¶Ȳż�������
            		   TCP_Client.clientCurTemp = TCP_Client.clientCurTemp + TCP_Client.clientTempReturn;
            		   System.out.println("��ǰ������¶ȣ�"+TCP_Client.clientCurTemp+"\n");
            	   }
            	   if(TCP_Client.clientMode == 1 && TCP_Client.clientCurTemp > TCP_Client.clientMinRoomTemp && TCP_Client.haltState == true) {//�¶�Ҫ��������¶Ȳż�������
            		   TCP_Client.clientCurTemp = TCP_Client.clientCurTemp - TCP_Client.clientTempReturn;
            		   System.out.println("��ǰ������¶ȣ�"+TCP_Client.clientCurTemp+"\n");
            	   }
            	   if (TCP_Client.clientTargetTemp > 0 && Math.abs(TCP_Client.clientCurTemp - TCP_Client.clientTargetTemp ) > 1.0 && TCP_Client.haltState == true ) {
            		   CmdConstant.bufferRoom = packet.encodeRestart();
            		   CmdConstant.bufferReady = true;
            		   TCP_Client.haltState = false;
            	   }
               }
            } catch (Exception e) {  
                e.printStackTrace();  
            } 
        }   
    }    
    
 /*  
 *������������߳�   
 */ 
 
    class ReadHandlerThread implements Runnable{
	    private TCP_Client tcp;
	    private final char END = '!';
	    public PacketHandler packetHandler = new PacketHandler();
	    public ReadHandlerThread(TCP_Client tcp) {  
	        this.tcp = tcp;
	    }  
  
	    @Override  
	    public void run() {   
	        InputStream dis = null;
	        InputStreamReader disReader = null;
	        String receive = "";
	        BufferedReader br = null;
	        int i = 0;
	        char[] ch = new char[100];
	        for(i=0;i<100;i++) {
	        	ch[i] = END;
	        }
	        try {  
	        	System.out.println("���߳̿���\n");
	        	dis = TCP_Client.client.getInputStream();  
		        disReader = new InputStreamReader(dis);
		        br = new BufferedReader(disReader);
	            while(true){  
	                //��ȡ������������    
	            		if(TCP_Client.client != null) {
	            		
		                System.out.println("���Ͼ�Ҫread��\n");
		                br.read(ch);
		                System.out.println("�Ѿ����ɹ���\n");
		                i = 0;
		                while(ch[i] != END) {
		                	receive = receive + ch[i];
		                	ch[i] = END;
		                	i++;
		                }
		                System.out.println("׼��decode\n");
		                if(receive != "") {//�Կմ�������
			                String[] receiveArray = receive.split("\\*");
			                for(int j = 1;j<receiveArray.length;j++) {
				                System.out.println("receive="+receiveArray[j]+"\n");
								packetHandler.decodePacket(receiveArray[j]);	
			                }	
		                }
		                else {
		                	System.out.println("�յ������Է������Ŀմ����Ѻ���\n");
		                }
						receive = "";
						if(TCP_Client.OffOn == false) {
							TCP_Client.client.close();
							TCP_Client.client = null;
							System.out.println("TCP���ӹر�\n");
						}
		                	
	            	}
	            	else {
						//System.out.println("TCP�����ѹرգ�����\n");
					}
	            }  
	        } catch (IOException e) {  
	            e.printStackTrace();  
	        } finally{  
	            try {   
	                if(dis != null){  
	                    dis.close();  
	                }  
	                if(TCP_Client.client != null){  
	                    TCP_Client.client = null;  
	                }  
	            } catch (IOException e) {  
	                e.printStackTrace();  
	            }  
	        }  
	    }  
    } 


  
/*  
 * ����д�������߳�  
 
*/ 
    class WriteHandlerThread implements Runnable{  
	    private TCP_Client tcp;
	    public WriteHandlerThread(TCP_Client tcp) {  
	        this.tcp = tcp;
	    }  
	  
	    @Override  
	    public void run() {	  
	        DataOutputStream dos = null;  
	        BufferedReader br = null; 
	        try {  
	        	System.out.println("д�߳̿���\n");
	        	//TCP_Client.client = new Socket(TCP_Client.IP, TCP_Client.PORT);
	        	
	            while(true){  
	                //ȡ������� 
	            	
	            	if(TCP_Client.client != null) {
	            		//if(!TCP_Client.OffOn) {
		            		dos = new DataOutputStream(TCP_Client.client.getOutputStream());  
			            	String send = CmdConstant.bufferRoom;
			            	if(send != "") {
			            		System.out.println("Cmd.buf="+CmdConstant.bufferRoom+"\n");
			            		CmdConstant.bufferRoom = "";
				            	CmdConstant.bufferReady = false;
				            	System.out.println("��Ҫ׼����������\n");
				                dos.write(send.getBytes());
				                System.out.println("���ݷ��ͳɹ�\n");
				                dos.flush();
			            	//}		
	            		}
		            	
	            	}
	            	else {
	            		//System.out.println("TCP���ӹرգ�д��\n");
	            		if(TCP_Client.client == null && TCP_Client.OffOn) {
	            			TCP_Client.client = new Socket(TCP_Client.IP, TCP_Client.PORT);
	            			System.out.println("������һ��tcp����\n");
	            		}
	            	}
	            	
	            }  
	        } catch (IOException e) {  
	            e.printStackTrace();  
	        } finally{  
	            try{  
	                if(dos != null){  
	                    dos.close();  
	                }  
	                if(br != null){  
	                    br.close();  
	                }  
	                if(TCP_Client.client != null){  
	                    TCP_Client.client = null;  
	                }  
	            }catch(Exception e){  
	                e.printStackTrace();  
	            }  
	        }  
	    }  
    }  
 



   


	class PacketHandler{
		private String Room_id = "312A";
	
		
		public void decodePacket(String receive){
			String[] splitString = receive.split("\\|");
			int type = Integer.parseInt(splitString[0]);
			switch(type) {
			case CmdConstant.OPEN_ACK_CODE:
				openConditioner(receive);
				break;
			case CmdConstant.CLOSE_ACK_CODE:
				closeConditioner(receive);
				break;
			case CmdConstant.SPEED_ACK_CODE:
				modifySpeed(receive);
				break;	
			case CmdConstant.TEMP_ACK_CODE:
				modifyTemp(receive);
				break;
			case CmdConstant.State_Resp_CODE:
				stateFresh(receive);
				break;	
			case CmdConstant.HALT_CODE:
				haltRequest(receive);
				break;
			default:
				System.out.println("Type="+type+";Type decoding is wrong!\n");
			
			}
		}
		
		public Boolean openConditioner(String receive){
			String[] splitString = receive.split("\\|");
			int index = 1;
			int result = Integer.valueOf(splitString[index]);
			if(result == 1) {
				TCP_Client.clientMode = Integer.parseInt(splitString[2]);
				TCP_Client.clientTargetTemp = Float.parseFloat(splitString[3]);
				TCP_Client.clientCurSpeed = Integer.parseInt(splitString[4]);
				TCP_Client.clientMinTargetTemp = Float.parseFloat(splitString[5]);
				TCP_Client.clientMaxTargetTemp = Float.parseFloat(splitString[6]);
				System.out.println("Air conditioner is working!\n");
				System.out.println("�յ������ɹ��������̱߳�����\n");
				return true;
			}
			else {
				System.out.println("Air conditioner can not be started!\n");
				TCP_Client.OffOn = false;
				return false;
			}
		}
		
		public Boolean closeConditioner(String receive) {
			String[] splitString = receive.split("\\|");
			int index = 1;
			int result = Integer.valueOf(splitString[index]);
			if(result == 1) {
				System.out.println("Air conditioner stopped!\n");
				System.out.println("�յ��ػ������³��򱻻���\n");
				return true;
			}
			else {
				System.out.println("Air conditioner can not be stopped!\n");
				TCP_Client.OffOn = true;
				return false;
			}
		}
		
		public int modifySpeed(String receive) {
			String[] splitString = receive.split("\\|");
			int index = 1;
			int result = Integer.valueOf(splitString[index]);
			if(result == 1) {
				System.out.println("Air conditioner's speed is modified\n");
				return TCP_Client.clientCurSpeed;
			}
			else {
				System.out.println("Air conditioner's speed can not be modifed!\n");
				return -1;//���ٵ���ʧ��
			}
		}
		
		public float modifyTemp(String receive) {
			String[] splitString = receive.split("\\|");
			int index = 1;
			int result = Integer.valueOf(splitString[index]);
			if(result == 1) {
				System.out.println("Air conditioner's temperature is modified\n");
				return TCP_Client.clientTargetTemp;
			}
			else {
				System.out.println("Air conditioner's temperature can not be modifed!\n");
				return -1;//Ŀ���¶ȵ���ʧ��
			}
		}
	
		public void stateFresh(String receive) {
			String[] splitString = receive.split("\\|");
			float Cur_temp = Float.valueOf(splitString[2]);
			float Energy = Float.valueOf(splitString[3]);
			float Cost = Float.valueOf(splitString[4]);
			if(TCP_Client.haltState == false) {//ֻ�з����ڱ�����ʱ�յ�״̬���°�����Ч
				System.out.println("Current temperature:"+Cur_temp+"\n");
				System.out.println("Energy:"+Energy+"\n");
				System.out.println("Cost:"+Cost+"\n");
				TCP_Client.clientCurTemp = Cur_temp;
				TCP_Client.clientCurFee = Cost;	
				TCP_Client.clientEnergy = Energy;
			}
			
		}
		
		public void haltRequest(String receive) {//�ӿػ��յ����������ػ���������ͣ�������û����߳�
			System.out.println("�յ�������������ͣ��������������̱߳�����\n");
			TCP_Client.haltState = true;
		}
	
		public String encodeOffOnConditioner(Boolean OffOn) {
			String open;
			if(OffOn == true) {
				open = "*"+CmdConstant.CLOSE_CODE+"|"+Room_id;
				TCP_Client.OffOn = false;
				TCP_Client.haltState = true;
			}
			else {
				float tempS = new BigDecimal(TCP_Client.clientCurTemp).setScale(2, BigDecimal.ROUND_HALF_UP).floatValue();
				open = "*"+CmdConstant.OPEN_CODE+"|"+Room_id+"|"+tempS;
				TCP_Client.OffOn = true;
				TCP_Client.haltState = false;
				/*try {
					TCP_Client.client = new Socket(TCP_Client.IP, TCP_Client.PORT);
				} catch (UnknownHostException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}*/
			}
			
			return open;
		}
		
		public String encodeSpeed(int targetSpeed) {
			String speed ="*"+CmdConstant.SPEED_CODE+"|"+Room_id+"|"+targetSpeed;
			return speed;
		}
		
		public String encodeTemp(Float targetTemp) {
			
			String temp = "*"+CmdConstant.TEMP_CODE+"|"+Room_id+"|"+targetTemp;
			return temp;
		}
		
		public String encodeRestart(){//�������������±�����İ�
			float tempS = new BigDecimal(TCP_Client.clientCurTemp).setScale(2, BigDecimal.ROUND_HALF_UP).floatValue();
			String restart = "*"+CmdConstant.TEMP_BACK_CODE+"|"+Room_id+"|"+tempS;
			TCP_Client.haltState = false;
			System.out.println("�ӻ������������±�����İ��������̱߳�����\n");
			return restart;
		}
		
	}


