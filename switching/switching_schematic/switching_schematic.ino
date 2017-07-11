int pin;
#define MAX_OUTPUTS 3
void setup()
{
  
  pin = 6; // We switch from D2 up to D7; where D7 corresponds with output 1, D6 with output 2, etc.
  for(int i = 7;i>=2;i--){
    pinMode(i, OUTPUT);
    }

}
//We want our pin to go low to enable an output pin
void loop()
{
  digitalWrite(PIN2, HIGH&!(pin==1));       // turn on pullup resistors
  digitalWrite(PIN3, HIGH&!(pin==2));       // turn on pullup resistors
  digitalWrite(PIN4, HIGH&!(pin==3));       // turn on pullup resistors
  digitalWrite(PIN5, HIGH&!(pin==4));       // turn on pullup resistors
  digitalWrite(PIN6, HIGH&!(pin==5));       // turn on pullup resistors
  digitalWrite(PIN7, HIGH&!(pin==6));       // turn on pullup resistors
  if(pin<6) {pin++;}
  else { pin=7-MAX_OUTPUTS;}
  delay(90000);

}

