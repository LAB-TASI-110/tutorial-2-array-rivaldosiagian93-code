#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nilai[n];
    
    // Input data
    for(int i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    int min = nilai[0];
    int max = nilai[0];

    // Cari nilai terkecil dan terbesar
    for(int i = 1; i < n; i++) {
        if(nilai[i] < min) {
            min = nilai[i];
        }
        if(nilai[i] > max) {
            max = nilai[i];
        }
    }

    // Cari rata-rata terendah dari dua elemen berurutan
    float rata_min = (nilai[0] + nilai[1]) / 2.0;

    for(int i = 1; i < n - 1; i++) {
        float rata = (nilai[i] + nilai[i+1]) / 2.0;
        if(rata < rata_min) {
            rata_min = rata;
        }
    }

    // Output
    printf("%d\n", min);
    printf("%d\n", max);
    printf("%.2f\n", rata_min);

    return 0;
}