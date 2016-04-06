#include <HX711.h>
#define factorUno -766000
HX711 scaleUno(A1, A0);
HX711 scaleDos(A3, A2);
HX711 scaleTres(A5, A4);
HX711 scaleCuatro(A7, A6);
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
}

void loop() {
  Serial.print(scaleUno.get_units(5)*1000,0);
  Serial.print(" ");
  Serial.print(scaleDos.get_units(5)*1000,0);
  Serial.print(" ");
  Serial.print(scaleTres.get_units(5)*1000,0);
  Serial.print(" ");
  Serial.print(scaleCuatro.get_units(5)*1000,0);
  Serial.println();
  Serial.print(" ");
  while(Serial.available()>0){
    String info = Serial.readStringUntil('\n');
    info.trim();
    if(info == "reiniciar"){
      //reinicia la pesa del plato
      scaleUno.tare(); 
      delay(3000);     
    }
  }
  delay(2000);
}
