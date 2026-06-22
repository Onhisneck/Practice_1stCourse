import cv2
import numpy as np

image = cv2.imread("test_2-example-task-No11.jpg")
output = image.copy()

hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

# Зелёные объекты
green_mask = cv2.inRange(hsv, np.array((36, 25, 25)), np.array((85, 255, 255)))
green_contours, _ = cv2.findContours(green_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

for cnt in green_contours:
    x, y, w, h = cv2.boundingRect(cnt)
    cx, cy = x + w // 2, y + h // 2
    cv2.rectangle(output, (x, y), (x + w, y + h), (255, 0, 0), 3)  # синяя рамка
    cv2.circle(output, (cx, cy), 8, (0, 0, 255), -1)               # точка красная

# Жёлтые объекты
yellow_mask = cv2.inRange(hsv, np.array((20, 100, 100)), np.array((36, 255, 255)))
yellow_contours, _ = cv2.findContours(yellow_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

for cnt in yellow_contours:
    x, y, w, h = cv2.boundingRect(cnt)
    cx, cy = x + w // 2, y + h // 2
    cv2.rectangle(output, (x, y), (x + w, y + h), (0, 255, 0), 3)  # зелёная рамка
    cv2.circle(output, (cx, cy), 8, (0, 0, 255), -1)               # красная точка

cv2.imshow("result", output)
cv2.waitKey(0)
cv2.destroyAllWindows()
