
//Bradley Allen
//This is a program that will implement the different operations of Singly Linked List
//This is for more understanding of how the Singly linked list works

#include <iostream>
using namespace std;

//The class node for the holding of data, keys ,and pointer info
class Node{
    //everthing in public for simplicity instead of getter functions!
    public:
        int key;
        int data;
        //pointer to point to next node
        Node* next;
       //constructor
        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
        }
        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};//end of Node class

class SinglyLinkedList{
    public:
        //head of the list location
        Node* head;

        SinglyLinkedList()
        {
            head = NULL;
        }
        //pass by address
        SinglyLinkedList(Node *n)
        {
            head = n;
        }

        //returns the pointer// 1. Checks if node exists using key value.
        Node* nodeExists(int k)
        {
            Node* temp = NULL;
            Node* ptr = head;
            while(ptr != NULL)
            {
                //if the node matches k
                if(ptr->key==k)
                {
                    temp = ptr;
                }
                //else go to next node
                ptr = ptr -> next;
            }
            return temp;
        }

        //Append a node to the list aka add// 2. Will add a node at the end of list
        void appendNode(Node *n)
        {
            if(nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key value :" << n->key <<" append a diff node with diff key value " << endl;
            }
            else
            {   //head is empty
                if(head == NULL)
                {
                    head = n;
                    cout << "Node Appended" << endl;
                }
                else
                {
                    // continue to next node
                    Node* ptr =head;
                    while(ptr->next!=NULL)
                    {
                        ptr = ptr -> next;
                    }
                    ptr -> next = n;
                    cout << "Node Appended" <<endl;
                }
            }
        }

        //3. Prepend node - Add a node at the beginning (start) of linked list
        void prependNode(Node* n)
        {
            if(nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key value :" << n->key <<" prepend a diff node with diff key value " << endl;
            }
            else
            {
                //head is already at the beginning no traversing to end
                n -> next = head;
                //grab the memory from head and return to n
                head = n;
            }
        }

        //4 Insert a node after a certain node in the list.
       void insertNodeAfter(int k, Node *n)
       {
           //STORING THE NODEKEY
           Node* ptr = nodeExists(k);
           if(ptr == NULL)
           {
               cout << " No Node exists with key value : " << k <<endl;
           }
           else
           {
                 if(nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key value :" << n->key <<" insert a diff node with diff key value " << endl;
            }
            else
            {
                //connect the lists in this order!
                n-> next = ptr -> next;
                ptr -> next = n;
                cout << "Node inserted" <<endl;
            }
           }
       }

       //5. Deleting a node by using a key
       void deletNodeByKey(int k)
       {
           if(head == NULL)
           {
               cout << "Singly List list Already Empty, Cant Delete!" << endl;
           }
           else if (head!=NULL)
           {
               if(head -> key == k)
               {
                   //not really deleting just unlinking
                   head = head -> next;
                   cout << "Node Unlinked with key value: " << k << endl;
               }
               else
               {
                    Node* temp = NULL;
                    Node* prevptr = head;
                    Node* currentptr = head -> next;
                    while(currentptr != NULL)
                    {
                        if(currentptr->key == k)
                        {

                            temp = currentptr;
                            currentptr = NULL;
                        }
                        else
                        {
                            //move on to next
                            prevptr = prevptr -> next;
                            currentptr = currentptr ->next;
                        }
                    }
                    if(temp != NULL)
                    {
                        prevptr -> next = temp ->next;
                        cout << "Node UNLINKED with key value: " << k << endl;
                    }
                    else
                    {
                        cout << "Node does not exist with key value" << k << endl;
                    }
               }
           }
       }
       //6. update the node by access the key
       void updateNodeByKey(int k, int d)
       {
           Node* ptr = nodeExists(k);
           if(ptr !=NULL)
           {
               ptr -> data = d;
               cout << "Node Data Updated Successfully" <<endl;
           }
           else
           {
                cout << "Node does not exist with the key value " << k << endl;
           }
       }

       // 7. printing out the Singly link list
       void printList()
       {
           if(head == NULL)
           {
               cout << " NO nodes in singly linked list";
           }
           else
           {
               cout << endl << "Singly Linked List Values : ";
               Node* temp = head;

               while(temp != NULL)
               {
                   cout << "(" << temp -> key << "," << temp -> data << ") --> ";
                   temp = temp->next;
               }
           }
       }
};//end of class SinglyLinkedList()//

int main(){

    SinglyLinkedList s;
    int option;
    int key1, k1, data1;

    do
    {
        cout << "\n What operation do you want to perform? Select Option number. Enter 0 to exit." <<endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen()" << endl;

        cin >> option;
        //creating a new node dynamic memory allocation heap global
        Node* n1 = new Node();

        switch(option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \n Enter key & data of the Node to be Appended" <<endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1-> data = data1;
            s.appendNode(n1);
            break;
        case 2:
            cout << "Prepend Node Operation \n Enter key and data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.prependNode(n1);
            break;
        case 3:
            cout << "Insert Node After Operation \n Enter key of existing Node which you want to Insert this new node after: " <<endl;
            cin >> k1;
            cout << "Enter the key and data of the New Node:" <<endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.insertNodeAfter(k1,n1);
            break;
        case 4:
            cout << "Delete Node By Key Operation \n Enter key & NEW data to be updated" <<endl;
            cin >> k1;
            s.deletNodeByKey(k1);
            break;
        case 5:
            cout << "Update Node By Key Operation \n Enter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1,data1);
            break;
        case 6:
            s.printList();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout<< "Enter proper number! " << endl;
        }
    }
    while(option!= 0);

    return 0;
}





