#include <HX711.h>
#define factorUno -766000
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
  scaleUno.set_scale(factorUno);
  scaleUno.tare();
  scaleDos.set_scale(factorUno);
  scaleDos.tare();
  scaleTres.set_scale(factorUno);
  scaleTres.tare();
  scaleCuatro.set_scale(factorUno);
  scaleCuatro.tare();
  scaleCinco.set_scale(factorUno);
  scaleCinco.tare();
  scaleSeis.set_scale(factorUno);
  scaleSeis.tare();
  scaleSiete.set_scale(factorUno);
  scaleSiete.tare();
}

void loop() {
  Serial.print("pesas");
  Serial.print(" ");
  Serial.print(scaleUno.get_units(5)*1000,0);
  Serial.print(" ");
  Serial.print(22);
  Serial.print(" ");
  Serial.print(33);
  Serial.print(" ");
  Serial.print(44);
  Serial.print(" ");
  Serial.print(55);
  Serial.print(" ");
  Serial.print(66);
  Serial.print(" ");
  Serial.print(77);
  Serial.println();
  Serial.print(" ");
  while(Serial.available()>0){
    String info = Serial.readStringUntil('\n');
    info.trim();
    if(info == "reiniciar"){           
      Serial.print("reset");
      Serial.println();
      delay(20000); 
      //reinicia la pesa del plato
      scaleUno.tare();      
    }
  }
  delay(1000);
}
