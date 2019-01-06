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
        cout<<' '<<temp->data;
        temp = temp->next;
    }
}

void isPalindrome(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!= NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    cout<<"\n slow data"<<slow->data;
    cout<<"\n fast data"<<fast->data;

    if(fast->next == NULL) cout<<"\n at last";
}

int main(){
    struct Node* head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(2);
    head->next->next->next->next = new_node(1);
    printLL(head);

    isPalindrome(head);
}