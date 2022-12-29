
#define dir2 7
#define pwm2 6
#define pwm1 5
#define dir1 4
#define pwm 9
#define dir 8
#define RX 1
#define TX 0 
#define serialEn 2
#define jnPulse 3 
#define An A0
int readVal,positionVal;  
int lastError = 0; 

const float Kp = 0.5; 
const float Kd = 2;   
const int setPoint = 35;  
const int baseSpeed = 50; 
   

void forward()
{
  analogWrite(pwm1,50);
  digitalWrite(dir1,LOW);
  analogWrite(pwm2,50);
  digitalWrite(dir2,LOW);
  analogWrite(pwm,LOW);
  digitalWrite(dir,LOW);
}
void right()
{ 
  analogWrite(pwm1,50);
  digitalWrite(dir1,LOW);
  analogWrite(pwm2,50);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm,50);
  digitalWrite(dir,HIGH);
}
void left()
{ 
  analogWrite(pwm1,50);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm2,50);
  digitalWrite(dir2,LOW);
  analogWrite(pwm,50);
  digitalWrite(dir,LOW);
}
void reverse()
{ 
  analogWrite(pwm1,50);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm2,50);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm,LOW);
  digitalWrite(dir,LOW);
}
void stopbot()
{
  analogWrite(pwm1,LOW);
  analogWrite(pwm2,LOW);
  analogWrite(pwm,LOW);
}
void pid()
{
  
  int  error= positionVal - setPoint;
  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error; 

  int rightMotorSpeed = baseSpeed - motorSpeed;
  int leftMotorSpeed = baseSpeed +
  motorSpeed;

  constrain(0,255,rightMotorSpeed);
  constrain(0,255,leftMotorSpeed);
  
  analogWrite(pwm1,rightMotorSpeed);
  analogWrite(pwm2,leftMotorSpeed);
}

void setup()
{ 
  
  Serial.begin(9600);
  pinMode(dir2,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir,OUTPUT);
  pinMode(pwm,OUTPUT);

  pinMode(serialEn,OUTPUT); 
  pinMode(jnPulse,INPUT);

  digitalWrite(serialEn,HIGH);
  
  analogWrite(pwm1,LOW);
  digitalWrite(dir1,LOW);
  analogWrite(pwm2,LOW);
  digitalWrite(dir2,LOW);
  analogWrite(pwm,LOW);
  digitalWrite(dir,LOW);

  delay(2000);
  
}
/*
  int lastError = 0;    

void loop()
{
  digitalWrite(serialEn,LOW);
  while(Serial.available() <= 0);   // Wait for data to be available
  int positionVal = Serial.read();    // Read incoming data and store in variable positionVal
  digitalWrite(serialEn,HIGH);    // Stop requesting for UART data

  // If no line is detected, stay at the position
  if(positionVal == 255)
  {
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
  }

  // Else if line detected, calculate the motor speed and apply
  else
  {
    int error = positionVal - setPoint;   // Calculate the deviation from position to the set point
    int motorSpeed = Kp * error + Kd * (error - lastError);   // Applying formula of PID
    lastError = error;    // Store current error as previous error for next iteration use

    // Adjust the motor speed based on calculated value
    // You might need to interchange the + and - sign if your robot move in opposite direction
    int rightMotorSpeed = baseSpeed - motorSpeed;
    int leftMotorSpeed = baseSpeed + motorSpeed;

    // If the speed of motor exceed max speed, set the speed to max speed
    if(rightMotorSpeed > maxSpeed) rightMotorSpeed = maxSpeed;
    if(leftMotorSpeed > maxSpeed) leftMotorSpeed = maxSpeed;

    // If the speed of motor is negative, set it to 0
    if(rightMotorSpeed < 0) rightMotorSpeed = 0;
    if(leftMotorSpeed < 0) leftMotorSpeed = 0;

    // Writing the motor speed value as output to hardware motor
    analogWrite(pwm1,rightMotorSpeed);
    analogWrite(pwm2,leftMotorSpeed);
  }

}*/
void loop()
{
  /*digitalWrite(serialEn,LOW);
  while(Serial.available() <= 0);   // Wait for data to be available
  int positionVal = Serial.read();    // Read incoming data and store in variable positionVal
  digitalWrite(serialEn,HIGH);    // Stop requesting for UART data*/
  
  
  readVal = analogRead(An);
  positionVal = ((float)readVal/921)*70;
  
  pid();

  if(digitalRead(jnPulse)==HIGH)
  forward();
  
  /*if(positionVal<=25)
  { 
    
    left();
    delay(20);
    
  }
  else if(positionVal<=40)
  { 
    
    forward();
    
  }
  else if(positionVal<=70)
  { 
    
    right();
    delay(20);
    
  }
  
  else
  { 
   
    right();
    delay(20);
  
  }*/
  
  
}
