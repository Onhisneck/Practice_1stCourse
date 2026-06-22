const int pinGreen = 9;   // зелёный светодиод — дверь открыта
const int pinRed   = 8;   // красный светодиод — дверь закрыта
const int pinPhoto = A0;  // фоторезистор

const int THRESHOLD  = 512;   // порог срабатывания
const int DOOR_DELAY = 3000;  // время удержания двери открытой (3 сек)

void setup() {
  pinMode(pinGreen, OUTPUT);
  pinMode(pinRed,   OUTPUT);
  Serial.begin(9600);

  // По умолчанию: дверь закрыта
  digitalWrite(pinRed,   HIGH);
  digitalWrite(pinGreen, LOW);
}

void loop() {
  int photoValue = analogRead(pinPhoto);

  if (photoValue > THRESHOLD) {
    digitalWrite(pinRed,   LOW);
    digitalWrite(pinGreen, HIGH);
    Serial.println("Дверь открывается");

    delay(DOOR_DELAY);  // ждём заданное время

    // Проверяем снова: ушёл ли человек?
    photoValue = analogRead(pinPhoto);
    if (photoValue <= THRESHOLD) {
      // Человек ушёл → закрываем дверь
      digitalWrite(pinGreen, LOW);
      digitalWrite(pinRed,   HIGH);
      Serial.println("Дверь закрывается");
    }
  }
}
