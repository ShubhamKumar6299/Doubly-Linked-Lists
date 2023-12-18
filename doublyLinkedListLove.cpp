// #include<RadheRadhe>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*prev;
    Node* next;
    //constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
       int value = this->data;
       if(this->next != NULL)
       {
        delete next;
        next = NULL;
       } 
       cout<<"memory is free for node with data"<<value<<endl;
    }
};


//return length of linked list
int getLength(Node* head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp-> next;
    }
    return len;
}
//inserting at the beginning of the linked list
void insertAtHead(Node* &tail,Node* &head, int d)
{
    if(head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next= head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d)
{
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev= tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &tail,Node* &head,int position, int d)
{
    //insertat start
    if(position == 1)
    {
        insertAtHead(tail,head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }
    //inserting at last position
    if(temp->next == NULL)
    {
        insertAtTail(tail,head,d);
        return;
    }
    //creating a new node
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
//traversing a linked list
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

/*void deleteNode(Node*head,Node* &tail, int position)
{
    if(position == 1)
    {
        Node* temp = head;
        // head = head->next;
        temp->next->prev =NULL;
        head = temp->next;
        temp->next =NULL;
        delete temp;
    }
    else{
        //deleting middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next == NULL)
        {
            tail = prev;
            tail->prev = prev;

        }

        curr->prev  =NULL;
        prev->next = curr->next;
        // curr->next->prev = prev;
        curr->next = NULL;
        
        delete curr;

    }
}
*/
void deleteNode(int position, Node* &head,Node* &tail) {

    // Deleting first or start node
    if (position == 1) {
        Node* temp = head;
        if (temp != NULL) {
            head = temp->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            temp->next = NULL;
            delete temp;
        }
    } else {
        // Deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position && curr != NULL) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr != NULL) {
            if (curr->prev != NULL) {
                curr->prev->next = curr->next;
            }
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            }
            if(curr->next == NULL)
            {
                tail = prev;
                tail->prev = prev;
            }
            curr->prev = NULL;
            curr->next = NULL;
            delete curr;
        }
    }
}
//second approach for doubly linked list deletion where we have managed hed as well as tail position.
/*
void deleteNode(int position, Node* &head, Node* &tail) {

    // Deleting first or start node
    if (position == 1) {
        Node* temp = head;
        if (temp != NULL) {
            head = temp->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                // If head is now NULL, update tail as well
                tail = NULL;
            }
            temp->next = NULL;
            delete temp;
        }
    } else {
        // Deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position && curr != NULL) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr != NULL) {
            if (curr->prev != NULL) {
                curr->prev->next = curr->next;
            } else {
                // If the node to be deleted is the first node, update head
                head = curr->next;
            }

            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            } else {
                // If the node to be deleted is the last node, update tail
                tail = prev;
            }

            curr->prev = NULL;
            curr->next = NULL;
            delete curr;
        }
    }
}
*/
int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(tail,head,10);
    insertAtHead(tail,head,11);
    insertAtHead(tail,head,12);
    insertAtHead(tail,head,13);
    insertAtPosition(tail,head,2,122);
    insertAtTail(tail,head,45);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
    deleteNode(3,head,tail);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
    return 0;
}