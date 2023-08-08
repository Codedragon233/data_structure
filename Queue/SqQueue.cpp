/*
 * @Author: farron_cat
 * @Date: 2021-07-26 16:43:08
 * @LastEditTime: 2021-09-05 16:57:16
 * @LastEditors: farron_cat
 * @Description: ˳�����(ѭ������)
 * @FilePath: \Briup\learn\data_structure\Queue\SqQueue.cpp
 * ��Ȩ�鷨��Сè����
 */

#define MaxSize 10
typedef int ElemType;
//����
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//��ʼ��
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

//���
bool EnQueue(SqQueue &Q, ElemType x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)//��������
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;//ѭ����һ
    return true;
}

//����
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if (Q.front == Q.rear)//�ӿմ���
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;//ѭ����һ
    return true;
}

//�п�
bool isEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)//��β�غ���ӿ�
        return true;
    else
        return false;
}