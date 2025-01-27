/* TinyI2C v2.0.1

   David Johnson-Davies - www.technoblogy.com - 5th June 2022
   
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license: 
   http://creativecommons.org/licenses/by/4.0/
   
   Edited by Martin Marcinčák into TinierI2C v2.0.2
*/

#ifndef TinierI2CMaster_h
#define TinierI2CMaster_h

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

/* CHOOSE THE ONE THAT APPLIES */
//#define USIDR
//#define TWDR
//#define DXCORE
#define MEGATINYCORE
//#define MEGACOREX

class TinierI2CMaster {

public:
  TinierI2CMaster();
  void init(void);
  uint8_t read(void);
  uint8_t readLast(void);
  bool write(uint8_t data);
  bool start(uint8_t address, int32_t readcount);
  bool restart(uint8_t address, int32_t readcount);
  void stop(void);

private:
  int32_t I2Ccount;
  uint8_t transfer(uint8_t data);
};

extern TinierI2CMaster TinierI2C;

#endif

