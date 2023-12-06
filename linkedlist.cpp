#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class linkedlist
{
private:
    Node *head;

public:
    linkedlist(/* args */);
    ~linkedlist();

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

    void insertIntoBeginning(int data)
    {
        Node *newNode = createNode(data);
        if (!newNode)
        {
            cout << "Unable to enter the value \n";
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtRear(int data)
    {
        Node *newNode = createNode(data);
        if (!newNode)
        {
            cout << "Unable to insert data at rear \n";
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }

    void deleteAtBeginig()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteInRear()
    {
        Node *temp = head;
        if (!head)
        {
            cout << "Deletion In rear error occured \n";
        }
        Node *previous = temp;
        while (temp->next != NULL)
        {
            previous = temp;
            temp = temp->next;
        }
        previous->next = NULL;
        delete temp;
    }

    void addBeforeValue(int data, int value)
    {
        Node *newnode = createNode(data);
        if (!newnode)
        {
            cout << "Error in creating newnode in add before value function \n";
        }
        Node *temp = head;
        if (!temp)
        {
            cout << "Error in addbefore function \n";
        }
        Node *previous = temp;
        if (head->data == value)
        {
            insertIntoBeginning(data);
        }
        else
        {
            while (temp->data != value)
            {
                previous = temp;
                temp = temp->next;
                if (temp == NULL)
                {
                    cout << "Value not found \n";
                }
            }
        }
        previous->next = newnode;
        newnode->next = temp;
    }

    void deleteData(int value)
    {
        Node *temp = head;
        if (!head)
        {
            cout << "Error in delete before data \n";
        }
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *previous = temp;
            while (temp->data != value)
            {
                previous = temp;
                temp = temp->next;
                if (temp == NULL)
                {
                    cout << "Value not found \n";
                }
            }
            previous->next = temp->next;
            delete temp;
        }
    }

    void display()
    {
        Node *temp = head;
        if (!temp)
        {
            cout << "Error in display function \n";
        }
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "null \n";
    }
};

linkedlist::linkedlist(/* args */)
{
    head = NULL;
}

linkedlist::~linkedlist()
{
    cout << "Destructor" << endl;
}
int main(int argc, char const *argv[])
{
    int data;
    linkedlist ob1;
    int choice;
    int value;
    while (1)
    {
        cout << "Enter your choice \n 1. CreateNode \n 2. Insert In Beginning \n 3. Insert In rear \n 4. Delete from Beginning \n 5. Delete from rear \n 6. Insert Before Value \n 7. Delete Value \n 8. Exit() \n  \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number to be added \n";
            cin >> data;
            ob1.createNode(data);
            break;
        case 2:
            cout << "Enter the number to be inserted in front\n";
            cin >> data;
            ob1.insertIntoBeginning(data);
            break;
        case 3:
            cout << "Enter the number to be inserted at rear\n";
            cin >> data;
            ob1.insertAtRear(data);
            break;
        case 4:
            cout << "Deleting the number of Node from front \n";
            ob1.deleteAtBeginig();
            break;
        case 5:
            cout << "Deleting the number of Node from rear\n";
            ob1.deleteInRear();
            break;

        case 6:
            cout << "Enter the number to be added before of node: \n";
            cin >> value;
            cout << "Enter the data to be added: \n";
            cin >> data;
            ob1.addBeforeValue(data, value);
            break;
        case 7:
            cout << "Enter the value of node to be deleted \n";
            cin >> value;
            ob1.deleteData(value);
            break;
        case 8:
            cout << "Thank you \n";
            cout << "Programm Exiting..";
            return 0;

        default:
            cout << "Invalid Input" << endl;
        }
        ob1.display();
    }
    return 0;
}
