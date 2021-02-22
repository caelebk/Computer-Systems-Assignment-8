#ifndef __LOGGINGSTRINGNODE_H__
#define __LOGGINGSTRINGNODE_H__

// TODO
struct LoggingStringNode_class {
  int  (*compareTo) (void*, void*);
  void (*printNode) (void*);
  void (*insert)    (void*, void*);
  void (*print)     (void*);
  void (*delete)    (void*);
};
extern struct LoggingStringNode_class LoggingStringNode_class_table;

struct LoggingStringNode;
struct LoggingStringNode {
  // TODO add class pointer and 
  // variables that are stored in instances of this class (including those introduced by super class)
  struct LoggingStringNode_class* class;
  struct StringNode* left;
  struct StringNode* right;
  char* s;
};

void LoggingStringNode_insert(void*, void*);

void* new_LoggingStringNode(char*);
#endif /*__LOGGINGSTRINGNODE_H__*/
