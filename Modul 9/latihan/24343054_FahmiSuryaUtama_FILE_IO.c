#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    char nama[50];
    char nim[15];
    char jurusan[30];
};

int main() {
    struct Mahasiswa mahasiswa[100];
    int jumlahMahasiswa = 0;

    // Membaca file input.txt
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("File input.txt tidak dapat dibuka!\n");
        return 1;
    }

    // Memeriksa apakah file kosong
    if (fgetc(inputFile) == EOF) {
        printf("File input.txt kosong.\n");
    } else {
        rewind(inputFile); // Kembalikan pointer file ke awal
        while (fscanf(inputFile, "%49s %14s %29s", mahasiswa[jumlahMahasiswa].nama, mahasiswa[jumlahMahasiswa].nim, mahasiswa[jumlahMahasiswa].jurusan) == 3) {
            jumlahMahasiswa++;
            if (jumlahMahasiswa >= 100) {
                printf("Data mahasiswa penuh, hanya membaca 100 data pertama.\n");
                break;
            }
        }
    }
    fclose(inputFile);

    // Menampilkan data yang telah dibaca
    printf("Data Mahasiswa dari File:\n");
    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("Nama: %s, NIM: %s, Jurusan: %s\n", mahasiswa[i].nama, mahasiswa[i].nim, mahasiswa[i].jurusan);
    }

    // Meminta input data mahasiswa baru
    if (jumlahMahasiswa < 100) {
        printf("Masukkan data mahasiswa baru:\n");
        printf("Nama: ");
        scanf(" %49[^\n]", mahasiswa[jumlahMahasiswa].nama);
        printf("NIM: ");
        scanf(" %14s", mahasiswa[jumlahMahasiswa].nim);
        printf("Jurusan: ");
        scanf(" %29[^\n]", mahasiswa[jumlahMahasiswa].jurusan);
        jumlahMahasiswa++;
    } else {
        printf("Data mahasiswa sudah penuh, tidak dapat menambahkan data baru.\n");
    }

    // Menulis seluruh data ke file output.txt
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("File output.txt tidak dapat dibuat!\n");
        return 1;
    }

    for (int i = 0; i < jumlahMahasiswa; i++) {
        fprintf(outputFile, "%s %s %s\n", mahasiswa[i].nama, mahasiswa[i].nim, mahasiswa[i].jurusan);
    }
    fclose(outputFile);

    printf("Data berhasil disimpan ke output.txt!\n");
    return 0;
}
