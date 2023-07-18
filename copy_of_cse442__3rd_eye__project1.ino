int duration;
int distance;
int sensorState = 0;  
  void setup()
  {
    pinMode(13, OUTPUT); //RED LED
    pinMode(12, OUTPUT); //BLUE LED
    pinMode(11, OUTPUT); //GREEN LED
    
    pinMode(10, OUTPUT); //VIBRATION MOTOR
    
    pinMode(9, OUTPUT); //BUZZER
    
    pinMode(2, OUTPUT); //US TRIGGER
    pinMode(3, INPUT); //US ECHO
    
    
    pinMode(5, INPUT);  //PIR
    pinMode(8, OUTPUT);  //BUZZER
    pinMode(4, INPUT);  //SWITCH SOS
    pinMode(6, OUTPUT);  //LED
    
    
    Serial.begin(9600);
  }
void loop()
  {
    digitalWrite(2,HIGH);
    delayMicroseconds(10);
    digitalWrite(2,LOW);
    
    duration= pulseIn(3,HIGH);
    distance= (duration/2)/29;
    
    Serial.print("Distance :");
    Serial.print(distance);
    Serial.print("cm");
    Serial.print("  ");
    
    if(distance>320){         //Safe distance green
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      Serial.println("Safe");
    }
    else{
      digitalWrite(11, LOW);}
    
    if(distance>=150 && distance<320){ // obstacle is close(blue)
      digitalWrite(12, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      Serial.println("Mid Range");
      delay(2000);
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
    }
    
    else{
      digitalWrite(12, LOW);}
       
    if(distance<150){                     //unsafe distance(red)
      digitalWrite(13, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      Serial.println("Unsafe");
      delay(50);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
    }
    else{
      digitalWrite(13, LOW);   
    }
  
  
  
  // read the state of the sensor/digital input
  sensorState = digitalRead(5);
  
  // check if sensor pin is HIGH. if it is, set the
  // LED on.
  if (sensorState == HIGH) {
    digitalWrite(8, HIGH);
    Serial.println("Sensor activated!");
   
  } else {
    digitalWrite(8, LOW);
  }
  delay(100); // Delay a little bit to improve simulation performance
  
  
  if (digitalRead(4)==HIGH) {
    digitalWrite (7, HIGH);
    delay(100);
    Serial.println("SOS!");
  }
  else{
    digitalWrite(7, LOW); }
  
}