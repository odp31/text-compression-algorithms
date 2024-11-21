// lossless data compression algorithm
// rearranges input data to improve compression ratios, especially for highly repetitive text

function BWT(text)
{
  const suffixArray = [];
  const n = text.length;

  // create suffix array
  for(let i = 0; i < n; i++)
    {
      suffixArray.push(text.substring(i));
    }
  // sort suffix array lexicographically 
  suffixArray.sort();
  // extract last character of each sorted suffix
  let BWT = "";
  for(let i = 0; i < n; i++)
    {
      BWT += suffixArray[i].charAt(n-1);
    }
  return BWT;
}

// example usage
const text = "banana";
const BWT_text = BWT(text);
console.log("BWT: ", BWT_text);
