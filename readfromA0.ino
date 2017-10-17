//Simple sketch to grab the Wemos Analogue pin value and print it to the serial output. 
//Also displays this value as a percentage of the total voltage

float sensorValue;
float VoltagePercentage;
//int voltage;  //should make voltage a variable at least



 
void setup()
{
    Serial.begin(115200);
}
 
void loop()
{
  sensorValue = analogRead(A0); // read analog input pin 0
  VoltagePercentage = (1-(sensorValue/1024))*100;

  Serial.print(sensorValue, DEC); // prints the value read
  Serial.print("   ");

  Serial.print(VoltagePercentage);
  Serial.print("%\n"); 
  delay(200); 

  
}
