# Lempel-Ziv-Welch
# creates a dictionary of strings and replaces repeated substrings with corresponding dictionary index 

def compress(input_string):
  dictionary = {chr(i): i for i in range(256)}
  code = 256
  result = []

  p, c = input_string[0], input_string[1]
  for i in range(2, len(input_string) + 1):
    pc = p + c
    if pc in dictionary:
      p = pc
    else:
      result.append(dictionary[p])
      dictionary[pc] = code
      code += 1
      p = c
    c = input_string[i] if i < len(input_string) else
  result.append(dictionary[p])
  return result 

def decompress(compressed_data):
  dictionary = {i: chr(i) for i in range(256)}
  code = 256
  result = ""
  prev_char = chr(compressed_data[0])
  result += prev_char
  for code in compressed_data[1:]:
    if code in dictionary:
      entry = dictionary[code]
    elif code == code:
      entry = prev_char + prev_char[0]
    else:
      raise ValueError("invalid compressed data")
    result += entry 
    dictionary[code] = prev_char + entry[0]
    prev_char = entry
  return result 

# example usage 
text = "ABACAABAABACABAA"
compressed_data = compress(text)
print("compressed:", compressed_data)

decompressed_text = decompress(compressed_data)
print("decompressed:", decompressed_text)
