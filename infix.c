#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        
        return '\0'; 
    }
    return stack[top--];
}


int isp(char c) {
    switch(c) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;  }
    return -1;  
}


int icp(char c) {
    switch(c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 9;  
    }
    return -1;  
}


int isOperand(char c) {
    return (isalnum(c));
}

void convert(char* exp) {
    push('(');        
    int i = 0;
    int len = strlen(exp);
    exp[len] = ')';  
    exp[len + 1] = '\0';

    while (top != -1) {   
        char item = exp[i++];    
        if (isOperand(item)) {
            
            printf("%c", item);
        } 
        else if (item == '(') {
            push(item);
        } 
        else if (item == ')') {
         
            char x = pop();
            while (x != '(') {
                printf("%c", x);
                x = pop();
            }
        } 
        else {
          
            char x = pop();
            while (isp(x) >= icp(item)) {
                printf("%c", x);
                x = pop();
            }
            push(x);
            push(item);
        }
    }
    printf("\n");
}

int main() {
    char expression[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", expression);
    convert(expression);
    return 0;
}

