#include <iostream>


// This is a Queue data structure program to understand the basics of Queue.
// This program will let the user store 5 integers and be able to use the Queue functions


using namespace std;

//class that emplements the Queue Data Structure
class Queue{
private:
    int front;
    int rear;
    int arr[5];

public:
    Queue()
    {
        front = -1;
        rear = -1;
        for(int i = 0; i<5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(rear == 4)
            return true;
        else
            return false;
    }
    void enqueue(int val)
    {
        if(isFull()){
            cout << "Queue is full" <<endl;
        return;
    }else if(isEmpty())
    {
        rear = 0;
        front = 0;
        arr[rear] = val;
    }
    else
    {
        rear++;
        arr[rear] = val;
    }
    }

    int dequeue()
    {
        int x;
        if(isEmpty())
        {
        cout << "Queue is empty" <<endl;
        return 0;
        }

    else if(front == rear)
    {
        x = arr[front];
        arr[front] = 0;
        rear = - 1;
        front = - 1;
        return x;
    }
    else
    {
        x = arr[front];
        arr[front] = 0;
        front++;
        return x;
    }
    }
    int count()
    {
        return (rear-front+1);
    }
    void display()
    {
        cout << "All the values in the Queue are : " <<endl;
        for(int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

// Main
int main()
{
    // creating the object and using the methods in the object
    Queue q1;
    int option, value;

    do
    {
        // The options that are displayed to the screen
        cout << "Select option you want to perform. Enter 0 to exit." << endl;
        cout<< "1. Enqueue()" <<endl;
        cout<< "2. Dequeue()"<< endl;
        cout<< "3. isEmpty()" <<endl;
        cout<< "4. isFull()"<< endl;
        cout<< "5. count()"<< endl;
        cout<< "6. display()"<< endl;
        cout<< "7. clear screen" <<endl << endl;
    cin >> option;



// This will be the loop of the program
    switch(option){
        case 1:
            cout << "Enqueue function called! \nEnter an item to Enqueue in the Queue" <<endl;
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << "Dequeue function called! \nDequeued value is : " << q1.dequeue() << endl;
            break;
        case 3:
            if(q1.isEmpty())
            cout << "Queue is Empty" <<endl;
            else
                cout << "Queue is not Empty" << endl;
            break;
        case 4:
            if(q1.isFull())
            cout << "Queue is full" << endl;
            else
                cout << "Queue is not full" <<endl;
            break;
        case 5:
            cout << "Count Operation \n Count of items in the Queue : " << q1.count() <<endl;
            break;
        case 6:
            cout << "Display function Called - " <<endl;
            q1.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter a valid option number!" <<endl;
    }

    }while(option!=0);

 return 0;
}
