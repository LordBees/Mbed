#include "mbed.h"
#include "TextLCD.h"

int tries = 3;// no of tries
int triggered = 0;// has alarm been triggered
int armed = 0;// has the alarm been armed
int armdelay = 5;// arm delay in seconds
int tens = 0;
int units = 0;
int tens_PWD = 1;
int units_PWD = 2;


DigitalIn tens_pin(p5);//tens pin
DigitalIn units_pin(p6);//units pin
DigitalIn rst_pin(p7);//reset pin
DigitalIn cnf_pin(p8);//confirm pin(try the code)
TextLCD lcd(p15,p16,p17,p18,p19,p20);//lcd pins
//int lcdprint(void){
//    lcd.printf
//    }
int Crystal_put(char* line1,char* line2){//prints to display
    lcd.cls();
    lcd.printf(line1);
    lcd.printf(line2);
    return 0;
    }


int main(){// mainloop
    while(1){
        lcd.cls();
        if (tries <0){// if no more attempts left on the lock  stops additional atempts 
            triggered = 1;
            Crystal_put("LOCKED OUT","________________");
            }
        else{
            if (tens_pin){//if  tens increment pressed
                if (tens == 10){
                    tens = 0;
                    }
                else{
                    tens++;//increment tens
                    }
                }
                
            if (units_pin){//if  units increment pressed
                if (units == 10){
                    units = 0;
                    }
                else{
                    units++;
                    }
                }
                
            if (rst_pin){//if  reset button pressed
                tens = 0;
                units = 0;
                }
                
            if (cnf_pin){//if  try input button pressed
                tries --;//sub 1 try
                if (tens_PWD == tens){
                if (units_PWD == units){// if pass number is valid for both tens and units
                    armed = 0;
                    //other unlock code
                    
                    //END
                    }
                    }
                }
            
            }
        lcd.printf("test!!!");
        //lcd update code
        
        //end
        }
    }

//DigitalOut myled(LED1);

//int main() {
//    while(1) {
//        myled = 1;
//        wait(0.2);
//        myled = 0;
//        wait(0.2);
//    }
//}
