#include <iostream>
#include <thread>
#include <vector>

void doThis(const std::string &arg)
{
  std::cout << "doThis(): " << arg << '\n';
}

void doThat(const std::string &arg)
{
  std::cout << "doThat(): " << arg << '\n';
}

int main()
{
  std::vector<std::thread> threads;

  std::string someArg{"Black Lives Matter"};
  threads.push_back(std::thread{doThis, someArg}); // get a copy
  threads.push_back(std::thread{doThat, std::move(someArg)}); // gets the moved value

  for (auto &t : threads)
    t.join();
}
