//-----------start-----------
//
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
 
Adafruit_ADS1115 ads;
//
double sqI,sumI;
double sampleI;
double Irms;
 
double squareRoot(double fg)
{
    double n = fg / 2.0;
    double lstX = 0.0;
    while (n != lstX)
    {
        lstX = n;
        n = (n + fg / n) / 2.0;
    }
    return n;
}
 
double calcIrms(unsigned int Number_of_Samples, float multiplier,double ical)
{
 
    for (unsigned int n = 0; n < Number_of_Samples; n++)
    {
        sampleI = (double)ads.readADC_Differential_0_1();
      //  Serial.println("Volt");
      //  Serial.println(sampleI);
        sqI = sampleI * sampleI;
        sumI += sqI;
    }
    Irms = squareRoot(sumI / Number_of_Samples) * multiplier * ical;
    sumI = 0;
//--------------------------------------------------------------------------------------
 
    return Irms;
}
 
 
 
void setup()
{
    Serial.begin(115200);
    Wire.begin();
                                                                   //ADS1015  ADS1115
  //                                                                -------  -------
   ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
   //ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV 20A/1V
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
   //ads.setGain(GAIN_FOUR);
    ads.begin();
    Serial.println();
    Serial.println("current meter");
 
}
 
void loop()
{
//    double Irms = calcIrms(64, 0.03125F,2.83) / 100;//SCT013 20A/1v
//    Serial.print(Irms*220.0);        // Apparent power
//    Serial.print(" SCT013 20A/1v ");
//    Serial.println(Irms);            // Irms

//      double Irms = calcIrms(64, 0.03125F,6.8) / 100;//SCT013 50A/1v
//      Serial.print(Irms*220.0);        // Apparent power
//      Serial.print(" SCT013 20A/1v ");
//      Serial.println(Irms);            // Irms

//      double Irms = calcIrms(64, 0.03125F,6.3) / 100;//SCT013 50A/5v
//      Serial.print(Irms*220.0);        // Apparent power
//      Serial.print(" SCT013 50A/5v ");
//      Serial.println(Irms);            // Irms


//      double Irms = calcIrms(64, 0.03125F,3.3) / 100;//SCT013 25A/5v
//      Serial.print(Irms*220.0);        // Apparent power
//      Serial.print(" SCT013 25A/5v ");
//      Serial.println(Irms);            // Irms

//      double Irms = calcIrms(64, 0.03125F,32) / 100;//SCT013 250A/5v
//      Serial.print(Irms*220.0);        // Apparent power
//      Serial.print(" SCT013 250A/5v ");
//      Serial.println(Irms1);            // Irms

     

//      double Irms= calcIrms(64, 0.03125F,64) / 100;//SCT013 500A/5v
//      Serial.print(Irms*220.0);        // Apparent power
//      Serial.print(" SCT013 500A/5v ");
//      Serial.println(Irms2);            // Irms

    delay(1000);
}
 
 
 
 
//------------end------------
