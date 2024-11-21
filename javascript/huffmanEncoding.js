// lossless data compression algorithm
// assigns variable-length codes to input characters with the goal of minimizing the overall code length

class Node
  {
    constructor(data, freq)
    {
      this.data = data;
      this.freq = freq;
      this.left = null;
      this.right = null;
    }
  }
function huffmanEncoding(text)
{
  // create frequency array to store character frequencies
  const freq = [];
  for(let i = 0; i < 256; i++)
    {
      freq[i] = 0;
    }
  for(let i = 0; i < text.length; i++)
    {
      freq[text.charCodeAt(i)]++;
    }
  // create priority queue to store nodes
  const pq = [];
  for(let i = 0; i < 256; i++)
    {
      if(freq[i] != 0)
      {
        pq.push(new Node(i, freq[i]));
      }
    }
  pq.sort((a,b) => a.freq - b.freq);
  // build huffman tree
  while(pq.length > 1)
    {
      const x = pq.shift();
      const y = pq.shift();

      const node = new Node(null, x.freq + y.freq);
      node.left = x;
      node.right = y;

      pq.push(node);
      pq.sort((a, b) => a.freq - b.freq);
    }
  // print huffman codes
  const huffmanCode = [];
  const code = [];
  encode(pq[0], huffmanCode, code);

  for(let i = 0; i < 256; i++)
    {
      if(freq[i] != 0)
      {
        console.log('${chr(i)} ${huffmanCode[i]}');
      }
    }
}
function encode(root, huffmanCode, code)
{
  if(root == null)
    return;

  // assign 0 to left edge and right edge
  if(root.data != null)
  {
    huffmanCode[root.data] = code.join(' ');
  }
  code.push('0');
  encode(root.left, huffmanCode, code);
  code.pop();

  code.push('1');
  encode(root.right, huffmanCode, cdoe);
  code.pop();
}
// helper function to convert int to char
function chr(charCode)
{
  return String.fromCharCode(charCode);
}
// example usage
const text = "Huffman coding is a data compression algorithm";
huffmanEncoding(text); 
