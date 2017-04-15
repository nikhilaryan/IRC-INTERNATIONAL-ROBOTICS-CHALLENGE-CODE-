// motor correction;
const int m11 = 8;
const int m12 = 7;
const int m21 = 6;
const int m22 = 5;
const int pwm2 = 9;
const int pwm1 = 10;
const int led = 13;
int s1;
int s2;
int s3;
int s4;
int s5;
int s6;
int kp=50;
int kd=0;
int final=0;
int p1 = 0;
int p2 = 0;
int err= 0;
int preErr=0;
double corr;
int v1;
int v2;
int ctx=0;
int x;
int y;
void forward();
void Leftturn()



void setup(){
  Serial.begin(9600);
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  tone(4, 3000, 1000);                       // Play tone for 1 second
  delay(1000);                               // Delay to finish tone
  pinMode(1, INPUT); 
  pinMode(2, OUTPUT);   // Left IR LED & Receiver
  Serial.begin(9600);                        // Set data rate to 9600 bps
  
}

void loop(){
  digitalWrite(13,HIGH);
  s1= analogRead(A0);
  s2= analogRead(A1);
  s3= analogRead(A2);
  s4= analogRead(A3);
  s5= analogRead(A4);
  s6= analogRead(A5);
  delay(500);
  digitalWrite(13,LOW);
  delay(500);
  
  Serial.println("Start");
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);
  Serial.println(s6);
  
  
  
  
  
  
  if(s2<400&&s3<400&&s4<400&&s5<400&&s6<400){
    final =1;
  }
  
  else if (s6<450){
    err = -2;
  }
  else if(s2<200){
    err= 2;
  }
  
  else if(s3<200){
    err = 1;
    
  }
  
  else if(s5<200){
    err = -1;
  } 
  else if(s4<200){
    err= 0;
  }  
  
  else{
  err  = preErr;
  }
  
  
  corr = (kp *err)+(kd*(err-preErr));
  /*
  if(preErr != err){
  v1 = 150 + corr;
  v2 = 150 -corr;
  
  }
  
  */
  if(final == 0){
  v1 = 150 -kp*err;
  v2 = 150 +kp*err;}
  else{
  v1= 0;
  v2 =0;
  }
  
  if(v1>255){
    v1 = 255;
    
  }
  if(v2 >255){
    v2 = 255;
  }
  if(v1<=0){
    v1 = 0;
  }
   if(v2<=0){
    v2 = 0;
  }
  // needs correction;
 
  digitalWrite(m11,HIGH);
  digitalWrite(m12,HIGH);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,HIGH);
  
  analogWrite(pwm1, v1);
  analogWrite(pwm2, v2);
  
  preErr = err;
  
  
  Serial.println(v1);
  Serial.println(v2);
  

 if (s1==HIGH&&s2==HIGH&&s3==HIGH&&s4==HIGH&&s5==HIGH){
  ctr=ctr+1};
  //store value x,y ;
  // priority;
  20 Traverse stack(int x,int y)
21 /*Stores the value of traversed coordinate*/
22 Set priority(int x,int y)
23 /* Stores the values of connected nodes and its priority*/
24 Write stack(int x ,int y)
  int irLeft = irDetect(1, 10, 38000);       // Check for object
  Serial.println(irLeft);                    // Display 1/0 no detect/detect

  delay(100);
  //Direction();
  if(ir==0)
   {Forward()}
   /*condition for forward */
  else
  Left turn();
  
 /*condition for Left turn */
   Right turn()
 /*condition for Right turn */


19 /* it is implemented as table 1*/
20 detect junction
21 Set x:=0 ,y:=0
22 While(irc!=0)
23 {Traverse stack(x,y)
24 Set priority(x,y, value)
25 Detect next node
26 Check max priority in priority stack
27 If priority is max
28 Take turn
29 Change direction
30 Else
31 Check in Direction turn.
32 End if
33 End while
  
  
};
int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);              // IRLED 38 kHz for at least 1 ms
  delay(1);                                  // Wait 1 ms
  int ir = digitalRead(irReceiverPin);       // IR receiver -> ir variable
  delay(1);                                  // Down time before recheck
  return ir;                                 // Return 1 no detect, 0 detect
}  

   forward(){
   digitalWrite(m11,HIGH);
   digitalWrite(m12,HIGH);
   digitalWrite(m21,HIGH);
   digitalWrite(m22,HIGH); 
    
   };
   Leftturn()
{
 motor[m11] = +15;
 motor[m12] = -15;
 motor[m21] = +15;
 motor[m22] = -15;
  wait1Msec(470);  
};
Rightturn()
{
 motor[m11] = -15;
 motor[m12] = +15;
 motor[m21] = -15;
 motor[m22] = +15;
  wait1Msec(470);  
}
    
   
   
  
   
  }
