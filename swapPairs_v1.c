#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head);

int main(int argc, char** argv){

	int i = 0;

	printf("the number is %d\n",i);

	return 0;
}

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* curNode = head;
    int temp = 0;
    while((curNode) && (curNode->next)){
        temp = curNode -> val;
        curNode -> val = curNode -> next -> val;
        curNode -> next -> val = temp;
        curNode = curNode -> next -> next;
    }
    return head;
}
