//Simple sketch to grab the Wemos Analogue pin value and print it to the serial output. 
//Also displays this value as a percentage of the total voltage

//This means that it will map input voltages between 0 and 5 volts into integer values
//between 0 and 1023. This yields a resolution between readings of: 5 volts / 1024 units or, .0049 volts (4.9 mV) per unit. 

//http://tronixstuff.com/2013/12/12/arduino-tutorials-chapter-22-aref-pin/


  // read the input on analog pin 0:
  //int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  //float voltage = sensorValue * (5.0 / 1023.0);

  

//float sensorValue;
int VoltagePercentage;
int voltageWet = 880;
int voltageDry = 940;
int i = 1;
int s;
int sval = 0;
int svalAverage;
//analogReference(EXTERNAL);


 
void setup()
{
    Serial.begin(115200);
    //ADC_MODE(ADC_VCC); 
}
 
void loop()
{
  
sval = 0;
VoltagePercentage = 0;
//https://www.arduino.cc/en/Reference/FunctionDeclaration
  for (s = 0; s < 5; s++){
    sval = sval + analogRead(A0);    // sensor on analog pin 0
      delay(200);
  }
  svalAverage = sval / 5;    // average
  //sensorValue = analogRead(A0); // read analog input pin 0
  
  //VoltagePercentage = (1-(sensorValue/1024))*100;
  VoltagePercentage = (1-(  (svalAverage-voltageWet)/ (voltageDry-voltageWet)  ))*100;

  //Serial.print(sensorValue, DEC); // prints the value read
  Serial.print("   svalAverage:");
  Serial.print(svalAverage);
  Serial.print("   ");
  Serial.print(VoltagePercentage);
  Serial.print("%  count:");
   Serial.print(i);
   Serial.print("   ");
     Serial.print(svalAverage-voltageWet);
     Serial.print("   ");
     Serial.print(voltageDry-voltageWet);
   Serial.print("\n");
  delay(200); 
  i = i+1;
  
}
