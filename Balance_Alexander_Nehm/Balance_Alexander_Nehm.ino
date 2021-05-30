//Aufgabe: Der Arduino soll in x-Richtung die Balance halten und das anzeigen (rot heißt vorne runter, gelb hinten runter, grün waagerecht).
//Autor: Alexander Nehm
//Datum: 04.12.2020 / 16.12.2020


#include <Arduino_LSM9DS1.h>

float x, y, z, Differenz = 0.05; // Über die Variable Differenz kann man einstellen um wie viel sich der X-Wert von der Nulllage unterscheiden darf. 
                                  // Dadurch, dass man der Variable hier direkt einen Wert zuweist, kann man wenn man die Empfindlichkeit ändern möchte einfach nur hier den Wert ändern und muss nicht die komplette Methode Messung umändern 
void setup() {
  pinMode(LEDR, OUTPUT);              //
  pinMode(LEDB, OUTPUT);             // definiere die LEDs als Ausgänge
  pinMode(LEDG, OUTPUT);            //

  Serial.begin(9600);
    if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!"); // Übernommen aus dem Beispielprogramm des Accelerometers. Checkt quasi nur ob der Sensor korrekt funktioniert.
    while (1);
                      }
 
            
   
            }
void loop() {
     
    Messung();
  
            }      

void Messung(){

 
  if (IMU.accelerationAvailable())
  
    IMU.readAcceleration(x, y, z );    // Abfrage des Wertes x nun in der Methode Messung 

      if( x >= -Differenz && x <= Differenz)
        gruenAn();  // wenn Board gerade, leuchte grün
        else
            if( x < Differenz )
              rotAn();   //ansonsten leuchte rot = Board nach vorne geneigt
               else 
                   if ( x > Differenz)
                     gelbAn();   // ansonsten leuchte gelb = Board nach hinten geneigt     
        
  
              }
    


// Farben der LED : 

void rotAn() {
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);  
             }

void gelbAn() {
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, HIGH);  
              }

void gruenAn() {
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, HIGH);  
                }


                
