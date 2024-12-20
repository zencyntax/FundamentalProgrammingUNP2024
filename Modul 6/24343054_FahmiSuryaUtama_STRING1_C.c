#include <stdio.h>
#include <string.h>
int membandingkanString(char str1[], char str2[]);
void judul();
int main() {
    judul();
    char str1[100];  
    char str2[100];  
    // Meminta input dari pengguna
    printf("Masukkan string pertama: ");
    scanf("%s", str1); 

    printf("Masukkan string kedua: ");
    scanf("%s", str2); 
    // pemanggilan fungsi untuk variabel "hasil"
    int hasil = membandingkanString(str1, str2);
    // penampilan hasil perbandingan string
    if (hasil == 0) {
        printf("Kedua string sama.....\n");
    } else {
        printf("Kedua string tidak sama.....\n");
    }
    return 0;
}
int membandingkanString(char str1[], char str2[]) {
    //membandingkan dua string
    return strcmp(str1, str2);
}
void judul(){
    printf("===============================================\n");
    printf("|         Membandingkan 2 Buah String         |\n");
    printf("|---------------------------------------------|\n");
    printf("| PROGRAMMER : FAHMI SURYA UTAMA              |\n");
    printf("| NIM        : 24343054                       |\n");
    printf("===============================================\n");
}