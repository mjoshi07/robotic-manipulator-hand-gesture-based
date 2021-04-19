#include <Servo.h> //include servo library

Servo myservo; // create servo object to control a servo
int dataPinD0=11; //data pin Do from decoder
int dataPinD1=12; //data pin D1 from decoder
int dataPinD2=13; //data pin D2 from decoder
int potpin = 10; //data pin from decoder
int Vccpin= A4; // Vcc for decoder and receiver
int Gndpin=A5; // Gnd for decoder and receiver
int VccForIC=A0; //Vcc for L293D IC
int GndForICC=A1; //Gnd for L293D IC
int motor1Terminal1=2; // motor1 terminal 1 connected to digital pin 2
int motor1Terminal2=3; // motor1 terminal 2 connected to digital pin 3
int motor2Terminal1=8; // motor2 terminal 1 connected to digital pin 8
int motor2Terminal2=9; // motor2 terminal 2 connected to digital pin 9
int valAnalogPin; // variable to read the value from the analog pin

void setup()
{
    Serial.begin(9600);
    myservo.attach(6); // attaches the servo on pin 9 to the servo object
    pinMode(potpin,INPUT);
    pinMode(Gndpin,OUTPUT);
    pinMode(Vccpin, OUTPUT);
    pinMode(VccForIC, OUTPUT);
    pinMode(GndForICC, OUTPUT);
    pinMode(dataPinD0, INPUT);
    pinMode(dataPinD1, INPUT);
    pinMode(dataPinD2, INPUT);
    pinMode(motor1Terminal1, OUTPUT);
    pinMode(motor1Terminal2, OUTPUT);
    pinMode(motor2Terminal1, OUTPUT);
    pinMode(motor2Terminal2, OUTPUT);
    digitalWrite(Gndpin,LOW);
    digitalWrite(Vccpin,HIGH);
    digitalWrite(VccForIC, HIGH);
    digitalWrite(GndForICC, LOW);
}

void loop()
{
    valAnalogPin=digitalRead(potpin);

    int val1=digitalRead(dataPinD0);
    int val2=digitalRead(dataPinD1);
    int val3=digitalRead(dataPinD2);

    if (val1==1 && val2==1 && val3==1)
    {
        valAnalogPin =map (valAnalogPin, 0,1,0,100);
        Serial.println(valAnalogPin);
        myservo.write(valAnalogPin);
        digitalWrite(motor1Terminal1, HIGH);
        digitalWrite(motor1Terminal2, LOW);
        digitalWrite(motor2Terminal1, LOW);
        digitalWrite(motor2Terminal2, LOW);
        Serial.println(" ");
        Serial.println("forward");
    }
    else if (val1==0 && val2==1 && val3==0)
    {
        valAnalogPin = map (valAnalogPin, 0,1,0,100);
        Serial.println(valAnalogPin);
        myservo.write(valAnalogPin);
        Serial.println(" ");
        Serial.println("backward");
        digitalWrite(motor1Terminal1, LOW);
        digitalWrite(motor1Terminal2, HIGH);
        digitalWrite(motor2Terminal1, LOW);
        digitalWrite(motor2Terminal2, LOW);
    }
    else if (val1==1 && val2==0 && val3==0)
    {
        valAnalogPin =map (valAnalogPin, 0,1,0,100);
        Serial.println(valAnalogPin);
        myservo.write(valAnalogPin);
        Serial.println("");
        Serial.println("right");
        digitalWrite(motor1Terminal1, LOW);
        digitalWrite(motor1Terminal2, LOW);
        digitalWrite(motor2Terminal1, LOW);
        digitalWrite(motor2Terminal2, HIGH);
    }
        else if (val1==0 && val2==0 && val3==1)
    {
        valAnalogPin =map (valAnalogPin, 0,1,0,100);
        Serial.println(valAnalogPin);
        myservo.write(valAnalogPin);
        Serial.println(" ");
        Serial.println("left");
        digitalWrite(motor1Terminal1, LOW);
        digitalWrite(motor1Terminal2, LOW);
        digitalWrite(motor2Terminal1, HIGH);
        digitalWrite(motor2Terminal2, LOW);
    }
    else if (val1==0 && val2==0 && val3==0)
    {
        valAnalogPin =map (valAnalogPin, 0,1,0,100);
        Serial.println(valAnalogPin);
        myservo.write(valAnalogPin);
        Serial.println("");
        Serial.println("stop");
        digitalWrite(motor1Terminal1, LOW);
        digitalWrite(motor1Terminal2, LOW);
        digitalWrite(motor2Terminal1, LOW);
        digitalWrite(motor2Terminal2, LOW);
    }
}
