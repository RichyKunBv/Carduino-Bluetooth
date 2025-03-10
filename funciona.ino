#include <LiquidCrystal.h>
#include <MotorShieldR3.h>

// Configurar LCD en modo 4 bits (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(40, 41, 42, 43, 44, 45);
MotorShieldR3 Car;

// Pines de los sensores ultrasónicos
#define TRIG_F 28
#define ECHO_F 29
#define TRIG_D 30
#define ECHO_D 31
#define TRIG_I 32
#define ECHO_I 33
#define TRIG_A 34
#define ECHO_A 35

// Pines de luces y buzzer
#define pinfrontLights 7
#define pinbackLights 4
#define pinpreventLights 10
#define pinbuzzer 6

// Variables de tiempo para los sensores
unsigned long lastSensorRead = 0;
const unsigned long sensorInterval = 200; // Leer sensores cada 200 ms

// Variables de control
char command = 'S';
char prevCommand = 'A';
int velocity = 0;
boolean flag = false;
int lastObstacle = -1; // Para evitar refrescar el LCD innecesariamente

void setup() {
    Serial.begin(9600); // Bluetooth
    lcd.begin(16, 2);
    
    // Configurar pines de sensores ultrasónicos
    pinMode(TRIG_F, OUTPUT); pinMode(ECHO_F, INPUT);
    pinMode(TRIG_D, OUTPUT); pinMode(ECHO_D, INPUT);
    pinMode(TRIG_I, OUTPUT); pinMode(ECHO_I, INPUT);
    pinMode(TRIG_A, OUTPUT); pinMode(ECHO_A, INPUT);
    
    // Configurar pines de luces y buzzer
    pinMode(pinfrontLights, OUTPUT);
    pinMode(pinbackLights, OUTPUT);
    pinMode(pinpreventLights, OUTPUT);
    pinMode(pinbuzzer, OUTPUT);
    
    lcd.clear();
}

long medirDistancia(int trig, int echo) {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    return pulseIn(echo, HIGH) / 58;  // Convertir a cm
}

void actualizarSensores() {
    int distanciaF = medirDistancia(TRIG_F, ECHO_F);
    int distanciaD = medirDistancia(TRIG_D, ECHO_D);
    int distanciaI = medirDistancia(TRIG_I, ECHO_I);
    int distanciaA = medirDistancia(TRIG_A, ECHO_A);

    int obstaculo = -1;
    if (distanciaF <= 5 || distanciaD <= 5 || distanciaI <= 5 || distanciaA <= 5) {
        // Si algún sensor detecta un objeto a menos de 5 cm, se considera un "chocaste"
        obstaculo = 5;  // Nuevo código para choque
        tone(pinbuzzer, 1000);  // Emite un tono de 1000 Hz cuando se detecta el choque
    } else if (distanciaF <= 10) obstaculo = 0;
    else if (distanciaD <= 10) obstaculo = 1;
    else if (distanciaI <= 10) obstaculo = 2;
    else if (distanciaA <= 10) obstaculo = 3;
    else obstaculo = 4;

    // Actualizar el LCD solo cuando haya un cambio en el obstáculo
    if (obstaculo != lastObstacle) {
        lcd.clear();
        lcd.setCursor(0, 0);
        switch (obstaculo) {
            case 0: lcd.print("Obstaculo Frente"); break;
            case 1: lcd.print("Obstaculo Derecha"); break;
            case 2: lcd.print("Obstaculo Izquierda"); break;
            case 3: lcd.print("Obstaculo Atras"); break;
            case 5: lcd.print("Chocaste!"); break; // Caso de choque
            default: lcd.print("Libre");
        }
        lastObstacle = obstaculo;
    }

    // Detener el buzzer si no hay choque
    if (obstaculo != 5) {
        noTone(pinbuzzer);
    }
}

void loop() {
    if (Serial.available() > 0) { 
        prevCommand = command;
        command = Serial.read();
        if (command != prevCommand) {
            Serial.println(command);
            switch (command) {
                case 'F': 
                    Car.Forward_2W(velocity, velocity); 
                    break;
                case 'B': 
                    Car.Back_2W(velocity, velocity); 
                    break;
                case 'L': 
                    Car.RotateLeft_2W(velocity, velocity); 
                    break;
                case 'R': 
                    Car.RotateRight_2W(velocity, velocity); 
                    break;
                case 'S': 
                    Car.Stopped_2W(); 
                    break;
                case 'I': 
                    Car.ForwardRight_2W(velocity, velocity); 
                    break;
                case 'J': 
                    Car.BackRight_2W(velocity, velocity); 
                    break;
                case 'G': 
                    Car.ForwardLeft_2W(velocity, velocity); 
                    break;
                case 'H': 
                    Car.BackLeft_2W(velocity, velocity); 
                    break;
                case 'W': 
                    digitalWrite(pinfrontLights, HIGH); 
                    break;
                case 'w': 
                    digitalWrite(pinfrontLights, LOW); 
                    break;
                case 'U': 
                    digitalWrite(pinbackLights, HIGH); 
                    break;
                case 'u': 
                    digitalWrite(pinbackLights, LOW); 
                    break;
                case 'X': 
                    flag = true; 
                    break;
                case 'x': 
                    flag = false; 
                    digitalWrite(pinpreventLights, LOW); 
                    break;
                case 'V': 
                    tone(pinbuzzer, 1000); 
                    break;
                case 'v': 
                    noTone(pinbuzzer); 
                    break;
                case 'D': 
                    digitalWrite(pinfrontLights, LOW);
                    digitalWrite(pinbackLights, LOW);
                    Car.Stopped_2W();
                    break;
                default:
                    if (command >= '0' && command <= '9') {
                        velocity = max((command - '0') * 28, 84); // Evita velocidades muy bajas
                        Car.SetSpeed_2W(velocity, velocity);
                    }
            }
        }
    }

    // Actualizar sensores solo después del intervalo de tiempo establecido
    if (millis() - lastSensorRead >= sensorInterval) {
        actualizarSensores();
        lastSensorRead = millis();
    }
}