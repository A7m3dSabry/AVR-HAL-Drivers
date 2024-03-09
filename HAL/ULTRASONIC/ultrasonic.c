

/*************************** Section: Includes *********************************/


#include "ultrasonic.h"


/*************************** Section: Global Variables Declarations ************/

static uint8_t edgeCount = 0; /* var to help process high time calculation (counter for the edges) */
static uint16_t highTime = 0; /* var to store level high time */

/*************************** Section: Local Variables Declarations *************/
/*************************** Section: Helper Methods Prototypes  ***************/
/*************************** Section: Methods Implementations ******************/


Std_ReturnType HAL_ULTRASONIC_init(void)
{
    /* Configuring TR pin */
    HAL_GPIO_setPinDirection(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, PIN_OUTPUT);
    /* Configuring TR Value */
    HAL_GPIO_setPinValue(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, STD_HIGH);
    /* Configuring EHO Value */
    HAL_GPIO_setPinDirection(ULTRASONIC_EHO_PORT_ID, ULTRASONIC_EHO_PIN_ID, PIN_INPUT);

    /* Configuring ICU Unit */
	ICU_ConfigType Config = {F_CPU_8,RISING};

    /* Register Interrupt Callback*/
    HAL_ICU_registerCallBack((void (*)(void)) HAL_ULTRASONIC_edgeProcessing);
    /* Init ICU Unit */
    HAL_ICU_init(&Config);
    return E_OK;
}


Std_ReturnType HAL_ULTRASONIC_Trigger(void)
{

    /* Waiting at leas 50ms between Triggers */
	_delay_ms(60);

	/* Trigger the ULTRASONIC device by Setting TR to High for more than 10us */
    HAL_GPIO_setPinValue(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, STD_HIGH);
    _delay_us(20);

    /* Sending High Voltage to TR pin */
    HAL_GPIO_setPinValue(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, STD_LOW);

    return E_OK;
}


Std_ReturnType HAL_ULTRASONIC_readDistance(uint16_t *value)
{

    Std_ReturnType ret = E_OK;
    if (value ==NULL){
        ret = E_NOT_OK;
    } else {

        /* Trigger the Sensor */
        HAL_ULTRASONIC_Trigger();

        /* Polling until HAL_ULTRASONIC_edgeProcessing function calculate the high time */
        while (edgeCount < 2) {}

        *value = (uint16_t) (highTime * 0.0173);
    }
	return ret;
}


Std_ReturnType HAL_ULTRASONIC_edgeProcessing(void)
{
	edgeCount++;
	if(edgeCount == 1)
	{
        HAL_ICU_clearTimerValue(); /* To start counting From zero */
        HAL_ICU_setEdgeDetectionType(FALLING); 	/* Detect falling edge */
	}
	else if(edgeCount == 2)
	{
        highTime = HAL_ICU_getCapturedValue(); /* ICR1 - 0 */
        HAL_ICU_setEdgeDetectionType(RISING); 	/* Detect Rising edge */
	}
	else
	{
        edgeCount = 0;
	}
    return E_OK;
}

/*************************** Section: Interrupt Methods Implementations ********/
/*************************** Section: Helper Methods Implementations  **********/