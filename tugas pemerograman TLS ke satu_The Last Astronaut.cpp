#include <iostream>

int main() {
    int n, k;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> n;
    std::cout << "Masukkan nilai K: ";
    std::cin >> k;

    // Menggunakan dynamic array karena tidak menggunakan <vector>
    bool* statusAlive = new bool[n + 1];
    for (int i = 1; i <= n; i++) {
        statusAlive[i] = true;
    }

    int remaining = n;
    int current_idx = 1;

    std::cout << "Urutan eliminasi: ";
    while (remaining > 1) {
        int count = 0;
        
        // Mencari posisi orang ke-K yang masih hidup
        while (count < k) {
            if (statusAlive[current_idx]) {
                count++;
                if (count == k) break;
            }
            current_idx++;
            if (current_idx > n) current_idx = 1;
        }

        // Eliminasi
        statusAlive[current_idx] = false;
        std::cout << current_idx << " ";
        remaining--;

        // Update nilai K sesuai nomor yang tereliminasi
        if (current_idx % 2 == 0) {
            k += 2;
        } else {
            k -= 1;
        }
        
        // Aturan K tidak boleh kurang dari 2
        if (k < 2) {
            k = 2;
        }

        // Pindah ke orang berikutnya yang masih hidup untuk persiapan siklus baru
        while (!statusAlive[current_idx] && remaining > 0) {
            current_idx++;
            if (current_idx > n) current_idx = 1;
        }
    }

    std::cout << "\n";
    
    // Cari astronot terakhir
    for (int i = 1; i <= n; i++) {
        if (statusAlive[i]) {
            std::cout << "Astronot terakhir yang bertahan: " << i << "\n";
            break;
        }
    }

    delete[] statusAlive;
    
     //system pause di gunakan karena aku menggunakan devc++ app lama yg membuat ada penyakit load cepet jadi setelah hasil keluar harus di tambah pause supaya tidak langsung forcedclose
    system("pause");
    
    return 0;
}
