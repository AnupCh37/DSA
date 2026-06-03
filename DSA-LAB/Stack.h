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
        std::cout << "Pushed: " << var << std::endl;
    }

    void pop()
    {
        if (top < 0)
        {
            std::cout << "Stack Underflow! Nothing to pop." << std::endl;
            return;
        }
        std::cout << "Popped: " << arr[top] << std::endl;
        top--;
    }

    T peek()
    {
        if (top < 0)
        {
            std::cout << "Stack is empty!" << std::endl;
            return T();
        }
        std::cout << "The top element is: " << arr[top] << std::endl;
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
};
