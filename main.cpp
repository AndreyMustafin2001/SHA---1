#include <iostream>
#include <string>
#include <vector>
//Left Rotate shift
template <typename T>
T shiftLeft( T value, int a)
{
    const int bit = sizeof(T) * 8;
    return ( value << a ) | (value >> (bit - a));
}
//F functions
unsigned int F ( int i,unsigned int B,unsigned int C,unsigned int D)
{
    unsigned int answer;
    if(0<=i&&i<=19){answer = (B & C) | ((~B)&D);}
    if(20<=i&&i<=39){answer = (B ^ C ^ D);}
    if(40<=i&&i<=59){answer = (B & C) | (B & D) | (C & D);}
    if(60<=i&&i<=79){answer = (B ^ C ^ D);}

    return answer;
}

std::string sha1(std::string mess)
{
    std::vector<bool> message;//Storage of message bits

    for(int i=0;i<mess.size();i++)//for each character
    {
        for(int j=7;j>=0;j--)//for each bit of a character
        {
            message.push_back(mess[i]&(1<<j));// Adding j-th bit to the vector
        }
    }

    unsigned int H0 = 0x67452301;
    unsigned int H1 = 0xEFCDAB89;
    unsigned int H2 = 0x98BADCFE;
    unsigned int H3 = 0x10325476;
    unsigned int H4 = 0xC3D2E1F0;

    unsigned int K[80];// allocate array for 80 numbers
    for(int i=0;i<=79;i++)
    {
        if(0<=i&&i<=19) K[i] = 0x5A827999;
        if(20<=i&&i<=39)K[i] = 0x6ED9EBA1;
        if(40<=i&&i<=59)K[i] = 0x8F1BBCDC;
        if(60<=i&&i<=79)K[i] = 0xCA62C1D6;
    }

    long long message_length = message.size();// long long because of length is 64 bits
    bool flag = true;
    while(message.size() % 512 != 448)//Adding 1 and 0s until the last chunk is of the length 448
    {
        if (flag == true)
        {
           message.push_back(1);// First adding 1
           flag = false;
        }
        else
        {
          message.push_back(0);// Then adding only 0s
        }
    }

     for (int i = 63;i >= 0;i--)// For each bit of the message length
    {
        message.push_back(message_length&(1LL<<i));//Adding i-th bit to the vector
                                                   //1LL because message_length type is long long
    }

    for (int i = 0;i < message.size();i+=512)//For each chunk of the length 512 bits
    {
        unsigned int A = H0 ;
        unsigned int B = H1 ;
        unsigned int C = H2 ;
        unsigned int D = H3 ;
        unsigned int E = H4 ;

        unsigned int W[80]={0};
        int k = 0;
        for (int j=i;j<i+512;j+=32)// Iterating over 16 parts of the length 32 bits
        {
            int p = 0;
            for(int z=j;z<j+32;z++)// Iterating over each bit  of the word(32 bit)
            {
                W[k] |= (static_cast<unsigned int>(message[z])<<p);//Filling each W[k]
                p++;
            }
                k++;
        }
        for(int j=16;j<=79;j++)
        {
            W[j] = shiftLeft<unsigned int>(W[j-3]^W[j-8]^W[j-14]^W[j-16] , 1);
        }
        for(int j=0;j<=79;j++)
        {
            unsigned int TEMP;
            TEMP = shiftLeft(A,5) + F(j,B,C,D) + E + W[j] + K[j];
            E=D;
            D=C;
            C=shiftLeft(B,30);
            B=A;
            A=TEMP;
        }
        H0 = H0 + A;
        H1 = H1 + B;
        H2 = H2 + C;
        H3 = H3 + D;
        H4 = H4 + E;
    }

    char all[41];
    std::sprintf(all, "%08x%08x%08x%08x%08x", H0, H1, H2, H3, H4);//Concatination of H0, H1, H2, H3, H4 written to all
    return std::string(all);
}
int main()
{
  std::string S = "abcd";
  std::cout << sha1(S) << std::endl;
}
