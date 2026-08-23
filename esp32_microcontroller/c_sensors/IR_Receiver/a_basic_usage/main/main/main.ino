#include <IRremote.hpp>                                                       //  important:  use IRremote.hpp instead of IRremote.h

#define IR_RECEIVER_PIN   15
#define BAUD_RATE         9600
#define PIN_LED           13

void setup() {
  Serial.begin(BAUD_RATE);
  delay(1000);

  IrReceiver.begin(IR_RECEIVER_PIN, /*aEnableLEDFeedback: */ true);           //  alternative:  ENABLE_LED_FEEDBACK for true | DISABLE_LED_FEEDBACK for false
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {    
    IrReceiver.printIRResultShort(&Serial);                                   //  Print protocol, address, command, etc.
    IrReceiver.printIRSendUsage(&Serial);                                     //  Print raw timing values

    Serial.print("Protocol : ");
    Serial.println(getProtocolString(IrReceiver.decodedIRData.protocol));

    Serial.print("Address  : 0x");
    Serial.println(IrReceiver.decodedIRData.address, HEX);

    Serial.print("Command  : 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    Serial.print("Raw Data : 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
      Serial.println("Repeat frame");
    }

    IrReceiver.resume();                                                      //  ready for the next transmission
                                                                              //  NOTE: this is required, otherwise the next command can't be analyzed
  }
}