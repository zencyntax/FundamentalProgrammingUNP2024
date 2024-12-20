#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int bilangan, sisaBagi;

    // Input bilangan
    printf("Menentukan bilangan bulat ganjil atau genap\n");
    printf("Masukan bilangan bulat: ");
    scanf("%d", &bilangan);

    // Proses menghitung sisa bagi dengan operator sisa bagi, jika sisa bagi == 0 maka bilangan genap
    sisaBagi = bilangan % 2;

    // Proses pengecekan dengan pengambilan keputusan if/else, dan output hasilnya
    if (sisaBagi == 0) {
        printf("Bilangan %d merupakan bilangan genap.\n", bilangan);
    } else {
        printf("Bilangan %d merupakan bilangan ganjil.\n", bilangan);
    }

    return 0;
}
