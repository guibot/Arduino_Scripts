#include <Chrono.h>
Chrono longpress_metro;

// constants won't change. They're used here to set pin numbers:
const int BUTTON_PIN = 3; // the number of the pushbutton pin
const int LONG_PRESS_TIME  = 2000; // 1000 milliseconds

// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin
unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;

void setup() {
  Serial.begin(57600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

long pressDuration;
bool active_state = true;


void loop() {
  //longPress();

  if (active_state == true)
  {
    longPress();
  }
  else
  {
    if (longpress_metro.hasPassed(5000))
    {
      Serial.println("active_state = true");
      active_state = true;
      //longpress_metro.restart();
    }
  }

}

void longPress()
{
  if (active_state == true)
  {
    // read the state of the switch/button:
    currentState = digitalRead(BUTTON_PIN);

    if (lastState == HIGH && currentState == LOW) {      // button is pressed

      pressedTime = millis();

      Serial.print("pressed time:");
      Serial.println(pressedTime);

    }
    else if (lastState == LOW && currentState == HIGH) { // button is released

      releasedTime = millis();

      Serial.print("released time:");
      Serial.println(releasedTime);

    }

     if (currentState == 0)
    {
      pressDuration = millis() - pressedTime;

      Serial.print("pressDuration:");
      Serial.println(pressDuration);

      if (pressDuration > 2000)
      {
        Serial.println("active_state = false");
        active_state = false;
        longpress_metro.restart();
      }

    }

    // save the the last state
    lastState = currentState;
  }
}
