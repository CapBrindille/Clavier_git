
#include <Arduino.h>
#include <Keypad.h>

#define COLS 4
#define ROWS 4
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};
Keypad clavier = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = clavier.getKey();
  if(key) {
    if (key == '4') {
      Serial.println("La touche 4 est pressée --> allumage de la led verte");
    }
    else {
      Serial.print("La touche ");
      Serial.print(key);
      Serial.println(" est pressée");
    }
  }

}
