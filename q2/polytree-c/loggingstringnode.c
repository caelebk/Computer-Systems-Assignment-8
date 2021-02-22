#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "stringnode.h"
#include "loggingstringnode.h"

// TODO
struct LoggingStringNode_class LoggingStringNode_class_table = {
  // TODO initialization of class table
  StringNode_compareTo,
  StringNode_printNode,
  LoggingStringNode_insert,
  Node_print,
  Node_delete,
};

void LoggingStringNode_insert(void* thisv, void* nodev) {
    Node_insert(thisv, nodev);
    printf("insert ");
    Node_print(nodev);
}

void* new_LoggingStringNode(char* s) {
  struct LoggingStringNode* obj = malloc(sizeof(struct StringNode));
  obj->class = &LoggingStringNode_class_table;
  StringNode_ctor(obj, s);
  return obj;
}
