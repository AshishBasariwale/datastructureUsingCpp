// Doubly Circular
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE, *PNODE;

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int Count;

    public:
        DoublyCL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no,int ipos);
        void DeleteAtPos(int ipos);
};

DoublyCL::DoublyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

void DoublyCL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else 
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
      
    }
    first->prev = last;
    last->next = first;
    Count++;
}
void DoublyCL::InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;


    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else 
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    Count++;
}
void DoublyCL::Display()
{
    cout<<"Elements inside the Linked list : "<<endl;

    if((first != NULL) && (last != NULL))
    {
        cout<<"NULL|<=>";
        do
        {
            cout<<"|"<<first->data<<"|<=>";
            first = first->next;
        } while (first != last->next);
    }
}
int DoublyCL::CountNode()
{
    return Count;
}
void DoublyCL::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete(first);
        first = NULL;
        last = NULL;
    }
    else 
    {
        first = first->next;
        delete(last->next);
        last->next = first;
        first->prev = last;
    }
}
void DoublyCL::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete(first);
        first = NULL;
        last = NULL;
    }
    else 
    {
        last = last->prev;
        delete(last->next);
        last->next = first;
        first->prev = last;
    }

}
void DoublyCL::InsertAtPos(int no,int ipos)
{
    if((ipos < 1) && (ipos > Count++))
    {
        cout<<"Invalid Position :"<<endl;
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
        newn->data = no;
        newn->next = NULL;  
        newn->prev = NULL;
        PNODE temp = first;
        int i = 0;
        for(i = 1; i< ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
        Count++;
    }

}
void DoublyCL::DeleteAtPos(int ipos)
{
    if((ipos < 1) && ( ipos > Count))
    {
        cout<<"Invalid position"<<endl;
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
        int i = 0; 
        PNODE temp = first;

        for(i =1; i < ipos -1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
        Count--;
    }

}

int main()
{

    DoublyCL obj;

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