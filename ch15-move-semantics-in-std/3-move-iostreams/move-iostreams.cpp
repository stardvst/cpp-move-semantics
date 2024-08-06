#include <iostream>
#include <fstream>

std::ofstream openToWrite(const std::string &name)
{
  std::ofstream file(name);
  if (!file)
  {
    std::cerr << "can't open file '" << name << "'\n";
    std::exit(EXIT_FAILURE);
  }
  return file;
}

void storeData(std::ofstream fstrm)
{
  fstrm << 42 << '\n';
}

int main()
{
  auto outFile{openToWrite("iostream.tmp")};
  storeData(std::move(outFile));

  if (outFile.is_open())
    outFile.close();
}
