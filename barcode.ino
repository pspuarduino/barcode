int outputPin = A0;

int resetTimer = 0;
int resetTime = 100;

int recordTime = 200;
int recordTimer = 0;
int linesCount = 0;
int currentState = 0;

// Главный цикл setup исполняется 1 раз в нем прописываются настройки
void setup()
{ // начало исполнения функции
  // частота обмена данными
  Serial.begin(9600); // 9600 бод| бод - бит/сек
  pinMode(A0, INPUT); // для пина A0 задаем режим чтения
} // конец исполнения функции

void loop() 
{ // начало исполнения функции
  int buttonState = digitalRead(A0); // читаем значение из аналогового входа
  
  recordTimer++;
  
  if(recordTimer < recordTime){
    digitalWrite(13, LOW);
    if(buttonState == HIGH && currentState == 1){
      currentState = 0;
      linesCount++;
    }else if(buttonState == LOW && currentState == 0){
      currentState = 1;
    }
  }else{
    digitalWrite(13, HIGH);
    if(buttonState == LOW){
      resetTimer++;
      if(resetTimer > resetTime){
        resetTimer = 0;
        recordTimer = 0;
        linesCount = 0;
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        delay(300);
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        delay(300);
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        delay(300);
      }
    }else{
      resetTimer = 0;
    }
  }
  
  Serial.print("");
  Serial.print(linesCount);
  Serial.print(" ");
  Serial.print(recordTimer);
  Serial.print(" ");
  Serial.print(resetTimer);
  Serial.print(" ");
  Serial.print(currentState);
  Serial.print(" ");
  Serial.println(buttonState);
  Serial.write(27);
  
  delay(1); // приостанавливаем исполнениие на 1 миллисекунду
} // конец исполнения функции



