

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

/*************************** Section: Includes *********************************/

#include "../../LIB/std_types.h"
#include "avr/io.h"


/*************************** Section: Macro Definitions ************************/
#define ADC_CHANNEL_CLEAR_MASK    0xE0 /* Mask used to clear the channel before inserting new one */
#define ADC_MAXIMUM_VALUE        1023 /* 10 bits ADC = 2^10-1 = 1023 */
#define ADC_REF_VOLT_VALUE        2.56

/*************************** Section: Macro Functions **************************/
/*************************** Section: Data Types *******************************/
typedef enum {
    ADC_F_CPU_2 = 1,
    ADC_F_CPU_4,
    ADC_F_CPU_8,
    ADC_F_CPU_16,
    ADC_F_CPU_32,
    ADC_F_CPU_64,
    ADC_F_CPU_128
} ADC_Prescaler_t;

typedef enum {
    ADC_AREF,
    ADC_AVCC,
    ADC_INTERNAL_VREF = 3
} ADC_RefVoltage_t;

typedef struct {

    ADC_RefVoltage_t ref_volt;
    ADC_Prescaler_t prescaler;

} ADC_Config_t;


/*************************** Section: Methods Prototypes ***********************/
Std_ReturnType HAL_ADC_init(const ADC_Config_t *config);


Std_ReturnType HAL_ADC_readChannel(uint8_t channel, uint16_t *value);

#endif /* ADC_ADC_H_ */
