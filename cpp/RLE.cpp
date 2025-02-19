// replaces consecutive occurences of same character with a single instance of the character and the run length
// effective when data contains many runs of identical characters

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string rle_encode(const std::string& text) {
  std::stringstream encdoed;
  if(text.empty()) return "";

  char current_char = text[0];
  int current_count = 1;

  for(size_t i = 1; i < text.length(); ++i) {
    if(text[i] == current_char) {
      current_count++;
    } else {
      encoded << current_char << current_coutn;
      current_char = text[i];
      current_count = 1;
    }
  }
  encoded << current_char << current_count;
  return encoded.str();
}

std::string rle_decode(const std::string& encoded) {
  std::stringstream decoded;
  if(encoded.empty()) return "";

  for(size_t i = 0; i < encoded.length(); i += 2) {
    char ch = encoded[i];
    int count = std::stoi(encoded.substr(i+1, 1));

    for(int j = 0; j < count; ++j) {
      decoded << ch;
    }
  }
  return decoded.str();
}

int main() {
  std::string text = "AAABBCDDDDEEEE";
  std::string encoded = rle_encode(text);
  std::string decoded = rle_decode(encoded);

  std::cout << "original: " << text << std::endl;
  std::cout << "encoded: " << encoded << std::endl;
  std::cout << "decoded: " << decoded << std::endl;

  return 0;
}
