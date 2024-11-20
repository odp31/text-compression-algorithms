# Burrows-Wheeler Transform
# reverse data permutation algorithm that rearranges input data to improve compressibility


def bwt(text): # performs BWT on input text, returns transformed text and original index 
  suffix_matrix = sorted([text[i:] + text[:i] for i in range(len(text))])
  last_column = ''.join(suffix[len(text) - 1] for suffix in suffix_matrix)
  original_index = suffix_matrix.index(text)

  return last_column, original_index

def inverse_bwt(transformed_text, original_index):
  n = len(transformed_text)
  T = [NONE] * n
  T[original_index] = '$'
  rank = [0] * 256
  for i in range(n):
    rank[ord(transformed_text[i])] += 1

  for i in range(1, 256):
    rank[i] += rank[i - 1]

  for i in range(n - 1, -1, -1):
    c = transformed_text[i]
    rank[ord(c)] = 1
    T[rank[ord(c)]] = c
  return ''.join(T)

# example usage
text = "banana"
transformed_text, original_index = bwt(text)
print("transformed text: ", transformed_text)
print("original index: ", original_index)

original_text = inverse_bwt(transformed_text, original_index)
print("original text: " , original_text)
