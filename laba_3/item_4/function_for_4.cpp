#include "function_for_4.h"

void function_for_4() {

    bool flag_continue = true;

    do {
        std::string string;
        std::size_t size;
        std::cout << "||| Выберите кол-во элементов в стеке |||" << std::endl;
        std::cout << "Выход: q" << std::endl;
        
        std::getline(std::cin, string);
        if (string == "q") {
            flag_continue = false;
            break;
        } else {
            try {
                size = std::stol(string);
            } catch (...) {
                std::cout << "Введено не число" << std::endl;
            }
        }

        Recursion_for_4 recurs(size);
        std::cout << std::endl;

        recurs.print_array();
        

        std::cout << "Пробуем добавить элемент" << std::endl;
        recurs.ADD();

        recurs.print_array();
    
    } while (flag_continue);
}
    