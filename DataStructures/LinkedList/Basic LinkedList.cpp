#include<iostream>

using namespace std;

struct node {
    int data;
    struct node* next;
}head;

int main(){
    node* head = new node();
    head = NULL;

    for(int i =0;i<10;i++){
        node* new_node = new node();

        if(head == NULL){
            new_node->data = i;
            new_node->next = NULL;
            head = new_node;
        }
        else{
            node *traversal = new node();
            traversal = head;
            while(traversal->next!= NULL){
                traversal = traversal->next;
            }

            new_node->data = i;
            new_node->next = NULL;
            traversal->next = new_node;
        }
    }

    cout<<"Printing LinkedList: "<<endl;

    while(head!=NULL){
        cout<<" "<<head->data;
        head = head->next;
    }
}