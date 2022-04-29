// fractional knapsack

#include <bits/stdc++.h>
using namespace std;

void frac_knapsack(int n, int capacity, vector <int> &profit, vector <int> &weight)
{
    vector<pair<int,int>> pw_ratio(n);

    for(int i=0;i<n;i++)
    {
        cout<<weight[i]<<" ";
        cout<<profit[i]<<" ";
        cout<<'\n';
    }

    for(int i=0;i<n;i++)
    {
        pw_ratio[i].first = profit[i]/weight[i];
        pw_ratio[i].second = i;
    }

    sort(pw_ratio.begin(),pw_ratio.end(),greater<pair<int,int>>());

    for(int i=0;i<n;i++)
    {
        cout<<pw_ratio[i].first<<" ";
        cout<<pw_ratio[i].second<<endl;
    }

    int max_profit=0;

    for(auto i:pw_ratio)
    {
        if(weight[i.second]<=capacity)
        {
            capacity -= weight[i.second];
            max_profit += profit[i.second];
        }
        else
        {
            max_profit += capacity*i.first;
            capacity = 0;
        }
    }
    cout<<max_profit<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif

    int n,capacity;
    cin>>n;
    cin>>capacity;

    vector <int> weight(n);
    vector <int> profit(n);

    for(int i=0;i<n;i++)
        cin>>profit[i];
    
    for(int i=0;i<n;i++)
        cin>>weight[i];

    frac_knapsack(n, capacity, profit, weight);
}