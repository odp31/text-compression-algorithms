// works by replacing frequently occurring sequences of characters (phrase or words) with shorter codes or references
// maintain a dictionary, explicit or implicit, of these sequences 
// when a sequence is encountered, its replaced with its corresponding code, reducing overall size of data

// lZ77 is a sliding-window based algorithm; uses lookahed buffer and search buffer
// seraches search buffer for longest match to a prefix of the lookahead buffer

#include <iostream>
#include <string>
#include <vector>

std::vector<std::pair<int, int>> lz77_encode(const std::string& text, int window_size, int lookahead_size) {
  int n = text.length();
  std::vector<std::pair<int, int>> encoded;

  for(int i = 0; i < n) {
    int best_match_len = 0;
    int best_match_pos = 0;

    for(int j = std::max(0, i - window_size); j < i; ++j) {
      int len = 0;
      while(i + len < n && j + len < n && text[i + len] == text[j + len] && len < lookahead_size) {
        len++;
      }
      if(len > best_match_len) {
        best_match_len = len;  
        best_match_pos = j;
      }
    }
    if(best_match_len > 0) {
      encoded.push_back({i - best_match_pos, best_match_len});
      i += best_match_len;
    } else {
      encoded.push_back({0,1});
      i++;
    }
  }
  return encoded;
}

std::string lz77_decode(const std::vector<std::pair<int, int>>& encoded) {
  std::string decoded = "";
  for(const auto& pair: encoded) {
    int offset = pair.first;
    int length = pair.second;

    if(offset == 0) {
      if(!decoded.empty()) {
        decoded += decoded.back();
      } else if (length == 1) {
        decoded += 'a';
      }
    } else {
      for(int i = 0; i < length; ++i) {
        decoded += decoded[decoded.length() - offset + i];
      }
    }
  }
  return decoded;
}

int main() {
  std::string text = "abracadabrabracadabra";
  int window_size = 10; 
  int lookahead_size = 5;

  std::vector<std::pair<int, int>> encoded = lz77_encode(text, window_size, lookahead_size);
  std::cout << "encoded: ";
  for(const auto& p: encoded) {
    std::cout << "(" << p.first << ", " << p.second << ")";
  }
  std::cout << std:endl;

  std::string decoded = lz77_decode(encoded);
  std::cout << "decoded" << decoded << std::endl;

  return 0;
}
