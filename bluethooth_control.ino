
int m1a = 6; 
int m1b = 9; 
int m2a = 10; 
int m2b = 11; 
int ea = 3; 
int eb = 5; 
char val; 
 
void setup()  
{   
pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin 
pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin 
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin 
pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin 
Serial.begin(9600); 
analogWrite(ea,255);
analogWrite(eb,255);
} 
 
void loop() 
{ 
  while (Serial.available() > 0) 
  { 
  val = Serial.read(); 
  Serial.println(val); 
  } 
 
  if( val == 'F') // Forward 
    { 
      digitalWrite(m1a, HIGH); 
      digitalWrite(m1b, LOW); 
      digitalWrite(m2a, HIGH); 
      digitalWrite(m2b, LOW);   
    } 
  else if(val == 'B') // Backward 
    { 
      digitalWrite(m1a, LOW); 
      digitalWrite(m1b, HIGH); 
      digitalWrite(m2a, LOW); 
      digitalWrite(m2b, HIGH);  
    } 
   
    else if(val == 'L') //Left 
    { 
    digitalWrite(m1a, LOW); 
    digitalWrite(m1b, LOW); 
    digitalWrite(m2a, HIGH); 
    digitalWrite(m2b, LOW); 
    } 
    else if(val == 'R') //Right 
    { 
    digitalWrite(m1a, HIGH); 
    digitalWrite(m1b, LOW); 
    digitalWrite(m2a, LOW); 
    digitalWrite(m2b, LOW);  
    } 
     
  else if(val == 'S') //Stop 
    { 
    digitalWrite(m1a, LOW); 
    digitalWrite(m1b, LOW); 
    digitalWrite(m2a, LOW); 
    digitalWrite(m2b, LOW);  
    } 
  else if(val == 'I') //Forward Right 
    { 
    
    analogWrite(m1a, 180); 
    digitalWrite(m1b, LOW); 
    digitalWrite(m2a, LOW); 
    digitalWrite(m2b, LOW); 
    } 
  else if(val == 'J') //Backward Right 
    { 
    digitalWrite(m1a, LOW); 
    analogWrite(m1b, 180); 
    digitalWrite(m2a, LOW); 
    analogWrite(m2b, LOW); 
   
    } 
   else if(val == 'G') //Forward Left 
   {
    digitalWrite(m1a, LOW); 
    digitalWrite(m1b, LOW); 
    analogWrite(m2a, 180);     
    digitalWrite(m2b, LOW); 
    } 
  else if(val == 'H') //Backward Left 
    { 
    digitalWrite(m1a, LOW); 
    digitalWrite(m1b, LOW); 
    digitalWrite(m2a, LOW); 
    analogWrite(m2b, 180);
      
    } 
     
} 
 
 
