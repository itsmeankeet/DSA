#include<iostream>
using namespace std;

class queue
{
    private:
    	int SIZE;
        int front, rear;
        int *que;
    public:
        queue(int data);
        bool enqueue(int data);
        int dequeue();
        bool isFull();
        bool isEmpty();
        void display();
};
queue::queue(int data)
{
	SIZE = data;
    front = rear = -1;
    que = new int[data];
}

bool queue::enqueue(int data)
{
    if(isFull())
    {
        cout<<"Queue is full unable to enque"<<endl;
        return false;
    }
    if(front ==-1 && rear == -1){
        front = front + 1;
    }
    rear = rear + 1;
    que[rear] = data;
    cout<< "Data inserted"<<endl;
}

bool queue::isFull()
{
    return((rear == SIZE -1));
}

bool queue::isEmpty()
{
    return((rear<front)||(rear==-1 && front== -1));
}

int queue::dequeue()
{
    if(isEmpty())
    {
        cout<<"The queue is empty"<<endl;
        return 0;
    }
    int data = que[front];
    front++;
    cout<<"Dequeue Successfull"<<endl;
    return data;
}

void queue::display()
{
    cout<<"The value in queue are:"<<endl;
    for(int i = front; i<=rear; i++)
    {
        cout<<que[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int cap;
    cout<<"Enter the size of queue"<<endl;
    cin>>cap;
    queue ob2(cap);
    cout<<"Enter the operation to perform:"<<endl;
    int choice;
    while (1)
    {
        cout<<"1. Enqueue"<<endl<<"2. Dequeue \n3. Display \n4. Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            int num;
            cout<<"Enter the number to insert:"<<endl;
            cin>>num;
            ob2.enqueue(num);
            break;
        
        case 2:
            ob2.dequeue();
            break;
        
        case 3:
            ob2.display();
            break;

        case 4:
            cout<<"Program Exiting..."<<endl;
            return 0;
            break;
        default:
            cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}
