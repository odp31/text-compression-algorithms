// lempel-ziv-welch (LZW)
// dictionary based compression algorithm; builds a dictionary of strings dynamically as it processes input data
// replaces frequently occuring strings with shorter codes (usually integers) 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>


std::vector<int> lzw_encode(const std::string& text) {
  int next_code = 256;
  std::map<std::string, int> dictionary;
  for(int i = 0; i <256; ++i) {
    std::string s(1, char(i));
    dictionary[s] = i;
  }
  std::string current_string = "";
  std::vector<int> encoded;

  for(char c : text) {
    std::string next_string = current_string + c;
    if(dictionary.count(next_string)) {
      current_string = next_string;
    } else {
      encoded.push_back(dictionary[current_string]);
      dictionary[next_string] = next_code++;
      current_string = std::string(1, c);
    }
  }
  if(!current_string.empty()) {
    encoded.push_back(dictionary[current_string]);
  }
  return encoded;
}

std::string lzw_decode(const std::vector<int> & encoded) {
  int next_code = 256;
  std::map<int, std::string> dictionary;
  for(int i = 0; i < 256; ++i) {
    std::string s(1, char(i));
    dictionary[i] = s;
  }
  std::string decoded = "";
  std::string previous_string = dictionary[encoded[0]];
  decoded += previous_string;

  for(size_t i = 1; i < encoded.size(); ++i) {
    int code = encoded[i];
    std::string current_string;
    if(dictionary.count(code)) {
      current_string = dictionary[code];
    } else {
      current_string = previous_string + previous_string[0];
    }
    decoded += current_string;
    dictionary[next_code++] = previous_string + current_string[0];
    previous_string = current_string;
  }
  return decoded;
}

int main() {
  std::string text = "ABABABAABAB";
  std::vector<int> encoded = lzw_encode(text);
  std::string decoded = lzw_decode(encoded);
  std::cout << "original: " << text << std::endl;
  std::cout << "encoded:";
  for(int code : encoded) {
    std::cout << code << " ";
  }
  std::cout << std::endl;
  std::cout << "decoded: " << decoded << std::endl;

  return 0;
}
