// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(3,INPUT);//Echo from ultrasonic sensor
  pinMode(4,OUTPUT); //Trigger for ultrasonic sensor
  pinMode(5,OUTPUT); //Output to servo motor
  pinMode(8,OUTPUT);//Green LED to indicate decrease in temperature
  pinMode(9,OUTPUT);//Blue LED to indicate increase in temperature
  pinMode(13,OUTPUT);//Brown LED considered as light and DC motor to turn ON fan
}

void loop()
{
  // Getting the data from the Temperature sensor
  double a = analogRead(A0);
 
  // Converting Analog value to Digital Value 
  double Conv = (((a/1024)*5)-0.5)*100;
  Serial.println("The Temperature is :");
  Serial.println(Conv);
  Serial.println("****************************");
  delay(1000);
  if(Conv>30)
  {
    	digitalWrite(9,HIGH);
    	digitalWrite(8,LOW);
  }
  else
  {
    	digitalWrite(8,HIGH);
    	digitalWrite(9,LOW);
  }
  
  //PIR Sensor
  int pirsensor=digitalRead(2);
  if(pirsensor==HIGH)
  {
    Serial.println("Motion detected");
    digitalWrite(13,HIGH);
    delay(10000);
  }
  else
  {
    digitalWrite(13,LOW);
    delay(120);
  }
  
  //Ultrasonic sensor
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  delayMicroseconds(10);
  digitalWrite(4,LOW);
  int time=pulseIn(3,HIGH);
  int distance=(time*0.034)/2;
  Serial.println("Distance is:");
  Serial.println(distance);
  if(distance<=20)
  {
    Serial.println("Person detected");
    digitalWrite(5,HIGH);
    delay(500);
  }
  else
  {
    digitalWrite(5,LOW);
    delay(500);
  }
}