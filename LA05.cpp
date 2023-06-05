/*
Convert given binary tree into threaded binary tree. Analyze time and space
complexity of the algorithm.
*/

#include<iostream>
using namespace std;

class node{
    public:
    int data,rth,lth;
    node *right,*left;
};

class TBT
{
public:
    node *root,*head;
    TBT(){
        head = new node;
        head->data = -999;
        head->left = head;
        head->right = head;
        head->rth = 1;
        head->lth = 0;
        root = NULL;
    }
    void create();
    void insert(node*,node*);
    void inorder();
    node* inorderSucc(node*);
};

void TBT::create(){
    int ch;
    node *newnode;
    do
    {
        newnode = new node;
        newnode->left = newnode->right = NULL;
        newnode->rth = newnode->lth = 0;
        cout<<"\nEnter Element to insert: ";
        cin>>newnode->data;
        if(root == NULL){
            root = newnode;
            root->right = root->left = head;
            head->left = root;
            head->lth = 1;
            cout<<"\nRoot of the tree is: "<<root->data<<endl;
        }
        else{
            insert(root,newnode);
        }
        cout<<"\nPress 1 to Add more elements: ";
        cin>>ch;
    } while (ch==1);
    
}

void TBT::insert(node* temp,node*newnode)
{
    if(newnode->data < temp->data){
        if(temp->lth == 0){
            newnode->right = temp;
            newnode->left = temp->left;
            temp->lth = 1;
            temp->left = newnode;
            cout<<"\nLeft child of "<<temp->data<<" is: "<<newnode->data<<endl;
        }
        else{
            insert(temp->left,newnode);
        }
    }
    else{
        if(temp->rth == 0){
            newnode->right = temp->right;
            newnode->left = temp;
            temp->rth = 1;
            temp->right = newnode;
            cout<<"\nRight child of "<<temp->data<<" is: "<<newnode->data<<endl;
        }
        else{
            insert(temp->right,newnode);
        }
    }
}

void TBT::inorder(){
    node *temp;
    temp = head;
    do
    {
        temp = inorderSucc(temp);
        if(temp != head){
            cout<<temp->data<<"\t";
        }
    } while (temp != head);   
}

node* TBT::inorderSucc(node *temp){
    node *p;
    p = temp->right;
    if(temp->rth == 1){
        while (p->lth == 1)
        {
            p = p->left;
        }
    }
    return p;
}

int main(){
    int ch,choice;
    TBT obj;
    do
    {
        cout<<"\n\t1-Insert\n\t2-Display\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            obj.create();
            break;
        
        case 2:
            obj.inorder();
            break;

        default:
            cout<<"\nInvalid choice!!\n";
            break;
        }
        cout<<"\nPress 1 to continue: ";
        cin>>ch;
    } while (ch==1);
    
}