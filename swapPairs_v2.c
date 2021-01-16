#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* generateList(int* num, int size);
void destroyList(struct ListNode* head);
void printList(struct ListNode* head);
struct ListNode* swapPairs(struct ListNode* head);

int main(int argc, char** argv){

	int num[] = {1,2,3,4,5,6};
	struct ListNode* l = generateList(num,6);
	struct ListNode* result = NULL;

	printList(l);
	
	result = swapPairs(l);

	printList(result);

	destroyList(result);

	return 0;
}

struct ListNode* generateList(int* num, int size){

	struct ListNode* head = NULL;
	struct ListNode* curNode = head;
	for(int i = 0; i < size; i++){
		if (i == 0){
			head = (struct ListNode*)malloc(sizeof(struct ListNode));
			head -> val = num[i];
			head -> next = NULL;
			curNode = head;
		}
		else{
			curNode -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
			curNode = curNode -> next;
			curNode -> val = num[i];
			curNode -> next = NULL;
		}
	}
	return head;
}

void destroyList(struct ListNode* head){
	struct ListNode* preNode = NULL;
	struct ListNode* curNode = head;
	while (curNode){
		preNode = curNode;
		curNode = curNode -> next;
		free(preNode);
	}
}

void printList(struct ListNode* head){
	struct ListNode* curNode = head;
	while(curNode){
		printf("%d->",curNode->val);
		curNode = curNode -> next;
	}
	printf("\n");
	/*
	curNode = head;
	while(curNode){
		printf("curNode address is %d\n",curNode);
		printf("nextNode address is %d\n",curNode->next);
		curNode = curNode -> next;
	}
	*/
}

struct ListNode* swapPairs(struct ListNode* head){
	struct ListNode* curNode = head;
	struct ListNode* result = head;
	struct ListNode* preNode = NULL;
	struct ListNode* temp = NULL;
	while((curNode) && (curNode -> next)){
		if(curNode == head){
			result = curNode -> next;
		}
		else{
			preNode -> next = curNode -> next;
		}
		preNode = curNode;
		temp = curNode -> next -> next;
		curNode -> next -> next = curNode;
		curNode -> next = temp;
		curNode = curNode -> next;
	}
	return result;
}
