// Internetdelascosas.cl
// Script para leer temperatura utilizando un LM35

// Declaracion de variables
float tempC;
float BPM;
int tempPin = 1; // Definimos la entrada en pin A1
int bpmPin = 0;

void setup()
{
    // Abre puerto serial y lo configura a 9600 bps
    Serial.begin(9600);
     pinMode(13, OUTPUT);
}
void loop()
{
    // Lee el valor desde el sensor
    tempC = analogRead(tempPin);
    BPM= analogRead(bpmPin);
   
    // Convierte el valor a temperatura
    tempC = (5.0 * tempC * 100.0)/1024.0; 
    
    if(BPM>60 || BPM<40 || tempC<20 || tempC>39)
   {
    Serial.print("BPM = \n");
    Serial.println(BPM);
    Serial.print(" Temperatura = \n " );
    Serial.println(tempC);
    Serial.print("Paciente inestable \n");
             // wait for a second
  digitalWrite(13, HIGH);    // turn the LED off by making the voltage LOW
    
   }
    // Envia el dato al puerto serial
    Serial.print("BPM = \n ");
    Serial.println(BPM);
    Serial.print(" Temperatura = \n");
    Serial.println(tempC);
    Serial.print("Paciente estable \n");
    // Espera cinco segundo para repetir el loop
      digitalWrite(13, LOW);  
    delay(3000);
   
}
