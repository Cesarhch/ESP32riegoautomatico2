#include <Arduino.h>

const int sensor = 12;
int valorsensor;

const int bomba=14;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT_PULLDOWN);

  pinMode(bomba, OUTPUT);
}

void loop()
{
  valorsensor = analogRead(sensor);
  if(valorsensor>=1500){
    digitalWrite(bomba, HIGH);
    delay(1000);
  }
  digitalWrite(bomba, LOW);
  esp_sleep_enable_timer_wakeup(10 * 60 * 1000000); // Despertar cada 10 minutos
  esp_deep_sleep_start();
}