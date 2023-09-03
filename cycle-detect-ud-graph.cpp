#include <bits/stdc++.h>
using namespace std;
int parent[1000];
int parentLevel[1000];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parentLevel[leaderB] = leaderA;
            // parentSize[leaderA] += parentSize[leaderB];
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
            // parentSize[b] += parentSize[leaderA];
        }
        else if (parentLevel[a])
        {
            parentLevel[leaderB] = leaderA;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA] = +1;
        }
    }
}
int main()

{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
        {
            cout << "cycle detect between" << a << b << endl;
        }
        {
            dsu_union(a, b);
        }
    }
    cout << dsu_find(6);
    return 0;
}