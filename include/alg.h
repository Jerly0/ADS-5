// Copyright 2021 NNTU-CS
#ifndef INCLUDE_ALG_H_
#define INCLUDE_ALG_H_

#include <string>
#include <iostream>
const int size = 100;

std::string infx2pstfx(std::string);
int eval(std::string);

template<class T>
class TStack {
    private:
      T arr[size];
      int top;
    public:
      TStack():top(-1) { }
      T get() const { 
         return arr[top];
     }
     bool isEmpty() const {
        return top == -1;
     }
     bool isFull() const {
        return top == size - 1;
     }
     void pop() {
        if(top >= 0)
          top--;
     }
     void push(T item) {
       if(top < size - 1)
         arr[++top] = item;
     }
};

#endif  // INCLUDE_ALG_H_
