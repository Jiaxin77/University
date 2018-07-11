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
  
    public static final String IP = "10.213.26.230";//服务器地址  
    public static final int PORT = 8800;//服务器端口号    
    public static float clientCurTemp = 30;//房间当前的温度
    public static float clientTargetTemp = -1;//房间目标温度
    public static int clientCurSpeed = 1;//房间当前风速
    public static float clientCurFee = 0;//房间当前费用
    public static float clientMaxRoomTemp = 40;//可回温的最高温度
    public static float clientMinRoomTemp = 10;//可调温的最低温度
    public static float clientMinTargetTemp = 16;//最低目标温度
    public static float clientMaxTargetTemp = 30;//最高目标温度
    public static float clientTempReturn = 0;//回温因子
    public static int clientMode = 0;//空调模式
    public static float clientEnergy = 0;
    public static Socket client = null;
    public static Boolean OffOn = false;//默认是关机状态
    public  PacketBuffer buffer = new PacketBuffer();
    public static Thread tempReturnHandler;
    public static Boolean haltState = true;//开机被服务状态：false；开机暂停状态：true
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
        // 通过输入缓冲流进行读取配置文件
	         InputStream inputStream= TCP_Client.class.getResourceAsStream("config/config.properties");//new BufferedReader(new FileReader());
	        // 加载输入流
	        prop.load(inputStream);
	        // 根据关键字获取value值
	        value = prop.getProperty("tempFactor");
	        TCP_Client.clientTempReturn = Float.parseFloat(value);
	        System.out.println("回温因子："+TCP_Client.clientTempReturn+"\n");
	        TCP_Client.tempReturnHandler = new Thread(new TempReturnHandlerThread());//开启回温线程
	        TCP_Client.tempReturnHandler.start();
        } catch (Exception e) {				
        	e.printStackTrace();
        }
        return value;
     }
    
    private static void handler(TCP_Client tcp){  
        try {  
            //开启两个线程，一个负责读，一个负责写  
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
			System.out.println("1.开机；2.关机；3.调整风速；4.调整目标温度\n");
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
					System.out.println("请重新输入：");
			
			}
			
		}
		
		
	} catch (Exception e) {
		// TODO: handle exception
		e.printStackTrace();
	}
}}
class PacketBuffer{
	private static String packetBuffer = "";//设置一个可以存放三个包的缓冲区，初始化为空
	private PacketHandler handler = new PacketHandler();
	private int lastTargetSpeed = 2;//记录上一次的目标温度和目标风俗
	private float lastTargetTemp = 26;
	public String getBuffer() {
		return packetBuffer;
			//System.out.println(packetBuffer+"\n");
		
	}
	public void setBuffer() {
		packetBuffer = "";
	}
	public Boolean produceOffOnPacket(Boolean OffOn) {//OffOn = true代表开机
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
     *回温处理线程
     */  
    class TempReturnHandlerThread extends Thread{  

        int send = 0;//检测是否为第一次发送会问请求
        
        public void run() {   
            try {  
            	PacketHandler packet = new PacketHandler();
            	System.out.println("回温线程开启\n");
               while(true) {
            	   Thread.currentThread();
            	   Thread.sleep(1000);//等待1秒
            	   if(TCP_Client.clientMode == 0 && TCP_Client.clientCurTemp < TCP_Client.clientMaxRoomTemp && TCP_Client.haltState == true) {//温度要低于最高温度才继续回温
            		   TCP_Client.clientCurTemp = TCP_Client.clientCurTemp + TCP_Client.clientTempReturn;
            		   System.out.println("当前房间的温度："+TCP_Client.clientCurTemp+"\n");
            	   }
            	   if(TCP_Client.clientMode == 1 && TCP_Client.clientCurTemp > TCP_Client.clientMinRoomTemp && TCP_Client.haltState == true) {//温度要低于最高温度才继续回温
            		   TCP_Client.clientCurTemp = TCP_Client.clientCurTemp - TCP_Client.clientTempReturn;
            		   System.out.println("当前房间的温度："+TCP_Client.clientCurTemp+"\n");
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
 *处理读操作的线程   
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
	        	System.out.println("读线程开启\n");
	        	dis = TCP_Client.client.getInputStream();  
		        disReader = new InputStreamReader(dis);
		        br = new BufferedReader(disReader);
	            while(true){  
	                //读取服务器端数据    
	            		if(TCP_Client.client != null) {
	            		
		                System.out.println("马上就要read了\n");
		                br.read(ch);
		                System.out.println("已经读成功了\n");
		                i = 0;
		                while(ch[i] != END) {
		                	receive = receive + ch[i];
		                	ch[i] = END;
		                	i++;
		                }
		                System.out.println("准备decode\n");
		                if(receive != "") {//对空串做处理
			                String[] receiveArray = receive.split("\\*");
			                for(int j = 1;j<receiveArray.length;j++) {
				                System.out.println("receive="+receiveArray[j]+"\n");
								packetHandler.decodePacket(receiveArray[j]);	
			                }	
		                }
		                else {
		                	System.out.println("收到了来自服务器的空串，已忽略\n");
		                }
						receive = "";
						if(TCP_Client.OffOn == false) {
							TCP_Client.client.close();
							TCP_Client.client = null;
							System.out.println("TCP链接关闭\n");
						}
		                	
	            	}
	            	else {
						//System.out.println("TCP链接已关闭（读）\n");
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
 * 处理写操作的线程  
 
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
	        	System.out.println("写线程开启\n");
	        	//TCP_Client.client = new Socket(TCP_Client.IP, TCP_Client.PORT);
	        	
	            while(true){  
	                //取得输出流 
	            	
	            	if(TCP_Client.client != null) {
	            		//if(!TCP_Client.OffOn) {
		            		dos = new DataOutputStream(TCP_Client.client.getOutputStream());  
			            	String send = CmdConstant.bufferRoom;
			            	if(send != "") {
			            		System.out.println("Cmd.buf="+CmdConstant.bufferRoom+"\n");
			            		CmdConstant.bufferRoom = "";
				            	CmdConstant.bufferReady = false;
				            	System.out.println("我要准备发数据了\n");
				                dos.write(send.getBytes());
				                System.out.println("数据发送成功\n");
				                dos.flush();
			            	//}		
	            		}
		            	
	            	}
	            	else {
	            		//System.out.println("TCP链接关闭（写）\n");
	            		if(TCP_Client.client == null && TCP_Client.OffOn) {
	            			TCP_Client.client = new Socket(TCP_Client.IP, TCP_Client.PORT);
	            			System.out.println("创建了一个tcp链接\n");
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
				System.out.println("空调开机成功，回温线程被挂起\n");
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
				System.out.println("空调关机，回温程序被唤醒\n");
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
				return -1;//风速调整失败
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
				return -1;//目标温度调整失败
			}
		}
	
		public void stateFresh(String receive) {
			String[] splitString = receive.split("\\|");
			float Cur_temp = Float.valueOf(splitString[2]);
			float Energy = Float.valueOf(splitString[3]);
			float Cost = Float.valueOf(splitString[4]);
			if(TCP_Client.haltState == false) {//只有房间在被服务时收到状态更新包才有效
				System.out.println("Current temperature:"+Cur_temp+"\n");
				System.out.println("Energy:"+Energy+"\n");
				System.out.println("Cost:"+Cost+"\n");
				TCP_Client.clientCurTemp = Cur_temp;
				TCP_Client.clientCurFee = Cost;	
				TCP_Client.clientEnergy = Energy;
			}
			
		}
		
		public void haltRequest(String receive) {//从控机收到了来自主控机发出的暂停包，调用回温线程
			System.out.println("收到服务器发来的停机请求包，回温线程被唤醒\n");
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
		
		public String encodeRestart(){//向主机请求重新被服务的包
			float tempS = new BigDecimal(TCP_Client.clientCurTemp).setScale(2, BigDecimal.ROUND_HALF_UP).floatValue();
			String restart = "*"+CmdConstant.TEMP_BACK_CODE+"|"+Room_id+"|"+tempS;
			TCP_Client.haltState = false;
			System.out.println("从机发送请求重新被服务的包，回温线程被挂起\n");
			return restart;
		}
		
	}


