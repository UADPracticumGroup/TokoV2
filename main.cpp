#include "library/Input.h"
#include "library/Output.h"
#include "library/Process.h"

int main() {
    Input input;
    Output output;
    Process process;
    
    bool IsNotEmpty = input.BeganInput();
    //std::printf("[DEBUG] IsEmpty: %d\n", IsEmpty);
    
    if (IsNotEmpty) {
        HasilProsess hasil = process.ProcessInput(input);
        output.Print(hasil);
    } else {
        std::cout << "Anda keluar dari program" << std::endl;
    }
    
    return 0;
}
