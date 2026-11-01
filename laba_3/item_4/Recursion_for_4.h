#pragma once

#include <iostream>
#include <format>
#include <cmath>

#include "Stack_FIFO/Stackcheck.h"

struct Recursion_function {
    long function(const long n) {
        return std::pow(2, (n+1)) / std::pow(3.0, (n-1));
    }

    std::string return_function() {
        return "2^(n+1) / 3^(n-1)";
    }
};


class Recursion_for_4 {
private:
    size_t count;
    Stack<long>* stack;


public:
    static Recursion_function r_function;

    Recursion_for_4(): count(0), stack(new Stack<long>()) {};
    Recursion_for_4(const size_t count);

    ~Recursion_for_4();

    // Добавить элемент
    void ADD();
    void ADD(int count);

    // размер
    size_t size();

    // вывести весь стэк c 1 элемента
    void print_array();

    // рекусривная функция которая задает стек
    void print_recursion_function();
};