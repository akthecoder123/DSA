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
    }//time comp. is O(N^2)in worst and avg. case ...and O(N) in best case, as when the array will already be sorted,only the for loop will run.
    j--;
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
    int left=0,right=mid+1;
     vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        temp.push_back(arr[right]);
        right++;
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

/*Quick Sort: just pick upa  pivot element and place it at its correct pospiition, pivot element can be any random element from the array.
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

int partition(vector<int>&arr,int low,int high){int pivot=arr[0],i=low,j=high;
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