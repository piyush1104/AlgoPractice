#include "stdc++.h"

using namespace std;
#define CAPACITY 16

struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

// Note: In C++, the struct keyword is optional before in declaration of a variable. In C, it is mandatory.

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = CAPACITY;
    stack->array = (int*)malloc(CAPACITY * sizeof(int));
    return stack;
}

bool isFull(struct Stack* stack) {
    return stack->top == stack->capacity-1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top==-1;
}

void updateStack(struct Stack* stack) {
    stack->capacity+=CAPACITY;
    stack->array = (int*)realloc(stack->array, stack->capacity * sizeof(int));
}

void push(struct Stack* stack, int value) {
    if(isFull(stack)) {
        updateStack(stack);
    }
    stack->array[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if(isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if(isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top];
}

int main(int argc, char const *argv[])
{
    int input;
    struct Stack* stack = createStack();
    while(1) {
        cout << "1: Push" << endl;
        cout << "2: Pop" << endl;
        cout << "3: Peek" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter your input now:\t";
        cin >> input;
        switch(input){
            case 1:
                int value;
                cout << "Enter your value now:\t";
                cin >> value;
                push(stack, value);
                break;
            case 2:
                cout << pop(stack) << endl;
                break;
            case 3:
                cout << peek(stack) << endl;
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid Value" << endl;
                break;
        }
    }
    return 0;
}
