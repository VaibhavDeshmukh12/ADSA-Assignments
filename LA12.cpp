/*
Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use sequential
file to main the data.
*/

#include<iostream>
#include<fstream>
using namespace std;

class Student{
    char name[30],addr[30];
    char division[5];
    int rollno;
    public:
    int roll(){
        return rollno;
    }
    void accept();
    void display();
};


void Student::accept(){
    cout<<"\nEnter roll No: ";
    cin>>rollno;
    cout<<"\nEnter Name: ";
    cin.ignore();
    cin.getline(name,30);
    cout<<"\nEnter Division: ";
    cin>>division;
    cout<<"\nEnter Address: ";
    cin.get();
    cin.getline(addr,30);
}

void Student::display(){
    cout<<"\n\t"<<rollno<<"\t\t"<<name<<"\t\t"<<division<<"\t\t"<<addr;
}

void create(){
    int n;
    Student s;
    ofstream out("sample.txt");
    cout<<"\nEnter no of records you want to add: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        s.accept();
        out.write((char *)&s,sizeof(s));
    }
    out.close();
}

void display(){
    Student s;
    ifstream inf("sample.txt");
    while (inf.read((char *)&s,sizeof(s)))
    {
        s.display();
    }
    inf.close();
}

void addRec(){
    Student s;
    ofstream out("sample.txt",ios::app);
    s.accept();
    out.write((char *)&s, sizeof(s));
    out.close();
    cout << "Record SUCCESSFULLY Added!";
}

void search(){
    int n;
    Student s;
    ifstream inf("sample.txt");
    cout<<"\nEnter Roll no to Search: ";
    cin>>n;
    int flag = 0;
    while (inf.read((char *)&s,sizeof(s)))
    {
        if(s.roll() == n){
            cout<<"\n\tRoll NO\tName\t\tDivsion\t\tAddress";
            s.display();
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout<<"\nRecord not found!!";
    }
    inf.close();
}


void dele(){
    int n;
    int flag =0;
    Student s;
    ifstream inf("sample.txt");
    ofstream out("temp.txt");
    cout<<"\nEnter roll no to Delete record: ";
    cin>>n;
    while (inf.read((char * )&s,sizeof(s)))
    {
        if(s.roll() != n){
            out.write((char *)&s,sizeof(s));
        }
        else{
            flag = 1;
            cout<<"\nRecord deleted successfully!!"<<endl;
        }
    }
    if(flag == 0){
        cout<<"\nRecord not found!";
    }
    out.close();
    inf.close();
    remove("sample.txt");
    rename("temp.txt","sample.txt");
}


int main(){
    int choice;
    do{
        cout<<"\n\t1-Create\n\t2-Display\n\t3-Add Record\n\t4-Search Record\n\t5-Delete Record\n\t6-Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                create();
                break;
            case 2:
                cout<<"\n\n\tRoll No\t\tName\t\tDivision\tAddress";
                display();
                break;
            case 3:
                addRec();
                break;
            case 4:
                search();
                break;
            case 5:
                dele();
                break;
            case 6:
                cout<<"\n\t---THANK YOU---\n";
                break;
            
        }
    }while(choice != 6);
}