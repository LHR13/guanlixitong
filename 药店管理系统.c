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
		printf("�Ƿ����ҩƷ��Y/N����");
		rewind(stdin);
		scanf("%c",&choice);
		if(choice=='N')
		{
			break;
		}
		printf("����ҩƷ��ţ�");
		scanf("%d",&p1->bianhao); 
		printf("����ҩƷ���ƣ�");
		scanf("%s",&p1->mingzi);
		printf("����ҩƷ���ۣ�");
		scanf("%f",&p1->danjia);
		printf("����ҩƷ��棺");
		scanf("%d",&p1->kucun);
		printf("����ҩƷ�������ͣ�");
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
			printf("ҩƷ��ţ�%d��ҩƷ���ƣ�%s�����ۣ�%.2f����棺%d���������ͣ�%s\n",p->bianhao,p->mingzi,p->danjia,p->kucun,p->chufangleixing);
			p=p->next;
		}
	}
}

void shuru(struct yaopin *head)
{
	struct yaopin *yao;
	yao=head;
	FILE *fp;
	fp=fopen("ҩƷ��Ϣ.txt","wt");
	if((fp=fopen("ҩƷ��Ϣ.txt","wt"))==NULL)
	{
		printf("�޷����ļ�");
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
	f1=fopen("ҩƷ��Ϣ.txt","r");
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
	printf("��������Ҫɾ����ҩƷ��ţ�");
	scanf("%d",&j); 
	for(t=h;t!=NULL;t=t->next)
	{
		if(t->next->bianhao==j)
		{
			printf("ҩƷ��Ϣ���£�\nҩƷ��ţ�%d��ҩƷ���ƣ�%s�����ۣ�%.2f����棺%d���������ͣ�%s\n",t->next->bianhao,t->next->mingzi,t->next->danjia ,t->next->kucun,t->next->chufangleixing);
			flag=1;
			while(1)
			{
				printf("ȷ��ɾ����ҩƷ�𣿣�Y/N����");
				rewind(stdin);
				scanf("%c",&choice);
				if(choice=='N')
				{
					printf("ɾ��ʧ�ܣ�\n"); 
					break;
				}
				else
				{
					t->next=t->next->next;
					printf("ɾ���ɹ���\n");
					break; 
				}
			} 
			
			break;
		}
		//break; 
	}
	if(flag==0)
	{
		printf("δ���ҵ�ҩƷ��Ϣ��"); 
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
	printf("������ҩƷ��ţ�");
	scanf("%d",&j); 
	for(t=h;t!=NULL;t=t->next)
	{
		if(t->bianhao ==j)
		{
			printf("ҩƷ��Ϣ���£�\n ҩƷ��ţ�%d��ҩƷ���ƣ�%s�����ۣ�%.2f����棺%d���������ͣ�%s\n",t->bianhao,t->mingzi,t->danjia ,t->kucun,t->chufangleixing);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("δ���ҵ�ҩƷ��Ϣ��"); 
	}
}

void xiugai()
{
	struct yaopin *h,*t,*p;
	h=shuchu();
	int j,flag=0;
	char choice;
	printf("������ҩƷ��ţ�");
	scanf("%d",&j); 
	for(t=h;t!=NULL;t=t->next)
	{
		if(t->bianhao ==j)
		{
			printf("ҩƷ��Ϣ���£�\n ҩƷ��ţ�%d��ҩƷ���ƣ�%s�����ۣ�%.2f����棺%d���������ͣ�%s\n",t->bianhao,t->mingzi,t->danjia ,t->kucun,t->chufangleixing);
			flag=1;
			while(1)
			{
				printf("ȷ���޸�ҩƷ��Ϣ�𣿣�Y/N����");
				rewind(stdin);
				scanf("%c",&choice);
				if(choice=='N')
				{
					break;
				}
				else
				{
					printf("����������ҩƷ����");
					scanf("%s",t->mingzi);
					printf("���������뵥�ۣ�") ;
					scanf("%f",&t->danjia );
					printf("�����������棺");
					scanf("%d",&t->kucun );
					printf("���������봦�����ͣ�");
					scanf("%s",t->chufangleixing);
					printf("�޸�������£�\n");
					printf("ҩƷ��ţ�%d��ҩƷ���ƣ�%s�����ۣ�%.2f����棺%d���������ͣ�%s\n",t->bianhao,t->mingzi,t->danjia ,t->kucun,t->chufangleixing);
				}
			}
			break;
		}
	}
	if(flag==0)
	{
		printf("δ���ҵ�ҩƷ��Ϣ��"); 
	}
	p=h->next ;
	shuru(p);
}


void tongji()
{
	struct yaopin *h,*t;
	h=shuchu();
	char n[10]={"����"};
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
	printf("ͳ�ƽ����\n");
	printf("������ҩ��%d�֣��Ǵ�����ҩ��%d�֡�\n",i,j);
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
	printf("��ҩƷ��潫ҩƷ�����������£�\n");
	printf("%10s%10s%10s%10s%10s\n","ҩƷ���","ҩƷ����","ҩƷ����","ҩƷ���","��������");
	for(t=h->next;t!=NULL;t=t->next)
	{
		printf("%10d%10s%10.2f%10d%10s\n",t->bianhao,t->mingzi,t->danjia,t->kucun,t->chufangleixing);
	}
	
} 

void baobiao()
{
	struct yaopin *h,*t;
	h=shuchu();
	printf("��ҩƷͳ�ƺ����ɱ�������:\n"); 
	printf("%15s%15s%15s%15s%15s\n","ҩƷ���","ҩƷ����","ҩƷ����","ҩƷ���","��������");
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
			printf("���һ��ҩƷ���Ϊ��%d\n",p->bianhao);
			printf("ȷ�������ҩƷ�𣿣�Y/N��");
			scanf("%c",&n);
			if(n=='Y')
			{
				printf("����ҩƷ��ţ�");
		        scanf("%d",&p->bianhao); 
		        printf("����ҩƷ���ƣ�");
		        scanf("%s",&p->mingzi);
		        printf("����ҩƷ���ۣ�");
		        scanf("%f",&p->danjia);
		        printf("����ҩƷ��棺");
		        scanf("%d",&p->kucun);
		        printf("����ҩƷ�������ͣ�");
		        scanf("%s",&p->chufangleixing);
	            FILE *fp;
	            fp=fopen("ҩƷ��Ϣ.txt","a");
	            if((fp=fopen("ҩƷ��Ϣ.txt","a"))==NULL)
	            {
	            	printf("�޷����ļ�");
		            getch();
		            exit(0);
				}
				fprintf(fp,"%d %s %.2f %d %s\n",p->bianhao,p->mingzi,p->danjia,p->kucun,p->chufangleixing );
				fclose(fp);
		        break;
			} 
		}
	}
	printf("��ӳɹ���\n"); 
}

int caidan() 
{
	char n;
	do
	{
		system("CLS");
		printf("***********��ӭ����ҩ�����ϵͳ**************\n");
		printf("1 �鿴ϵͳ��ҩƷ��Ϣ\n") ;
		printf("2 ɾ��ָ��ҩƷ��Ϣ\n");
		printf("3 ��ѯָ��ҩƷ��Ϣ\n");
		printf("4 �޸�ָ��ҩƷ��Ϣ\n");
		printf("5 ���ҩƷ\n");
		printf("6 ҩƷ�������\n");
		printf("7 ��ӡ����\n");
		printf("8 ��ʼ��ϵͳ\n");
		printf("9 �˳�\n"); 
		printf("*********************************************\n");
		printf("��ѡ��1~9��");
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
				printf("ϵͳ��ҩƷ��Ϣ���£�\n");
				x=shuchu();
				y=x->next;
				output(y);
				int a;
				printf("��1�ص��ײ˵�\n");
				a=getch();
				break; 
			case 2:
				system("CLS");
				shanchu();
				int b;
				printf("��2�ص��ײ˵�\n");
				b=getch();
				break;
			case 3:
				system("CLS");
				chaxun();
				int c;
				printf("��3�ص��ײ˵�\n");
				c=getch();
				break; 
			case 4:
				system("CLS");
				xiugai();
				int d;
				printf("��4�ص��ײ˵�\n");
				d=getch();
				break; 
			case 5:
				system("CLS");
				tianjia();
				int e;
				printf("��5�ص��ײ˵�\n");
				e=getch();
				break; 
			case 6:
				system("CLS");
				tongji();
				int f;
				printf("��6�ص��ײ˵�\n");
				f=getch();
				break; 
			case 7:
				system("CLS");
				baobiao();
				int g;
				printf("��7�ص��ײ˵�\n");
				g=getch();
				break; 
			case 8:
				system("CLS");
				printf("��ʼ����ɾ�������Ѵ�ҩƷ��Ϣ��ȷ����ʼ����(Y/N)\n");
				char h,i;
				scanf("%c",&h);
				if(h=='Y')
				{
					printf("��ʼ���ɹ���\n");
					rhead=creatNode();
					output(rhead);
					shuru(rhead);
					break;
				}
				if(h=='N')
				{
					printf("��ʼ��ʧ�ܣ�");
					printf("��8�ص��ײ˵�\n") ;
					break;
				}
			case 9:
				system("CLS");
				printf("��лʹ�ã�");
				exit(-1);
				break; 
		}
	}	
}

