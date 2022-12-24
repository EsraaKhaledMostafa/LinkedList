#include <iostream>
using namespace std;



class Node
{
public:
    int data;
    Node* next, * previous;
    Node(int data)
    {
        this->data = data;
        next = previous = NULL;
    }
};

class LinkedList
{
    Node* Head, * Tail;
public:
    LinkedList()
    {
        Head = Tail = NULL;
    }
    void addNode(int data)
    {
        Node* node = new Node(data);

        if (Head == NULL)
        {
            Head = Tail = node;
        }
        else
        {
            Tail->next = node;
            node->previous = Tail;
            Tail = node;
        }
    }

    void DisplayData()
    {
        Node* CurrentNode;
        CurrentNode = Head;
        while (CurrentNode != NULL)
        {
            cout << CurrentNode->data;
            CurrentNode = CurrentNode->next;
        }
    }
    Node* search(int data)
    {
        Node* CurrentNode = Head;
        while (CurrentNode != NULL && data != CurrentNode->data)
        {
            CurrentNode = CurrentNode->next;  
        }
        return CurrentNode;
    }

    void InsertNode(int data, int loc)
    {
        Node* node = new Node(data);
        Node* currentloc = Head;
             
        if (Head == NULL)
        {
            Head = Tail = node;
        }
       
        else
        {
            if (loc == 0)
            {
                node->next = Head;
                Head->previous = node;
                Head = node;
            }
            else
            {
                for (int i = 1; i < loc - 1 && currentloc; i++)
                {
                    currentloc = currentloc->next;
                }
                if (currentloc->next == NULL)
                {
                    Tail->next = node;
                    node->previous = Tail;
                    Tail = node;
                }
                else
                {
                    currentloc->next->previous = node;
                    node->next = currentloc->next;
                    node->previous = currentloc;
                    currentloc->next = node;      
                }
            }
        }
    }
    void RemoveNode(int data)
    {
        Node* currentloc = search(data);
        if (currentloc == NULL)
        {
            return;
        }

        if (currentloc==Head)
        {
            if (currentloc == Tail)
            {
                Head = Tail = NULL;
            }
            else
            {
                Head = Head->next;
                Head->previous = NULL;
            }
        }
        else if (currentloc->next == NULL)
        {
            Tail = Tail->previous;
            Tail->next = NULL;

        }
        else
        {
            currentloc->next->previous = currentloc->previous;
            currentloc->previous->next = currentloc->next;
        }
        delete[]currentloc;
    }
}; 




int main()
{
    LinkedList mylist;
    mylist.addNode(1);
    mylist.addNode(2);
    mylist.addNode(3);
    mylist.addNode(4);
    mylist.addNode(5);

    mylist.DisplayData();
    cout << endl;
    cout << mylist.search(4) << endl;

    mylist.InsertNode(99, 2);
    mylist.DisplayData();
    cout << endl;

    mylist.RemoveNode(3);
    mylist.DisplayData();
}

