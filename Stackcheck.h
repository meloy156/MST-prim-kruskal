#pragma once

#include <deque>
#include <vector>
#include <string>

// Структура для метода Pop
template <typename T>
struct Result_Pop {
    int code_return;
    T symbol;

    Result_Pop() : code_return(0), symbol() {};
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
    // return 0 - 
    Result_Pop<T> POP();

    // размер элементов
    std::size_t size() const;
};


#include "Stackcheck.tpp"