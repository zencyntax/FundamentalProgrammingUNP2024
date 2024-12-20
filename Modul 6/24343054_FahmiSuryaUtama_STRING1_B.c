#include <stdio.h>
#include <string.h>

// Deklarasi fungsi gabungkanString
void gabungkanString(char str1[], char str2[], char hasil[]);
void judul();
int main() {
    judul();
    char str1[50];  
    char str2[50];  
    char hasil[100]; 

    printf("Masukkan string pertama: ");
    scanf("%s", str1);

    printf("Masukkan string kedua: ");
    scanf("%s", str2);

    // Menggabungkan string
    gabungkanString(str1, str2, hasil);

    // Menampilkan hasil penggabungan
    printf("Hasil penggabungan string: %s\n", hasil);

    return 0;
}
void judul(){
    printf("===============================================\n");
    printf("|         Menggabungkan 2 Buah String         |\n");
    printf("|---------------------------------------------|\n");
    printf("| PROGRAMMER : FAHMI SURYA UTAMA              |\n");
    printf("| NIM        : 24343054                       |\n");
    printf("===============================================\n");
}
void gabungkanString(char str1[], char str2[], char hasil[]) {
 
    strcpy(hasil, str1);
 
    strcat(hasil, str2);
}
