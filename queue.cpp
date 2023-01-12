#include <iostream>
using namespace std;
#pragma pack(1)

template<class T>
struct node_Queue
{
    T data;
    struct node_Queue *next;
};

template<class T>
class Queue
{
public:
    struct node_Queue <T>*First;
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
    struct node_Queue <T> * newn = new struct node_Queue<T>;
    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct node_Queue <T> *temp = First;
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
        struct node_Queue <T>*temp = First;

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
        struct node_Queue <T> *temp = First;
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
    

    return 0;
}