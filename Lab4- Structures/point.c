#include <stdio.h>
#include <math.h>
int main(){
    struct Point{
        int x;
        int y;
        int z;
    };
    int n;
    printf("Number of points: ");
    scanf("%d", &n);
    struct Point points[n];
    for (int i = 1; i <= n; i++){
        int x;
        int y;
        int z;
        printf("X for point{%d}: ", i);
        scanf("%d", &x);
        printf("Y for pint{%d}: ", i);
        scanf("%d", &y);
        printf("Z for pint{%d}: ", i);
        scanf("%d", &z);
        struct Point point;
        point.x = x;
        point.y = y;
        point.z = z;

        points[i - 1] = point;
    }

    for (int i = 0; i < n / 3; i++){
                printf("For triangle %d:\n", i + 1);
                struct Point point1 = points[i];
                struct Point point2 = points[i + 1];
                struct Point point3 = points[i + 2];
                float a = sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y) + (point1.z - point2.z) * (point1.z - point2.z));
                float b = sqrt((point1.x - point3.x) * (point1.x - point3.x) + (point1.y - point3.y) * (point1.y - point3.y) + (point1.z - point3.z) * (point1.z - point3.z));
                float c = sqrt((point3.x - point2.x) * (point3.x - point2.x) + (point3.y - point2.y) * (point3.y - point2.y) + (point3.z - point2.z) * (point3.z - point2.z));
                printf("A: %f; B: %f; C: %f\n", a, b, c);
        
    }
    
}