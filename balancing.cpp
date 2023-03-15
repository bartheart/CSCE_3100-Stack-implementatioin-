#include "stack.hpp"

using namespace std;

int main(){
  freopen("input_balanced.txt", "r", stdin);
  string s,r;
  int line_counter;
  while(cin >> r){
    cin>>s;
    Stack<char> stack;
    bool isBalanced = true;
    bool solution;
    if(r[0] == 'Y' || r[0] == 'y'){
      solution = true;
    }else{
      solution = false;  
    }

    // The input file is in the format "expected_solution expression"
    // so variable solution tells you whether 'expression' is balanced or not

    for(int i=0; i<s.length(); ++i){
      // WRITE CODE HERE so that isBalanced indicates whether 's' is balanced
      char c;
      c = s[i];
      if( c == '{' || '[' || '('){
        stack.push(c);
      }
      else if( c == '}' || ']' || ')'){
        //check if the stack is empty 
        if (stack.size() < 0){
          isBalanced = false;
          break;
        }
        else if ( c == '}' && stack.peek() != '{' || c == ']' && stack.peek() != '[' || c == ')' && stack.peek() != '('){
          isBalanced = false;
          break;
        }
        else{
          stack.pop();
        }
      }
      
    }

    // checking if you stored in isBalanced the correct value
    if(isBalanced == solution){
      cout << "line " << line_counter << ": OK [" << solution << " " << isBalanced << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << isBalanced << "]" << endl;
    }
    line_counter++;
  }
}
