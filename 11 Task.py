import cv2
import numpy as np

image = cv2.imread("test_2-example-task-No11.jpg")
output = image.copy()

blurred = cv2.GaussianBlur(image, (11, 11), 0)
hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

green_min = np.array((36, 25, 25), np.uint8)
green_max = np.array((85, 255, 255), np.uint8)
green_mask = cv2.inRange(hsv, green_min, green_max)

contours, _ = cv2.findContours(green_mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

for cnt in contours:
    if cv2.contourArea(cnt) < 500:  # убираем мелкие артефакты
        continue

    x, y, w, h = cv2.boundingRect(cnt)
    cx = int(x + w / 2)
    cy = int(y + h / 2)

    # Рисуем красную точку в центре
    cv2.circle(output, (cx, cy), 12, (0, 0, 255), -1)
    cv2.circle(output, (cx, cy), 12, (255, 255, 255), 2)  # белая обводка
    cv2.putText(output, f"({cx},{cy})", (cx + 15, cy),
                cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 0, 255), 2)

cv2.imshow("Variant 20", output)
cv2.waitKey(0)
cv2.destroyAllWindows()
