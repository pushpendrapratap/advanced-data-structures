#include<iostream>
using namespace std;

typedef struct str1{
	struct str2* set_object;
	struct str1* next;
	int key;
}node;

typedef struct str2{
	struct str1* head;
	struct str1* tail;
}set;

set* make_set(int k){
	set* s=new set;
	node* n=new node;
	
	n->key=k;
	n->next=NULL;
	n->set_object=s;
	
	s->head=n;
	s->tail=n;
	
	return s;
}

set* find_set(node* s , int k){
	node* temp=s;
	
  if(temp!=NULL){		
	if(temp->key == k){  
		return temp->set_object;
	}
	else{
		return find_set(temp->next,k);
	}
  }
  else if(temp==NULL){
  	cout<<"\nSorry,key is not in this Set\n";
  	return NULL;
  }
}

set* union_set(set* &s1 , set* &s2){
	set* temp=s1;
	    
	temp->tail->next=s2->head;    
	temp->tail=s2->tail;          
	
	while(s2->head!=NULL){
		s2->head->set_object=s1;
		s2->head=s2->head->next;
	}
	
	return s1;           
}

void traverse(node* s){
	node* temp=s;
	if(temp!=NULL){
		cout<<temp->key<<"  ";
		traverse(temp->next);
	}
}

int main(){
	set* s1=make_set(1);set* s2=make_set(2);set* s3=make_set(3);set* s4=make_set(4);set* s5=make_set(5);
	
	s1=union_set(s1,s3);   
	s1=union_set(s1,s5);    
	s1=union_set(s1,s4);    
   
	set* pop=find_set(s1->head,3);  
	
	traverse(s1->head);     
}


