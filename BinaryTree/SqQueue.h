/*
 * @Author: farron_cat
 * @Date: 2021-09-11 12:42:19
 * @LastEditTime: 2021-09-20 10:19:31
 * @LastEditors: farron_cat
 * @Description: �������� ͷ�ļ�
 * @FilePath: \Briup\learn\data_structure\BinaryTree\SqQueue.h
 * ��Ȩ�鷨��Сè����
 */
#define MaxSize 10
typedef BiTree ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//��ʼ��
void InitQueue(SqQueue &Q);

//���
bool EnQueue(SqQueue &Q, ElemType x);

//����
bool DeQueue(SqQueue &Q, ElemType &x);

//�п�
bool isEmpty(SqQueue Q);
