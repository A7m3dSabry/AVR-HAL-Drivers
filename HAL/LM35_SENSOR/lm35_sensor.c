

/*************************** Section: Includes *********************************/

#include "lm35_sensor.h"


/*************************** Section: Local Variables Declarations *************/
/*************************** Section: Helper Methods Prototypes  ***************/
/*************************** Section: Methods Implementations ******************/

Std_ReturnType HAL_LM35_getTemperature(uint8_t *value) {
    Std_ReturnType ret = E_OK;

    if (value == NULL) {
        ret = E_NOT_OK;
    } else {

        uint16_t adc_value;

        HAL_ADC_readChannel(LM35_CHANNEL_ID, &adc_value);

        *value = (uint8_t) (((uint32_t) LM35_MAX_TEMPERATURE * ADC_REF_VOLT_VALUE * adc_value) /
                            (ADC_MAXIMUM_VALUE * LM35_MAX_VOLT_VALUE));

    }
    return ret;
}


/*************************** Section: Interrupt Methods Implementations ********/
/*************************** Section: Helper Methods Implementations  **********/