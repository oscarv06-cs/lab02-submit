#include <string>
#include "studentRoll.h"
#include "student.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *newer = new Node;
  newer-> s = new Student(s);
  newer->next = NULL;
  if (head == NULL){
    head = tail = newer; 
  }
  else{
    tail->next = newer;
    tail = newer;
  }
}

std::string StudentRoll::toString() const {
  if (head == NULL){
    return "[]";
  }
  std::string res = "[";

  Node *curr = head;

  bool first = true;
  while (curr != NULL){
    if (!first){
      res += ",";
    }
    res += curr->s->toString();
    first = false;
    curr = curr->next;
  }
  res += "]";
  return res;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  Node *current = orig.head;
  while (current != NULL) {
    insertAtTail(*(current->s)); // this is the deep copy
    current = current->next;
  }
}

StudentRoll::~StudentRoll() {
  Node *current = head;
  while (current != NULL) {
    Node *next = current->next;
    delete current->s;
    delete current;
    current = next;
  }
  head = tail = NULL;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in... 
  Node *current = head;
    while (current != NULL) {
      Node *next = current->next;
      delete current->s;
      delete current;
      current = next;
    }
  head = tail = NULL;
  head = tail;
  tail = NULL;

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.

  if (right.head == NULL){
    return (*this);
  }

  current = right.head;
    while (current != NULL) {
      insertAtTail(*(current->s));
      current = current->next;
    }
  return (*this); 
}





