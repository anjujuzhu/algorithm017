学习笔记
1. 最大的误区：做题只做一遍 | 不要死磕，重复练习，过遍数！

2. 五毒神掌
    a. 5~10min没有思路，看题解，背诵代码模板
    b. 马上自己写一遍-->提交，包括多种解法
    (看题解及国际站题解优化,most votes里面自己语言的最高票的三个解答)
    c. 24小时后重做
    d. 一周后重做
    e. 面试前一周内重做

3. 切题“四件套”
    a. clarification 与面试官沟通确认题目信息的细节
    b. possible solutions --> optimal （time & space）列出所有可能的解法，比较他们的复杂度，选出最优解法
    c. code 
    d. test cases 测试样例

4. 训练环境，VScode的设置，指法的刻意练习

5. add first 改写Deque的代码

```java
import java.util.Deque;
import java.util.LinkedList;

public class changeDequeExample {
  
  public static void main(String []args) {
    Deque<String> deque = new LinkedList<String>();

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
```
6. 分析![stackSourceCode](D:\askOffer\mindpicture\stackSourceCode.png)

