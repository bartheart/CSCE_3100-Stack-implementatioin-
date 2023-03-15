#include "stack.hpp"

using namespace std;

template<class T>
void Stack<T>::push(T c){
	//define the push methosd here
  arr[++topIndex] = c;
}

template<class T>
T Stack<T>::pop(){
	//define the pop method here
  if(topIndex < 0){
    cout<<"Cannot pop. Stack empty."<<endl;
  }
  return arr[topIndex--];
}

template<class T>
T Stack<T>::peek(){
  if(topIndex < 0){
    cout<<"Cannot peek. Stack empty."<<endl;
  }
  return arr[topIndex];
}

template<class T>
int Stack<T>::size(){
  return topIndex+1;
}

template<class T>
void Stack<T>::display(){
  for(int i=topIndex; i>=0; --i){
    cout<<arr[i]<<"\t";
  }
  cout<<endl;
}

template class Stack<char>;
template class Stack<int>;
