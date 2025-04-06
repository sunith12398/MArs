import cv2
import numpy as np
import math

# Camera Parameters
IMAGE_WIDTH = 1280
IMAGE_HEIGHT = 720
FOV_DEGREES = 55  # Diagonal Field of View
REAL_ARROW_WIDTH = 17.0  # cm

# Calculate focal length based on the camera's FOV and resolution
FOV_RADIANS = math.radians(FOV_DEGREES)
focal_length = (IMAGE_WIDTH / 2) / math.tan(FOV_RADIANS / 2)

def detect_arrow(image_path):
    # Read the image
    image = cv2.imread(image_path)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Apply Gaussian Blur to reduce noise
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)

    # Edge detection using Canny
    edges = cv2.Canny(blurred, 50, 150)

    # Find contours
    contours, _ = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for cnt in contours:
        approx = cv2.approxPolyDP(cnt, 0.02 * cv2.arcLength(cnt, True), True)

        if len(approx) == 7:  # Arrows typically have 7 sides
            cv2.drawContours(image, [approx], 0, (0, 255, 0), 3)
            print("Arrow detected!")

            # Bounding box to measure perceived width
            x, y, w, h = cv2.boundingRect(approx)
            perceived_width = max(w, h)

            # Distance calculation using the pinhole camera formula
            distance = find_distance(perceived_width)
            print(f"Estimated Distance: {distance:.2f} cm")

    # Display the result
    cv2.imshow('Detected Arrow', image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

def find_distance(perceived_width):
    # Pinhole camera formula for distance calculation
    distance = (REAL_ARROW_WIDTH * focal_length) / perceived_width
    return distance

# Path to the image
image_path = 'arrow.jpg'  # Replace with the correct path
detect_arrow(image_path)
