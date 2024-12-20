/*
    nama file         : tugas6.c
    programer         : Fahmi Surya Utama
    nim               : 24343054
    program           : program memebaca file teks, menghitung jumlah kata dan waktu eksekusi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER 1000 // Ukuran buffer untuk membaca file

//fungsi menampilkan biodata
void biodata(){
	printf("program memebaca file teks, menghitung jumlah kata dan waktu eksekusi\n");
	printf("=================================================================\n");
	printf("Nama : Fahmi Surya Utama\n");
	printf("Nim  : 24343054\n");
	printf("==============================\n");
}
// Fungsi untuk menghitung kata, karakter, dan baris dalam file menggunakan fgets()
void hitungDenganFgets(FILE *file, int *jumlahKata, int *jumlahKarakter, int *jumlahBaris) {
    char buffer[MAX_BUFFER];
    char *kata;

    *jumlahKata = *jumlahKarakter = *jumlahBaris = 0;

    while (fgets(buffer, MAX_BUFFER, file) != NULL) {
        (*jumlahBaris)++;
        *jumlahKarakter += strlen(buffer);

        kata = strtok(buffer, " \t\n"); // Tokenisasi string dengan delimiter spasi, tab, atau newline
        while (kata != NULL) {
            (*jumlahKata)++;
            kata = strtok(NULL, " \t\n"); // Ambil kata berikutnya
        }
    }
}

// Fungsi untuk menghitung kata, karakter, dan baris dalam file menggunakan fscanf()
void hitungDenganFscanf(FILE *file, int *jumlahKata, int *jumlahKarakter, int *jumlahBaris) {
    char c;
    char kata[MAX_BUFFER];

    *jumlahKata = *jumlahKarakter = *jumlahBaris = 0;

    while ((c = fgetc(file)) != EOF) {
        (*jumlahKarakter)++;
        if (c == '\n') {
            (*jumlahBaris)++;
        }
    }

    rewind(file); // Kembali ke awal file untuk membaca kata

    while (fscanf(file, "%s", kata) == 1) {
        (*jumlahKata)++;
    }
}

int main() {
    biodata();
    FILE *file;
    char namaFile[100];
    int jumlahKata, jumlahKarakter, jumlahBaris;
    clock_t start, end;
    double waktuFgets, waktuFscanf;

    // Meminta pengguna memasukkan nama file
    printf("Masukkan nama file: ");
    scanf("%s", namaFile);

    // Membuka file
    file = fopen(namaFile, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s.\n", namaFile);
        return 1;
    }

    // Mengukur waktu untuk metode fgets()
    start = clock();
    hitungDenganFgets(file, &jumlahKata, &jumlahKarakter, &jumlahBaris);
    end = clock();
    waktuFgets = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Dengan fgets():\n");
    printf("Jumlah kata: %d\n", jumlahKata);
    printf("Jumlah karakter: %d\n", jumlahKarakter);
    printf("Jumlah baris: %d\n", jumlahBaris);
    printf("Waktu eksekusi: %.5f detik\n", waktuFgets);

    rewind(file); // Kembali ke awal file untuk metode berikutnya

    // Mengukur waktu untuk metode fscanf()
    start = clock();
    hitungDenganFscanf(file, &jumlahKata, &jumlahKarakter, &jumlahBaris);
    end = clock();
    waktuFscanf = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nDengan fscanf():\n");
    printf("Jumlah kata: %d\n", jumlahKata);
    printf("Jumlah karakter: %d\n", jumlahKarakter);
    printf("Jumlah baris: %d\n", jumlahBaris);
    printf("Waktu eksekusi: %.5f detik\n", waktuFscanf);

    // Menutup file
    fclose(file);

    return 0;
}