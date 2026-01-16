# Gas-Detection-System
The Gas Detection System using Arduino and MQ2 Sensor is an embedded system designed to detect and monitor the presence of harmful and combustible gases in the surrounding environment. It uses the MQ2 gas sensor, which is capable of sensing gases such as LPG (Liquefied Petroleum Gas), methane, carbon monoxide (CO), hydrogen, alcohol, propane,
and smoke. The system provides both visual and audio alerts whenever the gas concentration crosses a specified safety threshold. It also displays real-time gas readings on
an I²C-based Liquid Crystal Display (LCD) and transmits data to the serial monitor for observation and analysis.


##  MQ-2 Gas Sensor Working Principle

The MQ-2 sensor is a **semiconductor-based gas sensor** that operates on the principle of change in electrical resistance of its sensing material, **Tin Dioxide (SnO₂)**, when exposed to combustible and hazardous gases.

In clean air, the SnO₂ sensing layer exhibits **high resistance**. When a target gas is present, it reacts with the **adsorbed oxygen ions** on the surface of the sensor. This reaction releases electrons back into the SnO₂ conduction band, resulting in a **decrease in sensor resistance**.

The change in resistance causes a corresponding change in the output voltage, which is **proportional to the concentration of the detected gas**.

###  Sensor Outputs

The MQ-2 sensor provides two types of outputs:

- **Analog Output (AO):**  
  Produces a continuous voltage signal (0–5V) that varies with gas concentration. This allows precise and real-time monitoring.

- **Digital Output (DO):**  
  Outputs a HIGH or LOW signal depending on whether the gas concentration crosses a preset threshold. The threshold can be adjusted using the onboard potentiometer.

###  Project Implementation

In this project, the **analog output (AO)** of the MQ-2 sensor is connected to the **analog input pin (A0)** of the Arduino Uno to obtain accurate and continuous gas concentration readings, enabling reliable detection and alert generation.

##  Microcontroller Unit: ATmega328P

The **ATmega328P** is an **8-bit AVR RISC-based microcontroller** widely used in embedded systems and forms the core of the Arduino Uno platform. It follows a **Reduced Instruction Set Computing (RISC)** architecture with **131 powerful instructions**, most of which execute in a **single clock cycle**, enabling efficient and high-speed operation.

The microcontroller supports clock frequencies of up to **20 MHz** when driven by an external crystal oscillator. In the Arduino Uno, it typically operates at a clock speed of **16 MHz**.

###  Key Features

- **CPU Architecture:** 8-bit AVR RISC CPU  
- **Flash Memory:** 32 KB (0.5 KB used by the bootloader)  
- **SRAM:** 2 KB  
- **EEPROM:** 1 KB (non-volatile memory for data storage)  
- **Operating Voltage:** 1.8 V – 5.5 V (5 V typical for Arduino Uno)  
- **Clock Speed:** 16 MHz (external crystal oscillator)  

###  Peripheral Support

- **Analog-to-Digital Converter (ADC):**  
  - 10-bit resolution  
  - 6 channels (DIP package) / 8 channels (SMD package)  

- **Timers:**  
  - 3 timers (two 8-bit and one 16-bit) for precise timing and PWM generation  

- **I/O Pins:**  
  - 23 general-purpose digital I/O lines  

###  Communication Interfaces

- **USART:** Serial communication  
- **SPI:** Serial Peripheral Interface  
- **I²C / TWI:** Two-Wire Interface  

###  Power Management

- Multiple **power-saving sleep modes** for low-power operation, making the ATmega328P suitable for energy-efficient embedded applications.

##  Role of Arduino Microcontroller

The **Arduino Uno**, based on the **ATmega328P microcontroller**, acts as the main control unit of the gas detection system. It is responsible for data acquisition, processing, decision-making, and output control.

###  Functions Performed

1. Reads the analog voltage from the **MQ-2 gas sensor** through the built-in **Analog-to-Digital Converter (ADC)**.
2. Processes the sensor data to compute approximate gas concentration levels (simulated in parts per million).
3. Compares the measured gas values with predefined safety threshold levels.
4. Activates output devices such as the **LED** and **buzzer** when unsafe gas levels are detected.
5. Displays real-time gas concentration values on the **I²C LCD** and transmits the data to the **serial monitor** for monitoring and debugging.

The **Liquid Crystal Display (LCD)** is interfaced using the **I²C communication protocol** via the **PCF8574 I/O expander module**, minimizing the number of required Arduino I/O pins.

---

##  Circuit Description

- The **MQ-2 sensor (AO pin)** is connected to the **A0** analog input pin of the Arduino Uno.
- The **VCC** and **GND** pins of the sensor are connected to the **5V** and **GND** pins of the Arduino, respectively.
- The **I²C LCD module** is interfaced using:
  - **SDA → A4**
  - **SCL → A5**
- The **LED** is connected to **digital pin 7**.
- The **buzzer** is connected to **digital pin 8**.

For simulation and calibration purposes (e.g., in **Proteus**), a **potentiometer** may be used to emulate the analog output of the gas sensor.

---

##  System Operation

1. Upon power-up, the LCD initializes and displays a welcome message.
2. The Arduino continuously reads the analog voltage from the MQ-2 sensor or potentiometer.
3. The readings are scaled to represent approximate concentrations of **LPG, CO, and smoke** using the `map()` function.
4. The processed values are displayed on the LCD and printed to the serial monitor.
5. When the gas concentration exceeds a predefined threshold, the **LED turns ON** and the **buzzer is activated**.
6. When the gas level returns to safe limits, the **LED and buzzer automatically turn OFF**.

---

##  Advantages of the System

- Low-cost and easy to implement using off-the-shelf components.
- Provides both **visual and audible alerts**.
- Supports **real-time monitoring** via LCD and serial interface.
- Easily extendable to **IoT platforms** for remote monitoring and automation.
- Portable and suitable for **home, industrial, and laboratory applications**.

---

##  Applications

- LPG leakage detection in kitchens and industrial plants.
- Fire and smoke detection systems.
- Air quality monitoring in laboratories and enclosed spaces.
- Integration into **smart home safety systems**.
- Industrial safety monitoring and automation.





