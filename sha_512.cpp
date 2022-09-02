#include<bits/stdc++.h>
using namespace std;


char constant[80][20]={"428a2f98d728ae22" ,"7137449123ef65cd", "b5c0fbcfec4d3b2f", "e9b5dba58189dbbc",
"3956c25bf348b538","59f111f1b605d019" ,"923f82a4af194f9b", "ab1c5ed5da6d8118",
"d807aa98a3030242","12835b0145706fbe" ,"243185be4ee4b28c" ,"550c7dc3d5ffb4e2",
"72be5d74f27b896f" ,"80deb1fe3b1696b1", "9bdc06a725c71235" ,"c19bf174cf692694",
"e49b69c19ef14ad2" ,"efbe4786384f25e3", "0fc19dc68b8cd5b5" ,"240ca1cc77ac9c65",
"2de92c6f592b0275" ,"4a7484aa6ea6e483" ,"5cb0a9dcbd41fbd4" ,"76f988da831153b5",
"983e5152ee66dfab" ,"a831c66d2db43210" ,"b00327c898fb213f" ,"bf597fc7beef0ee4",
"c6e00bf33da88fc2" ,"d5a79147930aa725", "06ca6351e003826f" ,"142929670a0e6e70",
"27b70a8546d22ffc" ,"2e1b21385c26c926" ,"4d2c6dfc5ac42aed" ,"53380d139d95b3df",
"650a73548baf63de" ,"766a0abb3c77b2a8", "81c2c92e47edaee6" ,"92722c851482353b",
"a2bfe8a14cf10364" ,"a81a664bbc423001", "c24b8b70d0f89791" ,"c76c51a30654be30",
"d192e819d6ef5218", "d69906245565a910", "f40e35855771202a" ,"106aa07032bbd1b8",
"19a4c116b8d2d0c8" ,"1e376c085141ab53", "2748774cdf8eeb99", "34b0bcb5e19b48a8",
"391c0cb3c5c95a63" ,"4ed8aa4ae3418acb", "5b9cca4f7763e373" ,"682e6ff3d6b2b8a3",
"748f82ee5defb2fc" ,"78a5636f43172f60" ,"84c87814a1f0ab72" ,"8cc702081a6439ec",
"90befffa23631e28" ,"a4506cebde82bde9" ,"bef9a3f7b2c67915" ,"c67178f2e372532b",
"ca273eceea26619c" ,"d186b8c721c0c207" ,"eada7dd6cde0eb1e", "f57d4f7fee6ed178",
"06f067aa72176fba", "0a637dc5a2c898a6", "113f9804bef90dae" ,"1b710b35131c471b",
"28db77f523047d84", "32caab7b40c72493" ,"3c9ebe0a15c9bebc" ,"431d67c49c100d4c",
"4cc5d4becb3e42b6" ,"597f299cfc657e2a" ,"5fcb6fab3ad6faec" ,"6c44198c4a475817"};

char binary_value[16][5]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
char hex_value[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
//bool abyte[80][64];


int compare_hex(char ch)
{
        for(int i=0;i<16;i++){
                if(ch == hex_value[i])
                        return i;
        }

        cout<<"Hex value not define\n";
        exit(0);
}


//Initial vector is a hexadecimal value. We convert it long int(64) bit value
//unsigned long long int initial_vector[8]={7640891576956012808,13503953896175478587,4354685564936845355,11912009170470909681,
 //                               5840696475078001361,11170449401992604703,2270897969802886507,6620516959819538809};


struct word_struct{
    bool byte[64];
};

struct word_struct word[80],temp[4],wc[4],init_vector[8],row_constant[80];


void hex_to_binary()
{
        int index;
        for(int i=0;i<80;i++){
                for(int j=0;j<16;j++){
                        index = compare_hex(constant[i][j]);
                        for(int k=0;k<4;k++){
                                row_constant[i].byte[j*4 + k] = binary_value[index][k] - '0';
                        }
                }
        }

        // for(int i=0;i<80;i++){
        //         for(int j=0;j<64;j++){
        //                 cout<<abyte[i][j];
        //         }
        //         cout<<endl;
        // }
}


void make_initialize_vector()
{

    bool initial_vector[8][64] = {0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,
                                 1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,1,
                                 0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0,1,0,1,1,1,1,1,1,1,0,1,0,0,1,0,1,0,0,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,1,
                                 1,0,1,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,1,1,1,1,1,0,0,0,1,1,1,0,1,0,0,1,1,0,1,1,0,1,1,1,1,0,0,0,1,
                                 0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,1,0,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,1,
                                 1,0,0,1,1,0,1,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,1,0,1,1,0,0,1,1,1,1,1,0,0,1,1,0,1,1,0,0,0,0,0,1,1,1,1,1,
                                 0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,1,1,0,1,1,1,1,0,1,0,1,1,0,1,0,1,1,
                                 0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1,0,0,1};
    
    for(int i=0;i<8;i++)
        copy (initial_vector[i], initial_vector[i]+64, init_vector[i].byte);   


}





void convert_binary(word_struct *shift,char text[],int init)
{
   for(int k=0;k<8;k++){
        int i=0,temp_bin[8],value = (int)text[init++],index=0,x=0;
        //cout<<" "<<value<<" ";
        for(i=0; value>0; i++)    
        {    
            temp_bin[i]=value%2;    
            value /= 2;  
            //cout<<temp_bin[i];
        }
        i--;
        for(int j=7;j>=0;j--){
            if(j>i)
                shift->byte[k*8 + index] = 0;
            else
                shift->byte[k*8 + index] = temp_bin[i--];

            index++;
        }  
   }
}


void left_shift(word_struct *shift,int number)
{
    //char temp[64];
    int index=number;
    for(int i=0;i<64 - number;i++){
        shift->byte[i] = shift->byte[index++];
    }

    for(int i= 64-number;i < 64;i++){
        shift->byte[i] = 0;
    }
}

void right_circular_shift(word_struct *shift,int number)
{
    char temp[64];
    int index=0;
    for(int i=64-number;i<64;i++){
        temp[index++] = shift->byte[i]; 
    }

    for(int i= 64;i >=number;i--){
        if(i>=number)
            shift->byte[i] = 0;
        else
            shift->byte[i] = temp[i];
    }
}


void XOR_two_word(word_struct *first,word_struct second)
{
    for(int i=0;i<64;i++){
        if( (first->byte[i] && second.byte[i]) ||  (!first->byte[i] && !second.byte[i]) )
            first->byte[i] = 0;
        else
            first->byte[i] = 1;
    }
}

struct word_struct sigma_function(word_struct *first,int x,int y,int z)
{
    temp[0] = *first;
    temp[1] = *first;
    temp[2] = *first;

    right_circular_shift(&temp[0],x);
    right_circular_shift(&temp[1],y);
    left_shift(&temp[2],z);

    XOR_two_word(&temp[0],temp[2]);
    XOR_two_word(&temp[0],temp[1]);

    return temp[0];
}


void make_word(char text[], int initial)
{
    int index=0,k=0;
    for(int i=0;i<16;i++){
        convert_binary(&word[0],text,initial+(i*8));
    }

    for(int i=6;i<64;i++){
        wc[0] = sigma_function(&word[i-2],1,8,7);
        wc[1] = word[i-7];
        wc[2] = sigma_function(&word[i-15],19,61,6);
        wc[3] = word[i-16];

        XOR_two_word(&wc[0],wc[1]);
        XOR_two_word(&wc[0],wc[2]);
        XOR_two_word(&wc[0],wc[3]);
        word[i] = wc[0];
    }
}

// Ch(e, f, g)
// = (e AND f)
// Maj(a, b, c)
// t
// 79
// (NOT e AND g) the conditional function: If e then f else g
// (a AND c)
// (b AND c) the function is true only of the majority (two or
// = (a AND b)
// three) of the arguments are true.

struct word_struct Ch()
{
    struct word_struct w;

    for(int i=0;i<64;i++){
        if(init_vector[4].byte[i])
            w.byte[i] = init_vector[5].byte[i];
        else
            w.byte[i] = init_vector[6].byte[i];
    }

    return w;
}


struct word_struct Maj()
{
    struct word_struct a,b,c;

    for(int i=0;i<64;i++)
        a.byte[i] = init_vector[0].byte[i] && init_vector[1].byte[i];
    for(int i=0;i<64;i++)
        b.byte[i] = init_vector[0].byte[i] && init_vector[2].byte[i];
    for(int i=0;i<64;i++)
        c.byte[i] = init_vector[2].byte[i] && init_vector[1].byte[i];

    XOR_two_word(&a,b);
    XOR_two_word(&a,c);

    return a;
}


struct word_struct summasion(word_struct *sum,int x,int y, int z)
{
    wc[0] = *sum;
    wc[1] = *sum;
    wc[2] = *sum;

    right_circular_shift(&wc[0],x);
    right_circular_shift(&wc[1],y);
    right_circular_shift(&wc[2],z);
    XOR_two_word(&wc[0],wc[1]);
    XOR_two_word(&wc[0],wc[2]);

    return wc[0];
}



void round_operation(int round_number)
{
    temp[0] = Ch();
    temp[2] = summasion(&init_vector[4],14,18,41);
    XOR_two_word(&temp[0],init_vector[7]);
    XOR_two_word(&temp[0],word[round_number]);
    XOR_two_word(&temp[0],row_constant[round_number]);
    XOR_two_word(&temp[0],temp[2]);     //temp[0] is T1

    temp[1] = Maj();
    temp[3] = summasion(&init_vector[0],28,34,39);
    XOR_two_word(&temp[1],temp[3]);     //temp[1] is T2

     XOR_two_word(&temp[1],temp[0]);
    init_vector[7] = init_vector[6];    //h=g
    init_vector[6] = init_vector[5];    //g =f
    init_vector[5] = init_vector[4];    //f=e
    XOR_two_word(&init_vector[3],temp[0]);
    init_vector[4] = init_vector[3];    //e=d
    init_vector[3] = init_vector[2];    //d=c
    init_vector[2] = init_vector[1];    //c=b
    init_vector[1] = init_vector[0];    //b=a

    XOR_two_word(&temp[1],temp[0]);     //T1+T2
    init_vector[0] = temp[1];



}


void control_round()
{
    word_struct temporary_iv[8];
    for(int i=0;i<8;i++){
        temporary_iv[i] = init_vector[i];
    }

    for(int i=0;i<80;i++){
        round_operation(i);
    }

    for(int i=0;i<8;i++){
        XOR_two_word(&init_vector[i],temporary_iv[i]);
    }
}


void control_block(char text[], int block_size)
{
    int number_of_block = block_size/128,index;

    make_initialize_vector();           //IV values create
    hex_to_binary();                    //row constant create
    for(int i=0;i<number_of_block;i++){
        make_word(text,i*128);
        control_round();
    }

    cout<<"Hash value is:\t";
    //print jash value
    for(int i=0;i<8;i++){
        for(int j=0;j<16;j++){
            index = j*4;
            char t[5];
            t[0] = init_vector[i].byte[index]+'0';
            t[1] = init_vector[i].byte[index+1]+'0';
            t[2] = init_vector[i].byte[index+2]+'0';
            t[3] = init_vector[i].byte[index+3]+'0';
            t[4] = '\0';
           
            for(int k=0;k<16;k++){
                if(strcmp(t,binary_value[k])==0){
                    index = k;
                    break;
                }
            }
            cout<<hex_value[index];
        }
    }

}


void padding_value(char pad[],int length)
{
    union Data {
        int i;
        char temp[4];
    } data;

    data.i = length;
    int k=3;
    for(int i=0;i<16;i++){
        if(i>11)
            pad[i] = data.temp[k--];
        else
            pad[i] = (char)0;
    }
    //cout<<sizeof(data);
}



void convert_decimal(char bin[])
{
    char temp[4];
    for(int i=0;i<4;i++){
        int start = i*8, end = ((i+1)*8 -1),base = 1,number=0;
 
        for (int j = end; j >= start; j--) {
             if (bin[j] == '1')
                 number += base;
            base = base * 2;
        }
        temp[i] = (char)number;
    }
    for(int i=0;i<12;i++){
        bin[i] = (char)0;
    }
     for(int i=12;i<16;i++){
        bin[i] = temp[i-12];
    }
     
    
}



void input()
{
    char text[2000],bin[16];
    cout<<"Input text: ";
    cin.getline(text,2000);

    int message_size = strlen(text) + 16,block_size;           //128 bit padding
   
    if(message_size%128 != 0)
         block_size = ((int)(message_size/128)+1)*128;
    else
        block_size = message_size;

    int pad_start = message_size - 16, pad_end = block_size - 16;

             //padding with 10000...000
    for(int i=pad_start;i<pad_end;i++){
        if(i == pad_start)
            text[i] = (char)128;
        else
            text[i] = (char)0;   
    }
    

    padding_value(bin,message_size-16);

    int index =0;
    for(int i=pad_end;i<block_size;i++){
        text[i] = bin[index++];
    }

    control_block(text,block_size);
}



int main()
{   
    input();
}