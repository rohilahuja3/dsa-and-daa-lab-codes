//1) LAB 1



//1.a) Write a program in C++ to handle the following task using vector
        /*a. Insert n numbers in the vector
        b. Print n numbers in the vector
        c. Swap two numbers
        d. Sort the n numbers in the vector
        e. Reverse the previously sorted numbers
        f. Delete 2 numbers from the vector
            i. One number from the beginning
            ii. Another from the last
            iii. Display the remaining numbers in the vector*/


/*#include <bits/stdc++.h>
using namespace std;

void insertion(vector <int> &rohil,int n)
{
    int num;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        rohil[i]=num;
    }
}

void print(vector <int> &rohil,int n)
{
    for(auto ele : rohil)
    {
        cout<<ele<<" ";
    }
}

void swap(vector <int> &rohil,int n)
{
    swap(rohil[0],rohil[n-1]);
}

void sort(vector <int> &rohil,int n)
{
    sort(rohil.begin(),rohil.end());
}

void reverse(vector <int> &rohil,int n)
{
    reverse(rohil.begin(),rohil.end());
}

void del_first(vector <int> &rohil,int n)
{
    rohil.erase(rohil.begin());
}

void del_last(vector <int> &rohil,int n)
{
    rohil.pop_back();
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    vector <int> rohil(n);

    insertion(rohil,n);

    cout<<"printing the vector: "<<endl;
    print(rohil,n);
    cout<<endl;
    
    cout<<endl<<"after swapping 2 elements in a vector: "<<endl;
    swap(rohil,n);
    print(rohil,n);
    cout<<endl;

    cout<<endl<<"after sorting the vector: "<<endl;
    sort(rohil,n);
    print(rohil,n);
    cout<<endl;

    cout<<endl<<"after reversing the sorted vector: "<<endl;
    reverse(rohil,n);
    print(rohil,n);
    cout<<endl;

    cout<<endl<<"after deleting the first element of the vector: "<<endl;
    del_first(rohil,n);
    print(rohil,n);
    cout<<endl;
    
    cout<<endl<<"after deleting the first and last element of the vector: "<<endl;
    del_last(rohil,n);
    print(rohil,n);

    return 0;
}*/



//1.b) Write a menu driven program in C++ to implement stack using 
    /*STL that performs following tasks:
        a. Insert the element in the stack
        b. Delete the element from the stack
        c. Display size of the stack
        d. Fetch top most element from the stack
        e. Quit*/


/*#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif

    int choice;
    stack<int> s;

    do{
        cin>>choice;

        // cout << "1. Insert element in the stack" << endl;
        // cout << "2. Pop an element from the stack" << endl;
        // cout << "3. Display size of the stack" << endl;
        // cout << "4. Display Top element of stack" << endl;
        // cout << "5. Exit" << endl;
        // cout << "Enter your choice: ";

        switch(choice)
        {
            case 1:
            int num;
            cout<<"enter the number to be pushed:"<<endl;
            cin>>num;
            s.push(num);
            break;

            case 2:
            cout<<"the top element has been poped"<<endl;
            s.pop();
            break;

            case 3:
            cout<<"the size of the satck is: "<<s.size()<<endl;
            break;

            case 4:
            cout<<"the top element is: "<<s.top()<<endl;
            break;

            // case 5:
            // cout<<"all the elements in the stack are: "<<endl;
            // for(auto ele:s)//why can't i print all the elements of stack like this
            // {
            //     cout<<ele<<" ";
            // }

            // while(!s.empty())
            // {
            //     cout<<s.top()<<" ";
            //     s.pop();
            // }

            default:
            break;
        }
    }while(choice!=0);

    return 0;
}*/



//1.c)Write a menu driven program in C++ to implement queue using STL 
    /*that performs following tasks:
            a. Insert the element in the queue
            b. Delete the element from the queue
            c. Display queue of the stack
            d. Fetch front element from the stack
            e. Fetch last element from the stack
            f. Quit*/

/*#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif

    int choice;
    queue<int> q;

    do{
        cin>>choice;

        switch(choice)
        {
            case 1:
            int num;
            cout<<"enter the number to be pushed:"<<endl;
            cin>>num;
            q.push(num);
            break;

            case 2:
            cout<<"CMD: pop an element , the front element has been popped"<<endl;
            q.pop();
            break;

            case 3:
            cout<<"the elements in the queue are: "<<endl;
            //for(int i=0;i<q.size();i++)//why is the not working with this for loop
            while(!q.empty())
            {
                cout<<q.front()<<endl;
                q.pop();
            }

            break;

            case 4:
            cout<<"the front element is: "<<q.front()<<endl;
            break;

            case 5:
            cout<<"the last element is: "<<q.back()<<endl;
            break;

            default:
            break;
        }
    }while(choice!=0);

    return 0;
}*/



//1.d)Write a program in C++ to handle the following task using list
            /*a. Insert n numbers in the List
            * b. Print n numbers in the List
            c. Sort the n numbers in the vector
            d. Reverse the previously sorted numbers*/

/*#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif

    list<int> l;
    list<int>::iterator it;
    int n;
    cout << "Enter number of elements in list: ";
    cin >> n;
    cout << endl;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }
    cout << endl;
    cout << "Elements in list: ";
    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Elements in list after sorting: ";
    l.sort();
    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Elements in list after reversing: ";
    reverse(l.begin(), l.end());
    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}*/



//1.e)Write a program in C++ using STL to find
        /*a. Minimum and Maximum among n numbers
        b. Addition (i.e. sum) of n numbers
        c. Swap the alternate numbers in the list 
        e.g. 1,2,3,4 will be 2,1,4,3 after swapping*/

/*using namespace std;

void insertion(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
}

void print(vector<int> &v)
{
    for(auto ele:v)
    {
        cout<<ele<<" ";
    }
    cout << endl;
}

pair<int,int> MinandMax(vector<int> &v)
{
    int min=v[0];
    int max=v[0];
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<min)
        {
            min=v[i];
        }
        if(v[i]>max)
        {
            max=v[i];
        }
    }
    return {min, max};
}


void SumOfnNum(vector<int> &v)
{
    // int sum=0;

    // for(auto ele:v)
    // {
    //     sum+=ele;
    // }
    // cout<<"Sum is :"<<sum<<endl;
    cout<<accumulate(v.begin(),v.end(),0);
    cout<<endl;

}

void SwapAdj(vector<int> &v)
{
    for(int i=0;i<v.size()-1;i+=2)
    {
        swap(v[i],v[i+1]);
    }
    print(v);
    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif

    int n;
    cout<<"no. of elements: "<<endl;
    cin>>n;

    vector<int> v(n);

    insertion(v);
    
    print(v);

    auto result=MinandMax(v);//pair datatype
    cout<<"min term: "<<result.first<<endl;
    cout<<"min term: "<<result.second<<endl;

    SumOfnNum(v);

    SwapAdj(v);
}*/




//2) LAB 2

//insertion sort

/*#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void insertion_sort(vector<int> &arr)
{
    for(int j=1;j<arr.size();j++)
    {
        int key=arr[j];
        int i=j-1;

        while(i>=0 and arr[i]>key)
        {
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
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
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;


    int n;
    cout<<"enter the size: "<<endl;
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        // int num;
        // cin>>num;
        arr[i]=rand();
    }

    cout<<"Before sorting: "<<endl;
    for(auto ele:arr)
    {
        cout<<ele<<endl;
    }

    insertion_sort(arr);

    cout<<"After sorting: "<<endl;
    for(auto ele:arr)
    {
        cout<<ele<<endl;
    }
}*/

//selection sort

/*#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selection_sort(vector<int> &arr)
{
    for(int i=1;i<arr.size()-1;i++)
    {
        int min=i;

        for(int j=i+1;j=arr.size();j++)
        {
            if(arr[j]<arr[min] && j!=min)
            {
                min=j;
            }
        }

        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
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
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;


    int n;
    cout<<"enter the size: "<<endl;
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        int num;
        cin>>num;
        arr[i]=num;
    }

    cout<<"Before sorting: "<<endl;
    for(auto ele:arr)
    {
        cout<<ele<<endl;
    }

    selection_sort(arr);

    cout<<"After sorting: "<<endl;
    for(auto ele:arr)
    {
        cout<<ele<<endl;
    }
}*/

/*#include<iostream>
#include<chrono>
#include<time.h>
#include<vector>

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void print(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("inputDAA.txt", "r", stdin);
    freopen("outputDAA.txt", "w", stdout);
    #endif

    int n;
    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }
    auto start = high_resolution_clock::now();
    selectionSort(arr);
    auto end = high_resolution_clock::now();
    cout<<duration_cast<microseconds>(end-start).count()<<" microseconds INCREASING"<<endl;

    for(int i=0;i<n;i++){
        arr[i] = n-i+1;
    }
    start = high_resolution_clock::now();
    selectionSort(arr);
    end = high_resolution_clock::now();
    cout<<duration_cast<microseconds>(end-start).count()<<" microseconds DECREASING"<<endl;

    for(int i=0;i<n;i++){
        arr[i] = rand()%n+1;
    }
    start = high_resolution_clock::now();
    selectionSort(arr);
    end = high_resolution_clock::now();
    cout<<duration_cast<microseconds>(end-start).count()<<" microseconds RANDOM"<<endl;

    return 0;
}*/




//3) lab3 (divide and conquer)
//   uploded in vpropel (DAA-vpropel-ques.cpp)




//4) lab 4
// fractional knapsack
//    uploded in vpropel (DAA-vpropel-ques.cpp)




// 5) lab 5

// matrix multiplication using brute force

/*#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


int display(int c[5][5], int row, int col)
{
   cout<<"\n Matrix is:\n";
   for(int i=0; i<row; i++)
   {
       for(int j=0; j<col; j++)
            cout<<c[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}


void multiply(int a[5][5], int b[5][5], int row, int col, int c1)
{
    int c[5][5];

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            c[i][j]=0;
    }

    for(int i=0; i<row; i++) 
    {
        for(int j=0; j<col; j++)
        {
            for(int k=0; k<c1; k++)
                    c[i][j]+=a[i][k]*b[k][j];
        }
    }
    cout<<"\n Matrix c after matrix multiplication is:\n";
    display(c, row, col);
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
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;


    int a[5][5], b[5][5], r1, c1, r2, c2;
    cout<<"\n Enter rows for first matrix: ";
    cin>>r1;
    cout<<"\n Enter columns for first matrix: ";
    cin>>c1;

    cout<<"\n Enter rows for second matrix: ";
    cin>>r2;
    cout<<"\n Enter columns for second matrix: ";
    cin>>c2;

    if (c1 != r2)
        return 0;

    cout<<"\n Enter elements of first matrix \n";

    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
            cin>>a[i][j];

    }

    cout<<"\n Enter elements of second matrix\n";

    for(int i=0; i<r2; i++)
    {
        for(int j=0; j<c2; j++)
            cin>>b[i][j];
    }

    display(a,r1,c1);
    display(b,r2,c2);
    multiply(a, b, r1, c2, c1);
    return 0;
}*/




// matrix multiplication using strassen method

/*#include <algorithm>
#include <iostream>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
int nextpowerof2(int k)
{
    return pow(2, int(ceil(log2(k))));
}

void display(vector<vector<int>> &matrix, int m, int n)
{
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (j != 0){
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void add(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    int i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    int i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void Strassen_algorithmA(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    // base case
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int new_size = size / 2;
        vector<int> z(new_size);
        vector<vector<int>>
            a11(new_size, z), a12(new_size, z), a21(new_size, z), a22(new_size, z),
            b11(new_size, z), b12(new_size, z), b21(new_size, z), b22(new_size, z),
            c11(new_size, z), c12(new_size, z), c21(new_size, z), c22(new_size, z),
            p1(new_size, z), p2(new_size, z), p3(new_size, z), p4(new_size, z),
            p5(new_size, z), p6(new_size, z), p7(new_size, z),
            aResult(new_size, z), bResult(new_size, z);

        int i, j;

        for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + new_size];
                a21[i][j] = A[i + new_size][j];
                a22[i][j] = A[i + new_size][j + new_size];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + new_size];
                b21[i][j] = B[i + new_size][j];
                b22[i][j] = B[i + new_size][j + new_size];
            }
        }
        // Problems
        add(a11, a22, aResult, new_size);
        add(b11, b22, bResult, new_size);
        Strassen_algorithmA(aResult, bResult, p1, new_size);
        add(a21, a22, aResult, new_size);
        Strassen_algorithmA(aResult, b11, p2, new_size);
        sub(b12, b22, bResult, new_size);
        Strassen_algorithmA(a11, bResult, p3, new_size);
        sub(b21, b11, bResult, new_size);
        Strassen_algorithmA(a22, bResult, p4, new_size);
        add(a11, a12, aResult, new_size);
        Strassen_algorithmA(aResult, b22, p5, new_size);
        sub(a21, a11, aResult, new_size);
        add(b11, b12, bResult, new_size);
        Strassen_algorithmA(aResult, bResult, p6, new_size);
        sub(a12, a22, aResult, new_size);
        add(b21, b22, bResult, new_size);
        Strassen_algorithmA(aResult, bResult, p7, new_size);
        add(p3, p5, c12, new_size);
        add(p2, p4, c21, new_size);
        add(p1, p4, aResult, new_size);
        add(aResult, p7, bResult, new_size);
        sub(bResult, p5, c11, new_size);
        add(p1, p3, aResult, new_size);
        add(aResult, p6, bResult, new_size);
        sub(bResult, p2, c22, new_size);
        for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + new_size] = c12[i][j];
                C[i + new_size][j] = c21[i][j];
                C[i + new_size][j + new_size] = c22[i][j];
            }
        }
    }
}
void Strassen_algorithm(vector<vector<int>> &A, vector<vector<int>> &B, int m, int n, int a, int b)
{
    int k = max({m, n, a, b});
    int s = nextpowerof2(k);
    vector<int> z(s);
    vector<vector<int>> Aa(s, z), Bb(s, z), Cc(s, z);
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            Aa[i][j] = A[i][j];
        }
    }
    for (unsigned int i = 0; i < a; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            Bb[i][j] = B[i][j];
        }
    }
    auto start = high_resolution_clock::now();
    Strassen_algorithmA(Aa, Bb, Cc, s);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    vector<int> temp1(b);
    vector<vector<int>> C(m, temp1);
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            C[i][j] = Cc[i][j];
        }
    }
    display(C, m, b);
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
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    vector<vector<int>> a = {{1, 2, 3,4}, {4, 5, 6,8},{5,6,7,8},{9,10,11,12}};
    vector<vector<int>> b = {{1, 2, 3, 4}, {4, 5, 6, 7},{5,6,7,8},{9,10,11,12}};
    Strassen_algorithm(a, b, 4, 4, 4, 4);
    return 0;
}*/