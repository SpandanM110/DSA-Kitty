#include<stdio.h>
#include<stdlib.h>

struct node *createNode();

void push(struct node *);

struct node *pop();

void infixConvert(char []);

void display(struct node *);

struct node {
    char ch;
    struct node *left;
    struct node *right;
}*stack[11];

int top=11;

void main() {
    char expr[25];
    printf("Enter the Expression : ");
    scanf("%s",expr);
    infixConvert(expr);
    printf("Infix Expression : ");
    display(pop(top));
}


struct node *createNode() {
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    return newnode;
}


void infixConvert(char expr[]) {
    struct node *op1, *op2;
    struct node *newnode;
    int i;
    for(i=0;expr[i]!='\0';i++) {
        if(expr[i]>='a'&&expr[i]<='z'||expr[i]>='A'&&expr[i]<='Z') {
            newnode=createNode();
            newnode->ch=expr[i];
            newnode->left=NULL;
            newnode->right=NULL;
            push(newnode);
        }
        else if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/'||expr[i]=='^') {
            op1=pop();
            op2=pop();
            newnode=createNode();
            newnode->ch=expr[i];
            newnode->right=op1;
            newnode->left=op2;
            push(newnode);
        }
    }
}


void push(struct node *ch) {
    if(top<=0) {
        printf("Full Stack");
        return;
    }
    stack[top]=ch;
    top--;
}


struct node *pop() {
    if(top>=11) {
        printf("Stack Empty");
    }
    else {
        return stack[++top];
    }
}


void display(struct node *temp) {
    if(temp==NULL) {
        return;
    }
    display(temp->left);
    printf("%c",temp->ch);
    display(temp->right);
}
