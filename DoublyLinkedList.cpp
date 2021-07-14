/*
Bradley Allen
This is a program that will implement Doubly Linked List Data Structure.
This is a linked list that will store previous node location in memory.
This program is run in the command line.
*/
#include<iostream>
using namespace std;

class Node{
public:
    //stored in public for simplicity instead of private no getter functions.
    int key;
    int data;
    Node* next;
    Node* previous;
    //Constructor
    Node()
    {
        key = 0;
        data = 0;
        next=NULL;
        previous = NULL;
    }
    Node(int k , int d)
    {
        key=k;
        data=d;
    }
};//end of Node Class
class DoublyLinkedList{
public:
    Node* head;
    //Constructor
    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head = n;
    }

    //1. Check if node exists using key, returns pointer
    Node* checkIfNodeExists(int k)
    {
        Node* temp = NULL;
        Node* ptr = head;

        while(ptr!=NULL)
        {
            //will loop until found match key
            if(ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr ->next;
        }
        return temp;
    }
    //2. Append a node(add) pass by address
    void appendNode(Node* n)
    {
        if(checkIfNodeExists((n->k) != NULL)
           {
               cout << "Node already exists with key value : " << n->key << "Append another node with diff key " <<endl;
           }
           //traversing each
           else
           {
               if(head == NULL)
               {
                   head = n;
                   cout << "Node Appended as head node" <<endl;
               }
               else
               {
                   Node* ptr = head;
                   while(ptr->next != NULL)
                   {
                       ptr = ptr -> next;
                   }
                   ptr -> next =n;
                   n->previous = ptr;
                   cout << "Node Appended" <<endl;
               }
           }
    }}

    //3. Prepend Node -add to the beginning (no traversing)
    void prependNode(Node* n )
    {
        if(checkIfNodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value:" << k << "Append another node with diff key " <<endl;
        }
        else
        {
            if(head == NULL)
            {
                head = n;
                cout << " node prepended as head node" <<endl;
            }
            else
            head ->previous = n;
            n->next = head;

            head = n;
            cout << "Node Prepended" <<endl;
        }
    }

    //4. Insert a node after another node.
    void insertNodeAfter(int k, Node *n)
    {
        Node* ptr = checkIfNodeExists(k);
        if(ptr==NULL)
        {
            cout << "no node exists with key value:" << k <<endl;
        }
        else
        {
            if(checkIfNodeExists(n->key)!=NULL)
            {
                cout << "Node already exists with key value: " <<n->k << endl;
            }
            else
            {
                Node *nextNode = ptr->next;

                //add to the end
                if(nextNode == NULL)
                {
                    ptr ->next=n;
                    n->previous=ptr;
                    cout << "Node inserted at the end" <<endl;
                }

                //add between 2 nodes
                else
                {
                    n->next=nextNode;
                    nextNode->previous=n;
                    n->previous=ptr;
                    ptr->next=n;
                    cout << "Node Inserted between the 2 nodes"
                }

            }
        }
    }


    //Delete Node by using key (Unlinking the list not deleting memory)
    void deleteNodeByKey(int k)
    {
        Node* ptr = checkIfNodeExists(k);
        if(ptr==NULL)
        {
            cout << "No node exists with key value: " << k << endl;

        }else
        {

            if(head->key==k)
            {
                head = head->next;
                cout << "node unlinked with key value: " <<k << endl;
            }
            else
            {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr0>previous;
                //delete end
                if(nextNode == NULL)
                {
                    prevNode->next=NULL;
                    cout << "Node deleted at the END" <<endl;
                }
                //delete between
                else
                {
                    prevNode->next=nextNode;
                nextNode->previous=prevNode;
                cout << "Node deleted inbetween" <<endl;

                }
            }
        }
    }

    //6. update the node
    void updateNodeByKey(int k, int d)
    {
        Node* ptr = checkIfNodeExists(k);
        if(ptr!=NULL)
        {
            ptr->data = d;
            cout << "node data updated successfully" <<endl;
        }
        else
        {
            cout << "node does not exists with key value:" <<k <<endl;
        }
    }

    //7. printing out the list
    void printList()
    {
        if(head==NULL)
        {
            cout << "no nodes in doubly list" <<endl;
        }
        else
        {
         cout << endl << "Doubly list values: ";
         Node* temp = head;

         while(temp!= NULL)
         {
             cout << "(" << temp->key<<","<< temp->data<<") <--> ";
             temp = temp->next;
         }
        }
    }
};//end of DoublyLinkedList Class


int main()
{
    DoublyLinkedList s;
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
    }while(option!= 0);
    return 0;
}
