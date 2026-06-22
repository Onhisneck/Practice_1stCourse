import cv2
import numpy as np

image = cv2.imread("test_2-example-task-No11.jpg")
output = image.copy()

# Размытие для подавления шума
blurred = cv2.GaussianBlur(image, (11, 11), 0)
hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

# Зелёные объекты
green_min = np.array((36, 25, 25), np.uint8)
green_max = np.array((85, 255, 255), np.uint8)
green_mask = cv2.inRange(hsv, green_min, green_max)
green_contours, _ = cv2.findContours(green_mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

for cnt in green_contours:
    if cv2.contourArea(cnt) < 500:  # фильтрация мелких артефактов
        continue
    x, y, w, h = cv2.boundingRect(cnt)
    cx, cy = int(x + w / 2), int(y + h / 2)
    cv2.rectangle(output, (x, y), (x + w, y + h), (255, 0, 0), 4)      # синяя рамка
    cv2.circle(output, (cx, cy), 12, (0, 0, 255), -1)                   # красная точка
    cv2.circle(output, (cx, cy), 12, (255, 255, 255), 2)                # белая обводка
    cv2.putText(output, f"G ({cx},{cy})", (x, y - 10),
                cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 0, 0), 2)          # подпись

# Жёлтые объекты
yellow_min = np.array((20, 100, 100), np.uint8)
yellow_max = np.array((36, 255, 255), np.uint8)
yellow_mask = cv2.inRange(hsv, yellow_min, yellow_max)
yellow_contours, _ = cv2.findContours(yellow_mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

for cnt in yellow_contours:
    if cv2.contourArea(cnt) < 500:  # фильтрация мелких артефактов
        continue
    x, y, w, h = cv2.boundingRect(cnt)
    cx, cy = int(x + w / 2), int(y + h / 2)
    cv2.rectangle(output, (x, y), (x + w, y + h), (0, 255, 0), 4)      # зелёная рамка
    cv2.circle(output, (cx, cy), 12, (0, 0, 255), -1)                   # красная точка
    cv2.circle(output, (cx, cy), 12, (255, 255, 255), 2)                # белая обводка
    cv2.putText(output, f"Y ({cx},{cy})", (x, y - 10),
                cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 200, 0), 2)          # подпись

cv2.imshow("result", output)
cv2.waitKey(0)
cv2.destroyAllWindows()
