#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

typedef struct node {
  int data;
  int height;
  struct node *left;
  struct node *right;
  struct node *parent;
}node;

typedef struct binary_search_tree {
  node *root;
}binary_search_tree;

binary_search_tree* new_binary_search_tree() {
  binary_search_tree *t = (struct binary_search_tree*)malloc(sizeof(binary_search_tree));
  t->root = NULL;

  return t;
}

void insert(binary_search_tree *t, node *n) {
  
  node *y = NULL;
  node *temp = t->root;
  while(temp != NULL) {
    y = temp;
    if(n->data < temp->data)
      temp = temp->left;
    else
      temp = temp->right;
  }
  
  n->parent = y;

  if(y == NULL) //newly added node is root
    t->root = n;
  else if(n->data < y->data)
    y->left = n;
  else
    y->right = n;
}


void RotateRight(binary_search_tree* t, node* X){
    node* X_Prnt = NULL;
    node* X_lt_rt = NULL;
    if(X->parent!= NULL)
		X_Prnt = X->parent;  // here X_Prnt is P
    node* X_lt = X->left;      // here X_lt  is Y
    X_lt_rt = X_lt->right; //here X_lt_rt is B
    //Now
    X_lt->parent = X_Prnt;     // Y->parent = P
    if(X->parent !=NULL){
    	if(X->parent->data > X->data)
        	X_Prnt->left = X_lt; //P->left = Y
    	else
        	X_Prnt->right = X_lt;// P->right = Y
	}
	else
		t->root = X_lt;
    X->parent = X_lt , X_lt->right = X;   //X->parent = Y , Y->left =X
    if(X_lt_rt!=NULL)
		X_lt_rt->parent = X , X->left = X_lt_rt;  //B->parent =X ,X->right = B
    else
    	X->left = NULL;
}

void RotateLeft(binary_search_tree* t, node* Y){
	node* Y_Prnt = NULL;
	node* Y_rt_lt =NULL;
	if(Y->parent!=NULL)
    	Y_Prnt = Y->parent;  //Y_Prnt is P
	node* Y_rt = Y->right;   // Y_rt is X
    Y_rt_lt = Y_rt->left; //Y_rt_lt = B
    //Now
    Y_rt->parent = Y_Prnt;  // X->parent = P
    if(Y->parent != NULL){
		if(Y->parent->data > Y->data)
        	Y_Prnt->left = Y_rt;  // P->left = X
    	else
        	Y_Prnt->right = Y_rt;  // P->right = X
	}
	else{
			t->root = Y_rt;}
    Y->parent = Y_rt, Y_rt->left = Y;  //Y->parent = X , X->left =Y
    if(Y_rt_lt!=NULL)
    	Y_rt_lt->parent = Y , Y->right = Y_rt_lt; //B->parent =Y ,Y->right = B
	else{
		//Y_rt_lt->parent = Y;
		Y->right = NULL;	
	}
		
}

int FindMax(int l ,int r){
    if(l>=r)
        return l;
    else 
        return r;
}

int FindHeight(node* N){
    if(N!=NULL){
        return FindMax(FindHeight(N->left) ,FindHeight(N->right))+1;
    }
    else
        return -1;
}

void RebalanceRight(binary_search_tree* t, node* N){ // Left side of N is too heavy
    node* N_lt = N->left;
    if(FindHeight(N_lt->right) > FindHeight(N_lt->left)){
        RotateLeft(t,N_lt);}
    RotateRight(t,N);
    N->height= FindHeight(N);
}

void RebalanceLeft(binary_search_tree* t, node* N){ // right side of N is too heavy
    node* N_rt = N->right;
    if(FindHeight(N_rt->left) > FindHeight(N_rt->right)){
    	RotateRight(t,N_rt);}
    RotateLeft(t, N);
    N->height=FindHeight(N);
}

void Rebalance(binary_search_tree* t, node* N){
    node* N_Prnt = N->parent;
    if(FindHeight(N->left) > FindHeight(N->right)+1)
        RebalanceRight(t,N);
    if(FindHeight(N->right) > FindHeight(N->left)+1)
        RebalanceLeft(t,N);
    N->height = FindHeight(N);
    if(N_Prnt != NULL)
        Rebalance(t,N_Prnt);
}
  
void inorder(binary_search_tree *t, node *n){
     if(n!=NULL){
		inorder(t, n->left);
		cout<<n->data;
		cout<<"\n";
		inorder(t, n->right);
	}
}

node* Find(binary_search_tree *t, int k, node *n){
    if(n->data == k){
        return n;
    }
    else if(n->data > k){
        if(n->left != NULL)
            return Find(t, k ,n->left);
        return n;
    }
    else if(n->data < k){
        if(n->right != NULL)
            return Find(t,k ,n->right);
        return n;
    }
}

void AVLInsert(binary_search_tree* t ,node* n,int k){
    n = (struct node*)malloc(sizeof(node));
    n->data = k;
    n->height = -1;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    insert(t ,n);
    node* fnd = Find(t, k ,t->root);
    Rebalance(t,fnd);
    
}

node* minimum(binary_search_tree *t ,node *x){
    while(x->left !=NULL)
        x= x->left;
    return x;
}

void transplant(binary_search_tree *t ,node *u ,node *v){
	if(u->parent == NULL) //u is root
		t->root = v;
	else if(u == u->parent->left)//u is left child
		u->parent->left = v;
	else // u is right child
		u->parent->right =v;
	if(v!=NULL)
		v->parent = u->parent;
}

void Delete(binary_search_tree *t ,node* z){
	if(z->left == NULL){
		transplant(t,z,z->right);
		z->height = FindHeight(z);
		free(z);
	}
	else if(z->right == NULL){
		transplant(t,z, z->left);
		z->height = FindHeight(z);
		free(z);
	}
	else{
		node* y = minimum(t,z->right);
		if(y->parent!=z){
			transplant(t,y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(t,z,y);
		y->left = z->left;
		y->left->parent = y;
		z->height = FindHeight(z);
		free(z);
	}
	//z->height = FindHeight(z);
}

int main() {
  binary_search_tree *t = new_binary_search_tree();

   	node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;

//  i = new_node(160);
 	AVLInsert(t, a ,30);
  	AVLInsert(t, b ,40);
	AVLInsert(t, c ,50);
	AVLInsert(t, d ,60);
	AVLInsert(t, e ,70);
	AVLInsert(t, f ,80);
	AVLInsert(t, g ,90);
	AVLInsert(t, h ,100);
	AVLInsert(t, i ,110);
	AVLInsert(t, j ,120);
  	AVLInsert(t, k ,130);
	AVLInsert(t, l ,140);
  	AVLInsert(t, m ,150);
  	Delete(t,Find(t,40,t->root));
  	Delete(t,Find(t,60,t->root));
  	Delete(t,Find(t,70,t->root));
  	Delete(t,Find(t,90,t->root));
  	Delete(t,Find(t,120,t->root));
  	Delete(t,Find(t,40,t->root));
   	inorder(t ,t->root);
	//cout<<FindHeight(Find(t,100,t->root));
//  	cout<<endl;
  return 0;
 }







