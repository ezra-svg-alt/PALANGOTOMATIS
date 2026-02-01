int ledmerah = 13;
int ledhijau = 12;
#define ECHO_PIN 10
#define TRIG_PIN 11
#include <Servo.h>

Servo servoku;
int sudut;

void setup() {
  // Memulai komunikasi serial dengan baud rate 9600
  Serial.begin(9600); 
  
  servoku.attach(9);
  pinMode(ledmerah, OUTPUT);
  pinMode(ledhijau, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.println("Sistem Dimulai...");
}

float jarak_cm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, LOW);
  int durasi = pulseIn(ECHO_PIN, HIGH);
  return durasi * 0.034 / 2;
}

void loop() {
  float jarak = jarak_cm();

  // Menampilkan data ke Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  if (jarak > 150) {
    digitalWrite(ledmerah, HIGH);
    digitalWrite(ledhijau, LOW);
    servoku.write(90);
  } 
  else {
    digitalWrite(ledmerah, LOW);
    digitalWrite(ledhijau, HIGH);
    servoku.write(0);
  }
  
  delay(100); // Jeda singkat agar pembacaan serial lebih stabil
}