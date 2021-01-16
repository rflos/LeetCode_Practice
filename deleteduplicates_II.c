/* LeetCode 82 Remove Duplicates from Sorted List II */
#include<stdlib.h>
#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* generateList(int* num, int size);
void destroyList(struct ListNode* head);
void printList(struct ListNode* head);
void reverseList(struct ListNode** head);
struct ListNode* deleteDuplicates(struct ListNode* head);

int main(){
	
	int number1[]={7,9,9,5,5};
	int number2[]={9,9,9,9,9};
	struct ListNode* l1 = generateList(number1,5);
	struct ListNode* l2 = generateList(number2,3);
	struct ListNode* result=NULL;

	printList(l1);
	printList(l2);

	result = deleteDuplicates(l1);

	printf("dfdfasdf");
	printList(result);

	result = deleteDuplicates(l2);

	destroyList(l1);
	destroyList(l2);

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

void reverseList(struct ListNode** head){
	struct ListNode* curNode = *head;
	struct ListNode* preNode;
	struct ListNode* nextNode;
	while(curNode){
		nextNode = curNode -> next;
		curNode -> next = (curNode == *head)? NULL : preNode;
		preNode = curNode;
		curNode = nextNode;
	}
	*head = preNode;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
	struct ListNode* curNode = head;
	struct ListNode* valhead = head;
	struct ListNode* rcurNode = NULL;
	struct ListNode* result = NULL;
	int pre_val = -1;
	int count = 0;
	while((curNode)&&(curNode -> val != pre_val)){
		pre_val = curNode -> val;
		valhead = curNode;
		curNode = curNode -> next;
		while((curNode)&&(curNode -> val == pre_val)){
			count++;
			curNode = curNode -> next;
		}
		if(!count){
			if(!result){
				result = valhead;
				rcurNode = result;
			}
			else{
				rcurNode -> next = valhead;
				rcurNode = rcurNode -> next;
			}
		}
		else{
			count = 0;
		}
	}
	if(result){
		rcurNode -> next = NULL;
	}
	return result;
}

