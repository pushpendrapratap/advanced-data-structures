#include<iostream>
using namespace std;

struct stack
{
	int top,bottom,capacity,size;
	int* arr;
};
typedef struct stack sun;

sun* create(int cap)
{
	sun* s=new stack;
	s->capacity=cap;
	s->top=s->bottom=-1;
	s->size=0;
	s->arr=new int[s->capacity];
	return s;
}
bool isempty(sun* s)
{
	if(s->size==0)
	   return true;
	else
	   return false;   
}
bool isfull(sun* s)
{
	if(s->size==s->capacity)
	   return true;
	else
	   return false;   
}
sun* push(sun* s,int item)
{
	if(isfull(s))
	   cout<<"\nSorry-stack is full ";
	else
	 {
	 	(s->top)++;
	 	s->arr[s->top]=item;
	 	s->bottom=0;
	 	(s->size)++;
	 	return s;
	 }   
}
void pop(sun* s)
{
	if(isempty(s))
	   cout<<"\nSorry-stack is empty ";
	else
	{
		(s->top)--;
		(s->size)--;
	}   
}
void trav(sun* s)
{
	if(isempty(s))
	   cout<<"\nNothing to show.it's empty ";
	else
	{
	    for(int i=s->bottom;i<s->size;i++)
		   cout<<s->arr[i]<<"  ";
		 cout<<"\n";  	
	}   
}

int main()
{
	sun* s=new stack;
	s=create(10);
	for(int i=0;i<7;i++)
	   s=push(s,i);   
	cout<<"\n";
	trav(s);
	pop(s);
	trav(s);   
}
