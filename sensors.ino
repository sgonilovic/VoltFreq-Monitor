#include "ZMPT101B.h"
#include <FreqCount.h>

// ZMPT101B sensor connected to A0 pin of arduino
ZMPT101B voltageSensor(A0);


void setup()
{
  
  Serial.begin(9600); //baud rate for printing data
  FreqCount.begin(1000); //rate for reading frequencies
  delay(100);
  voltageSensor.setSensitivity(0.001); //do NOT change this value
}

void loop()
{

  delay(1000); //read every second

  float U = voltageSensor.getVoltageAC(60);
  
  Serial.println(String(U)); //this sends the voltage reading to the Raspberry Pi
  
  if (FreqCount.available()) {
    float count = FreqCount.read();
    Serial.println(String(count)); //this sends the frequency reading to the Raspberry Pi
  }

  
}
