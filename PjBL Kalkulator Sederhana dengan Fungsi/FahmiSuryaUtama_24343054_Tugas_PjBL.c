#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi untuk menampilkan identitas program
void judul() {
    printf("===============================================\n");
    printf("|               KALKULATOR SEDERHANA          |\n");
    printf("|---------------------------------------------|\n");
    printf("| PROGRAMMER : FAHMI SURYA UTAMA              |\n");
    printf("| NIM        : 24343054                       |\n");
    printf("===============================================\n");
}

// Fungsi untuk operasi matematika
float tambah(float a, float b) { return a + b; }
float kurang(float a, float b) { return a - b; }
float kali(float a, float b) { return a * b; }
float bagi(float a, float b) {
    if (b != 0) return a / b;
    printf("Error: Pembagian dengan nol tidak diperbolehkan.\n");
    return 0;
}

int main() {
    FILE *inputFile, *outputFile;
    int pilihan;
    float angka1, angka2, hasil;
    int pertama = 1;
    clock_t start_time, end_time;  // Variabel untuk mengukur waktu
    double execution_time;

    do {
        if (pertama) {
            judul();
            pertama = 0;
        }

        printf("\n=== Kalkulator Sederhana ===\n");
        printf("1. Penjumlahan\n");
        printf("2. Pengurangan\n");
        printf("3. Perkalian\n");
        printf("4. Pembagian\n");
        printf("5. Baca dari file\n");
        printf("6. Keluar\n");
        printf("Pilih operasi (1-6): ");
        scanf("%d", &pilihan);

        if (pilihan >= 1 && pilihan <= 4) {
            printf("Masukkan angka pertama: ");
            scanf("%f", &angka1);
            printf("Masukkan angka kedua: ");
            scanf("%f", &angka2);
        }

        // Mulai pengukuran waktu
        start_time = clock();

        switch (pilihan) {
            case 1:
                hasil = tambah(angka1, angka2);
                printf("Hasil: %.2f\n", hasil);
                break;
            case 2:
                hasil = kurang(angka1, angka2);
                printf("Hasil: %.2f\n", hasil);
                break;
            case 3:
                hasil = kali(angka1, angka2);
                printf("Hasil: %.2f\n", hasil);
                break;
            case 4:
                hasil = bagi(angka1, angka2);
                if (angka2 != 0) printf("Hasil: %.4f\n", hasil);
                break;
            case 5:
                inputFile = fopen("input_7.txt", "r");
                if (inputFile == NULL) {
                    printf("File input_7.txt tidak dapat dibuka!\n");
                    break;
                }
                outputFile = fopen("output_7.txt", "w");
                if (outputFile == NULL) {
                    printf("File output_7.txt tidak dapat dibuat!\n");
                    fclose(inputFile);
                    break;
                }
                char operatorChar;
                while (fscanf(inputFile, "%f %c %f", &angka1, &operatorChar, &angka2) != EOF) {
                    switch (operatorChar) {
                        case '+':
                            hasil = tambah(angka1, angka2);
                            fprintf(outputFile, "%.2f %c %.2f = %.4f\n", angka1, operatorChar, angka2, hasil);
                            break;
                        case '-':
                            hasil = kurang(angka1, angka2);
                            fprintf(outputFile, "%.2f %c %.2f = %.4f\n", angka1, operatorChar, angka2, hasil);
                            break;
                        case '*':
                            hasil = kali(angka1, angka2);
                            fprintf(outputFile, "%.2f %c %.2f = %.4f\n", angka1, operatorChar, angka2, hasil);
                            break;
                        case '/':
                            hasil = bagi(angka1, angka2);
                            if (angka2 != 0) {
                                fprintf(outputFile, "%.2f %c %.2f = %.4f\n", angka1, operatorChar, angka2, hasil);
                            } else {
                                fprintf(outputFile, "%.2f %c %.2f = Error: Pembagian dengan nol\n", angka1, operatorChar, angka2);
                            }
                            break;
                        default:
                            fprintf(outputFile, "%.2f %c %.2f = Error: Operator tidak valid\n", angka1, operatorChar, angka2);
                            break;
                    }
                }
                fclose(inputFile);
                fclose(outputFile);
                printf("Operasi selesai, hasil disimpan di output_7.txt\n");
                break;
            case 6:
                printf("Terima kasih telah menggunakan kalkulator.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

        // Catat waktu selesai dan hitung waktu eksekusi
        end_time = clock();
        execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Waktu eksekusi: %.6f detik\n", execution_time);

    } while (pilihan != 6);

    return 0;
}
