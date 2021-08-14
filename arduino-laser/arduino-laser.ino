/* Автор кода - Prosta
 * Донат - https://www.donationalerts.com/r/prostaprogramming
 * https://github.com/ProstaIT
 * https://www.youtube.com/c/PROSTA
 * 
 */
 
 
const int led1 = 31; // Пин светодиода
const int laser = 30; //
int num = 0;
void setup() {
  Serial.begin(115200);
  pinMode(laser, OUTPUT);
  pinMode(led1, OUTPUT);
  digitalWrite(laser, HIGH);
  delay(2000);
 
}

void loop() {
  int value = analogRead(A0);
  Serial.println(value);

  if (value > 750){
    digitalWrite(led1, LOW);
  
  }
  
  /*value > 1000 данная часть кода позволяет включить тревогу когда значения с фоторезистора сильно увеличилось (когда кто-то светит сильным фонариком)
    value < 750 данная часть кода позволяет включить тревогу когда значения с фоторезистора сильно упало (когда кто-то перекрыл лазер)
  */
  
  if (value < 750 or value > 1000){
     while (true) {
      if (num <= 5){
            Serial.println(num);
            digitalWrite(led1, HIGH);
            delay(1000);
            digitalWrite(led1, LOW);
            delay(1000);
            num++;
            }
      if (num == 6){
            num = 0;
            break;
            }

    } 
  }
}
