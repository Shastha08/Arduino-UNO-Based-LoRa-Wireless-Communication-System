
#include <SPI.h>
#include <LoRa.h>

//====================================================
// LORA PIN CONFIGURATION
//====================================================

#define SS_PIN       10
#define RST_PIN      9
#define DIO0_PIN     2

//====================================================
// LORA PARAMETERS
//====================================================

#define LORA_FREQUENCY  433E6

//====================================================
// VARIABLES
//====================================================

unsigned long previousMillis = 0;

const unsigned long TX_INTERVAL = 1000;

unsigned long txCount = 0;

//====================================================
// SETUP
//====================================================

void setup()
{
    Serial.begin(9600);

    delay(1000);

    Serial.println();
    Serial.println("================================");
    Serial.println(" ARDUINO UNO LORA TRANSMITTER");
    Serial.println("================================");

    // LoRa Pin Configuration
    LoRa.setPins(SS_PIN, RST_PIN, DIO0_PIN);

    // Initialize LoRa
    Serial.println("INITIALIZING LORA...");

    if (!LoRa.begin(LORA_FREQUENCY))
    {
        Serial.println("LORA INIT FAILED!");

        while (1);
    }

    //================================================
    // LORA CONFIGURATION
    //================================================

    LoRa.setSpreadingFactor(7);

    LoRa.setSignalBandwidth(125E3);

    LoRa.setCodingRate4(5);

    LoRa.setSyncWord(0x12);

    LoRa.enableCrc();

    LoRa.setTxPower(17, PA_OUTPUT_PA_BOOST_PIN);

    //================================================

    Serial.println("LORA INITIALIZATION SUCCESS");

    Serial.println("FREQUENCY : 433 MHz");
    Serial.println("SF        : 7");
    Serial.println("BANDWIDTH : 125 kHz");
    Serial.println("CODING    : 4/5");
    Serial.println("SYNC WORD : 0x12");
    Serial.println("CRC       : ENABLED");

    Serial.println("--------------------------------");
    Serial.println("TRANSMITTING CHARACTER: s");
    Serial.println("INTERVAL: 1000 ms");
    Serial.println("--------------------------------");

    previousMillis = millis();
}

//====================================================
// LORA TRANSMIT FUNCTION
//====================================================

void LoRa_Transmit()
{
    // Start packet
    LoRa.beginPacket();

    // Send ONLY one character
    LoRa.write((uint8_t)'s');

    // Blocking transmission
    int result = LoRa.endPacket();

    if (result == 1)
    {
        txCount++;

        Serial.print("TRANSMITTED: s");

        Serial.print(" | COUNT: ");

        Serial.println(txCount);
    }
    else
    {
        Serial.println("TRANSMISSION FAILED");
    }
}

//====================================================
// MAIN LOOP
//====================================================

void loop()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= TX_INTERVAL)
    {
        previousMillis = currentMillis;

        LoRa_Transmit();
    }
}
