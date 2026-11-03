#include "item_3/function_for_3.h"
#include "item_4/function_for_4.h"
#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    // 3 Пункт запускч
    function_for_3();


    // 4 пункт запуск
    function_for_4();
}