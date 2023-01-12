#pragma pack(1)

template<class T>
struct node_Stack
{
    T data;
    struct node_Stack *next;
};

template<class T>
class Stack     //Last in first out
{
public:
    struct node_Stack <T> * First;
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
    struct node_Stack <T> * newn = new struct node_Stack<T>;
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
        struct node_Stack <T>* temp = First;
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
        struct node_Stack <T>* temp = First;
        
        while(temp != NULL)
        {
            cout<<"| "<<temp -> data<<" | -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
    }
}