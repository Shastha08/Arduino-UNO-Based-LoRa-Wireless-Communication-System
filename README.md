# Arduino UNO Based LoRa Wireless Communication System

## Project Description

This project implements wireless communication between two Arduino UNO boards using SX1278 RA-02 LoRa modules operating at 433 MHz.

The transmitter sends the character **'s'** at a regular interval of 1000 milliseconds. The receiver receives the transmitted LoRa packet and displays the received character on a 16x2 I2C LCD and Serial Monitor.

The project demonstrates point-to-point wireless communication using LoRa technology.

## Project Objectives

- Establish wireless communication between two Arduino UNO boards.
- Implement LoRa communication using SX1278 RA-02 modules.
- Transmit data at regular time intervals.
- Receive and process wireless data packets.
- Monitor RSSI and SNR values.
- Display received data using an I2C LCD.

## Hardware Components

| S.No | Component | Quantity |
|---|---|---|
| 1 | Arduino UNO | 2 |
| 2 | SX1278 RA-02 LoRa Module (433 MHz) | 2 |
| 3 | 16x2 I2C LCD Display | 1 |
| 4 | 433 MHz Antenna | 2 |
| 5 | Jumper Wires | As required |
| 6 | Regulated 3.3V Power Supply | As required |

## Software Requirements

- Arduino IDE
- LoRa Library by Sandeep Mistry
- LiquidCrystal_I2C Library
- Proteus Design Suite

## Circuit Connections

### LoRa Module – Arduino UNO

| RA-02 Pin | Arduino UNO Pin |
|---|---|
| NSS | D10 |
| RESET | D9 |
| DIO0 | D2 |
| MOSI | D11 |
| MISO | D12 |
| SCK | D13 |
| VCC | 3.3V regulated supply |
| GND | GND |

### I2C LCD – Arduino UNO (Receiver)

| LCD Pin | Arduino UNO Pin |
|---|---|
| SDA | A4 |
| SCL | A5 |
| VCC | According to LCD module specification |
| GND | GND |

**Important:** SX1278 RA-02 operates at 3.3V. Do not directly connect its power or logic pins to 5V. Use appropriate voltage regulation and logic-level interfacing.

## LoRa Communication Parameters

| Parameter | Value |
|---|---|
| Frequency | 433 MHz |
| Spreading Factor | 7 |
| Bandwidth | 125 kHz |
| Coding Rate | 4/5 |
| Sync Word | 0x12 |
| CRC | Enabled |
| Transmission Interval | 1000 ms |
| Transmitted Character | 's' |
| TX Power | 17 dBm |

## Working Principle

### Transmitter Operation

1. Arduino UNO initializes the SX1278 LoRa module.
2. LoRa communication parameters are configured.
3. The transmitter sends the character 's'.
4. Transmission occurs every 1000 milliseconds.
5. Successful transmission count is displayed on the Serial Monitor.

### Receiver Operation

1. Arduino UNO initializes the LoRa module and I2C LCD.
2. The receiver continuously monitors incoming packets.
3. When a packet arrives, the receiver reads the received bytes.
4. Packet size, RSSI and SNR values are displayed on the Serial Monitor.
5. The LCD displays the received character.

## Expected Output

### Transmitter Serial Monitor

```text
ARDUINO UNO LORA TRANSMITTER

LORA INITIALIZATION SUCCESS

FREQUENCY : 433 MHz
SF        : 7
BANDWIDTH : 125 kHz
CODING    : 4/5
SYNC WORD : 0x12
CRC       : ENABLED

TRANSMITTED: s | COUNT: 1
TRANSMITTED: s | COUNT: 2
TRANSMITTED: s | COUNT: 3
```

### Receiver LCD Display

```text
DATA RECEIVED
CHARACTER: s
```

### Receiver Serial Monitor

The receiver displays:

- Packet Size
- Available Bytes
- Received Data (HEX)
- Read Bytes
- RSSI
- SNR

## Repository Structure

```text
Arduino-UNO-Based-LoRa-Wireless-Communication-System/
│
├── design/
│   └── Proteus Simulation Files
│
├── receiver/
│   └── receiver/
│       └── receiver.ino
│
├── transmit/
│   └── transmit/
│       └── transmit.ino
│
└── README.md
```

## How to Run

1. Install Arduino IDE.
2. Install the LoRa library by Sandeep Mistry.
3. Install the LiquidCrystal_I2C library.
4. Open the transmitter Arduino code.
5. Select Arduino UNO and upload the transmitter program.
6. Open the receiver Arduino code.
7. Select Arduino UNO and upload the receiver program.
8. Power both LoRa modules using suitable regulated 3.3V supplies.
9. Connect the appropriate antennas.
10. Open Serial Monitor at 9600 baud.
11. Observe the transmitted and received data.

## Applications

- Wireless sensor networks
- IoT communication systems
- Remote monitoring applications
- Long-range wireless communication
- Embedded systems projects
- Industrial monitoring applications

## Technologies Used

`Arduino UNO` | `Embedded C/C++` | `LoRa` | `SX1278` | `433 MHz` | `SPI` | `I2C` | `Proteus`

## Author

**SHASTHA CHANDRU S**

Embedded Systems Engineer

## License

This project is intended for educational and research purposes. No formal open-source license has been specified.
