import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class changeDequeExample {
  
  public static void main(String []args) {
    Deque<String> deque = new LinkedList<String>();
    Queue<String> queue = new LinkedList<String>();
    Stack<Integer> stack = new Stack<>();
    stack.push(1);
    queue.offer("one");
    deque.addFirst("a");
    deque.addFirst("b");
    deque.addFirst("c");
    deque.addFirst("d");
    
    String str = deque.peek();
    System.out.println(str);
    System.out.println(deque);
    
    while (deque.size() > 0) {
      System.out.println(deque.removeFirst());
    }
  
    System.out.println(deque);
    
  }
}
