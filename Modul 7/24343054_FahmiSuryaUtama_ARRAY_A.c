#include <stdio.h>

void judul() {
    printf("Nama  : Fahmi Surya Utama\n");
    printf("NIM   : 24343054\n");
}

int main() {
    judul();
    int angka[5] = {10, 20, 30, 40, 50};
    for(int i = 0; i < 5; i++) {
        printf("Angka ke-%d: %d\n", i + 1, angka[i]);
    }
    return 0;
}
