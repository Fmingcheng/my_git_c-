#include "BTNode.h"


BTNode* BinaryTreeCreate(BTDataType* a,int* pi) //根据前序遍历构建二叉树
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
   ++(*pi); //递归用法

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
   free(root); //不用制空root,tree和root不是一个指针，若要在这制空要传地址
}

void BinaryTreeInOrder(BTNode* root)//中序遍历
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
    tree=NULL; //tree制空，不然会变成野指针
	free(array);
}
