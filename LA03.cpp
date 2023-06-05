/*
Beginning with an empty binary search tree, Construct binary search tree by
inserting the values in the order given. After constructing a binary tree - i. Insert new
node ii. Find number of nodes in longest path iii. Minimum data value found in the
tree iv. Change a tree so that the roles of the left and right pointers are swapped at
every node v. Search a value
*/

#include<iostream>
using namespace std;

class BST{
    typedef struct Btree{
        int data;
        struct Btree *right,*left;
    }node;
    node *root;
    public:
    BST(){
        root = NULL;
    }
    void create();
    void insert(node*,node*);
    void display();
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    void search();
    void minterm();
    int depth();
    void mirror(node*);
    void changeptr();
};


void BST::create(){
    int ch;
    node * newnode;
    do
    {
        newnode = new node;
        newnode->right = NULL;
        newnode->left = NULL;
        cout<<"\nEnter element to insert: ";
        cin>>newnode->data;

        if (root == NULL)
        {
            root = newnode;
            cout<<"\nThe root of tree is: "<<root->data<<endl;
        }
        else{
            insert(root,newnode);
        }
        cout<<"\nPress 1 to continue insertion: ";
        cin>>ch;
    } while (ch==1);
}

void BST::insert(node *root,node*newnode){
    if(newnode->data < root->data){
        if (root->left == NULL)
        {
            root->left = newnode;
            cout<<"\nLeft child of "<<root->data<<" is: "<<newnode->data<<endl;
        }
        else{
            insert(root->left, newnode);
        }
    }
    else{
        if (root->right == NULL)
        {
            root->right = newnode;
            cout<<"\nRight child of "<<root->data<<" is: "<<newnode->data<<endl;
        }
        else{
            insert(root->right, newnode);
        }
    }
}


void BST::display(){
    int choice,ch;
    do
    {
        cout<<"\n\t1-Inorder\n\t2-Preorder\n\t3-Postorder\n\t4-Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            inorder(root);
            break;
        
        case 2:
            preorder(root);
            break;
        
        case 3:
            postorder(root);
            break;
        
        default:
            cout<<"\nInvalid choice!!";
            break;
        }
        cout<<"\n\nPress 1 to continue display operation: ";
        cin>>ch;
    } while (ch == 1);
}

void BST::inorder(node * root){
    if(root != NULL){
        inorder(root->left);
        cout<<"\t"<<root->data;
        inorder(root->right);
    }
}

void BST::preorder(node * root){
    if(root != NULL){
        cout<<"\t"<<root->data;
        inorder(root->left);
        inorder(root->right);
    }
}

void BST::postorder(node * root){
    if(root != NULL){
        inorder(root->left);
        inorder(root->right);
        cout<<"\t"<<root->data;
    }
}

void BST::search(){
    int n,flag = 0;
    node * temp = root;
    cout<<"\nEnter element to search: ";
    cin>>n;
    while(temp != NULL){
        if (n == temp->data)
        {
            flag = 1;
            break;
        }
        else if(n < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    if (flag == 1)
    {
        cout<<"\n"<<n<<" is present!!"<<endl;
    }
    else{
        cout<<"\n"<<n<<" is not found!!"<<endl;
    }
}

void BST::minterm(){
    node * temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    cout<<"\nMin term is: "<<temp->data<<endl;
}

int BST::depth(){
    int rcount=0,lcount=0;
    node * temp = root;
    if (temp == NULL)
    {
        cout<<"\nTree is not created yet!!";
    }
    else{
        while(temp->left != NULL){
            temp = temp->left;
            lcount += 1;
        }
        while (temp->right != NULL)
        {
            temp = temp->right;
            rcount += 1;
        }
    }
    if(lcount > rcount){
        return lcount;
    }
    else{
        return rcount;
    }
}

void BST::changeptr(){
    if(root == NULL)
        cout<<"\nTree is not created yet!!";
    else
        mirror(root);
}

void BST::mirror(node*root){
    node *temp = root,*swaped;
    if(temp->right != NULL)
        mirror(temp->right);
    if(temp->left != NULL)
        mirror(temp->left);
    
    swaped = temp->left;
    temp->left = temp->right;
    temp->right = swaped;
}

int main(){
    BST obj;
    int ch,choice,count;
    do
    {
        cout<<"\n\t1-Insert\n\t2-Display\n\t3-Min Term\n\t4-Height\n\t5-Mirror\n\t6-Search\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            obj.create();
            break;
        
        case 2:
            obj.display();
            break;

        case 3:
            obj.minterm();
            break;
        
        case 4:
            count = obj.depth();
            cout<<"\nHeight of Tree is: "<<count<<endl;
            break;
        
        case 5:
            obj.changeptr();
            break;

        case 6:
            obj.search();
            break;

        default:
            cout<<"\nInvalid choice!!\n";
            break;
        }
        cout<<"\nPress 1 to continue: ";
        cin>>choice;
    } while (choice==1);
}