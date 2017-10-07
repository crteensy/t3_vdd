#include <ADC.h>
#include <t3_vdd.h>
ADC adc;

void setup() {
  t3_vdd::enable_vref();
}

void loop() {
  uint16_t mv = t3_vdd::measure_vdd_mV(adc);
  Serial.printf("vdd: %04d mV\n", mv);
  delay(500);
}
