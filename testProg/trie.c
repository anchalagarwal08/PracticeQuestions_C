#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size (26)

typedef struct Node node;
struct Node{
 int val; 
 node *child[size];
 int flag;
};

typedef struct Trie Trie_t;
struct Trie{
 node *root;
};

node* getNewNode(){
 int i;
 node *pnode = NULL;
 pnode = (node *)malloc(sizeof(node));
 if(pnode){
  pnode->val = 0;
  for(i=0;i<size;i++){
	pnode->child[i]=NULL;
  }

 }
return pnode;
}

void Initialize(Trie_t *trie){
  trie->root = getNewNode();
}

void insert(Trie_t *t, char string[]){
 node *node = t->root;
 int len = strlen(string);
 int i;
 int val;
 for(i =0; i<len;i++){
  val = (char)string[i]-(char)'a';
  if(!node->child[val]){
     node->child[val] = getNewNode();
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
 int val;
 for(i=0;i<len;i++){
   val = (char)string[i]- (char)'a';
   if(!node->child[val]){
   	return 0;
   }
   node = node->child[val];
 }
 if(node->flag)
   return 1;
 else
    return 0;
}

int main(){
 char keys[][8]= {"the", "a", "there", "answer", "any", "by", "bye", "their"};
 Trie_t trie_t;
 Initialize(&trie_t); 
 int i;
// trie_t.root = getNewNode();
 for(i =0;i<8;i++){
  insert(&trie_t, keys[i]);
 }
 if(search(&trie_t, "tha")){
  printf("found \n\n");
 }
 else
  printf("\n not found \n");
}
