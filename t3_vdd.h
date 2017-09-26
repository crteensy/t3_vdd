#ifndef T3_VDD_H
#define T3_VDD_H 1

#include <ADC.h>

class t3_Vdd
{
public:
  uint16_t get_mV()
  {
    return m_vdd;
  }

  void begin(ADC* adc)
  {
    m_pAdc = adc;
    // enable VREF_OUT buffer for Vdd measurement
    VREF_TRM |= VREF_TRM_CHOPEN;
    VREF_SC = VREF_SC_VREFEN | VREF_SC_REGEN | VREF_SC_ICOMPEN | VREF_SC_MODE_LV(2);
    while(!(VREF_SC & VREF_SC_VREFST))
    { }
  }

  void update()
  {
    int adc = m_pAdc->analogRead(ADC_INTERNAL_SOURCE::VREF_OUT, ADC_1);
    if (adc != ADC_ERROR_VALUE)
    {
      m_vdd = (1200*m_pAdc->getMaxValue(ADC_1))/adc;
    }
  }
private:
  uint16_t m_vdd;
  ADC* m_pAdc;
};

#endif // T3_VDD_H
