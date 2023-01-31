#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


char lagi, gamau;

struct Mahasiswa {
    string nama;
    string nim;
    string alamat;
    int tahunMasuk;
};

vector<Mahasiswa> mahasiswa;

void tambahMahasiswa() {
    Mahasiswa m;
    cout << "Masukkan nama mahasiswa : ";
    cin >> m.nama;
    cout << "Masukkan NIM mahasiswa : ";
    cin >> m.nim;
    cout << "Masukkan alamat mahasiswa : ";
    cin >> m.alamat;
    cout << "Masukkan tahun masuk mahasiswa : ";
    cin >> m.tahunMasuk;
    mahasiswa.push_back(m);
    cout << "Mahasiswa berhasil ditambahkan!" << endl;
}

void ubahMahasiswa() {
    string nim;
    cout << "Masukkan NIM mahasiswa yang akan diubah : ";
    cin >> nim;
    bool found = false;
    for (int i = 0; i < mahasiswa.size(); i++) {
        if (mahasiswa[i].nim == nim) {
            found = true;
            cout << "Masukkan nama mahasiswa : ";
            cin >> mahasiswa[i].nama;
            cout << "Masukkan NIM mahasiswa : ";
            cin >> mahasiswa[i].nim;
            cout << "Masukkan alamat mahasiswa : ";
            cin >> mahasiswa[i].alamat;
            cout << "Masukkan tahun masuk mahasiswa : ";
            cin >> mahasiswa[i].tahunMasuk;
            cout << "Mahasiswa berhasil diubah!" << endl;
        }
    }
    if (!found) {
        cout << "Mahasiswa tidak ditemukan!" << endl;
    }
}

void hapusMahasiswa() {
    string nim;
    cout << "Masukkan NIM mahasiswa yang akan dihapus : ";
    cin >> nim;
    bool found = false;
    for (int i = 0; i < mahasiswa.size(); i++) {
        if (mahasiswa[i].nim == nim) {
            found = true;
            mahasiswa.erase(mahasiswa.begin() + i);
            cout << "Mahasiswa berhasil dihapus!" << endl;
        }
    }
    if (!found) {
        cout << "Mahasiswa tidak ditemukan!" << endl;
    }
}

void tampilkanSemuaMahasiswa() {
    cout << "Data mahasiswa : " << endl;
    for (int i = 0; i < mahasiswa.size(); i++) {
        cout << "Nama : " << mahasiswa[i].nama << endl;
        cout << "NIM : " << mahasiswa[i].nim << endl;
        cout << "Alamat : " << mahasiswa[i].alamat << endl;
        cout << "Tahun Masuk : " << mahasiswa[i].tahunMasuk << endl;
        cout << endl;
    }
}

void presensiKuliah() {
    string nama, nim, mataKuliah;
    int timestamp;
    cout << "Masukkan nama mahasiswa : ";
    cin >> nama;
    cout << "Masukkan NIM mahasiswa : ";
    cin >> nim;
    cout << "Masukkan mata kuliah : ";
    cin >> mataKuliah;
    cout << "Masukkan timestamp : ";
    cin >> timestamp;
    cout << "Kehadiran berhasil dicatat!" << endl;
}

void tampilkanMahasiswaKuliah() {
    string mataKuliah;
    cout << "Masukkan mata kuliah : ";
    cin >> mataKuliah;
    cout << "Data mahasiswa di mata kuliah " << mataKuliah << " : " << endl;
    for (int i = 0; i < mahasiswa.size(); i++) {
        cout << "Nama : " << mahasiswa[i].nama << endl;
        cout << "NIM : " << mahasiswa[i].nim << endl;
        cout << "Alamat : " << mahasiswa[i].alamat << endl;
        cout << "Tahun Masuk : " << mahasiswa[i].tahunMasuk << endl;
        cout << endl;
    }
}

void urutkanMahasiswaKuliah() {
    string mataKuliah;
    cout << "Masukkan mata kuliah : ";
    cin >> mataKuliah;
    cout << "Data mahasiswa di mata kuliah " << mataKuliah << " : " << endl;
    sort(mahasiswa.begin(), mahasiswa.end(), [](Mahasiswa a, Mahasiswa b) {
        return a.nama < b.nama;
    });
    for (int i = 0; i < mahasiswa.size(); i++) {
        cout << "Nama : " << mahasiswa[i].nama << endl;
        cout << "NIM : " << mahasiswa[i].nim << endl;
        cout << "Alamat : " << mahasiswa[i].alamat << endl;
        cout << "Tahun Masuk : " << mahasiswa[i].tahunMasuk << endl;
        cout << endl;
    }
}

void cariMahasiswa() {
    string keyword;
    cout << "Masukkan keyword : ";
    cin >> keyword;
    bool found = false;
    for (int i = 0; i < mahasiswa.size(); i++) {
        if (mahasiswa[i].nama.find(keyword) != string::npos ||
            mahasiswa[i].nim.find(keyword) != string::npos ||
            mahasiswa[i].alamat.find(keyword) != string::npos) {
            found = true;
            cout << "Nama : " << mahasiswa[i].nama << endl;
            cout << "NIM : " << mahasiswa[i].nim << endl;
            cout << "Alamat : " << mahasiswa[i].alamat << endl;
            cout << "Tahun Masuk : " << mahasiswa[i].tahunMasuk << endl;
            cout << endl;
        }
    }
    if (!found) {
        cout << "Mahasiswa tidak ditemukan!" << endl;
    }
}

int main() {
    int pilihan;

    do {
        system("cls");
        cout << "Menu : " << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Ubah Mahasiswa" << endl;
        cout << "3. Hapus Mahasiswa" << endl;
        cout << "4. Tampilkan Seluruh Data Mahasiswa" << endl;
        cout << "5. Presensi" << endl;
        cout << "6. Tampilkan Seluruh Data Mahasiswa di Kuliah Tertentu" << endl;
        cout << "7. Urutkan Data Mahasiswa di Kuliah Tertentu" << endl;
        cout << "8. Cari Mahasiswa" << endl;
        cout << "9. Keluar" << endl;
        cout << "Masukkan pilihan Anda : ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahMahasiswa();
                break;
            case 2:
                ubahMahasiswa();
                break;
            case 3:
                hapusMahasiswa();
                break;
            case 4:
                tampilkanSemuaMahasiswa();
                break;
            case 5:
                presensiKuliah();
                break;
            case 6:
                tampilkanMahasiswaKuliah();
                break;
            case 7:
                urutkanMahasiswaKuliah();
                break;
            case 8:
                cariMahasiswa();
                break;
        }
    cout << endl;
    cout << "Mau input lagi apa engga ? ";
    cin >> lagi;
    }while (lagi == 'Y' || lagi == 'y' || gamau == 'N' || gamau == 'n');
    cout << gamau << "y udh kalo g mau";
    return 0;
}
