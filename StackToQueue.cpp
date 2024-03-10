#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int top;

public:
    int a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void empty();
    int size();
};

// O(1)
bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        return true;
    }
}

// O(1)
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return -1;
    }
    else {
        int x = a[top--];
        return x;
    }
}

// O(1)
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return -1;
    }
    else {
        int x = a[top];
        return x;
    }
}

// O(1)
bool Stack::isEmpty()
{
    return (top < 0);
}

// O(n)
void Stack::empty()
{
    while (!isEmpty()) {
        pop();
    }
}

// O(1)
int Stack::size()
{
    return (top + 1);
}

class Queue {
public:
    class Stack s1;
    class Stack s2;
    bool isEmpty();
    void empty();
    int size();
    int front();
    int back();
    bool enqueue(int x);
    int dequeue();
};

// O(1)
bool Queue::isEmpty()
{
    return (s1.isEmpty() && s2.isEmpty());
}

// O(1)
void Queue::empty()
{
    s1.empty();
    s2.empty();
}

// O(1)
int Queue::size() {
    return (s1.size() + s2.size());
}

// O(n)
int Queue::front()
{
    if (isEmpty()) {
        return -1;
    }
    if (s2.isEmpty()) {
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }
    }
    return s2.peek();
}

// O(1)
int Queue::back()
{
    if (isEmpty()) {
        return -1;
    }
    if (!s1.isEmpty()) {
        return s1.peek();
    }
    return s2.a[0];
}

// O(1)
bool Queue::enqueue(int x)
{
    return (s1.push(x));
}

// O(n)
int Queue::dequeue()
{
    if (isEmpty()) {
        return -1;
    }
    if (s2.isEmpty()) {
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }
    }
    return s2.pop();
}

// Driver program to test above functions
int main()
{
    class Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout << "size is : " << q1.size() << endl;
    cout << "front is : " << q1.front() << endl;
    cout << "back is : " << q1.back() << endl;
    q1.empty();
    cout << "size is : " << q1.size() << endl;

    return 0;
}
