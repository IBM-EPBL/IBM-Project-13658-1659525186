void setup()
{
  Serial.begin(9600);
  pinMode(4,INPUT);//Echo 
  pinMode(5,OUTPUT); //Trigger 
  pinMode(6,OUTPUT); //O/P to servo motor
  pinMode(10,OUTPUT);//Brown LED - Indicate decrease in temperature
  pinMode(11,OUTPUT);//Blue LED - Indicate increase in temperature
  pinMode(12,OUTPUT);//Green LED - Light and DC motor - Fan
}

void loop()
{
  // Getting the data from the Temperature sensor
  double a = analogRead(A0); 
  double Conv = (((a/1024)*5)-0.5)*100;
  Serial.println("The Temperature is :");
  Serial.println(Conv);
  Serial.println("----------------------------------");
  delay(1000);
  if(Conv>30)
  {
    	digitalWrite(11,HIGH);
    	digitalWrite(10,LOW);
  }
  else
  {
    	digitalWrite(10,HIGH);
    	digitalWrite(11,LOW);
  }
  
  //PIR Sensor
  int pirsensor=digitalRead(3);
  if(pirsensor==HIGH)
  {
    Serial.println("Motion detected.");
    digitalWrite(12,HIGH);
    delay(10000);
  }
  else
  {
    digitalWrite(12,LOW);
    delay(120);
  }
  //Ultrasonic sensor
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  delayMicroseconds(10);
  digitalWrite(5,LOW);
  int time=pulseIn(4,HIGH);
  int distance=(time*0.034)/2;
  Serial.println("Distance is:");
  Serial.println(distance);
  if(distance<=20)
  {
    Serial.println("Person detected.");
    digitalWrite(6,HIGH);
    delay(500);
  }
  else
  {
    digitalWrite(6,LOW);
    delay(500);
  }
}