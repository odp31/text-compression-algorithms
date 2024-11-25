import java.util.HashMap;
import java.util.Map;

public class DictionaryBasedCompression
  {
    public static byte[] compress(String text) {
      Map<String, Integer> dictionary = new HashMap<>();
      int code = 256; 

      StringBuilder sb = new StringBuilder();
      for(int i = 0; i < text.length(); i++) {
        String key = text.substring(i);
        if(!dictionary.containsKey(key)) {
          dictionary.put(key, code++);
        }
        sb.append(dictionary.get(key));
        i += key.length() -  1; 
      }
      // convert compressed text to byte array 
      byte[] compressedData = new byte[sb.length() / 8 + 1];
      for(int i = 0; i < sb.length(); i += 8) {
        String byteStr = sb.substring(i, Math.min(i + 8, sb.length()));
        compressedData[i / 8] = (byte) Integer.parseInt(byteStr, 2);
      }
      return compressedData;
    }
    public static String decompress(byte[] compressedData, Map<Integer, String> dictionary)
    {
      StringBuilder sb = new StringBuilder();
      int w = 0;

      for(byte b: compressedData) {
        int code = b & 0xFF;
        String entry = dictionary.get(code);
        sb.append(entry);
        w = code;
        if(dictionary.containsKey(w)) {
          sb.append(dictionary.get(w));
        }
      }
      return sb.toString();
    }
    public static void main(String[] args)
    {
      String text = "ABACAABB";
      byte[] compressedData = compress(text);

      Map<Integer, String> dictionary = new HashMap<>();
      String decompressedText = decompress(compressedData, dictionary);
      System.out.println(decompressedText(;
    }
  }
