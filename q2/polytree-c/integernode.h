#ifndef __INTEGERNODE_H__
#define __INTEGERNODE_H__

// TODO
struct IntegerNode_class {
    int (*compareTo) (void*, void*);
    void (*printNode) (void*);
    void (*insert) (void*, void*);
    void (*print) (void*);
    int (*sum)  (void*);
    void (*delete) (void*);
};

struct IntegerNode;
struct IntegerNode {
  struct IntegerNode_class* class;
  struct IntegerNode* left;
  struct IntegerNode* right;
  int i;
};

void IntegerNode_ctor(void*, int);
int IntegerNode_compareTo(void*, void*);
void IntegerNode_printNode(void*);
void* new_IntegerNode(int);
int IntegerNode_sum(void*);

#endif /*__INTEGERNODE_H__*/
