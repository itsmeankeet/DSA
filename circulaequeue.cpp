#include<iostream>
#include<cstdlib>
using namespace std;

class circulaequeue
{
private:
    int capacity;
    int rear, front;
    int *cap;
public:
    circulaequeue(int data);
    ~circulaequeue();
    bool isfull()
    {
        if((rear+1)%(capacity)==front)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if((front == rear)){
            return true;
        }
        return false;
    }

    bool enqueue(int data);
    int dequeue();
    void display();
};

circulaequeue::circulaequeue(int data)
{
    capacity = data;
    front = rear =-1 ;
    cap = new int [data];
}

circulaequeue::~circulaequeue()
{
    cout<<"Destructor Called"<<endl;
    delete[] cap;
}

bool circulaequeue::enqueue(int data)
{
    // if(isfull())
    // {
    //     cout<<"The queue is full"<<endl;
    //     return false;
    // }
    if(front == -1 && rear == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % capacity;
    cap[rear] = data;
    cout<<"Data enqueued succesfully"<<endl;
}

int circulaequeue::dequeue()
{
    if(isEmpty())
    {
        cout<<"The queue is empty"<<endl;
        return 0;
    }
    int data = cap[front];
    front = (front + 1)%capacity;
    return data;
    cout<<endl;
}

void circulaequeue::display()
{
    cout<<"The values in queue are: \n";
    for(int i = front; i<= rear; i++)
    {
        cout<<cap[i]<<"\t";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int size;
    cout<<"Enter the size of the queue \n";
    cin>>size;
    circulaequeue ob1(size);
    while (1)
    {
        int choice;
        cout<<"1. Enqueue()\n2. Dequeue()\n3. Display()\n4. Exit()\n";
        cout<<"Enter your choice: \n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int data;
            if(ob1.isfull())
            {
                cout<<"Cannot enqueue the value the queue is full \n";
            }
            else{
                cout<<"Enter the data to be enqued\n";
                cin>>data;
                ob1.enqueue(data);
            }
            break;
        
        case 2:
            cout<<"Dequeing Values..\n";
            cout<<"\n"<<ob1.dequeue()<<endl;
            cout<<"Dequeued Succesfully"<<endl;
            break;

        case 3:
            ob1.display();
            break;
        case 4:
            cout<<"Program Exiting...";
            exit(0);
        default:
            cout<<"Invlaid Input";
            break;
        }

    }
    
    return 0;
}
