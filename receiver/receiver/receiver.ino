#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//====================================================
// LORA PIN CONFIGURATION
//====================================================

#define SS_PIN       10
#define RST_PIN      9
#define DIO0_PIN     2

//====================================================
// LCD CONFIGURATION
//====================================================

LiquidCrystal_I2C lcd(0x27, 16, 2);

//====================================================
// VARIABLES
//====================================================

int packetSize = 0;

unsigned long packetCount = 0;

uint8_t receivedData[255];

int dataLength = 0;

//====================================================
// SETUP
//====================================================

void setup()
{
    Serial.begin(9600);

    delay(1000);

    Serial.println("ARDUINO UNO LORA RECEIVER");

    // LCD Initialization
    lcd.init();
    lcd.backlight();
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("LORA RECEIVER");

    lcd.setCursor(0, 1);
    lcd.print("INITIALIZING...");

    // LoRa Initialization
    LoRa.setPins(SS_PIN, RST_PIN, DIO0_PIN);

    if (!LoRa.begin(433E6))
    {
        Serial.println("LORA INIT FAILED");

        lcd.clear();
        lcd.print("LORA INIT ERROR");

        while (1);
    }

    // LoRa Configuration
    LoRa.setSpreadingFactor(7);

    LoRa.setSignalBandwidth(125E3);

    LoRa.setCodingRate4(5);

    LoRa.setSyncWord(0x12);

    LoRa.enableCrc();

    // Continuous Receive
    LoRa.receive();

    Serial.println("LORA INITIALIZATION SUCCESS");

    Serial.println("FREQUENCY: 433 MHz");
    Serial.println("SF: 7");
    Serial.println("BANDWIDTH: 125 kHz");
    Serial.println("SYNC WORD: 0x12");
    Serial.println("CRC: ENABLED");

    Serial.println("WAITING FOR DATA...");

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("LORA READY");

    lcd.setCursor(0, 1);
    lcd.print("WAITING DATA...");
}

//====================================================
// LORA RECEIVE FUNCTION
//====================================================

void LoRa_Receive()
{
    int packetSize = LoRa.parsePacket();

    if (packetSize > 0)
    {
        Serial.println();
        Serial.println("========================");

        Serial.print("PACKET SIZE: ");
        Serial.println(packetSize);

        Serial.print("AVAILABLE BYTES: ");
        Serial.println(LoRa.available());

        int dataCount = 0;

        Serial.print("DATA HEX: ");

        for (int i = 0; i < packetSize; i++)
        {
            int data = LoRa.read();

            if (data < 0)
            {
                Serial.println();
                Serial.println("READ ERROR!");
                break;
            }

            if (data < 0x10)
            {
                Serial.print("0");
            }

            Serial.print(data, HEX);
            Serial.print(" ");

            dataCount++;
        }

        Serial.println();

        Serial.print("READ BYTES: ");
        Serial.println(dataCount);

        Serial.print("RSSI: ");
        Serial.println(LoRa.packetRssi());

        Serial.print("SNR: ");
        Serial.println(LoRa.packetSnr());

        if (dataCount == 1)
        {
            Serial.println("RECEIVED CHARACTER: s");

            lcd.clear();

            lcd.setCursor(0, 0);
            lcd.print("DATA RECEIVED");

            lcd.setCursor(0, 1);
            lcd.print("CHARACTER: s");
        }
        else
        {
            Serial.println("DATA LENGTH ERROR");

            lcd.clear();

            lcd.setCursor(0, 0);
            lcd.print("DATA ERROR");

            lcd.setCursor(0, 1);
            lcd.print("READ: ");

            lcd.print(dataCount);
        }

        Serial.println("========================");

        LoRa.receive();
    }
}

//====================================================
// MAIN LOOP
//====================================================

void loop()
{
    LoRa_Receive();
}
