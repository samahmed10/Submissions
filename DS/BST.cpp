#include<bits/stdc++.h>

using namespace std;

class Node {
	public:
		int data;
		Node *left;
		Node *right;

		Node(int data,Node *left,Node *right) {
			this->data = data;
			this->left = left;
			this->right = right;
		}

};

Node* addNode(Node *root,int data) {
	if(!root)
		return new Node(data,NULL,NULL);

	if(data < root->data)
		root->left = addNode(root->left,data);

	if(data > root->data)
		root->right = addNode(root->right,data);

	return root;
}

Node* findLeftMost(Node* root) {
	while(root && root->left) 
		root = root->left;
	return root;
}

Node* deleteNode(Node* root,int key) {
	if(!root)
		return root;

	if(key < root->data)
		root->left = deleteNode(root->left,key);
	else if(key > root->data)
		root->right = deleteNode(root->right,key);

	else {
		if(!root->left) {
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if(!root->right) {
			Node* temp = root->left;
			free(root);
			return temp;
		}
		else {
			Node* temp = findLeftMost(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
	return root;
}

void inorder(Node *root) {
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

void levelOrder(Node *root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* t = q.front();
		cout<<t->data<<endl;
		q.pop();
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
}

int main() {
	Node *root = NULL;
	root = addNode(root,50);
	root = addNode(root,30);
	root = addNode(root,20);
	root = addNode(root,40);
	root = addNode(root,70);
	root = addNode(root,60);
	root = addNode(root,80);	
	inorder(root);
	// root = deleteNode(root,20);
	// cout<<endl;
	// inorder(root);
	// root = deleteNode(root,30);
	// cout<<endl;
	// inorder(root);
	// root = deleteNode(root,70);
	// cout<<endl;
	// inorder(root);
	// root = deleteNode(root,50);
	// cout<<endl;
	// inorder(root);
	cout<<endl;
	cout<<"level order is :"<<endl;
	levelOrder(root);
	return 0;
}
