#include<iostream>
using namespace std;
int addition(auto a,auto b){return a+b;} 
int subtraction(auto a,auto b){return a-b;}
int multiplication(auto a,auto b){return a*b;}
int division(auto a,auto b){return a/b;}
int main(){
    cout<<"Calculator\n";
        int a,b;
        char x;
        cout<<"Enter First Number = ";
        cin>>a;
        cout<<"Enter Opetation (*,/,+,-) = ";
        cin>>x;
        cout<<"Enter secound Number = ";
        cin>>b;

        switch (x)
        {
        case '+':
            {cout<<addition(a,b);
            break;}
        case '-':
            {cout<<subtraction(a,b);
            break;}
        case '*':
            {cout<<multiplication(a,b);
            break;}
        case '/':
            {cout<<division(a,b);
            break;}
        
        default:
            {cout<<"Invalid operation";}
            break;
        }
    return 0;
}