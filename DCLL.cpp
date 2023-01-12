#include <iostream>
using namespace std;
#pragma pack(1)
template<class T>

struct node_DCLL
{
    T data;
    struct node_DCLL *next;
    struct node_DCLL *prev;
};

template <class T>

class LinkedListX
{
public :
    struct node_DCLL <T> * First;
    struct node_DCLL <T> * Last;
    int iCnt;

    LinkedListX();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo,int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void Display();
};

template <class T>
LinkedListX <T> :: LinkedListX()
{
    First = NULL;
    Last = NULL;
    iCnt = 0;
}

template <class T>
void LinkedListX <T> :: InsertFirst(T iNo)
{
    struct node_DCLL <T> * newn = new struct node_DCLL <T>;

    newn -> data = iNo;
    newn -> prev = NULL;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = Last = newn;
        newn -> next = First;
        newn -> prev = Last;
    }
    else
    {
        newn -> next = First;
        newn -> prev = Last;
        First -> prev = newn;
        First = newn;
        Last -> next = First;
    }
    iCnt++;
}

template <class T>
void LinkedListX <T> :: InsertLast(T iNo)
{
    struct node_DCLL <T> * newn = new struct node_DCLL <T>;

    newn -> data = iNo;
    newn -> prev = NULL;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = Last = newn;
        newn -> next = First;
        newn -> prev = Last;
    }
    else
    {
        Last -> next = newn;
        newn -> prev = Last;
        Last = newn; 
        Last -> next = First;
        First -> prev = Last;
    }
    iCnt++;
}

template <class T>
void LinkedListX <T> :: InsertAtPos(T iNo,int iPos)
{   
    if(iPos < 1 || iPos > (iCnt + 1))
    {
        cout << "invalid position\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCnt + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct node_DCLL <T>*temp = First;
        struct node_DCLL <T> * newn = new struct node_DCLL <T>;

        newn -> data = iNo;
        newn -> prev = NULL;
        newn -> next = NULL;

        for(int i = 1; i < (iPos - 1); i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        newn -> prev = temp;
        temp -> next -> prev = newn;
        temp -> next = newn;
        iCnt++;
    }
}

template <class T>
void LinkedListX <T> :: DeleteFirst()   
{
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First -> next == Last)
    {
        delete(First);
        delete(Last);
        First = Last = NULL;
    }
    else
    {
        struct node_DCLL <T> * temp = First;
        First = First -> next;
        First -> prev = Last;
        Last -> next = First;
        delete(temp);
    }
    iCnt--;
}

template <class T>
void LinkedListX <T> :: DeleteLast()
{
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First -> next == Last)
    {
        delete(First);
        delete(Last);
        First = Last = NULL;
    }
    else
    {
        struct node_DCLL <T> * temp = Last;
        Last = Last -> prev;
        Last -> next = First; 
        First -> prev = Last;
        delete(temp);
    }
    iCnt--;
}

template <class T>
void LinkedListX <T> :: DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCnt)
    {
        printf("Enter valid positoin.");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCnt)
    {
        DeleteLast();
    }
    else
    {
        struct node_DCLL <T> * temp = First;

        for(int i = 1; i < iPos; i++)
        {
            temp = temp -> next;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        delete(temp);
        iCnt--;
    }

}

template <class T>
void LinkedListX <T> :: Display()
{
    struct node_DCLL <T> *temp = First;

    if(First == NULL && Last == NULL)
    {
        return;
    }
    else
    {
        do
        {
            cout<<"| "<<temp -> data<<" | -> ";
            temp = temp -> next;
        }while(temp != Last -> next);
        cout<<"\n";
    }
}
int main()
{
    
}