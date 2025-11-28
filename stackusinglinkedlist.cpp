#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct node{
    int data;
    struct node* next; 
};

struct node* top = NULL;

bool isEmpty = true;

// here we dont really have to worry about the size of the stack , as we are using dynamic memory so that is fine

void push(int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(top == NULL){
        top = newnode;
        isEmpty = false;
    }
    else{
        newnode->next = top;
        top = newnode;
    }
}

void pop(){
    if(top == NULL){
        return;
    }
    struct node* tmp = top;
    top = top->next;
    tmp->next = NULL;
    if(top == NULL){
        isEmpty = true;
    }
}


bool Empty(){
    return isEmpty;
}
void TCSOLVE(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);

    pop();
    pop();
    pop();
    pop();

    while(top!=NULL){
        cout << top->data << " ";
        top = top->next;
    }
}
int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}
