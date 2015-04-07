
const int PIN_RELAY_1 = 4;
const int PIN_RELAY_2 = 5;
const int PIN_RELAY_3 = 6;
const int PIN_RELAY_4 = 7;
const int RELAY_COUNT = 4;
const int PIN_RELAYS[] = {PIN_RELAY_1, PIN_RELAY_2, PIN_RELAY_3, PIN_RELAY_4};
boolean relayState[] = {false, false, false, false};


#include <Nokia5110.h>

// LCDnokia5110::LCDnokia5110(int rst, int ce, int dc, int in, int clk)
LCDnokia5110 lcd(9, 8, 10, 11, 12);


void setup() {
  Serial.begin(9600);
  pinMode(PIN_RELAY_1, OUTPUT);
  pinMode(PIN_RELAY_2, OUTPUT);
  pinMode(PIN_RELAY_3, OUTPUT);
  pinMode(PIN_RELAY_4, OUTPUT);

  relayOff();

  initLCD();
}

void initLCD() {
  lcd.LcdInitialise();
  lcd.LcdClear();
  lcd.GotoXY(0, 0);

  lcd.LcdString("Relay");

  lcd.GotoXY(0, 1);
  lcd.LcdString("1 2 3 4");

}

void lcdRelay() {
  for (int i = 0; i < RELAY_COUNT; i++)  {
    lcd.GotoXY(i * 12, 2);
    Serial.print(" relayState ");
    Serial.print(i);
    Serial.println(relayState[i]);
    if (relayState[i] == true) {
      lcd.LcdString("*");
    } else
      lcd.LcdString("-");
  }
}

void loop() {


  for (int i = 0; i < RELAY_COUNT; i++)  {


    relayOff();//spis vypnout predchozi, problikava
    relayOn(i);
    lcdRelay();
    delay(1000);
  }

}

void relayOn(int index) {
  debug("Relay on: ", index);
  relayState[index] = true;
  digitalWrite(PIN_RELAYS[index], LOW);
}

void relayOff(int index) {
  debug("Relay off: ", index);
  relayState[index] = false;
  digitalWrite(PIN_RELAYS[index], HIGH);
}

void relayOff() {
  for (int i = 0; i < RELAY_COUNT; i++)  {
    relayOff(i);
  }
}
void relayOn() {
  for (int i = 0; i < RELAY_COUNT; i++)  {
    relayOn(i);
  }
}

/* LOGGER */
void debug(String msg, int arg) {// FIXME: nic hezkeho - sehnat knihovnu
  Serial.print(millis());
  Serial.print(": ");
  Serial.print(msg);
  Serial.print(" * ");
  Serial.println(arg);
}
