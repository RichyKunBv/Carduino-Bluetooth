# Carduino


### 1. Descripción General
Este proyecto consiste en un vehículo autónomo controlado vía Bluetooth con sensores ultrasónicos para detección de obstáculos, un LCD para visualización de estado y luces/buzzer para señalización.

### 2. Dispositivos y Pines Utilizados

#### 2.1. Pantalla LCD (LiquidCrystal)
Conectada en modo 4 bits:
- RS -> Pin 40
- E  -> Pin 41
- D4 -> Pin 42
- D5 -> Pin 43
- D6 -> Pin 44
- D7 -> Pin 45

#### 2.2. Módulo de Motores (MotorShieldR3)
El objeto `Car` maneja la locomoción del vehículo con funciones predefinidas para moverse en distintas direcciones y ajustar la velocidad.

#### 2.3. Módulo Bluetooth
El módulo Bluetooth está conectado a través del puerto serie del microcontrolador:
- **RX:** Recibe datos desde el dispositivo remoto (conectado a TX del microcontrolador).
- **TX:** Envía datos al dispositivo remoto (conectado a RX del microcontrolador).
- **Baud Rate:** 9600 bps.

#### 2.4. Sensores Ultrasónicos
Cada sensor consta de un pin TRIG y un pin ECHO:
- **Frontal:** TRIG_F -> Pin 28, ECHO_F -> Pin 29
- **Derecho:** TRIG_D -> Pin 30, ECHO_D -> Pin 31
- **Izquierdo:** TRIG_I -> Pin 32, ECHO_I -> Pin 33
- **Trasero:** TRIG_A -> Pin 34, ECHO_A -> Pin 35

#### 2.5. Luces y Buzzer
- **Luces frontales:** Pin 7
- **Luces traseras:** Pin 4
- **Luces de prevención:** Pin 10
- **Buzzer:** Pin 6

#### 2.6. Método de Alimentación
El sistema utiliza dos baterías de 9V:
- **Batería 1:** Alimenta el Arduino.
- **Batería 2:** Alimenta el módulo de motores.

### 3. Funcionalidad
#### 3.1. Control del Vehículo
El vehículo responde a comandos vía Bluetooth para moverse en diferentes direcciones:
- **F:** Adelante
- **B:** Atrás
- **L:** Rotar izquierda
- **R:** Rotar derecha
- **S:** Detenerse
- **I, J, G, H:** Movimientos diagonales

#### 3.2. Sensado de Obstáculos
Cada 200 ms se miden las distancias con los sensores ultrasónicos. Si un obstáculo se encuentra a menos de 5 cm, el buzzer emite un tono y el LCD muestra "Chocaste!". Si está entre 5 y 10 cm, se indica la dirección del obstáculo en la pantalla LCD.

#### 3.3. Control de Luces y Buzzer
Los comandos permiten encender y apagar luces y el buzzer:
- **W/w:** Encender/apagar luces frontales
- **U/u:** Encender/apagar luces traseras
- **V/v:** Activar/desactivar buzzer

### 4. Consideraciones
- El vehículo ajusta su velocidad con valores de 0 a 9.
- La velocidad mínima permitida es de 84 (evitando velocidades muy bajas).
- Se implementa un sistema de bandera (`flag`) para activar funciones adicionales.





English


### 1. General Description
This project consists of an autonomous vehicle controlled via Bluetooth with ultrasonic sensors for obstacle detection, an LCD for status display and lights/buzzer for signaling.

### 2. Devices and Pins Used

#### 2.1. LCD Display (LiquidCrystal)
Connected in 4-bit mode:
- RS -> Pin 40
- E -> Pin 41
- D4 -> Pin 42
- D5 -> Pin 43
- D6 -> Pin 44
- D7 -> Pin 45

#### 2.2. Motor Module (MotorShieldR3)
The `Car` object handles the locomotion of the vehicle with predefined functions to move in different directions and adjust the speed.

#### 2.3. Bluetooth Module
The Bluetooth module is connected through the serial port of the microcontroller:
- **RX:** Receives data from the remote device (connected to TX of the microcontroller).
- **TX:** Sends data to the remote device (connected to RX of the microcontroller).
- **Baud Rate:** 9600 bps.

#### 2.4. Ultrasonic Sensors
Each sensor consists of a TRIG pin and an ECHO pin:
- **Front:** TRIG_F -> Pin 28, ECHO_F -> Pin 29
- **Right:** TRIG_D -> Pin 30, ECHO_D -> Pin 31
- **Left:** TRIG_I -> Pin 32, ECHO_I -> Pin 33
- **Rear:** TRIG_A -> Pin 34, ECHO_A -> Pin 35

#### 2.5. Lights and Buzzer
- **Front lights:** Pin 7
- **Rear lights:** Pin 4
- **Warning lights:** Pin 10
- **Buzzer:** Pin 6

#### 2.6. Power Supply Method
The system uses two 9V batteries:
- **Battery 1:** Powers the Arduino.
- **Battery 2:** Powers the motor module.

### 3. Functionality
#### 3.1. Vehicle Control
The vehicle responds to Bluetooth commands to move in different directions:
- **F:** Forward
- **B:** Backward
- **L:** Turn left
- **R:** Turn right
- **S:** Stop
- **I, J, G, H:** Diagonal movements

#### 3.2. Obstacle Sensing
Distances are measured every 200 ms with the ultrasonic sensors. If an obstacle is less than 5 cm away, the buzzer emits a tone and the LCD displays "You crashed!". If it is between 5 and 10 cm, the direction of the obstacle is indicated on the LCD screen.

#### 3.3. Lights and Buzzer Control
The commands allow you to turn on and off lights and the buzzer:
- **W/w:** Turn on/off front lights
- **U/u:** Turn on/off rear lights
- **V/v:** Activate/deactivate buzzer

### 4. Considerations
- The vehicle adjusts its speed with values ​​from 0 to 9.
- The minimum speed allowed is 84 (avoiding very low speeds).
- A flag system is implemented to activate additional functions.
