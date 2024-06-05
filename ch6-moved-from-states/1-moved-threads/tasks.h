#pragma once

#include <array>
#include <thread>

class Tasks
{
public:
  Tasks() = default;

  template <typename T>
  void start(T op)
  {
    m_threads[m_numThreads] = std::thread{std::move(op)};
    ++m_numThreads;
  }

  ~Tasks()
  {
    for (int i = 0; i < m_numThreads; ++i)
    {
      //if (m_threads[i].joinable())
        m_threads[i].join();
    }
  }

  Tasks(Tasks &&) = default;
  Tasks &operator=(Tasks &&) = default;

private:
  std::array<std::thread, 10> m_threads{};
  int m_numThreads{};
};
