#include "stack.hpp"

using namespace std;

int main(){
  freopen("input_postfixEval.txt", "r", stdin);
  string s;
  int solution;
  int line_counter = 0;
  while(cin>>solution){
    cin>>s;
    Stack<int> stack;
    
    // The input file is in the format "expected_solution postfix_expression"

    // We assume that all operands in the input are one digit (so they range from 0 to 9)
    for(int i=0; i<s.length(); ++i){
      // WRITE CODE HERE to evaluate the postfix expression in s
      // At the end of the loop, stack.pop() should contain the value of the postfix expression
      
      // Get the character at position i in the postfix expression
      char c = s[i];
      
      // If the character is a digit, push its value onto the stack
      if (isdigit(c)){
        stack.push(c - '0');  // Convert the character to an integer value
      }
      // If the character is an operation, pop the top two values from the stack, apply the operation, and push the result onto the stack
      else if( c == '*' || c == '/' || c == '+' || c == '-'){
        int operandR = stack.pop();
        int operandL = stack.pop();
        if(c == '*'){
          stack.push(operandL*operandR);  // Multiply the operands and push the result onto the stack
        }
        else if(c == '/'){
          stack.push(operandL/operandR);  // Divide the operands and push the result onto the stack
        }
        else if(c == '-'){
          stack.push(operandL-operandR);  // Subtract the operands and push the result onto the stack
        }
        else if( c == '+'){
          stack.push(operandL+operandR);  // Add the operands and push the result onto the stack
        }
        
      }
      // If the character is not a digit or an operation, break out of the loop (this should not happen in a valid postfix expression)
      else{
        break;
      }


    }

    // Checking whether the value you calculated is correct ...
    int value = stack.pop();

    if(solution == value){
      cout << "line " << line_counter << ": OK [" << solution << " " << value << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << value << "]" << endl;
    }
    line_counter++;
  }
}


