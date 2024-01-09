#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Colocando os pinos pro LCD

int cm = 0; // Determinando todas as váriaveis que vão ser utilizadas
const int buttonPin = 9; // também colocando que o pin do botão ta no 9
float d1;
float d2;
float p = 0;
float f = 0;
int area = d1*d2;

long readUltrasonicDistance(int triggerPin, int echoPin) { //Sendo honesto? Copiei da aula de Sensor ultrasonico
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() //Dando setup nas propriedades que vamos utilizar
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(buttonPin, INPUT);
}

void loop() {
  area = d1 * d2; //Definindo área antes dos "if" porque senão da erro
  if (f == 0) { //Se o "f" for 0 ele vai dar loop nessa propriedade aqui
    cm = 0.01723 * readUltrasonicDistance(6, 7);
    Serial.print(cm);
    Serial.println("cm");
    delay(500);
    lcd.clear();
    lcd.print ("Dist: ");
    lcd.print (cm);
    lcd.print (" cm");
    delay(500);
  }
  if (digitalRead(buttonPin)){ //Se você aperta o botão isso aqui acontece
    if (p == 0) { // Se o P for 0, ele vai executar esse código aqui
    d1 = cm; // Salva o valor de d1 como o valor do sensor ultrasonico
    p = p+1; // Beleza agora o P é igual a 1
    lcd.clear();
    lcd.print("Valor atribuido");
    delay(1000);
    }
    else if (p == 1) { // Agora sim, já que você já apertou o botão 1x (fez com que o P fosse 1) ele vai executar esse código
    d2 = cm; // Definiu o d2 como o outro valor do sensor ultrasonico
    f = f+1; // Opa, agora o f (da linha 33) vai ser igual a 1
    lcd.clear();
    lcd.print("2o Valor");
    lcd.setCursor(0,1); // Linha de baixo pra ficar bonitinho pra quem ver
    lcd.print("Atribuido");
    delay(1000);
   }
  }
  else if (f == 1) { // Então agora que o F é 1 ele vai dar loop nesse código aqui, ao invés do código da linha 33
     lcd.clear();
     lcd.print ("Area: ");
     lcd.print(area); // Ele coloca no LCD a área definida da linha 32
     lcd.print (" cm2");
    delay(2000);
  }
}