#ifndef T3_VDD_H
#define T3_VDD_H 1

#include <ADC.h>

namespace t3_vdd
{

uint16_t measure_vdd_mV(ADC& adc)
{
  adc.setAveraging(4, ADC_1);
  adc.setResolution(12, ADC_1);
  adc.setConversionSpeed(ADC_CONVERSION_SPEED::HIGH_SPEED, ADC_1);
  adc.setSamplingSpeed(ADC_SAMPLING_SPEED::HIGH_SPEED, ADC_1);
  int value = adc.analogRead(ADC_INTERNAL_SOURCE::VREF_OUT, ADC_1);
  if (value != ADC_ERROR_VALUE)
  {
    return (1200*adc.getMaxValue(ADC_1))/value;
  }
  return 0;
}

void enable_vref()
{
  // enable VREF_OUT buffer for Vdd measurement
  VREF_TRM |= VREF_TRM_CHOPEN;
  VREF_SC = VREF_SC_VREFEN | VREF_SC_REGEN | VREF_SC_ICOMPEN | VREF_SC_MODE_LV(VREF_SC_MODE_LV_LOWPOWERBUF);
  while(!(VREF_SC & VREF_SC_VREFST))
  { }
}

} // end namespace t3_vdd

#endif // T3_VDD_H
