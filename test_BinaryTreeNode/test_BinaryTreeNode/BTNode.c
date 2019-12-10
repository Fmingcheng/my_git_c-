#include "BTNode.h"


BTNode* BinaryTreeCreate(BTDataType* a,int* pi) //����ǰ���������������
{
   BTNode* root=NULL;
   if(a[*pi]=='#')
   {
      ++(*pi);
	  return NULL;
   }
   else{
   root=(BTNode*)malloc(sizeof(BTNode));
   root->_data=a[*pi];
   ++(*pi); //�ݹ��÷�

   root->_left=BinaryTreeCreate(a,pi);
   root->_right=BinaryTreeCreate(a,pi);
   return root;
   }
}

void BinaryTreeDestory(BTNode* root)
{
   if(root==NULL)
	   return;
   BinaryTreeDestory(root->_left);
   BinaryTreeDestory(root->_right);
   free(root); //�����ƿ�root,tree��root����һ��ָ�룬��Ҫ�����ƿ�Ҫ����ַ
}

void BinaryTreeInOrder(BTNode* root)//�������
{
   if(root==NULL)
	   return;

   BinaryTreeInOrder(root->_left);
   printf("%c ",root->_data);
   BinaryTreeInOrder(root->_right);
}
void TestBinaryTree()
{
	BTNode* tree=NULL;
	int index=0;
	char* array=(char*)malloc(sizeof(char)*100);
	scanf("%s",array);
	tree=BinaryTreeCreate(array,&index);
    BinaryTreeInOrder(tree);
    BinaryTreeDestory(tree);
    tree=NULL; //tree�ƿգ���Ȼ����Ұָ��
	free(array);
}
