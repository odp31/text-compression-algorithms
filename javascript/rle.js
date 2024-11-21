// run length encoding; simple data compression technique that replaces repeated sequences 
// of identical characters with a single instance of the character followed by a count

function encode(str)
{
  let encodedString = "";
  let count = 1;

  for(let i = 0; i < str.length; i++)
    {
      if(i+1 < str.length && str[i] === str[i+1])
      {
        count++;
      }
      else
      {
        encodedString += str[i] + count;
        count = 1;
      }
    }
  return encodedString;
}

function decode(str)
{
  let decodedString = "";
  let i = 0;

  while(i < str.length)
    {
      let count = "";
      while(i < str.length && !isNan(parseInt(str[i])))
        {
          count += str[i];
          i++;
        }
      decodedString += str[i].repeat(parseInt(count));
      i++;
    }
  return decodedString;
}
// example usage
const inputString = "AAAABBBCCDAA";
const encodedString = encode(inputString);
const decodedString = decode(encodedString);

console.log("original string:", inputString);
console.log("encoded string:", encodedString);
console.log("decoded string:", decodedString); 
