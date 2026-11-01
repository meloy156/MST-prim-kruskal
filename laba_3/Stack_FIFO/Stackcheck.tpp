#pragma once

template <typename T>
Stack<T>::Stack(std::vector<T>& v)
    : stack(new std::deque<T>(v.begin(), v.end()))
{}

template <typename T>
Stack<T>::Stack(std::string& s)
    : stack(new std::deque<T>(s.begin(), s.end()))
{}

template <typename T>
Stack<T>::~Stack() {
    delete stack;
}

template <typename T>
bool Stack<T>::PUSH(T c) {
    try {
        stack->push_front(c);
    } catch (...) {
        return 0;
    }

    return 1;
}

template <typename T>
Result_Pop<T> Stack<T>::POP() {
    Result_Pop<T> r;
    if (stack->empty()) {
        r.code_return = 1;
        return r;
    }

    r.symbol = stack->back();
    stack->pop_back();
    r.code_return = 0;
    return r;
}

template <typename T>
std::size_t Stack<T>::size() const {
    return stack->size();
}


template <typename T>
void Stack<T>::to_stream() {
    for (auto it = stack->rbegin(); it != stack->rend(); ++it) {
        std::cout << *it << ", ";
    }

    std::cout << std::endl;
}
