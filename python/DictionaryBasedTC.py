def compress(text):
  """ compresses given text using a dictionary based approach
  Args:
    text: the input text to be compressed
  returns:
    tuple containing the compressed text and the dictionary used for compression
    """
  dictionary = {}
  code = 256
  compressed_text = []

  for i in range(len(text)):
    char = text[i]
    if char not in dictionary:
      dictionary[char] = code
      code += 1
    if i == 0:
      compressed_text.append(dictionary[char])
    else:
      prev_char = text[i - 1]
      prev_code = dictionary[prev_char]

      if prev_char + char in dictionary:
        prev_char = prev_char + char
      else:
        dictionary[prev_char + char] = code
        code += 1
        compressed_text.append(prev_code)
        prev_char = char
    compressed_text.append(dictionary[prev_char])
  return compressed_text, dictionary 


def decompress(compressed_text, dictionary)
{
  decompressed_text = ""
  w = ""
  for code in compressed_text:
    if code in dictionary:
      w += dictionary[code]
      if w in dictionary:
        decompressed_text += w
        w = ""
    else:
      raise ValueError("invalid code in compressed text")
  return decompressed_text

# example usage
text = "ABACAABB"
compressed_text, dictionary = compress(text)
print(compressed_text)
print(dictionary)

decompressed_text = decompress(compressed_text, dictionary)
print(decompressed_text)
  
