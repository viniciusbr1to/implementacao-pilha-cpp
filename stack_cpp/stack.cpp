#include <iostream>
#define stack_size 100
using namespace std;


struct int_stack{
       int stack[stack_size];
       int top;


int_stack(){
top = -1;
}
bool is_full(){
if(top == stack_size -1){
   return true;
}

return false;
}
bool is_empty(){
if(top == -1){
   return true;
}

return false;
}
int push(int number){
if(is_full()){
   return 1;
}

stack[++top] = number;
return 0;
}
int pop(){
if(is_empty()){
   return 1;
}

top--;
return 0;
}
int peek(){
if(is_empty()){
   return -1;
}

return stack[top];
}
int size(){
return top + 1;
}
int search(int number){
if(is_empty()){
   return -1;
}

for(int i = 0; i <= top; i++){
    if(stack[i] == number){
       return i + 1;
    }
}

return 0;
}
int clear(){
if(is_empty()){
   return 1;
}

top = -1;
return 0;
}
int reverse(){
if(is_empty()){
   return 1;
}

   int aux_stack[stack_size];

for(int i = 0; i <= top; i++){
    aux_stack[i] = stack[i];
}

for(int i = 0; i <= top; i++){
    stack[i] = aux_stack[top - i];
}

return 0;
}
int print(){
if(is_empty()){
   return 1;
}

cout << "| ";
for(int i = 0; i <= top; i++){
    cout << stack[i] << " | ";
}
cout << endl;
return 0;
}
};
void menu(){
cout << "-----------------------------------------------------------------\n";
cout << "|1. Push             |5. Search           |9. Leave             |\n";
cout << "-----------------------------------------------------------------\n";
cout << "|2. Pop              |6. Clear            |\n";
cout << "-------------------------------------------\n";
cout << "|3. Peek             |7. Reverse          |\n";
cout << "-------------------------------------------\n";
cout << "|4. Size             |8. Print            |\n";
cout << "-------------------------------------------\n";
}


int main(){
    int_stack s;
    int option, number;


do{
menu();
cin >> option;
system("cls");


switch(option){
case 1:
cout << "Enter a number: ";
cin >> number;
system("cls");

if(s.push(number) == 1){
   cout << "The stack is full.\n";
} else
   cout << "Number entered successfully.\n";

break;

case 2:
if(s.pop() == 1){
   cout << "The stack is empty.\n";
} else
   cout << "Number removed successfully.\n";

break;

case 3:
if(s.is_empty()){
   cout << "The stack is empty.\n";
} else
   cout << "The last number in the stack is " << s.peek() << ".\n";

break;

case 4:
if(s.is_empty()){
   cout << "The stack is empty.\n";
} else
   cout << "The stack size is " << s.size() << ".\n";

break;

case 5:
cout << "Number to search: ";
cin >> number;
system("cls");


if(s.search(number) == -1){
   cout << "The stack is empty.\n";
} else if(s.search(number) == 0){
   cout << "The number " << number << " was not found in the stack.\n";
} else
   cout << "The number " << number << " was found at position " << s.search(number) << ".\n"; 

break;

case 6:
if(s.is_empty()){
   cout << "The stack is already empty.\n";
} else{
   s.clear();
   cout << "The stack was cleared successfully.\n";
}

break;

case 7:
if(s.reverse() == 1){
   cout << "The stack is empty.\n";
} else{
   cout << "The stack was successfully inverted.\n";
}

break;

case 8:
if(s.print() == 1){
   cout << "The stack is empty.\n";
}
  
break;

default:
if(option != 9){
   cout << "Invalid option.\n";
}

break;
}


system("pause");
system("cls");
} while(option != 9);


cout << "Shutting down the system...";
return 0;
}