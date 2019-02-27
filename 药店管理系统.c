#include<string.h>
#include<conio.h>
#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct yaopin)
typedef struct yaopin
{
	int bianhao;
	char mingzi[100];
	float danjia;
	int kucun;
	char chufangleixing[100];
	struct yaopin *next;
}yaopin;

struct yaopin *creatNode()
{
	struct yaopin *head;
	struct yaopin *p1;
	struct yaopin *p2;
	head=NULL;
	p1=(struct yaopin *)malloc(LEN);
	p2=(struct yaopin *)malloc(LEN);
	int n=0;
	char choice;
	while(1)
	{
		printf("是否添加药品（Y/N）：");
		rewind(stdin);
		scanf("%c",&choice);
		if(choice=='N')
		{
			break;
		}
		printf("输入药品编号：");
		scanf("%d",&p1->bianhao); 
		printf("输入药品名称：");
		scanf("%s",&p1->mingzi);
		printf("输入药品单价：");
		scanf("%f",&p1->danjia);
		printf("输入药品库存：");
		scanf("%d",&p1->kucun);
		printf("输入药品处方类型：");
		scanf("%s",&p1->chufangleixing);
		n++;
		if(n==1)
		{
			head=p1;
		}
		else
		{
			p2->next=p1;
		}
		p2=p1;
		p1=(struct yaopin *)malloc(LEN);	
	}
	p2->next=NULL;
	return(head);
}
void output(struct yaopin *head)
{
	struct yaopin *p;
	if(head!=NULL)
	{
		p=head;
		while(p!=NULL)
		{
			printf("药品编号：%d，药品名称：%s，单价：%.2f，库存：%d，处方类型：%s\n",p->bianhao,p->mingzi,p->danjia,p->kucun,p->chufangleixing);
			p=p->next;
		}
	}
}

void shuru(struct yaopin *head)
{
	struct yaopin *yao;
	yao=head;
	FILE *fp;
	fp=fopen("药品信息.txt","wt");
	if((fp=fopen("药品信息.txt","wt"))==NULL)
	{
		printf("无法打开文件");
		getch();
		exit(0);
	}
	for(yao=head;yao!=NULL;yao=yao->next)
	{
		fprintf(fp,"%d %s %.2f %d %s\n",yao->bianhao,yao->mingzi,yao->danjia,yao->kucun,yao->chufangleixing );
	}
	fclose(fp);
}
struct yaopin *shuchu()
{
	struct yaopin *ahead,*r,*yao;
	FILE*f1;
	f1=fopen("药品信息.txt","r");
	ahead=(struct yaopin*)malloc(sizeof(struct yaopin));
	ahead->next=NULL;
	r=ahead;
	while(!feof(f1))
	{
		yao=(struct yaopin*)malloc(sizeof(struct yaopin));
		fscanf(f1,"%d %s %f %d %s\n",&yao->bianhao,yao->mingzi,&yao->danjia,&yao->kucun,yao->chufangleixing);
		r->next =yao;
		r=yao;
	}
	r->next =NULL;
	fclose(f1);
	return ahead;
}

void shanchu()
{
	struct yaopin *h,*t,*p;
	h=shuchu();
	int j,flag=0;
	char choice;
	printf("请输入需要删除的药品编号：");
	scanf("%d",&j); 
	for(t=h;t!=NULL;t=t->next)
	{
		if(t->next->bianhao==j)
		{
			printf("药品信息如下：\n药品编号：%d，药品名称：%s，单价：%.2f，库存：%d，处方类型：%s\n",t->next->bianhao,t->next->mingzi,t->next->danjia ,t->next->kucun,t->next->chufangleixing);
			flag=1;
			while(1)
			{
				printf("确定删除此药品吗？（Y/N）：");
				rewind(stdin);
				scanf("%c",&choice);
				if(choice=='N')
				{
					printf("删除失败！\n"); 
					break;
				}
				else
				{
					t->next=t->next->next;
					printf("删除成功！\n");
					break; 
				}
			} 
			
			break;
		}
		//break; 
	}
	if(flag==0)
	{
		printf("未查找到药品信息！"); 
	}
	p=h->next;
	shuru(p);
	output(p);
}



void chaxun()
{
	struct yaopin *h,*t;
	h=shuchu();
	int j,flag=0;
	printf("请输入药品编号：");
	scanf("%d",&j); 
	for(t=h;t!=NULL;t=t->next)
	{
		if(t->bianhao ==j)
		{
			printf("药品信息如下：\n 药品编号：%d，药品名称：%s，单价：%.2f，库存：%d，处方类型：%s\n",t->bianhao,t->mingzi,t->danjia ,t->kucun,t->chufangleixing);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("未查找到药品信息！"); 
	}
}

void xiugai()
{
	struct yaopin *h,*t,*p;
	h=shuchu();
	int j,flag=0;
	char choice;
	printf("请输入药品编号：");
	scanf("%d",&j); 
	for(t=h;t!=NULL;t=t->next)
	{
		if(t->bianhao ==j)
		{
			printf("药品信息如下：\n 药品编号：%d，药品名称：%s，单价：%.2f，库存：%d，处方类型：%s\n",t->bianhao,t->mingzi,t->danjia ,t->kucun,t->chufangleixing);
			flag=1;
			while(1)
			{
				printf("确定修改药品信息吗？（Y/N）：");
				rewind(stdin);
				scanf("%c",&choice);
				if(choice=='N')
				{
					break;
				}
				else
				{
					printf("请重新输入药品名：");
					scanf("%s",t->mingzi);
					printf("请重新输入单价：") ;
					scanf("%f",&t->danjia );
					printf("请重新输入库存：");
					scanf("%d",&t->kucun );
					printf("请重新输入处方类型：");
					scanf("%s",t->chufangleixing);
					printf("修改情况如下：\n");
					printf("药品编号：%d，药品名称：%s，单价：%.2f，库存：%d，处方类型：%s\n",t->bianhao,t->mingzi,t->danjia ,t->kucun,t->chufangleixing);
				}
			}
			break;
		}
	}
	if(flag==0)
	{
		printf("未查找到药品信息！"); 
	}
	p=h->next ;
	shuru(p);
}


void tongji()
{
	struct yaopin *h,*t;
	h=shuchu();
	char n[10]={"处方"};
	int i=0,j=0,m;
	for(t=h->next ;t!=NULL;t=t->next)
	{
		m=strcmp(t->chufangleixing,n);
		if(m==0)
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	printf("统计结果：\n");
	printf("处方类药共%d种，非处方类药共%d种。\n",i,j);
}

void paixu()
{
	struct yaopin *p,*q,*h,*t;
	h=shuchu();
	int tbianhao;
	char tmingzi[50];
	float tdanjia;
	int tkucun;
	char tchufangleixing[50];
	for(p=h->next;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->kucun > q->kucun)
			{
				tbianhao=p->bianhao;
			    p->bianhao=q->bianhao;
			    q->bianhao=tbianhao;
			    
				strcpy(tmingzi,p->mingzi);
			    strcpy(p->mingzi,q->mingzi);
			    strcpy(q->mingzi,tmingzi);
			
			    tdanjia=p->danjia;
			    p->danjia=q->danjia;
			    q->danjia=tdanjia;
			
			    tkucun=p->kucun;
			    p->kucun=q->kucun;
			    q->kucun=tkucun;
			
			    strcpy(tchufangleixing,p->chufangleixing);
			    strcpy(p->chufangleixing,q->chufangleixing);
			    strcpy(q->chufangleixing,tchufangleixing);
			}	
		}
	}
	printf("按药品库存将药品升序排列如下：\n");
	printf("%10s%10s%10s%10s%10s\n","药品编号","药品名字","药品单价","药品库存","处方类型");
	for(t=h->next;t!=NULL;t=t->next)
	{
		printf("%10d%10s%10.2f%10d%10s\n",t->bianhao,t->mingzi,t->danjia,t->kucun,t->chufangleixing);
	}
	
} 

void baobiao()
{
	struct yaopin *h,*t;
	h=shuchu();
	printf("对药品统计后生成报表如下:\n"); 
	printf("%15s%15s%15s%15s%15s\n","药品编号","药品名字","药品单价","药品库存","处方类型");
	for(t=h->next;t!=NULL;t=t->next)
	{
		printf("%15d%15s%15.2f%15d%15s\n",t->bianhao,t->mingzi,t->danjia,t->kucun,t->chufangleixing);
	}
}

void tianjia()
{
	struct yaopin *p,*h,*t;
	char n;
	h=shuchu();
	for(p=h;p!=NULL;p=p->next)
	{
		if(p->next==NULL)
		{
			printf("最后一项药品编号为：%d\n",p->bianhao);
			printf("确定添加新药品吗？（Y/N）");
			scanf("%c",&n);
			if(n=='Y')
			{
				printf("输入药品编号：");
		        scanf("%d",&p->bianhao); 
		        printf("输入药品名称：");
		        scanf("%s",&p->mingzi);
		        printf("输入药品单价：");
		        scanf("%f",&p->danjia);
		        printf("输入药品库存：");
		        scanf("%d",&p->kucun);
		        printf("输入药品处方类型：");
		        scanf("%s",&p->chufangleixing);
	            FILE *fp;
	            fp=fopen("药品信息.txt","a");
	            if((fp=fopen("药品信息.txt","a"))==NULL)
	            {
	            	printf("无法打开文件");
		            getch();
		            exit(0);
				}
				fprintf(fp,"%d %s %.2f %d %s\n",p->bianhao,p->mingzi,p->danjia,p->kucun,p->chufangleixing );
				fclose(fp);
		        break;
			} 
		}
	}
	printf("添加成功！\n"); 
}

int caidan() 
{
	char n;
	do
	{
		system("CLS");
		printf("***********欢迎进入药店管理系统**************\n");
		printf("1 查看系统内药品信息\n") ;
		printf("2 删除指定药品信息\n");
		printf("3 查询指定药品信息\n");
		printf("4 修改指定药品信息\n");
		printf("5 添加药品\n");
		printf("6 药品库存排序\n");
		printf("7 打印报表\n");
		printf("8 初始化系统\n");
		printf("9 退出\n"); 
		printf("*********************************************\n");
		printf("请选择1~9：");
		n=getch();
	}while(n<'0'||n>'9');
	return (n-48);
	
}

int main()
{
	struct yaopin *x,*y,*rhead;
	while(1)
	{
		switch(caidan())
		{
			case 1:
				
				system("CLS");
				printf("系统内药品信息如下：\n");
				x=shuchu();
				y=x->next;
				output(y);
				int a;
				printf("按1回到首菜单\n");
				a=getch();
				break; 
			case 2:
				system("CLS");
				shanchu();
				int b;
				printf("按2回到首菜单\n");
				b=getch();
				break;
			case 3:
				system("CLS");
				chaxun();
				int c;
				printf("按3回到首菜单\n");
				c=getch();
				break; 
			case 4:
				system("CLS");
				xiugai();
				int d;
				printf("按4回到首菜单\n");
				d=getch();
				break; 
			case 5:
				system("CLS");
				tianjia();
				int e;
				printf("按5回到首菜单\n");
				e=getch();
				break; 
			case 6:
				system("CLS");
				tongji();
				int f;
				printf("按6回到首菜单\n");
				f=getch();
				break; 
			case 7:
				system("CLS");
				baobiao();
				int g;
				printf("按7回到首菜单\n");
				g=getch();
				break; 
			case 8:
				system("CLS");
				printf("初始化会删除所有已存药品信息，确定初始化吗？(Y/N)\n");
				char h,i;
				scanf("%c",&h);
				if(h=='Y')
				{
					printf("初始化成功！\n");
					rhead=creatNode();
					output(rhead);
					shuru(rhead);
					break;
				}
				if(h=='N')
				{
					printf("初始化失败！");
					printf("按8回到首菜单\n") ;
					break;
				}
			case 9:
				system("CLS");
				printf("感谢使用！");
				exit(-1);
				break; 
		}
	}	
}

