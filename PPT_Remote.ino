#include <BleKeyboard.h>

BleKeyboard bleKeyboard("PPTRemote", "ESP32", 100);

// Pin definitions
const int nextSlideButton = 15;  // D2 - Page down
const int prevSlideButton = 4;  // D4 - Page up
const int startSlideButton = 18; // D18 - F5
const int endSlideButton = 19;   // D19 - Esc
const int ledPin = 23;           // D23 - Indicator LED

// Variables to store button states
int lastNextSlideButtonState = HIGH;
int lastPrevSlideButtonState = HIGH;
int lastStartSlideButtonState = HIGH;
int lastEndSlideButtonState = HIGH;

// Variables to store LED Delay
int ledDelay = 100;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE Keyboard...");

  // Initialize BLE Keyboard
  bleKeyboard.begin();

  // Set up buttons as input with pull-up resistors
  pinMode(nextSlideButton, INPUT_PULLUP);
  pinMode(prevSlideButton, INPUT_PULLUP);
  pinMode(startSlideButton, INPUT_PULLUP);
  pinMode(endSlideButton, INPUT_PULLUP);

  // Set up LED as output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // LED off initially

  Serial.println("Setup complete. Waiting for button presses...");
}

void loop() {
  if (bleKeyboard.isConnected()) {
    // Read button states
    int nextSlideButtonState = digitalRead(nextSlideButton);
    int prevSlideButtonState = digitalRead(prevSlideButton);
    int startSlideButtonState = digitalRead(startSlideButton);
    int endSlideButtonState = digitalRead(endSlideButton);

    // Check if any button is pressed and released (to avoid continuous presses)
    if (nextSlideButtonState == LOW && lastNextSlideButtonState == HIGH) {
      Serial.println("Next Slide button pressed.");
      digitalWrite(ledPin, HIGH);  // Turn on LED
      bleKeyboard.write(KEY_PAGE_DOWN); // Send Page Down key
      delay(ledDelay); // Debounce delay
      digitalWrite(ledPin, LOW);   // Turn off LED
      // Serial.println("Next Slide action completed.");
    }

    if (prevSlideButtonState == LOW && lastPrevSlideButtonState == HIGH) {
      Serial.println("Previous Slide button pressed.");
      digitalWrite(ledPin, HIGH);  // Turn on LED
      bleKeyboard.write(KEY_PAGE_UP); // Send Page Up key
      delay(ledDelay); // Debounce delay
      digitalWrite(ledPin, LOW);   // Turn off LED
      // Serial.println("Previous Slide action completed.");
    }

    if (startSlideButtonState == LOW && lastStartSlideButtonState == HIGH) {
      Serial.println("Start Slide Show button pressed.");
      digitalWrite(ledPin, HIGH);  // Turn on LED
      bleKeyboard.write(KEY_F5); // Send F5 key (Start Slide Show)
      delay(ledDelay); // Debounce delay
      digitalWrite(ledPin, LOW);   // Turn off LED
      // Serial.println("Start Slide Show action completed.");
    }

    if (endSlideButtonState == LOW && lastEndSlideButtonState == HIGH) {
      Serial.println("End Slide Show button pressed.");
      digitalWrite(ledPin, HIGH);  // Turn on LED
      bleKeyboard.write(KEY_ESC); // Send Esc key (End Slide Show)
      delay(ledDelay); // Debounce delay
      digitalWrite(ledPin, LOW);   // Turn off LED
      // Serial.println("End Slide Show action completed.");
    }

    // Update last button states
    lastNextSlideButtonState = nextSlideButtonState;
    lastPrevSlideButtonState = prevSlideButtonState;
    lastStartSlideButtonState = startSlideButtonState;
    lastEndSlideButtonState = endSlideButtonState;

  } else {
    Serial.println("PPT Remote is not connected. Waiting for connection...");
  }

  delay(10);  // Small delay to avoid unnecessary CPU usage
}
