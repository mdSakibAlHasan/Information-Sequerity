//takes only alphabate ande pair random value an encrpt

#include<bits/stdc++.h>
using namespace std;
#include<stdlib.h>

#define SIZE 100

map<char,char>substitution;

void fill_table()
{
    bool alphabate[26]={0};
    
    for(char i = 'a';i<='z';i++){
        int x = rand()%26;
        
        if(!alphabate[x]){
            alphabate[x] = true;
            x += 97;
            substitution.insert(pair<char, char>(i,x));
        }
        else{
            int k=0;
            for(k=0;k<26;k++){
                if(!alphabate[k]){
                    break;
                }
            }
            alphabate[k] = true;
            k += 97;
            substitution.insert(pair<char, char>(i,k));
        }
    }
    substitution.insert(pair<char, char>(32,32));


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
    cin.getline(str,sizeof(str));
    

    encryption(str);
    cout<<"\nEncryption message: "<<str<<endl;

     decryption(str);
     cout<<"\nDecryption message is: "<<str<<endl;

    
    return 0;

}