#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pesanan {
    char nama_makanan[50];
    int jumlah;
    float harga;
    struct Pesanan* next;
};

// Head untuk linked list pesanan
struct Pesanan* head = NULL;

// Fungsi untuk menambah pesanan
void tambahPesanan(char* nama_makanan, int jumlah, float harga) {
    struct Pesanan* new_pesanan = (struct Pesanan*)malloc(sizeof(struct Pesanan));
    if (new_pesanan == NULL) {
        printf("Memori tidak cukup untuk menambah pesanan baru!\n");
        return;
    }

    strcpy(new_pesanan->nama_makanan, nama_makanan);
    new_pesanan->jumlah = jumlah;
    new_pesanan->harga = harga;
    new_pesanan->next = head;
    head = new_pesanan;
    printf("Pesanan berhasil ditambahkan!\n");
}

// Fungsi untuk menghapus pesanan pertama (yang sudah selesai)
void hapusPesanan() {
    if (head == NULL) {
        printf("Tidak ada pesanan yang bisa dihapus!\n");
        return;
    }

    struct Pesanan* temp = head;
    head = head->next;
    free(temp);
    printf("Pesanan pertama berhasil dihapus!\n");
}

// Fungsi untuk menampilkan semua pesanan
void tampilkanPesanan() {
    if (head == NULL) {
        printf("Tidak ada pesanan saat ini!\n");
        return;
    }

    struct Pesanan* current = head;
    printf("Daftar Pesanan:\n");
    printf("-------------------------\n");
    while (current != NULL) {
        printf("Nama Makanan: %s\n", current->nama_makanan);
        printf("Jumlah: %d\n", current->jumlah);
        printf("Harga: %.2f\n", current->harga);
        printf("-------------------------\n");
        current = current->next;
    }
}

// Fungsi untuk menghitung total pendapatan
float hitungTotalPendapatan() {
    float total = 0;
    struct Pesanan* current = head;

    while (current != NULL) {
        total += current->jumlah * current->harga;
        current = current->next;
    }

    return total;
}

// Fungsi untuk mengedit pesanan berdasarkan nama makanan
void editPesanan(char* nama_makanan) {
    struct Pesanan* current = head;
    while (current != NULL) {
        if (strcmp(current->nama_makanan, nama_makanan) == 0) {
            printf("Pesanan ditemukan. Silakan masukkan data baru.\n");
            printf("Masukkan Jumlah Baru: ");
            scanf("%d", &current->jumlah);
            printf("Masukkan Harga Baru: ");
            scanf("%f", &current->harga);
            printf("Pesanan berhasil diupdate!\n");
            return;
        }
        current = current->next;
    }
    printf("Pesanan dengan nama '%s' tidak ditemukan!\n", nama_makanan);
}

// Fungsi utama
int main() {
    int pilihan;
    char nama_makanan[50];
    int jumlah;
    float harga;

    do {
        printf("\n=== Sistem Manajemen Pesanan Restoran ===\n");
        printf("1. Tambah Pesanan\n");
        printf("2. Hapus Pesanan Pertama\n");
        printf("3. Tampilkan Daftar Pesanan\n");
        printf("4. Hitung Total Pendapatan\n");
        printf("5. Edit Pesanan\n");
        printf("6. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan Nama Makanan: ");
                scanf(" %[^\n]", nama_makanan);
                printf("Masukkan Jumlah: ");
                scanf("%d", &jumlah);
                printf("Masukkan Harga per Unit: ");
                scanf("%f", &harga);
                tambahPesanan(nama_makanan, jumlah, harga);
                break;

            case 2:
                hapusPesanan();
                break;

            case 3:
                tampilkanPesanan();
                break;

            case 4:
                printf("Total Pendapatan: %.2f\n", hitungTotalPendapatan());
                break;

            case 5:
                printf("Masukkan Nama Makanan yang Ingin Diedit: ");
                scanf(" %[^\n]", nama_makanan);
                editPesanan(nama_makanan);
                break;

            case 6:
                printf("Keluar dari program...\n");
                break;

            default:
                printf("Opsi tidak valid. Silakan coba lagi.\n");
                break;
        }
    } while (pilihan != 6);

    // Bersihkan semua pesanan sebelum keluar
    struct Pesanan* current = head;
    while (current != NULL) {
        struct Pesanan* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
