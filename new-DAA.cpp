// #include <bits/stdc++.h>
// #include <chrono>
// using namespace std;
// using namespace std::chrono;

// int main()
// {
//     #ifndef ONLINE_JUDGE
//     freopen("inputDAA.txt", "r", stdin);
//     freopen("outputDAA.txt", "w", stdout);
//     #endif
    
//     vector<int> values(10000);
//     auto f = []() -> int { return rand() % 10000; };
//     generate(values.begin(), values.end(), f);
//     auto start = high_resolution_clock::now();
//     sort(values.begin(), values.end());
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);
//     cout << "Time taken by function: "
//          << duration.count() << " microseconds" << endl;

    

// }




//fractional kanpsack
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print(vector<int> &a)
// {
//     for(auto ele:a){
//         cout<<ele<<" ";
//     }
//     cout<<endl;
// }

// int knapsack(vector<int> &profit, vector<int> &weight, int capacity, int no_of_items)
// {
//     vector<pair<int,int>> pw_ratio(no_of_items);

//     for(int i=0;i<no_of_items;i++){
//         pw_ratio[i].first=profit[i]/weight[i];
//         pw_ratio[i].second=i;
//     }

//     sort(pw_ratio.begin(),pw_ratio.end(),greater<pair<int,int>>());

//     for(int i=0;i<no_of_items;i++)
//     {
//         cout<<pw_ratio[i].first<<" ";
//         cout<<pw_ratio[i].second<<endl;
//     }
    
//     int max_profit=0;

//     for(auto i:pw_ratio)
//     {
//         if(weight[i.second]<=capacity){
//             capacity-=weight[i.second];
//             max_profit+=profit[i.second];
//         }
//         else{
//             max_profit+=capacity*i.first;
//             capacity=0;
//             break;
//         }
//     }

//     cout<<max_profit;
//     return 0;
// }

// int main()
// {
//     #ifndef ONLINE_JUDGE
//     freopen("inputDAA.txt", "r", stdin);
//     freopen("outputDAA.txt", "w", stdout);
//     #endif

//     int capacity,no_of_items;
//     cin>>capacity>>no_of_items;
//     vector<int> weight(no_of_items);
//     vector<int> profit(no_of_items);

//     for(int i=0;i<no_of_items;i++){
//         cin>>weight[i];
//     }

//     for(int i=0;i<no_of_items;i++){
//         cin>>profit[i];
//     }

//     knapsack(profit,weight,capacity,no_of_items);
// }





// A dynamic programming based (bottom up)
// #include <bits/stdc++.h>
// using namespace std;

// void print(vector<vector<int>> &a)
// {
//     for(auto ele : a)
//     {
//         for(auto ele1 : ele)
//         {
//             cout<<ele1<<" ";
//         }
//         cout<<endl;
//     }
// }

// int max(int a, int b)
// {
//     return (a > b) ? a : b;
// }

// int knapSack(int capacity, int weight[], int profit[], int n)
// {
//     int i, w;
//       vector<vector<int>> matrix(n + 1, vector<int>(capacity + 1));

//     for(i = 0; i <= n; i++)
//     {
//         for(w = 0; w <= capacity; w++)
//         {
//             if (i == 0 || w == 0) 
//                 matrix[i][w] = 0;
            
//             else if (weight[i - 1] <= w)
//                 matrix[i][w] = max(matrix[i - 1][w], matrix[i - 1][w - weight[i - 1]] + profit[i - 1]);
//             else
//                 matrix[i][w] = matrix[i - 1][w];
//         }
//     }
//     print(matrix);
//     return matrix[n][capacity];
// }

// int main()
// {
//     // 3
//     // 10 12 20
//     // 20 23 24

//     int profit[] = { 20, 23, 24 };
//     int weight[] = { 10,12,20 };

//     // int profit[] = { 60, 100, 120 };
//     // int weight[] = { 10, 20, 30 };

//     int capacity = 30;
//     int n = sizeof(profit) / sizeof(profit[0]);
//     cout << knapSack(capacity, weight, profit, n);
     
//     return 0;
// }




//knapsack using top down appproach
/*#include<bits/stdc++.h>
using namespace std;

void print_dp(vector<vector<int>> &dp)
{
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int knapsack(vector<pair<int,int>> &v,int n,int pos,int capacity,vector<vector<int>> &dp)
{
    //base case
    if(pos==n || capacity==0){
        return 0;
    }

    if(dp[pos][capacity]!=-1){
        return dp[pos][capacity];
    }

    int include,exclude;
    include=exclude=0;

    if(v[pos].second<=capacity){
        
        include=v[pos].first+knapsack(v,n,pos+1,capacity-v[pos].second,dp);
    }
    exclude=knapsack(v,n,pos+1,capacity,dp);

    return dp[pos][capacity]=max(include,exclude);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif

    // 3
    // 50
    // 60 10
    // 120 30 
    // 100 20

    int n;
    cin>>n;
    int capacity;
    cin>>capacity;
    int profit;

    vector<pair<int,int>> v(n);
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,-1));

    for(int i=0;i<n;i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }

    int final_profit=knapsack(v,n,0,capacity,dp);
    cout<<final_profit<<endl;

    print_dp(dp);
    
    return 0;
}*/




// matrix multiplication using bottom up approach
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <limits.h>
// using namespace std;

// void print_dp(vector<vector<int>> &dp)
// {
//     for(auto i:dp){
//         for(auto j:i){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }

// int bottom_up(vector<int> &dimesion_vector)
// {
//     vector<vector<int>> dp(dimesion_vector.size(),vector<int>(dimesion_vector.size(),-1));
    
//     for(int i=1;i<dimesion_vector.size();i++)
//     {
//         dp[i][i]=0;// for len=1 all digonals ==0

//         //for len = 2 => (1,2) , (2,3) , (3,4)  i is from 1 to 3 and j is 2 to 4
//         //for len = 3 => (1,3) , (2,4) i is from 1 to 2 and j from 3 to 4
//         //for len = 4 => (1,4) i is 1 and j is 4
//     }

//     for(int L=2;L<dimesion_vector.size();L++)
//     {
//         for(int  i=1;i<=dimesion_vector.size()-L;i++)
//         {
//             int j=i+L-1;

//             dp[i][j]=INT_MAX;

//             for(int k=i;k<j;k++)
//             {
//                 dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+dimesion_vector[i-1]*dimesion_vector[k]*dimesion_vector[j]);
//             }
//         }
        
//     }
//     return dp[1][dp.size()-1];
    
// }

// int main()
// {
//     #ifndef ONLINE_JUDGE
//     freopen("inputDAA.txt", "r", stdin);
//     freopen("outputDAA.txt", "w", stdout);
//     #endif
    
//     int n;
//     cin>>n;
//     vector<int> dimesion_vector(n);

//     //vector<int> dimesion_vector={2,3,4,2,5};//a1=2,3  a2=3,4  a3=4,2  a4=2,5
    
//     for(int i=0;i<n;i++){
//         cin>>dimesion_vector[i];
//     }
    
//     cout<<bottom_up(dimesion_vector)<<endl;
// }







// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print_vector(vector<int> &a)
// {
//     for(auto ele : a){
//         cout<<ele<<endl;
//     }
// }

// void print_matrix(vector<vector<int>> &a)
// {
//     for(auto ele : a){
//         for(auto ele1 : ele){
//             cout<<ele1<<" ";
//     }
//     cout<<endl;
// }

// int max1(int a, int b)
// {
//     return (a>b)?a:b;
// }


// int knapsack(int capacity, vector<int> weight, vector<int> profit, int n)
// {
//     int i, w;
//     vector<vector<int>> matrix(n+1, vector<int> (capacity+1));
    
//     for(i=0; i<=n; i++){
//         for(w=0;w<=capacity;w++){
            
//             if(i==0 || w==0)
//                 matrix[i][w]=0;
                
//             else if(weight[i-1]<=w)
//                 matrix[i][w]=max1(matrix[i-1][w], matrix[i-1][w-weight[i-1]]+ profit[i-1]);
                
//             else
//             matrix[i][w]=matrix[i-1][w];
//         }
//     }
//     print_matrix(matrix);
//     return matrix[n][capacity];
// }

// int main()
// {
//     int n;
//     cin>>n;
//     cout<<n<<endl;
    
//     vector<int> vector_start_time(n);
//     vector<int> vector_end_time(n);
    
//     for(int i=0;i<n;i++){
//         cin>>vector_start_time[i];
//     }
    
//     for(int i=0;i<n;i++){
//         cin>>vector_end_time[i];
//     }
    
//     int capacity=2;
//     cout<<knapsack(capacity, vector_start_time, vector_end_time, n);
    
//     return 0;
// }



// 1) PAT 1 question

// A person working in a garage has to complete few activities related to the cars standing in the garage for repairing. 
// For every car the time taken to         start and finish is given. 
// The person is the only one in the garage so he can take only one task at a time. 
// Find out the maximum number of activities that can be performed by the person
// Input format:

// Number of activities:

// Enter start time of n activities (only in terms of hour (24-hour format))

// Enter finish time of n activities (only in terms of hour (24-hour format))

// Output:

// Total number of activities performed by the person


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print(vector<int> &a)
// {
//     for(auto ele:a){
//         cout<<ele<<" ";
//     }
//     cout<<endl;
// }

// int knapsack(vector<int> &profit, vector<int> &weight, int capacity, int no_of_items)
// {
//     vector<pair<int,int>> pw_ratio(no_of_items);

//     for(int i=0;i<no_of_items;i++){
//         pw_ratio[i].first=profit[i]/weight[i];
//         pw_ratio[i].second=i;
//     }

//     sort(pw_ratio.begin(),pw_ratio.end(),greater<pair<int,int>>());

//     for(int i=0;i<no_of_items;i++)
//     {
//         cout<<pw_ratio[i].first<<" ";
//         cout<<pw_ratio[i].second<<endl;
//     }
    
//     int max_profit=0;

//     for(auto i:pw_ratio)
//     {
//         if(weight[i.second]<=capacity){
//             capacity-=weight[i.second];
//             max_profit+=profit[i.second];
//         }
//         else{
//             max_profit+=capacity*i.first;
//             capacity=0;
//             break;
//         }
//     }

//     // cout<<max_profit;
//     return 0;
// }

// int main()
// {

//     int capacity,no_of_items;
//     cin>>capacity>>no_of_items;
//     vector<int> weight(no_of_items);
//     vector<int> profit(no_of_items);

//     for(int i=0;i<no_of_items;i++){
//         cin>>weight[i];
//     }

//     for(int i=0;i<no_of_items;i++){
//         cin>>profit[i];
//     }

//     knapsack(profit,weight,capacity,no_of_items);
// }




// #include <iostream>
//     #include <vector>
//     #include <algorithm>
//     using namespace std;

//     void print(vector<int> &a)
//     {
//         for(auto ele:a){
//             cout<<ele<<" ";
//         }
//         cout<<endl;
//     }

//     int knapsack(vector<int> &profit, vector<int> &weight, int capacity, int no_of_items)
//     {
//         vector<pair<int,int>> pw_ratio(no_of_items);

//         for(int i=0;i<no_of_items;i++){
//             pw_ratio[i].first=profit[i]/weight[i];
//             pw_ratio[i].second=i;
//         }

//         sort(pw_ratio.begin(),pw_ratio.end(),greater<pair<int,int>>());

//         for(int i=0;i<no_of_items;i++)
//         {
//             cout<<pw_ratio[i].first<<" ";
//             cout<<pw_ratio[i].second<<endl;
//         }
        
//         int max_profit=0;

//         for(auto i:pw_ratio)
//         {
//             if(weight[i.second]<=capacity){
//                 capacity-=weight[i.second];
//                 max_profit+=profit[i.second];
//             }
//             else{
//                 max_profit+=capacity*i.first;
//                 capacity=0;
//                 break;
//             }
//         }

//         cout<<max_profit;
//         return 0;
//     }

//     int main()
//     {
//         #ifndef ONLINE_JUDGE
//         freopen("inputDAA.txt", "r", stdin);
//         freopen("outputDAA.txt", "w", stdout);
//         #endif

//         int capacity,no_of_items;
//         cin>>capacity>>no_of_items;
//         vector<int> weight(no_of_items);
//         vector<int> profit(no_of_items);

//         for(int i=0;i<no_of_items;i++){
//             cin>>weight[i];
//         }

//         for(int i=0;i<no_of_items;i++){
//             cin>>profit[i];
//         }

//         knapsack(profit,weight,capacity,no_of_items);
//     }



/*#include<bits/stdc++.h>
using namespace std;

void print_dp(vector<vector<int>> &dp)
{
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int knapsack(vector<pair<int,int>> &v,int n,int pos,int capacity,vector<vector<int>> &dp)
{
    //base case
    if(pos==n || capacity==0){
        return 0;
    }

    if(dp[pos][capacity]!=-1){
        return dp[pos][capacity];
    }

    int include,exclude;
    include=exclude=0;

    if(v[pos].second<=capacity){
        
        include=v[pos].first+knapsack(v,n,pos+1,capacity-v[pos].second,dp);
    }
    exclude=knapsack(v,n,pos+1,capacity,dp);

    return dp[pos][capacity]=max(include,exclude);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif

    // 3
    // 50
    // 60 10
    // 120 30 
    // 100 20

    int n;
    cin>>n;
    int capacity;
    cin>>capacity;
    int profit;

    vector<pair<int,int>> v(n);
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,-1));

    for(int i=0;i<n;i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }

    int final_profit=knapsack(v,n,0,capacity,dp);
    cout<<final_profit<<endl;

    print_dp(dp);
    
    return 0;
}*/


#include <bits/stdc++.h>
#define inf 100
using namespace std;

void print(vector<vector<int>> &chess)
{
    for(auto ele : chess){
        for(auto num : ele)
            cout<<num<<" ";
        cout<<endl;
    }
}

bool is_safe(vector<vector<int>> &chess,int initial_row,int pos_of_j,int final_row_size_of_chess)
{
    //check if currnt cell is being attacked from row or column
    for(int k=0;k<=final_row_size_of_chess;k++){
        if(chess[initial_row][k]==1 || chess[k][pos_of_j]==1)
            return false;
    }

    //check diagonals = first left upper diagonal
    int r=initial_row;
    int c=pos_of_j;

    while(r>=0 && c>=0){
        if(chess[r][c]==1)
            return false;
        r--;
        c--;
    }

    //check diagonals = right upper diagonal

    r=initial_row;
    c=pos_of_j;

    while(r>=0 && c<=final_row_size_of_chess){
        if(chess[r][c]==1)
            return false;
        r--;
        c++;
    }

    //if the pos is not attcaked therefore safe to put queen there
    return true;
}

int mark_blocked_state(vector<vector<int>> &chess,int initial_row,int pos_of_j,int final_row_size_of_chess)
{
    //block that particular row and cloumn
    for(int k=0;k<final_row_size_of_chess;k++){
        chess[initial_row][k]=inf;
        chess[k][initial_row]=inf;
    }

    //block right diagonal
    int i=initial_row;
    int j=pos_of_j;

    while(i>=0 && j<final_row_size_of_chess){
        for(int k=0;k<final_row_size_of_chess;k++){
            chess[i][j]=inf;
        }
        i++;
        j++;
    }
    
    //block left diagonal
    i=initial_row;
    j=pos_of_j;

    while(i>=0 && j<final_row_size_of_chess){
        for(int k=0;k<final_row_size_of_chess;k++){
            chess[i][j]=inf;
        }
        i++;
        j--;
    }

    return is_safe(chess,initial_row,j,final_row_size_of_chess);
}

bool pos_of_queen(vector<vector<int>> &chess,int initial_row,int final_row_size_of_chess)
{
    //base condition

    //there are no more rows left to traverse from and we need to print
    if(initial_row>final_row_size_of_chess){
        print(chess);
        return false;
    }

    //recursive case

    //we have to check for each pos in a row there for we need a for loop
    for(int j=0;j<=final_row_size_of_chess;j++){

        if(is_safe(chess,initial_row,j,final_row_size_of_chess)){

            chess[initial_row][j]=1;

            //checking for the rows after the initial passed row
            bool check_for_next_rows_after_initial_row = pos_of_queen(chess,initial_row+1,final_row_size_of_chess);
            if(check_for_next_rows_after_initial_row)
                return true;

            //back tracking
            chess[initial_row][j]=0;
        }
    }

    return false;//if no case works therefore no soln.
}

int main()
{    
    int n;
    cout<<"input size of matrix: "<<endl;
    cin>>n;

    vector<vector<int>> chess(n,vector<int> (n,0));

    pos_of_queen(chess,0,n-1);
}