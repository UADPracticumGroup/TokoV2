#include "../library/Input.h"
#include "../library/Harga.h"

Input::Input() {
    std::cout << "=================================================" << std::endl;
    std::cout << "Rumah makan gorengan yang bikin kaleng" << std::endl;
    std::cout << "Daftar Harga: " << std::endl;
    std::cout << "1. Ayam Geprek    : " << HargaAyamGeprek << std::endl;
    std::cout << "2. Ayam Goreng    : " << HargaAyamGoreng << std::endl;
    std::cout << "3. Udang Goreng   : " << HargaUdangGoreng << std::endl;
    std::cout << "4. Cumi Goreng    : " << HargaCumiGoreng << std::endl;
    std::cout << "5. Ayam Bakar     : " << HargaAyamBakar << std::endl;
    std::cout << "=================================================" << std::endl;

    pilihan = std::vector<Item>(5);
}

bool Input::BeganInput() {
    ClearInput();
    std::cout << "Masukan nomor makanan yang akan di pesan (ketik 0 untuk keluar)" << std::endl;

    while (true) {
        std::cout << "Masukan nomor makanan: ";
        int nomor;
        std::cin >> nomor;
        if (nomor == 0) {
            break;
        }

        if (nomor < 1 || nomor > 5) {
            std::cout << "Nomor makanan tidak ada" << std::endl;
            continue;
        }

        // check if any index contain number from nomor
        bool found = false;
        for (int i = 0; i < pilihan.size(); i++) {
            if (pilihan[i].nomor == nomor) {
                found = true;
                break;
            }
        }

        if (found) {
            std::cout << "Nomor makanan sudah dipilih" << std::endl;
            continue;
        }

        int jumlah;
        std::cout << "Masukan jumlah makanan: ";
        std::cin >> jumlah;

        Item item;
        item.nomor = nomor;
        item.jumlah = jumlah;
        pilihan.push_back(item);
    }

    // check if input is complete empty
    bool isEmpty = true;

    for (int i = 0; i < pilihan.size(); i++) {
        if (pilihan[i].jumlah != 0) {
            isEmpty = false;
            break;
        }
    }

    if (!isEmpty) {
        std::cout << "Masukan jarak rumah anda: "; std::cin >> jarak_destinasi;
    }
    
    return isEmpty == false ? true : false;
}

// not in use right now
void Input::ClearInput() {
    pilihan.clear();
}
