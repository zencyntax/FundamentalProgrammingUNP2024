#include <stdio.h>
#include <string.h>

//Deklarasi Fungsi
int hitungPanjangString(char string []){
    return strlen(string);
}

void judul(){
    printf("===============================================\n");
    printf("|            Menhitung Panjang String         |\n");
    printf("|---------------------------------------------|\n");
    printf("| PROGRAMMER : FAHMI SURYA UTAMA              |\n");
    printf("| NIM        : 24343054                       |\n");
    printf("===============================================\n");

}
int hitungPanjangString(char string []);
int main (){

    judul();
    char string [20];

    printf("Masukkan String Yang Akan Di Hitung:");
    scanf("%s", string);

    int panjangString=hitungPanjangString(string);
    printf("Jumlah Karakter Dalam String Adalah: %d\n",panjangString );
    return 0;
}