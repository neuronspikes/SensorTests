
const int ledPin = 13;        // built-in arduino uno LED
int ledBright = 127; // defaut = 50% sensor led power at start

int pulseCount=0;
int pulseVal=0;

void setup(){
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT); 
  
  analogWrite(ledPin,ledBright);
  
}

void loop()
{
  if(Serial.available()){
    char val = Serial.read();
    if(val != -1)
    {
      switch(val)
      {
        
      case '8':
        ledBright++;
        if(ledBright>255)ledBright=255;

        Serial.println("+");  
        break;
      case '2':
        ledBright--;
        if(ledBright<0)ledBright=0;
        
        Serial.println("-");   
        break;
      }
      analogWrite(ledPin,ledBright);
    }
  }

  int sensorVal = digitalRead(2);
  
  if(sensorVal != pulseVal) pulseCount++;
  pulseVal=sensorVal;

  Serial.print(ledBright);
  Serial.print("    light=");  
  Serial.print(sensorVal);
  Serial.print("    count=");
  Serial.println(pulseCount);
  
  
  digitalWrite(ledPin,sensorVal);
}



