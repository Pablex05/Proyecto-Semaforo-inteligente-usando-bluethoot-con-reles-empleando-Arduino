char estado="";
int retardo=100;
int contador = 0;
int luz_rojo = 4;
int luz_amarillo = 7;
int luz_verde = 6;
long previousMillis = 0;       
long intervalOff = 5000;
long intervalOn = 7000;          
// el modulo hc05 esta conectado en los pines 1 y 0 
void setup(){
  
  pinMode(luz_rojo, OUTPUT);
  pinMode(luz_amarillo, OUTPUT);
  pinMode(luz_verde, OUTPUT);
  digitalWrite(luz_rojo, LOW);
  digitalWrite(luz_amarillo, LOW);
  digitalWrite(luz_verde, LOW);

  Serial.begin(9600);
 }
 void loop(){
  unsigned long currentMillis = millis();
  if(Serial.available()>0){           
        estado = Serial.read();      
  if(estado == 'a'){                    
    digitalWrite(luz_rojo, LOW);
    digitalWrite(luz_amarillo, LOW);
    digitalWrite(luz_verde, LOW);
    delay(10000);
     estado = "";
     contador = 0;
 }
 }
 if(contador != 1 && contador != 2 && contador != 2 && contador != 3){                    
    digitalWrite(luz_rojo, LOW);
    digitalWrite(luz_amarillo, LOW);
    digitalWrite(luz_verde, LOW);
  
 }
    if(currentMillis - previousMillis > intervalOff) {
            previousMillis = currentMillis;
            contador = contador + 1;
    }
    if (contador == 0){
        digitalWrite(luz_rojo, LOW);
        digitalWrite(luz_amarillo, HIGH);
        digitalWrite(luz_verde, HIGH);
    }
    if (contador == 1){
        digitalWrite(luz_rojo, HIGH);
        digitalWrite(luz_amarillo, LOW);
        digitalWrite(luz_verde, HIGH);
    }
    if (contador == 2){
        digitalWrite(luz_rojo, HIGH);
        digitalWrite(luz_amarillo, HIGH);
        digitalWrite(luz_verde, LOW);
    }   
    if (contador > 3){
        digitalWrite(luz_rojo, LOW);
        digitalWrite(luz_amarillo, HIGH);
        digitalWrite(luz_verde, LOW);
        contador = 0;
    }     
        if(currentMillis - previousMillis > intervalOn) {
           previousMillis = currentMillis;   
    }
 Serial.println(contador);
 
 Serial.println(estado);
 delay(retardo);
 }
 
 
