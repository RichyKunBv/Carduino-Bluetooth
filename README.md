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


![WhatsApp Image 2025-03-24 at 16 28 28](https://github.com/user-attachments/assets/408020e9-7793-4984-80c6-95979a045196)

![WhatsApp Image 2025-03-24 at 16 28 36](https://github.com/user-attachments/assets/adbc66e5-7736-477b-942a-db6177fe59d8)

![WhatsApp Image 2025-03-25 at 23 24 34](https://github.com/user-attachments/assets/8a07b6d2-9f78-4327-ab05-2d793c3bb321)

![WhatsApp Image 2025-03-25 at 23 24 35](https://github.com/user-attachments/assets/68d8e8bd-45ff-4472-bbed-fc98cba9e1a2)

![WhatsApp Image 2025-03-25 at 23 24 35 (1)](https://github.com/user-attachments/assets/1edbfe2a-8165-47fb-be6a-14a21717d62c)

![WhatsApp Image 2025-03-25 at 23 24 35 (2)](https://github.com/user-attachments/assets/c2810b38-e3dd-4de5-a3e0-8cf8691ce812)
