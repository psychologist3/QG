
typedef  struct StackNode
{
	int word;
	struct StackNode *next;	
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr 	 top;	  //栈顶指针
	int		 count;  //栈中元素个数
}LinkStack;

