#include <Wire.h>     // I2C protocol
#include <VL53L0X.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1     // oleds have resets -> -1 = no resets
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// VL53L0X setup
VL53L0X sensor;     // object "sensor"

// Switch setup
const int switchPin = 2; // Connect switch between Pin 2 and GND

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Initialize Switch
  pinMode(switchPin, INPUT_PULLUP);

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {        // if not oled found at address "0x3C"
    Serial.println(F("SSD1306 allocation failed at 0x3C"));
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {      // if not oled found at address "0x3D"
      Serial.println(F("SSD1306 allocation failed at 0x3D"));
      while(1);       // infinite loop to hold off the program
    }
  }
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.println("Starting...");
  display.display();      // send to oled

  // Initialize VL53L0X
  sensor.init();
  sensor.setTimeout(500);     // expects answer within 500ms
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize VL53L0X!");
    display.clearDisplay();
    display.setTextSize(2);
    display.println("VL53L0X failed!");
    display.display();
    while(1);
  }
  sensor.startContinuous();   // continuous reading

  display.clearDisplay();
  display.setTextSize(2);
  display.println("Ready!");
  display.display();
  delay(1000);
}

void loop() {
  // Logic: If switch is ON (connected to GND), run the sensor
  if (digitalRead(switchPin) == LOW) {
    int distance = sensor.readRangeContinuousMillimeters();

    // Your original Serial logic
    Serial.print(distance);
    Serial.println(" mm");

    // Your original Display logic
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 10);     // cursor at x=0, y=10 pixels
    display.print("Dist: ");
    display.print(distance);
    display.print(" mm");
    display.display();
  } 
  else {
    // Optional: Clear display or show "OFF" when switch is flipped
    display.clearDisplay();
    display.setCursor(0, 10);
    display.println("PAUSED");
    display.display();
  }

  // Your original 5-second delay
  delay(5000); 
}