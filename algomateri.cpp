#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode()
{
    Node * newNode = new Node();
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode -> noMhs;
    cout << "\nEnter the name of the student: ";
    cin >> newNode -> name;

    if (START != NULL && newNode->noMhs == START->noMhs) {
    
        if (START != NULL && newNode->noMhs == START->noMhs){
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
    }
    //jika list kosong
        newNode->next = START;
        if (START != NULL) 
    {
        START->prev = newNode;
    }
    newNode->prev = NULL;
    START = newNode;
    }
    else 
    {
        //memasukkan new node di tengah atau di terakhir
        Node *current = START;
        Node *previous = NULL;

        while (current != NULL && current->noMhs < newNode->noMhs)
        {
            previous = current;
            current = current->next;
        }
        
        newNode->next = current;
        newNode->prev = previous;

        if (current != NULL)
        {
            current->prev = newNode;
        }

        if (previous != NULL)
        {
            previous->next = newNode;
        }
        else
        {
            //jika previous masih NULL, tandanya newnode ada di first node
            START = newNode;
        }
    }
}

bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node *previous, *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    current = START;
    previous = NULL;

    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
        return;
    }

    if (current == START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    {
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }

    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m" << endl;
}

bool ListEmpty()
{
    return(START == NULL);
}

void traverse()
{
    if (ListEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in ascending order of roll number are:" << endl;
        Node *currentNode = START;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

void retraverse()
{
    if (ListEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in ascending order of roll number are:" << endl;
        Node *currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;
        
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
        
    }
}

void searchData()
{
    if (ListEmpty() == true)
    {
        cout << "\nList is empty" << endl;
    }
    Node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search: ";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found" << endl;
    else
    {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number: " << endl;
        cout << "\nName: " << endl;
    }
}




