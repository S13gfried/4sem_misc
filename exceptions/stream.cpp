#include <iostream>

#include <fstream>
#include <sstream>
#include <iomanip>

int main(void)
{
    std::ifstream input("bingus.txt");
    std::ofstream output("n.txt"/*ios::app*/);
    //input.ignore(N);

    std::stringstream strs("hello world");

    double xi = 2.239159107f;
    std::cout << std::setprecision(2) << xi << std::endl;
    
    std::cout << std::setw(3) << "welcome to the cumzone" << std::endl;

    std::cout << std::setfill('#');

    return 0;
}