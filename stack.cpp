// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/tutorial/

#include <iostream>

using namespace std;

class StackMember {
public:
    int data;
    StackMember *previous;
    StackMember *next;
    StackMember(int data) {
        this->data = data;
        previous = NULL;
        next = NULL;
    }
};

class Stack {
public:
    StackMember *top;
    int size;
    int current_size;
    
    Stack(int size) {
        this->size = size;
        this->current_size = 0;
        this->top = NULL;
    }
    
    bool isEmpty() {
        return !top;
    }
    
    bool isFull() {
        return (current_size == size);
    }
    
    StackMember *push(StackMember *sm) {
        if(isFull()) {
            return NULL;
        } else {
            if (! isEmpty()) {
                sm->previous = top;
                top->next = sm;
            }
            top = sm;
            current_size++;
            return sm;
        }
    }
    
    StackMember *pop() {
        if(isEmpty()) {
            return NULL;
        } else {
            StackMember *sm = top;
            top = top->previous;
            if (top) {
                top->next = NULL;
            }
            current_size--;
            return sm;
        }
    }
};

int main() {
    Stack *s = new Stack(10);
    for (int i=0; i<20; i++) {
        StackMember *sm = s->push(new StackMember(i));
        cout << sm << endl;
    }
    while(StackMember *sm = s->pop()) {
        cout << sm->data << endl;
    }
}
