#include "../library/Process.h"
#include "../library/Harga.h"

HasilProsess Process::ProcessInput(Input input) {
    std::cout << "=================================================" << std::endl;
    std::cout << "Daftar makanan yang dipesan: " << std::endl;
    for (int i = 0; i < input.pilihan.size(); i++) {
        switch (input.pilihan[i].nomor) {
            case 1:
                std::cout << "Ayam Geprek   : " << input.pilihan[i].jumlah << std::endl;
                break;
            case 2:
                std::cout << "Ayam Goreng   : " << input.pilihan[i].jumlah << std::endl;
                break;
            case 3:
                std::cout << "Udang Goreng  : " << input.pilihan[i].jumlah << std::endl;
                break;
            case 4:
                std::cout << "Cumi Goreng   : " << input.pilihan[i].jumlah << std::endl;
                break;
            case 5:
                std::cout << "Ayam Bakar    : " << input.pilihan[i].jumlah << std::endl;
                break;
        }
    }
    
    std::cout << std::endl;
    std::cout << "Jarak anda: " << input.jarak_destinasi << std::endl;
    std::cout << "=================================================" << std::endl;
    
    std::cout << std::endl;
    HasilProsess hasil = {};
    
    hasil.jarak_destinasi = input.jarak_destinasi;

    int totalOnkir = 0;
    if (input.jarak_destinasi < 3) {
        totalOnkir += 15000;
    } else {
        totalOnkir += 25000;
    }

    int totalHargaMakanan = 0;
    for (int i = 0; i < input.pilihan.size(); i++) {
        switch (input.pilihan[i].nomor) {
            case 1:
                totalHargaMakanan += HargaAyamGeprek * input.pilihan[i].jumlah;
                break;
            case 2:
                totalHargaMakanan += HargaAyamGoreng * input.pilihan[i].jumlah;
                break;
            case 3:
                totalHargaMakanan += HargaUdangGoreng * input.pilihan[i].jumlah;
                break;
            case 4:
                totalHargaMakanan += HargaCumiGoreng * input.pilihan[i].jumlah;
                break;
            case 5:
                totalHargaMakanan += HargaAyamBakar * input.pilihan[i].jumlah;
                break;
        }
    }
    
    hasil.totalSemuaHarga = totalHargaMakanan + totalOnkir;
    hasil.totalOnkir = totalOnkir;
    hasil.totalHarga= totalHargaMakanan;
    hasil.items = input.pilihan;

    return hasil;
}
