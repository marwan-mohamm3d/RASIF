#include <SoftwareSerial.h>
#include <EEPROM.h>
#include<DS1302.h>//for RTC
#include<SD.h>//for sd card
#include<SPI.h>//for sd card
#include<String.h>

//initialising pins for RTC to use
 //      RST,DAT,CLK
DS1302 rtc(6, 5, 4 );

const  int valves = 3;
int CS = 10;// for chip select of sd reader
char fileName[20] = {"table1.dat"};
File file;
int d,h,m;
int lastClose = 0;//to index tha closest time block for now time

struct block
{
  int day,startH,startM,finishH,finishM;
  bool val[valves];
};
block blocks[40];
int countLines()
{
  file = SD.open(fileName);
  int x=0;
  char ch;
  while(file.available())
  {
    ch = file.read()
    Serial.print(ch);
    if(ch == '\n')
    {
      x++;
    }
  }
  return x;
}
void updateClose()
{
    for(int i=countLines()-1;i>0;i--)
    {
      if(d <= blocks[i].day)
        if(h <= blocks[i].startH)
          if(m < blocks[i].startM)
            lastClose = i;
      
    }
}

void loadValve()
{
  for(int i=0;i<valves;i++)
  {
    digitalWrite(14+i,blocks[lastClose].val[i]);
    
  }
  lastClose++;
  lastClose = lastClose % 20;
}
void StrloadVlave(String x)//for SIM messaaegs
{
  for(int i=0;i<x.length()-1;i++)
  {
    digitalWrite(14+i,((int)x[i])-48 );
    Serial.print(14+i);
    Serial.print(':');
    Serial.println(((int)x[i])-48 );
  }
}

String readLine()//error hhere
{
  String received = "12345";
  char ch;
  
  while (file.available())
  {
    ch = file.read();
    if (ch == '\n')
    {
      return String(received);
    }
    else
    {
      received += ch;
    }
  }
  return "";
}

void initializeSD()
{
  Serial.println("initializing sd");
  SD.begin();
  if(SD.begin())//checks if SD is ready
  {
    return NULL;//exit function
  }
  else
  {
    Serial.println("there is a problem in SD card");
  }
}
// added on 29-04-2024
void setBlock(block &b,String data)
{
	// example of data: 2 05 00 05 30 1 0 1 0
	 b.day = int(data[0])-48 ;//convert it to numbre from ascii
	 b.startH =  (int(data[2]) - 48)*10 + int(data[3])-48;
	 b.startM =  (int(data[5]) - 48)*10 + int(data[6])-48;
	 b.finishH =  (int(data[8]) - 48)*10 + int(data[9])-48;
	 b.finishM =  (int(data[11]) - 48)*10 + int(data[12])-48;
	 //starting valves from 14
	 int j = 0;
	 for(int i=14;i<(2*valves)+14;i+=2)//14 is for ofsetting it to start from valves insted of 0
	 {
	 	b.val[j] =data[i] - 48;//-48 for converting asci to int
	 	j++;
	 }
}
int getDay()
{
  if(rtc.getDOWStr() == "Saturday")
    return 0;
  if(rtc.getDOWStr() == "Sunday")
    return 1;
  if(rtc.getDOWStr() == "Monday")
    return 2;
  if(rtc.getDOWStr() == "Tuesday")
    return 3;
  if(rtc.getDOWStr() == "Wednesday")
    return 4;
  if(rtc.getDOWStr() == "Thursday")
    return 5;
  if(rtc.getDOWStr() == "Friday")
    return 6;
  
}
#define rxPin 2
#define txPin 3
#define miso 10;
SoftwareSerial sim800(rxPin, txPin);

void setup() 
{
  lastClose = 0;
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  Serial.begin(9600);
  SD.begin(10);
  initializeSD();
  file = SD.open("table1.dat");
  sim800.begin(9600);
  Serial.println("opened succusuflly");
  
  h = rtc.getTime().hour;
  m = rtc.getTime().min;
  d = getDay();
  int lines = countLines();
  Serial.print(lines);
  for(int i=0;i<lines;i++)//loading all the blocks
  {
    String x = readLine();
    setBlock(blocks[i],x);//proemo hero
  }
  file.seek(0);
  updateClose();
  sim800.println("AT+CMGF=1");
}

void checkMassages()
{
  String x,message;
  while (Serial.available()) 
  {
    sim800.write(Serial.read());
  }
  if(sim800.available())
  {
    String input = sim800.readStringUntil('\n');
    if(input.indexOf("+CMTI") > -1)
    {
      sim800.println("AT+CMGL=\"REC UNREAD\"");
       x = sim800.readString();
       int zer = x.indexOf('\n');
       int first =x.indexOf('\n',zer+1);
       int sec = x.indexOf('\n',first+1);
      message = x.substring(first+1,sec); 
      StrloadVlave(message);
    }
  }
  
}

void loop() {
  Serial.print("d:");
  Serial.print(d);
  Serial.print(" h:");
  Serial.print(h);
  Serial.print(" m:");
  Serial.print(m);
  Serial.print(" s: ");
  Serial.print(rtc.getTime().sec);
  
  Serial.print(" nL:");
  Serial.println(countLines());
  Serial.print(" next teablea D:");

  Serial.print(blocks[lastClose].day);
  Serial.print(" h:");
  Serial.print(blocks[lastClose].startH);
  Serial.print(" m:");
  Serial.println(blocks[lastClose].startM);


  
  //for reciving SMS
  checkMassages();
//for the simcard
  int lines = countLines();
  block b[lines];
  h = rtc.getTime().hour;
  m = rtc.getTime().min;
  d = getDay();
  if(d == blocks[lastClose].day)
    if(h == blocks[lastClose].startH)
      if(m == blocks[lastClose].startM)
        loadValve();//if all conditions met, the valve boolean array will be loaded
  delay(300);
  
  updateClose();

}
