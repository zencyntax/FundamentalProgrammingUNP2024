#include <stdio.h>
#include <string.h>

int main()
{
    int jumlahPerulangan; // Variabel untuk menyimpan jumlah pengulangan
    printf("Masukkan jumlah data mahasiswa: ");
    scanf("%d", &jumlahPerulangan); // Membaca jumlah pengulangan

    for (int i = 0; i < jumlahPerulangan; i++)
    {
        char nama[100];
        char nim[20];
        char prodi[50];
        char universitas[50];
        char alamat[100];

        printf("\nSistem informasi data mahasiswa!\n");

        printf("Masukkan nama: ");
        scanf(" %[^\n]", nama);

        printf("Masukkan NIM: ");
        scanf("%s", nim);

        printf("Masukkan program studi: ");
        scanf(" %[^\n]", prodi);

        printf("Masukkan universitas: ");
        scanf(" %[^\n]", universitas);

        printf("Masukkan alamat: ");
        scanf(" %[^\n]", alamat);

        printf("\nInformasi data mahasiswa yang dimasukkan:\n");
        printf("Nama: %s\n", nama);
        printf("NIM: %s\n", nim);
        printf("Program Studi: %s\n", prodi);
        printf("Universitas: %s\n", universitas);
        printf("Alamat: %s\n", alamat);

        puts("\nTerima kasih atas informasi yang Anda berikan!");
    }

    return 0;
}