/*
    Nama    : Fahmi Surya Utama
    NIM     : 24343054
    Program : Permainan Menara Hanoi
*/

#include <stdio.h>

// Fungsi untuk memindahkan cakram
void hanoi(int n, char asal, char tujuan, char bantu){
    if (n == 1) {
        // Pindahkan cakram dari tiang asal ke tiang tujuan
        printf("Pindahkan cakram 1 dari tiang %c ke tiang %c\n", asal, tujuan);
        return;
    } 
        // Pindahkan n-1 cakram dari tiang asal ke tiang bantu
        hanoi(n - 1, asal, bantu, tujuan);
        // Pindahkan cakram terakhir dari tiang asal ke tiang tujuan
        printf("Pindahkan cakram %d dari tiang %c ke tiang %c\n", n, asal, tujuan);
        // Pindahkan n-1 cakram dari tiang bantu ke tiang tujuan
        hanoi(n - 1, bantu, tujuan, asal);
    }
int main() {

    printf("TUGAS3.c \n");
    printf("=================================\n");
    printf("Nama  : Fahmi Surya Utama \n");
    printf("NIM   : 24343054 \n");
    printf("Judul : Permainan Menara Hanoi\n");
    printf("=================================\n");
    printf("\n");

    int n;

    // Meminta input jumlah cakram dari pengguna
    printf("Masukkan jumlah cakram                     : ");
    scanf("%d", &n);

    // Memanggil fungsi untuk menyelesaikan permainan Menara Hanoi
    printf("Langkah-langkah untuk memindahkan %d cakram:\n", n);
    hanoi(n, 'A', 'C', 'B');  // A = tiang asal, B = tiang bantu, C = tiang tujuan

    return 0;
}
