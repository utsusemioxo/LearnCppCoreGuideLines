#include <iostream>
#include <new>
#include <cstring>

class ResourceGuard
{
public:
  explicit ResourceGuard(const std::string& res) : resource(res)
  {
    std::cout << "Acquire the " << resource << "." << '\n';
  }
  ~ResourceGuard()
  {
    std::cout << "Release the " << resource << "." << '\n';
  }

private:
  std::string resource;
};

int main()
{
  std::cout << '\n';

  ResourceGuard resource_guard1{ "memoryBlock1" };

  std::cout << "\nBefore local scope" << '\n';
  {
    ResourceGuard resource_guard2{ "memoryBlock2" };
  }
  std::cout << "After local scope" << '\n';

  std::cout << '\n';


  std::cout << "\nBefore try-catch block" << '\n';
  try
  {
    ResourceGuard resource_guard3{ "memoryBlock3" };
    throw std::bad_alloc();
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what();
  }
  std::cout << "\nAfter try-catch block" << '\n';

  std::cout << '\n';

}
