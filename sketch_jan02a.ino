#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
    #define S0 6
    #define S1 7
    #define S2 8
    #define S3 9
    #define sensorOut 10
    int frequency = 0;
    void setup() {
      pinMode(S0, OUTPUT);
      pinMode(S1, OUTPUT);
      pinMode(S2, OUTPUT);
      pinMode(S3, OUTPUT);
      pinMode(sensorOut, INPUT);
      
      // Frekans ölçekleme oranını% 20'ye ayarlama
      digitalWrite(S0,HIGH);
      digitalWrite(S1,LOW);
      lcd.begin(16,2);
    }
    void loop() {
    // Okunacak kırmızı filtrelenmiş fotodiyotların ayarlanması
      digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      lcd.setCursor(0,0);
      lcd.print("Kir=");//printing name
      lcd.print(frequency);//printing RED color frequency
      lcd.print(" ");
      delay(100);
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      lcd.setCursor(8,0);
      lcd.print("Kah=");//printing name
      lcd.print(frequency);//printing RED color frequency
      lcd.print("  ");
      delay(100);
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      lcd.setCursor(5,1);
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      lcd.print("Mavi=");//printing name
      lcd.print(frequency);//printing RED color frequency
      lcd.println("     ");
      delay(100);
    }
