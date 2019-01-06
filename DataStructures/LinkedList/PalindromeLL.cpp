#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Node* new_node(int data){
    struct Node * nodes = new Node();
    nodes->data = data;
    nodes->next = NULL;
}

void printLL(Node* temp){
    if(temp==NULL){
    cout<<"\n Empty ll";
    }

    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp = temp->next;
    }
}

Node* helper(Node* head,Node* nex){
    if(nex==NULL)
        return head;
    
    if(nex->next ==NULL){
        return head->data==nex->data ? head->next : NULL;
    }

    Node* currhead = helper(head,nex->next);

    if(currhead == NULL) return NULL;

    return currhead->data == nex->data?currhead->next:NULL;
}

bool isPalindrome(Node* head){
    if(head==NULL) return true;

    return helper(head,head->next)==NULL?false:true;
}

int main(){
    struct Node* head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(2);
    head->next->next->next->next = new_node(1);
    printLL(head);

    isPalindrome(head)?cout<<"\nyes":cout<<"\nno";
}