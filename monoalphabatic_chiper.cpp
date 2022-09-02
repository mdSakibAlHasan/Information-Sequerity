/* a simple encryption programe just shift some character*/

#include<bits/stdc++.h>
using namespace std;

#define SIZE 100

void encryption(char str[], int key)
{
    for(int i=0;i<strlen(str);i++){
        str[i] += key;
    }
}


void decryption(char str[], int key)
{
    for(int i=0;i<strlen(str);i++){
        str[i] -= key;
    }
}


int main()
{
    char str[SIZE];
    int key;

    cout<<"Input message: ";
    //gets(str);
    cin.getline(str,sizeof(str));
    cout<<"Input key: ";
    cin>>key;

    encryption(str,key);
    cout<<"\nEncryption message: "<<str<<endl;

    decryption(str, key);
    cout<<"\nDecryption message is: "<<str<<endl;

}