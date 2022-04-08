#pragma once

#include "Input.h"
#include <iostream>

struct HasilProsess {
    std::vector<Item> items;
    
    int jarak_destinasi;
    int totalHarga;
    int totalOnkir;
    int totalSemuaHarga;
};

class Process {
public:
    HasilProsess ProcessInput(Input input);
};
