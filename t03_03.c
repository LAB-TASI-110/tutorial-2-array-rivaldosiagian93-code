#include <stdio.h>   // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h>  // Diperlukan untuk INT_MAX dan INT_MIN agar inisialisasi min/max awal lebih aman

// Fungsi utama program
int main() {
    int n;          // Variabel untuk menyimpan jumlah masukan angka
    int num;        // Variabel sementara untuk setiap angka yang dibaca
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan angka maksimum yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan angka minimum yang mungkin
    int count_valid_inputs = 0; // Untuk menghitung jumlah input valid yang berhasil diproses (selain 'n')

    // Variabel untuk menyimpan empat angka pertama yang valid
    int first_num_data = 0;
    int second_num_data = 0;
    int third_num_data = 0;
    int fourth_num_data = 0;

    // Variabel untuk rata-rata, bertipe float agar bisa menyimpan desimal
    float avg_first_two = 0.0;
    float avg_third_fourth = 0.0;

    // Langkah 2: Minta Input Jumlah Angka (n) dan Validasi
    printf("Masukkan jumlah angka yang akan diinput (n, bilangan bulat positif): ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input tidak valid. n harus bilangan bulat positif. Silakan masukkan lagi: ");
        // Membersihkan buffer input
        while (getchar() != '\n');
    }

    printf("Silakan masukkan %d angka, setiap angka harus dalam rentang -100 sampai 100:\n", n);

    // Langkah 4: Loop untuk Membaca Angka Lainnya
    for (int i = 0; i < n; i++) {
        printf("Masukkan angka ke-%d: ", i + 1);
        
        // Langkah 5: Validasi Setiap Angka (type check)
        if (scanf("%d", &num) != 1) {
            printf("Input di luar batasan yang di perbolehkan: Input harus bilangan bulat.\n");
            while (getchar() != '\n'); // Membersihkan buffer input
            i--; // Kurangi i agar angka yang tidak valid diulang inputnya
            continue; // Lanjut ke iterasi berikutnya
        }

        // Langkah 5: Validasi Setiap Angka (range check)
        if (num < -100 || num > 100) {
            printf("Input di luar batasan yang di perbolehkan: Angka harus antara -100 dan 100.\n");
            while (getchar() != '\n'); // Membersihkan buffer input
            i--; // Kurangi i agar angka yang tidak valid diulang inputnya
            continue; // Lanjut ke iterasi berikutnya
        }
        
        // Hanya angka yang valid yang dihitung dan diproses
        count_valid_inputs++; 

        // Langkah 6: Simpan Empat Angka Pertama dan Hitung Rata-rata
        if (count_valid_inputs == 1) {
            first_num_data = num;
        } else if (count_valid_inputs == 2) {
            second_num_data = num;
            avg_first_two = (float)(first_num_data + second_num_data) / 2.0;
        } else if (count_valid_inputs == 3) {
            third_num_data = num;
        } else if (count_valid_inputs == 4) {
            fourth_num_data = num;
            avg_third_fourth = (float)(third_num_data + fourth_num_data) / 2.0;
        }

        // Langkah 7: Perbarui min dan max
        if (num < min_val) {
            min_val = num;
        }
        if (num > max_val) {
            max_val = num;
        }
    }

    printf("\nBerikut adalah luaran yang dihasilkan:\n");
    // Langkah 8: Tampilkan Hasil
    if (count_valid_inputs > 0) {
        printf("%d\n", min_val); // Baris keluaran 1: nilai terkecil
        printf("%d\n", max_val); // Baris keluaran 2: nilai terbesar
        
        // Baris keluaran 3: rata-rata dari dua angka pertama, dengan 2 digit presisi
        if (count_valid_inputs >= 2) { 
            printf("%.2f\n", avg_first_two);
        } else {
            // Jika kurang dari 2 input, tidak bisa menghitung rata-rata dua angka pertama
            printf("Tidak cukup input untuk menghitung rata-rata dua angka pertama.\n");
        }

        // Baris keluaran 4: rata-rata dari angka ketiga dan keempat, dengan 2 digit presisi
        if (count_valid_inputs >= 4) { 
            printf("%.2f\n", avg_third_fourth);
        } else {
            // Jika kurang dari 4 input, tidak bisa menghitung rata-rata angka ketiga dan keempat
            printf("Tidak cukup input untuk menghitung rata-rata angka ketiga dan keempat.\n");
        }

    } else {
        printf("Tidak ada input angka yang valid diproses.\n");
    }

    return 0; // Menandakan program berakhir dengan sukses
}