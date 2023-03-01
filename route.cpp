#include <iostream>
#include <string>
#include <vector>

#include "route.h"


  Route::Route(std::string source, std::string destination)
  {
    source_ = source;
    destination_ = destination;
    length_ = 1;
  }

  //getters
  std::string Route::GetSource() const { return source_; }

  std::string Route::GetDestination() const { return destination_; }

  int Route::GetLength() const { return length_; }

  void Route::printParams() const
  { std::cout << "\nSOURCE: " << source_ << "\nDESTINATION: " << destination_ << "\nLENGTH: " << length_ << std::endl; }

  //setters
  void Route::SetSource(const std::string& new_source) 
  {
    source_ = new_source;
    UpdateLength();
  }
  void Route::SetDestination(const std::string& new_destination) 
  {
    destination_ = new_destination;
    UpdateLength();
  }

  //parameters
void Route::UpdateLength() { length_ = (length_ + 3) % 5; }

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