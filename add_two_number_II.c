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
struct ListNode* addTwoNumber(struct ListNode* l1, struct ListNode* l2);

int main(){
	
	int number1[]={7,9,4,5,6};
	int number2[]={9,9,9,9,9};
	struct ListNode* l1 = generateList(number1,1);
	struct ListNode* l2 = generateList(number2,3);
	struct ListNode* result=NULL;

	printList(l1);
	printList(l2);

	//reverseList(&l1);
	//reverseList(&l2);

	//printList(l1);
	//printList(l2);

	result = addTwoNumber(l1,l2);

	printList(result);

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

struct ListNode* addTwoNumber(struct ListNode* l1, struct ListNode* l2){

	struct ListNode* curNode = l1;
	struct ListNode* preNode = NULL;
	struct ListNode* nextNode = NULL;
	int size = 0;
	int carry = 0;
	struct ListNode* head_l1;
	struct ListNode* head_l2;
	while(curNode){
		nextNode = curNode -> next;
		curNode -> next = (curNode == l1) ? NULL : preNode;
		preNode = curNode;
		curNode = nextNode;
		size++;
	}
	head_l1 = preNode;
	curNode = l2;
	while(curNode){
		nextNode = curNode -> next;
		curNode -> next = (curNode == l2) ? NULL : preNode;
		preNode = curNode;
		curNode = nextNode;
		size--;
	}
	head_l2 = preNode;
	if(size >= 0){
		curNode = head_l2;
		preNode = head_l1;
	}
	else{
		curNode = head_l1;
		preNode = head_l2;
	}
	while(curNode){
		preNode -> val = preNode -> val + curNode -> val + carry;
		if(preNode -> val > 9){
			carry = 1;
			preNode -> val = (preNode -> val)%10;
		}
		else{
			carry = 0;
		}
		nextNode = preNode;
		preNode = preNode -> next;
		curNode = curNode -> next;
	}
	if(carry){
		if(size == 0){
			preNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			nextNode -> next = preNode;
			preNode -> val = 1;
			preNode -> next = NULL;
		}
		else{
			preNode -> val ++;
			while(preNode -> val > 9){
				preNode -> val = (preNode -> val) % 10;
				if(preNode -> next){
					preNode = preNode -> next;
					preNode -> val++;
				}
				else{
					preNode -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
					preNode = preNode -> next;
					preNode -> val = 1;
					preNode -> next = NULL;
				}
			}
		}
	}
	if(size >= 0){
		curNode = head_l1;
	}
	else{
		curNode = head_l2;
		head_l1 = head_l2;
	}
	while(curNode){
		nextNode = curNode -> next;
		curNode -> next = (curNode == head_l1) ? NULL : preNode;
		preNode = curNode;
		curNode = nextNode;
	}
	head_l1 = preNode;
	return head_l1;
}
