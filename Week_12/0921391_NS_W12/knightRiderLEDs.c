#include <wiringPi.h>
#include <stdio.h>

int main(void) {
    
    // LED Pin configurations
    int LedPins[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    //when initialize wiringPi failed, print message to screen
    if(wiringPiSetup() == -1) {
            printf("setup wiringPi failed !\n");
            return -1;
    }

    //set pin mode for all the LEDs
    
    for(int i = 0; i < 10; i++)
    	pinMode(LedPins[i], OUTPUT);
    
    //code for knight rider LED effect
    //assume at one time only one LED is turned on
    while(1) {
	    //light each light then turn it off after .1 secin assending order 
	    for (int j = 0; j < 10; j++)
	    {	digitalWrite(i, HIGH);   //led on
            	delay(50);		 // wait 0.05 sec
            	digitalWrite(i, LOW);    //led off
            	delay(50);              // wait 0.05 sec
	    }

	    //light each light in decending order
	    for (int j = 9; j < 0; j--)
	    {	digitalWrite(i, HIGH);   //led on
            	delay(50);		 // wait 0.05 sec
            	digitalWrite(i, LOW);    //led off
            	delay(50);              // wait 0.05 sec
	    }	
    }
    
    return 0;
}
