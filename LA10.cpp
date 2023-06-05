/*
Read the marks obtained by students of second year in an online examination of
particular subject. Find out maximum and minimum marks obtained in that subject. Use
heap data structure. Analyze the algorithm.
*/

#include<iostream>
using namespace std;

class Heap{
    int marks[10];
    public:
    Heap(){
        for(int i=0;i<10;i++){
            marks[i] = 0;
        }
    }
    void insert(int);
    void display(int);
    void showMax(int);
    void showMin();
};


void Heap::insert(int total){
    for(int i=1;i<=total;i++){
        cout<<"\nEnter marks of students: ";
        cin>>marks[i];
        int j = i;
        int parent = j/2;
        while(marks[j] <= marks[parent] && j!=0){
            int temp = marks[j];
            marks[j] = marks[parent];
            marks[parent] = temp;
            j = parent;
            parent = j/2;
        }
    }
}

void Heap::display(int total){
    for(int i=1;i<=total;i++){
        cout<<marks[i]<<"\t";
    }
}

void Heap::showMax(int total){
    int max1 = marks[1];
    for(int i = 2;i<=total;i++){
        if (marks[i] > max1)
        {
            max1 = marks[i];
        }
    }
    cout<<"\nMax marks ia: "<<max1<<endl;
}

void Heap::showMin(){
    cout<<"\nMinimum marks are: "<<marks[1]<<endl;
}

int main(){
    int ch,choice,total;
    Heap obj;
    do
    {
        cout<<"\n\t1-Insert Data\n\t2-Display\n\t3-Max Marks\n\t4-Min Marks\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter total no of students: ";
            cin>>total;
            obj.insert(total);
            break;
        
        case 2:
            obj.display(total);
            break;
        
        case 3:
            obj.showMax(total);
            break;
        
        case 4:
            obj.showMin();
            break;
        
        default:
            break;
        }
        cout<<"\nPress 1 to continue: ";
        cin>>ch;
    } while (ch==1);
    
}