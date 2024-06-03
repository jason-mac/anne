// clang-format off
/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Jason Mac
 * Date: May 2024 
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // TEMPLATE STACK

using std::cout;
using std::endl;
using std::cin;

int evaluate(int num1, int num2, Token token) {
  int value;
  switch(token.tt) {
    case pltok:
      value = num1 + num2;
      break;
    case mitok:
      value = num1 - num2;
      break;
    case asttok:
      value = num1 * num2;
      break;  
    case slashtok:
      value = num1 / num2;
      break;
    default:
      cout << "value = -1" << endl;
      value = -1;
  }
  return value;
}

int main () {
  Scanner S(cin);
  Token t;

  Stack<Token> numstack, opstack;  // 2x Stacks of type Token
 //  typedef enum { pltok, mitok, asttok, slashtok, lptok, rptok, integer, errtok, eof }

  t = S.getnext();
  while((t.tt != eof) || (!opstack.isEmpty())) {
    if(t.tt == integer) {
      numstack.push(t);
      t = S.getnext();
    } else if (t.tt == lptok) {
      opstack.push(t);
      t = S.getnext();
    } else if (t.tt == rptok) {
      if(opstack.peek().tt == lptok) {
        opstack.pop();
        t = S.getnext();
      } else {
        int num1 = numstack.peek().val;
        numstack.pop();
        int num2 = numstack.peek().val;
        numstack.pop();
        Token token = opstack.peek();
        opstack.pop();
        Token newToken;
        newToken.tt = integer;
        newToken.val = evaluate(num1, num2, token);
        numstack.push(newToken); 
      }
    } else if (t.tt == pltok || t.tt == mitok || t.tt == eof) {
      if((!opstack.isEmpty()) && ((opstack.peek().tt == pltok) || (opstack.peek().tt == mitok) || (opstack.peek().tt == asttok) || (opstack.peek().tt == slashtok))) {
        int num1 = numstack.peek().val;
        numstack.pop();
        int num2 = numstack.peek().val;
        numstack.pop();
        Token token = opstack.peek();
        opstack.pop();
        Token newToken;
        newToken.tt = integer;
        newToken.val = evaluate(num1, num2, token);
        numstack.push(newToken); 
      } else {
        opstack.push(t);
        t = S.getnext();
      }
    } else if (t.tt == asttok || t.tt == slashtok) {
      if(!opstack.isEmpty() && ((opstack.peek().tt == slashtok) || (opstack.peek().tt == asttok))) {
        int num1 = numstack.peek().val;
        numstack.pop();
        int num2 = numstack.peek().val;
        numstack.pop();
        Token token = opstack.peek();
        opstack.pop();
        Token newToken;
        newToken.tt = integer;
        newToken.val = evaluate(num1, num2, token);
        numstack.push(newToken); 
      } else {
        opstack.push(t);
        t = S.getnext();
      }
    }
  }
  cout << numstack.peek().val << endl;
  cout << endl;
  // End pretty printer coding demo.

  return 0;
}
/*
  // Pretty printer coding demo.  Please remove before coding
  while (t.tt != eof) {
    if (t.tt == integer || t.tt == lptok || t.tt == rptok) {
      cout << t;
    } 
	else 
	  if (t.tt == pltok || t.tt == mitok || t.tt == asttok || t.tt == slashtok) {
        cout << ' ' << t << ' ';
      }

    t = S.getnext();
  }
*/

// clang-format on
