#include <iostream>

using namespace std;

struct node {
        int data;
        struct node *next;
} head;

int main(){
        node* head = new node();
        head = NULL;
        while(1) {
                cout<<"\n 1. Insert node";
                cout<<"\n 2. View nodes";
                cout<<"\n 3. Delete nodes";
                cout<<"\n 4. Exit."<<endl;
                int ch;
                cin>>ch;
                switch (ch) {
                case 1: {
                        char choice;
                        cout<<"\n a. Insert at the beginning";
                        cout<<"\n b. Insert at the end";
                        cout<<"\n c. Insert at a specified location"<<endl;
                        cin>>choice;
                        switch(choice) {
                        case 'a': {
                                cout<<"\n Enter the element to be inserted ";
                                int element;
                                cin>>element;
                                if(head == NULL) {
                                        cout<<"\n Linked list is empty. Inserting at the beginning....."<<endl;
                                        struct node * ini = new node();
                                        ini->data = element;
                                        ini->next = NULL;
                                        head = ini;
                                }
                                else{
                                        struct node *new_node = new node();
                                        new_node->data = element;
                                        new_node->next = head;
                                        head = new_node;
                                }

                        } break;
                        case 'b': {
                                cout<<"\n Enter the element to be inserted ";
                                int element;
                                cin>>element;
                                if(head == NULL) {
                                        cout<<"\n Linked list is empty. Inserting at the beginning....."<<endl;
                                        struct node * ini = new node();
                                        ini->data = element;
                                        ini->next = NULL;
                                        head = ini;
                                }
                                else{
                                        struct node * new_node = new node();
                                        new_node->data = element;
                                        new_node->next = NULL;
                                        struct node * traversal = new node();
                                        traversal = head;
                                        while(traversal->next != NULL) {
                                                traversal = traversal->next;
                                        }
                                        traversal->next = new_node;
                                }

                        } break;
                        case 'c': {
                                cout<<"\n Enter the element to be inserted ";
                                int element;
                                cin>>element;
                                if(head == NULL) {
                                        cout<<"\n Linked list is empty. Inserting at the beginning....."<<endl;
                                        struct node * ini = new node();
                                        ini->data = element;
                                        ini->next = NULL;
                                        head = ini;
                                }
                                else {
                                        struct node * disp = new node();
                                        disp = head;
                                        while(disp != NULL) {
                                                cout<<"\t "<<disp->data;
                                                disp = disp->next;
                                        }
                                        cout<<"\n Where do you want to insert? Enter the value ";
                                        int val;
                                        cin>>val;
                                        cout<<"\n x. Before "<<val;
                                        cout<<"\n y. After  "<<val<<endl;
                                        char ch;
                                        cin>>ch;
                                        switch (ch) {
                                        case 'x': {

                                                struct node* traversal = new node();
                                                traversal = head;
                                                if(head->data == val) {
                                                        struct node* new_node = new node();
                                                        new_node->data = element;
                                                        new_node->next = head;
                                                        head= new_node;
                                                }
                                                else{
                                                        while(traversal->next->data != val) {
                                                                traversal = traversal->next;
                                                        }
                                                        struct node*new_node = new node();
                                                        new_node->data = element;
                                                        new_node->next = traversal->next;
                                                        traversal->next = new_node;
                                                }
                                        } break;
                                        case 'y': {
                                                struct node* traversal = new node();
                                                traversal = head;
                                                while(traversal->data!=val) {
                                                        traversal = traversal->next;
                                                }
                                                struct node * new_node = new node();
                                                new_node->data = element;
                                                new_node->next = traversal->next;
                                                traversal->next = new_node;


                                        } break;
                                        default: {
                                                cout<<"\n Invalid selection "<<endl;
                                        }
                                        }
                                }

                        } break;
                        default: {
                                cout<<"\n Invalid option"<<endl;
                        }
                        }

                } break;
                case 2: {
                        if(head == NULL) {
                                cout<<"\n Linked list is empty"<<endl;
                        }
                        else{
                                cout<<"\n";
                                struct node * disp = new node();
                                disp = head;
                                while(disp != NULL) {
                                        cout<<"\t "<<disp->data;
                                        disp = disp->next;
                                }
                        }
                } break;
                case 3: {
                        if(head == NULL) {
                                cout<<"\n Linked list empty cannot delete elements"<<endl;
                        }
                        else{
                                int che;
                                cout<<"\n 1.Delete from the beginning :";
                                cout<<"\n 2.Delete from the end :";
                                cout<<"\n 3.Delete from a specific location :";
                                cin>>che;
                                switch (che) {
                                case 1: {
delb:                                   struct node * nex = new node();
                                        nex = head;
                                        head =head->next;
                                        free(nex);
                                } break;
                                case 2: {
                                        struct node * tra = new node();
                                        struct node * pre = new node();
                                        tra = head;
                                        if(tra->next==NULL) {
                                                head = NULL;
                                        }
                                        else{
                                                while(tra->next!=NULL) {
                                                        pre = tra;
                                                        tra = tra->next;
                                                }
                                                free(tra);
                                                pre->next = NULL;
                                        }
                                } break;
                                case 3: {
                                        if(head == NULL) {
                                                cout<<"\n Linked list is empty"<<endl;
                                        }
                                        else{
                                                cout<<"\n";
                                                struct node * disp = new node();
                                                disp = head;
                                                while(disp != NULL) {
                                                        cout<<"\t "<<disp->data;
                                                        disp = disp->next;
                                                }
                                        }
                                        cout<<"\n Enter the element you want to delete";
                                        int elem;
                                        cin>>elem;
                                        node * tra = new node();
                                        node * prev = new node();
                                        tra = head;
                                        prev = tra;
                                        if(head->data == elem) {
                                                goto delb;
                                        }
                                        else{
                                                while(tra->next->data!=elem && tra->next!= NULL) {
                                                        prev = tra;
                                                        tra = tra->next;
                                                }
                                                prev->next = tra->next->next;
                                        }


                                } break;
                                default: {
                                        cout<<"\n Invalid Entry"<<endl;
                                }
                                }
                        }
                } break;
                case 4: {
                        return 0;
                }
                default: {
                        cout<<"\n Invalid Entry"<<endl;
                }
                }
        }
}