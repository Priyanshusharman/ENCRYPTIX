// Create a program that generates a random number and asks the user
// to guess it. Provide feedback on whether the guess is too high or too low
// until the user guesses the correct number
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int max_value =100;
    int min_value = 10;
    int cout_try=0;
    int Guess_no=min_value-1;
    srand(time(0));
    int random_number = rand() % (max_value - min_value + 1) + min_value;
    cout<<"Welcome To Number Guess Game\n";
    cout << "Guess the number between " << min_value << " to " << max_value << endl;
    while(Guess_no!=random_number){
        cout<<"Enter : ";
        cin>>Guess_no;
        cout_try++;
        if(Guess_no==random_number){
            cout<<"Right Guess. \nYou Guess in "<<cout_try<<" Time";
        }
        else if(Guess_no>random_number){
            cout<<"\nGuess Number is too High then Number\n";
        }
        else{
            cout<<"\nGuess Number is too Low then Number\n";
        }
        
   
    }
    
    return 0;
}