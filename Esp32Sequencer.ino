
 #include <Wire.h>
 #include "SSD1306.h"
 #include "OLEDDisplayUi.h"

#define D0 15
#define D1 14
#define D2 12
#define D3 13


SSD1306  display(0x3c, 5, 4);
/*
const int seq[] = { 1, 2, 3, 0, 0,
                    5, 3, 6, 5, 2,
                    6, 7, 6, 5, 2, 
                    0, 0, 4, 3, 5, 
                    0, 4, 0, 3, 1, 
                    0, 0, 4, 0, 5, 
                    1, 4, 7, 3, 2, 
                    0, 0, 4, 3, 5, 
                    5, 5, 5, 5, 5, 
                    0, 0, 4, 0, 5, 
                    0, 4, 7, 3, 2};
*/
/*
const int seq[] = { 0, 0, 0, 0, 0,
                    5, 3, 6, 5, 2,
                    0, 0, 0, 0, 0,
                    5, 3, 6, 5, 2,
                    0, 0, 0, 0, 0,
                    5, 3, 6, 5, 2,
                    0, 0, 0, 0, 0,
                    5, 3, 6, 5, 2,
                    5, 5, 5, 5, 5,
                    5, 3, 6, 5, 2,
                    5, 5, 5, 5, 5
                    };
                    */

const int seq[] = { 5, 5, 5, 5, 5,
                    5, 5, 5, 5, 5,
                    5, 5, 5, 5, 5,
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0,
                    5, 5, 5, 5, 5,
                    5, 5, 5, 5, 5,
                    5, 5, 5, 5, 5,
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0,
                    5, 5, 5, 5, 5,
                    5, 5, 5, 5, 5,
                    5, 5, 5, 5, 5,
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0
                    };



void setup() {

  Serial.begin(115200);
  
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);

  display.init();

  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
}


void loop() {
  for(int i = 0; i < 55; i++){
      //
      display.clear();
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 10, "i= ");
      display.drawString(15, 10, String(i));

      display.drawString(50, 10, "seq= ");
      display.drawString(90, 10, String(seq[i]));

      if((seq[i] >> 0) & 1)
        display.drawString(30, 20, "1");
      else
        display.drawString(30, 20, "0");

      if((seq[i] >> 1) & 1)
        display.drawString(50, 20, "1");
      else
        display.drawString(50, 20, "0");

      if((seq[i] >> 2) & 1)
        display.drawString(70, 20, "1");
      else
        display.drawString(70, 20, "0");
      
      
      digitalWrite(D1, (seq[i] >> 0) & 1);
      digitalWrite(D2, (seq[i] >> 1) & 1); 
      digitalWrite(D3, (seq[i] >> 2) & 1); 

      if((i >= 5) && (i <= 10)) {
        digitalWrite(D0, 1);
        display.drawString(0, 36, "MOJ SIGNAL");
      }
      else {
        digitalWrite(D0, 0);
      }
      display.display();
      delay(250);
  }
}
