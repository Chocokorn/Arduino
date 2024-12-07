#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#define sw1 4
#define ledPin 3
int buttonPin = A0;//ปุ่มกด
int count = 0;
String sent[] = { "IoT", "ML", "Graphic" }; //วิชาที่สุ่มในจอ lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte customChar0[8] = { //รูปกล่อง
  B00000,
  B00000,
  B01010,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111
};
byte customChar1[8] = {  //ก
  B00000,
  B01110,
  B10001,
  B01001,
  B10001,
  B10001,
  B10001,
  B10001
};
byte customChar2[8] = {  //ล่
  B00001,
  B11111,
  B10001,
  B00001,
  B00001,
  B01101,
  B11011,
  B11001
};
byte customChar3[8] = {  //อ
  B00000,
  B11111,
  B10001,
  B00001,
  B11001,
  B11001,
  B10001,
  B11111
};
byte customChar4[8] = {  //ง
  B00000,
  B00111,
  B00111,
  B00001,
  B10001,
  B01001,
  B00101,
  B00011
};
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(sw1, INPUT);
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, customChar0); //ของรูปกล่องกับข้อความกล่อง
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4);

  lcd.setCursor(6, 0); //กล่อง
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  lcd.write((uint8_t)3);
  lcd.write((uint8_t)4);

  lcd.setCursor(7, 1); //รูปกล่อง
  lcd.write((uint8_t)0);



  pinMode(ledPin, OUTPUT); 
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (digitalRead(sw1)) {
    digitalWrite(ledPin, 1);
    delay(200) ;
    digitalWrite(ledPin,0) ; 
    lcd.clear();
    lcd.setCursor((16 - sent[random(0, 9)].length()) / 2, 0);//
    lcd.print(sent[random(0, 9)]);
    delay(1000) ;
    while (true ) {
      if (digitalRead(sw1)) {
        lcd.clear();
        setup();
        loop();
        break;
        
      }
    }
    
  }
}
void scrollTextDisplay() { //แสดงผลรูปกล่องกับข้อความกล่อง
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    delay(400);
  }
  lcd.clear();
}
