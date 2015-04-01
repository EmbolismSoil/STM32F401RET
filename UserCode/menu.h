#ifndef __MENU_H__
#define __MENU_H__
#define MENU_BUFFER_SIZES 100

#include <stdio.h>


typedef void *(*actFunc_t)(void *);
typedef void *(*updataFunc_t)(void *);
typedef unsigned short ID_t;

typedef struct __actFuncAndArg actFuncAndArg_t;
struct __actFuncAndArg
{
    actFunc_t Func;
    void *Arg;
    actFuncAndArg_t *NextFunc;
};

typedef struct __menu
{
  /*����˵�ʱ�����õĺ�����*/
  actFuncAndArg_t *EnterActList;
  actFuncAndArg_t *BackActList;
  /*updata�������������ǽ����иò�
    ����Ŀ�µ��Ӳ˵���ʾ����*/
  actFuncAndArg_t *Updata;
  /*��ʹ��UCOSIIʱ�����ID��ʾ���øò˵��Ľ���*/
  ID_t IDNum;
  char *menuName;
  /*ָ�򸸲˵�*/
  struct __menu *Parent;
  /*ָ���Ӳ˵�*/
  struct __menu *subMenuList;
  /*��һ���ֵܲ˵�*/
  struct __menu *PreBrother;
  /*ָ����һ���ֵܲ˵�*/
  struct __menu *NextBrother;
  /*�����û�����ʹ�õ�˽������ָ��*/
  void *pri;
}menu_t;


/*Menuģ��ʵ�ֵĽӿ�*/
extern menu_t *Menu_CurMenu(void);
extern menu_t* Menu_Enter(void);
extern menu_t* Menu_Back(void);
extern menu_t* Menu_Next(void);
extern menu_t* Menu_Pre(void);
extern menu_t* Menu_AddBrotherAfter(menu_t *dstMenu, menu_t *srcMenu);
extern menu_t* Menu_AddBrotherBefore(menu_t *dstMenu, menu_t *srcMenu);
extern menu_t* Menu_HeadInit(menu_t* root);
extern menu_t* Menu_NewMenu(char *menuString, menu_t* Parent,
                     actFuncAndArg_t *EnteractList,
                      actFuncAndArg_t *BackActList,
                      actFuncAndArg_t *Updata);

/**********************************************************************************
                                   Demo
**********************************************************************************
void *updata(void *unused)
{
    printf("hello world");
    return NULL;
}

actFuncAndArg_t Updata =
{
   .Func = updata,
   .Arg = NULL,
};

int main(void)
{
   menu_t *menu =   Menu_NewMenu("Root",NULL,NULL,NULL,&Updata);
   menu_t *SubMenu = Menu_NewMenu("SubMenu",menu,NULL,NULL,&Updata);
   Menu_Enter();
}
***********************************************************************************
                                Demo End
**********************************************************************************/

#endif