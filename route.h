#include <iostream>
#include <string>
#include <vector>

class Route {
 public:

  Route(std::string source, std::string destination);

  //getters
  std::string GetSource() const;
  std::string GetDestination() const;
  int GetLength() const;
  void printParams() const;

  //setters
  void SetSource(const std::string& new_source); 
  void SetDestination(const std::string& new_destination); 

  //parameters
 private:

  void UpdateLength();
  std::string source_;
  std::string destination_;
  int length_;
};

void routeReverse(Route& route_);