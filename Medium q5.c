#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Function to convert Euler angles to quaternion
void eulerToQuaternion(double roll, double pitch, double yaw, double *w, double *x, double *y, double *z) {
    // Convert degrees to radians
    roll = roll * PI / 180.0;
    pitch = pitch * PI / 180.0;
    yaw = yaw * PI / 180.0;

    // Calculate quaternion components
    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);

    *w = cr * cp * cy + sr * sp * sy;
    *x = sr * cp * cy - cr * sp * sy;
    *y = cr * sp * cy + sr * cp * sy;
    *z = cr * cp * sy - sr * sp * cy;
}

int main() {
    double roll, pitch, yaw;
    double w, x, y, z;

    printf("Enter Euler angles (Roll, Pitch, Yaw) in degrees:\n");
    scanf("%lf %lf %lf", &roll, &pitch, &yaw);

    eulerToQuaternion(roll, pitch, yaw, &w, &x, &y, &z);

    printf("Quaternion (w, x, y, z): (%.4f, %.4f, %.4f, %.4f)\n", w, x, y, z);

    return 0;
}
