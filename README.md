# Carduino

**Documentación del Proyecto**

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

#### 2.2. Controlador de Motor (MotorShieldR3)
El objeto `Car` maneja la locomoción del vehículo con funciones predefinidas.

#### 2.3. Sensores Ultrasónicos
Cada sensor consta de un pin TRIG y un pin ECHO:
- **Frontal:** TRIG_F -> Pin 28, ECHO_F -> Pin 29
- **Derecho:** TRIG_D -> Pin 30, ECHO_D -> Pin 31
- **Izquierdo:** TRIG_I -> Pin 32, ECHO_I -> Pin 33
- **Trasero:** TRIG_A -> Pin 34, ECHO_A -> Pin 35

#### 2.4. Luces y Buzzer
- **Luces frontales:** Pin 7
- **Luces traseras:** Pin 4
- **Luces de prevención:** Pin 10
- **Buzzer:** Pin 6

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

### 5. Mejoras Futuras
- Implementación de un algoritmo de evasión de obstáculos.
- Agregar sensores adicionales para mejorar la detección.

