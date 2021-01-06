#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct pointers{
	struct Node *head;
	struct Node *tail;
};

void push(struct pointers *ptr, int data);
void printList(struct pointers *ptr);
void reverseList(struct pointers *ptr);
void delete(struct pointers *ptr, int data); //deletes the first occurrence of key in linked list

int main(void) {
	struct pointers *ptr = (struct pointers *)malloc(sizeof(struct pointers));
	ptr -> head = NULL;
	ptr -> tail = NULL;
	for(int i = 0; i < 10; i++)
		push(ptr, i);
	printList(ptr);
	reverseList(ptr);
	printList(ptr);
	delete(ptr, 5);
	printList(ptr);
	return 0;
}


void push(struct pointers *ptr, int data){
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	if(!ptr -> head)
		ptr -> head = new;
	new -> data = data;
	new -> next = NULL;
	if(ptr -> tail)
		ptr -> tail -> next = new;
	ptr -> tail = new;
}

void delete(struct pointers *ptr, int data){
	struct Node *del, *pre;
	for(del = ptr -> head; del -> data != data; del = del -> next)
		pre = del;
	pre -> next = del -> next;
	del -> next = NULL;
	free(del);
}

void printList(struct pointers *ptr){
	struct Node *p;
	for(p = ptr -> head; p != NULL; p = p -> next)
		printf("%d -> ", p -> data);
	printf("NULL\n");
}

void reverseList(struct pointers *ptr){
	struct Node *curr, *pre = NULL, *nextNode = NULL;
	curr = ptr -> head;
	while(curr){
		nextNode = curr -> next;
		curr -> next = pre;
		pre = curr;
		curr = nextNode;
	}
	ptr -> tail = ptr -> head;
	ptr -> head = pre;
}


