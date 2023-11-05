#include <iostream>
#include <cstring>

struct Record
{
  explicit Record(const std::string& na) : name(na) {}
  std::string name;
};

int main()
{

  auto p2 = new Record("Record");
  std::cout << p2->name << '\n';

  Record* p1 = static_cast<Record*>(malloc(sizeof(Record)));  // bad
  std::cout << p1->name << '\n';                                   // undefined behavior
}
