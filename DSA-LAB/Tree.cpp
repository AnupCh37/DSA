class Node
{
public:
    int data;
    Node *left, *right;
    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

int main()
{
 int arr[]={1,2,3,4,5,6,6,6,6};
 int n =sizeof(arr)/sizeof(arr[0]);
 Node * root=insertLevelOrder(arr,0,n);
}