/*
A Dictionary stores keywords and its meanings. Provide facility for adding new
keywords, deleting keywords, updating values of any entry. Provide facility to display
whole data sorted in ascending/ Descending order. Also find how many maximum
comparisons may require for finding any keyword. Use Binary Search Tree for
implementation.
*/

#include <iostream>
#include <string.h>
using namespace std;

typedef struct node1
{
public:
    char word[30];
    string meaning;
    struct node1 *left, *right;
} node;

class Dictionery
{
public:
    node *root, *newnode;
    Dictionery()
    {
        root = NULL;
    }
    void create();
    void insert(node *, node *);
    void display(node *);
    int compare();
    int update();
    node *deleted(node *, char[]);
    node *min(node *);
};

void Dictionery::create()
{
    int ch;
    do
    {
        newnode = new node;
        cout << "\nEnter Keyword: ";
        cin >> newnode->word;
        cout << "\nEnter Meaning of " << newnode->word << " : ";
        cin.get();
        getline(cin, newnode->meaning);
        newnode->left = NULL;
        newnode->right = NULL;
        if (root == NULL)
        {
            root = newnode;
        }
        else
        {
            insert(root, newnode);
        }
        cout << "\nPress 1 to Add more words: ";
        cin >> ch;
    } while (ch == 1);
}

void Dictionery::insert(node *temp, node *newnode)
{
    if (strcmp(newnode->word, temp->word) < 0)
    {
        if (temp->left == NULL)
        {
            temp->left = newnode;
        }
        else
        {
            insert(temp->left, newnode);
        }
    }
    else
    {
        if (temp->right == NULL)
        {
            temp->right = newnode;
        }
        else
        {
            insert(temp->right, newnode);
        }
    }
}

void Dictionery::display(node *root)
{
    node *temp;
    temp = root;
    if (temp != NULL)
    {
        display(temp->left);
        cout << "\n\tWord: " << temp->word << "\t Meaninig: " << temp->meaning;
        display(temp->right);
    }
}

int Dictionery::compare()
{
    node *temp;
    temp = root;
    int count = 0;
    char w[20];
    cout << "\nEnter Keyword to Search: ";
    cin >> w;
    while (temp != NULL)
    {
        count++;
        if (strcmp(w, temp->word) == 0)
        {
            cout << "\nNo of comparisons are: " << count;
            return 1;
        }
        if (strcmp(w, temp->word) < 0)
        {
            temp = temp->left;
        }
        if (strcmp(w, temp->word) > 0)
        {
            temp = temp->right;
        }
    }
    return -1;
}

int Dictionery::update()
{
    node *temp;
    temp = root;
    char w[20];
    cout << "\nEnter Keword to update: ";
    cin >> w;
    while (temp != NULL)
    {
        if (strcmp(w, temp->word) == 0)
        {
            cout << "\nEnter Meaning to update: ";
            cin >> temp->meaning;
            return 1;
        }
        if (strcmp(w, temp->word) < 0)
        {
            temp = temp->left;
        }
        if (strcmp(w, temp->word) > 0)
        {
            temp = temp->right;
        }
    }
    return -1;
}

node *Dictionery::deleted(node *root, char key[])
{
    node *temp;
    if (root == NULL)
    {
        cout << "\nKeyword is not found!";
        return root;
    }

    if (strcmp(key, root->word) < 0)
    {
        root->left = deleted(root->left, key);
        return root;
    }
    if (strcmp(key, root->word) > 0)
    {
        root->right = deleted(root->right, key);
        return root;
    }

    if (root->left == NULL && root->right == NULL)
    {
        temp = root;
        delete temp;
        return NULL;
    }
    if (root->right == NULL)
    {
        temp = root;
        root = root->left;
        delete temp;
        return root;
    }
    else if (root->left == NULL)
    {
        temp = root;
        root = root->right;
        delete temp;
        return root;
    }

    temp = min(root->right);
    strcpy(root->word, temp->word);
    root->right = deleted(root->right, temp->word);
    return root;
}

node *Dictionery::min(node *p)
{
    while (p->left != NULL)
    {
        p = p->left;
    }
    return p;
}

int main()
{
    int choice;
    int count;
    Dictionery obj;
    do
    {
        cout << "\n\n\t1-Insert Data\n\t2-Display Data\n\t3-No of comparisons\n\t4-Updatae Data\n\t5-Delete Data\n\t6-Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.create();
            break;

        case 2:
            obj.display(obj.root);
            break;

        case 3:
            count = obj.compare();
            if (count == 1)
            {
                cout << "\nKeword is present!!" << endl;
            }
            else
            {
                cout << "\nKeywored is not present!!" << endl;
            }
            break;

        case 4:
            count = obj.update();
            if (count == 1)
            {
                cout << "\nKeword is present!!" << endl;
            }
            else
            {
                cout << "\nKeywored is not present!!" << endl;
            }
            break;

        case 5:
            char key[20];
            cout << "\nEnter Keyword to delete: ";
            cin >> key;
            obj.root = obj.deleted(obj.root, key);
            break;

        case 6:
            cout << "\n\t----THANK YOU----\n";
            break;

        default:
            cout << "\nInvalid choice\n";
            break;
        }
    } while (choice != 6);
}