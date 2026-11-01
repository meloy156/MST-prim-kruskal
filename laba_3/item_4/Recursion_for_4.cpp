#include "Recursion_for_4.h"


// 1. Определение статической структуры
Recursion_function Recursion_for_4::r_function;


Recursion_for_4::Recursion_for_4(const size_t count)
    : count(count), stack(new Stack<long>())
    {
    for (size_t i = 1; i <= count; ++i) {
        stack->PUSH(r_function.function(i));
    }
}

Recursion_for_4::~Recursion_for_4() {
    delete stack;
}


void Recursion_for_4::ADD() {
    stack->PUSH(r_function.function(((long) stack->size()) + 1));
    this->count++;
}


void Recursion_for_4::ADD(int count) {
    int current_size = stack->size();
    for (int i = current_size + 1; i <= current_size + count; ++i) {
        stack->PUSH(r_function.function(i));
        this->count++;
    }
}


size_t Recursion_for_4::size() {
    return count;
}


void Recursion_for_4::print_array() {
    std::cout << "Все элементы стэка: " << std::endl;
    stack->to_stream();
    std::cout << std::endl;
}


void Recursion_for_4::print_recursion_function() {
    std::cout << "Функция по которой задается рекурсия: " << std::endl;
    r_function.return_function();
}

