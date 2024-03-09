
#ifndef ICU_H_
#define ICU_H_

/*************************** Section: Includes *********************************/


#include "../../LIB/std_types.h"
#include "../../MCAL/GPIO/gpio.h"
#include "avr/io.h"
#include "avr/interrupt.h"

/*************************** Section: Macro Definitions ************************/
/*************************** Section: Macro Functions **************************/
/*************************** Section: Data Types *******************************/


typedef enum {
    NO_CLOCK,
    F_CPU_CLOCK,
    F_CPU_8,
    F_CPU_64,
    F_CPU_256,
    F_CPU_1024
} ICU_Clock_t;

typedef enum {
    FALLING,
    RISING
} ICU_EdgeDetectionType_t;

typedef struct {
    ICU_Clock_t clock;
    ICU_EdgeDetectionType_t edge;
} ICU_ConfigType;

/*************************** Section: Methods Prototypes ***********************/

Std_ReturnType HAL_ICU_init(const ICU_ConfigType *config);

Std_ReturnType HAL_ICU_registerCallBack(void(*a_ptr)(void));

Std_ReturnType HAL_ICU_setEdgeDetectionType(const ICU_EdgeDetectionType_t a_edgeType);

Std_ReturnType HAL_ICU_getCapturedValue(uint16_t *value);

Std_ReturnType inline HAL_ICU_clearTimerValue(void);

Std_ReturnType HAL_ICU_DeInit(void);

#endif /* ICU_H_ */
