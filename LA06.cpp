/*
Represent a given graph using adjacency matrix/list to perform DFS and BFS. Use the map of the area around the college as the
graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.
*/

#include<iostream>
using namespace std;

class DBF{
    int stack[10],e,n,visit1[10],top;
    int que[10],cost[10][10],visit[10],front,rear;
    public:
    void init();
    void create();
    void display();
    void dfs();
    void bfs();
};

void DBF::init(){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            visit1[i] = 0;
            visit[i] = 0;
            stack[i] = 0;
            que[i] = 0;
            cost[i][j] = 0;
        }
    }
}

void DBF::create(){
    int i,j;
    init();
    cout<<"\nEnter no of nodes: ";
    cin>>n;
    cout<<"\nEnter no of edges: ";
    cin>>e;
    cout<<"\nEnter edges: \n";
    for (int k = 0; k < e; k++)
    {
        cin>>i>>j;
        cost[i][j] = cost[j][i] = 1;
    }
}


void DBF::display(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"   "<<cost[i][j];
        }
        cout<<endl;
    }
}


void DBF::bfs(){
    front = rear = 0;
    int k = 1,v;
    cout<<"\nEnter initial vertex for BFS: ";
    cin>>v;
    cout<<"\nBFS is: \n";
    cout<<v;
    visit[v] = 1;
    while (k < n)
    {
        for(int i=0;i<n;i++){
            if(cost[v][i] == 1 && visit[i] != 1){
                visit[i] = 1;
                que[rear++] = i;
            }
        }
        v = que[front++];
        cout<<"   "<<v;
        k++;
    }
}


void DBF::dfs(){
    top = 0;
    int k = 1,v;
    cout<<"\nEnter initial vertex for BFS: ";
    cin>>v;
    cout<<"\nBFS is: \n";
    cout<<v;
    visit1[v] = 1;
    while (k < n)
    {
        for(int i=n-1;i>=0;i--){
            if(cost[v][i] == 1 && visit1[i] != 1){
                visit1[i] = 1;
                stack[top++] = i;
            }
        }
        v = stack[--top];
        cout<<"   "<<v;
        k++;
    }
}


int main(){
    int ch,choice;
    DBF obj;
    do
    {
        cout<<"\n\t1-Create\n\t2-Display\n\t3-BFS\n\t4-DFS\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            obj.create();
            break;
        
        case 2:
            obj.display();
            break;
        
        case 3:
            obj.bfs();
            break;
        
        case 4:
            obj.dfs();
            break;
            
        }
        cout<<"\nPress 1 to continue: ";
        cin>>ch;
    } while (ch==1);
    
}