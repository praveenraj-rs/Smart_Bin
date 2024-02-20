## Smart-Bin Version Control

### Steps to Flow:

1. Flashing the RPI OS in RPI-4
2. SSH into RPI

```
ssh raspberry@192.168.172.80
```

user: raspberry
password: pi

3. Cloning the github repository

```
git clone url_of_repository
```

4. Creating the virtual environment

```
python3 -m venv venv
```

5. Activating the virtual environment

```
source /home/raspberry/venv/bin/activate
```

6. Move into deployment folder

```
cd /home/raspberry/smart_bin/img_processing/deployment/
```

7. Install the requirements

```
pip install -r requirements.txt
```

8. Run the Main Script

```
python3 main_script.py
```

### Startup Script

```bash
#!/bin/bash
# Bash Script to run the main script
which python3
cd /home/hexfuse/smart_bin/img_processing/deployment
pwd
activate() {
. /home/hexfuse/venv/bin/activate
}
activate
which python3
python3 main_script.py
```

### Pins Connection to RPI:

#### 1. LCD Connection

- VCC pin -- 5V on the Raspberry Pi.
- GND pin -- GND on the Raspberry Pi.
- SDA pin -- SDA pin on the Raspberry Pi **(GPIO2)**.
- SCL pin -- SCL pin on the Raspberry Pi **(GPIO3)**.

#### 2. Motion Detection - IR Sensor

- VCC pin -- 5V on the RPI.
- GND pin -- GND on the RPI.
- OUT pin -- GPIO-26

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

#### 6. Stepper for BottomBin Rotation

#### 7. Slider Stepper inside bin opening
