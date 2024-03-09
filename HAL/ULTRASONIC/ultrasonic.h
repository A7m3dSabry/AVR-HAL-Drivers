
#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_
/*************************** Section: Includes *********************************/

#include "../../LIB/std_types.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/ICU/icu.h"
#include "../../MCAL/GPIO/gpio.h"
#include "util/delay.h"

/*************************** Section: Macro Definitions ************************/

#define ULTRASONIC_TRIGGER_PORT_ID			PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID			PIN_5

#define ULTRASONIC_EHO_PORT_ID			PORTD_ID
#define ULTRASONIC_EHO_PIN_ID			PIN_6


/*************************** Section: Macro Functions **************************/
/*************************** Section: Data Types *******************************/
/*************************** Section: Methods Prototypes ***********************/

Std_ReturnType HAL_ULTRASONIC_init(void);


Std_ReturnType HAL_ULTRASONIC_Trigger(void);


Std_ReturnType HAL_ULTRASONIC_readDistance(uint16_t *value);



Std_ReturnType HAL_ULTRASONIC_edgeProcessing(void);

#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
