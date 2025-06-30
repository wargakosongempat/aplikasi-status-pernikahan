#include <stdio.h>             // Untuk fungsi input/output standar (printf, scanf)
#include <string.h>            // Untuk fungsi manipulasi string (fgets, strcmp, strcspn)

#define MAX_DATA 100           // Batas maksimum jumlah data yang dapat disimpan

// Struktur untuk menyimpan data status pernikahan
struct StatusPernikahan {
    char inisial[100];         // Inisial nama orang
    char namaLengkap[300];     // Nama lengkap orang
    char status[100];          // Status pernikahan: Menikah, Belum Menikah, Cerai
    int umur;                  // Umur orang tersebut
};

// Fungsi untuk menambahkan data ke dalam array
void inputStatus(struct StatusPernikahan *data, int *jumlah) {
    int n;
    printf("Masukkan jumlah data yang ingin ditambahkan: ");
    scanf("%d", &n);
    while (getchar() != '\n'); // Bersihkan newline dari buffer

    if (*jumlah + n > MAX_DATA) { // Cek apakah jumlah melebihi kapasitas maksimum
        printf("Jumlah total melebihi kapasitas maksimal (%d data). Input dibatalkan.\n", MAX_DATA);
        return;
    }

    for (int i = *jumlah; i < *jumlah + n; i++) {
        printf("\nData ke-%d:\n", i + 1);

        printf("Inisial: ");
        fgets(data[i].inisial, sizeof(data[i].inisial), stdin);       // Baca input inisial
        data[i].inisial[strcspn(data[i].inisial, "\n")] = '\0';       // Hapus newline

        printf("Nama Lengkap: ");
        fgets(data[i].namaLengkap, sizeof(data[i].namaLengkap), stdin); // Baca nama lengkap
        data[i].namaLengkap[strcspn(data[i].namaLengkap, "\n")] = '\0';

        printf("Status Pernikahan (Menikah/Belum Menikah/Cerai): ");
        fgets(data[i].status, sizeof(data[i].status), stdin);         // Baca status pernikahan
        data[i].status[strcspn(data[i].status, "\n")] = '\0';

        printf("Umur: ");
        scanf("%d", &data[i].umur);                                   // Baca umur
        while (getchar() != '\n');                                    // Bersihkan buffer
    }

    *jumlah += n;     // Tambahkan jumlah data setelah input selesai
}

// Fungsi untuk menampilkan seluruh data dalam bentuk tabel
void tampilStatus(struct StatusPernikahan *data, int jumlah) {
    if (jumlah == 0) {  // Jika belum ada data
        printf("Data status pernikahan masih kosong.\n");
        return;
    }

    // Header tabel
    printf("\n=== DAFTAR STATUS PERNIKAHAN ===\n");
    printf("+-----+------------+-------------------------------+------------------------+------+\n");
    printf("| No  | Inisial    | Nama Lengkap                 | Status Pernikahan      | Umur |\n");
    printf("+-----+------------+-------------------------------+------------------------+------+\n");

    // Isi tabel
    for (int i = 0; i < jumlah; i++) {
        printf("| %-3d | %-10s | %-29s | %-22s | %-4d |\n",
               i + 1,
               data[i].inisial,
               data[i].namaLengkap,
               data[i].status,
               data[i].umur);
    }

    // Footer tabel
    printf("+-----+------------+-------------------------------+------------------------+------+\n");
}

// Fungsi untuk mencari data berdasarkan inisial
void cariStatus(struct StatusPernikahan *data, int jumlah) {
    char inisialCari[100];
    printf("Masukkan inisial yang dicari: ");
    fgets(inisialCari, sizeof(inisialCari), stdin);              // Input inisial pencarian
    inisialCari[strcspn(inisialCari, "\n")] = '\0';              // Hapus newline

    int ketemu = 0;
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(data[i].inisial, inisialCari) == 0) {         // Bandingkan dengan data
            // Jika ditemukan, tampilkan datanya
            printf("\nData ditemukan:\n");
            printf("Inisial        : %s\n", data[i].inisial);
            printf("Nama Lengkap   : %s\n", data[i].namaLengkap);
            printf("Status         : %s\n", data[i].status);
            printf("Umur           : %d tahun\n", data[i].umur);
            ketemu = 1;
            break;
        }
    }

    if (!ketemu) {                                               // Jika tidak ditemukan
        printf("Data dengan inisial %s tidak ditemukan.\n", inisialCari);
    }
}

// Fungsi utama program
int main() {
    struct StatusPernikahan data[MAX_DATA]; // Array untuk menyimpan data
    int jumlah = 0;                         // Jumlah data saat ini
    int pilih;                              // Pilihan menu dari user
    char ulang;                             // Untuk mengulang menu

    do {
        // Tampilkan menu utama
        printf("\n===== MENU STATUS PERNIKAHAN =====\n");
        printf("1. Tambah Data Status Pernikahan\n");
        printf("2. Tampilkan Semua Data\n");
        printf("3. Cari Status Berdasarkan Inisial\n");
        printf("4. Selesai & Keluar\n");
        printf("Pilih menu (1-4): ");
        scanf("%d", &pilih);
        while (getchar() != '\n'); // Bersihkan buffer

        // Eksekusi menu berdasarkan pilihan
        switch (pilih) {
            case 1:
                inputStatus(data, &jumlah);        // Tambah data baru
                break;
            case 2:
                tampilStatus(data, jumlah);        // Tampilkan semua data
                break;
            case 3:
                cariStatus(data, jumlah);          // Cari data berdasarkan inisial
                break;
            case 4:
                printf("Terima kasih telah menggunakan aplikasi Status Pernikahan!\n");
                return 0;                          // Keluar dari program
            default:
                printf("Pilihan tidak valid, coba lagi.\n"); // Input salah
        }

        // Tanya user apakah ingin kembali ke menu
        printf("\nKembali ke menu? (y/n): ");
        scanf(" %c", &ulang);                     // Input karakter
        while (getchar() != '\n');                // Bersihkan newline
    } while (ulang == 'y' || ulang == 'Y');       // Ulang jika jawaban y/Y

    printf("Program selesai.\n");                 // Tampilkan akhir program
    return 0;
}


