#include <Arduino.h>

int samples = 10;
int millisdelay = 10;
float resistor_series = 10e3; // ohm

void setup() {
  Serial.begin(BAUD);
  pinMode(A0, INPUT);
}

void loop() {
  float sum_bit = 0.0f;
  for (int i = 0; i < samples; i++) {
    sum_bit += analogRead(A0);
    delay(millisdelay);
  }

  // in bits
  float sum_volt = sum_bit / 1023.0f * 5.0f;
  float sample_mean_volt = (sum_volt / (float)samples);

  // \[V_{\text{out} }= V_\text{in} \frac{R}{R + R_{1}} \]
  // (Vo/Vi)R1 * 1/(1- (Vo/Vi)) = R

  float trans = sample_mean_volt / 5.0f;

  float thermistor = trans * resistor_series / (1 - trans);

  Serial.println(thermistor);
}
