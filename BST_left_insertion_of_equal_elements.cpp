//In this BST, equal elements will go in left-subtree

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct tree{
	struct tree* left;
	struct tree* right;
	struct tree* parent;
	int info;
}node;

node* create(node* &root,int x){    //Used for both creation and insertion of BST
	node* z=new node;
	z->info=x;
	z->left=z->right=z->parent=NULL;
	
	node* current=new node;
	current=root;
	node* hero=new node;
	hero=NULL;
	
	while(current!=NULL){
		  hero=current;
			if(z->info<=current->info)
			   current=current->left;
			else 
			   current=current->right;
	}
	if(hero==NULL)
		   root=z; 
	else if(z->info <= hero->info){
		 hero->left=z;
		 z->parent=hero;
	}
	else{
	    hero->right=z;
		z->parent=hero;	
	}		 	 	        
	return root;     
}

/*void transplant(node* &root , node* &u , node* &v){     //Pushpendra's version of transplant()
	if(u->parent==NULL){
		root=v;
	}
	else if(u==u->parent->left && v!=NULL){
	    u->parent->left=v;
	    v->parent=u->parent;
	  }
	else if(u==u->parent->left && v==NULL)
	    u->parent->left=v;
	else if(u==u->parent->right && v!=NULL){
	    u->parent->right=v;
	    v->parent=u->parent;
      }
	else if(u==u->parent->right && v==NULL)
	    u->parent->right=v;	    		    
}*/
void transplant(node* &root , node* &u , node* &v){       //Cormen's version of transplant()
	if(u->parent==NULL)
		root=v;
	else if(u==u->parent->left)
	    u->parent->left=v;
	else if(u==u->parent->right)
	    u->parent->right=v;                
	if(v!=NULL)
	    v->parent=u->parent;		    
}

node* find_max(node* &root){
   node* temp=root;
   	if(temp->right==NULL)
   		return temp;
	else
		return find_max(temp->right); 
}

node* search(node* &root,int x){
	node* temp=root;
	while(temp!=NULL){
		if(temp->info == x)
			return temp;         
		else if(x < temp->info)
			temp=temp->left;
		else if(x > temp->info)
			temp=temp->right;
	}
	cout<<"\nelement is not in Tree \n";
}
/*node* search(node* root,int x){              //Recursive search
	node* temp=root;
	if(x < temp->info)
	   return search(temp->left,x);
	else if(x==temp->info)
	   return temp;
	else if(x > temp->info)
	   return search(temp->right,x);         
}*/

void del(node* &root,node* &p){
	if(p->left==NULL && p->right!=NULL)
	   transplant(root,p,p->right);
	else if(p->right==NULL && p->left!=NULL)
	    transplant(root,p,p->left); 
	else{
		node* y=find_max(p->left);    
		if(y->parent!=p){
		   transplant(root,y,y->left);
		   y->left=p->left;
		   y->left->parent=y;
		   
		   transplant(root,p,y);
		   y->right=p->right;
		   y->right->parent=y;
		}
		else{
		   transplant(root,p,y);
		   y->right=p->right;
		   y->right->parent=root;
		}
	}	  
}

void inorder(node* &p){
   if(p!=NULL){
      inorder(p->left);
	  cout<<p->info<<" ";
	  inorder(p->right);
   }
}

int main(){
	node* root=new node; 
	root=NULL;
	
    for(int i=1;i<=10;i++)
        root=create(root,i*i*i-7*i*i-i+7);
//    root=create(root,i);
    node* temp=search(root,0);       
//	node* temp=search(root,1);
    
    del(root,temp);   temp=search(root,0); del(root,temp);  
	inorder(root);
	cout<<"\n"<<root->info;
}
