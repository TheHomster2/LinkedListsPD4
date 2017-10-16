#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next;};

void print_list(struct node *n){
	printf("%d", n->i);
	if (n->next != 0){
		printf(",");
		print_list(n->next);
	}
	else{printf("\n");}
	}

struct node * insert_front(struct node *count, int value){
	struct node *newVal = malloc(sizeof(struct node));
	newVal->i = value;
	newVal->next  = count;
	return newVal;
}

struct node * free_list(struct node *list){
	free(list);
	if (list->next != 0){
		free_list(list->next);
	}
}

int main(){
	printf("Making a list from 1 to 3 where 1 is first and 3 is on last\n");
	struct node *list = insert_front(0, 3);
	list = insert_front(list, 2);
	list = insert_front(list, 1);
	print_list(list);
	printf("Removing stuff from the list\n");
	list = free_list(list);
	print_list(list);
	printf("Done!\n");
	return 0;
}