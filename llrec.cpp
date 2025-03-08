#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if (!head){
		smaller = NULL;
		larger = NULL;
		return;
	}
	Node* temp = head; 
	head = head ->next; 
	temp ->next = NULL;

	if (temp ->val <= pivot){
		smaller = temp;
		llpivot(head,smaller->next,larger,pivot);
	}
	else{
		larger = temp;
		llpivot(head,smaller,larger->next,pivot);
	}
	
}

