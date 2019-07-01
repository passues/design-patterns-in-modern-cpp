#include<vector>
#include<map>
#include<sstream>
#include<iostream>

using namespace std;
struct Sentence
{
   
  struct WordToken
  {
    bool capitalize;
  };
  
  vector<string> words;
  map<int, WordToken> tokens;

  Sentence(const string& text)
  {
    std::string word;
    for (stringstream s(text); s >> word;)
        words.push_back(word);
  }

  WordToken& operator[](size_t index)
  {
    WordToken token;
    tokens[index] = token;
    return tokens[index];
  }

  string str() const
  {
    ostringstream oss;
    std::string format_string;
    for(int i= 0; i < words.size(); ++i)
    {
        if(i!=0)
            format_string += " ";
        auto it= tokens.find(i);
        if(it!=tokens.end())
        {
            if(it->second.capitalize){
                std::string tmp;
                for(auto c:words[i]){
                    tmp += toupper(c);
                }
                format_string += tmp;
            }
            else{
                format_string += words[i];
            }
            continue;
        }
        format_string += words[i];
    }
    return format_string;
  }
    
};
