#include <iostream>
#include <stack>
using namespace std;

int main(){
    while(true){
        string ary;
        stack<char> stack;
        bool flag = true;
        getline(cin, ary);

        if(ary.at(0)=='.' && ary.length()==1) break;

        int len = ary.length();

        for(int i=0; i<len; i++){
            if(ary.at(i)=='('){
                stack.push(ary.at(i));
            }else if(ary.at(i)=='['){
                stack.push(ary.at(i));
            }
            else if(ary.at(i)==')' || ary.at(i)==']'){
                if(stack.empty()){
                    cout << "no\n";
                    flag = false;
                    break;
                }
                if((stack.top() == '(' && ary.at(i) == ')' )
                    || (stack.top()=='[' && ary.at(i)==']')){
                    stack.pop();                    
                }else{
                    cout << "no\n";
                    flag = false;
                    break;
                }
            }
          
        }
        if(!stack.empty() && flag){
            cout << "no\n";
            flag = false;
        }
            
        if(flag)
            cout << "yes\n";
    }

    return 0;
}

