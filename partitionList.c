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
struct ListNode* partition(struct ListNode* head, int x);

int main(){
	
	int number1[]={7,9,4,5,6};
	int number2[]={9,9,9,9,9};
	struct ListNode* l1 = generateList(number1,5);
	struct ListNode* l2 = generateList(number2,3);
	struct ListNode* result=NULL;

	printList(l1);
	printList(l2);

	result = partition(l1,5);

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

struct ListNode* partition(struct ListNode* head, int x){
	struct ListNode* ghead = NULL;
	struct ListNode* gcurNode = NULL;
	struct ListNode* lhead = NULL;
	struct ListNode* lcurNode = NULL;
	struct ListNode* curNode = head;
	
	while(curNode){
		if(curNode -> val >= x){
			if(!ghead){
				ghead = curNode;
				gcurNode = ghead;
			}
			else{
				gcurNode -> next = curNode;
				gcurNode = gcurNode -> next;
			}
		}
		else{
			if(!lhead){
				lhead = curNode;
				lcurNode = lhead;
			}
			else{
				lcurNode -> next = curNode;
				lcurNode = lcurNode -> next;
			}
		}
		curNode = curNode -> next;
	}
	if(lhead){
		if(ghead){
			lcurNode -> next = ghead;
			gcurNode -> next = NULL;
		}
		else{
			lcurNode -> next = NULL;
		}
	}
	else{
		if(ghead){
			lhead = ghead;
			gcurNode -> next = NULL;
		}
	}
	return lhead;
}

