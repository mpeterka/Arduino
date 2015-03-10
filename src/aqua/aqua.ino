
const int PIN_RELAY_1 = 8;
const int PIN_RELAY_2 = 9;
const int PIN_RELAY_3 = 10;
const int PIN_RELAY_4 = 11;
const int RELAY_COUNT = 4;
const int PIN_RELAYS[] = {PIN_RELAY_1, PIN_RELAY_2, PIN_RELAY_3, PIN_RELAY_4};

void setup() {
  Serial.begin(9600);
  pinMode(PIN_RELAY_1, OUTPUT);
  pinMode(PIN_RELAY_2, OUTPUT);
  pinMode(PIN_RELAY_3, OUTPUT);
  pinMode(PIN_RELAY_4, OUTPUT);

  relayOff();
}

void loop() {

  for (int i = 0; i < RELAY_COUNT; i++)  {
    relayOff();//spis vypnout predchozi, problikava
    relayOn(i);
    delay(1000);
  }

}

void relayOn(int index) {
  debug("Relay on: ", index);
  digitalWrite(PIN_RELAYS[index], LOW);
}

void relayOff(int index) {
  debug("Relay off: ", index);
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
