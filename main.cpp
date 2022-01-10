#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int p, r;
    cout << "Enter number of processes : ";
    cin >> p;
    cout << "Enter number of resources : ";
    cin >> r;
    vector<int> resources(r);
    cout << "Enter resource numbers : ";
    for (int i = 0; i < r; i++)
        cin >> resources[i];
    vector<vector<int>> allocation(p, vector<int>(r));
    cout << "Enter allocation matrix : " << endl;
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            cin >> allocation[i][j];
    vector<vector<int>> max(p, vector<int>(r));
    cout << "Enter max matrix : " << endl;
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            cin >> max[i][j];
    vector<vector<int>> need(p, vector<int>(r));
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    return 0;
}
