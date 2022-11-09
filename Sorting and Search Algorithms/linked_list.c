#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

// Insert at the beginning

void insertAtBeginning(struct Node**headref, int new_data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	// insert the data
	new_node->data = new_data;
	new_node->next = (*headref);
	
	(*headref) = new_node;
	
}

// Inserting a node after a node

void insertAfter(struct Node*prev_node, int new_data)
{
	if(prev_node==NULL){
		printf("The given previous node cannot be null");
		return;
	}
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	
}

/// Insert at the end

void insertAtEnd(struct Node** headref, int new_data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = *headref;
	
	new_node->data = new_data;
	new_node->next = NULL;
	
	// If the node is empty either
	
	if(*headref==NULL){
		*headref = new_node;
		return;
	}
	
	while(last->next!=NULL)  last = last->next;
	
	last->next = new_node;
	return;
}


/// Delete a node


void deleteNode(struct Node**headref, int key){
	
	struct Node*temp = *headref,*prev;
	
	if(temp!=NULL && temp->data == key){
		*headref = temp->next;
		free(temp);
		return;
	}
	 
	 // Finding the key to be deleted
	 
	while(temp!=NULL && temp->data != key){
		prev = temp;
		temp = temp->next;
	}
	
	// If the key is not only present
	if(temp == NULL) return;
	
	// Remove the Node
	prev->next = temp->next;
	
	free(temp);
	
}



// Search a node
int searchNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;

  while (current != NULL) {
  if (current->data == key) return 1;
  current = current->next;
  }
  return 0;
}

void sortLinkedList(struct Node** headref){
	struct Node *current = *headref,*index=NULL;
	int temp;
	
	if(headref==NULL){
		return;
	}
	else{
		while(current!=NULL){
			
			// index will point the node next to the current
			
			index = current->next;
			
			while(index!=NULL){
				if(current->data > index->data){
					temp = current->data;
					current->data = index->data;
					index->data = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

void printList(struct Node* node){
	while(node != NULL){
		printf(" %d ", node->data);
		node = node->next;
	}
}


int main()
{
	struct Node* head = NULL;
	
	insertAtBeginning(&head, 1);
	insertAtBeginning(&head, 3);
	insertAtBeginning(&head, 7);
	insertAtBeginning(&head, 45);
	
	printf("LINKED LIST\n");
	printList(head);
	
	insertAtEnd(&head, 4);
	insertAfter(head->next, 123);
	
	printf("\n Look at the update\n");
	printList(head);
	
	printf("\n Deleting a node\n");
	deleteNode(&head, 3);
	
	printf("\n Look at the update\n");
	printList(head);
	
	int item_to_find = 3;
	if (searchNode(&head, item_to_find)) {
	printf("\n%d is found", item_to_find);
	} else {
	printf("\n%d is not found", item_to_find);
	}
	

	
	printf("\n Look at the update\n");
	printList(head);
	
	
	sortLinkedList(&head);
	printf("\nSorted List:");
	printList(head);
}











