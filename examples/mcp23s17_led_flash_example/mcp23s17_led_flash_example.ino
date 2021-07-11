/*
 * MCP23S17 LED Flash example  
 */
#include <SPI.h>
#include <MCP23S17.h>

/*
 * Unlike the other examples, this one defaults to address 0 which is
 * the default on my module. We use pin 10 as the Slave Select / Chip Select pin.
 */
MCP iochip(0,10);

void setup() {
  SPI.begin();
  Serial.begin(57600);
  Serial.println();
  Serial.println();
  Serial.println(F("----------------------------------------------------"));
  Serial.println(F("MCP23S17 LED Flash example"));
  Serial.print(F(" - Setting arduino pin 10 to output... "));
  pinMode(10,OUTPUT);
  Serial.println(F("done."));

  Serial.print(F(" - Enabling as SPI slave select (SS) / chip select (CS) line... "));
  digitalWrite(10,LOW);
  Serial.println(F("done."));

  Serial.print(F(" - Initializing MCP23S17... "));
  iochip.begin();
  Serial.println(F("done."));

  Serial.print(F(" - Configuring MCP23S17 output pins.... "));
  // quick method to set all pin directions to output
  iochip.byteWrite(IODIRA, 0x00);
  iochip.byteWrite(IODIRB, 0x00);
  // quick method to zero all output values
  iochip.byteWrite(OLATA, 0x00);
  iochip.byteWrite(OLATB, 0x00);
  Serial.println(F("done."));
  Serial.println(F("----------------------------------------------------"));
}

void loop() {
  Serial.println(F("On."));
  // per pin method to set output values.
  // we could also do...
  //  iochip.byteWrite(OLATA, 0xFF); // pins 0-7
  //  iochip.byteWrite(OLATB, 0xFF); // pins 8-15
  // ... which would be faster and more concise but less readable.
  iochip.digitalWrite(0, HIGH);
  iochip.digitalWrite(1, HIGH);
  iochip.digitalWrite(2, HIGH);
  iochip.digitalWrite(3, HIGH);
  iochip.digitalWrite(4, HIGH);
  iochip.digitalWrite(5, HIGH);
  iochip.digitalWrite(6, HIGH);
  iochip.digitalWrite(7, HIGH);
  iochip.digitalWrite(8, HIGH);
  iochip.digitalWrite(9, HIGH);
  iochip.digitalWrite(10, HIGH);
  iochip.digitalWrite(11, HIGH);
  iochip.digitalWrite(12, HIGH);
  iochip.digitalWrite(13, HIGH);
  iochip.digitalWrite(14, HIGH);
  iochip.digitalWrite(15, HIGH);
  delay(200);
  Serial.println(F("Off."));
  // we could also do...
  //  iochip.byteWrite(OLATA, 0x00); // pins 0-7
  //  iochip.byteWrite(OLATB, 0x00); // pins 8-15
  // ... which would be faster and more concise but less readable.
  iochip.digitalWrite(0, LOW);
  iochip.digitalWrite(1, LOW);
  iochip.digitalWrite(2, LOW);
  iochip.digitalWrite(3, LOW);
  iochip.digitalWrite(4, LOW);
  iochip.digitalWrite(5, LOW);
  iochip.digitalWrite(6, LOW);
  iochip.digitalWrite(7, LOW);
  iochip.digitalWrite(8, LOW);
  iochip.digitalWrite(9, LOW);
  iochip.digitalWrite(10, LOW);
  iochip.digitalWrite(11, LOW);
  iochip.digitalWrite(12, LOW);
  iochip.digitalWrite(13, LOW);
  iochip.digitalWrite(14, LOW);
  iochip.digitalWrite(15, LOW);
  delay(200);
}
