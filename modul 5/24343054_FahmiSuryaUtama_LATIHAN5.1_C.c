#include <stdio.h>

// Fungsi untuk menghitung faktorial secara rekursif
int hitungFaktorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * hitungFaktorial(n - 1);
    }
}

int main()
{
    int n;

    printf("Masukkan bilangan bulat positif: ");
    if (scanf("%d", &n) != 1 || n < 0) { // Validasi input
        printf("Input tidak valid. Masukkan bilangan bulat positif.\n");
        return 1; // Keluar dari program jika input tidak valid
    }

    // Memanggil fungsi faktorial dan menampilkan hasil
    int faktorial = hitungFaktorial(n);
    printf("Faktorial dari %d adalah: %d\n", n, faktorial);

    return 0;
}
