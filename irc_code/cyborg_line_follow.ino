const int m11 = 22;
const int m12 = 24;
const int m21 = 26;
const int m22 = 28;
const int pwm2 = 9;
const int pwm1 = 8;
const int led = 13;

int s1;
int s2;
int s3;
int s4;
int s5;
int s6;
int s7;

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

void setup(){
  Serial.begin(9600);
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  
}

void loop(){
  digitalWrite(13,HIGH);
  s1= analogRead(A0);
  s2= analogRead(A1);
  s3= analogRead(A2);
  s4= analogRead(A3);
  s5= analogRead(A4);
  s6= analogRead(A5);
  s7= analogRead(A6);
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
  Serial.println(s7);
  
  
   
  
  if(s2>400&&s3>400&&s4>400&&s5>400&&s6>400){
    final =1;
  }
  
  else if (s6<250){
    err = -4;
  }
  else if(s2<250){
    err= 4;
  }
  
  else if(s3<200){
    err = 2;
    
  }
  
  else if(s5<200){
    err = -2;
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
  
  digitalWrite(m11,LOW);
  digitalWrite(m12,HIGH);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);

  analogWrite(pwm1, v1);
  analogWrite(pwm2, v2);
  
  preErr = err;
  
  
  Serial.println(v1);
  Serial.println(v2);
  
  
}
