#pragma once

#include <iostream>
#include <vector>

struct Item {
    int nomor;
    int jumlah;
};

class Input {
public:
    Input();

    std::vector<Item> pilihan;
    int jarak_destinasi;
    bool BeganInput();
    void ClearInput();
};
