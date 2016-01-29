#ifndef CarSeatCodeFunctions_h
#define CarSeatCodeFunctions_h

#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FAN_PIN       13
#define MOTION_PIN    12
#define WEIGHT_PIN    11
#define LIGHT_PIN     10
#define SIREN_PIN     9

#define MAX_VOLT_MILLIVOLT  5000
#define RESOLUTION          1024
#define VOLT_OFFSET         50
#define LIN_DIV             10
#define TEMP_OFFSET         32
#define CONVERSION_CONST    1.8
#define SIREN_FREQ          2000
#define ALARM_SIREN(duration)        tone(SIREN_PIN,SIREN_FREQ,duration)
#define ALARM_LIGHT(level)           digitalWrite(LIGHT_PIN, level)


#define TESTING      false
#define TEMP_TEST    false
#define FAN_TEST     false
#define BABY_TEST    false
#define ALARM_TEST   false


#ifdef __cplusplus
  extern "C"
  {
    float temp_array_avg( int array_size, float * temp_array);

    float retreive_f_temp( int pin );

    void fans_on( void );
    
    bool baby_check( void );
    
    bool motion_detected( void );
    
    bool weight_detected( void );
    
    void sound_alarm( void );
    
//    void alarm_light_on( void );
//    
//    void alarm_light_off( void );
//    
//    void alarm_siren( void );
  }

#endif

#endif /* CarSeatCodeFunctions_h */
