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

int insidePriority(int oprtor) {
    switch(oprtor) {
        case 6:
            return 0;
        case 5:
            return 3;
        case 4:
            return 2;
        case 3:
            return 2;
        case 2:
            return 1;
        case 1:
            return 1;
        default:
            return -1;
    }
}

int outsidePriority(int oprtor) {
    switch(oprtor) {
        case 6:
            return 5;
        case 5:
            return 3;
        case 4:
            return 2;
        case 3:
            return 2;
        case 2:
            return 1;
        case 1:
            return 1;
        default:
            return -1;
    }
}

int opValue(char oprtor) {
    switch(oprtor) {
        case '(':
            return 6;
        case '^':
            return 5;
        case '*':
            return 4;
        case '/':
            return 3;
        case '+':
            return 2;
        case '-':
            return 1;
        default:
            return -1;
    }
}

int operation(int value1, int oprtor, int value2) {
    switch(oprtor) {
        case 5:
            return pow(value1, value2);
        case 4:
            return value1*value2;
        case 3:
            if(value2 ==0) {
                cout << "Cannot divide by 0. Terminating the program." << endl;
                exit(0);
                return -1;
            }
            return value1/value2;
        case 2:
            return value1 + value2;
        case 1:
            return value1 - value2;
        default:
            cout << "Operator - " << oprtor << " is wrong" << endl;
            exit(0);
            return -1;
    }
}

void calculate(char expression[]) {
    struct Stack* values = createStack();
    struct Stack* ops = createStack();
    char* value = (char*)malloc(100*sizeof(char));
    int j=0;
    // cout << "Length of expression: " << strlen(expression) << endl;
    int length = strlen(expression);
    // also since we already store our expression in an array,
    // we don't have to use "#" as to know the end of the expression
    // "#" was also introduce by sir
    for (int i = 0; i < length; ++i)
    {
        // cout << expression[i] << endl;
        if(isdigit(expression[i])){
            if(i == length -1 || !isdigit(expression[i+1])) {
                *(value+j)=expression[i];
                push(values, stoi(value));
                value = (char*)malloc(100*sizeof(char));
                j=0;
            } else {
                *(value+j)=expression[i];
                j++;
            }
            continue;
        } else {
            if(expression[i] == '\0') {
                break;
            }
            if(expression[i] == ' ') {
                // this if is not working because cin stops at space. We have to
                // use getChar() to implement it.
                continue;
            }
            if(expression[i] == ')') {
                while(peek(ops) != 6) {
                    cout << "case 1 " << peek(ops) << endl;
                    int value2 = pop(values);
                    int value1 = pop(values);
                    push(values, operation(value1, pop(ops), value2));
                }
                pop(ops);
                continue;
            }
            int oprtor = opValue(expression[i]);
            if(oprtor == -1) {
                cout << "Undefined operator: " << expression[i] << endl;
                free(value);
                return;
            }
            // sir introduced the concept of "$" having priority -1 for handling empty operator stack
            // but we didn't include it in our program and it still worked
            // here is why? see peek() gives INT_MIN if the stack is empty
            // and our priority function gives -1 if operator is not valid
            // since INT_MIN is not a valid operator, we get priority -1
            // thus INT_MIN was able to act as "$" for us. But be careful of such bugs
            while(insidePriority(peek(ops)) >= outsidePriority(oprtor)) {
                cout << "case 2 " << oprtor << " " << peek(ops) << endl;
                int value2 = pop(values);
                int value1 = pop(values);
                push(values, operation(value1, pop(ops), value2));
            }
            push(ops, oprtor);
        }
    }
    while(!isEmpty(ops)) {
        int value2 = pop(values);
        int value1 = pop(values);
        push(values, operation(value1, pop(ops), value2));
    }
    free(value);
    cout << pop(values) << endl;
}

int main(int argc, char const *argv[])
{
    int input;
    struct Stack* stack = createStack();
    int invalidValueCount = 0;
    while(1) {
        cout << "1: Calculate" << endl;
        cout << "2: Exit" << endl;
        cout << "Enter your input now:\t";
        cin >> input;
        switch(input){
            case 1:
                invalidValueCount = 0;
                cout << "Enter your expression now:\t";
                char expression[10000];
                cin >> expression;
                calculate(expression);
                break;
            case 2:
                exit(0);
                break;
            default:
                invalidValueCount++;
                cout << "Invalid Value" << endl;
                if(invalidValueCount == 2){
                    exit(0);
                }
                break;
        }
    }
    return 0;
}
