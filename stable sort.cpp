#include<iostream>
#include<limits.h>
using namespace std;

void insert_sort(int* arr,int n){         //Both sorting algo. are Stable sort
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++)
			if(arr[i]>=arr[j])
			  continue;
			else{
				int temp=arr[i];
			    int front=j;
			    int rear=i;
			    
			    while(front!=rear){
			    	arr[rear]=arr[rear-1];
			    	rear--;
				}
				arr[j]=temp;
			}  
	}
}

void bubble_sort(int* arr,int n){
   int i=n-1;
   while(i!=0){
   	int temp;
   	int max=INT_MIN;
   	for(int j=0;j<=i;j++){
   		if(arr[j]>max){
   			max=arr[j];
   			temp=j;
		   }
	   }
	int rear=temp;
	int front=i;   
	while(front!=rear){
		arr[rear]=arr[rear+1];
		rear++;
	  }
	  arr[i]=max;
	  i--;
   }
}

int main(){
	int arr[]={3,5,4,7,2,9,11,1,2,6,3};
	int x=sizeof(arr)/sizeof(arr[0]);
	cout<<"Array elements:  ";
	
	for(int i=0;i<x;i++)
	  cout<<arr[i]<<"  ";
	  
	insert_sort(arr,x);
	cout<<"\n\n";
	cout<<"Insertion_sort:  ";
	
	for(int i=0;i<x;i++)
	   cout<<arr[i]<<"  "; 
	    
	bubble_sort(arr,x);
	cout<<"\n\n";
	cout<<"Bubble_sort:     ";
	  
	for(int i=0;i<x;i++)
	   cout<<arr[i]<<"  "; 
	cout<<"\n";    
}
