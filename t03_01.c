#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nilai, min, max;

    // Membaca nilai pertama sebagai acuan awal
    scanf("%d", &nilai);
    min = nilai;
    max = nilai;

    // Membaca sisa nilai
    for(int i = 1; i < n; i++) {
        scanf("%d", &nilai);

        if(nilai < min) {
            min = nilai;
        }

        if(nilai > max) {
            max = nilai;
        }
    }

    // Menampilkan hasil
    printf("%d\n", min);
    printf("%d\n", max);

    return 0;
}