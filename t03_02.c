#include <stdio.h>   
#include <limits.h> 

int main() {
    int n;         
    int num;       
    int min_val = INT_MAX; 
    int max_val = INT_MIN; 
    int count_valid_inputs = 0; 
    
    int first_num_data = 0;
    int second_num_data = 0;
    float avg_first_two = 0.0;

   
    printf("Masukkan jumlah angka yang akan diinput (n, bilangan bulat positif): ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input tidak valid. n harus bilangan bulat positif. Silakan masukkan lagi: ");
       
        while (getchar() != '\n');
    }

    printf("Silakan masukkan %d angka, setiap angka harus dalam rentang -100 sampai 100:\n", n);

   
    for (int i = 0; i < n; i++) {
        printf("Masukkan angka ke-%d: ", i + 1);
        
       
        if (scanf("%d", &num) != 1) {
            printf("Input di luar batasan yang di perbolehkan: Input harus bilangan bulat.\n");
            while (getchar() != '\n');
            i--; 
            continue; 
        }

        
        if (num < -100 || num > 100) {
            printf("Input di luar batasan yang di perbolehkan: Angka harus antara -100 dan 100.\n");
            while (getchar() != '\n');
            i--; 
            continue;
        }
        
        
        count_valid_inputs++; 

        if (count_valid_inputs == 1) {
            first_num_data = num;
        } else if (count_valid_inputs == 2) {
            second_num_data = num;
            avg_first_two = (float)(first_num_data + second_num_data) / 2.0;
        }

     
        if (num < min_val) {
            min_val = num;
        }
        if (num > max_val) {
            max_val = num;
        }
    }

    printf("\nBerikut adalah contoh luaran yang dihasilkan:\n");
   
    if (count_valid_inputs > 0) {
        printf("%d\n", min_val); 
        printf("%d\n", max_val); 
        
       
        if (count_valid_inputs >= 2) { 
            printf("%.2f\n", avg_first_two);
        } else {
            
            printf("Tidak cukup input untuk menghitung rata-rata dua angka pertama.\n");
        }
    } else {
        printf("Tidak ada input angka yang valid diproses.\n");
    }

    return 0;
}