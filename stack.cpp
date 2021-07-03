#include <iostream>


// This is a stack data structure program to understand the basics of stack.
// This program will let the user store 5 integers and be able to use the stack functions


using namespace std;


// the class with all of the methods that can be called
class Stack{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for(int i = 0; i<5; i++)
        {
                arr[i]= 0;
        }
    }
    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(top == 4)
            return true;
        else
            return false;
    }
    void push(int val)
    {
        if(isFull())
        {
            cout<< "Stack Overflow" << endl;
        }
        else
        {
            top++; //getting the index on top
            arr[top] = val; // putting the val in the index of the array
        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }
    int count()
    {
        return(top+1);
    }
    int peek(int pos)
    {
        if(isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }else
        {
            return arr[pos]; // getting the value of the index position
        }
    }
    void change( int pos, int val)
    {
        arr[pos] = val;
        cout << "Value changed at the location" << pos << endl;
    }
    void display()
    {
        cout << " All values in the stack are " << endl;
        for(int i = 4; i>=0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

// Main
int main()
{
    // creating the object and using the methods in the object
    Stack s1;
    int option, position, value;

    do
    {
        // The options that are displayed to the screen
        cout << "Select option you want to perform. Enter 0 to exit." << endl;
        cout<< "1. Push" <<endl;
        cout<< "2. Pop"<< endl;
        cout<< "3. isEmpty()" <<endl;
        cout<< "4. isFull()"<< endl;
        cout<< "5. peek()"<< endl;
        cout<< "6. count()"<< endl;
        cout<< "7. change()" <<endl;
        cout<< "8. display()"<< endl;
        cout<< "9. clear screen" <<endl << endl;
    cin >> option;
// This will be the loop of the program
    switch(option){
        case 1:
            cout << "Enter an item to push in the stack" <<endl;
            cin >> value;
            s1.push(value);
            break;
        case 2:
                cout << "Pop function called - Poped Value: " << s1.pop() << endl;
            break;
        case 3:
            if(s1.isEmpty())
                cout << "Stack is empty"<< endl;
            else
                cout << "Stack is not Empty" << endl;
            break;
        case 4:
            if(s1.isFull())
                cout << "Stack is Full" << endl;
            else
                cout << "Stack is not Full" << endl;
            break;
        case 5:
            cout << "Enter the position of the item you want to peek" <<endl;
            cin >> position;
            cout << "Peek Function Called - Value at position "<<position << " is "<< endl << s1.peek(position) << endl;
            break;
        case 6:
            cout << "Count Function Called - number of items in the stack are : " << s1.count() << endl;
        case 7:
            cout << "Change Function called - " <<endl;
            cout << " Enter position of the item you want to change : ";
            cin >> position;
            cout << endl;
            cout << "Enter the value of the item you want to change : ";
            cin >> value;
            s1.change(position, value);
            break;
        case 8:
            cout << "Display function Called - " <<endl;
            s1.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter a valid option number!" <<endl;
    }


    }while(option!=0);


 return 0;
}
