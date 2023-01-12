#include <iostream>
using namespace std;
#pragma pack(1)
template<class T>

struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>

class LinkedListX
{
public :
    struct node <T> * First;
    struct node <T> * Last;
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
    struct node <T> * newn = new struct node <T>;

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
    struct node <T> * newn = new struct node <T>;

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
        struct node <T>*temp = First;
        struct node <T> * newn = new struct node <T>;

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
        struct node <T> * temp = First;
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
        struct node <T> * temp = Last;
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
        struct node <T> * temp = First;

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
    struct node <T> *temp = First;

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


template<class T>
class Stack     //Last in first out
{
public:
    struct node <T> * First;
    int iCnt;

    Stack();
    bool Is_Stack_empty();
    void push(T No);
    T pop();
    void Display();

};

template<class T>
Stack <T>::Stack()
{
    First = NULL;
    iCnt = 0;
}

template<class T>
bool Stack <T>::Is_Stack_empty()
{
    if(iCnt == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
template<class T>
void Stack <T>::push(T No)
{
    struct node <T> * newn = new struct node<T>;
    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }   
    else
    {
        newn -> next = First;
        First = newn;
    }
    iCnt++;
    cout<<"Gets pushed in the Stack successfully\n";

}
template<class T>
T Stack <T>::pop()
{
    if(First == NULL)
    {
        cout<<"unable to pop the element Stack is empty";
        return (T)-1;
    }
    else if(First -> next == NULL)
    {
        delete(First);
        First = NULL;
    }
    else
    {
        T Value = First -> data;
        struct node <T>* temp = First;
        First = First -> next;
        delete(temp);
        return Value;
    }
    iCnt--;

}
template<class T>
void Stack <T>::Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty.\n";
    }
    else
    {
        cout<<"Elements of strack are:\n";
        struct node <T>* temp = First;
        
        while(temp != NULL)
        {
            cout<<"| "<<temp -> data<<" | -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
    }
}

template<class T>
class Queue
{
public:
    struct node <T>*First;
    int iCnt;
    Queue();
    bool Is_Queue_empty();
    void Enqueue(T No);
    T Dequeue();
    void Display();
};

template<class T>
Queue <T> :: Queue()
{
    First = NULL;
    iCnt = 0;
} 

template<class T>
bool Queue <T> :: Is_Queue_empty()
{
    if(iCnt == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
} 

template<class T>
void Queue <T> :: Enqueue(T No)
{
    struct node <T> * newn = new struct node<T>;
    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct node <T> *temp = First;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCnt++;
}

template<class T>
T Queue <T> :: Dequeue()
{
    if(First == NULL)
    {
        cout<<"Unable to dequeue as queue is empty";
        return (T) -1;
    }
    else
    {
        T Value = First -> data;
        struct node <T>*temp = First;

        First = First -> next;
        iCnt--;
        delete(temp);
        return Value;
    }
}

template<class T>
void Queue <T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Queue is empty";
    }
    else
    {
        struct node <T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp -> data<<" | -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
    }
}

int main()
{
    LinkedListX <int>lobj;
    Stack <char> sobj;
    Queue <float> qobj;

    
    return 0;
}