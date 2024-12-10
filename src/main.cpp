
#include <Arduino.h>          //Librairie pour utiliser les commandes de l'IDE Arduino sur Visual Studio Code
#include <Keypad.h>           //Librairie pour utiliser le clavier 

#define COLS 4                //Le clavier aura 4 colognes 
#define ROWS 4                //Le clavier aura 4 lignes
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},          //Disposition des touches du clavier
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};      //Broches de l'Arduino sur lesquelles les lignes du clavier seront connectées
byte colPins[COLS] = {9, 8, 7, 6};      //Broches de l'Arduino sur lesquelles les colognes du clavier seront connectées

Keypad clavier = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);      //On associe les broches des colognes comme étant pour les colognes, idem pour les lignes

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = clavier.getKey();                //On check si une touche a été pressé 
  if(key) {                                   //Si une touche a bien été touché 
    if (key == '4') {                         //On vérifie si la touche en question est le 4
      Serial.println("La touche 4 est pressée --> allumage de la led verte");       //On affiche qu'on a bien pressé la touche 4
    }
    else {                                    //Si ce n'est pas la touche 4, on affiche quelle touche a été touché 
      Serial.print("La touche ");
      Serial.print(key);
      Serial.println(" est pressée");
    }
  }

}
