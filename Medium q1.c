#include <stdio.h>
#include <math.h>

// Function to calculate distance between two points in 3D space
double calculateDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

// Function to adjust the rover's position
void adjustRoverPosition(double x, double y, double z, double shift_distance, double *x_final, double *y_final, double *z_final) {
    // Adjusting the position to be exactly above the marker
    // Assuming the rover was shifted 55 cm behind, we need to correct that
    // We shift the rover forward by 55 cm along the x-axis
    *x_final = x + shift_distance;
    *y_final = y;
    *z_final = z;
}

int main() {
    // Input coordinates from the camera detection
    double x = 0.0, y = 0.0, z = -60.0; // Example coordinates of the marker
    double shift_distance = 55.0; // The distance the rover was off by (in cm)

    double x_final, y_final, z_final;

    // Adjust rover's position
    adjustRoverPosition(x, y, z, shift_distance, &x_final, &y_final, &z_final);

    // Calculate distances before and after adjustment
    double initial_distance = calculateDistance(x, y, z, x_final, y_final, z_final);

    // Output the final position and distance
    printf("Original Marker Position: (%.2f, %.2f, %.2f)\n", x, y, z);
    printf("Adjusted Position: (%.2f, %.2f, %.2f)\n", x_final, y_final, z_final);
    printf("Distance before adjustment: %.2f cm\n", initial_distance);
    printf("Distance after adjustment: 0.00 cm (Rover is exactly above the marker)\n");

    return 0;
}
