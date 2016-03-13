#include<iostream>
using namespace std;

typedef struct str1{
	struct str1* parent;
	int key;
	int rank;
}set;

set* make_set(int k){    
	set* s=new set;
	s->key=k;
	s->parent=s;
	s->rank=0;
	
	return s;
}

set* find_set(set* temp){       			
	if(temp!=temp->parent)
		temp->parent=find_set(temp->parent);
	return temp->parent;	
}

void link(set* x , set* y){
	if(x->rank > y->rank){
		y->parent=x;
	}
	else{
		x->parent=y;
		if(x->rank == y->rank)
		    y->rank = y->rank +1;   
	}
}

void union_set(set* s1 , set* s2){
	link(find_set(s1),find_set(s2));           
}

int main(){
	set* s1=make_set(1);set* s2=make_set(2);set* s3=make_set(3);set* s4=make_set(4);set* s5=make_set(5);
	set* temp;
	union_set(s1,s3);   
	union_set(s1,s5);    
	union_set(s1,s4);    
   
	set* pop=find_set(s5);      
	cout<<pop->rank; 
}


