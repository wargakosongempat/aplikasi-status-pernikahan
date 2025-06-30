# aplikasi-status-pernikahan
📝 Aplikasi Status Pernikahan
Aplikasi sederhana berbasis bahasa C untuk mencatat, menampilkan, dan mencari data status pernikahan seseorang berdasarkan inisial.

🔧 Fitur
✅ Tambah data (inisial, nama lengkap, status pernikahan, dan umur)

✅ Tampilkan seluruh data dalam bentuk tabel

✅ Cari data berdasarkan inisial

✅ Validasi input jumlah data agar tidak melebihi batas maksimum (MAX_DATA = 100)

📄 Struktur Data
Menggunakan struktur struct StatusPernikahan:

c
Copy
Edit
struct StatusPernikahan {
    char inisial[100];
    char namaLengkap[300];
    char status[100];
    int umur;
};


▶️ Cara Menjalankan
Kompilasi program:


gcc status_pernikahan.c -o status_pernikahan


Jalankan program:

./status_pernikahan


📌 Catatan
Program berbasis CLI (Command Line Interface).

Input harus sesuai dengan instruksi (misalnya: status harus "Menikah", "Belum Menikah", atau "Cerai").

Maksimum data yang dapat ditampung adalah 100.

📜 Lisensi
Repositori ini tidak memiliki lisensi resmi. Silakan gunakan untuk pembelajaran atau pengembangan pribadi.

🙋 Kontribusi
Pull request dan saran selalu diterima. Silakan fork repositori ini dan kembangkan sesuai kebutuhanmu!
