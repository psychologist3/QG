
typedef  struct StackNode
{
	int word;
	struct StackNode *next;	
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr 	 top;	  //ջ��ָ��
	int		 count;  //ջ��Ԫ�ظ���
}LinkStack;

