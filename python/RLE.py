def compress(input_string):
  output_string = ""
  count = 1

  for i in range(1, len(input_string)):
    if input_string[i] == input_string[i-1]:
      count+= 1
    else:
      output_string += str(count) + input_string[i - 1]
      count = 1

  # handle last character
  output_string += str(count) + input_string[-1]
  return output_string

def decompress(input_string):
  output_string = ""
  i = 0

  while i < len(input_string):
    count = int(input_string[i])
    char = input_string[i+1]
    output_string += char * count
    i += 2

  return output_string 

# example usage 
text = "AAAAABBBCCDAA"
compressed_text = compress(text)
print("compressed:", compressed_text)

decompressed_text = decompress(compressed_text)
print("Decompressed: ", decompressed_text)
