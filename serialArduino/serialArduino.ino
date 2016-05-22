#include <HX711.h>
#define factorUno -775000
HX711 scaleUno(A1, A0);
HX711 scaleDos(A3, A2);
HX711 scaleTres(A5, A4);
HX711 scaleCuatro(A7, A6);
HX711 scaleCinco(A9, A8);
HX711 scaleSeis(A11, A10);
HX711 scaleSiete(A13, A12);
//(DT, SCK)
void setup() {
  Serial.begin(9600);
  scaleUno.set_scale(-816000);
  scaleUno.tare();
  scaleDos.set_scale(-839500);
  scaleDos.tare();
  scaleTres.set_scale(-788000);
  scaleTres.tare();
  scaleCuatro.set_scale(-778000);
  scaleCuatro.tare();
  scaleCinco.set_scale(-729000);
  scaleCinco.tare();
  scaleSeis.set_scale(factorUno);
  scaleSeis.tare();
  //scaleSiete.set_scale(factorUno);
  //scaleSiete.tare();
}

void loop() {
  Serial.print("pesas");
  Serial.print(" ");
  Serial.print(abs(scaleUno.get_units(5))*1000,0);
  Serial.print(" ");
  Serial.print(abs(scaleDos.get_units(5))*1000,0);
  Serial.print(" ");
  Serial.print(abs(scaleTres.get_units(5))*1000,0);
  Serial.print(" ");
  Serial.print(abs(scaleCuatro.get_units(5))*1000,0);
  Serial.print(" ");
  Serial.print(abs(scaleCinco.get_units(5))*1000,0);
  Serial.print(" ");
  Serial.print(abs(scaleSeis.get_units(5))*1000,0);
  Serial.print(" ");
  Serial.print(77);
  Serial.println();
  while(Serial.available()>0){
    String info = Serial.readStringUntil('\n');
    info.trim();
    if(info == "reiniciar"){           
      Serial.print("reset");
      Serial.println();
      delay(20000); 
      //reinicia la pesa del plato
      scaleUno.tare(); 
      Serial.print("nuevoPeso");
      Serial.println();     
    }
  }
  delay(1000);
}

