#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//defining node
struct bnode{
	int info;
	struct bnode *left, *right;
};

typedef struct bnode binNode;

binNode *root=NULL, *temp;

//for search
void binSearch(binNode* root, int key){
	if(root==NULL) cout<<key<<" not found."<<endl;
	else if(root->info==key) cout<<key<<" found."<<endl;
	else if(key<root->info) binSearch(root->left, key);
	else binSearch(root->right, key);	
}

//for insert
binNode* insert(binNode* root, int item){
	if(root==NULL){
		root=(binNode*)malloc(sizeof(binNode));
		root->left=root->right=NULL;
		root->info=item;
	}
	else if(item<root->info) root->left=insert(root->left, item);
	else root->right=insert(root->right, item);
	return root;
}

void inOrderTraversal(binNode *root){
	if(root!=NULL){
	    inOrderTraversal(root->left);
    	cout<<root->info<<" ";
    	inOrderTraversal(root->right);
	}
}
int main(void){
    cout<<"Root Node=\t"; root=insert(root,17); inOrderTraversal(root);
	cout<<"\nInsert 16:\t"; insert(root, 16); inOrderTraversal(root);
	cout<<"\nInsert 19:\t"; insert(root, 19); inOrderTraversal(root);
	cout<<"\nInsert 5:\t"; insert(root, 5); inOrderTraversal(root);
	cout<<"\nInsert 200\t"; insert(root, 200); inOrderTraversal(root);
	cout<<"\nSearch 16:\t"; binSearch(root,16);
}




