//1) LAB 2 (insertion sort)




    //vpropel ques 1 (insertion sort with binary search)

    /*while sorting the algo using insertion sort, if half of the elements are sorted
    and half is unsorted. The positions of one element, say from unsorted list is determined
    and placed at the suitable position, say "i". 
    In order to determine the position of the element from the unsorted list use binary search*/

    /*#include <iostream>
    using namespace std;

    int binarySearch(int a[], int item,
                    int low, int high)
    {
        if (high <= low)
            return (item > a[low]) ?
                    (low + 1) : low;

        int mid = (low + high) / 2;

        if (item == a[mid])
            return mid + 1;

        if (item > a[mid])
            return binarySearch(a, item,
                                mid + 1, high);
        return binarySearch(a, item, low,
                            mid - 1);
    }

    void insertionSort(int a[], int n)
    {
        int i, loc, j, k, selected;

        for (i = 1; i < n; ++i)
        {
            j = i - 1;
            selected = a[i];

            loc = binarySearch(a, selected, 0, j);

            while (j >= loc)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = selected;
        }
    }

    int main()
    {
        int a[6];
        int n = sizeof(a) / sizeof(a[0]), i;
        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        insertionSort(a, n);
        
        for (int i = 0; i < n; i++)
            cout <<" "<< a[i];

        return 0;
    }*/




    //vpropel ques 2 (insertion sort with swapping the adjacent numbers)

    /* In insertion sort we arrange the element in given order. 
    Consider that you have one given list of elements as follows
        12,31,56,45,78,68,15
    change the code to arrange the element in acending order. 
    For example after the sorting the list will be
        15 12 56 31 78 45 68 */

    /*#include <bits/stdc++.h>
    #include <iostream>
    #include <vector>
    #include <climits>
    #include <chrono>
    using namespace std;
    using namespace std::chrono;

    void print(vector<int> &arr)
    {
        for(auto ele:arr){
            cout<<ele<<" ";
        }
    }

    void swap_adj_nums(vector<int> &arr,bool flag)
    {
        for(int i=0;i<arr.size()-1;i+=2){
            swap(arr[i],arr[i+1]);
        }
        print(arr);
        cout<<endl;
    }

    void insertion_sort(vector<int> &arr,bool flag)
    {
        for(int j=1;j<arr.size();j++)
        {
            int key=arr[j];
            int i=j-1;

            while(i>=0 && arr[i]>key)
            {
                arr[i+1]=arr[i];
                i=i-1;
            }
            

            arr[i+1]=key;
            if(flag==true){
                swap(arr[i],arr[i+1]);
            }
            flag=!flag;
        }
        print(arr);
        cout<<endl;
        //swap_adj_nums(arr,flag);
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
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        bool flag=false;
        insertion_sort(arr,flag);
    }*/




    //vpropel ques 3 (insertion sort with class and vectors)

    /*Consider a class named student with student name, student registration number 
    and the student marks.
        a) sort the student usnig the student marks using insertion sort
        b) use vector*/


    //usning structure in c


    /*#include <iostream>
    using namespace std;

    struct student
    {
        string student_name;
        int student_reg_no;
        int student_marks;
    };

    void input(student arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].student_name;
            cin>>arr[i].student_reg_no;
            cin>>arr[i].student_marks;
        }
    }

    void print(student arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i].student_name<<endl;
        }
    }

    void insertion_sort(student arr[],int n)
    {
        for(int j=1;j<n;j++)
        {
            student key=arr[j];
            int i=j-1;

            while(i>=0 && arr[i].student_marks<key.student_marks)
            {
                arr[i+1]=arr[i];
                i--;
            }
            arr[i+1]=key;
        }
    }

    int main()
    {
        int n=3;
        
        student S[n];

        input(S,n);

        insertion_sort(S,n);

        print(S,n);
    }
    */


    //usning classes in c++

    /*#include<bits/stdc++.h>
    using namespace std;

    class Student
    {
        public:
        string student_name;
        int student_reg_no;
        int student_marks;

        public:
        Student(){

        }

        Student(string student_name,int student_reg_no,int student_marks)
        {
            this->student_name=student_name;
            this->student_reg_no=student_reg_no;
            this->student_marks=student_marks;
        } 
        
    };

    void print(vector<Student> &arr)
    {
        for(auto ele:arr){
            cout<<ele.student_name<<endl;
        }
    }

    void insertion_sort(vector<Student>& arr)
    {
        for(int j=1;j<arr.size();j++)
        {
            Student key=arr[j];
            int i=j-1;

            while(i>=0 && arr[i].student_marks<key.student_marks)
            {
                arr[i+1]=arr[i];
                i--;
            }
            arr[i+1]=key;
        }
    }

    int main() {

        
        int n = 3;
        vector<Student> v;
        for(int i=0;i<n;i++){
            string name;
            int marks;
            int reg_no;
            cin>>name>>marks>>reg_no;
            Student s(name, marks, reg_no);
            v.push_back(s);
        }

        insertion_sort(v);
        print(v);
    }*/




//3) Lab 3 (divide and conquer)




    //vpropel ques 1 (find min and max using divide and conquer)

    /*
    In order to find out the element in a given unsorted list of element that has 
    maximum and minimum element needs to be displayed on the screen. 
    Use divide and conquer approach to get the minimum and maximum elements.

    Input format:
    Total number of element (including duplicate): n
    Enter the total number of n element

    Output format:
    Minimum element
    Maximum element
    */

    /*#include <iostream>
    #include <vector>
    #include <climits>
    using namespace std;

    void findMinAndMax(vector<int> const &nums, int low, int high, int &min, int &max)
    {
        if (low == high){
            
            if (max < nums[low]){
                max = nums[low];
            }
    
            if (min > nums[high]){
                min = nums[high];
            }
            return;
        }
    
        if (high - low == 1){
            
            if (nums[low] < nums[high]){
                
                if (min > nums[low]){   
                    min = nums[low];
                }
    
                if (max < nums[high]){  
                    max = nums[high];
                }
            }
            
            else {
                
                if (min > nums[high]){     
                    min = nums[high];
                }
    
                if (max < nums[low]){   
                    max = nums[low];
                }
            }
            return;
        }
        int mid = (low + high) / 2;
    
        findMinAndMax(nums, low, mid, min, max);
    
        findMinAndMax(nums, mid + 1, high, min, max);
    }
    
    int main()
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        
        for(int i=0;i<nums.size();i++){
            cin>>nums[i];
        }
        
        int max = INT_MIN, min = INT_MAX;
        
        findMinAndMax(nums, 0, n - 1, min, max);

        cout << max << endl;
        cout << min << endl;
    
        return 0;
    }*/


    

    //vpropel 2 ( finding first occurrence and last occurrence of a repeated element in an array)

    /*Consider the list of elements in the array where the elements are sorted and duplicates 
    are allowed. In order to find out the position of first and last occurrence of duplicate
    elements. The basic idea of divide and conquer approach is to divide the elements into 
    similar subproblem and recursively solve them. 
    This approach is better as compared to the brute force approach since the 
    running time is reduced. Use the divide and conquer approach in order to find the 
    first and last occurrences of elements in the problem

    Input format:
    Total number of element (including duplicate): n
    Enter the total number of n element
    Enter the element to find first and last occurrence

    Output format:
    Index position of First occurrence of the element
    Index position of last occurrence of the element*/


    /*#include <iostream>
    #include <vector>
    #include <climits>
    using namespace std;

    void print(vector<int> &a)
    {
        for(auto ele:a){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    int binary_search(vector<int> &a,int key,bool isCheck)
    {
        int result=-1;
        int start=0;
        int end=a.size()-1;

        while(start<=end)
        {
            int mid=(start+end)/2;

            if(a[mid]>key)
                end=mid-1;

            else if(a[mid]<key)
                start=mid+1;

            else
            {
                result = mid;

                if(isCheck)
                    end=mid-1;

                else
                    start=mid+1;
            }
        }
        return result;
    }

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        int n;
        cin>>n;
        vector<int> a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int key;
        cin>>key;

        int start=binary_search(a,key,true);
        int end=binary_search(a,key,false);

        cout<<start<<endl;
        cout<<end<<endl;
    }*/





    //vpropel 3(find the no. of time a number is repeaded in an array) 
    
    /*While taking a walk on the beach one kid is counting the number of person 
    available on the beach. In the middle of the counting, he forgets the counting 
    and repeats few numbers. Write a program in C++ to find out the frequency 
    of occurrence the kid has counted a particular person. Use the efficient 
    way of designing the algorithm for the given problem.

    Input format:
    Total number of element (including duplicate): n
    Enter the total number of n element
    Enter the element to find occurrence

    Output format:
    Number of occurrences of the element
    */


    #include <iostream>
    #include <vector>
    #include <climits>
    using namespace std;

    void print(vector<int> &a)
    {
        for(auto ele:a){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    int binary_search(vector<int> &a,int key,bool isCheck)
    {
        int result=-1;
        int start=0;
        int end=a.size()-1;

        while(start<=end)
        {
            int mid=(start+end)/2;

            if(a[mid]>key)
                end=mid-1;

            else if(a[mid]<key)
                start=mid+1;

            else
            {
                result = mid;

                if(isCheck)
                    end=mid-1;

                else
                    start=mid+1;
            }
        }
        return result;
    }

    int main()
    {
        int n;
        cin>>n;
        vector<int> a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int key;
        cin>>key;

        int start=binary_search(a,key,true);
        int end=binary_search(a,key,false);
        
        if(start<0){
            cout<<0;
        }

        cout<<end-start+1<<endl;
    }





    //vpropel 3(find the no. of time a number is repeaded in an array) 

    /*Given a list of elements where one element has been missed out by mistake in a 
    series of element. In order to find the missing elements divide and conquer approach 
    is applied so that the time taken to find out the missing element will be logarithmic. 
    Write a program to accomplish the goal.

    Input format:
    Total number of element (including duplicate): n
    Enter the total number of n element

    Output format:
    Missing element*/


    /*#include<iostream>
    #include<vector>

    using namespace std;

    int binarySearch(vector<int> &arr, bool isLeft)
    {
        int start = 0;
        int end = arr.size() - 1;
        int diff = arr[1]-arr[0];
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(mid<=start && mid-diff<0){
                return -1;
            }
            if(arr[mid]!=arr[mid-1]+diff){
                return arr[mid-1]+diff;
            }
            else{
                if(isLeft){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }
        }
    }
    int main(){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int leftSideResult = binarySearch(a,true);
        if(leftSideResult<0){
            int rightSideResult = binarySearch(a, false);
            if(rightSideResult < 0){
                cout<<-1;
            }else{
                cout<<rightSideResult;
            }
        }
        else{
            cout<<leftSideResult;
        }
        return 0;
    }*/




//4) Lab 4

    //1) knapsack problem without dynamic problem

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

    int knapsack(vector<int> &profit, vector<int> &weight, int m, int n)
    {
        vector<int> pw_ratio(n,0);

        for(int i=0;i<n;i++){
            pw_ratio[i]=profit[i]/weight[i];
        }

        print(pw_ratio);

        sort(pw_ratio.begin(),pw_ratio.end(),greater<int>());
        print(pw_ratio);

        vector<int> final_cost(n,0);
        int final=0;

        while(final<=m)
        {
            for(int i=0;i<n;i++)
            {
                final_cost[i]=pw_ratio[i];
                final+=
            }
        }


        print(final_cost);
        return 0;
    }

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("inputDAA.txt", "r", stdin);
        freopen("outputDAA.txt", "w", stdout);
        #endif

        int capacity,n;
        cin>>capacity>>n;
        vector<int> weight(n);
        vector<int> profit(n);

        for(int i=0;i<n;i++){
            cin>>weight[i];
        }

        for(int i=0;i<n;i++){
            cin>>profit[i];
        }

        print(profit);
        print(weight);

        knapsack(profit,weight,capacity,n);
    }*/

    /*#include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    bool compare(pair<int, int> p1, pair<int, int> p2)
    {
        double v1 = (double)p1.first / p1.second;
        double v2 = (double)p2.first / p2.second;

        return v1 > v2;
    }

    int main()
    {
        int n;
        int w;

        cin >> w;
        cin >> n;

        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }

        sort(a.begin(), a.end(), compare);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (w >= a[i].second)
            {
                ans += a[i].first;
                w -= a[i].second;
                continue;
            }
            double ratio = (double)a[i].first / a[i].second;
            ans += ratio * w;
            w = 0;
            break;
        }

        cout << ans << endl;
        return 0;
    }*/