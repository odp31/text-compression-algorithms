import java.util.HashMap;
import java.util.Map; 

public class LZW
  {
    public static byte[] compress(byte[] input)
    {
      int dictionarySize = 256;
      Map<String, Integer> dictionary = new HashMap<>();
      for (int i = 0; i < 256; i++) {
        dictionary.put(String.valueOf((char) i), i);
      }
      StringBuilder w = new StringBuilder();
      w.append((char) input[0]);
      StringBuilder result = new StringBuilder();

      for(int i = 1; i < input.length; i++) {
        String wc = w.toString() + (char) input[i];
        if(dictionary.containsKey(wc)){
          w.append((char)input[i]);
        }
        else{
          result.append(dictionary.get(w.toString()));
          dictionary.put(wc, dictionarySize++);
          w.setLength(1);
          w.append((char) input[i]);
        }
      }
      result.append(dictionary.get(w.toString()));
      // convert result to byte array
      byte[] compressedData = new byte[result.length() / 2];
      for (int i = 0; i < compressedData.length; i++) {
        compressedData[i] = (byte) Integer.parseInt(result.substring(i * 2, i * 2 + 2), 16);
      }
      return compressedData;
    }

    public static byte[] decompress(byte[] compressedData)
    {
      int dictionarySize = 256;
      Map<Integer, String> dictionary = new HashMap<>();
      for(int i = 0; i < 256; i++){
        dictionary.put(i, String.valueOf((char) i));
      }
      StringBuilder w = new StringBuilder();
      w.append((char) compressedData[0]);
      StringBuilder result = new StringBuilder();
      result.append(w.toString());

      int code = 0;
      for(int i - 1; i < compressedData.length; i++) {
        code = code * 256 + compressedData[i];
        if(dictionary.containsKey(code)) {
          String entry = dictionary.get(code);
          result.append(entry);
          w.append(entry.charAt(0));
          dictionary.put(dictionarySize++, w.toString());
        }
        else {
          String entry = w.toString() + w.charAt(0);
          result.append(entry);
          dictionary.put(code, entry);
          w.setLength(1);
          w.append((char) code);
        }
      }
      return result.toString().getBytes();
    }
  }
