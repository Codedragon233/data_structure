/*
 * @Author: farron_cat
 * @Date: 2021-08-30 16:06:33
 * @LastEditTime: 2021-09-20 10:18:25
 * @LastEditors: farron_cat
 * @Description: ��̬������
 * @FilePath: \Briup\learn\data_structure\String\SString.cpp
 * ��Ȩ�鷨��Сè����
 */

#define MAXLEN 255
typedef struct 
{
    char ch[MAXLEN]; //0�±�λ������
    int length;
}SString;

//���Ӵ�
bool SubString(SString &Sub, SString S,int pos, int len)
{
    if(pos+len-1>S.length)
        return false;
    for(int i=pos; i<pos+len;i++)
        Sub.ch[i-pos+1] = S.ch[i];
    Sub.length = len;
    return true;
}

//���ıȽ�
int StrCompare(SString S,SString T)
{
    for(int i=1;i<=S.length&&i<=T.length;i++)
    {
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    return S.length-T.length;//����ͬʱ ���ĳ��ȴ�
}

//S�ж�λ�ִ�T ����ģʽƥ��
int Index(SString S,SString T)
{
    int i=1,n=S.length, m=T.length;
    SString sub;
    while(i<=n-m+1)
    {
        SubString(sub,S,i,m);
        if(StrCompare(sub,T)!=0) i++;
        else return i;
    }
    return 0;
}

//����ģʽƥ��
int Index(SString S,SString T)
{
    int k=1;//��������λ��
    int i=k,j=1;
    while (i<=S.length&&j<=T.length)        
    {
        if (S.ch[i]==T.ch[j])
        {
            //i j ����
            ++i;
            ++j;
        }
        else
        {
            //���ں���
            k++;
            //i j ��λ
            i=k;
            j=1;
        }
    }
    if (j>T.length)
        //j�������ȴ���ƥ��ɹ�
        return k;
    else
        return 0;
    
}

void get_next(SString T,int next[])
{
    int i=1, j=0;
    next[1]=0;
    while(i<T.length)
    {
        if(j==0||T.ch[i]==T.ch[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
        
    }
}

int Index_KMP(SString S,SString T,int next[])
{
    int i=1,j=1;
    while(i<=S.length&&j<=T.length)
    {
        if (j==0;S.ch[i]==T.ch[i])      
        {
            ++i;
            ++j;
        }
        else
        {
            j=next[j];
        }        
    }
    if(j>T.length)
        return i-T.length;
    else
        return 0;
}