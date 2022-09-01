#include <string>
#include <vector>
#include <iostream>

using namespace std;

std::vector<std::string> splitString(std::string strng, char splitter)
{
  std::vector<std::string> result;
  std::string current = "";
  for (int f = 0; f < strng.size(); f++)
  {
    if (strng[f] == splitter)
    {
      if (current != "")
      {
        result.push_back(current);
        current = "";
      }
      continue;
    }
    current += strng[f];
  }
  if (current.size() != 0)
    result.push_back(current);
  return result;
}

std::string spinWords(const std::string &str)
{
  vector<string> words;

  words = splitString(str, ' ');

  string phrase = "";

  for (int i = 0; i < words.size(); i++)
  {
    int wordSize = words[i].size();
    if (!(wordSize >= 5))
    {
      phrase += " " + words[i];
    }
    else
    {
      string reversed = "";
      for (int j = wordSize - 1; j + 1 > 0; j--)
      {
        reversed += words[i][j];
      }
      phrase += " " + reversed;
    }
  }
  phrase.erase(0, 1);
  return phrase;
}

int main()
{
  cout << spinWords("um macaco me deu bom dia na casa da tia mamae mandou eu escolher esse daqui");
}
