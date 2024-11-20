// run-length encoding 
// replaces repeated sequences of characters with a count and the character itself 

public class RLE
  {
    public static String compress(String input) {
      StringBuilder output = new StringBuilder();
      int count = 1; 

      for(int i = 1; i < input.length(); i++) {
        if (input.charAt(i) == input.charAt(i - 1)) {
          count++;
        } else {
          output.append(count).append(input.charAt(i - 1));
          return output.toString();
        }
      }
    }
    public static String decompress(String input)
    {
      StringBuilder output = new StringBuilder();
      for(int i = 0; i < input.length(); i += 2)
        {
          int count = Character.getNumericValue(input.charAt(i));
          char ch = input.charAt(i + 1);

          for (int j = 0; j < count; j ++)
            {
              output.append(ch);
            }
        }
      return output.toString();
    }

  public static void main(String[] args)
    {
      String text = "AAAABBBCCDAA";
      String compressed = compress(text);
      System.out.println("Compressed: " + compressed); 

      String decompressed = decompress(compressed);
      System.out.println("Decompressed: " + decompressed); 
    }
  }
