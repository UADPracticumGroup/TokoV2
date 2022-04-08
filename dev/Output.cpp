#include "../library/Output.h"
#include "../library/Process.h"
#include "../library/Harga.h"

#include <fstream>

void Output::Print(HasilProsess process) {
    std::string output;
    output.append("======================================\n");
    output.append("Rumah makan gorengan yang bikin kaleng Versi 2\n");
    output.append("======================================\n");
    output.append("Menu yang di pesan:\n");
    
    do {
        // ambil item dari paling item paling belakang
        Item item = process.items.back();
        switch (item.nomor) {
            case 1: {
                output.append(" - Ayam Geprek   : ");
                output.append(std::to_string(item.jumlah) + " (Total harga: " + std::to_string(HargaAyamGeprek * item.jumlah) + ")\n");
                break;
            }
                
            case 2: {
                output.append(" - Ayam Goreng   : ");
                output.append(std::to_string(item.jumlah) + " (Total harga: " + std::to_string(HargaAyamGoreng * item.jumlah) + ")\n");
                break;
            }
                
            case 3: {
                output.append(" - Udang Goreng  : ");
                output.append(std::to_string(item.jumlah) + " (Total harga: " + std::to_string(HargaUdangGoreng * item.jumlah) + ")\n");
                break;
            }
                
            case 4: {
                output.append(" - Cumi Goreng   : ");
                output.append(std::to_string(item.jumlah) + " (Total harga: " + std::to_string(HargaCumiGoreng * item.jumlah) + ")\n");
                break;
            }
                
            case 5: {
                output.append(" - Ayam Bakar    : ");
                output.append(std::to_string(item.jumlah) + " (Total harga: " + std::to_string(HargaAyamBakar * item.jumlah) + ")\n");
                break;
            }
        }

        // hapus item dari index paling belakang
        process.items.pop_back();
    } while (process.items.empty() == false);
    
    output.append("Biaya onkir  : " + std::to_string(process.totalOnkir) + " (jarak dari rumah anda ke rumah makan: " + std::to_string(process.jarak_destinasi) + ")\n");
    output.append("Harga Makanan: " + std::to_string(process.totalHarga) + "\n");
    output.append("Total harga  : " + std::to_string(process.totalSemuaHarga) + "\n");
    output.append("======================================\n");

    std::fstream file_stream("struk.txt", std::ios::out | std::ios::trunc);
    file_stream << output;
    file_stream.close();
  
    std::cout << output;
}
