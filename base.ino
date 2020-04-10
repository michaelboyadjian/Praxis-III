#define RPWM 3   // Define pin 3 for RPWM pin (output)
#define R_EN 4   // Define pin 4 for R_EN pin (input)
#define R_IS 5   // Define pin 5 for R_IS pin (output)
#define LPWM 6   // Define pin 6 for LPWM pin (output)
#define L_EN 7   // Define pin 7 for L_EN pin (input)
#define L_IS 8   // Define pin 8 for L_IS pin (output)
#define CW 1     // Do not change
#define CCW 0    // Do not change
#define debug 1  // Change to 0 to hide serial monitor debugging information or set to 1 to view

#include <RobojaxBTS7960.h>
RobojaxBTS7960 motor(R_EN, RPWM, R_IS, L_EN, LPWM, L_IS, debug);

void setup() {
   Serial.begin(9600);          // Setup Serial monitor to display information
   motor.begin();
}

void loop() {  
   if (Serial.available()) {
      char val = Serial.read();
      Serial.println(val);
      
      if (val == 'f') {
          motor.rotate(75, CCW);        // Run motor with 100% speed in CW direction
          char val2 = Serial.read();
          if (val2 != 'f') {
              loop();
          }
          
      } else if (val == 'b') {
         motor.rotate(75, CW);          // Run motor at 100% speed in CCW direction
         delay(500);                    // Run for 1 seconds
         char val2 = Serial.read();
         if (val2 != 'b') {
              loop();
         }
         
      } else if (val == 's') {
         motor.stop();                  // Stop the motor
      }
   }
}
