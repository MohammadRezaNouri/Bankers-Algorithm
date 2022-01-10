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
    vector<int> available(r);
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < p; j++)
            sum += allocation[j][i];
        available[i] = resources[i] - sum;
    }
    vector<int> safe(p);
    vector<int> finish(p);
    for (int i = 0; i < p; i++)
        finish[i] = 0;
    int count = 0;
    while (count < p)
    {
        int B = 0;
        for (int i = 0; i < p; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < r; j++)
                    if (need[i][j] > available[j])
                        break;
                if (j == r)
                {
                    for (int k = 0; k < r; k++)
                        available[k] += allocation[i][k];
                    safe[count++] = i;
                    finish[i] = 1;
                    B = 1;
                }
            }
        }
    }
    return 0;
}
