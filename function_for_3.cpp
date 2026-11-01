#include "function_for_3.h"

void function_for_3() {
    std::string string;
    
    bool flag_for_do = true;
    do {
        // Интрефейс
        std::cout << "Введите строку: " << std::endl;
        std::cout << "выход: q" << std::endl;
        std::cin >> string;
        std::cout << std::endl;
        if (string == "q") {
            flag_for_do = false;
            break;
        }
        // проверка
        if (check_for_3(string)) {
            std::cout << "Скобки расставленны верно" << std::endl;
        } else {
            std::cout << "Выражение неверное: скобки расставленны неверно" << std::endl;
        }

    } while(flag_for_do);
}




bool check_for_3(const std::string& s) {
    Stack<char> stack;

    for (char c : s) {
        if (c == '(') {
            stack.PUSH(c);
        } else if (c == ')') {
            if (stack.size() == 0) return false;
            stack.POP();
        }
    }
    return stack.size() == 0;
}