#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

    Node *find(int key) const
    {
        Node *cur = head;
        while (cur)
        {
            if (cur->data == key)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList()
    {
        Node *cur = head;
        while (cur)
        {
            Node *t = cur;
            cur = cur->next;
            delete t;
        }
    }

    bool isEmpty() const { return head == nullptr; }

    void insertAtBeginning(int val)
    {
        Node *n = new Node(val);
        if (isEmpty())
        {
            head = tail = n;
        }
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
        }
        cout << "  insertAtBeginning(" << val << ")\n";
    }

    void insertAtEnd(int val)
    {
        Node *n = new Node(val);
        if (isEmpty())
        {
            head = tail = n;
        }
        else
        {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
        cout << "  insertAtEnd(" << val << ")\n";
    }

    void insertAfter(int key, int val)
    {
        Node *cur = find(key);
        if (!cur)
        {
            cout << "  insertAfter: " << key << " not found.\n";
            return;
        }
        Node *n = new Node(val);
        n->next = cur->next;
        n->prev = cur;
        if (cur->next)
            cur->next->prev = n;
        else
            tail = n;
        cur->next = n;
        cout << "  insertAfter(" << key << ", " << val << ")\n";
    }

    void insertBefore(int key, int val)
    {
        Node *cur = find(key);
        if (!cur)
        {
            cout << "  insertBefore: " << key << " not found.\n";
            return;
        }
        Node *n = new Node(val);
        n->prev = cur->prev;
        n->next = cur;
        if (cur->prev)
            cur->prev->next = n;
        else
            head = n;
        cur->prev = n;
        cout << "  insertBefore(" << key << ", " << val << ")\n";
    }

    void deleteFromBeginning()
    {
        if (isEmpty())
        {
            cout << "  deleteFromBeginning: list is empty.\n";
            return;
        }
        Node *t = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        cout << "  deleteFromBeginning() -> removed " << t->data << "\n";
        delete t;
    }

    void deleteFromEnd()
    {
        if (isEmpty())
        {
            cout << "  deleteFromEnd: list is empty.\n";
            return;
        }
        Node *t = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        cout << "  deleteFromEnd() -> removed " << t->data << "\n";
        delete t;
    }

    void deleteAfter(int key)
    {
        Node *cur = find(key);
        if (!cur)
        {
            cout << "  deleteAfter: " << key << " not found.\n";
            return;
        }
        if (!cur->next)
        {
            cout << "  deleteAfter: no node after " << key << ".\n";
            return;
        }
        Node *t = cur->next;
        cur->next = t->next;
        if (t->next)
            t->next->prev = cur;
        else
            tail = cur;
        cout << "  deleteAfter(" << key << ") -> removed " << t->data << "\n";
        delete t;
    }

    void deleteBefore(int key)
    {
        Node *cur = find(key);
        if (!cur)
        {
            cout << "  deleteBefore: " << key << " not found.\n";
            return;
        }
        if (!cur->prev)
        {
            cout << "  deleteBefore: no node before " << key << ".\n";
            return;
        }
        Node *t = cur->prev;
        cur->prev = t->prev;
        if (t->prev)
            t->prev->next = cur;
        else
            head = cur;
        cout << "  deleteBefore(" << key << ") -> removed " << t->data << "\n";
        delete t;
    }

    void display(const string &label = "") const
    {
        cout << "  ";
        if (!label.empty())
            cout << "[" << label << "] ";
        if (isEmpty())
        {
            cout << "NULL (empty)\n";
            return;
        }
        cout << "NULL <-> ";
        Node *cur = head;
        while (cur)
        {
            cout << cur->data;
            cout << (cur->next ? "<->" : " <-> NULL\n");
            cur = cur->next;
        }
    }
};

int main()
{

    DoublyLinkedList dll;

    cout << "\n-- a) Insert at beginning --\n";
    dll.insertAtBeginning(30);
    dll.insertAtBeginning(20);
    dll.insertAtBeginning(10);
    dll.display("list so far");

    cout << "\n-- b) Insert at end --\n";
    dll.insertAtEnd(40);
    dll.insertAtEnd(50);
    dll.display("list so far");

    cout << "\n-- c) Insert after node with value 30 --\n";
    dll.insertAfter(30, 35);
    dll.display("after inserting 35 after 30");

    cout << "\n-- d) Insert before node with value 40 --\n";
    dll.insertBefore(40, 37);
    dll.display("after inserting 37 before 40");

    cout << "\n=== 4.2 DELETION OPERATIONS ===\n";
    cout << "\n  Starting state:\n";    
    dll.display();

    cout << "\n-- e) Delete from beginning --\n";
    dll.deleteFromBeginning();
    dll.display("after delete from beginning");

    cout << "\n-- f) Delete from end --\n";
    dll.deleteFromEnd();
    dll.display("after delete from end");

    cout << "\n-- g) Delete node after 30 --\n";
    dll.deleteAfter(30);
    dll.display("after deleting node after 30");

    cout << "\n-- h) Delete node before 40 --\n";
    dll.deleteBefore(40);
    dll.display("after deleting node before 40");

    cout << "\n=== EDGE CASES ===\n";
    cout << "\n-- Delete before head (should warn) --\n";
    dll.deleteBefore(20);

    cout << "\n-- Delete after tail (should warn) --\n";
    dll.deleteAfter(40);

    cout << "\n  Final list:\n";
    dll.display();

    return 0;
}
