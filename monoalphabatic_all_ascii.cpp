/* thi s programm takes a message and 
crate random pair value and decrypt this message*/

//takes all ascii character
#include<bits/stdc++.h>
using namespace std;

#define SIZE 100

map<char,char>substitution;

void fill_table()
{
    bool alphabate[128]={0};
    
    for(int i = 32;i<=127;i++){
        int x = 32 + rand()%96;
        
        if(!alphabate[x]){
            alphabate[x] = true;
            //x += 97;
            substitution.insert(pair<char, char>(i,x));
        }
        else{
            int k=0;
            for(k=32;k<128;k++){
                if(!alphabate[k]){
                    break;
                }
            }
            alphabate[k] = true;
            //k += 97;
            substitution.insert(pair<char, char>(i,k));
        }
    }

    return;
}


void encryption(char str[])
{
    map<char, char>:: iterator itr;

    for(int i=0;i<strlen(str);i++){
        itr = substitution.find(str[i]);
        str[i] = itr->second;
    }

    return;
}

char find_value(char x)
{
    map<char, char>:: iterator itr;

    for(itr = substitution.begin(); itr != substitution.end(); ++itr){
        if(itr->second == x){
            return itr->first;
        }
    }

    return ' ';
}


void decryption(char str[])
{
    for(int i=0;i<strlen(str);i++){
        str[i] = find_value(str[i]);
    }

    return;
}


int main()
{
    char str[SIZE];

    fill_table();

    cout<<"Input message: ";
    //gets(str);
    cin.getline(str,sizeof(str));

    encryption(str);
    cout<<"Encryption message is: "<<str<<endl;
    decryption(str);
    cout<<"decryption messge is: "<<str<<endl;
}