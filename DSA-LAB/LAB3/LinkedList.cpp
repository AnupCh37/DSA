#include <iostream>

class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(nullptr) {}
};
class LinkedList
{
private:
    Node *head = NULL;

public:
    void insertBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }
    void insertEnd(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            return;
        }
    }
    void insertAfterNode(int checkval, int insertVal)
    {
        Node *temp = head;
        while (temp->value != checkval)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                std::cout << "Node not found !" << std::endl;
                return;
            }
            if (temp->value == checkval)
            {
                Node *newNode = new Node(insertVal);
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
    void insertBeforeNode(int checkVal, int insertVal)
    {
        if (head == NULL)
        {
            std::cout << "List is Empty" << std::endl;
            return;
        }
        else if (head->value == checkVal)
        {
            insertBeginning(insertVal);
            return;
        }
        else
        {
            Node *prev = head;
            Node *temp = head->next;
            while (temp->value != checkVal)
            {
                prev = temp;
                temp = temp->next;

                if (temp == NULL)
                {
                    std::cout << "Node not found" << std::endl;
                }
                else if (temp->value == checkVal)
                {
                    Node *newNode = new Node(insertVal);
                    newNode->next = temp;
                    prev->next = newNode;
                    return;
                }
            }
        }
    }
    void insertNposition(int pos, int insertVal)
    {

        if (pos < 1)
            std::cout << "Invalid position" << std::endl;
        return;
        if (pos == 1)
        {
            insertBeginning(insertVal);
            return;
        };
        Node *temp = head;
        int count = 1;
        while (count < pos)
        {
            temp = temp->next;
            count++;
        }
    }
};