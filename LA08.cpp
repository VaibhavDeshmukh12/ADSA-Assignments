/*
Given sequence k = k1 &lt;k2 &lt; … &lt;kn of n sorted keys, with a search probability pi for
each key ki . Build the Binary search tree that has the least search cost given the
access probability for each key.
*/

#include <iostream>
using namespace std;

class OBST
{
    float p[20], q[20], wt[20][20], c[20][20];
    int r[20][20], n;

public:
    void con_obst();
    void print(int, int);
    void create();
};

void OBST::create()
{
    int i;
    cout << "\n**** PROGRAM FOR OBST ******\n";
    cout << "\nEnter the no. of nodes : ";
    cin >> n;
    cout << "\nEnter the probability for successful search :: \n";
    for (i = 1; i <= n; i++)
    {
        cout << "p[" << i << "]";
        cin >> p[i];
    }
    cout << "\nEnter the probability for unsuccessful search :: \n";
    for (i = 0; i <= n; i++)
    {
        cout << "q[" << i << "]";
        cin >> q[i];
    }
}

void OBST::con_obst(void)
{
    int i, j, k, min;
    for (i = 0; i < n; i++)
    { // Initialisation
        c[i][i] = 0.0;
        r[i][i] = 0;
        wt[i][i] = q[i];
        // for j-i=1 can be j=i+1
        wt[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;
    }
    c[n][n] = 0.0;
    r[n][n] = 0;
    wt[n][n] = q[n];
    // for j-i=2,3,4....,n
    for (i = 2; i <= n; i++)
    {
        for (j = 0; j <= n - i; j++)
        {
            wt[j][j + i] = q[j + i] + p[j + i] + wt[j][j + i - 1];
            c[j][j + i] = 9999;
            for (k = j + 1; k <= j + i; k++)
            {
                if (c[j][j + i] > (c[j][k - 1] + c[k][j + i]))
                {
                    c[j][j + i] = c[j][k - 1] + c[k][j + i];
                    r[j][j + i] = k;
                }
            }
            c[j][j + i] += wt[j][j + i];
        }
        cout << endl;
    }
    cout << "Optimal BST is :: ";
    cout << "\nw[0][" << n << "] :: " << wt[0][n];
    cout << "\nc[0][" << n << "] :: " << c[0][n];
    cout << "\nr[0][" << n << "] :: " << r[0][n];
    print(0, n);
}
void OBST::print(int l1, int r1)
{
    if (l1 >= r1)
        return;
    if (r[l1][r[l1][r1] - 1] != 0)
        cout << "\n Left child of " << r[l1][r1] << " :: " << r[l1][r[l1][r1] - 1];
    if (r[r[l1][r1]][r1] != 0)
        cout << "\n Right child of " << r[l1][r1] << " :: " << r[r[l1][r1]][r1];
    print(l1, r[l1][r1] - 1);
    print(r[l1][r1], r1);
    return;
}

int main()
{
    OBST obj;
    obj.create();
    obj.con_obst();
    return 0;
}