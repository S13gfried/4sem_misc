#include <iostream>
#include <string>
#include <vector>

class Route {
 public:
  Route(std::string source, std::string destination)
  {
    source_ = source;
    destination_ = destination;
    length_ = 1;
  }
  //getters
  std::string GetSource() const { return source_; }

  std::string GetDestination() const { return destination_; }

  int GetLength() const { return length_; }



  void printParams() const
  { std::cout << "\nSOURCE: " << source_ << "\nDESTINATION: " << destination_ << "\nLENGTH: " << length_ << std::endl; }



  //setters
  void SetSource(const std::string& new_source) 
  {
    source_ = new_source;
    UpdateLength();
  }
  void SetDestination(const std::string& new_destination) 
  {
    destination_ = new_destination;
    UpdateLength();
  }


  //parameters
 private:
  void UpdateLength() { length_ = (length_ + 3) % 5; }

  std::string source_;
  std::string destination_;
  int length_;
};

void routeReverse(Route& route_)
{
    std::string buf = route_.GetDestination();
    route_.SetDestination(route_.GetSource());
    route_.SetSource(buf);
}

int main()
{ 
std::string src, dest;

getline(std::cin, src);
getline(std::cin, dest);
Route myRoute = Route(src, dest);

myRoute.printParams();
routeReverse(myRoute);
myRoute.printParams();

    return 0; 
}