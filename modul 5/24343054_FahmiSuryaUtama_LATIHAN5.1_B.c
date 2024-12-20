#include <stdio.h>
#include <math.h>  // Tambahkan untuk menggunakan M_PI

// Fungsi untuk menghitung keliling lingkaran
float hitungKelilingLingkaran(float jariJari) {
    return 2 * M_PI * jariJari;  // Menggunakan M_PI dari math.h
}

int main() {
    float jariJari;

    // Meminta input dari user
    printf("Masukkan jari-jari lingkaran: ");
    scanf("%f", &jariJari);

    // Memanggil fungsi dan menampilkan hasil
    float keliling = hitungKelilingLingkaran(jariJari);
    printf("Keliling lingkaran adalah: %.2f\n", keliling);

    return 0;
}
