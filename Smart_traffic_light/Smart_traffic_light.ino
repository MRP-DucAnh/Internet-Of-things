// C++ code
//
unsigned long t0=0, t;
unsigned long k = 0;
//
const unsigned int TRIG_PIN=3;
const unsigned int ECHO_PIN=2;
const unsigned int BAUD_RATE=9600;

void setup() {
  //Cam Bien
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(BAUD_RATE);
  //Cam Bien
  
  //TrafficLight
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  //TrafficLight
}

void loop() {
 
  //CamBien
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration/29/2;
 if(duration==0){
   Serial.println("Warning: no pulse from sensor");
   } 
  else
{
      Serial.print("distance to nearest object:");
      Serial.print(distance);
      Serial.println(" cm");
  }
 delay(1000);
  //CamBien
 
  t=millis();
  if (t-t0 < 5000 &&1==1 ){
    one();}else if(t-t0 < 6000)
  {two();}else if(t-t0 < 11000 + k)
  {   
    three();
  }else if(distance > 30 )//when no one on the non-highspeed road
    {
    delay(1000);
    k=k+1000;
    Serial.print(k);
    }   
  else 
  {four();delay(3000);t0=t;k=0;}
 }

void one(){
digitalWrite(13, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(12,LOW);
  digitalWrite(7,LOW);
}

void two(){
//digitalWrite(13, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
}

void three(){
  digitalWrite(13, LOW);
  digitalWrite(6, LOW);
  digitalWrite(11,HIGH);
  digitalWrite(7,HIGH);
}
void four(){
  digitalWrite(11,LOW);
 // digitalWrite(7,HIGH);
  digitalWrite(12,HIGH);
}
