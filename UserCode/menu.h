#ifndef __MENU_H__
#define __MENU_H__

typedef void *(*actFunc_t)(void *);
typedef void *(*updataFunc_t)(void *);
typedef unsigned short ID_t;

typedef struct
{
    actFunc_t Func;
    void *Arg;
}actFuncAndArg_t;

typedef __menu menu_t;
struct __menu
{
  /*����˵�ʱ�����õĺ�����*/
  actFuncAndArg_t EnterActList;
  /*�˳��˵�ʱ�����õĺ�����*/
  actFuncAndArg_t BackActList;
  /*updata�������������ǽ����иò�
    ����Ŀ�µ��Ӳ˵���ʾ����*/
  actFuncAndArg_t Updata;
  /*��ʹ��UCOSIIʱ�����ID��ʾ���øò˵��Ľ���*/
  ID_t IDNum;
  /*�˵���Ŀ������*/
  char *menuString;
  /*ָ�򸸲˵�*/
  menu_t *Parent;
  /*ָ���Ӳ˵�*/
  menu_t *subMenuList;
  /*�����û�����ʹ�õ�˽������ָ��*/
  void pri[0];
};

/*ͷָ�룬ָ��ǰ���ڲ˵���Ŀ*/
extern menu_t *head;

#define Menu_Enter()\
do{\
  head = head->subMenuList;\
  while(head->EnterActList){\
      head->EnterActList->Func(head->EnterActList->Arg);\
  }\
  if (head->Updata)\
      head->Updata->Func( head->updata->Arg);\
}while(0)

#define Menu_Back()\
do{\
  head = head->Parent;\
  while(head->BackActList){\
      head->BackActList->Func(head->BackActList->Arg);\
  }\
  if (head->Updata)\
      head = head->Updata->Func(head->Updata->Arg);\
}while(0)
#endif