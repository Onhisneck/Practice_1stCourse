#include <Servo.h>

Servo myServo;

int currentAngle = 0;  // текущий угол

void setup() {
  myServo.attach(9);
  myServo.write(currentAngle);
  Serial.begin(9600);
  Serial.println("Введите угол от 0 до 180:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    // Проверка: только цифры
    bool isNumber = true;
    for (int i = 0; i < input.length(); i++) {
      if (!isDigit(input[i])) {
        isNumber = false;
        break;
      }
    }

    if (!isNumber || input.length() == 0) {
      Serial.println("Ошибка: введите число от 0 до 180");
      return;
    }

    int targetAngle = input.toInt();

    if (targetAngle < 0 || targetAngle > 180) {
      Serial.println("Ошибка: угол должен быть от 0 до 180");
      return;
    }

    if (targetAngle == currentAngle) {
      Serial.println("Сервопривод уже в этом положении");
      return;
    }

    // Плавный поворот
    Serial.print("Поворот к углу: ");
    Serial.println(targetAngle);

    int step = (targetAngle > currentAngle) ? 1 : -1;
    while (currentAngle != targetAngle) {
      currentAngle += step;
      myServo.write(currentAngle);
      delay(15);  // скорость поворота
    }

    Serial.println("Готово!");
  }
}
