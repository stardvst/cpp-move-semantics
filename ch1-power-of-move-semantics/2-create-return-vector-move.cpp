#include <string>
#include <vector>

std::vector<std::string> createAndInsert()
{
  std::vector<std::string> collection;
  collection.reserve(3);

  std::string s = "data"; // dtor won't free (s was moved)

  collection.push_back(s); // copy: ok
  collection.push_back(s + s); // temp is MOVED! ok
  collection.push_back(std::move(s)); // move: ok

  return collection; // nrvo OR MOVE: ok
}

int main()
{
  std::vector<std::string> v;
  v = createAndInsert(); // MOVED: ok
}
