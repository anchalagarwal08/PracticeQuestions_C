#include <stdio.h>

typedef struct Node node;
struct Node{
	node *left;
	node *right;
	int data;
};
