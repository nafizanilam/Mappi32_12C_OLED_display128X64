#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#define LED 5

int count = 0;
const int lebar = 128;
const int tinggi = 64;
const int reset = 4;
Adafruit_SSD1306 oled(lebar, tinggi, &Wire, reset);

void setup() { 
  // put your setup code here, to run once:
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  Serial.begin(115200);
  pinMode(5, OUTPUT);
  while (!Serial);
  Serial.println("Input 1 to Turn LED on and 2 to off");
}

void loop() {
  Serial.println("Nilai count = " + String(count));
  if (count == 0)
  {
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.setCursor(25, 3);
    oled.println("_ Hallo _");
    oled.setCursor(15, 25);
    oled.println("Selamat");
    oled.setCursor(15, 47);
    oled.println("_ Siang _");
    oled.display();
    delay (1000);
  }

  if (count == 1)
  {
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.setCursor(13, 3);
    oled.println("_ Jangan _");
    oled.setCursor(31   , 25);
    oled.println("Lupa");
    oled.setCursor(25, 47);
    oled.println("_ Makan _");
    oled.display();
    delay (1000);
  }

  digitalWrite (5, HIGH);
  delay (250);
  digitalWrite (5, LOW);
  delay (250);
  digitalWrite (5, HIGH);
  delay (250);
  digitalWrite (5, LOW);
  delay (250);
  digitalWrite (5, HIGH);
  delay (1000);
  digitalWrite (5, LOW);
  delay (250);

  delay(2000);
  count = !count;
  oled.clearDisplay();
}
