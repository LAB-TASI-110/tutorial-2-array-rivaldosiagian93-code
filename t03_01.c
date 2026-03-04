#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN agar inisialisasi min/max awal lebih aman

// Fungsi utama program
int main() {
    int n; // Variabel untuk menyimpan jumlah masukan angka
    int num; // Variabel sementara untuk setiap angka yang dibaca
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan angka maksimum yang mungkin (dari limits.h)
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan angka minimum yang mungkin (dari limits.h)
    int count = 0; // Untuk menghitung jumlah input valid yang berhasil diproses

    // Langkah 2: Minta Input Jumlah Angka (n)
    printf("Masukkan jumlah angka yang akan diinput (n, bilangan bulat positif): ");
    // Menggunakan scanf untuk membaca input. %d untuk bilangan bulat, &n adalah alamat variabel n.
    // Pengecekan return value scanf untuk memastikan input adalah angka
    while (scanf("%d", &n) != 1 || n <= 0) {
        // Jika input bukan angka atau n tidak positif
        printf("Input tidak valid. n harus bilangan bulat positif. Silakan masukkan lagi: ");
        // Membersihkan buffer input untuk menghindari loop tak terbatas jika ada karakter non-angka
        while (getchar() != '\n');
    }

    // Penjelasan: Baris 1 "n" mempresentasikan bilangan bulat positif sebagai jumlah masukan.
    // Spesifikasi 2: 'n' adalah bilangan bulat antara "-100-100" (ini kemungkinan typo dan merujuk pada angka-angka yang diinput, bukan n itu sendiri)
    // Berdasarkan contoh input, angka-angka setelah 'n' yang memiliki rentang -100 hingga 100.
    // Jadi, kita akan validasi rentang -100 hingga 100 untuk setiap angka yang diinput *setelah* 'n'.

    printf("Silakan masukkan %d angka, setiap angka harus dalam rentang -100 sampai 100:\n", n);

    // Langkah 5: Loop untuk Membaca Angka Lainnya
    for (int i = 0; i < n; i++) {
        printf("Masukkan angka ke-%d: ", i + 1);
        // Langkah 6: Validasi Setiap Angka
        if (scanf("%d", &num) != 1) { // Pengecekan apakah input adalah angka
            printf("Input di luar batasan yang di perbolehkan: Input harus bilangan bulat.\n");
            // Membersihkan buffer input
            while (getchar() != '\n');
            i--; // Kurangi i agar angka yang tidak valid diulang inputnya
            continue; // Lanjut ke iterasi berikutnya
        }

        // Validasi rentang -100 hingga 100
        if (num < -100 || num > 100) {
            printf("Input di luar batasan yang di perbolehkan: Angka harus antara -100 dan 100.\n");
            // Membersihkan buffer input
            while (getchar() != '\n');
            i--; // Kurangi i agar angka yang tidak valid diulang inputnya
            continue; // Lanjut ke iterasi berikutnya
        }
        
        count++; // Tambahkan hitungan input valid

        // Langkah 7: Perbarui min dan max
        if (num < min_val) {
            min_val = num; // Jika angka saat ini lebih kecil, update min_val
        }
        if (num > max_val) {
            max_val = num; // Jika angka saat ini lebih besar, update max_val
        }
    }

    printf("\nBerikut adalah contoh luaran yang dihasilkan:\n");
    // Langkah 8: Tampilkan Hasil
    if (count > 0) { // Pastikan ada input valid yang diproses
        printf("%d\n", min_val); // Baris keluaran 1: nilai terkecil
        printf("%d\n", max_val); // Baris keluaran 2: nilai terbesar
        // Catatan: Anda menyebutkan 3 keluaran baris. Karena contoh output hanya 2 baris (min dan max),
        // saya mengikuti contoh tersebut. Jika ada baris ketiga yang spesifik, mohon informasikan.
    } else {
        printf("Tidak ada input angka yang valid diproses.\n");
    }

    return 0; // Menandakan program berakhir dengan sukses 
}