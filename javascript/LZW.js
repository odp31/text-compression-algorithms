// Lempel-Ziv-Welch (LZW)
// lossless data compression algorithm that works by replacing repeated sequences of characters w/ single code

function LZWEncode(input)
{
  const dictionary = {};
  let code = 256; 

  for(let i = 0; i < 256; i++)
    {
      dictionary[String.fromCharCode(i)] = i;
    }
  let result = [];
  let p = input[0];

  for(let i = 1; i < input.length; i++)
    {
      let c = input[i];
      let pc = p + c;
      if(dictionary[pc]){
        p = pc;
      }
      else
      {
        result.push(dictionary[p]);
        dictionary[pc] = code;
        code++;
        p = c;
      }
    }
  result.push(dictionary[p]);
  return result;
}

function LZWDecode(encodedData)
{
  const dictionary = {};
  for(let i = 0; i < 256; i++)
    {
      dictionary[i] = String.fromCharCode(i);
    }
  let code = 256; 
  let result = dictionary[encodedData[0]];
  let p = dictionary[encodedData[0]];

  for(let i = 1; i < encodedData.length; i++)
    {
      let c = encodedData[i];
      if(dictionary[c])
      {
        let entry = dictionary[c];
        result += entry;
        dictionary[code] = p + entry[0];
        code++;
        p = entry;
      }
      else
      {
        let entry = p + p[0];
        result += entry;
        dictionary[code] = entry;
        code++;
        p = entry;
      }
    }
  return result;
}

// example usage
const input = "ABACA";
const encoded = LZWEncode(input);
const decoded = LZWDecode(encoded);

console.log("encoded: ", encoded);
console.log("decoded: ", decoded); 
