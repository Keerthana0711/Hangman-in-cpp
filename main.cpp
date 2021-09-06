#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;
//Array of country names
string country_names[20]={"india","nepal","usa","china","japan","germany","russia","england","mexico","australia","switzerland","bhutan","thailand","srilanka","maldives","canada","chile","pakisthan","dubai","singapore"};
int random_number()
{
    //To generate a random index number for country name
    srand(time(0));
    int rnumber = rand()%20;
    return rnumber;
}
int check_in_string(string s, char ch,string& progress)
{
    //To check if the letter is the word
    int cc=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==ch)
        {
            cc++;
            progress[i]=s[i];
        }
    }
    return cc;
}
void pretty_print(string s, string& progress)
{
    //Printing as _
    cout<<endl;
    cout<<endl;
    for(int i=0;i<s.length();i++)
    {
        //cout<<"_";
        progress+="_";
    }
}
int main()
{
    cout<<"\t\tWelcome to Hangman Game!!!!";
    cout<<"\n\t\tGuess the name of country (*only lower case letters)";
    int index = random_number();
    string s = country_names[index];
    string progress;
    pretty_print(s,progress);
    int count=5,guess=0;
    do{
       char ch;
       cout<<'\t'<<progress;
       cout<<"\nGuess a letter: ";
       cin>>ch;
       int flag = check_in_string(s,ch,progress);
       if(flag)
       {
           cout<<"\nCorrect Guess!!";
           guess+=flag;
       }
       else
       {
           count--;
           cout<<"\nWrong Guess!!! You have "<<count<<" guesses left!!!";
       }
       if(guess==s.length())
       {
           cout<<"\nYou guessed the word!!!";
           cout<<"\nThe country is: "<<s;
           break;
       }
    }while(count>0);
    return 0;
}
