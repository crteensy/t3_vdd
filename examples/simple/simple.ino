#include <t3_vdd.h>

ADC* pAdc;

void setup() {
  pAdc = new ADC();
  t3_Vdd vdd;
  vdd.begin(pAdc);

  elapsedMillis vddTimer;
  const uint16_t vdd_update_period = 1000;
  while(1)
  {
    if (vddTimer >= vdd_update_period)
    {
      vdd.update();
      Serial.print("vdd = ");
      Serial.print(vdd.get_mV());
      Serial.println(" mv");
      vddTimer = 0;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
