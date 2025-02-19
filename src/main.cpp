#include <Arduino.h>

float sample_mu = 0;
int SUM = 0;
int samples = 10;
int millisdelay = 10;

void setup() {
Serial.begin(115200);
pinMode(A0, INPUT);
}

void loop() {
sample_mu = 0;
int sample = 0;
SUM = 0;
for (int i = 0; i < samples; i++) {
  sample = analogRead(A0);
  SUM += sample;
  delay(millisdelay);
}

sample_mu = ((float)SUM / (float)samples);
Serial.println(sample_mu);

}
