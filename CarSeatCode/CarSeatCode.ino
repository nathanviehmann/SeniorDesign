/*------------------------------------------------
CarSeatCode.c

Acts as the main loop for the Car Seat Project
------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "CarSeatCodeFunctions.h"

#define TEMP_SENSORS 6

float * pointer;
float   temp_sens_array[TEMP_SENSORS] = {0};
float ret_val = 0;

void setup()
{
pointer = temp_sens_array;

pinMode(FAN_PIN,   OUTPUT);
pinMode(LIGHT_PIN, OUTPUT);
pinMode(SIREN_PIN, OUTPUT);
pinMode(MOTION_PIN,INPUT);
pinMode(WEIGHT_PIN,INPUT);

}

void loop() 
{

#if TESTING

#if TEMP_TEST
ret_val = temp_array_avg( TEMP_SENSORS, pointer );
Serial.print("Average temperature value: ");
Serial.println(ret_val);
#endif

#if FAN_TEST
fans_on();
Serial.println("FANS ARE ON");
#endif

#if BABY_TEST
Serial.print("Is there a baby in the seat? - ");
Serial.println(baby_check());
#endif

#if ALARM_TEST
sound_alarm();
Serial.println("ALARM IS ON!!!!!!!!");
#endif

#else

  ret_val = temp_array_avg( TEMP_SENSORS, pointer );

  if(ret_val > 85)
  {
    fans_on();
  }

  if(ret_val > 90)
  {
    if(baby_check())
    {
      sound_alarm();
    }
  }
#endif

}

void sound_alarm( void )
{
  ALARM_LIGHT(HIGH);
  ALARM_SIREN(1000);
  ALARM_LIGHT(LOW);
  delay(500);
}

