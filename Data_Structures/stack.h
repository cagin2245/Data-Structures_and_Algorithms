#pragma once
#include <iostream>


using std::cout, std::endl, std::flush;
// LIFO -> L ast I n F irst O ut
// Recursion => Stack
// Iterative => Stack ~


/* 
        ADT Stack
Data:
    1. Space for showing elements
    2. Top pointer
Operations:
    1. Push(x)
    2. Pop()
    3. Peek(Index)
    4. stackTop()
    5. isEmpty()
    6. isFull()

*/
class Stack {
    private:
    int size;
    int top;
    int * s;
    public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    int stackTop();
};
Stack::Stack(int size){
    this->size = size;
    top = -1;
    s = new int[size];
}
Stack::~Stack(){
    delete [] s;
}

void Stack::push(int x){
    if(isFull())
    {
        cout << "Stack Overflow!"<< endl;

    }
    else{
        top++;
        s[top] = x;
    }
}
int Stack::pop(){
    int x = 1;
    if(isEmpty()){
        cout << "Stack Overflow!" << endl;
    }
    else{
        x = s[top];
        top--;
    }
    return x;    
}
int Stack::peek(int index){
    int x = -1;
    if(top-index+1 < 0|| top-index+1 == size){
        cout << "Gecersiz konum!" << endl;
    }
    else{
        x = s[top-index+1];
    }
    return x;
}

int Stack::isFull(){
    if(top == size-1)
    {
        return 1 ;
    }
    return 0;
       
}
int Stack::isEmpty(){
    if(top== -1)
    {
        return 1;
    }
    return 0;
}

void Stack::display()
{
    for(int i = top; i>=0;i--)
    {
        cout << s[i] << " | " << flush;

    }
    cout << endl;

}
int Stack::stackTop(){
    if (isEmpty())
    {
        return -1;
    }
    return s[top];
}

