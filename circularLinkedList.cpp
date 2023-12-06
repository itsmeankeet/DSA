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
        newNode->data = data;
        if(!start)
        {
            start = newNode;
            newNode->next = start;
        }
        return newNode;
    }

    void insertFromFront(int data)
    {
        Node *newNode = createNode(data);
        if(!newNode)
        {
            cout<<"Error in insertFromFront:: Cannot create newnode \n";
        }
        newNode->next = start;
        start->next = newNode;
        start = newNode;
    }

    void deleteFront()
    {
        Node *temp = start;
        if(!temp)
        {
            cout<<"Error in deleteFront::start is null \n";
        }
        Node *previous = temp;
        while(temp->next!=start)
        {
            previous = temp;
            temp = temp->next;
        }
        previous->next = start;
        delete temp;
    }


    void display()
    {
        Node *temp = start;
        if(!temp)
        {
            cout<<"Node is empty \n";
        }
        while(temp->next != start)
        {
            cout<<temp->data<<"->";
            temp= temp->next;
        }
        cout<<"circular \n";
    }

    void dissplay()
    {
        cout<<"Unable to do more than this";
    }
};

circularLinkedList::circularLinkedList(/* args */)
{
    start = NULL;
}

circularLinkedList::~circularLinkedList()
{
}


int main()
{
    circularLinkedList ob;
    cout<<"Creating Node \n";
    ob.createNode(10);
    ob.display();
    cout<<"Inserting in front \n";
    ob.insertFromFront(20);
    ob.display();
    cout<<"Inserting in front \n";
    ob.insertFromFront(30);
    ob.display();
    cout<<"Deleting front \n";
    ob.deleteFront();
    ob.display();
}
