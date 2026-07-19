#include <iostream>
#include <vector>
class Node
{
public:
    int data;
    Node *left, *right;
};
Node *createNode(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
Node *insert(Node *root, int val)
{

    if (root == nullptr)
        return createNode(val);
    else if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(Node *root)
{
    if (!root)
        return;
    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
}
int main()
{
    std::vector<int> nums = {45, 12, 34, 33, 10, 20, 15, 67, 56, 70, 48, 26};
    Node *root = nullptr;
    for (const auto num : nums)
    {
        root = insert(root, num);
    }

    inOrder(root);
    std::cout << std::endl;
    postOrder(root);
    std::cout << std::endl;
    preOrder(root);
    std::cout << std::endl;
}