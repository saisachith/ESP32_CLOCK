#include<WiFi.h>
#include<NTPClient.h>
#include<WiFiUdp.h>
#include<string.h>

const char* ssid = "JB REDDY";
const char* password = "jannepally7889";

// defining ntp client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

String Time;
String Hours;
String Mins;
String Secs;
char*h;

void setup(){
  Serial.begin(115200);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(21,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(27,OUTPUT);
  
  Serial.println("Commnecing wifi action");
  Serial.println("System command connect to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(". ");
    }
  Serial.println();
  Serial.println("Operation success, Connected to ");
  Serial.println(ssid);
  Serial.println("IP address of the connection: ");
  Serial.println(WiFi.localIP());
  /*
    Wifi connection code is done.
  */
  // Initialize a NTPclient to get time
  timeClient.begin();
  /*
    for 1 hour we add to GMT there will be 3600 seconds 
    so in India GMT+5:30 = 5*3600 + 0.5*3600 = 19800 seconds
  */
  timeClient.setTimeOffset(19800);
  }
// Setup done
void loop(){
//  Serial.println("Debug1");
  while(!timeClient.update()){
    timeClient.forceUpdate();
    }
//    Serial.println("Debug2");
    // problem: time client is not updating
    
    /*  
      the date format is like this: 
      year-month-date[+]T[+]hours:min:seconds
    */
    Time = timeClient.getFormattedTime();
    Time = Time.c_str();
    Serial.println(Time);
    int split = Time.indexOf(":");
    Serial.print("Hours: ");
    Hours = (Time.substring(0,split));
//    h = Hours;
    Serial.println(Hours);
    split = Time.indexOf(":");
    Mins = Time.substring(split+1,split+3);
    Serial.print("Mins : ");
    Serial.println(Mins);
    Secs = Time.substring(split+4,split+6);
    Serial.print("Secs: ");
    Serial.println(Secs);
//    Serial.println(split);
    delay(1000);
   int n;
/*
  pins allocation
*/
    char* Hours_a;
    strcpy(Hours_a, Hours.c_str());
    if(strcmp(Hours_a, ("12")) == 0){
      n = 12;
      }
    else if(strcmp(Hours_a, "1") == 0 || strcmp(Hours_a, "13") == 0){
      n = 2;
      }
    else if(strcmp(Hours_a, "2") == 0 || strcmp(Hours_a,"14") == 0){
      n = 14;
      }
    else if(strcmp(Hours_a,"3")== 0 || strcmp(Hours_a, "15") == 0){
      n = 2;
      }
    else if(strcmp(Hours_a,"4") == 0 || strcmp(Hours_a, "16") == 0){
      n = 4;
      }
    else if(strcmp(Hours_a,"5") == 0||strcmp(Hours_a,"17") == 0){
      n = 5;
      }
    else if(strcmp(Hours_a,"6") == 0||strcmp(Hours_a,"18") == 0){
      n = 18;
      }
    else if(strcmp(Hours_a,"7") == 0||strcmp(Hours_a,"19") == 0){
      n = 19;
      }
    else if(strcmp(Hours_a,"8") == 0||strcmp(Hours_a,"20") == 0){
      n = 21;
      }
    else if(strcmp(Hours_a,"9") == 0||strcmp(Hours_a,"21") == 0){
      n = 22;
      }
    else if(strcmp(Hours_a,"10") == 0||strcmp(Hours_a,"22") == 0){
      n = 23;
      }
    else if(strcmp(Hours_a,"11") == 0||strcmp(Hours_a,"23") == 0){
      n = 27;
      }
    digitalWrite(n,HIGH);
    delay(2000);
    digitalWrite(n,LOW);
    delay(1000);
    
  }
