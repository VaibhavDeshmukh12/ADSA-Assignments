/*
There are flight paths between cities. If there is a flight between city A and city B
then there is an edge between the cities. The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. Represent thisas a graph.The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph. Check whether the graph is connected or not. Justify the storage representation used.
*/

#include <iostream>
using namespace std;

class Flight
{
    int cost[10][10], num;
    char arr[10][10], ch;

public:
    Flight()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    void accept();
    void route();
    void display();
    void connectivity();
};

void Flight::accept()
{
    cout << "\nEnter No of cities: ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter Name of city " << (i + 1) << " : ";
        cin >> arr[i];
    }
}

void Flight::route()
{
    for (int i = 0; i < num; i++)
    {
        for (int j = i; j < num; j++)
        {
            if (i == j)
                cost[i][j] = 0;
            else
            {
                cout << "\nIs there any path between " << arr[i] << " and " << arr[j] << "? (y/n): ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    cout << "\nEnter amount of fuel (LTR's) required: ";
                    cin >> cost[i][j];
                    cost[j][i] = cost[i][j];
                }
                else
                {
                    cost[i][j] = cost[j][i] = -1;
                }
            }
        }
    }
}

void Flight::connectivity()
{
    int flag = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = i; j < num; j++)
        {
            if (cost[i][j] == -1)
            {
                cout << "\nGraph is not connected as there is no path between " << arr[i] << " and " << arr[j] << endl;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
    {
        cout << "\nGraph is Connected!!" << endl;
    }
}

void Flight::display()
{
    for (int i = 0; i < num; i++)
    {
        cout << "\t" << arr[i];
    }
    cout << endl;
    for (int j = 0; j < num; j++)
    {
        cout << arr[j];
        for (int k = 0; k < num; k++)
        {
            cout << "\t" << cost[j][k];
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    Flight obj;
    do
    {
        cout << "\n\t1-Insert\n\t2-Display\n\t3-Check connectivity\n\t4-Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.accept();
            obj.route();
            break;

        case 2:
            obj.display();
            break;

        case 3:
            obj.connectivity();
            break;

        case 4:
            cout << "\n\t----THANK YOU----\n";
            break;
        }
    } while (choice != 4);
}