

/*************************** Section: Includes *********************************/

#include "icu.h"

/*************************** Section: Global Variables Declarations ************/

static volatile void (*g_callBackPtr)(void) = NULL;

/*************************** Section: Local Variables Declarations *************/
/*************************** Section: Helper Methods Prototypes  ***************/
/*************************** Section: Methods Implementations ******************/



Std_ReturnType HAL_ICU_init(const ICU_ConfigType *config) {
    Std_ReturnType ret = E_OK;
    if (config == NULL) {
        ret = E_NOT_OK;
    } else {
        HAL_GPIO_setPinDirection(PORTD_ID, PIN_6, PIN_INPUT);

        TCCR1A = (1 << FOC1A) | (1 << FOC1B);
        TCCR1B = (TCCR1B & 0xF8) | (config->clock);
        TCCR1B = (TCCR1B & 0xBF) | ((config->edge) << 6);
        TCNT1 = 0;
        ICR1 = 0;
        SET_BIT(TIMSK, TICIE1);
    }
    return ret;
}


Std_ReturnType HAL_ICU_registerCallBack(void(*a_ptr)(void)) {
    g_callBackPtr = (volatile void (*)(void)) a_ptr;
}

Std_ReturnType HAL_ICU_setEdgeDetectionType(const ICU_EdgeDetectionType_t a_edgeType) {
    TCCR1B = (TCCR1B & 0xBF) | ((a_edgeType) << 6);
    return E_OK;
}

Std_ReturnType ICU_getInputCaptureValue(uint16_t *value) {
    Std_ReturnType ret = E_OK;
    if (value == NULL){
        ret = E_NOT_OK;
    } else {
        *value =  ICR1;
    }
    return ret;
}

Std_ReturnType HAL_ICU_clearTimerValue(void) {
    TCNT1 = 0;
    ret = E_OK;
}

Std_ReturnType HAL_ICU_DeInit(void) {
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;
    ICR1 = 0;

    CLEAR_BIT(TIMSK, TICIE1);
    return E_OK;
}

/*************************** Section: Interrupt Methods Implementations ********/




ISR(TIMER1_CAPT_vect){
        if (g_callBackPtr != NULL)
        {

            (*g_callBackPtr)();
        }
}

/*************************** Section: Helper Methods Implementations  **********/
