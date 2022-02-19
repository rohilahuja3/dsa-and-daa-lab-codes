//solve 8 puzzle problem using brute force

// X 5 2
// 1 8 3
// 4 7 6

//exchange the space and a particular number such that the number right to it is smaller.

    /*#include <bits/stdc++.h>
    #include <chrono>
    using namespace std;
    using namespace std::chrono;

    void print(vector<vector<int>> &puzzle)
    {
        for(auto ele: puzzle){
            for(auto num: ele)
                cout<<num<<" ";
            cout<<endl;
        }
    }

    void sort_the_puzzle(vector<vector<int>> &puzzle,int n)
    {
        for(int i=0;i<n;i++){
                sort(puzzle[i].begin(),puzzle[i].end());
                //sort(begin(puzzle[i]),end(puzzle[i]));
                //sort(puzzle.begin()[i],puzzle.end()[i]);
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<puzzle[0].size();j++){
        //         sort_fun(puzzle[j][i]);
        //     }
        // }

        cout<<endl;
        print(puzzle);
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

        vector<vector<int>> puzzle(n ,vector<int> (n));

        for(int i=0;i<puzzle.size();i++){
            for(int j=0;j<puzzle[0].size();j++){
                cin>>puzzle[i][j];
            }
        }

        print(puzzle);
        sort_the_puzzle(puzzle,n);
    }*/




//merge sort

/*#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void print(int arr[],int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge_2_list(int left[],int left_size,int right[],int right_size,int arr[],int start,int mid,int end)
{
    int i_left=0,i_right=0,i_arr=start;

    while(i_left<left_size && i_right<right_size)
    {
        if(left[i_left]<=right[i_right])
        {
            arr[i_arr]=left[i_left];
            i_left++;
            i_arr++;
        }
        else
        {
        arr[i_arr]=right[i_right];
        i_right++;
        i_arr++;
        }
    }

    while(i_left<left_size)
    {
        arr[i_arr++]=left[i_left++];
    }

    while(i_right<right_size)
    {
        arr[i_arr++]=right[i_right++];
    }
}

void merge(int arr[],int start,int mid,int end)
{
    int left_size=mid-start+1;
    int right_size=end-mid;
    int left[left_size],right[right_size];

    for(int i=0;i<left_size;i++)
    {
        left[i]=arr[start+i];
    }

    for(int i=0;i<right_size;i++)
    {
        right[i]=arr[mid+1+i];
    }

    merge_2_list(left,left_size,right,right_size,arr,start,mid,end);
}

void merge_sort(int arr[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
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
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int s=0;
    int e=n-1;
    merge_sort(arr,s,e);
    print(arr,n);

    return 0;
}*/


/*#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &num, int target, bool isStart)
{
int ans = -1;
int start = 0;
int end = num.size() - 1;
while (start <= end)
{
int mid = start + (end - start) / 2;
if (target < num[mid])
{
end = mid - 1;
}
else if (target > num[mid])
{
start = mid + 1;
}
else
{
ans = mid;
if (isStart)
{
end = mid - 1;
}
else
{
start = mid + 1;
}
}
}
return ans;
}
int main()
{
int n;
cin>>n;
int key;
vector<int> nums(n);
for(int i=0;i<n;i++){
cin>>nums[i];
}
cin>>key;
int start = binarySearch(nums, key, true);
int end = binarySearch(nums, key, false);
cout<<start<<endl<<end<<endl;
return 0;
}*/


/*#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void print(vector<int> &arr)
{
    for(auto ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}

// void binary_search(vector<int> &arr,int key)
// {
//     int start=0;
//     int end=arr.size()-1;

//     while(start<=end)
//     {
//         int mid=(start+end)/2;

//         if(arr[mid]==key)
//         {
//             cout<<mid;
//             break;
//         }

//         else if(arr[mid]>key)
//         {
//             end=mid-1;
//         }

//         else{
//             start=mid+1;
//         }
//     }
// }

int binary_search(vector<int> &arr,int key,int start,int end)
{
    while(start<=end)
    {
        int mid=(start+end)/2;

        if(arr[mid]==key)
        {
            return mid;
        }

        else if(arr[mid]>key)
        {
            return binary_search(arr,key,start,mid-1);
        }

        else{
            return binary_search(arr,key,mid+1,end);
        }
    }
    return -1;
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

    print(arr);

    int key;
    cin>>key;
    
    //binary_search(arr,key);

    int s=0;
    int e=arr.size()-1;
    cout<<binary_search(arr,key,s,e);
}*/