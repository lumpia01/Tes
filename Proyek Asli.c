#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASIEN 100
#define MAX_DOKTER 50
#define MAX_KAMAR 50

// struktur untuk menyimpan data pasien

typedef struct{
    char nama[50];
    int umur;
    char alamat[100];
    char penyaktit[50];
    int lamainap;
    char jeniskamar[20];
    int status; // 1 =aktif, 0 = keluar
} Pasien;

// Struktur untuk menyimpan data dokter
typedef struct{
    char hari[10];
    char waktu[20];    // jadwal dokter
} JadwalDokter;

typedef struct{
    char nama[50];
    char spesialis[50];     //dokter
    JadwalDokter jadwal[7];

} Dokter;
// kamarr
typedef struct{
int nomor;
char kelas[20];
int status; // 1= terisi. 0=kosong
char namapasien[50];
int lamapenggunaan;
} Kamar;

//STruktur data GLoballllllll sheesh

Pasien daftarpasien[MAX_PASIEN];
Dokter daftardokter[MAX_DOKTER]{
    {"Dr. Andi", "Jantung",
        {{"Senin", "08:00 - 14:00"}, {"Rabu", "08:00-14:00"}, {"Jumat", "13:00-20:00"}}
    },
    {"Dr. Budi", "Paru",
        {{"Selasa", "08:00-14:00"},{"Kamis","13:00-20:00"}{"Sabtu", "08:00-14:00"}}
    },
    {"Dr. Citra","Anak"
        {{"Senin", "13:00-20:00"},{"Selasa", "13:00-18:00"},{"Jumat", "08:00-14:00"}}
    },
    {"Dr. Nolen", "Bedah"
        {{"Selasa", "09:00-14:00"},{"Rabu","11:00-19:00"},{"Jumat","08:30-14:50"}}
    }
    {"Dr. Rahmat", "Kanker"
        {{"Senin", "08:00-14:00"},{"Rabu","08:00-17:00"},{"Kamis","09:30-15:30"}}
    }
};
Kamar daftarkamar[MAX_KAMAR]{
    {101, "VIP", 0, ""}, {102, "VIP", 0, ""}, {103, "VIP", 0, ""}, {104, "VIP", 0, ""}, {105, "VIP", 0, ""},
    {201, "Kelas 1", 0, ""}, {202, "Kelas 1", 0, ""}, {203, "Kelas 1", 0, ""}, {204, "Kelas 1", 0, ""}, {205, "Kelas 1", 0, ""},
    {301, "Kelas 2", 0, ""}, {302, "Kelas 2", 0, ""}, {303, "Kelas 2", 0, ""}, {304, "Kelas 2", 0, ""}, {305, "Kelas 2", 0, ""},
    {401, "Kelas 3", 0, ""}, {402, "Kelas 3", 0, ""}, {403, "Kelas 3", 0, ""}, {404, "Kelas 3", 0, ""}, {405, "Kelas 3", 0, ""}
};

int jumlahpasien = 0;
int jumlahkamar = 20;
int jumlahdokter = 5;

// fungsi bukan nabi boy wajarr!!!

//mengelola data pasien

void tambahPasien(){
    if(jumlahpasien >= MAX_PASIEN){
        printf("Pasien di Kamar Rawat Inap Rumah Sakit Sudah Penuh!!");
        return;
    }

printf("============ Pendaftaran Pasien Baru Rawat INAP ============");
printf("Nama :");
scanf(" %[^\n]s", pasien[jumlahpasien].nama);
printf("Umur :");
scanf(" %d", &pasien[jumlahpasien].umur);
printf("Alamat :");
scanf(" %[^\n]s", pasien[jumlahpasien].alamat);
printf("Jenis Penyakit :");
scanf(" %[^\n]s", pasien[jumlahpasien].penyakit);
printf("Butuh Dokter Spesialis? (y/n): ");
scanf(" %c", &pasien[jumlahPasien].butuhSpesialis);
printf("Lama Menginap (hari):");
scanf(" %d", &pasien[jumlahpasien].lamainap);
printf("Jenis Kamar (VIP/Kelas1/Kelas2/Kelas3): ");
scanf(" %[^\n]s", pasien[jumlahPasien].jenisKamar);
}
