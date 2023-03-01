#include <exception>
#include <stdexcept>
#include <iostream>

int main()
{
    int num = 0;
    std::cin >> num;

    try 
    {
        if (num == 0) throw std::runtime_error("Division by zero");

        int ans = 10 / num;
        std::cout << "10 / " << num << " = " << ans << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << "Exception occurred: " << ex.what() << std::endl;
    }

    return 0;
}