#ifndef CONVERT_CLAUSE_H
#define CONVERT_CLAUSE_H
#include "convertTree.h"

extern bool variUsed[26];//��־�����ù�����ĸ����a��ʼ
extern bool funcUsed[26];//��־�����ù�����ĸ����Ҫ��f��ʼ
extern int clauseVariUsed[26];//��־�Ӿ�������ù�����ĸ



extern char concludeReflect[26];
const int notRelated = 0;
const int equal = 1;
const int opposite = 2;

const int ok = 0;
const int change = 1;

const int isNull = 2;

void first_del_arrow(LogicNode* root);
void second_del_neg(LogicNode* root);
void del_neg(LogicNode* root);
void third_var_regulation(LogicNode* root);
void fourth_del_exist(LogicNode* root, char* base, int baseNum, char* exist, int existNum,bool* exisUsed);
void fifth_mov_all(LogicNode* root, LogicNode* curNode);
void sixth_convert_cnf(LogicNode*& root);
void makeCalc(LogicNode* root, int& changeNum);
void calAll(LogicNode*& root, int& changeNum,bool isRoot=false);
bool mergeInNode(LogicNode* root,int& status,bool conclude=false);//��ȥ�ظ����ӽڵ㣬Ҫ���ӽڵ�ȫ��Ҷ�ӽڵ�,�����Ƿ����ӽڵ�ʣ��(false�������ڵ�ɾ��)
int mergeBetweenNodes(LogicNode*& a,LogicNode*& b,bool conclude=false);//��ȥ�����໥�����ӽڵ�
int mergeRoot(LogicNode*& root,bool conclude=false);
int getRelation(LogicNode*& a, LogicNode*& b,bool conclude=false);
void seventh_del_all(LogicNode* root);
void ninth_clause_var_regu(LogicNode* root, char* u, int len);
bool belong_to_u(char c, char* u, int len);
void deal_exist(LogicNode*& root,char* u,int len);//��ṫ������󣬼�����������ʱ����,uΪȫ������֮ǰ�ô�д��ĸ�ͺ�����־�Ĵ��ڷ�����ȫ���и����滻
#endif