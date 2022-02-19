//1) implementation of stack

/*#include <stdio.h>
int top=-1;
int N;
int stack[100];

void push(int a)
{
    if(top==N-1)
    {
        printf("STACK FULL\n");
    }
    else
    {
        top++;
        stack[top]=a;
    }
}

void display()
{
    if(top==-1)
    {
        printf("STACK EMPTY\n");
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d ,",stack[i]);
        }
    }
}

void pop()
{
    if(top==-1)
    {
        printf("stack empty\n");
    }
    else
    {
        printf("\n%d\n",stack[top]);
        top--;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    //printf("size of stack:");
    scanf("%d", &N);
    
    int choice;
    do
    {
        //printf("enter ur choice 1) push, 2) display, 3) pop, 4) to end:");
        int val;
        scanf("%d", &choice);
        switch(choice){

        case 1:
        //printf("val of stack to be entered:");
        scanf("%d", &val);
        push(val);
        break;

        case 2:
        display();
        break;

        case 3:
        pop();
        break;

        default:
        break;
        }
    }
    while(choice!=4);
}*/




//2) expression eval of postfix

//237*+;
/*#include<stdio.h>
#include<string.h>
int stack[10];
int N;
int top=-1;

void push(int val)
{
    if(top==9)
    {
        printf("STACK OVERFLOW:");
    }
    else
    {
        top++;
        stack[top]=val;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("STACK EMPTY:");
    }
    else
    {
        top--;
    }
}

int Top_element()
{
    if(top==-1)
    {
        printf("STACK EMPTY:");
        return -100;
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char str[10];
    //printf("enter experesion:");
    scanf("%s",&str);//237*+;
    //printf("%d",str[0]-'0');

    int n = strlen(str);
    for(int i=0;i<n;i++)
    {
        if(str[i]=='+' || str[i]=='-' || str[i]=='*')
        {
            int operator2=Top_element(); 
            pop();//poping operator 2;
            int operator1=Top_element(); 
            pop();//poping operator 1;

            int result=0;

            switch(str[i])
            {
                case '+':
                result=operator1+operator2;
                break;

                case '-':
                result=operator1-operator2;
                break;

                case '*':
                result=operator1*operator2;
                break;

                default:
                break;
            }
            push(result);
        }
        else
        {
            push(str[i]-'0');
        }
    }
    printf("%d",Top_element());
    return 0;
}*/




//3) queue implemntation

/*#include <stdio.h>
#include <string.h>
int front=-1,rear=-1;
int queue[100];

void push(int val)
{
    if(front==-1 && rear==-1)
    {
        front=0,rear=0;
        queue[rear]=val;
    }
    else if(rear+1==100)
    {
        printf("QUEUE FULL:");
    }
    else
    {
        rear++;
        queue[rear]=val;
    }
}

void pop()
{
    if(front==-1 && rear==-1)
    {
        printf("QUEUE EMPTY:");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}

int Front()
{    
    if(front==-1 && rear==-1)
    {
        printf("QUEUE EMPTY:");
        return -100;
    }
    else 
    {
        return queue[front];
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("QUEUE EMPTY:");
    }
    else{
        for(int i=front;i<=rear;i++)
        {
            printf("%d ,",queue[i]);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int num;
    do{
    //printf("ENTER THE NUMBER TO BE PUSHED:");
    scanf("%d",&num);
    push(num);
    push(num+1);
    push(num+2);
    printf("%d \n",Front());
    display();//the output is not correct 
    }while(num!=10);
    return 0;
}*/




//4) circular queue

/*#include <stdio.h>
#include <string.h>
int front=-1,rear=-1;
int queue[5];

void push(int val)
{
    if(front==-1 && rear==-1)
    {
        front=0,rear=0;
        queue[rear]=val;
    }
    else if(front==(rear+1)%5)
    {
        printf("QUEUE FULL:");
    }
    else
    {
        rear=(rear+1)%5;
        queue[rear]=val;
    }
}

void pop()
{
    if(front==-1 && rear==-1)
    {
        printf("QUEUE EMPTY:");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        printf("%d",queue[front]);
        front=(front+1)%5;
    }
}

int Front()
{
    if(front==-1 && rear==-1)
    {
        printf("QUEUE EMPTY:");
        return -100;
    }
    else 
    {
        return queue[front];
    }
}

void display()
{
    int temp1=front;
    int temp2=rear;
    if(front==-1 && rear==-1)
    {
        printf("QUEUE EMPTY:");
    }
    else{
        /*for(int i=front;i<=rear;i=(i+1)%5)
        {
            printf("%d\n",queue[i]);
        }/

        while(1)
        {
            printf("%d\n",queue[temp1]);
            if(temp1==temp2)
            {
                break;
            }
            temp1=(temp1+1)%5;
        }
    }
}

int main()
{    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int choice;
    do
    {        
        printf("enter ur choice 1)push, 2)display, 3)pop, 4)Front:");
        int val;
        scanf("%d", &choice);
        switch(choice){

        case 1:
        printf("val of stack to be entered:");
        scanf("%d", &val);
        push(val);
        break;

        case 2:
        display();
        break;

        case 3:
        pop();
        break;

        case 4:
        Front();
        break;

        default:
        break;
        }
    }
    while(choice!=-1);
}*/




//5) singly link list implementation

/*#include<stdio.h>
#include<stdlib.h>

struct link_list{
    int data;
    struct link_list *next;
};

struct link_list *head=NULL;
struct link_list *tail=NULL;

void insert_beg(int val)
{
    struct link_list *newNode_beg=(struct link_list *)malloc(sizeof(struct link_list));

    newNode_beg->data=val;
    //newNode->next=NULL;

    newNode_beg->next=head;
    head=newNode_beg;

    if(tail==NULL)//first case
    {
        tail=head;
    }
}

void insert_end(int val)
{
    struct link_list *newNode_end=(struct link_list *)malloc(sizeof(struct link_list));

    newNode_end->data=val;
    //newNode_end->next=NULL;

    tail->next=newNode_end;
    newNode_end->next=NULL;
    tail=newNode_end;
}

void insert_any_ith(int val,int l)
{
    int pos;
    printf("ENTER POS:");
    scanf("%d",&pos);

    if(pos==0 || head==NULL)//insertion at beg
    {
        insert_beg(val);
    }

    else if(pos>=l)//insertion at end
    {
        insert_end(val);
    }

    else//insertion at any pos
    {
        struct link_list *temp1=head;
        struct link_list *temp2=head;

        for(int i=0;i<pos-1;i++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;

        struct link_list *newNode_any_ith=(struct link_list *)malloc(sizeof(struct link_list));

        newNode_any_ith->data=val;
        newNode_any_ith->next=NULL;

        temp1->next=newNode_any_ith;
        newNode_any_ith->next=temp2;
    }
}

void display()
{
    struct link_list *temp=head;
    
    while(temp!=NULL)
    {
        printf("%d, ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void delete_beg()
{
    struct link_list *temp1=head;
    head=head->next;
    free(temp1);
}

void delete_end(int l)
{
    struct link_list *temp1=head;
    printf("%d",l);
    for(int i=0;i<l-2;i++)
    {
        temp1=temp1->next;
    }
    temp1->next=NULL;
    free(tail);
    tail=temp1;
}

void delete_at_any_ith(int l)
{
    int pos;
    scanf("%d",&pos);
    printf("%d",pos);

    if(head == NULL){
        return;
    }
    if(pos==0){
        delete_beg();
    }
    else if(pos>=l){
        delete_end(l);
    }
    else{
        struct link_list* temp1 = head;
        for(int i=0;i<pos-1;i++){
            temp1 = temp1->next;
        }
        struct link_list* node_to_be_deleted = temp1->next;
        temp1->next = node_to_be_deleted->next;
        free(node_to_be_deleted);
    }    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int num_beg,num_end,num_any_ith;
    int l1=0;
    int choice;
    do{
        printf("enter ur choice:\n");
        printf("1.Beg Insertion\n2. display\n3. end insertion\n 4.insert_any_ith_pos\n 5. delete_beg\n 6. delete_end\n 7. delete_any_ith_pos\n"); 
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            scanf("%d",&num_beg);
            insert_beg(num_beg);
            l1++;
            break;

            case 2:
            display();
            break;

            case 3:
            scanf("%d",&num_end);
            insert_end(num_end);
            l1++;
            break;

            case 4:
            scanf("%d",&num_any_ith);
            insert_any_ith(num_any_ith,l1);
            l1++;
            break;

            case 5:
            delete_beg();
            l1--;
            break;

            case 6:
            delete_end(l1);
            l1--;
            break;

            case 7:
            delete_at_any_ith(l1);
            l1--;
            break;

            default:
            break;
        }
    }while(choice!=0);
    return 0;
}*/




//5.b) doubly linked list

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char acc_no[10];
    int bal;
    struct Node * next;
    struct Node * prev;
};

struct Node * head=NULL;
struct Node * tail=NULL;

struct Node *create_node(char val1[],int bal1)
{
    struct Node *newNode1=(struct Node*)malloc(sizeof(struct Node));

    if(bal1>=1500)
    {
        strcpy(newNode1->acc_no,val1);
        newNode1->bal=bal1;
        newNode1->next=NULL;
        newNode1->prev=NULL;
    }
    else{
        return NULL;
    }

    return newNode1;
}

void insert_beg(char val[],int bal)
{
    struct Node *newNode=create_node(val,bal);

    if(newNode==NULL)
    {
        return;
    }
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else{
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    }
}

void rev_display()
{
    struct Node *temp2=tail;

    while(temp2!=NULL)
    {
        printf("%s" "------" "%d\n",temp2->acc_no,temp2->bal);
        temp2=temp2->prev;
    }
    printf("\n");
}

void search_delete(char acc_to_del[])
{
    struct Node *temp=head;
    struct Node *temp2=NULL;

    while(temp!=NULL)
    {
        if(strcmp(temp->acc_no,acc_to_del)==0)
        {
            temp2=temp;

            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;

            free(temp);
            printf("ELEMENT DELETED\n");
            return;
        }
        temp=temp->next;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char acc_no[10],acc_to_del[10];
    int bal;
    //int l1=0;
    int choice;
    do{
        printf("enter ur choice:\n");
        printf("1.Beg Insertion\n2.display(rev)\n3.search and delete\n"); 
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            scanf("%s",acc_no);
            //printf("%s",acc_no);
            scanf("%d",&bal);
            insert_beg(acc_no,bal);
            //l1++;
            break;

            case 2:
            rev_display();
            break;

            case 3:
            printf("ENTER THE ACC NO. TO DELETE:");
            scanf("%s",acc_to_del);
            search_delete(acc_to_del);
            break;

            default:
            break;
        }
    }while(choice!=0);
    return 0;
}*/




//5.c) Addition of 2 singly lists 

/*#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

struct NODE *create_node(int val)
{
    struct NODE *new_Node=(struct NODE*)malloc(sizeof(struct NODE));

    new_Node->data=val;
    new_Node->next=NULL;

    return new_Node;
}

struct NODE *insert(struct NODE *head,int val)
{
    struct NODE *newNode=create_node(val);

    newNode->next=head;
    head=newNode;

    return head;    
}

void display(struct NODE *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

struct NODE *add(struct NODE *head3,struct NODE *head1,struct NODE *head2)
{
    while(head1!=NULL)
    {
        int n=head1->data+head2->data;
        head3=insert(head3,n);
        head1=head1->next;
        head2=head2->next;
    }
    return head3;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    struct NODE *head1,*head2,*head3;
    head1=head2=head3=NULL;
    int val;
    scanf("%d",&val);
    head1=insert(head1,val);
    head1=insert(head1,val+1);
    head1=insert(head1,val+3);
    head2=insert(head2,val);
    head2=insert(head2,val+1);
    head2=insert(head2,val+2);

    display(head1);
    display(head2);

    head3=add(head3,head1,head2);
    display(head3);    
}*/




//5.d) reversing a singly list

/*#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void insert_beg(int val)
{
    struct Node *newNode_beg=(struct Node *)malloc(sizeof(struct Node));

    newNode_beg->data=val;
    //newNode->next=NULL;

    newNode_beg->next=head;
    head=newNode_beg;
}

void rev()
{
    struct Node *prev=NULL;
    struct Node *current=head;
    struct Node *NEXT=current->next;

    while(current->next!=NULL)
    {
        current->next=prev;
        prev=current;
        current=NEXT;
        NEXT=current->next;
    }
    current->next=prev;
    head=current;
}

void display()
{
    struct Node *temp=head;
    
    while(temp!=NULL)
    {
        printf("%d, ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d",&n);
    insert_beg(n);
    insert_beg(n+1);
    insert_beg(n+2);
    insert_beg(n+3);
    display();
    rev();
    display();
}*/




//6) Linear search

/*#include<stdio.h>
#include<stdlib.h>

void l_search(int a[], int size)
{
    int num;//number to be searched
    int temp;
    scanf("%d",&num);

    for(int i=0;i<size;i++)
    {
        if(num==a[i])
        {
            temp=i;
        }
        else
        {
            printf("NO NOT FOUND IN THE LIST:\n");
        }
    }
    printf("NO. FOUND AT LOACATION: %d\n",temp);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int a[10]={1,2,3,4,5,6};

    l_search(a,6);
    return 0;
}*/




//7) Binary search

/*#include <stdio.h>

int bs(int a[],int n)
{
    int key;
    scanf("%d",&key);

    //initial search space
    int start=0;//a[start]=a[0]
    int end=n-1;

    while(start<=end)
    {
        int mid=(start+end)/2;

        if(a[mid]==key)
            return mid;


        if(key<a[mid])//search space = left side
        {
            end=mid-1;//start will remain same           
        }
        else//rifht arry key>a[mid]
        {
            start = mid+1;// end reamin same
        }
    }
    return -1;
}

// //using recurssion 
// int bs(int a[],int n)
// {
//     int key;
//     scanf("%d",&key);

//     //initial search space
//     int start=0;//a[start]=a[0]
//     int end=n-1;

//         if(start>end)
//         {
//             return -1;
//         }
//         int mid=(start+end)/2;

//         if(a[mid]==key)
//             return mid;

//         if(key<a[mid])//search space = left side
//         {
//             end=mid-1;//start will remain same      
//         }
//         else//rifht arry key>a[mid]
//         {
//             start = mid+1;// end reamin same
//         }
//     return -1;
// }

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int a[5]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(int);//size of array
    int result=bs(a,n);
    if(result!=-1)
    {
        printf("ELMENT FOUND at :%d",result);
    }
    else
    {
        printf("NOT FOUND");
    }
}*/




//8) Bubble sort

/*#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)//n-1 iterartion and the last one will be sorted itself
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                //swap(a[j+1],a[j]);
                temp=a[j+1];//now temp=a[j]
                a[j+1]=a[j];//now val of a[j+1] is equal to val of a[j];
                a[j]=temp;
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int a[10]={6,5,4,3,2,1,10,11};

    bubble_sort(a,8);

    for(int i=0; i<8;i++)
    {
        printf("%d ",a[i]);
    }
}*/




//9) selection sort

/*#include <stdio.h>
#include <stdlib.h>

void select_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int i_min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i_min])
            {
                i_min=j;
            }
        }
        //swap(a[i_min],a[i]);
        int temp=a[i_min];//now temp=a[j]
        a[i_min]=a[i];//now val of a[j+1] is equal to val of a[j];
        a[i]=temp;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int a[10]={6,5,4,3,2,1};

    select_sort(a,6);

    for(int i=0; i<6;i++)
    {
        printf("%d ",a[i]);
    }
}*/




//10) insertion sort

/*#include<stdio.h>
#include<stdlib.h>

void insert_sort(int a[],int n)
{
    for(int i=1;i<n;i++)//unsorted array
    {
        //int temp=i;
        int val=a[i];
        int j=i-1;//for sorted list

        while (j>=0 && a[j]>val)//loop for sorted list
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=val;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int a[10]={6,5,4,3,2,1,21,68,69,0};

    insert_sort(a,10);

    for(int i=0; i<10;i++)
    {
        printf("%d ",a[i]);
    }
}*/




//11) merge sort

/*#include <stdio.h>

void merge(int left[],int left_size,int right[],int right_size,int arr[])
{
    int i_left=0,i_right=0,i_arr=0;

    while(i_left<left_size && i_right<right_size)
    {
        if(left[i_left]<=right[i_right])
        {
            arr[i_arr]=left[i_left];
            i_left++;
            i_arr++;
        }
        else{
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

void create_merge(int arr[],int s,int mid,int e)
{
    int left_size=mid-s+1;
    int right_size=e-mid;
    int left[left_size],right[right_size];

    for(int i=0;i<left_size;i++)
    {
        left[i]=arr[s+i];
    }

    for(int i=0;i<right_size;i++)
    {
        right[i]=arr[mid+1+i];
    }
    merge(left,left_size,right,right_size,arr); 
}

void merge_sort(int arr[],int s,int e)
{
    if(s<e)
    {
        int mid=(s+e)/2;

        merge_sort(arr,s,mid);
        merge_sort(arr,mid+1,e);

        create_merge(arr,s,mid,e);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int arr[10];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}*/




//11.b) merging 2 arrays in sorted way

/*#include <stdio.h>
void merge_sorted_array(int a1[],int l1, int a2[],int l2,int a3[])
{
    int i1=0,i2=0,i3=0;

    while(i1<l1 && i2<l2)
    {
        if(a1[i1]<=a2[i2])
        {
            a3[i3]=a1[i1];
            i1++;
            i3++;
        }
        else{
        a3[i3]=a2[i2];
        i2++;
        i3++;
        }
    }

    while(i1<l1)
    {
        a3[i3++]=a1[i1++];
    }

    while(i2<l2)
    {
        a3[i3++]=a2[i2++];
    }
}

int main()
{
    int a1[4]={2,3,4,5};
    int a2[5]={1,3,7,8,10};
    int a3[9];

    merge_sorted_array(a1,4,a2,5,a3);

    for(int i=0;i<sizeof(a3)/sizeof(int);i++)
    {
        printf("%d ",a3[i]);
    }
}*/




// Merge sort in C 
/*#include<stdio.h>
#include<stdlib.h>

// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// rightCount = number of elements in R. 
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
        free(L);
        free(R);
}

int main() {
	// Code to test the MergeSort function. 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	
	int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers. 
	int i,numberOfElements;

	// finding number of elements in array as size of complete array in bytes divided by size of integer in bytes. 
	// This won't work if array is passed to the function because array
	// is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.
	// Watch this video to understand this concept - http://www.youtube.com/watch?v=CpjVucvAc3g  
	numberOfElements = sizeof(A)/sizeof(A[0]); 

	// Calling merge sort to sort the array. 
	MergeSort(A,numberOfElements);

	//printing all elements in the array once its sorted.
	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
	return 0;
}*/




//12) Quick Sort

/*#include <stdio.h>

// void swap(int *a,int *b)
// {
//     int temp=*a;
//     *b=*a;
//     *b=temp;
// }

int partition(int arr[],int start,int end)
{
    int partition_index=start;
    int pivot_element=arr[end];

    for(int i=start;i<=end-1;i++)
    {
        if(arr[i]<=pivot_element)
        {
            //swap(&arr[i],&arr[partition_index]);
            int temp=arr[i];
            arr[i]=arr[partition_index];
            arr[partition_index]=temp;
            partition_index++;
        }
    }
    //swap(&arr[end],&arr[partition_index]);
    int temp=arr[end];
    arr[end]=arr[partition_index];
    arr[partition_index]=temp;
    //printf("%d",partition_index);
    return partition_index;
}


void Quick_sort(int arr[],int start, int end)
{
    // if(start>=end)
    //     return;

    if(start<end)
    {
    int partition_index=partition(arr,start,end);

    Quick_sort(arr,start,partition_index-1);
    Quick_sort(arr,partition_index+1,end);
    }
}

void display(int arr[],int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int arr[]={6,3,2,1,5,8,4,69,0};

    Quick_sort(arr,0,8);
    display(arr,0,8);
}*/




//13) implementation of trees

/*#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST *insertion(struct BST *root,int val)
{
    struct BST *newNode=(struct BST *)malloc(sizeof(struct BST));

    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;

    if(root==NULL)
    {
        root=newNode;
    }

    else if(root->data>=val)
    {
        root->left=insertion(root->left,val);
    }

    else
    {
        root->right=insertion(root->right,val); 
    }

    return root;
}

int search(struct BST *root,int x)
{
    if(root->data==x)
        return 1;
    
    else if(root==NULL)
        return -1;

    else if(root->data>=x)
    {
        return search(root->left,x);
    }

    else
    {
        return search(root->right,x);
    }
}

int max(int a,int b)
{
    return a>b?a:b;
}

int height(struct BST *root)
{
    if(root==NULL)
        return -1;

    int height_left=height(root->left);
    int height_right=height(root->right);

    int ans=max(height_left,height_right)+1;

    return ans;
}

int min_element(struct BST *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}

void preorder(struct BST *root)//root->left->right
{
    if(root==NULL)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct BST *root)//left->root->right
{
    if(root==NULL)
        return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct BST *root)//left->right->root
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

struct BST *deletion(struct BST *root,int val)
{
    if(root==NULL)
        return root;

    else if(root->data>val)
    {
        root->left=deletion(root->left,val);
    }

    else if(root->data<val)
    {
        root->right=deletion(root->right,val);
    }

    else//val==root
    {
        if(root->left ==NULL && root->right ==NULL)//case 1 no child
        {
            printf("\ncase 1\n");
            free(root);
            root=NULL;
            //return root;
        }

        else if(root->left ==NULL && root->right !=NULL)//case 3 two child's
        {
            printf("\ncase 3\n");
            int min_val=min_element(root->right);
            root->data=min_val;
            root->right=deletion(root->right,min_val);
            //return root;
        }

        else if(root->left !=NULL )//case 2 only 1 left child
        {
            printf("\ncase 2 left\n");
            struct BST *temp = root;
            root=root->left;
            free(temp);
            //return root;            
        }

        else if(root->right!=NULL)//case 2 oly 1 right child
        {
            printf("\ncase 2 right\n");
            struct BST *temp = root;
            root=root->right;
            free(temp);
            //return root;
        }
        //return root;
    }
    return root;
}

struct BST *queue[20];
int front=-1,rear=-1;

void push(struct BST* val)
{
    if(front==-1 && rear==-1)
    {
 
        front=0,rear=0;
        queue[rear]=val;
    }
    else if((rear+1)%20==front)
    {
        printf("QUEUE FULL:");
    }
    else
    {
        rear=(rear+1)%20;
        queue[rear]=val;
    }
}
 
int isEmpty(){
	if(front==-1 && rear==-1)
    {
        printf("QUEUE EMPTY:");
        return 1;
    }
 
    return 0;
 
}

void pop()
{
    if(front==-1 && rear==-1)
    {
        printf("QUEUE EMPTY:");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front = (front+1)%20;
    }
}

struct BST* Front(){
 
	if(front==-1 && rear ==-1){
		printf("Empty\n");
		return NULL;
	}
 
	return queue[front];
 
}

void level_order_display(struct BST* root)
{
 
 	push(root);
 
	while(isEmpty()!=1){
 
		struct BST* poppedNode = Front();
		printf("%d ", poppedNode->data);
		pop();
		if(poppedNode->left != NULL)
		push(poppedNode->left);
		if(poppedNode->right !=NULL)
		push(poppedNode->right);
	}   
 
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    struct BST *root=NULL; 

    int num,x,val;
    int choice;
    do{
        //printf("\nenter ur choice:\n");
        //printf("1. Insertion\n2. search\n3. height of tree\n4. min. element of tree\n5. print preorder\n6. print inorder\n7. print postorder\n8. Deletion\n9. level order display\n"); 
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            //printf("Insert num:");
            scanf("%d",&num);
            root=insertion(root,num);
            break;

            case 2:
            //printf("NO TO BE seached:");
            scanf("%d",&x);
            printf("%d\n",search(root,x));
            break;

            case 3:
            printf("height is:%d\n",height(root));
            break;

            case 4:
            printf("%d\n",min_element(root));
            break;

            case 5:
            preorder(root);
            break;

            case 6:
            inorder(root);
            break;

            case 7:
            postorder(root);
            break;

            case 8:
            //printf("enter val to be deleted:");
            scanf("%d",&val);
            root=deletion(root,val);
            break;

            case 9:
            level_order_display(root);
            break;

            default:
            break;
        }
    }while(choice!=0);
    return 0;
}*/




//13.b) kth max elemsnt in a tree

/*#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST *insertion(struct BST *root,int val)
{
    struct BST *newNode=(struct BST *)malloc(sizeof(struct BST));

    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;

    if(root==NULL)
    {
        root=newNode;
    }

    else if(root->data>=val)
    {
        root->left=insertion(root->left,val);
    }

    else
    {
        root->right=insertion(root->right,val); 
    }

    return root;
}

void preorder(struct BST *root)
{
    if(root==NULL)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int arr[10],i;

int inorder(struct BST*root)
{
    if(root!=NULL)
    {
      inorder(root->left);
      arr[i++]=root->data;
      inorder(root->right);
    }
    return 0;
}

int kth_max_element(struct BST*root,int k)
{
   inorder(root);
   printf("%d",arr[i-k]);

   return 0;
}

int max_element(struct BST *root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}

int main()
{
    struct BST *root=NULL; 

    int num,x,val,k;
    int choice;
    do{
        printf("\nenter ur choice:\n");
        printf("1. Insertion\n2. preorder\n3. inorder\n4. kth max element\n5. max element\n"); 
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            scanf("%d",&num);
            root=insertion(root,num);
            break;

            case 2:
            preorder(root);
            break;

            case 3:
            inorder(root);
            break;

            case 4:
            scanf("%d",&k);
            kth_max_element(root,k);
            break;

            case 5:
            printf("%d\n",max_element(root));
            break;

            default:
            break;
        }
    }while(choice!=0);
    return 0;
}*/




//14) grapf implementaion

//14 a) graph with matrix
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 10000

void insertion(int matrix[][100],int u,int v,int weight,int directed)
{
    matrix[u][v]=weight;

    if(directed==0)
    {
        matrix[v][u]=weight;
    }
}

void display(int matrix[][100],int nodes)
{
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void DFS(int matrix[][100],int visited_DFS[],int root_DFS,int nodes)
{
    if(visited_DFS[root_DFS]==1)
        return;
    
    printf("%d ",root_DFS);
    visited_DFS[root_DFS]=1;

    for(int i=1;i<=nodes;i++)
    {
        if((matrix[root_DFS][i])==1)
        {
            DFS(matrix,visited_DFS,i,nodes);
        }
    }
}

int front = -1;
int rear = -1;
int Queue[100];
int visited_BFS[100]={0};
int level_BFS[100]={0};

int empty_BFS()
{
	if(front ==-1 && rear == -1)
    {
		return 1;
	}
	return 0;
}

void push_BFS(int data)
{
	if(empty_BFS()==1)
    {
		front = rear = 0;
	}
	else if((rear+1)%100 == front)
    {
		return;
	}
	else
    {
		rear = (rear+1)%100;
	}
	Queue[rear] = data;
}

void pop_BFS()
{ 
	if(empty_BFS()==1) return;
 
	if(front == rear)
    {
		front = rear = -1;
	}
	else
		front = (front+1)%100;
}

int Front_BFS()
{
	return Queue[front];
}

void BFS(int matrix[][100],int root_BFS,int nodes)
{
    push_BFS(root_BFS);
    level_BFS[root_BFS]=0;
    
    while(empty_BFS()==0)
    {
        int val=Front_BFS();
        pop_BFS();
        printf("%d ",val);
        visited_BFS[val]=1;

        for(int i=1;i<=nodes;i++)
        {
            if(matrix[val][i]==1 && visited_BFS[i]==0)
            {
                push_BFS(i);
                level_BFS[i]=level_BFS[val]+1;
                visited_BFS[i]=2;
            }
        }
    }
}

int visited_dijistra[100]={0};
int distance_dijistra[100]={inf};

void dijistra_algo(int root_dijistra,int matrix[][100],int nodes)
{
    int u = root_dijistra;

    for(int i=1;i<=nodes;i++)
    {
        if(matrix[u][i]!=0 && visited_dijistra[i]!=1)
        {
            int v=i;

            //relaxation algo
            if(distance_dijistra[u]+matrix[u][v]<distance_dijistra[v])
            {
                distance_dijistra[v]=distance_dijistra[u]+matrix[u][v];
            }
        }
    }
    visited_dijistra[u]=1;

    int temp1=inf;
    int temp2=inf;

    for(int i=1;i<=nodes;i++)
    {
        if(distance_dijistra[i]<temp1 && visited_dijistra[i]!=1)
        {
            temp1=distance_dijistra[i];
            temp2=i;
        }
    }
    
    int u_new=temp2;
    if(u_new==inf)
        return;
    
    dijistra_algo(u_new,matrix,nodes);
}

void disp_min_dist(int nodes)
{
    for(int i=1;i<=nodes;i++)
    {
        printf("%d ",distance_dijistra[i]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int nodes,edges;

    scanf("%d",&nodes);
    scanf("%d",&edges);

    int matrix[100][100];
    memset(matrix,0,sizeof(matrix));

    int u,v,weight;
    for(int i=0;i<edges;i++)
    {
        scanf("%d %d",&u,&v);
        printf("ENTER WEIGHT:");
        scanf("%d",&weight);
        insertion(matrix,u,v,weight,0);//undirected graph=0
    }

    display(matrix,nodes);

    int root_DFS;
    int visited_DFS[100]={0};
    scanf("%d",&root_DFS);
    DFS(matrix,visited_DFS,root_DFS,nodes);

    int root_BFS;
    scanf("%d",&root_BFS);
    BFS(matrix,root_BFS,nodes);

    int root_dijistra;
    printf("ROOT NODE FOR DIJASTRA:");
    scanf("%d",&root_dijistra);
    distance_dijistra[root_dijistra]=0;
    dijistra_algo(root_dijistra,matrix,nodes);
    disp_min_dist(nodes);
}*/




//14 b) graph with adjacey list
/*#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *next;
};

struct NODE *adj_list[100];
int length[100]={0};
int visited_DFS[100]={0};

struct NODE *create_node(int num)
{
    struct NODE *new_Node=(struct NODE *)malloc(sizeof(struct NODE));

    new_Node->data=num;
    new_Node->next=NULL;

    return new_Node;
}

struct NODE *insert(struct NODE *head, int val)
{
    struct NODE *newNode=create_node(val);

    newNode->next=head;
    head=newNode;

    return head;
}

void display(struct NODE *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int top=-1;
int N;
int stack[100];
int visited_cycle[100]={0};

int empty_DFS()
{
    if(top==N-1)
    {
        return 1;
    }
    return 0;
}

void push_DFS(int a)
{
    if(empty_DFS()==1)
        return;
    top++;
    stack[top]=a;
}

void pop_DFS()
{
    if(empty_DFS()==1)
        return;
    printf("%d",stack[top]);
    top--;
}

void DFS(int root)
{
    if(visited_DFS[root]==1)
        return;

    
    printf("%d",root);
    push(root);
    visited_DFS[root]=1;
    visited_cycle[root]=1;

    struct NODE *head=adj_list[root];
    struct NODE *head_cycle=adj_list[root];

    while(head!=NULL)
    {
        DFS(head->data);
        head=head->next;
    }
}

int front = -1;
int rear = -1;
int Queue[100];
int visited_BFS[100]={0};
int level_BFS[100]={0};

int empty_BFS()
{
	if(front ==-1 && rear == -1)
    {
		return 1;
	}
	return 0;
}

void push_BFS(int data)
{
	if(empty_BFS()==1)
    {
		front = rear = 0;
	}
	else if((rear+1)%100 == front)
    {
		return;
	}
	else
    {
		rear = (rear+1)%100;
	}
	Queue[rear] = data;
}

void pop_BFS()
{ 
	if(empty_BFS()==1) return;
 
	if(front == rear)
    {
		front = rear = -1;
	}
	else
		front = (front+1)%100;
}

int Front_BFS()
{
	return Queue[front];
}

void BFS(int root)
{ 
	push_BFS(root);
	level_BFS[root]=0;

	while(empty_BFS()==0)
    {
		int val = Front_BFS();
        pop_BFS();
		printf("%d ", val);
		visited_BFS[val] = 1;

		struct NODE *head = adj_list[val];
		
        while(head!=NULL)
        {
			if(visited_BFS[head->data]==0)
			{
				push_BFS(head->data);
				level_BFS[head->data] = level_BFS[val]+1;
				visited_BFS[head->data] = 2;//why?
			}
			head = head->next;
		}
	}

	printf("\n");
	
    for(int i=1;i<=6;i++)
    {
		printf("%d - > %d\n", i, level_BFS[i]);
	}

    printf("\n");

    for(int i=1;i<=6;i++)
    {
		printf("%d - > %d\n", i, visited_BFS[i]);
	}
}

int main()
{
    int nodes,edges,u,v,dfs,bfs;
    int choice;

    for(int i=1;i<nodes+1;i++)
    {
        adj_list[i]=NULL;
    }

    do{
        printf("\nenter ur choice:\n");
        printf("1. Insertion into graph\n2. Display adjaceny list\n3. DFS traversal\n4. BFS traversal\n5. No. of nodes conn. to a particular node\n"); 
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("ENTER NO. OF NODES:");
            scanf("%d",&nodes);
            printf("ENTER NO. OF EDGES:");
            scanf("%d",&edges);
            printf("ENTER EDGES IN (u,v) format:\n");

            for(int i=0;i<edges;i++)
            {
                scanf("%d%d",&u,&v);

                adj_list[u]=insert(adj_list[u],v);
                adj_list[v]=insert(adj_list[v],u);
                length[u]++;
                length[v]++;
            }
            break;

            case 2:
            for(int i=1;i<=nodes;i++)
            {
                printf("%d -> ",i);
                display(adj_list[i]);
            }
            break;

            case 3:
            printf("ENTER SOURCE VERTEX FOR DFS TRAVERSAL:");
            scanf("%d",&dfs);
            DFS(dfs);
            break;

            case 4:
            printf("ENTER SOURCE VERTEX FOR BFS TRAVERSAL:");
            scanf("%d",&bfs);
            BFS(bfs);
            break;

            case 5:
            for(int i=1;i<nodes+1;i++)
            {
                printf("%d -> ",i);
                display(adj_list[i]);
                printf("NO OF NODE CONNECTED TO NODE %d is %d\n",i,length[i]);
            }
            break;

            default:
            break;
        }
    }while(choice!=0);
    return 0;
}
*/




//15) imp ques based on binary serach tree

/*#include <stdio.h>
#include <stdlib.h>
#define infinty 10000

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST *insertion(struct BST *root,int val)
{
    struct BST *newNode=(struct BST *)malloc(sizeof(struct BST));

    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;

    if(root==NULL)
    {
        root=newNode;
    }

    else if(root->data>=val)
    {
        root->left=insertion(root->left,val);
    }

    else
    {
        root->right=insertion(root->right,val); 
    }

    return root;
}

void inorder(struct BST *root)//left->root->right
{
    if(root==NULL)
        return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void search_and_update(struct BST *root,int x,int swap_num)
{
    if(root->data==x)
        root->data=swap_num;
    
    else if(root==NULL)
        return;

    else if(root->data>=x)
    {
        search_and_update(root->left,x,swap_num);
    }

    else
    {
        search_and_update(root->right,x,swap_num);
    }
}

int min(int a, int b){

    if(a>=b) return b;
    return a;
}

int max(int a, int b){

    if(a>=b) return a;
    return b;
}

int find_min(struct BST *root)
{
    if(root==NULL)
    {
        return infinty;
    }

    int val_of_node=root->data;
    
    int left_min=find_min(root->left);
    int right_min=find_min(root->right);

    int ans = min(left_min, min(right_min,val_of_node));
    return ans;
}

int find_max(struct BST *root)
{
    if(root==NULL)
    {
        return -infinty;
    }

    int val_of_node=root->data;
    
    int left_min=find_max(root->left);
    int right_min=find_max(root->right);

    int ans = max(left_min, max(right_min,val_of_node));
    return ans;
}

int max_left_sub_tree(struct BST *root)
{
    return find_max(root);
}

int min_right_sub_tree(struct BST *root)
{
    return find_min(root);
}

int isBST(struct BST *root)
{
    if(root==NULL)
        return 1;// bst check

    int max=max_left_sub_tree(root->left);
    int min=min_right_sub_tree(root->right);

    
    if(max<=root->data && min>root->data && isBST(root->left) && isBST(root->right))
        return 1;
    
    return 0;
}

struct BST *search(struct BST *root,int x)
{
    if(root==NULL)
        return NULL;

    else if(root->data==x)
        return root;

    else if(root->data>=x)
    {
        return search(root->left,x);
    }

    else
    {
        return search(root->right,x);
    }
}

int inorder_succesor(struct BST *root,int val)
{
    if(root==NULL)
        return infinty;

    struct BST *temp=search(root,val);

    if(temp->right!=NULL)//when there is a right sub tree
    {
        //printf("CASE 1");
        return min_right_sub_tree(temp->right);//case 1
    }

    else//when there is no right sub tree
    {
        //printf("CASE 2");
        struct BST *ancestor=root;
        int succesor=infinty;

        while(ancestor->data!=val)
        {
            if(val<=ancestor->data)//left sub tree
            {
                succesor=ancestor->data;
                ancestor=ancestor->left;
            }
            else//right sub tree
            {
                ancestor=ancestor->right;
            }
        }
        return succesor;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    struct BST *root=NULL; 

    int num,x,val,swap_num,succesor;
    int choice;
    do{
        printf("\nenter ur choice:\n");
        printf("1. Insertion\n2. print inorder\n3. search and update\n4. find min element\n5. is BST or not\n6. inorder succesor\n"); 
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Insert num:");
            scanf("%d",&num);
            root=insertion(root,num);
            break;

            case 2:
            inorder(root);
            break;

            case 3:
            printf("no. to be searched:");
            scanf("%d",&x);
            printf("no. to be swapped:");
            scanf("%d",&swap_num);
            search_and_update(root,x,swap_num);
            break;

            case 4:
            printf("%d",find_min(root));
            printf("%d",find_max(root));
            break;

            case 5:
            isBST(root)==0? printf("NOT BST") : printf("BST");
            break;

            case 6:
            printf("find inorder succesor of:");
            scanf("%d",&succesor);
            printf("%d",inorder_succesor(root,succesor));
            break;

            default:
            break;
        }
    }while(choice!=0);
    return 0;
}*/





//16) minimum spanning tree implementaion 

//16 a) empire ques

/*#include <stdio.h>

struct node{
    int count;
    int parent;
};

struct node campers[100001];

struct edge{
    int u;
    int v;
    int w;
};

struct edge edge_list[100001];

int swap(struct edge a,struct edge b)
{
    struct edge temp;
}

void edge_sort(int edges)
{
    //quick sort
    int temp;
    for(int i=0;i<edges;i++)
    {
        if(edge_list[i].w>edge_list[i+1].w)
        {
            swap(edge_list[i+1],edge_list[i]);
        }
    }
}

int find(int x)
{
    if(state[x].parent==-1);
        return x;
    state[x].parent=find(state[x].parent);
    return state[x].parent;
}

void union1(int x,int y)
{
    if(find(x)==find(y))
        return;

    int p1=find(x);
    int p2=find(y);

    if(state[p1].count<state[p2].count)
    {
        state[p1].parent=p2;
        state[p2].count+=state[p1].count;
    }
    else
    {
        state[p2].parent=p1;
        state[p1].count+=state[p2].count;
    }
}

int mst(int nodes,int edges)
{
    edge_sort(edges);

    for(int i=0;i<edges;i++)
    {
        struct edge e=edge_list[i];


    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int nodes,edges;

    printf("No. of nodes/empires:");
    scanf("%d",&nodes);

    for(int i=1;i<=nodes;i++)
    {
        state[i].count=1;
        state[i].parent=-1;
    }

    printf("No. of edges/wars:");
    scanf("%d",&edges);

    int u,v,weight;
    for(int i=0;i<edges;i++)
    {
        struct edge e;
        scanf("%d%d",&e.u,&e.v);
        printf("WEIGHT:");
        scanf("%d",e.w);

        edge_list[i]=e;        

        union1(u,v);
    }

    for(int i=1;i<=nodes;i++)
    {
        printf("%d->%d\n",i,state[i].parent);
    }

    int empires=0;
    for(int i=1;i<=nodes;i++)
    {
        if(state[i].parent==-1)
        {
            empires++;
        }
    }
    printf("%d",empires);
}*/





//16 b) kruskals algo for graphs
/*#include <stdio.h>
#include <string.h>

struct Edge{
    int u,v,w;//staring pt, ending pt, wieght 
};

struct Disjoint_Node{
    int parent,count;
}disjoint_arr[100001];

int find(int x)
{
    if(disjoint_arr[x].parent==-1)
        return x;

    return disjoint_arr[x].parent=find(disjoint_arr[x].parent);
}

void merge(int u,int v)
{
    u=find(u);
    v=find(v);

    if(u==v)
        return;

    if(disjoint_arr[u].count>disjoint_arr[v].count)
    {
        disjoint_arr[v].parent=u;
        disjoint_arr[u].count+=disjoint_arr[v].count;
    }

    else{
        disjoint_arr[u].parent=v;
        disjoint_arr[v].count+=disjoint_arr[u].count;
    }
}

void bubble_sort(struct Edge edge_list[],int edges)
{
    struct Edge temp;
    for(int i=0;i<edges-1;i++)
    {
        for(int j=0;j<edges-1;j++)
        {
            if(edge_list[j].w>edge_list[j+1].w)
            {
                //swap(edge_list[j],edge_list[j+1]);
                temp=edge_list[j+1];//now temp=a[j]
                edge_list[j+1]=edge_list[j];//now val of a[j+1] is equal to val of a[j];
                edge_list[j]=temp;
            }
        }
    }
    printf("SORTED EDGE LIST ACCORDING TO WEIGHT:\n");
    for(int k=0;k<edges;k++)
    {
        printf("%d %d %d\n",edge_list[k].u,edge_list[k].v,edge_list[k].w);
    }
    printf("\n");
}

void print_edges(struct Edge edge_list[],int edges)
{
    for(int i=0;i<edges;i++)
    {
        printf("%d %d %d\n",edge_list[i].u,edge_list[i].v,edge_list[i].w);
    }
}

void Krushkal(struct Edge edge_list[],int nodes,int edges)
{
    //step 1
    //sort edges according to weight
    bubble_sort(edge_list, edges);

    //step 2
    //crate a tree
    
    // int tree[nodes+1][nodes+1];
    // memset(tree,0,sizeof(tree));

    struct Edge edge_tree[nodes-1];
    int k=0;//no. of edges in tree

    //step 3 
    //for lopp for edges check wheter that edge should be included in MST or not
    
    //with matrix
    // int cost=0;
    // for(int i=0;i<edges;i++)
    // {
    //     int u=edge_list[i].u;
    //     int v=edge_list[i].v;

    //     if(find(u)!=find(v))
    //     {
    //         tree[u][v]=1;
    //         tree[v][u]=1;
    //         cost+=edge_list[i].w;
    //         merge(u,v);
    //     }
    // }

    //with edge list
    int cost=0;
    for(int i=0;i<edges;i++)
    {
        int u=edge_list[i].u;
        int v=edge_list[i].v;

        if(find(u)!=find(v))
        {
            edge_tree[k]=edge_list[i];
            k++;
            cost+=edge_list[i].w;
            merge(u,v);
        }
    }

    //print matrix
    // for(int i=1;i<=nodes;i++)
    // {
    //     for(int j=1;j<=nodes;j++)
    //     {
    //         printf("%d ",tree[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("cost of MST=%d",cost);

    //print edge list
    print_edges(edge_tree,nodes-1);
    printf("cost of MST=%d",cost);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int nodes, edges;

    scanf("%d",&nodes);
    scanf("%d",&edges);

    for(int i=1;i<=nodes;i++)
    {
        disjoint_arr[i].parent=-1;
        disjoint_arr[i].count=1;
    }
    
    struct Edge edge_list[edges];
    for(int i=0;i<nodes;i++)//loop should be from 0 to edges
    {        
        scanf("%d%d%d",&edge_list[i].u,&edge_list[i].v,&edge_list[i].w);
    }

    Krushkal(edge_list,nodes,edges);
}*/




//16 c) my kurskals

/*#include <stdio.h>
#include <string.h>

struct Edge{
    int u;//startinhg edge
    int v;//ending edge
    int w;//weight
};

struct Disjoint_node{
    int parent;
    int count;
}disjoint_arr[100001];

void bubble_sort(struct Edge edge_list[],int edges)
{
    struct Edge temp;
    for(int i=0;i<edges-1;i++)
    {
        for(int j=0;j<edges-1;j++)
        {
            if(edge_list[j].w>edge_list[j+1].w)
            {
                //swap(edge_list[j],edge_list[j+1]);
                temp=edge_list[j+1];//now temp=a[j]
                edge_list[j+1]=edge_list[j];//now val of a[j+1] is equal to val of a[j];
                edge_list[j]=temp;
            }
        }
    }
    printf("SORTED EDGE LIST ACCORDING TO WEIGHT:\n");
    for(int k=0;k<edges;k++)
    {
        printf("%d %d %d\n",edge_list[k].u,edge_list[k].v,edge_list[k].w);
    }
    printf("\n");
}

int find(int x)
{
    int ans=disjoint_arr[x].parent;

    if(ans==-1)
    {
        return x;
    }
    return disjoint_arr[x].parent=find(ans);
}

void merge(int u,int v)
{
    if(find(u)==find(v))
    {
        return;
    }
    else
    {
        int parent_of_u=find(u);
        int parent_of_v=find(v);
        if(disjoint_arr[parent_of_u].count>disjoint_arr[parent_of_v].count)
        {
            disjoint_arr[parent_of_v].parent=parent_of_u;
            disjoint_arr[parent_of_u].count+=disjoint_arr[parent_of_v].count;
        }
        else
        {
            disjoint_arr[parent_of_u].parent=parent_of_v;
            disjoint_arr[parent_of_v].count+=disjoint_arr[parent_of_u].count;
        }
    }
}

void kurskal(struct Edge edge_list[],int nodes,int edges)
{
    //step 1 sort the edges list
    bubble_sort(edge_list,edges);

    //step 2 declare an empty tree
    struct Edge edge_tree[nodes-1];
    int k=0;//no. of edges in tree

    //step 3 if the parents are not same the merge them
    int cost=0;
    for(int i=0;i<edges;i++)
    {
        int u=edge_list[i].u;
        int v=edge_list[i].v;
        if(find(u)!=find(v))
        {
            edge_tree[k]=edge_list[i];
            k++;
            cost+=edge_list[i].w;
        }
        merge(u,v);
    }

    for(int i=0;i<nodes-1;i++)
    {
        printf("%d %d\n",edge_tree[i].u,edge_tree[i].v);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int nodes,edges;

    scanf("%d",&nodes);
    scanf("%d",&edges);

    for(int i=1;i<=nodes;i++)
    {
        disjoint_arr[i].parent=-1;
        disjoint_arr[i].count=1;
    }
    
    struct Edge edge_list[edges];
    for(int i=0;i<edges;i++)
    {
        scanf("%d%d%d",edge_list[i].u,edge_list[i].v,edge_list[i].w);
    }

    kurskal(edge_list,nodes,edges);
}*/




//16 d) prims algo
/*#include <stdio.h>

int auction(int arr[],int size)
{
    int r[10],j;
    r[j++]=arr[j++];
}

int main()
{
    int arr[10];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    auction(arr,n);
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 10000

void insertion(int matrix[][100],int u,int v,int weight,int directed)
{
    matrix[u][v]=weight;

    if(directed==0)
    {
        matrix[v][u]=weight;
    }
}

void display(int matrix[][100],int nodes)
{
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int min_element(int dist[],int mst[],int nodes)
{
    int temp=inf;
    int index=-1;
    for(int i=1;i<=nodes;i++)
    {
        if(temp>dist[i] && mst[i]==0)
        {
            index=i;
            temp=dist[i];
        }
    }
    return index;
}

void prims(int dist[],int mst[],int parent[],int nodes,int matrix[][100],int edges,int root_node)
{
    dist[root_node]=0;
    parent[root_node]=-1;

    for(int i=1;i<nodes;i++)
    {
        int u=min_element(dist,mst,nodes);
        printf("%d\n",u);
        mst[u]=1;

        for(int j=1;j<=nodes;j++)
        {
            if(matrix[u][j]>0 && mst[j]==0 && dist[j]>matrix[u][j])//relaxation
            {
                dist[j]=matrix[u][j];
                parent[j]=u;
            }
        }
    }

    for(int i=2;i<=nodes;i++)
    {
        printf("edge between: %d -> %d , %d\n",parent[i],i,matrix[parent[i]][i]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int nodes,edges;

    scanf("%d",&nodes);
    scanf("%d",&edges);

    int matrix[100][100];
    memset(matrix,0,sizeof(matrix));

    int u,v,weight;
    for(int i=0;i<edges;i++) 
    {
        scanf("%d %d",&u,&v);
        scanf("%d",&weight);
        insertion(matrix,u,v,weight,0);//undirected graph=0
    }

    display(matrix,nodes);

    int dist[100];
    memset(dist,inf,sizeof dist);
    int mst[100]={0};
    int parent[100]={0};
    int root_node;
    scanf("%d",&root_node);
    prims(dist,mst,parent,nodes,matrix,edges,root_node);
}*/




//17) heapify / heap sort

//17 a) MIN HEAP

/*#include <stdio.h>
#include <string.h>
#define inf 1000000

struct Heap{
    int size;
    int tree[100];
}h;

int parent(int i)
{
    return i>>1;//this is i/2 right shit
}

int left_child(int i)
{
    return i<<1;//this is 2*i, left shift
}

int right_child(int i)
{
     return (i<<1)+1;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insert(int ele)
{
    h.size++;
    h.tree[h.size]=ele;

    int i=h.size;
    while(h.tree[parent(i)]>h.tree[i] && i>1)
    {
        swap(&h.tree[parent(i)],&h.tree[i]);
        i=parent(i);
    }
}

void heapify(int index)
{
    int smallest=index;

    if(left_child(index)<=h.size && h.tree[left_child(index)] < h.tree[smallest])
    {
        smallest=left_child(index);
    }
    if(right_child(index)<=h.size && h.tree[right_child(index)] < h.tree[smallest])
    {
        smallest=right_child(index);
    }

    if(smallest!=index)
    {
        swap(&h.tree[smallest],&h.tree[index]);

        heapify(smallest);
    }
}

int isEmpty()
{
    if(h.size<=0)
        return 1;
    
    return 0;
}

void deleteMin()
{
    if(isEmpty())
        return;
    
    swap(&h.tree[1],&h.tree[h.size]);
    h.size--;

    heapify(1);
}

int findMin()
{
    if(isEmpty())
        return inf;
    
    return h.tree[1];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(h.tree,0,sizeof h.tree);
    h.size=0;

    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int temp;
        scanf("%d",&temp);
        insert(temp);
    }

    while(!isEmpty())//heap sort
    {
        printf("%d\n",findMin());
        deleteMin();
    }
}*/




//17 b) MAX HEAP

/*#include <stdio.h>
#include <string.h>
#define inf 1000000

struct Heap{
    int size;
    int tree[100];
}h;

int parent(int i)
{
    return i>>1;//this is i/2 right shit
}

int left_child(int i)
{
    return i<<1;//this is 2*i, left shift
}

int right_child(int i)
{
     return (i<<1)+1;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertion(int num)
{
    h.size++;
    h.tree[h.size]=num;

    int pos=h.size;
    if(pos>1 && h.tree[parent(pos)]<h.tree[pos])
    {
        swap(&h.tree[parent(pos)],&h.tree[pos]);
        pos=parent(pos);
    }
}

void heapify(int index)
{
    int largest=index;

    if(h.tree[left_child(index)]>h.tree[largest] && left_child(index)<=h.size)
    {
        largest=left_child(index);
    }

    if(h.tree[right_child(index)]>h.tree[largest] && right_child(index)<=h.size)
    {
        largest=right_child(index);
    }

    if(largest!=index)
    {
        swap(&h.tree[largest],&h.tree[index]);
        heapify(largest);
    }
}

void print_tree()
{
    int num=6;
    printf("\n");
    for(int i=1;i<=num;i++){
        printf("%d ", h.tree[i]);
    }
}

int isEmpty()
{
    if(h.size<=0)
        return 0;

    return 1;//then not empty
}

void deleteMax()
{
    if(isEmpty()==0)
        return;
    
    //print_tree();
    swap(&h.tree[1],&h.tree[h.size]);
    //h.tree[h.size]=-1;
    h.size--; 
    //print_tree();

    heapify(1);
}

int findMax()
{
    if(isEmpty()==0)
        return -inf;

    return h.tree[1];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputDSA.txt", "r", stdin);
    freopen("outputDSA.txt", "w", stdout);
    #endif

    memset(h.tree,0,sizeof h.tree);
    h.size=0;

    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int val;
        scanf("%d",&val);
        insertion(val);
    }

    while(isEmpty()!=0)//heap sort
    {
        printf("%d\n",findMax());
        deleteMax();
    }   
}*/