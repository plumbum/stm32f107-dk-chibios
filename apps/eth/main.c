#include <ch.h>
#include <hal.h>

/*
 * Application entry point.
 */
int main(void)
{

    /* Enable RMII, remap RX pins to PD8 .. PD10 */
    AFIO->MAPR   |= 0x00A00000;

    /*
     * System initializations.
     * - HAL initialization, this also initializes the configured device drivers
     *   and performs the board-specific initializations.
     * - Kernel initialization, the main() function becomes a thread and the
     *   RTOS is active.
     */
    halInit();
    chSysInit();

    /*
     * Activates the EXT driver 1.
     */
    /*  macStart(&ETHD1, NULL);*/

    /*
     * Normal main() thread activity, in this demo it enables and disables the
     * button EXT channel using 5 seconds intervals.
     */
    int leds = 0;
    while (TRUE)
    {
        GPIOE->BSRR = (~leds<<8) & 0xFF00;
        GPIOE->BRR = (leds<<8) & 0xFF00;
        leds = (leds+1) & 0xFF;
        chThdSleepMilliseconds(100);
    }
}
