long distancia;
long tiempo;

long distancia1;
long tiempo1;

const int ledI =5;
const int ledD =6;

void setup(){
  //Serial.begin(9600);
  pinMode(10, OUTPUT); /*Declara el Pin 11 como salida para el Trigg*/
  pinMode(8, INPUT); /*Declara el Pin1 12 como entrada para el Echo*/
  pinMode(ledI, OUTPUT);

  
  pinMode(11, OUTPUT); /*Declara el Pin 11 como salida para el Trigg*/
  pinMode(7, INPUT); /*Declara el Pin1 12 como entrada para el Echo*/
  pinMode(ledD, OUTPUT);

}

void loop(){
  digitalWrite(10,LOW); 
  delayMicroseconds(5);
  digitalWrite(10, HIGH); /*Envia pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(8, HIGH); /* Mide el tiempo que tarda en regresar una onda ultrasónico de Echo a Trigg*/
  distancia= int(0.017*tiempo); /*Calcula la distancia (en cm) con la formula Distancia = Velocidad * Tiempo */
  //Serial.print("Distancia ");
  //Serial.print(distancia);
  //Serial.println(" cm");
  delay(10);
  //analogWrite(ledI, distancia);

 if (distancia>50){
  analogWrite(ledI, 255);
 }
else
{
   analogWrite(ledI, 125);
  }
if (distancia<10){
  analogWrite(ledI, 0);
 }
 
  digitalWrite(11,LOW); 
  delayMicroseconds(5);
  digitalWrite(11, HIGH); /*Envia pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo1=pulseIn(7, HIGH); /* Mide el tiempo que tarda en regresar una onda ultrasónico de Echo a Trigg*/
  distancia1= int(0.017*tiempo1); /*Calcula la distancia (en cm) con la formula Distancia = Velocidad * Tiempo */

 
 if (distancia1>50){
  analogWrite(ledD, 255);
 }
else
{
   analogWrite(ledD, 125);
}
if (distancia1<10){
  analogWrite(ledD, 0);
 }
}
