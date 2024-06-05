#include "tasks.h"
#include <iostream>
#include <chrono>
#include <utility>

int main()
{
  try
  {
    Tasks tasks;
    tasks.start([]
                {
                  std::this_thread::sleep_for(std::chrono::seconds{2});
                  std::cout << "\nt1 done" << std::endl; });
    tasks.start([]
                { std::cout << "\nt2 done" << std::endl; });

    Tasks other{std::move(tasks)};
  }
  catch (const std::exception &ex)
  {
    std::cerr << "EXCEPTION: " << ex.what() << '\n';
  }
}
