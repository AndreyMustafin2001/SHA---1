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
}
    unsigned int H0 = 0x67452301;
    unsigned int H1 = 0xEFCDAB89;
    unsigned int H2 = 0x98BADCFE;
    unsigned int H3 = 0x10325476;
    unsigned int H4 = 0xC3D2E1F0;

int main()
{

}
