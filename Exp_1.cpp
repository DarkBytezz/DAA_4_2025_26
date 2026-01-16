#include <bits/stdc++.h>
using namespace std;

int currentDepth = 0;
int maxDepth = 0;

void complexRec(int n)
{
    currentDepth++;
    maxDepth = max(maxDepth, currentDepth);

    if (n <= 2)
    {
        currentDepth--;
        return;
    }

    int p = n;
    while (p > 0)
    {
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = i ^ p;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++)
    {
        small[i] = i * i;
    }

    reverse(small.begin(), small.end()); 

    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);

    currentDepth--;
}

int main()
{
    int n = 64;   
    complexRec(n);
    cout << "Max recursion depth: " << maxDepth << endl;
    return 0;
}
