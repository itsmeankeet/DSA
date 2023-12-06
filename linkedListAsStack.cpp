#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class linkedListAsStack
{
public:
    Node *head;

public:
    linkedListAsStack()
    {
        head = NULL;
    }

    Node *createNode(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (!head)
        {
            head = newNode;
        }
        return newNode;
    }

    void insertInFront(int data)
    {
        Node *newNode = createNode(data);
        if (!newNode)
        {
            cout << "Error in entering the value at the beginning \n";
        }
        newNode->next = head;
        head = newNode;
    }

    void deleteAtFront()
    {
        Node *temp = head;
        if (!temp)
        {
            cout << "Error in deletion at the front \n";
        }
        head = head->next;
        delete temp;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    void deleteOldNode()
    {
        Node *temp = head;
        Node *nextNode;
        while (temp != NULL)
        {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = NULL;
    }

    ~linkedListAsStack()
    {
        Node *current = head;
        Node *next;
        while (current != NULL)
        {
            next = current->next;
            delete current;
            current = next;
        }
        cout << "Destructor" << endl;
    }
};

int main()
{
    linkedListAsStack ob1;
    while (1)
    {
        cout << "Enter your choice \n";
        int choice;
        cout << "1. Create new Node\n2. Insert in the beginning of the Node\n3. Deletion of the front Node\n4. Exit\n";
        cin >> choice;
        int data;
        switch (choice)
        {
        case 1:
            cout << "Enter the data to be inserted: \n";
            cin >> data;
            ob1.createNode(data);
            cout << "Node created with value: " << data << endl;
            break;
        case 2:
            cout << "Enter the data to be inserted\n";
            cin >> data;
            cout << "1. Press Y to continue in the Node created already\n2. To create a new Node press N: ";
            char a;
            cin >> a;
            if (ob1.head != NULL)
            {
                if (a == 'Y' || a == 'y')
                {
                    cout << "Continuing in the old Node \n";
                    ob1.insertInFront(data);
                }
                else if (a == 'N' || a == 'n')
                {
                    ob1.deleteOldNode();
                    ob1.createNode(data);
                    break;
                }
            }
            else
            {
                cout << "Node is not created\n";
                return 0;
            }
            break;
        case 3:
            ob1.deleteAtFront();
            cout << "Front Node deleted.\n";
            break;
        case 4:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid Input\n";
        }
        ob1.display();
    }

    return 0;
}
