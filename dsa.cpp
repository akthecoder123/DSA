#include<bits/stdc++.h>
#include <limits.h>
using namespace std;
//ios::sync_with_stdio(false);//these lines make i/o faster.use it in main.
//cin.tie(nullptr);

//hello
/*The rate at which the time, required to run a code, changes with respect to the input size, is considered the time complexity.'
Basically, the time complexity of a particular code depends on the given input size, not on the machine used to run the code.*/
/*The term space complexity generally refers to the memory space that a code uses while being executed. Again space complexity is also dependent on the machine and so we are going to represent the space complexity using the Big O notation instead of using the standard units of memory like MB, GB, etc.
Space complexity generally represents the summation of auxiliary space and the input space. Auxiliary space refers to the space that we use additionally to solve a problem. And input space refers to the space that we use to store the inputs.
*/

//TO TACKLE THE LIMIT OF DATATYPES.


int reverse(int x) {
    int rev = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // overflow check
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
            return 0;

        rev = rev * 10 + digit;
    }

    return rev;
}


//STL(Standard Template Library)

//Containers
void explainpair(){
pair<int,int>p={1,2};
cout << p.first<< p.second;

pair<int,pair<int,int>>q={1,{2,3}};
cout <<q.first<< q.second.second<<q.second.first;

pair<int,int>arr[]={{1,2},{3,4},{5,6}};
cout<< arr[1].second;
}

void explainvector(){//used to make the size variable, we use it when we do not know the size of let's say array.
vector<int> v;
vector<int>v1;//creates an empty array
v.push_back(1);//added 1 to it
v.emplace_back(2);//dynamically create one more space and added 2 

vector<pair<int,int>> a;
a.push_back({1,2});
a.emplace_back(3,4);

vector<int>b(5,20);//creates an array with 5 instances of 20 in it.
vector<int>c(b);//makes a copy of vector b.

//how do u access elements in vector?
vector<int>::iterator it=v.begin();//points at the memory of the first element
cout<< *(it);//to get other elements, inncrease 'it'
vector<int>::iterator bit=v.end();//points to the memory just after the last element
bit--;//so, to get the last element , we do bit--
cout<<*(bit);

vector<int>::reverse_iterator it=v.rend();//reverse the arr and then does same work as end.

vector<int>::reverse_iterator it=v.rbegin();//reversse the arr and does same work as begin

//we can also simply get the elements by
cout<< v[0]<<v[1];
cout<<v.back();//last element.

//printing whole vector
for(vector<int>::iterator it=v.begin();it!=v.end();it++){
    cout<<*(it);
}
for(auto it=v.begin();it!=v.end();it++){//'auto' automatically assigns 'it' to a vector iterator.
    cout<<*(it);
}
for(auto it:v){
    cout<<it;
}

//to delete elements in vector
v.erase(v.begin());
v.erase(v.begin()+1,v.begin()+3);//when we have to remove more than one elements, then give the add of starting element and then the add of element next to the last elemnt.{10,20,30,40,50,60}--->{10,40,50,60}

//adding elements in variable position
v.insert(v.begin(),5);//adds 5 at starting
v.insert(v.begin()+2,2,10);//adds 2 instances of 10 at 3rd position.
//few more are
v.size();
v.swap(v1);
v.clear();
v.empty();
}

void explainlist(){
list<int>ls;
ls.push_back(1);//{1}
ls.emplace_back(2);//{1,2}
ls.push_front(5);//{5,1,2}
//rest are same as vector.
}

void explaindeque(){
deque<int>dq;
dq.push_back(1);
dq.emplace_back(2);
dq.pop_back();
dq.pop_front();
//rest are are similar to list and vector,
}

void explainstack(){//it follows LIFO(Last In First Out).
stack<int>st;
st.push(1);//{1}
st.push(2);//{2,1}
st.push(3);//{3,2,1}
st.emplace(4);//{4,3,2,1}
cout<<st.top();//prints 4,we can't get stack's element by indexing.indexing is not valid in stack.
st.pop();//{3,2,1}
cout<<st.size();//3
stack<int>s1,s2;
s1.swap(s2);
}

void explainqueue(){//it follows FIFO(First In First Out).
queue<int>q;
q.push(1);//{1}
q.push(2);//{1,2}
q.emplace(3);//{1,2,3}
q.back()+=5;
cout<<q.back();//8
cout<<q.front();//1
q.pop();//{2,8}
cout<<q.front();//2
}

void explainPQ(){//it is queue only, but it prioritises large int,char,str,etc.
    priority_queue<int>p;
    p.push(5);//{5}
p.push(2);//{5,2}
p.push(8);//{8,5,2}

priority_queue<int,vector<int>,greater<int>>pq;//this reverses it, it prioritises small int,char,str,etc.
pq.push(5);//{5}
pq.push(2);//{2,5}
pq.push(8);//{2,5,8}
}

void explainset(){//sorts the elements and only accepts unique element.
    set<int>s;
    s.insert(2);//{2}
    s.insert(1);//{1,2}
    s.emplace(8);//{1,2,8}
    s.insert(8);//{1,2,8}

    auto it=s.find(2);//'it' is an iteator that points on 2
    auto it=s.find(10);//as 10 is not in the set, so it points at s.end()
}

void explainmultiset(){
    multiset<int>ms;
    ms.insert(1);//{1}
    ms.insert(1);//{1,1}
    ms.insert(1);//{1,1,1}
    ms.erase(1);//all 1's are erased
    ms.count(1);//3
    ms.erase(ms.find(1));//erases only one 1 as find gives the iterator to one 1 only.
    ms.erase(ms.find(1),next(ms.find(1),2));//erases all 1's.
}

void explainUset(){//unique but not sorted.
    //bound functions does not work.
}

void explainMap(){//we map here keys and values, like student of same names gets distinguished by their roll number. Roll no. is unique i.e. keys are unique.
    //so, map stores in key value pair, and it stores unique keys in sorted order.
    map<int,int>m;//<key,value>
    m[1]=10;//[{1,10}]
    m.insert({3,4});//[{1,10},{3,4}]
    m.emplace(2,5);//[{1,10},{2,5},{3,4}]
    for(auto it:m){
        cout<<it.first<<it.second<<endl;
    }
}

//Algorithms
//scroll below my friend, this is related to a question.
bool comp(pair<int,int> p1, pair<int,int> p2){
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;

    if (p1.first > p2.first) return true;
    return false;
}
/*OR
bool comp(pair<int,int> p1, pair<int,int> p2) {
    if (p1.second != p2.second)
        return p1.second < p2.second;   // sort by second (ascending)
    return p1.first > p2.first;         // if tie, sort first (descending)
}


void explainExtra(){//used to sort array,vectors,etc...but not map.
    int a[4];
    sort(a,a+4);//length of array is 4...so,here,a points to the first element and a+4 points to the last element.
    //if you are using vector
    vector<int>v;
    sort(v.begin(),v.end());
    //to sort in decreasing order,
    sort(a+1,a+3,greater<int>());

//right now, we only know how to sort it in inc or dec order.what if we want to sort it in our own way.
pair<int,int>a[]={{1,2},{3,4},{6,5},{7,9}};
    //sort it according to second element
    //if the second element is same, sort it according to the first element in dec order. 
//First, make a comparator,which i have made above this function.
sort(a,a+4,comp);
}



int main(){
    explainpair();
    
    //EXPLAIN PERMUTATION
    string s="123";//you should always sort the string before calculating its permutations,as it it would have been 231, then it would not give 123,132,213.
    sort(s.begin(),s.end());
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
    

//MAX/MIN ELEMENT
int n;
int a[n];
int maxi=*max_element(a,a+n);
int mini=*min_element(a,a+n);
}

//HASHING
let's say, we have to  find the number of times a number occurs in an array, the numbr would be provided by the user.so, we can use the for loop, whicih will run n times to search the quantity of one number. Supppose the user gives us 10 numbers, so the time complexity would become 10*O(N),which would be quite large if our array size is also large.To make it effiecient hashing is introduced*/


void explainhashing() {
 

    int n;
    cout << "enter the length" << endl;
    cin >> n;

    int arr[n];
    cout << "enter the elements" << endl;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int hash[1000000];//we can't create an array with more than 1e6 elements inside the main, although we can create an array upto 1e7 elements as global array.

    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    cout<<"enetr the number of searches you want:\n";
    int q,num;
    cin>>q;
    while(q--){
        cout<<"enetr the number:\n";
        cin>>num;
        cout<<hash[num];
    }

    
}
/*for strings, we will use ascii values
just one change,hash[256] is enough as there are only 256 ascii characters.
do the same as above. 
*/
/*now talking about the case where the input in the array will have number greater than 1e7.
in that case we will use map*/
void explainHashing2() {
    int n;
    map<int ,int>mpp;//map will only store that value which is given in the array, it will not create any extra memory.
    int arr[n];
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
}
/*we should use unordered map instead of map because the time complexitiy of unordered map is O(1) in good and avg case, while that of map is O(logN).In the worst case time comp. is O(N), but that's a very rare case */



//Types of sorting
void explainselectionsort(){//we basically select one element and comapres it with the rest, if someone is grearer than it, then swap.we don't have to run loop for yhe last element as ofc it is the last element and there's nothing to compare with it
int n;cin>>n;
int arr[n];int temp;
for(int i=0;i<n-1;i++){int min=i;
    for(int j=i+1;j<n;j++){
        if(arr[min]>arr[j])min=j;
    }
    temp=arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
    //time complexity is O(N^2)
}
}

void explainbubblesort(){//we basically compare adjacent elements.like in first run, we will compare all adjacent elements, then in next run, we'll leave the last element and compare the rest, and then so on.
    int n;cin>>n;
    int arr[n],temp;
    
    for(int i=n-1;i>=1;i--){int diditrun=0;
        for (int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                    temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                    diditrun=1;
                    //time comp. O(N^2) for avg. and worst case.
            }
        }
        if(diditrun==0)break;//checks if the array is already sorted. if yes, then it would not run any further. the best case is if the araray is already sorted, so the best time compelxity is O(N).
    }
}

void explaininsertionsort(){//picks up one element and drop it at its correct location, it is diff from bubble as bubble compares adj., and it keeps swapping until the order gets fixed itself, while insertion carefully sorts elements individually, first , it will select one element and place it on its correct order and then second and so on. 
    int n;
    cin>>n;
    int arr[n],temp;
for(int i=0;i<n;i++){
    int j=i;
    while(j>0 && arr[j-1]>arr[j]){
        temp=arr[j-1];
        arr[j-1]=arr[j];
        arr[j]=temp;
        j--;
    }//time comp. is O(N^2)in worst and avg. case ...and O(N) in best case, as when the array will already be sorted,only the for loop will run.
   
}
}

void explainmergesort(){
    int n;
    cin>>n;
    int arr[n];
mergesort(arr,0,n-1);

}

void mergesort(int arr[],int low,int high){
    if(low==high) return;
int mid=(low+high)/2;
mergesort(arr,low,mid);
mergesort(arr,mid+1,high);
merge(arr,low,high,mid);
}
void merge(int arr[],int low, int high, int mid){
    int left=low,right=mid+1;
     vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
       else{ temp.push_back(arr[right]);
        right++;}
    }

while(left<=mid){
    temp.push_back(arr[left]);left++;
}
while(right<=high){
    temp.push_back(arr[right]);right++;
}

for(int i=low;i<=high;i++){
    arr[i]=temp[i-low];
}//time complexity is O(NlogN) in all cases, space complexity is(N).
}

//Two pointers and sliding window concept
//we use this concept in questions like if we have to find the length of largest substring with unique characters. in this concept, we basically set our two pointers at the starting of an array.then moves the right pointer throughout the array, we store index of each element in the hashing array. if the hashing array is not equal to value it was initialised(i.e -1), then we get to know that we have already seen that element, now we have to make sure that, that element is before or after l, if before, then no issue as it is not part of our current substring, if after then we have a dupplicate. so, we increase l.
void explainslidingwindow(){
    string s;
    cin>>s;
    int hash[256]={-1};
    int l=0,r=0,len=0,maxlen=0,n=s.size();
    while(r<n){
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
        }
        len=l-r+1;
        maxlen=max(len,maxlen);
        hash[s[r]]=r;
        r++;
    }
    
}

/*Quick Sort: just pick up a pivot element and place it at its correct pospiition, pivot element can be any random element from the array.
Select the pivot and place smaller elements on left and alrger on right, so that pivot would now be at its correct position
now again call this function for the left part, then right.(recursive)*/
vector<int> explainquicksort(vector<int>arr){
    qs(arr,0,arr.size()-1);
return arr;}

int qs(vector<int>&arr,int low,int high){
   if(low<high)
    {int pIndex=partition(arr,low,high);
    qs(arr,low,pIndex-1);
    qs(arr,pIndex+1,high);}
}

int partition(vector<int>&arr,int low,int high){int pivot=arr[low],i=low,j=high;
    while(i<j){
        while(i<=high-1 && pivot>=arr[i]){
            i++;
        }
        while(j>=low+1 && pivot<=arr[i]){
            j--;
        }
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

//Dutch national flag algorith[basically the rule is that elements in 0 to low-1 should be all 0, low+1 to mid-1, all 1's, mid+1 to high-1,all unsorted,high+1 to n-1,all 2's](question : sort and bring all the 0's ,1's,2's together)
int explaindutch(vector<int>&nums){int n=nums.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(mid==0)swap(nums[low++],nums[mid++]);
        else if(mid==1)mid++;
        else swap(nums[mid],nums[high--]);
    }

}
//Moore's voting algorithm[basically, we first select an element(the first element) and then traverse through the array with a count variable whose work is to increment itself if the element is the selected element and decrement if it is not.if the count becomes 0, then we consider that, that selected element is not the majority element, so we move forward and select the next element,(element before which the subarray ended),again do the same process,and at the element for which the count doesn't become 0, is the majority element.](queston:find the majoriy element,i.e,element which is occuring more than n/2 times)
int explainmoore(vector<int>&nums){int n=nums.size();
    int el;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            el=nums[i];
        }
        else if(nums[i]==el)cnt++;
        else cnt--;
        }
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el)cnt1++;
        }
        if(cnt1>n/2)return el;
        return -1;
}

//Lower bound: smallest index such that arr[i]>=x.If there no element in the array which is >=x,then the lower bound will be the last hypothetical element i.e. 'n'.
int explainlowerbound(int array[],int n,int x){//remember,if the question is about searching an element then always use BS as it has the least complexity(logn)as it divides the array in halves each time it runs.
    int l=0,r=n-1,index=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(array[mid]>=x){index= mid;r=mid-1;}
        else l=mid+1;
    }
    return index;
} 
//to find lower bound,c++ has inbuilt function
vector<int>arr(5);int x;
int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();//it returns the iterator pointing to the lb index,so to get the index,we subtract the begin iterator.

//Upper bound: smallest index such that arr[i]>x.
int explainupperbound(int array[],int n,int x){
     int l=0,r=n-1,index=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(array[mid]>x){index= mid;r=mid-1;}
        else l=mid+1;
    }
    return index;
}

//Floor and Ceil in sorted array: floor means the largest no. in the array which is <=x; ceil means the smallest no. in the array >=x,ceil is lower-bound only.

//Linked List 
class Node{//as linked list stores data as well as the pointer to the next value, it requires a special datatype, so we define our very own datatype.
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){//this is the contructor
        data=data1;
        next=next1;}
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
void explainlinkedlist(int array[],int n){
    vector<int>arr={2,5,8,7};
    //ways to initialize linked list
    Node *x= new Node(2,nullptr);
    //or(it is best as it automatically stores a pointer to the memory location)
    Node* y=new Node(arr[0],nullptr);
    cout<<y;//prints the address of the first node.
    cout<<y->data;//prints 2
    //if we remove 'new' then it will throw a error as it'll become an object.
    Node z=Node(arr[0],nullptr);
    cout<<z.data;
    cout<<z.next;

    //converting array to ll
    Node* head=convertarr2ll(arr);
    //to print all the elements in ll
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* convertarr2ll(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

//to find the length of ll
int lengthofll(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

//search in the ll
int checkifpresent(Node* head,int val){
    Node* temp=head;
    while(temp){
        if(temp->data==val)return 1;
        temp=temp->next;
    }
    return 0;
}

//deletion of elements in LL(head,position,value,last)
Node* deletehead(Node* head){
    if(head==NULL)return head;
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
Node* deletetail(Node* head){
    if(head==NULL || head->next==NULL)return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}
Node* removekthelement(Node* head,int k){
    if(head==NULL)return head;
    if(k==1 ) {
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
     int cnt=0;Node* temp=head,*prev=NULL;
     while(temp!=NULL){
        cnt++;
        if(cnt==k){
             prev->next=prev->next->next;
             free(temp);break;
        }
        prev=temp;
        temp=temp->next;
     }
     return head; //O(k)
}
Node* removevalue(Node* head,int value){         
    if(head==NULL)return head;
    if(head->data==value){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
     Node* temp=head,*prev=NULL;
     while(temp!=NULL){
        if(temp->data==value){
             prev->next=prev->next->next;
             free(temp);break;
        }
        prev=temp;
        temp=temp->next;
     }
     return head; //O(N or 1 or N/2)n is the length of LL.
} 

//insertion of elements in LL
Node* insertathead(Node* head,int value){
    Node* temp;
    temp->data=value;
    temp->next=head;//or Node* el=new Node(value,head);
    return temp;
}
Node* insertatend(Node* head,int value){
    if(head==NULL){
        return new Node(value);
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newel=new Node(value,NULL);
    temp->next=newel;
    return head; 
}
Node* insertatkthposition(Node* head,int k,int value){
    if(head==NULL){
        if(k==1){
        return new Node(value);}
        else return NULL;
    }
    if(k==1){
        return new Node(value,head);
    }
    int cnt=0;Node* temp=head;
    while(temp!=NULL){
        if(cnt==k-1){
            Node* newel=new Node(value,temp->next);
            temp->next=newel;break;
        }
        cnt++;
        temp=temp->next;
    }
    return head;
}
Node* insertvaluebeforex(Node* head,int x,int value){
        if(head==NULL)return NULL;
    if(head->data==x){
        return new Node(value,head);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==x){
            Node* newel=new Node(value,temp->next);
            temp->next=newel;break;
        }
        
        temp=temp->next;
    }
    return head;
}

//DOUBLY LL
class DNode{\
        public:
    int data;
    DNode* next;
    DNode* back;
    DNode(int data1,DNode* next1,DNode* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    DNode(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

DNode* convertarrtodll(int arr[], int n){
    DNode* head = new DNode(arr[0]);
    DNode* prev = head;
    for(int i = 1; i < n; i++){
        DNode* temp = new DNode(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

DNode* deletehead(DNode* head){
    if(head==nullptr || head->next==nullptr)return nullptr;
    DNode* temp=head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    free(temp);
    return head;
}

DNode* deletetail(DNode* head){
    if(head==nullptr || head->next==nullptr)return nullptr;
    DNode* temp=head;
    while(temp->next->next!=nullptr){//while(temp->next!=nullptr){temp=temp->next;}
        temp=temp->next;               //temp->back->next=nullptr;                                        //prev->next=nullptr;                                        //
    }                                   //delete(temp);
    temp->next->back=nullptr;           
    free(temp->next);
    temp->next=nullptr;
    return head;
}

DNode* deletekthel(DNode* head,int k){
    if(head==nullptr)return nullptr; 
    DNode* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k)
            break;
        temp=temp->next;
    }
    if(temp==nullptr)return head;//when k>length of ll
    DNode* prev=temp->back;
    DNode* front =temp->next;
    if(front==nullptr && prev==nullptr){
        delete(temp);
        return nullptr;
    }
    else if(prev==nullptr){
        front->back=nullptr;
        delete(temp);
        return front;
    }
    else if(front==nullptr){
        prev->next=nullptr;
        delete(temp);
        return head;
    }
    else {
        prev->next=front;
        front->back=prev;
        delete(temp);
        return head;
    }
    return head;
}

DNode* deletenode(DNode* temp){//node can't be head, as for it to be head we would have too amny conditions
      DNode* prev=temp->next;
      DNode* front=temp->back;
      if(front==nullptr){
        prev->next=nullptr;
        delete(temp);
      }
      prev->next=front;
      front->back=prev;

      temp->next=temp->back=nullptr;
      free(temp);
}

DNode* insertionbeforehead(DNode*head,int val){
    DNode* el=new DNode(val,head,nullptr);
    head->back=el;
    return el;
}
DNode* insertbeforetail(DNode* head,int val){
    if(head->next==nullptr)return insertionbeforehead(head,val);
    
    DNode* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    DNode* el=new DNode(val,temp,temp->back);
    temp->back=el;
    temp->back->next=el;
    return head;
}
DNode* insertbeforekthele(DNode* head,int k,int val){
    if(k==1)insertionbeforehead(head,val);
    DNode* temp=head;int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k)break;
        temp=temp->next;
    }
    DNode* prev=temp->back;
    DNode* el=new DNode(val,temp,prev);
    prev->next=el;
    temp->back=el;
    return head;
}
DNode* insertbeforeagivennode(DNode* head,DNode*temp,int val){
    DNode* prev=temp->back;
    DNode* el=new DNode(val,temp,prev);
    prev->next=el;
    temp->back=el;
}
DNode* reversedll(DNode* head){
    if(head==nullptr || head->next==nullptr)return head;   
    DNode* last=nullptr,*current=head;
    while(current!=nullptr){
        last=current->back;
        current->back=current->next;
        current->next=last;
        current=current->back;//to move forward we have to do current->back instead of current->next as the pointers are now reversed.
    }
    return last->back;
}

//revese in single ll
Node* reverseList(Node* head) {
        Node* prev=nullptr,*front=nullptr,*temp=head;
        while(temp!=nullptr){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    Node* byrecursion(Node* head){
        if(head==nullptr|| head->next==nullptr)return head;
        Node* newhead=byrecursion(head->next);
        Node* front=head->next;
        front->next=head; 
        head->next=nullptr;
        return newhead;
    }

    //sort LL
    Node *ms(Node* head){
        Node* middle=findmiddle(head);
        Node* left=head,*right=middle->next;
        middle->next=nullptr;
        left=ms(left);
        right=ms(right);
        return mergelist(left,right);
    }
    Node* findmiddle(Node* head){
        Node*fast=head->next,*slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    Node* mergelist(Node*list1,Node*list2){
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->data < list2->data){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
            while(list1){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            while(list2){
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
            return dummy->next;
        }
    }
    

//STACK AND QUEUE
class stk{
   int top=-1;int st[10],size=10;

   int push(int x){
    if(top>=size-1)cout<<"error";
    st[++top]=x;
   }

   int top(){
    if(top==-1)cout<<"erorr";
    return st[top];
   }

   int pop(){
    if(top==-1)cout<<"error";
    int el=st[top];
    top--;
    return st[top];
   }

   int size(){
    return top+1;
   }

};

class queue{
    int start=-1,end=-1;int queue[4],size=4;
    int currsize=0;
     
    int push(int x){
        if(currsize==size)cout<<"error";
        if(currsize==0){
            start=0;end=0;
        }
        else{
            end=(end+1)%size;
        }
        queue[end]=x,currsize+=1;
    }

    int pop(){
        if(currsize==0)cout<<"empty";
        int el=queue[start];
        if(currsize==-1)start=end=-1;
        else start=(start+1)%size;
        currsize-=1;
        return el;
    }

    int top(){
        if(currsize==0)cout<<"empty";
        return queue[start];
    }

    int size(){
        return currsize;
    }
};
