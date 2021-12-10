
public class BinaryTree {

    // TODO complete this method
    public static boolean isValid(int[] arr) {
      if (arr.length == 1) return true; // if binary tree is 0 in length.
      return isBSTHelper(arr, 1, Integer.MIN_VALUE, Integer.MAX_VALUE); 
    }

    public static boolean isBSTHelper(int[] arr, int index, int min, int max) {
      if (index >= arr.length) // if we go out of bounds, then we've reached the leaf nodes and beyond, so we return true.
        return true; 
      if (arr[index] < min || arr[index] > max)  
        return false;
      return (isBSTHelper(arr, 2*index, min, arr[index] - 1) && (isBSTHelper(arr, 2*index + 1, arr[index] + 1, max)));
    }
    public static void main (String args[]) {
      // milestone 1
      int[] arr1 = new int[]{-1,7,4,10,3,6,8,15};
      int[] arr2 = new int[]{-1,20,12,32,5,18,25,38};
      int[] arr3 = new int[]{-1,11,3,33,2,8,10,44};
      int[] arr4 = new int[]{-1,55,44,77,33,48,54,95,22,34,45,57,53,70,85,98};

      System.out.println("arr1 valid: " + isValid(arr1));  // expected: true
      System.out.println("arr2 valid: " + isValid(arr2));  // expected: true
      System.out.println("arr3 valid: " + isValid(arr3));  // expected: false
      System.out.println("arr4 valid: " + isValid(arr4));  // expected: false
    }
}
