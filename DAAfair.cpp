//1) STL basics 

    /*#include <iostream>
    #include <vector>
    using namespace std;

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        vector <int> rohil={10,20,30};
        rohil.push_back(15);

        vector<int>::iterator i;

        for(i=rohil.begin();i!=rohil.end();i++)
        {
            cout<<*i<<endl;
        }

        rohil.push_back(50);
        rohil.push_back(60);
        rohil.pop_back();
        rohil.erase(rohil.begin()+1);

        cout<<"new: "<<endl;
        for(i=rohil.begin();i!=rohil.end();i++)
        {
            cout<<*i<<endl;
        }
    }*/


    /*#include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        vector <int> v(5);
        int a[5];
        
        for(int i=0;i<5;i++)
        {
            // int temp;
            // cin>>temp;
            // v.push_back(temp);

            cin>>v[i];
            a[i]=v[i];
        }

        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }

        for(auto ele : v){
            cout<<ele;
        }
    }*/

    /*#include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        string input;
        getline(cin,input);

        stack<char> s;

        for(auto ch:input)
        {
            s.push(ch);
        }

        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
        return 0;
    }*/




//2) basics of classes

    /*#include <bits/stdc++.h>
    using namespace std;

    class Complex{

        public:
        //data members
        int real;
        int img;

        Complex()//this is a constructor
        {
            //cout<<"inside a constructor:";
            real=img=0;
        }

        //overloading constructor
        Complex(int a,int b)
        {
            real=a;
            img=b;
        }

        //operator overloading
        Complex operator +(Complex c)
        {
            return add(c);
        }

        //member function
        Complex add(Complex c)
        {
            Complex temp;

            temp.real=real+c.real;
            temp.img=img+c.img;

            return temp;
        }

        void print()
        {
            cout<<real<<"+"<<img<<" "<<"*"<<" "<<"i"<<endl;
        }

    };

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        // Complex c1,c2;//c1 and c2 are objects

        // c1.real=4;
        // c1.img=3;
        // c2.real=1;
        // c2.img=1;

        // Complex c3=c1.add(c2);
        // c1.print();
        // c2.print();
        // c3.print();

        Complex c1,c2(3,5);//therefore c2 will call overloaded consturctor
        Complex c3=c1+c2;
        c3.print();

        return 0;
    }*/




//3) function overloading

    /*#include <bits/stdc++.h>
    using namespace std;

    int add(int a,int b,int c)
    {
        return a+b+c;
    }
    int add(int a,int b)
    {
        return a+b;
    }
    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        cout<<add(4,5,6)<<endl;
        cout<<add(4,5);
        return 0;
    }*/




//4) priority queue or heap sort in STL

    /*#include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        //priority_queue<int> pq;//by degaut max heap

        priority_queue<int,vector<int>,greater<int>> pq;

        pq.push(4);
        pq.push(5);
        pq.push(7);
        pq.push(3);

        cout<<pq.top()<<endl;
        pq.pop();
        cout<<pq.top()<<endl;
        
        return 0;
    }*/
    
    //practice ques

    /*#include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        int t;
        cin>>t;

        while(t--)
        {
            int n, z;
            cin>>n>>z;

            // vector<int> v(n);

            // for(int i=0;i<v.size();i++)
            // {
            //     cin>>v[i];
            // }

            // while(z!=0)
            // {
            //     int max=*max_element(v.begin(),v.end());
            //     auto max_pos=max_element(v.begin(),v.end());

            //     z=z-max;
            //     max=max/2;
            //     v.at(max_pos)=max;
            // }

            priority_queue<int> pq;//by degaut max heap
            
            for(int i=0;i<n;i++)
            {
                int num;
                cin>>num;
                pq.push(num);
            }

            int count=0;
            while(z>0 && !pq.empty())
            {
                int max=pq.top();
                pq.pop();
                if(max/2>0)
                    pq.push(max/2);

                z=z-max;
                count++;
            }

            if(z>0)
            {
                cout<<"evacuate"<<endl;
            }  
            else{
                cout<<count<<endl;
            }
        }
        return 0;
    }*/




//5) map in STL

    /*#include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        int n;
        cin>>n;

        vector<string> v(n);
        map<string, int> mp;

        for(int i=0;i<n;i++)
        {
            cin>>v[i];

            if(mp.find(v[i])!=mp.end())
            {
                mp[v[i]]++;
            }
            else
                mp[v[i]]=1;
        }

        for(auto ele:mp)
        {
            cout<<ele.first<<" "<<ele.second<<endl;
        }

        return 0;
    }*/

    /*#include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        map<int, int> mp;
        mp[1]=69;
        mp[2]=70;
        //mp[key]=value; if the key exists it's value would be changed
        // if that key doesn't exists then it would create one

        //mp[key]++   ;  mep[key]=mp[key]+1 // if the key dosen't exist it would create one and assign 1
        //if the key exists increase value by 1

        //map<int, int>::iterator it;

        for(auto it=mp.begin();it!=mp.end();it++)
        {
            cout<<it->first<<endl;
            cout<<it->second<<endl;
        }

        return 0;
    }*/




//6) graph using map

    /*#include <bits/stdc++.h>
    using namespace std;

    void DFS(int start_node,map<int,vector <int>> &graph,vector<bool> &visited_arr)
    {
        if(visited_arr[start_node])// if true then if condition runs
            return;

        cout<<start_node<<"->";
        visited_arr[start_node]=true;

        for(auto neigh:graph[start_node])
        {
            DFS(neigh,graph,visited_arr);
        }
    }

    void BFS(int start_node,map<int,vector <int>> &graph,vector<bool> &visited_arr)
    {
        queue<int> q;

        q.push(start_node);
        visited_arr[start_node]=true;

        while(!q.empty())
        {
            cout<<q.front()<<" -> ";
            for(auto neigh:graph[q.front()])
            {
                if(!visited_arr[neigh])
                {
                    q.push(neigh);
                    visited_arr[neigh]=true;
                }
            }
            q.pop();
        }
    }

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif
        
        map<int,vector <int>> graph;

        int n;
        cout<<"enter no. of nodes"<<endl;
        cin>> n;

        int m;
        cout<<"enter no. of edges"<<endl;
        cin>>m;

        for(int i=0;i<m;i++)
        {
            int u,v;
            cout<<"enter the edges between 2 nos. staring pint - end point :"<<endl;

            cin>>u>>v;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(auto item:graph)
        {
            cout<<item.first<<" -> ";

            for(auto val:item.second)
            {
                cout<<val<<" ";
            }
            cout<<endl;
        }

        vector<bool> visited_arr(n+1,false);// gives false to all n+1 values
        int x;
        cout<<"starting node for DFS: "<<endl;//rohil
        cin>>x;

        DFS(x,graph,visited_arr);

        cout<<endl<<"BFS: "<<endl;
        for(int i=0;i<n+1;i++)
        {
            visited_arr[i]=false;
        }
        BFS(x,graph,visited_arr);

        return 0;
    }*/



    
//7) c++ classes

    /*#include <bits/stdc++.h>
    using namespace std;
    class Car{
        //Data members 
        double milege;
        string color;
        double price;
        int top_speed;
        int current_speed;
        public:

        //Member functions
        int apply_brakes(int speed){
            int x = 10;
            // some logic to apply brakes 
            // return new speed of car
            return x;
        }       

    };

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif
        
        return 0;
    }*/

    /*#include <bits/stdc++.h>
    using namespace std;

    class Complex{
        // data members
        public:
        int real;
        int imaginary;

        public : 

        Complex() 
        {
            // special member function name should be same as class with no return type.
            //will be called automatically via compiler as soon as the object gets created;
            real = imaginary = 0;
        }
        Complex(int real){
            this->real = real;
        }
        Complex(int real, int imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }

        Complex(const Complex &c){
            real = c.real;
            imaginary = c.imaginary;
        }
        Complex add(Complex c){
            Complex temp;
            temp.real = real+c.real;
            temp.imaginary = imaginary + c.imaginary;
            return temp;
        }

        void print(){
            cout<<real<<" + i"<<imaginary<<endl;
        }

    };

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif
        Complex c1(5, 4);
        Complex c2(5, 8);

        auto c3 = c1.add(c2);
        Complex c4 = c3; 
        Complex c5;
        c5 = c3;
        c3.print();
        c4.print();
        c5.print();

        
        return 0;
    }*/




//8)brute force and recursion

    //8.a) permuation and combination

    /*#include <bits/stdc++.h>
    #include <chrono>
    using namespace std;
    using namespace std::chrono;

    void print(vector<int> &l)
    {
        for(auto ele:l)
        {
            cout<<ele<<endl;
        }
    }

    void factorial_of_number(vector<int> &l,int start,int end)
    {
        if(start==end)
        {
            print(l);
        }

        for(int i=start;i<end;i++)
        {
            swap(l[i],l[start]);
            factorial_of_number(l,start+1,end);
            swap(l[start],l[i]);//back tracking
        }
    }
    
    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        vector<int> values(10000);
        auto f = []() -> int { return rand() % 10000; };
        generate(values.begin(), values.end(), f);
        auto start = high_resolution_clock::now();
        sort(values.begin(), values.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time: "
            << duration.count() << " msec" << endl;

        int n;
        cin>>n;

        vector<int> l(n);
        for(int i=0;i<l.size();i++)
        {
            int num;
            cin>>num;
            l[i]=num;
        }

        for(auto ele:l)
        {
            cout<<ele<<endl;
        }

        factorial_of_number(l,l[0],l[n]);
        
        return 0;
    }*/




    //8.b) Rat and maze problem

    /*#include <bits/stdc++.h>
    #include <chrono>
    using namespace std;
    using namespace std::chrono;

    void print(vector<vector<int>> &grid)
    {
        for(auto ele: grid){
            for(auto num: ele)
                cout<<num<<" ";
            cout<<endl;
        }
    }

    bool find_path_for_mice(vector<vector<int>> &grid, int initial_i, int initial_j, int final_n, int final_m)
    {
        //Base cases
        //position of i and j is out of the grid condition
        if(initial_i<0 || initial_j<0 || initial_i>final_n || initial_j>final_m)
            return false;

        //reached the goal state
        if(initial_i==final_n && initial_j==final_m){
            grid[final_n][final_m]=1;
            print(grid);
            return true;
        }

        //condition for blocked state
        if(grid[initial_i][initial_j]==2)
            return false;

        //intermidiate i and j
        //condition when case does not comes under base cases

        grid[initial_i][initial_j]=1;

        bool can_i_move_down=find_path_for_mice(grid,initial_i+1,initial_j,final_n,final_m);
        if(can_i_move_down)
            return true;

        bool can_i_move_right=find_path_for_mice(grid,initial_i,initial_j+1,final_n,final_m);
        if(can_i_move_right)
            return true;

        grid[initial_i][initial_j]=0;
        
        return false;
    }

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        vector<int> values(10000);
        auto f = []() -> int { return rand() % 10000; };
        generate(values.begin(), values.end(), f);
        auto start = high_resolution_clock::now();
        sort(values.begin(), values.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time: "
            << duration.count() << " msec" << endl;

        int n,m;
        cin>>n>>m;

        vector<vector<int>> grid(n,vector<int>(m));

        for(int i=0;i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++)
                cin>>grid[i][j];
        }

        find_path_for_mice(grid, 0, 0, n-1, m-1);//send the grid along with initial state and goal state

        return 0;
    }*/




    //8.c) n queen problem

    #include <bits/stdc++.h>
    #include <chrono>
    using namespace std;
    using namespace std::chrono;

    void print(vector<vector<int>> &grid)
    {
        for(auto ele: grid){
            for(auto num: ele)
                cout<<num<<" ";
            cout<<endl;
        }
    }

    bool is_safe(vector<vector<int>> &grid, int row_i, int pos_j,int final_row_n)
    {
        //check if currnt cell is being attacked from row or column
        for(int k=0;k<=final_row_n;k++){
            if(grid[row_i][k]==1 || grid[k][pos_j]==1)
                return false;
        }

        //check diagonals = first left upper diagonal
        int r=row_i;
        int c=pos_j;

        while(r>=0 and c>=0){
            if(grid[r][c]==1)
                return false;
            r--;
            c--;
        }

        //check diagonals = right upper diagonal

        r=row_i;
        c=pos_j;

        while(r>=0 and c<=final_row_n){
            if(grid[r][c]==1)
                return false;
            r--;
            c++;
        }

        //if the pos is not attcaked therefore safe to put queen there
        return true;
    }

    bool pos_of_n_queen(vector<vector<int>> &grid,int row_i,int final_row_n,vector<vector<int>> &sol)
    {
        //base cases
        //if all the rows are completed and i is bigger than n
        if(row_i>final_row_n){
            print(grid);
            //return true;
            cout<<"====================="<<endl;
            return false;
        }

        //recursive case
        //trying out all colums pos for a particular row
        //j should be less than final_row_j becoz no. of rows and colums are equal in chess
        for(int j=0;j<=final_row_n;j++){
            if(is_safe(grid,row_i,j,final_row_n)){
                cout<<"Safe : "<<row_i<<","<<j<<endl;
                grid[row_i][j]=1;

                bool kya_baki_rows_theek_hai=pos_of_n_queen(grid,row_i+1,final_row_n,sol);
                if(kya_baki_rows_theek_hai)
                    return true;

                grid[row_i][j]=0; //back tracking
            }
        }

        return false; //no sol occurs      
    }

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        vector<int> values(10000);
        auto f = []() -> int { return rand() % 10000; };
        generate(values.begin(), values.end(), f);
        auto start = high_resolution_clock::now();
        sort(values.begin(), values.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time: "
            << duration.count() << " msec" << endl;

        int n;
        cin>>n;

        vector<vector<int>> chess(n,vector<int>(n,0));
        vector<vector<int>> sol(n,vector<int>(n,0));

        pos_of_n_queen(chess,0,n-1,sol);//passing row not colums becoz we have to try all colums, and final state is n-1 final row

        return 0;
    }


    /*#include <bits/stdc++.h>
    #include <chrono>
    #define inf 100
    using namespace std;
    using namespace std::chrono;

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

    // int mark_blocked_state(vector<vector<int>> &chess,int initial_row,int pos_of_j,int final_row_size_of_chess)
    // {
    //     //block that particular row and cloumn
    //     for(int k=0;k<final_row_size_of_chess;k++){
    //         chess[initial_row][k]=inf;
    //         chess[k][initial_row]=inf;
    //     }

    //     //block right diagonal
    //     int i=initial_row;
    //     int j=pos_of_j;

    //     while(i>=0 && j<final_row_size_of_chess){
    //         for(int k=0;k<final_row_size_of_chess;k++){
    //             chess[i][j]=inf;
    //         }
    //         i++;
    //         j++;
    //     }
        
    //     //block left diagonal
    //     i=initial_row;
    //     j=pos_of_j;

    //     while(i>=0 && j<final_row_size_of_chess){
    //         for(int k=0;k<final_row_size_of_chess;k++){
    //             chess[i][j]=inf;
    //         }
    //         i++;
    //         j--;
    //     }

    //     return is_safe(chess,initial_row,j,final_row_size_of_chess);
    // }

    bool pos_of_queen(vector<vector<int>> &chess,int initial_row,int final_row_size_of_chess)
    {
        //base condition

        //there are no more rows left to traverse from and we need to print
        if(initial_row>final_row_size_of_chess){
            print(chess);
            return true;
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
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        vector<int> values(10000);
        auto f = []() -> int { return rand() % 10000; };
        generate(values.begin(), values.end(), f);
        auto start = high_resolution_clock::now();
        sort(values.begin(), values.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time: "
            << duration.count() << " msec" << endl;
        
        int n;
        cout<<"input size of matrix: "<<endl;
        cin>>n;

        vector<vector<int>> chess(n,vector<int> (n,0));

        pos_of_queen(chess,0,n-1);
    }*/




//9) subsequences 

    /*#include <bits/stdc++.h>
    #include <chrono>
    using namespace std;
    using namespace std::chrono;

    void Subsequence(char input_arr[],int pointer_to_input_arr,char output_arr[],int pointer_to_output_arr)
    {
        if(input_arr[pointer_to_input_arr]=='\0')
        {
            output_arr[pointer_to_output_arr]='\0';
            cout<<output_arr<<endl;

            return;
        }

        //ek baar consider nahi karna hai
        Subsequence(input_arr,pointer_to_input_arr+1,output_arr,pointer_to_output_arr);

        //ek baar consider karna hai
        output_arr[pointer_to_output_arr]=input_arr[pointer_to_input_arr];
        Subsequence(input_arr,pointer_to_input_arr+1,output_arr,pointer_to_output_arr+1);

    }

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        vector<int> values(10000);
        auto f = []() -> int { return rand() % 10000; };
        generate(values.begin(), values.end(), f);
        auto start = high_resolution_clock::now();
        sort(values.begin(), values.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time: "
            << duration.count() << " msec" << endl;

        int n;
        cout<<"Size of sting: "<<endl;
        cin>>n;

        //vector<char> input_arr(n);
        char input_arr[n+1];
        char output_arr[n+1];

        cin>>input_arr;
        input_arr[n]='\0';
        //cout<<input_arr;

        //vector<char> output_arr(n);

        Subsequence(input_arr,0,output_arr,0);
    }*/




//10) knapsack problem

//1) fractional knapsack problem using greedy approach

    /*Consider the knapsack problem having N items needs to be placed in a bag with capacity W 
    to get the maximum profit. Consider two array named profit[0..N-1] and weight[0..N-1] which 
    represent the profit and weight attached to the N objects to get the maximum profit. 
    Calculate the maximum profit earned by the system.

    Input format:
    Capacity W
    Number of object: N
    Weight: weight attached with each object
    Profit : profit attached with each object

    Output:
    Maximum profit earned*/

    /*#include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    void print(vector<int> &a)
    {
        for(auto ele:a){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    int knapsack(vector<int> &profit, vector<int> &weight, int capacity, int no_of_items)
    {
        vector<pair<int,int>> pw_ratio(no_of_items);

        for(int i=0;i<no_of_items;i++){
            pw_ratio[i].first=profit[i]/weight[i];
            pw_ratio[i].second=i;
        }

        sort(pw_ratio.begin(),pw_ratio.end(),greater<pair<int,int>>());

        for(int i=0;i<no_of_items;i++)
        {
            cout<<pw_ratio[i].first<<" ";
            cout<<pw_ratio[i].second<<endl;
        }
        
        int max_profit=0;

        for(auto i:pw_ratio)
        {
            if(weight[i.second]<=capacity){
                capacity-=weight[i.second];
                max_profit+=profit[i.second];
            }
            else{
                max_profit+=capacity*i.first;
                capacity=0;
                break;
            }   
        }

        cout<<max_profit;
        return 0;
    }

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        int capacity,no_of_items;
        cin>>capacity>>no_of_items;
        vector<int> weight(no_of_items);
        vector<int> profit(no_of_items);

        for(int i=0;i<no_of_items;i++){
            cin>>weight[i];
        }

        for(int i=0;i<no_of_items;i++){
            cin>>profit[i];
        }

        knapsack(profit,weight,capacity,no_of_items);
    }*/




//2) 0-1 kanpsack problem using dp(top down)

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
    vector<vector<int>> dp(capacity+1,vector<int>(capacity+1,-1));

    for(int i=0;i<n;i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }

    int final_profit=knapsack(v,n,0,capacity,dp);
    cout<<final_profit<<endl;

    print_dp(dp);
    
    return 0;
}*/




//11) Matrix chain multiplication

//11 a) using top down approach

/*#include <bits/stdc++.h>
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

int top_down(vector<int> &dimesion_vector,int n,int i,int j,vector<vector<int>> &dp)
{
    //base case: cost[1][1]==0
    if(i==j){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //recursive case
    int ans=INT_MAX;

    for(int k=i;k<j;k++)//partitions
    {
        int result = top_down(dimesion_vector,n,i,k,dp) + top_down(dimesion_vector,n,k+1,j,dp) + dimesion_vector[i-1]*dimesion_vector[k]*dimesion_vector[j];

        ans=min(ans,result);
    }

    dp[i][j]=ans;
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif 

    vector<int> dimesion_vector={2,3,4,2,5};
    vector<vector<int>> dp(dimesion_vector.size(),vector<int>(dimesion_vector.size(),-1));

    cout<<top_down(dimesion_vector,dimesion_vector.size(),1,4,dp)<<endl;//dimesion vector and size and 1 to 4 => cost of multiplication of 1 to 4 matrix
    print_dp(dp);
}*/




//11 b) using bottom up approach

/*#include <bits/stdc++.h>
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

int bottom_up(vector<int> &dimesion_vector)
{
    vector<vector<int>> dp(dimesion_vector.size(),vector<int>(dimesion_vector.size(),-1));
    
    for(int i=1;i<dimesion_vector.size();i++)
    {
        dp[i][i]=0;// for len=1 all digonals ==0

        //for len = 2 => (1,2) , (2,3) , (3,4)  i is from 1 to 3 and j is 2 to 4
        //for len = 3 => (1,3) , (2,4) i is from 1 to 2 and j from 3 to 4
        //for len = 4 => (1,4) i is 1 and j is 4
    }

    for(int L=2;L<dimesion_vector.size();L++)
    {
        for(int  i=1;i<=dimesion_vector.size()-L;i++)
        {
            int j=i+L-1;

            dp[i][j]=INT_MAX;

            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+dimesion_vector[i-1]*dimesion_vector[k]*dimesion_vector[j]);
            }
        }

    }

    print_dp(dp);
    return dp[1][dp.size()-1];
    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif 

    vector<int> dimesion_vector={2,3,4,2,5};//a1=2,3  a2=3,4  a3=4,2  a4=2,5
    cout<<bottom_up(dimesion_vector)<<endl;
}*/



//12) LCS 

//12 a) top down approcah

/*#include <bits/stdc++.h>
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

int top_down(string s1,int n1,string s2,int n2,int i,int j,vector<vector<int>> &dp)
{
    //base case if i and j is >= size of string
    if(i>=n1 || j>=n2){
        return 0;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    //recursive case
    if(s1[i]==s2[j]) // whenm s1[i]==s2[j] then we have to increment i and j
    {
        return dp[i][j]=1+top_down(s1,n1,s2,n2,i+1,j+1,dp);
    }

    else
    {
        return dp[i][j]=max(top_down(s1,n1,s2,n2,i,j+1,dp),top_down(s1,n1,s2,n2,i+1,j,dp));
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif 

    string s1,s2;
    cin>>s1;
    cin>>s2;
    
    vector<vector<int>> dp(s1.size(), vector<int> (s2.size(),-1));

    int i=0;
    int j=0;

    cout<<top_down(s1,s1.size(),s2,s2.size(),i,j,dp)<<endl;//i==0 and j==0
    print_dp(dp);
}*/




//12 a) bottom up approcah

/*#include <bits/stdc++.h>
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

int bottom_up(string s1,int n1,string s2,int n2)
{//s2 is in rows and s2 is in columns
    vector<vector<int>> dp(n2+1, vector<int> (n1+1,-1));

    for(int i=0;i<=max(n1,n2);i++){
        dp[0][i]=0;
        dp[i][0]=0;
    }

    for(int i=1;i<=n2;i++)//initially i is pointing a
    {
        for(int j=1;j<=n1;j++)//comparing pos i that is a with complete s2 string and j is initially pointnig at b
        {
            if(s2[i-1]==s1[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }

            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }

    print_dp(dp);
    return dp[n2][n1];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif 
    

    // input 

    // bd
    // abcd
    

    string s1,s2;
    cin>>s1;
    cin>>s2;

    cout<<bottom_up(s1,s1.size(),s2,s2.size())<<endl;
}*/