// burrows wheeler transfor (BTW)
// rearranges input string into a new string that tends to have rusn of identical characters; is reversible 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string bwt(const std::string& s) {
  int n = s.length();
  std::vector<std::string> rotations(n);

  for(int i = 0; i < n; i++) {
    rotations[i] = s.substr(i) + s.substr(0, i);
  }
  std::sort(rotations.begin(), rotations.end());
  std::string bwt_string = "";
  for(int i = 0; i < n; i++) {
    bwt_string += rotations[i][n-1];
  }
  return bwt_string;
}

std::string inverse_bwt(const std::string& bwt_string) {
  int n = bwt_string.length();
  std::vector<std::string> rotations(n, std::string(n, ' '));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      rotations[j] = bwt_string[j] + rotations[j].substr(0, n - 1);
    }
    std::sort(rotations.begin(), rotations.end());
  }
  // find original string
  for(const auto& s: rotations) {
    if(s.back() == '$') {
      return s.substr(0, n - 1);
    }
  }
  return rotations[0];
}
int main() {
  std::string text = "banana$";
  std::string bwt_result = bwt(text);
  std::cout << "BWT: " << bwt_result << std::endl;
  std:string original_text = inverse_bwt(bwt_result);
  std::cout << "inverse bwt:" << original_text << std::endl;
  return 0;
}
