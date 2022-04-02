// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prior(char c) {
  if (c == '(') {
    return 0;
  }
  else if (c == ')') {
    return 1;
  }
  else if (c ==  '+' || c == '-') {
    return 2;
  }
  else if (c == '*' || c == '/') {
    return 3;
  }
  else {
    return -1;
  }
}

std::string infx2pstfx(std::string inf) {
  // добавьте код
  TStack <char, 100> mystack;
  std::string str;
  for (int i = 0; i < inf.size(); i++) {
    int p = prior(inf[i]);
    if (p == -1) {
      if (!str.empty() && prior(inf[i - 1]) != -1) {
        str.push_back(' ');
      }
      str.push_back(inf[i]);
    } else if ((p == 0) || (p > prior(stck.get())) || (mystack.isEmpty())) {
            mystack.push(inf[i]);
        } else {
            if (p == 1) {
                while (mystack.get() != '(') {
                    str.push_back(' ');
                    str.push_back(mystack.get());
                    mystack.pop();
                }
                mystack.pop();
            } else {
                while (prior(mystack.get()) >= p) {
                    str.push_back(' ');
                    str.push_back(mystack.get());
                    mystack.pop();
                }
                mystack.push(inf[i]);
            }
        }
    }
    while (!mystack.isEmpty()) {
        str.push_back(' ');
        str.push_back(mystack.get());
        mystack.pop();
    }
    return str;
}

int eval(std::string pref) {
  // добавьте код
  TStack <int, 100> mystack1;
  std::string temp;
  int n = 0, m = 0;
  size_t a = 0, z = 0;
  for (size_t i = 0; i < pref.size(); ++i) {
    if (pref[i] == ' ' || i == pref.size() - 1) {
      z = i;
      if (i == pref.size() - 1)
                z++;
      temp = pref.substr(a, z - a);
      a = z + 1;
      bool tNum = true;
      for (int i = 0; i < temp.size(); ++i) {
        if (temp[i] < '0' || temp[i] > '9') {
          tNum = false;
          break;
        }
      }
      if (tNum) {
        mystack1.push(std::stoi(temp));
      } else {
        m = mystack1.get();
        mystack1.pop();
        n = mystack1.get();
        mystack1.pop();
        if (temp == "+")
          mystack1.push(n + m);
        else if (temp == "-")
          mystack1.push(n - m);
        else if (temp == "*")
          mystack1.push(n * m);
        else if (temp == "/")
          mystack1.push(n / m);
      }
    }
  }
  return mystack1.get();
}
