int buzzer = 8;
int LED = 9;
int i;
# define analog_pin 0
float sensor_value;
#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  pinMode(buzzer,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600); 
}
// the loop routine runs over and over again forever:
void loop() 
{
    sensor_value = analogRead(analog_pin);
    Serial.println(sensor_value);
    
    if( sensor_value>450) 
    {
      digitalWrite(buzzer,HIGH);
      lcd.begin(16, 2);
      lcd.print("The Driver is ");
      lcd.setCursor(2, 1);
      lcd.print("Drunk");
      digitalWrite(LED,HIGH);
    }
    else {
      digitalWrite(buzzer,LOW);
      lcd.begin(16, 2);
      lcd.print("DRIVE SAFElY");
      digitalWrite(LED,LOW);
    }
  char input = Serial.read();
  if(input == '1')
  {   
      digitalWrite(LED,HIGH);
      digitalWrite(buzzer,HIGH);
      lcd.begin(16, 2);
      lcd.print("CAUTION");
      lcd.setCursor(2, 1);
      lcd.print("DRIVER ASLEEP");    
  }
if(input == '0')
{
      digitalWrite(buzzer,LOW);
      lcd.begin(16, 2);
      lcd.print("DRIVE SAFElY");
      digitalWrite(LED,LOW);   
}
}
