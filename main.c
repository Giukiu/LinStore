#include <stdio.h>
#include <stdlib.h>
/*Conversion of infix expressions to suffix expressions, calculation of suffix expressions*/
/*At present, it is implemented to press the elements of the infix expression into the stack, 
and the operators and numbers are stored separately*/

struct node {
	int data;
	char value;
	struct node* next;
};
struct node* stack = NULL;
struct node* expression = NULL;

struct noed* push_m()
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->value = '*';
	new->data = 2;
	if (stack == NULL) {
		stack = new;
		stack->next = NULL;
		return stack;
	}
	new->next = stack;
	stack = new;
	return stack;
}

struct node* push_d()
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->value = '/';
	new->data = 2;
	if (stack == NULL) {
		stack = new;
		stack->next = NULL;
		return stack;
	}
	new->next = stack;
	stack = new;
	return stack;
}

struct node* push_a()
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->value = '+';
	new->data = 1;
	if (stack == NULL) {
		stack = new;
		stack->next = NULL;
		return stack;
	}
	new->next = stack;
	stack = new;
	return stack;
}

struct node* push_s()
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->value = '-';
	new->data = 1;
	if (stack == NULL) {
		stack = new;
		stack->next = NULL;
		return stack;
	}
	new->next = stack;
	stack = new;
	return stack;
}

struct node* push_int(char ele)
{
	
	int x = ele - 48;
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->value = x;
	if (expression == NULL) {
		expression = new;
		expression->next = NULL;
		return expression;
	}
	new->next = expression;
	expression = new;
	return expression;
	
}
void print()
{
	if (stack == NULL) {
		printf("The stack haven't element\n");
		return;
	}
	struct node* temp = stack;
	while (temp != NULL) {
		printf("%c\n", temp->value);
		temp = temp->next;
	}
}
_Bool judg(char e)
{
	int x = e - 48;
	if (x < 0 || x > 57) {
		return 0;
	}

	return 1;
}
void Print()
{
	if (expression == NULL) {
		printf("The expression haven't element");
		return;
	}
	struct node* temp = expression;
	while (temp != NULL) {
		printf("int is %d\n", temp->value);
		temp = temp->next;
	}
}
int main()
{
	char array[21];
	gets_s(array, 21);
	int len = strlen(array);
	for (int i = 0; i < len; i++) {
		if (judg(array[i])) {
			push_int(array[i]);
		}
		switch (array[i]) {
		case '+':
			push_a();
			break;
		case '-':
			push_s();
			break;
		case '*':
			push_m();
			break;
		case '/':
			push_d();
			break;
		}
	}
	Print();
	print();
	return 0;
}