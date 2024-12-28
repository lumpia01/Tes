#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASIEN 100
#define MAX_DOKTER 20

struct Kamar {
    int nomor;
    char kelas[20];
    int terisi;
    char namaPasien[50];
};

struct JadwalDokter {
    char hari[10];
    char waktu[20];
};

struct Dokter {
    char nama[50];
    char spesialisasi[50];
    struct JadwalDokter jadwal[7];
};

struct Pasien {
    char nama[50];
    int umur;
    char alamat[100];
    char penyakit[50];
    char butuhDokter[5];
    char spesialisDokter[50];
    int lamaMenginap;
    char kelasKamar[20];
    int nomorKamar;
    float biayaKamar;
    float totalBiaya;
};

struct Pasien daftarPasien[MAX_PASIEN];
struct Dokter daftarDokter[MAX_DOKTER] = {
    {"Dr. Andi", "Jantung", 
        {{"Senin", "08:00-14:00"}, {"Rabu", "08:00-14:00"}, {"Jumat", "13:00-20:00"}}},
    {"Dr. Budi", "Paru", 
        {{"Selasa", "08:00-14:00"}, {"Kamis", "13:00-20:00"}, {"Sabtu", "08:00-14:00"}}},
    {"Dr. Citra", "Anak",
        {{"Senin", "13:00-20:00"}, {"Rabu", "13:00-20:00"}, {"Jumat", "08:00-14:00"}}},
    {"Dr. Deni", "Bedah",
        {{"Selasa", "13:00-20:00"}, {"Kamis", "08:00-14:00"}, {"Sabtu", "13:00-20:00"}}}
};

struct Kamar daftarKamar[40] = {
    {101, "VIP", 0, ""}, {102, "VIP", 0, ""}, {103, "VIP", 0, ""}, {104, "VIP", 0, ""}, {105, "VIP", 0, ""},
    {201, "Kelas 1", 0, ""}, {202, "Kelas 1", 0, ""}, {203, "Kelas 1", 0, ""}, {204, "Kelas 1", 0, ""}, {205, "Kelas 1", 0, ""},
    {301, "Kelas 2", 0, ""}, {302, "Kelas 2", 0, ""}, {303, "Kelas 2", 0, ""}, {304, "Kelas 2", 0, ""}, {305, "Kelas 2", 0, ""},
    {401, "Kelas 3", 0, ""}, {402, "Kelas 3", 0, ""}, {403, "Kelas 3", 0, ""}, {404, "Kelas 3", 0, ""}, {405, "Kelas 3", 0, ""}
};

int jumlahKamar = 20;
int jumlahDokter = 4;
int jumlahPasien = 0;

void tampilkanStatusKamar() {
    int vip = 0, kelas1 = 0, kelas2 = 0, kelas3 = 0;
    int vipTerisi = 0, kelas1Terisi = 0, kelas2Terisi = 0, kelas3Terisi = 0;
    
    for (int i = 0; i < jumlahKamar; i++) {
        if (strcmp(daftarKamar[i].kelas, "VIP") == 0) {
            vip++;
            if (daftarKamar[i].terisi) vipTerisi++;
        } else if (strcmp(daftarKamar[i].kelas, "Kelas 1") == 0) {
            kelas1++;
            if (daftarKamar[i].terisi) kelas1Terisi++;
        } else if (strcmp(daftarKamar[i].kelas, "Kelas 2") == 0) {
            kelas2++;
            if (daftarKamar[i].terisi) kelas2Terisi++;
        } else if (strcmp(daftarKamar[i].kelas, "Kelas 3") == 0) {
            kelas3++;
            if (daftarKamar[i].terisi) kelas3Terisi++;
        }
    }
    
    printf("\nStatus Kamar Rumah Sakit:\n");
    printf("VIP    : %d/%d kamar terisi\n", vipTerisi, vip);
    printf("Kelas 1: %d/%d kamar terisi\n", kelas1Terisi, kelas1);
    printf("Kelas 2: %d/%d kamar terisi\n", kelas2Terisi, kelas2);
    printf("Kelas 3: %d/%d kamar terisi\n", kelas3Terisi, kelas3);
    
    printf("\nDetail Kamar yang Terisi:\n");
    for (int i = 0; i < jumlahKamar; i++) {
        if (daftarKamar[i].terisi) {
            printf("Kamar %d (%s): Ditempati oleh %s\n", 
                   daftarKamar[i].nomor, 
                   daftarKamar[i].kelas, 
                   daftarKamar[i].namaPasien);
        }
    }
}

int cariKamarKosong(char *kelas) {
    for (int i = 0; i < jumlahKamar; i++) {
        if (strcmp(daftarKamar[i].kelas, kelas) == 0 && !daftarKamar[i].terisi) {
            return i;
        }
    }
    return -1;
}

float hitungBiayaKamar(char *kelas) {
    if (strcmp(kelas, "VIP") == 0) return 1000000;
    if (strcmp(kelas, "Kelas 1") == 0) return 750000;
    if (strcmp(kelas, "Kelas 2") == 0) return 500000;
    if (strcmp(kelas, "Kelas 3") == 0) return 250000;
    return 0;
}

void tampilkanDaftarHarga() {
    printf("\nDaftar Harga Kamar per Hari:\n");
    printf("1. VIP       : Rp. 1.000.000\n");
    printf("2. Kelas 1   : Rp. 750.000\n");
    printf("3. Kelas 2   : Rp. 500.000\n");
    printf("4. Kelas 3   : Rp. 250.000\n");
}

void tampilkanDaftarDokter() {
    printf("\nDaftar Dokter dan Jadwal Praktik:\n");
    for (int i = 0; i < jumlahDokter; i++) {
        printf("\n%s - Spesialis %s\n", daftarDokter[i].nama, daftarDokter[i].spesialisasi);
        printf("Jadwal Praktik:\n");
        for (int j = 0; j < 3; j++) {
            if (strlen(daftarDokter[i].jadwal[j].hari) > 0) {
                printf("- %s: %s\n", 
                    daftarDokter[i].jadwal[j].hari,
                    daftarDokter[i].jadwal[j].waktu);
            }
        }
    }
}

void daftarPasienBaru() {
    if (jumlahPasien >= MAX_PASIEN) {
        printf("Kapasitas pasien penuh!\n");
        return;
    }

    struct Pasien pasienBaru;
    
    printf("\nPendaftaran Pasien Baru\n");
    printf("Nama: ");
    scanf(" %[^\n]s", pasienBaru.nama);
    
    printf("Umur: ");
    scanf("%d", &pasienBaru.umur);
    
    printf("Alamat: ");
    scanf(" %[^\n]s", pasienBaru.alamat);
    
    printf("Jenis Penyakit: ");
    scanf(" %[^\n]s", pasienBaru.penyakit);
    
    printf("Butuh Dokter? (ya/tidak): ");
    scanf(" %[^\n]s", pasienBaru.butuhDokter);
    
    if (strcmp(pasienBaru.butuhDokter, "ya") == 0) {
        tampilkanDaftarDokter();
        printf("Spesialis Dokter yang dibutuhkan: ");
        scanf(" %[^\n]s", pasienBaru.spesialisDokter);
    }
    
    printf("Lama Menginap (hari): ");
    scanf("%d", &pasienBaru.lamaMenginap);
    
    tampilkanDaftarHarga();
    tampilkanStatusKamar();
    
    printf("Pilih Kelas Kamar (VIP/Kelas 1/Kelas 2/Kelas 3): ");
    scanf(" %[^\n]s", pasienBaru.kelasKamar);
    
    int indexKamar = cariKamarKosong(pasienBaru.kelasKamar);
    if (indexKamar == -1) {
        printf("Maaf, kamar kelas %s sedang penuh.\n", pasienBaru.kelasKamar);
        return;
    }
    
    pasienBaru.nomorKamar = daftarKamar[indexKamar].nomor;
    pasienBaru.biayaKamar = hitungBiayaKamar(pasienBaru.kelasKamar);
    pasienBaru.totalBiaya = pasienBaru.biayaKamar * pasienBaru.lamaMenginap;
    
    // Update status kamar
    daftarKamar[indexKamar].terisi = 1;
    strcpy(daftarKamar[indexKamar].namaPasien, pasienBaru.nama);
    
    daftarPasien[jumlahPasien] = pasienBaru;
    jumlahPasien++;
    
    printf("\nPendaftaran berhasil!\n");
    printf("Nomor Kamar: %d\n", pasienBaru.nomorKamar);
    printf("Total biaya: Rp. %.2f\n", pasienBaru.totalBiaya);
}

void lihatDaftarPasien() {
    if (jumlahPasien == 0) {
        printf("Belum ada pasien terdaftar.\n");
        return;
    }
    
    printf("\nDaftar Pasien Rawat Inap:\n");
    for (int i = 0; i < jumlahPasien; i++) {
        printf("\nPasien %d:\n", i+1);
        printf("Nama: %s\n", daftarPasien[i].nama);
        printf("Umur: %d\n", daftarPasien[i].umur);
        printf("Alamat: %s\n", daftarPasien[i].alamat);
        printf("Penyakit: %s\n", daftarPasien[i].penyakit);
        printf("Nomor Kamar: %d\n", daftarPasien[i].nomorKamar);
        printf("Kelas Kamar: %s\n", daftarPasien[i].kelasKamar);
        printf("Lama Menginap: %d hari\n", daftarPasien[i].lamaMenginap);
        printf("Total Biaya: Rp. %.2f\n", daftarPasien[i].totalBiaya);
        if (strcmp(daftarPasien[i].butuhDokter, "ya") == 0) {
            printf("Spesialis Dokter: %s\n", daftarPasien[i].spesialisDokter);
        }
    }
}

int main() {
    int pilihan;
    
    while (1) {
        printf("\nAplikasi Manajemen Rawat Inap Rumah Sakit\n");
        printf("1. Pendaftaran Pasien Baru\n");
        printf("2. Lihat Daftar Pasien\n");
        printf("3. Lihat Daftar Harga Kamar\n");
        printf("4. Lihat Daftar Dokter\n");
        printf("5. Lihat Status Kamar\n");
        printf("6. Keluar\n");
        printf("Pilih menu (1-6): ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                daftarPasienBaru();
                break;
            case 2:
                lihatDaftarPasien();
                break;
            case 3:
                tampilkanDaftarHarga();
                break;
            case 4:
                tampilkanDaftarDokter();
                break;
            case 5:
                tampilkanStatusKamar();
                break;
            case 6:
                printf("Terima kasih telah menggunakan aplikasi ini.\n");
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
    
    return 0;
}
