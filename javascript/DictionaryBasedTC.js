function compress(text)
{
  const dictionary = {};
  let code = 256;
  const compressed = [];

  for(let i = 0; i < text.length; i++) {
    let key = text[i];
    while(i + 1 < text.length && dictionary[key + text[i + 1]]) {
      key += text[i + 1];
      i++;
    }
    if(!dictionary[key]){
      dictionary[key] = code++;
    }
    compressed.push(dictionary[key]);
  }
  return compressed;
}

function decompress(compressesd, dictionary)
{
  let w = "";
  const decompressed = [];

  for(const code of compressed)
    {
      w += dictionary[code];
      if(dictionary[w]) {
        decompressed.push(w);
        w = "";
      }
    }
  return decompressed.join("");
}

// example usage
const text = "ABACAABB";
const compressed = compress(text);
console.log(compressed);

const dictionary = {};
const decompressed = decompress(compressed, dictionary);
console.log(decompressed); 
