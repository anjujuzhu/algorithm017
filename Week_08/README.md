学习笔记
### 位运算
- XOR 异或
 x ^ 0 = x
 x ^ 1s = ~x (1s = ~0)
 x ^ (~x) = 1s
 x ^ x = 0
 c = a ^ b => a ^ c
- 指定位置的位运算
 1. 将x最右边的n位清零：x & (~0 << n)
 2. 获取x的第n位值(0 或者 1)

### 布隆过滤器
 - 优点：空间效率和查询时间都远远超过一般的算法
 - 缺点：有一定的误识别率和删除困难

### 缓存
 - LRU

### 排序
- 冒泡
```C++
void bubbleSort(int a[], int n){
	int temp = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
```
- 插入
```C++
//插入排序直接插入，从目标位置往前遍历，找到第一个比目标位置数据大的地方，
	//插入到前一个位置上 
void insertSort(int arr[], int start, int end) {
	int temp, j;
	//从前往后遍历，起止点为start+1，原因为后面需要用到下标i-1 
	for(int i = start+1; i < end; i++) {
		j = i; temp = arr[i];//用temp将当前位置的数据保存
		while(arr[j-1] > temp) {
			arr[j] = arr[j-1];
			if(j == 0) break;
			j--;
		}//满足条件即前一个数仍旧比目标位置的数据大，就将数据往后挪一个位置 
		//当条件不满足 即找到了最靠前比目标数据大的数，此时j是该数据的前一个位置 
		arr[j] = temp; 
	}
}
```
- 快速排序
```C++
void quickSort(int arr[], int L, int R){
	if(L >= R){
		return ;
	} 
	int left = L, right = R;
	int temp = arr[left];
	while(left < right){
		while(left < right && arr[right] >= temp){
			right--;
		}
		if(left < right) arr[left] = arr[right];
		while(left < right && arr[left] <= temp){
			left++;
		}
		if(left < right) arr[right] = arr[left];
		if(left >= right) arr[left] = temp;
	}
	quickSort(arr, L, left-1);
	quickSort(arr, right+1, R);
}
```
 - 非递归实现快排
```C++
#include<iostream> 
#include<stdlib.h>
using namespace std;
//使用单链表创造堆栈，结点要指向开头，易删除和插入 
typedef struct SNode *stack;
struct SNode{
	int data;
	stack top; 
}; 
//完成一次快速排序，返回的下标为分割点，接下来要将分割点
//左右边两部分进行快速排序 
int quickSortOneTime(int arr[], int low, int high){
	int basic = arr[low];
	while(low < high){
		while(low < high && arr[high] >= basic) {
			high--;
		}
		if(low < high) arr[low] = arr[high];
		while(low < high && arr[low] <= basic){
			low++;
		}
		if(low < high) arr[high] = arr[low];
	}
	arr[low] = basic;
	return low;
}
//创建堆栈，创建一个头结点，不存放数据，指针指向NULL 
stack makeStack(){
	stack s;
	s = (stack)malloc(sizeof(struct SNode));
	s->top = NULL;
	return s;
}
//入栈 
void push(stack s, int x){
	stack p;
	p = (stack)malloc(sizeof(struct SNode));
	p->data = x;
	p->top = s->top;
	s->top = p;
}
//判断堆栈是否为空，返回值为布尔类型 
bool isEmpty(stack s){
	if(!s->top) return true;
	else return false;
}

//出栈
int pop(stack s){
	if(isEmpty(s)){
		return -1;
	}else{
		stack p = s->top;
		int mid = p->data;
		s->top = p->top;
		free(p);//释放空间 
		return mid;
	}
} 
//非递归实现快速排序，使用压栈
void quickSort2(int arr[], stack s, int low, int high){
	if(low < high){
		//此时堆栈为空，进行第一次快速排序 
		int mid = quickSortOneTime(arr, low, high);
		if(low < mid-1){
			push(s, low);
			push(s, mid-1);
		}
		if(mid+1 < high){
			push(s, mid+1);
			push(s, high);
		}
		//只要堆栈不空，就代表还有子区间内待排序，因此循环 
		while(!isEmpty(s)){
			int high = pop(s);
			int low = pop(s);
			//出栈获得区间下标，进行排序 
			mid = quickSortOneTime(arr, low, high);
			//如果子区间依旧需要排序则依次入栈 
			if(low < mid-1){
				push(s, low);
				push(s, mid-1);
			}
			if(mid+1 < high){
				push(s, mid+1);
				push(s, high);
			}
		}
	}
} 

void print(int arr[]){
	int num = 7;
	for(int i = 0; i < num; i++){
		cout << arr[i] << "*";
	}
}
int main(){
	int arr2[7] = {17,16,15,14,13,12,11};
	stack s = makeStack();
	quickSort2(arr2, s, 0, 6);
	print(arr2);
	return 0;
}

```
- 归并
```C++
void merge(int arr[], int L, int M, int R){
	int len = R - L + 1;
	int newArr[len];
	for(int k = L; k <= R; k++){//传入的arr其实是原数组，而L,R定义的只是其中一段 
		newArr[k - L] = arr[k];//所以将这一段需要进行处理的子序列先复制到一个数组中 
	}//因为新建的newArr，下标是从0到 len，而对应的原数组中是L到R，则k=[L-R],则k-L=【0-(len-1)】 
	int i = L, j = M + 1, k = 0;
	for(int k = L; k <= R; k++){//首先，我们是要将这一段共L-R的每个位置重置的，因此循环这么多次 
		if(i > M && j <= R){//说明左序列已经遍历完，只需将右序列的依次放入即可
			arr[k] = newArr[j-L]; j++;// 
		}
		else if(i <= M && j > R){//右序列遍历完毕，只剩左序列 
			arr[k] = newArr[i-L]; i++;//利用复制的序列将原序列重置 
		}
		else if(newArr[i-L] > newArr[j-L]){//除去以上两种情况，开始比较两个子序列 
			arr[k] = newArr[j-L]; j++;//因为i,j是在L-R中，因此减去L，就是新数组下标对应的位置 
		}//小的先放入先重置数组 
		else if(newArr[i-L] <= newArr[j-L]){
			arr[k] = newArr[i-L]; i++;
		}
	}
}
```
- 堆排序
```C++
void heapAort(vector<int>& arr) {
    priority_queue<int> heap;
    for (auto c : arr) {
        heap.push(c);
    }
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = heap.top();
        heap.pop();
    }
}
```
- 希尔
```C++
void shellSort(int arr[], int start, int end){
	int increment = end - start + 1;	//初始化划分增量
	int temp = 0;
	//确定增量increment，初始值下文将提到 
	//int increment = (end - start + 1)/3 + 1;
	//当增量小于1的时候停止循环 
	while(increment > 1){
		//更新增量的大小 
		increment = increment / 3 + 1;
		//每确定一个increment长度，都要以此增量来遍历数据，进行直接插入，参考上文直接插入的思想 
		for(int i = start+increment; i <= end; i++){
			if(arr[i - increment] > arr[i]){
				//略有不同的是， i 从 start+increment开始，确定目标位置数据，向前以increment为步长跳跃遍历，比较大小 
				int j = i-increment;
				temp = arr[i];
				while(j >= start && arr[j] > temp){
					arr[j+increment] = arr[j];
					j -= increment;
				}
				arr[j+increment] = temp;
			}
		}
	}
}
```