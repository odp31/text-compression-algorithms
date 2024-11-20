# lossless data compression algorithm 
# assigns variable-length codes to input characters, w/ the code length inversely proportional to the character's frequency
# more freqeuent characters get shorter codes and less frequent characters get longer codes 

from heapq import heappush, heappop 

class Node:
  def __init__(self, char, freq):
    self.char = char
    self.freq = freq
    self.left = None
    self.right = None

  def __lt__(self, other):
    return self.freq < other.freq 


def huffman_encoding(text):
  freq = {}
  for char in text:
    if char in freq:
      freq[char] += 1
    else:
      freq[char] = 1

  pq = []
  for char, freq in freq.items():
    heappush(pq, Node(char, freq))

  while len(pq) > 1:
    left = heappop(pq)
    right = heappop(pq)
    parent = Node(None, left.freq + right.freq)
    parent.left = left
    parent.right = right
    heappush(pq, parent)

  root = pq[0]

  code = {}
  def encode(node, curr_code):
    if node is None:
      return 
    if node.char is not None:
      code[node.char] = curr_code
      return
    encode(node.left, curr_code + "0")
    encode(node.right, curr_code + "1")

  encode(root, "")
  encoded_text = ""
  for char in text:
    encoded_text += code[char]
  return encoded_text, root 

def huffman_decoding(encoded_text, root):
  curr_node = root
  decoded_text = ""
  for bit in encoded_text:
    if bit == '0':
      curr_node = curr_node.left
    else:
      curr_node = curr_node.right
    if curr_node.char is not None:
      decoded_text += curr_node.char
      curr_node = root
  return decoded text 

if __name__ == "__main__":
  text = "Huffman coding is a data compression algorithm"
  encoded_text, root = huffman_encoding(text)
  print("encoded text:", encoded_text)

  decoded_text = huffman_decoding(encoded_text, root)
  print("decoded text:", decoded_text) 
