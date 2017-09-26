# t3_vdd
Library to measure supply voltage on Teensy

- 3.1/3.2
- 3.5
- 3.6

This not really useful in USB-powered systems, but systems that run from a battery that is directly connected to Vdd - or with an otherwise variable Vdd - can benefit.

Uses pevide's ADC library to perform the measurement, see https://forum.pjrc.com/threads/25532-ADC-library-update-now-with-support-for-Teensy-3-1

To do this, the internal 1.2 V reference and its output buffer have to be enabled. This is done by the library in a call to begin(...). The buffer is set to "low power", that is VREF_SC:MODE_LV = 0b10

A simple example is included.
