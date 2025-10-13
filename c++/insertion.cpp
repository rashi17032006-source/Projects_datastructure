#include<iostream>
#include<cstdlib>
using namespace std ;
struct node{
    int data;
    struct node*link;
};

int main (){
    struct node*start=NULL,*N1=NULL,*N2=NULL,*N3=NULL;
    N1=(struct node*)malloc(sizeof(struct node));
    N2=(struct node*)malloc(sizeof(struct node));
    N3=(struct node*)malloc(sizeof(struct node));
       if ( N1==NULL||N2==NULL||N3=NULL){
        cout<<"memory allocation failed";
        return 1;
       }
      cout<<"enter data for node 1:";
      cin>>N1->data;
      N1->link=N2;
     cout<<"enter data for node 2:";
     cin>>N2->data;
     N2->link=N3;
     cout<<"enter the data for node 3 :";
     cin>>N3->data;
     N3->link=NULL;
     start = N1;
     cout<<"linked list is:"
     while(ptr!=NULL)
      



}