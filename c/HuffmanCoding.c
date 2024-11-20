#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  char ch;
  int freq;
  struct Node *left, *right;
}
Node;

Node* newNode(char ch, int freq) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->ch = ch;
  node->freq = freq;
  node->left = node->right = NULL;
  return node;
}

void printCodes(Node* root, int arr[], int top)
{
  if (root == NULL)
    return;

  if (root-> ch != '\0'){
    printf("%c: ", root->ch);
    for (int i = 0; i < top; i++)
      printf("%d", arr[i]);
    printf("\n");
  }
  arr[top] = 0; 
  printCodes(root->left, arr, top + 1);

  arr[top] = 1;
  printCodes(root->right, arr, top + 1);
}

void HuffmanCodes(char data[], int n)
{
  int charCount[256] = {0};
  for(int i = 0; i < n; i++)
    charCount[data[i]]++;

  // create a PQ to store characters and their frequencies 
  Node* pq = (Node*)malloc(sizeof(Node)*256);
  int size = 0;

  for(char ch = 0; ch < 256; ch++) {
    if(charCount[ch] > 0) {
      pq[size] = *newNode(ch, charCount[ch]);
      size++;
    }
  }

// build huffman tree 
  while (size != 1) {
    Node* left = &pq[0];
    Node* right = &pq[1];

    Node* parent = newNode('\0', left->freq + right->freq);
    parent->left = left;
    parent-> right = right;

    for(int i = 1; i < size; i++)
      pq[i - 1] = pq[i];

    pq[size - 1] = parent;
    size--;
  }
int arr[256];
printCodes(pq[0], arr, 0);
}

int main()
{
  char data[] = "Huffman coding is a data compression algorithm";
  int size = sizeof(data) / sizeof(data[0]);
  HuffmanCodes(data, size);
  return 0; 
}
    
