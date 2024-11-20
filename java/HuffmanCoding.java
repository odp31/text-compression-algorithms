import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.Map;

class Node {
  char ch;
  int freq;
  Node left, right;

  Node(char ch, int freq) {
    this.ch = ch;
    this.freq = freq;
    left = right = null;
  }
}

public class HuffmanCoding {
  public static void printCodes(Node root, String str)
  {
    if (root == null)
      return;
    if (root.ch != '\0') {
      System.out.println(root.ch + ": " + str);
    }
    printCodes(root.left, str + "0");
    printCodes(root.right, str + "1");
  }
  public static void HuffmanCode (String text)
  {
    int n = text.length();
    // create a map to store character frequencies 
    Map<Character, Integer> freq = new HashMap<>();
    for (char ch: text.toCharArray()) {
      freq.put(ch, freq.getOrDefault(ch, 0) + 1);
    }
    // create PQ to store characters and their frequencies 
    PriorityQueue<Node> pq = new PriorityQueue<>(freq.size(), (a,b) -> a.freq - b.freq);
    // add all characters to PQ
    for (Map.Entry<Character, Integer> entry: freq.entrySet()) {
      pq.add(new Node(entry.getKey(), entry.getValue()));
    }
    // build huffman tree
    while (pq.size() > 1)
      {
        Node left = pq.poll();
        Node right = pq.poll();

        Node parent = new Node('\0', left.freq + right.freq);
        parent.left = left;
        parent.right = right; 
        pq.add(parent);
      }
    // print huffman codes
    printCodes(pq.peek(), ""):
    }
  public static void main(String[] args)
  {
    String text = "Huffman coding is a data compression algorithm.";
    HuffmanCode(text):
      }
}
