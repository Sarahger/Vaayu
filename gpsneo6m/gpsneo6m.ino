// #include <SoftwareSerial.h>

// int Rx_pin = 7;
// int Tx_pin = 6;
// SoftwareSerial SerialGPS(Rx_pin, Tx_pin);

// void setup()
// {
//   Serial.begin(9600);
//   SerialGPS.begin(9600);
// }

// void loop()
// {
//   while (SerialGPS.available() > 0)
//   Serial.write(SerialGPS.read());
// }



#include <SoftwareSerial.h>

// Choose two Arduino pins to use for software serial
int RXPin = 7;
int TXPin = 6;

//Default baud of NEO-6M is 9600
int GPSBaud = 115200;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);

  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);
}

void loop()
{
  // Displays information when new sentence is available.
  while (gpsSerial.available() > 0)
    Serial.write(gpsSerial.read());
}