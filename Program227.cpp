#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE, *PNODE;

class DoublyLL
{
    private:
        PNODE first;
        int Count;

    public:
        DoublyLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no,int ipos);
        void DeleteAtPos(int ipos);
};

DoublyLL::DoublyLL()
{
    first = NULL;
    Count = 0;
}

void DoublyLL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else 
    {
        newn->next = first;
        first->prev = newn;
        first = newn; 
    }
    Count++;
}

void DoublyLL::InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    PNODE temp = first;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while ( temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}

void DoublyLL::Display()
{
    cout<<"Elements inside the linked list :"<<endl;

    PNODE current = first;
    cout<<"NULL<=>";
    while (current != NULL)
    {
        cout<<"| "<<current->data<<" |<=>";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}

int DoublyLL::CountNode()
{
    return Count;
}

void DoublyLL::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else 
    {
        PNODE temp = first;
        first = first->next;
        first->prev = NULL;
        delete(temp);
    }
    Count--;
}

void DoublyLL::DeleteLast()
{
    PNODE temp = first;
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else 
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;    
    }
    Count--;
}

void DoublyLL::InsertAtPos(int no,int ipos)
{
    if((ipos < 1) || (ipos > Count + 1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count + 1)
    {
        InsertLast(no);
    }
    else 
    {
        PNODE newn = new NODE;
        PNODE temp = first;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        int i = 0;
        for(i = 1; i < ipos -1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        Count++;
    }
}

void DoublyLL::DeleteAtPos(int ipos)
{
    if((ipos < 1) || ( ipos > Count))
    {
        cout<<"Invalid Position : "<<endl;
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else 
    {
        PNODE temp = first;
    
        int i = 0; 
        for(i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;
        Count--;   
    }
}

int main()
{
    DoublyLL obj;

    int iRet = 0;

    obj.InsertFirst(111);
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);
    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.InsertAtPos(105, 5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
    
    return 0;
}
