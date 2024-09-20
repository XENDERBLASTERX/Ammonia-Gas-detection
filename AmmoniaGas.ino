
#define RL 47
#define m -0.263
#define b 0.42
#define Ro 20
#define MQ_sensor A0

#include <LiquidCrystal.h>


const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {

  lcd.begin(16, 2);

  lcd.print("NH3 in PPM");

  lcd.setCursor(0, 1);

  lcd.print("-CircuitDigest");


   delay(2000);

   lcd.clear();

}


void loop() {


  float VRL;

  float Rs;

  float ratio;
   

  VRL = analogRead(MQ_sensor)*(5.0/1023.0);

  Rs = ((5.0*RL)/VRL)-RL;

  ratio = Rs/Ro;

 

  float ppm = pow(10, ((log10(ratio)-b)/m));

  lcd.print("NH3 (ppm) = "); 

  lcd.print(ppm);

  lcd.setCursor(0, 1); 

  lcd.print("Voltage = "); 
  lcd.print(VRL);


   delay(200);

   lcd.clear(); 

}