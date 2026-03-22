#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }

};

Node* deletevalue(Node* head,int value1){
    if(head==nullptr)return head;
    if(head->data==value1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }


    Node* temp=head;
    while(temp->next!=nullptr){
        if(temp->next->data==value1){
            Node* tobedeleted=temp->next;
            temp->next=temp->next->next;
            free(tobedeleted);
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    cout<<"enetr the length";
    int n;
    cin>>n;

Node* head=nullptr,*temp=nullptr,*newnode=nullptr;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        newnode=new Node(value);
        if(head==nullptr){
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    int value1;
    cout<<"enetr the value you want to be deleted";
    cin>>value1;
head=deletevalue(head,value1);
temp=head;
while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->next;
}

}