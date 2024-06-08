// clang-format off
/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Jason Mac and Jagyjot Parmar
 * Date: May 2024 
 */

#include <iostream>
#include <new>
#include "Scanner.h"
#include "Stack.h"  // TEMPLATE STACK

using std::cout;
using std::endl;
using std::cin;

// Evaluate operation and return corresponding token
Token evaluate(Stack<Token>& numstack, Stack<Token>& opstack) {
  Token newToken;
  newToken.tt = integer;

  // Pop top two values from numstack and retrieve them
  int num1 = numstack.pop().val;
  int num2 = numstack.pop().val;
  int value;
  Token op = opstack.pop();

  // Perform operation depending on token op
  switch(op.tt) { 
    // case plus
    case pltok:
      value = num2 + num1;
      break;
    // case minus
    case mitok:
      value = num2 - num1;
      break;
    // case multiplication
    case asttok:
      value = num2 * num1;
      break;  
    // case division
    case slashtok:
      value = num2 / num1;
      break;
    default:
      value = -1;
  }
  newToken.val = value;
  return newToken;
}

 // typedef enum { pltok, mitok, asttok, slashtok, lptok, rptok, integer, errtok, eof }

int main () {
  Scanner S(cin);
  Token t;

  Stack<Token> numstack, opstack;  // 2x Stacks of type Token

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
        Token newToken = evaluate(numstack, opstack);
        numstack.push(newToken); 
      }
    } else if (t.tt == pltok || t.tt == mitok || t.tt == eof) {
      if((!opstack.isEmpty()) && ((opstack.peek().tt == pltok) || (opstack.peek().tt == mitok) || (opstack.peek().tt == asttok) || (opstack.peek().tt == slashtok))) {
        Token newToken = evaluate(numstack, opstack);
        numstack.push(newToken); 
      } else {
        opstack.push(t);
        t = S.getnext();
      }
    } else if (t.tt == asttok || t.tt == slashtok) {
      if(!opstack.isEmpty() && ((opstack.peek().tt == slashtok) || (opstack.peek().tt == asttok))) {
        Token newToken = evaluate(numstack, opstack);
        numstack.push(newToken); 
      } else {
        opstack.push(t);
        t = S.getnext();
      }
    }
  }
  // Display the final output
  cout << numstack.peek().val << endl;

  return 0;
}
  // End pretty printer coding demo.
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
