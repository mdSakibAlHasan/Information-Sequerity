//only take small value and space that 

#include<bits/stdc++.h>
using namespace std;

#define SIZE 100


char substitution[26][26];

bool search_in_column(int column, int row, char ch)
{
    for(int i=0;i<row;i++){
        if(substitution[i][column] == ch){
            return true;
        }
    }

    return false;
}


void fill_table()
{
    bool alphabate[26]={0};
    
    for(int p = 0;p < 26;p++){
        for(int a=0;a<26;a++)
            alphabate[a] = 0;
        for(int i = 0;i < 26;i++){
            int x = rand()%26;
        
            if(!alphabate[x] && !search_in_column(i,p,x+97)){
                alphabate[x] = true;
                x += 97;
                substitution[p][i] = (char)x;
            
            }
            else{
                int k=0;
                for(k=0;k<26;k++){
                    if(!alphabate[k] && !search_in_column(i,p,k+97)){
                        break;
                    }
                }
                alphabate[k] = true;
                k += 97;
            substitution[p][i] = (char)k;
            }   
        }
    }
    

    return;
}




void encryption(char str[], int key)
{
    int position, row;
    for(int i=0;i<strlen(str);i++){
        if(str[i] == 32){
            continue;
        }
        position = i%26;
        row = (int)str[i] - 97;
        str[i] = substitution[row][position] + key;
    }

    return;
}

char find_value(char x, int position)
{
    position = position%26;

    for(int i=0;i<26;i++){
        if(substitution[i][position] == x){
            return (i+97);
        }
    }

    return 32;
}


void decryption(char str[], int key)
{
    for(int i=0;i<strlen(str);i++){
        str[i] = find_value(str[i] - key,i);
    }

    return;
}


int main()
{
    char str[SIZE];
     int key;

    fill_table();       //create random table
   
    cout<<"Input message: ";
    cin.getline(str,sizeof(str));
    cout<<"Input key: ";
    cin>>key;

    encryption(str,key);
    cout<<"\nEncryption message: "<<str<<endl;

     decryption(str,key);
     cout<<"\nDecryption message is: "<<str<<endl;

    
    return 0;

}