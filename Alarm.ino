#include<SoftwareSerial.h>
SoftwareSerial softSerial(10,11);//用10/11口做软串口，接SIM900
double i0;
bool tp=false;
void sendMsg()
  {
  softSerial.listen();
  softSerial.println("AT+CMGF=1");//短信模式设为1方便发送编码
  delay(1000);
  softSerial.println("AT+CSCS=\"UCS2\"");//设置编码为Unicode(USC2)
  delay(1000);
  softSerial.println("AT+CSMP=17,167,2,25");//发信息设置(忘了这几个数字干啥的了QAQ)
  delay(1000);
  softSerial.println("AT+CMGS=\"*\"");//把*换成电话号码
  delay(1000);
  softSerial.print("#");//把#换成要发送的消息，用USC2编码
  softSerial.write(0x1A);//通信终止(EOF)
  Serial.println("Successful!");
  }
  
void setup() {
 Serial.begin(9600);
 softSerial.begin(9600);
 sendMsg();
 pinMode(8,OUTPUT);//8口接蜂鸣器
 i0=analogRead(A0);//模拟口A0读初始距离，这里接的是红外线测距模块
}

void loop() {
  double i;
  i=analogRead(A0);//读取后来的距离
  Serial.println(i); 
  Serial.println(i0);   
  Serial.println(i/i0);
  digitalWrite(8,LOW);
  if(i>1.5*i0)//后来的距离超过原距离1.5倍可以判定门开了，报警(其实这个看你把报警器装在哪里了，自己调一下也可)
    {
    Serial.println("Alarm!");//这里触发警报，通过距离。
    digitalWrite(8,HIGH);
    if(tp==false)
    {
      sendMsg();//设个tp保证只发一次短信，不然每隔500ms就会发一次(太费钱啦QAQ)
      tp=true;
    }
    }  
  delay(500);
  }
