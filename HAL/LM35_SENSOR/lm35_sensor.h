

#ifndef HAL_LM35_SENSOR_LM35_SENSOR_H_
#define HAL_LM35_SENSOR_LM35_SENSOR_H_

/*************************** Section: Includes *********************************/
#include "../../LIB/std_types.h"
#include "../../MCAL/ADC/adc.h"

/*************************** Section: Macro Definitions ************************/

#define LM35_MAX_VOLT_VALUE		1.5
#define LM35_MAX_TEMPERATURE	150
#define	LM35_CHANNEL_ID			2


/*************************** Section: Macro Functions **************************/
/*************************** Section: Data Types *******************************/
/*************************** Section: Methods Prototypes ***********************/

Std_ReturnType HAL_LM35_getTemperature(uint8_t *value);

#endif /* HAL_LM35_SENSOR_LM35_SENSOR_H_ */
