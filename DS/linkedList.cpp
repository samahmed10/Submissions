#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
};

void insertAtBeginning(Node **head,int data) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	if(*head == NULL) {
		*head = newNode;
	}
	else {
		newNode->next = *head;
		*head = newNode;
	}
}

void insertAtEnd(Node **head,int data) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	if(*head == NULL) {
		*head = newNode;
		return;
	}

	Node *temp = *head;
	while(temp->next) {
		temp = temp->next;
	}

	temp->next = newNode;
}

void deleteNode(Node **head,int data) {
	if(*head == NULL)
		return;

	Node *temp = *head;
	Node *prev = NULL;

	if(temp->data == data) {
		*head = temp->next;
		free(temp);
		return;
	}

	while(temp != NULL && temp->data != data) {
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL)
		return;

	prev->next = temp->next;

	free(temp);
}

void printList(Node *head) {
	while(head) {
		cout<<head->data<<endl;
		head = head->next;
	}
}
int main() {
	Node *head = NULL;
	insertAtBeginning(&head,4);
	insertAtBeginning(&head,5);
	insertAtEnd(&head,3);
	insertAtEnd(&head,2);
	insertAtEnd(&head,1);


	printList(head);

	cout<<endl;

	deleteNode(&head,1);

	printList(head);
	return 0;
}