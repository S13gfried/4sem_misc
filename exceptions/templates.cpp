#include <iostream>
#include <map>
#include <vector>

template <class keytype, class valtype>
std::ostream& operator<<(std::ostream& stream, const std::map<keytype, valtype>& map)
{
    stream << "{";
    for(std::pair<keytype, valtype> pair : map)
    {
        stream << pair.first << " : " << pair.second << ", ";
    }
    stream << "}";
    return stream;
}

template <class vtype>
class table
{
    private:
    
    std::vector<std::vector<vtype>> data;

    public:

    table(std::vector<std::vector<vtype>> ndata)
    { data = ndata; }

    std::vector<vtype>& operator[](const int index)
    { return data[index]; }
};


int main()
{
    std::map<int,int> map1 = std::map<int,int>({{1, 4}, {3, 8}, {4, 12}});
    std::cout << map1;

    table table1 = table(std::vector<std::vector<int>>({{1, 2, 3},{4, 5, 6},{7, 8, 9}}));
    std::cout << table1[1][2];

    return 0;
}