#include <iostream>

class Node
{
public:
    int coeff;
    int exp;
    Node *next;
    Node(int co, int ex) : coeff(co), exp(ex), next(nullptr) {}
};

class Polynomial
{
public:
    Node *head;
    Polynomial()
    {
        head = nullptr;
    }

    void createNode(int coeff, int exp)
    {
        Node *newNode = new Node(coeff, exp);

        if (head == nullptr || head->exp < exp)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->exp >= exp)
        {
            temp = temp->next;
        }

        if (temp->exp == exp)
        {
            temp->coeff += coeff;
            delete newNode;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void add(Polynomial p1, Polynomial p2)
    {
        Node *h1 = p1.head;
        Node *h2 = p2.head;

        while (h1 != nullptr && h2 != nullptr)
        {
            if (h1->exp == h2->exp)
            {
                createNode(h1->coeff + h2->coeff, h1->exp);
                h1 = h1->next;
                h2 = h2->next;
            }
            else if (h1->exp > h2->exp)
            {
                createNode(h1->coeff, h1->exp);
                h1 = h1->next;
            }
            else
            {
                createNode(h2->coeff, h2->exp);
                h2 = h2->next;
            }
        }

        while (h1 != nullptr)
        {
            createNode(h1->coeff, h1->exp);
            h1 = h1->next;
        }

        while (h2 != nullptr)
        {
            createNode(h2->coeff, h2->exp);
            h2 = h2->next;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            std::cout << "0" << std::endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->coeff << "x^" << temp->exp;
            temp = temp->next;

            if (temp != nullptr)
            {
                std::cout << " + ";
            }
        }
        std::cout << std::endl;
    }
};

int main()
{
    Polynomial p1, p2, p3;

    p1.createNode(5, 3);
    p1.createNode(3, 2);
    p1.createNode(4, 1);
    p1.createNode(1, 0);

    p2.createNode(5, 3);
    p2.createNode(3, 2);
    p2.createNode(4, 1);
    p2.createNode(1, 0);

    std::cout << "P1: ";
    p1.display();
    std::cout << "P2: ";
    p2.display();

    p3.add(p1, p2);

    std::cout << "Result: ";
    p3.display();

    return 0;
}