#pragma once

#include <deque>
#include <vector>
#include <string>

// Структура для метода Pop
// code_return = 0 - все норм символ есть
// code_return = 1 - стек пуст
template <typename T>
struct Result_Pop {
    int code_return;
    T symbol;

    Result_Pop() : code_return(1), symbol() {};
};


template <typename T>
class Stack {
private:
    std::deque<T>* stack;
    
public:
    Stack() : stack(new std::deque<T>) {};

    Stack(std::vector<T>& v);
    Stack(std::string& s);

    ~Stack();

    // положить символ в очередь
    // param char - символ который положить
    // return - 0 все ок
    //          1 стек переполнен
    bool PUSH(T c);
    
    // взять вершину стэка
    Result_Pop<T> POP();

    // размер элементов
    std::size_t size() const;

    // Полный вывод в консоль стенка
    void to_stream();
};


#include "Stackcheck.tpp"