#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "integernode.h"

// TODO 
struct IntegerNode_class IntegerNode_class_table = {
  IntegerNode_compareTo,
  IntegerNode_printNode,
  Node_insert,
  Node_print,
  IntegerNode_sum,
  Node_delete,
};

void IntegerNode_ctor(void* thisv, int x){
    struct IntegerNode * this = thisv;
    Node_ctor(this);
    this->i = x;
}

void* new_IntegerNode(int x) {
    struct IntegerNode * this = malloc(sizeof(struct IntegerNode));
    this->class = &IntegerNode_class_table;
    IntegerNode_ctor(this, x);
    return this;
}

int IntegerNode_compareTo(void*this, void*thisv) {
    struct IntegerNode * node1 = this;
    struct IntegerNode * node2 = thisv;
    return (node1->i - node2->i);
}

void IntegerNode_printNode (void* thisv) {
    struct IntegerNode* this = thisv;
    printf("%d\n", this->i);
}

int IntegerNode_sum(void* thisv){
  struct IntegerNode* this = thisv;
  if(this->left == NULL && this->right == NULL)
    return this->i;
  else if (this->left != NULL && this->right == NULL)
    return this->i + IntegerNode_sum(this->left);
  else if (this->right != NULL && this->left == NULL)
    return this->i + IntegerNode_sum(this->right);
  else
  {
      return this->i + IntegerNode_sum(this->left) + IntegerNode_sum(this->right);
  }
  

}