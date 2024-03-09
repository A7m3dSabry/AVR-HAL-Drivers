
/*************************** Section: Includes *********************************/
#include "adc.h"

/*************************** Section: Local Variables Declarations *************/
/*************************** Section: Helper Methods Prototypes  ***************/
/*************************** Section: Methods Implementations ******************/

Std_ReturnType HAL_ADC_init(const ADC_Config_t *config) {
    Std_ReturnType ret = E_OK;

    if (config == NULL) {
        ret = E_NOT_OK;
    } else {
        /* Disabling ADC for safe modifying */
        ADCSRA = 0;
        ADMUX = 0;

        /* left shift the value by 6 so we can insert it in the right place at REFS0 and REFS1 */
        ADMUX |= ((config->ref_volt) << 6);

        /* same as the last step but this time ADPSX bits are the first 3 bits so no need to shift */
        ADCSRA |= (config->prescaler);

        /* Enable the ADC */
        SET_BIT(ADCSRA, ADEN);

    }
    return ret;
}

Std_ReturnType HAL_ADC_readChannel(uint8_t channel, uint16_t *value) {
    Std_ReturnType ret = E_OK;

    if (value == NULL) {
        ret = E_NOT_OK;
    } else {
        /* clear the previous channel and insert the new one in only 3 bits ( 8 channels ) " */
        ADMUX = (ADMUX & ADC_CHANNEL_CLEAR_MASK) | (channel & 0x07);

        /* start conversion */
        SET_BIT(ADCSRA, ADSC);

        /* wait the ADC o/p with polling method */
        while (BIT_IS_CLEAR(ADCSRA, ADIF)) {}

        /* clearing ADC flag */
        SET_BIT(ADCSRA, ADIF);

        *value = ADC;

    }
    return ret;
}

/*************************** Section: Interrupt Methods Implementations ********/
/*************************** Section: Helper Methods Implementations  **********/