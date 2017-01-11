int trig = 13;
int echo = 12;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(trig,OUTPUT);
   pinMode(echo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(100);
  digitalWrite(trig,LOW);
  int t = pulseIn(echo,HIGH);
  int dis = t/58; // distance in cm from time duration
  Serial.print(dis);
  Serial.print("cm\n");
  if(dis<40)
      Serial.print("Intruder here!!!\n");
  delay(500);
  
}
