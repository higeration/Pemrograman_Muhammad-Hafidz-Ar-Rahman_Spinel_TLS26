#include <iostream>

// User-defined function untuk panjang string (tanpa <string> / strlen)
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// User-defined function untuk mengubah A-Z menjadi 1-26
int charToInt(char c) {
    return c - 'A' + 1;
}

// User-defined function untuk mengubah 1-26 menjadi A-Z dengan siklus
char intToChar(int val) {
    while (val > 26) {
        val -= 26;
    }
    return (char)(val - 1 + 'A');
}

int main() {
    char message[1000];
    std::cout << "Masukkan pesan (Kapital, tanpa spasi): ";
    std::cin >> message;

    int len = stringLength(message);
    if (len == 0) return 0;

    char result[1000];
    result[0] = message[0]; // Karakter pertama tidak berubah

    // Pergeseran karakter sandi
    for (int i = 1; i < len; i++) {
        int shiftValue = charToInt(message[i - 1]);
        int currentValue = charToInt(message[i]);
        int newValue = currentValue + shiftValue;
        
        result[i] = intToChar(newValue);
    }
    result[len] = '\0'; // Tambahkan terminator pada array char hasil

    std::cout << "Pesan tersandi: " << result << "\n";
    
       //system pause di gunakan karena aku menggunakan devc++ app lama yg membuat ada penyakit load cepet jadi setelah hasil keluar harus di tambah pause supaya tidak langsung forcedclose
    system("pause");

    return 0;
}
