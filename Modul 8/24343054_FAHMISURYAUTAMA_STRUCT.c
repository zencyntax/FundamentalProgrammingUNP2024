#include <stdio.h>
#include <string.h>

//defenisi tipe struct secara global
struct tanggal
{
    int hari, bulan, tahun;
};

struct mahasiswa
{
    char nama[30];
    int nim;
    struct tanggal tanggal_lahir;
};

//deklarasi variabel data_mahasiswa secara global
struct mahasiswa data_mahasiswa;
 
int main() {

//  mengisi data kedalan variabel struct data_mahasiswa
    strcpy(data_mahasiswa.nama, "Fahmi Surya Utama");
    data_mahasiswa.nim = 24343054;
    data_mahasiswa.tanggal_lahir.hari = 28;
    data_mahasiswa.tanggal_lahir.bulan = 1;
    data_mahasiswa.tanggal_lahir.tahun = 2006;

//  menampilkan data dalam struct data_mahasiswa
    printf("Nama Mahasiswa: %s\n", data_mahasiswa.nama);
    printf("Nomor Induk Mahasiswa: %d\n", data_mahasiswa.nim);
    printf("Tanggal Lahir: %02d-%02d-%d\n", data_mahasiswa.tanggal_lahir.hari,
     data_mahasiswa.tanggal_lahir.bulan, 
     data_mahasiswa.tanggal_lahir.tahun);

    return 0;
};