#pragma once
#include <iostream>

template <typename T>
class Stack
{
private:
    T arr[100];
    int top = -1;

public:
    void push(T var)
    {
        if (top >= 99)
        {
            std::cout << "Stack Overflow!" << std::endl;
            return;
        }
        arr[++top] = var;
    }

    void pop()
    {
        if (top < 0)
        {
            std::cout << "Stack Underflow! Nothing to pop." << std::endl;
            return;
        }
        top--;
    }

    T peek()
    {
        if (top < 0)
        {
            return T();
        }
        return arr[top];
    }

    void view()
    {
        if (top < 0)
        {
            std::cout << "The stack is empty." << std::endl;
            return;
        }
        std::cout << "The stack elements are: ";
        for (int i = 0; i <= top; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    bool empty()
    {
        return top < 0;
    }
};