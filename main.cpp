#include <iostream>
#include <string>
#include <vector>

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

int main()
{

}
