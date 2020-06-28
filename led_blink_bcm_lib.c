#include <bcm2835.h>
#include <stdio.h>

#define PIN 25

int main(int argc, char **argv)
{
    if (!bcm2835_init())
	    return 1;
    printf("setting gpio pin %d\n",PIN);
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
    
    
        bcm2835_gpio_write(PIN,LOW);
       // printf("LED ON\n");
	//bcm2835_delay(200);
	sleep(10);
        
	bcm2835_gpio_write(PIN,HIGH);
//	printf("LED OFF\n");
//        bcm2835_delay(200);
  
    
   // bcm2835_close();
   // return 0;
}
