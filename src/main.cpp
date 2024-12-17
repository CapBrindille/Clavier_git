/*
  Code fait par mathis BENOIT
  Compileur : Microsoft Visual Studio Code v1.96.0
  IDE : PlateformIO v3.3.3

  Programme pour faire fonctionner un petit clavier en 4x4 en utilisant une carte Arduino Mega

  Câblage : 
*/
#include <Arduino.h>          //Librairie pour utiliser les commandes de l'IDE Arduino sur Visual Studio Code
#include <Keypad.h>           //Librairie pour utiliser le clavier 

#define COLS 4                //Le clavier aura 4 colognes 
#define ROWS 4                //Le clavier aura 4 lignes
char keys[ROWS][COLS] = {
  {'1','2','3','F'},
  {'4','5','6','E'},          //Disposition des touches du clavier
  {'7','8','9','D'},
  {'A','0','B','C'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};      //Broches de l'Arduino sur lesquelles les lignes du clavier seront connectées
byte colPins[COLS] = {9, 8, 7, 6};      //Broches de l'Arduino sur lesquelles les colognes du clavier seront connectées

Keypad clavier = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);      //On associe les broches des colognes comme étant pour les colognes, idem pour les lignes

char mdp[4] = {'6','4','2','0'};
 int i = 0;
int fail = 3;
char essai[4];
bool clr = false;

void setup() {
  Serial.begin(9600);                         //Initialisation du moniteur série
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  
}

void loop() {
 Serial.print("Veuillez rentrer votre mot de passe : ");
 for (int i = 0; i <= 3; i++){    //On demande le code à 4 chiffres
 char touche = clavier.getKey();
 while (touche == false){
  touche = clavier.getKey();
 }
 if (touche == 'C'){      //Création d'une touche "clear" qui réinitialise le mot de passe
  essai[4] = {};
  i = 0;
  fail = 3 ;
  
 }
 else {
 essai[i] == touche;
 Serial.print(touche);    //on affiche le code qui est rentré 
 }
}
 Serial.println();
 Serial.println("affichage des tuples");
 Serial.println(essai);
 //char essaimdp = essai;
 //Serial.println(essaimdp);
 Serial.println(mdp);
 if (essai == mdp) {
  digitalWrite(10, HIGH);
  Serial.print("... Mot de passe correct");
  fail = 3 ;
  delay(5000);
  digitalWrite(10, LOW);
 }
 else {
  Serial.print("... Mot de passe incorrect, ");
  fail = fail - 1 ;
  Serial.print(fail);  
  Serial.println(" essai(s) restant(s)");
  
  if (fail == 0) {
    digitalWrite(11, HIGH);
    Serial.println("Trop d'essais incorrects, blocage de la carte ");
    delay(5000);
    digitalWrite(11, LOW);
    fail = 3;
  }
 }
}
