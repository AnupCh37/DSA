// Perform push and pop operations in stack
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
        std::cout << "Pushed" << std::endl;
        arr[++top] = var;
    }
    void pop()
    {
        std::cout << "Popped" << std::endl;
        top--;
    }
    T peek()
    {
        std::cout << "The top of the element:" << arr[top] << std::endl;
    };
    void view()
    {
        std::cout << "The stack element is :" << std::endl;
        for (size_t i = 0; i <= top; i++)
        {
            std::cout << arr[i] << std::endl;
        }
    }
};
int main()
{
    Stack<char> S;
    S.push('H');
    S.push('A');
    S.push('R');
    S.push('I');
    S.view();
    S.pop();
    S.pop();
    S.view();
    S.peek();
}