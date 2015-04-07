#ifndef LCDnokia5110_h
#define LCDnokia5110_h

#include "Arduino.h"

class LCDnokia5110
{
  public:
    LCDnokia5110(int, int, int, int, int);
    void LcdClear();
    void LcdInitialise();
    void LcdWrite(byte, byte);
    void LcdString(char*);
    void LcdCharacter(char character);
    void GotoXY(int, int);
    void ShowLogo(int);
    void ShowImage(const unsigned char[], int);
    
    int CharSpace; 
    		
  private:
    
};

#endif