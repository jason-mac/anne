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

// Evaluate operation and return corresponding token with calculated value  
Token evaluate(Stack<Token>& numstack, Stack<Token>& opstack) {
  Token newToken;
  newToken.tt = integer;

  // Pop top two values from numstack and retrieve them
  int num1 = numstack.pop().val;
  int num2 = numstack.pop().val;
  int value;
  Token op = opstack.pop();

  // Perform operation depending on token op and its operator value
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
      value = 0;
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
    // check if t is integer
    if(t.tt == integer) {
      // push t to the number stack and get the next token t
      numstack.push(t);
      t = S.getnext();
    // check if t is a left paranthesis
    } else if (t.tt == lptok) {
      // push t to the operator stack and get the next token t
      opstack.push(t);
      t = S.getnext();
    // check if t is a right paranthesis
    } else if (t.tt == rptok) {
      if(opstack.peek().tt == lptok) {
        // if the top of operator stack is left paranthesis, pop it and get next token
        opstack.pop();
        t = S.getnext();
      } else {
        // perform operation with top two values on numstack and top value on opstack
        // receive the value from operation, store it in token and push it to numstack
        Token newToken = evaluate(numstack, opstack);
        numstack.push(newToken); 
      }
      //if t is +, -, or eof
    } else if (t.tt == pltok || t.tt == mitok || t.tt == eof) {
      // if opstack is nonempty and the top is either +, -, *, or /
      if((!opstack.isEmpty()) && ((opstack.peek().tt == pltok) || (opstack.peek().tt == mitok) || (opstack.peek().tt == asttok) || (opstack.peek().tt == slashtok))) {
        // perform operation with top two values on numstack and top value on opstack
        // receive the value from operation, store it in token and push it to numstack
        Token newToken = evaluate(numstack, opstack);
        numstack.push(newToken); 
      } else {
        // push t to the opstack and get next token
        opstack.push(t);
        t = S.getnext();
      }
      //if t is either * or /
    } else if (t.tt == asttok || t.tt == slashtok) {
      // if the opstack is not empty and the its top value is either / or *
      if(!opstack.isEmpty() && ((opstack.peek().tt == slashtok) || (opstack.peek().tt == asttok))) {
        // perform operation with top two values on numstack and top value on opstack
        // receive the value from operation, store it in token and push it to numstack
        Token newToken = evaluate(numstack, opstack);
        numstack.push(newToken); 
      } else {
        // push t to the opstack and get next token
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
