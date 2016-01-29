#include "CarSeatCodeFunctions.h"

float retreive_f_temp( int pin )
{
  float analog_raw = 0;
  float analog_mV = 0;
  float cent_temp = 0;
  float f_temp = 0;
  analog_raw = analogRead(pin);
  analog_mV = analog_raw*(MAX_VOLT_MILLIVOLT/RESOLUTION);
  cent_temp = (analog_mV-VOLT_OFFSET)/LIN_DIV;
  f_temp = (cent_temp*CONVERSION_CONST) + TEMP_OFFSET;
  
  return( f_temp );
}

float temp_array_avg( int array_size, float * temp_array )
{
    float   total_temp = 0;
    float   avg_temp = 0;
    int counter;
    
    for (counter = 0; counter < array_size; counter++)
    {
        *temp_array  = retreive_f_temp(counter);
        total_temp += *temp_array;
        temp_array++;
    }

    avg_temp = total_temp/array_size;
    
    return avg_temp;
}

void fans_on( void )
{
  digitalWrite(FAN_PIN, HIGH); 
}

bool motion_detected( void )
{
  return(digitalRead(MOTION_PIN));
}

    
bool weight_detected( void )
{
  return(digitalRead(WEIGHT_PIN));
}


bool baby_check( void )
{
  if( motion_detected() || weight_detected() )
  {
      return true;
  }    
  return false;
}

//void alarm_light_on( void )
//{
//  digitalWrite(LIGHT_PIN,HIGH); 
//}
//
//void alarm_light_off( void )
//{
//  digitalWrite(LIGHT_PIN,LOW);
//}






