## Smart-Bin Version Control

### Pins Connection to RPI:

#### 1. LCD Connection

- VCC pin -- 5V on the Raspberry Pi.
- GND pin -- GND on the Raspberry Pi.
- SDA pin -- SDA pin on the Raspberry Pi **(GPIO2)**.
- SCL pin -- SCL pin on the Raspberry Pi **(GPIO3)**.

#### 2. Motion Detection - IR Sensor

- VCC pin -- 5V on the RPI.
- GND pin -- GND on the RPI.
- OUT pin -- GPIO-4

#### 3. For flashlight

- Flashlight -- GPIO-17

#### 4. Ultrasonic for Fill level

- VCC pin -- 5V on the Raspberry Pi.
- GND pin -- GND on the Raspberry Pi.
- TRIG_PIN = GPIO-23
- ECHO_PIN = GPIO-24 [5v => 3.3v] need to stepped down.

#### 5. Ultrasonic for Fill level for organic bin

- VCC pin -- 5V on the Raspberry Pi.
- GND pin -- GND on the Raspberry Pi.
- TRIG_PIN = GPIO-25
- ECHO_PIN = GPIO-8 [5v => 3.3v] need to stepped down.
