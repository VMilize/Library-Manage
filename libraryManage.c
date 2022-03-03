#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//定义 书籍 结构体存储数据
typedef struct book
{
	int id;
	char name[20];
	char author[20];
	float price;
}bk;

static int num = 0;

 addBook(bk list[]);//添加书籍
 delBook();			//删除书籍
 modifyBook();		//修改书籍信息
 queryBook();		//查询书籍信息 
 allBook();			//总览所有书籍信息
 void clean();		//cls清屏
 int cout();		//查询数组空缺



int main()

{
	bk bookList[10];
	int cmd;
	
	printf("\n\n\n==========================欢迎来到图书信息管理系统=======================\n\n");

	while (1) {
		printf("		  	  请输入要进行的操作:\n\n");
			printf("1.添加书籍	2.删除书籍	3.修改书籍信息    	4.查询书籍信息    	5.所有图书	6.退出系统	\n");
			scanf("%d", &cmd);
			clean();

			

			switch (cmd)
	{
	case 1:  
		addBook(bookList);
		break;
	case 2:
		delBook(bookList);
		break;
	case 3:
		modifyBook(bookList);
		break;
	case 4:
		queryBook(bookList);
		break;
	case 5:
			allBook(bookList);
			break;
	case 6:
		return;
	default: 
	{
		printf("		  	  您输入的数据有误，请重新输入！\n\n\n");
		printf("\n\n按任意键返回系统~~~\n\n\n");
		int a = getch();
		clean();
	}
		
		break;

	}
	}
	

	//		匹配分支功能

	
	//printf("%d", cmd);

}

addBook(bk templist[])				//添加书籍 
{
	int i;
	/*
	printf("\nnum = %d\n", num);
	bk* p = templist;
	for (i = 0;i <= num;i++)
	{
		if (p->id < 0 || p->id>100)
		{
			n = i;
			break;
		}
		else
			n = num;
	}
	*/

	printf("请输入要添加书籍的名称：");
	scanf("%s", &templist[num].name);

	printf("\n\n请输入要添加书籍的作者：");
	scanf("%s", &templist[num].author);

	printf("\n\n请输入要添加书籍的价格：");
	scanf("%f", &templist[num].price);

	templist[num].id = num+1;

	printf("\n\n《%s》的id为：%d", templist[num].name,num+1);
	num++;
	printf("\n\n按任意键返回系统~~~\n\n\n");
	int a = getch();
	clean();
	return templist;
}

delBook(bk templist[])				//删除书籍 
{
	if (num == 0)
	{
		printf("当前图书馆里还没有书籍，请先添加一本书哦~");
		printf("\n\n按任意键返回系统~~~\n\n\n");
		int a = getch();
		clean();
		return;

	}
	int tempn, m, tempcmd, i;

	printf("图书列表及id如下：\n");
	for (i = 0;i <= num;i++)
	{
		if (templist[i].id >= 0 && templist[i].id < 100)
			printf("\n\n《%s》------%d", templist[i].name, templist[i].id + 1);
		else
			printf("\n");

		printf("\n");
		//templist[i].id > 0 && templist[i].id < 100 ? printf("\n\n《%s》------%d\n", templist[i].name, templist[i].id):printf("\n");
	}

	printf("\n请输入要删除书籍的id：");
	scanf("%d", &m);
	//templist[ m - 1].name = "该图书已下架";
	for (i = m - 1;i <= num;i++)
	{
		templist[i] = templist[i+1];
		templist[i].id--;
	}
	num--;
	/*
	for (i = m - 1;i < num;i++)
	{
		templist[i].id--;
	}
	*/
	printf("下架成功\n\n按任意键继续~");
	tempn = getch();
	clean();
}

modifyBook(bk templist[])			//修改书籍信息 
{
	if (num == 0)
	{
		printf("当前图书馆里还没有书籍，请先添加一本书哦~");
		printf("\n\n按任意键返回系统~~~\n\n\n");
		int a = getch();
		clean();
		return;
	}
	int tempn,tempm,tempcmd,i;
	
	int n = cout(templist);
	//printf("\n%d\n", n);
	printf("图书列表及id如下：\n");
	for (i = 0;i <= num;i++)
	{		
		if (templist[i].id >= 0 && templist[i].id < 100)
			printf("\n\n《%s》------%d", templist[i].name, templist[i].id);
		else
			printf("\n");

		printf("\n");
		//templist[i].id > 0 && templist[i].id < 100 ? printf("\n\n《%s》------%d\n", templist[i].name, templist[i].id):printf("\n");
	}
	printf("\n请输入要修改的书籍id：");
	scanf("%d", &tempm);
	clean();
	tempn=tempm-1;
	printf("\n请输入要修改书籍的哪项内容：");
	printf("\n1.书名		2.作者		3.价格		\n");
	scanf("%d", &tempcmd);
	clean();
	switch (tempcmd)
	{
	case 1 :
	{
		printf("\n请输入新的书名：");
		scanf("%s", &templist[tempn].name);
		
		printf("\n该图书名更新完成~\n\n\n按任意键继续---");
		int aa = getch();
		clean();
		break;
	}
	case 2:
	{
		printf("\n请输入新的作者：");
		scanf("%s", &templist[tempn].author);
		printf("\n该作者更新完成~\n\n\n按任意键继续---");
		int aa = getch();
		clean();
		break;
	}
	case 3:
	{
		printf("\n请输入新的价格：");
		scanf("%f", &templist[tempn].price);
		printf("\n该图书价格更新完成~\n\n\n按任意键继续---");
		int aa = getch();
		clean();
		break;
	}
	default:
		printf("请输入正确的指令~");
		break;
	}
	return templist;
}

queryBook(bk templist[])			//查询书籍信息 
{
	if (num == 0)
	{
		printf("当前图书馆里还没有书籍，请先添加一本书哦~");
		printf("\n\n按任意键返回系统~~~\n\n\n");
		int a = getch();
		clean();
		return;
	}
	int i;
	//int n = cout(templist);
	printf("目前共有%d本书，目录如下，请问您要查看第几本：", num);
	for (i = 0;i <= num;i++)
	{
		if (templist[i].id >= 0 && templist[i].id < 100)
			printf("\n\n《%s》------%d", templist[i].name, templist[i].id);
		else
			printf("\n");

		printf("\n");
		//templist[i].id > 0 && templist[i].id < 100 ? printf("\n\n《%s》------%d\n", templist[i].name, templist[i].id):printf("\n");
	}
	scanf("%d", &i);
	printf("\n\n-----------------------");
	printf("\n\n书id： %d", i);
	printf("\n\n书名： 《%s》", templist[i - 1].name);
	printf("\n\n作者： %s", templist[i - 1].author);
	printf("\n\n价格： %.2f\n", templist[i - 1].price);
	printf("\n按任意键继续~~");
	int aa = getch();
	clean();
}

allBook(bk templist[])
{
	if (num == 0)
	{
		printf("当前图书馆里还没有书籍，请先添加一本书哦~");
		printf("\n\n按任意键返回系统~~~\n\n\n");
		int a = getch();
		clean();
		return;
	}
	int i;
	for (i = 0;i < num;i++)
	{
		printf("---------------------");
		printf("\n\nid:%d\n",templist[i].id);
		printf("\n书名:《%s》\n",templist[i].name);
		printf("\n作者:%s\n",templist[i].author);
		printf("\n价格:%.2f\n",templist[i].price);
	}
	printf("---------------------\n");
	printf("按任意键继续~");
	int aa = getch();
	clean();
	clean();
}

void clean()
{
	system("cls");
	printf("\n\n\n");
}

int cout(bk templist[])		//遍历数组，查找空缺（针对bk结构体数组）
{
	int i, n;

	for (i = 0; i < 10; i++)
	{
		if (templist[i].id > 0 && templist[i].id < 100)
			i++;
		else
			return i;
			

	}
}
