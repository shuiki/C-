#ifndef CONVERT_TREE_H
#define CONVERT_TREE_H
#include<queue>
#include<iostream>

typedef struct {
	char type;
	char var;
} Qualifier;


const int TEXTLEN=30;
static bool variUsed[26];//��־�����ù�����ĸ����a��ʼ
static bool funcUsed[26];//��־�����ù�����ĸ����Ҫ��f��ʼ
//static bool exisUsed[26];//���������滻�ù�����ĸ
static int clauseVariUsed[26];//�Ӿ�����ù�����ĸ
static char reflect[26];

struct LogicNode {
	Qualifier qualifiers[10] = { 0 };//�������
	int quaNum = 0;//������Ŀ
	bool isLeaf = true;//�Ƿ�ԭ�����
	bool antiFlag = false;//�Ƿ��зǷ���
	bool emptyFlag = false;//�ǿս��
	char name[TEXTLEN] = { 0 };//�������Q(x)�е�Q
	int nameLen = 0;
	char vars[TEXTLEN] = { 0 };//������
	int varsNum = 0;
	LogicNode* child = nullptr;
	LogicNode* brother = nullptr;
	char broLink = '\0';//���ֵܵ����ӷ�
};
//rootΪempty����
//!quaNum&&!isLeaf&&!antiFlag&&!nameLen&&!varsNum&&!root->child->isLeaf


const int Letter = 0;
const int Qualif = 1;
const int Linker = 2;
const int Unknown = 3;

bool isLetter(char c);
bool isUpper(char c);
bool isLower(char c); 
int getType(char c);
LogicNode* createNode(char* str, int len, int& pos,int thisIndex,int& curIndex,bool conti, bool isQuialNode=false);
//thisIndex: �м������ʣ�curIndex:��������û��ɣ�conti:�Ƿ��������������ʣ�isQuialNode:�Ƿ�������������ڵ㣨���ʺ��һ�����ţ�
LogicNode* strToTree(char* str, int len);
int formRead(wchar_t* a, char* str,bool*exisUsed=NULL);
void showNode(LogicNode* root, char* str, int& pos);
int treeToStr(LogicNode* root, char* str);
LogicNode* copyTree(LogicNode* root,bool isRoot=true);
LogicNode* copyNode(LogicNode* root);
void settleTree(LogicNode* root, LogicNode* front, bool parentFlag, char depLink,char* concludeReflect);//�����������ر�׼������������ͬһ���㶼����ͬһ��

//parent��root��ǰ���ڵ� deplink��root���ڲ���������
LogicNode* collectUsefulNodes(LogicNode* root,char link='\0');//������ýڵ�
void letLeafFirst(LogicNode* root,LogicNode* parent);
void deleteTree(LogicNode* root);
int showTree(LogicNode* root, bool showClause = false);
void adjustTree(LogicNode*& root);//ֱ�ӱ�main���õĺ���
wchar_t corre(char c);
//LogicNode* copyTreeWithoutBro(LogicNode* root);
#endif 