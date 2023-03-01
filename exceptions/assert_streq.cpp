#include <iostream>

#include <string>
#include <sstream>

int assertEquStrings(std::string str1, std::string str2)
{
    if(str1 != str2)
    throw std::runtime_error("assertEquStrings: strings are not equal");

    return 0;
}
int main(void)
{

    std::stringstream strs("hello world");

    std::string str1, str2;
    std::cin >> str1 >> str2;

    try
    {
        assertEquStrings(str1, str2);
        std::cout << "Success" << std::endl;
    }
    catch(const std::exception& excp)
    {
        std::cerr << excp.what() << std::endl; //'\n';
    }
    return 0;
}
