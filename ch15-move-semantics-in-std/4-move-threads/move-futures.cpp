#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <future>

void getValue(std::promise<std::string> p)
{
  try
  {
    std::string ret{"vote"};
    // ...
    p.set_value_at_thread_exit(std::move(ret));
  }
  catch(const std::exception& e)
  {
    p.set_exception_at_thread_exit(std::current_exception());
  }
}

int main()
{
  std::vector<std::future<std::string>> results;

  std::promise<std::string> p;
  std::future<std::string> f{p.get_future()};
  results.push_back(std::move(f));

  std::thread t{getValue, std::move(p)};
  t.detach();

  for (auto &f : results)
    std::cout << f.get() << '\n';
}
