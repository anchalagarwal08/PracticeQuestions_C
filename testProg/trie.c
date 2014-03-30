#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size (26)

typedef struct Node node;
struct Node{
 int val; 
 node *child[size];
 int flag;
 node *next;
};

typedef struct Trie Trie_t;
struct Trie{
 node *root;
};

node* getNewNode(int val){
 int i;
 node *pnode = NULL;
 pnode = (node *)malloc(sizeof(node));
 if(pnode){
  pnode->val = val;
  for(i=0;i<size;i++){
	pnode->child[i]=NULL;
  }

 }
return pnode;
}

void Initialize(Trie_t *trie){
  trie->root = getNewNode(0);
}

void insert(Trie_t *t, char string[]){
 node *node = t->root;
 int len = strlen(string);
 int i;
 int val;
 for(i =0; i<len;i++){
  val = (char)string[i]- (char)'a';
  if(!node->child[val]){
     node->child[val] = getNewNode(val);
     node->next = node->child[val];
  }
  node = node->child[val];
  if(i==len-1){
     node->flag = 1;
   }
 }
}

int search(Trie_t *t, char string[]){
 node *node = t->root;
 int len = strlen(string);
 int i;
 int c=0,val,count=0;
 for(i=0;i<len;i++){
   val = (char)string[i] - (char)'a';
   if(!node->child[val]){
   	return 0;
   }
   node = node->child[val];
 }
 printf("parent node: %d \n",node->val);
 for(i=0;i<26;i++)
 {	c =0;
	if(node->child[i]!=0){
	  count++;
	  struct Node *temp = node->child[i];
	  while(temp!=NULL){

 		int v = temp->val;
		printf("child: %d : %c\n",c, (char)v);
		temp = temp->next;	
		c++;
	 }
	printf("next \n");
        }	
 }
 printf("count: %d \n", count); 
 if(node->flag)
   return 1;
 else
    return 0;
}

int main(){
 char keys[][8]= {"the", "their", "there", "answer", "any", "by", "bye", "then"};
 Trie_t trie_t;
 Initialize(&trie_t); 
 int i;
// trie_t.root = getNewNode();
 for(i =0;i<8;i++){
  insert(&trie_t, keys[i]);
 }
int val = search(&trie_t, "the");
 if(val>0){
  printf("found: %d \n\n", val);
 }
 else
  printf("\n not found \n");
}
