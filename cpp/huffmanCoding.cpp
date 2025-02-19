// variable length prefix coding algorithm
// assigns shorter codes to more frequent characters and longer codes to less frequent characters
// minimizes average code length, leanding to compression 
// steps; 1. frequency calculation- determine frequency of each character in the input text
// 2. build huffman tree; create binary tree where each leaf node reps a character and its frequency
// 3. generate codes; traverse huffman tree to assign codes to each character; a left branch represents a '0', right 
// branch represents a '1;
// 4. encoding; replace each character in the text with its corresponding huffman code
// 5. decoding; use huffman tree to decode the encoded text 


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>


// structure for huffman tree node 
struct Node {
  char ch;
  int freq; 
  Node *left, *right;

  Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
  struct Compare {
    bool operator()(Node* l, Node* r) {
      return l->freq > r->freq;
    }
};
};

std::map<char, std::string> generateHuffmanCodes(Node* root) {
  std::map<char, std::string> codes;
  std::function<void(Node*, std::string) > traverse = 
    [&](Node* node, std::string code) {
      if(!node) return;
      if(node->left == nullptr && node->right == nullptr) {
        codes[node->ch] = code;
      }
      traverse(node->left, code + "0");
      traverse(node->right, code + "1");
    };
    traverse(root, "");
    return codes;
}

Node* buildHuffmanTree(const std::map<char, int>& frequencies) {
  std::priority_queue<Node*, std::vector<Node*>, Node::Compare> pq;
  for(auto const& [ch, freq] : frequencies) {
    pq.push(new Node(ch, freq));
  }
  while(pq.size() > 1) {
    Node* left = pq.top(); pq.pop();
    Node* right = pq.top(); pq.pop();
    Node* parent = new Node('\0', left->freq + right->freq);
    parent->left = left;
    parent->right = right;
    pq.push(parent);
  }
  return pq.top();
}

std::string huffmanEncode(const std::string& text) {
  std::map<char,int> frequencies;
  for(char ch : text) {
    frequencies[ch]++;
  }
  Node* root = buildHuffmanTree(frequencies);
  std::map<char, std::string> codes = generateHuffmanCodes(root);

  std::string encodedText = "";
  for(char ch : text) {
    encodedText += codes[ch];
  }
  return encodedText;
}

std::string huffmanDecode(const std::string& encodedText, Node* root) {
  std::string decodedText = "";
  Node* current = root;
  for(char bit : encodedText) {
    if(bit == '0') {
      current = current->left;
    } else {
      current = current->right;
    }
    if(current->left == nullptr && current->right == nullptr) {
      decodedText += current->ch;
      current = root;
    }
  }
  return decodedText;
}

int main() {
  std::string text = "this is an example of huffman coding";
  std::string encoded = huffmanEncode(text);
  std::map<char, int> frequencies;
  for(char ch: text) {
    frequencies[ch]++;
  }
  Node* root = buildHuffmanTree(frequencies);

  std::string decoded = huffmanDecode(encoded, root);

  std::cout << "original: " << text << std::endl;
  std::cout << "encoded: " << encoded << std::endl;
  std::cout << "decoded: " << decoded << std::endl;

  // clean up memory
  std::function<void(Node*) > deleteTree = [&](Node* node) {
    if(!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  };
  deleteTree(root);
  return 0;
}
