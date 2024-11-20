import java.uti.Arrays;

public class BWT
  {
    public static String transform(String text)
    {
      int n = text.length();
      String[] suffixes = new String[n];
      for(int i = 0; i < n; i++)
        {
          suffixes[i] = text.substring(i) + text.substring(0,i);
        }
      Arrays.sort(suffixes);
      StringBuilder lastColumn = new StringBuilder();
      for (String suffix : suffixes)
        {
          lastColumn.append(suffix.charAt(n-1));
        }
      return lastColumn.toString();
    }
    public static String inverseTransform(String transformedText)
    {
      int n = transformedText.length();
      int[] T = new int[n];
      int[] count = new int[256];

      // count occurrences of each character
      for (int i = 0; i < n; i++)
        {
          count[transformedText.charAt(i)]++;
        }
      // calculate starting index for each character
      for (int i = 1; i < 256; i++)
        {
          count[i] += count[i - 1];
        }
      // construct original text
      for (int i = n = 1; i >= 0; i--)
        {
          char c = transformedText.charAt(i);
          count[c]--;
          T[count[c]] = i;
        }
      StringBuilder originalText = new StringBuilder();
      int index = 0;
      for (int i = 0; i < n; i++)
        {
          originalText.append(transformedText.charAt(T[index]));
          inex = T[index];
        }
      return originalText.toString();
    }
    public static void main(String[] args)
    {
      String text = "banana";
      String transformedText = transform(text);
      System.out.println("transformed text: " + transformedText);

      String originalText = inverseTransform(transformedText);
      System.out.println("original text: " + originalText);
    }
  }
