#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class circularLinkedList
{
private:
    Node *start;
public:
    circularLinkedList(/* args */);
    ~circularLinkedList();
    Node *createNode(int data)
    {
        Node *newNode = new Node();
    }
};

circularLinkedList::circularLinkedList(/* args */)
{
    start = NULL;
}

circularLinkedList::~circularLinkedList()
{
}
