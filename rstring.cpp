#include <iostream>
#include <string>
#include <vector>

class Rstring
{
    public:
    std::string val;

    Rstring()
    { val = ""; }

    Rstring(std::string newstr)
    { val = newstr; }

    std::string ToString() const
    { return val;  }

    void reverse()
    {
        int size = val.size();
        char buff;
        for(int i = 0; i < size/2; i++)
        {
            buff = val[i];
            val[i] = val[size - 1 - i];
            val[size - 1 - i] = buff;
        }
    }
};

int main()
{ 
    std::string input;
    std::cin >> input;

    Rstring rstr = Rstring(input);
    rstr.reverse();
    std::cout << rstr.ToString();
    return 0; 
}