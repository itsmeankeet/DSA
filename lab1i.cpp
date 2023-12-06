#include<iostream>
using namespace std;
#define size 5
class stack
{
private:
   int *stk;
   int tos;
public:
    stack()
    {
        tos = 0;
        stk = new int[size];
    }

    bool isFull()
    {
        if(tos == size)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if(tos == -1)
        {
            return true;
        }
        return false;
    }

    bool Push(int data)
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;
            return false;
        }
        tos++;
        stk[tos]= data;
        return true;
    }

    int PoP()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int data = stk[tos];
        tos--;
        return data;
    }

    bool display()
    {
        if(isEmpty())
        {
            cout<<"The stack is empty"<<endl;
            return false;
        }
        cout<<"The stack values are:"<<endl;
        for(int a = tos; a>0; a--)
        {
            cout<<stk[a]<<endl;
        }
    }
};
int main()
{
    stack s;
    int choice;
    while(1)
    {
        cout<<"Enter your choice:"<<endl;
        cout<<"1. Push"<<endl<<"2. PoP"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the number to be pushed:"<<endl;
            int a;
            cin>>a;
            s.Push(a);
            cout<<"Pushed Sucessfully";
            break;
        case  2:
            s.PoP();
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout<<"Program ending..."<<endl;
            return 0;
        
        default:
            cout<<"Invalid Input"<<endl;
            break;
        }
    }
}
