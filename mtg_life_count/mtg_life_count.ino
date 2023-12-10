#include <M5StickCPlus.h>

int lifeRed = 40;
int lifeBlue = 40;

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(3);
  drawLife();
}

void loop() {
  M5.update();
  
  if (M5.BUTTON_PWR.wasPressed()) {
    decreaseLifeRed();
    delay(100);
  }
  
  if (M5.BtnB.wasPressed()) {
    decreaseLifeBlue();
    delay(100);
  }
}

void drawLife() {
  M5.Lcd.fillScreen(BLACK);

  // Lado vermelho
  M5.Lcd.fillRect(0, 0, 240, 67, RED);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(110, 25);
  M5.Lcd.setTextSize(4);
  M5.Lcd.print(lifeRed);

  // Lado azul
  M5.Lcd.fillRect(0, 68, 240, 67, BLUE);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(110, 97);
  M5.Lcd.setTextSize(4);
  M5.Lcd.print(lifeBlue);
}

void decreaseLifeRed() {
  if (lifeRed > 0) {
    lifeRed--;
  }
  
  drawLife();
}

void decreaseLifeBlue() {
  if (lifeBlue > 0) {
    lifeBlue--;
  }

  drawLife();
}