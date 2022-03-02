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
 void clean();		//cls清屏
 int cout();		//查询数组空缺


int main()

{
	bk bookList[10];
	int cmd;
	
	printf("\n\n\n==========================欢迎来到图书信息管理系统=======================\n\n");

	while (1) {
		printf("		  	  请输入要进行的操作:\n\n");
			printf("1.添加书籍	2.删除书籍	3.修改书籍信息	4.查询书籍信息	5.退出系统\n");
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
		return;
	default:
		printf("		  	  您输入的数据有误，请重新输入！\n\n\n");
		break;

	}
	}
	

	//		匹配分支功能

	
	//printf("%d", cmd);

}

addBook(bk templist[])				//添加书籍 
{
	int n = cout(templist);
	printf("\n n为：%d\n", n);
	printf("请输入要添加书籍的名称：");
	scanf("%s", &templist[n].name);

	printf("\n\n请输入要添加书籍的作者：");
	scanf("%s", &templist[n].author);

	printf("\n\n请输入要添加书籍的价格：");
	scanf("%f", &templist[n].price);

	printf("\n\n《%s》的id为：%d", templist[n].name,n+1);
	
	printf("\n\n按任意键返回系统~~~\n\n\n");
	int a = getch();
	clean();
	return templist;
}

delBook(bk templist[])				//删除书籍 
{

}

modifyBook(bk templist[])			//修改书籍信息 
{

}

queryBook(bk templist[])			//查询书籍信息 
{
	int i;
	int n = cout(templist);
	printf("目前共有%d本书，请问您要查看第几本：", n+1);
	scanf("%d", &i);
	printf("\n\n-----------------------");
	printf("\n\n书id： %d", n+1);
	printf("\n\n书名： 《%s》", templist[i - 1].name);
	printf("\n\n作者： 《%s》", templist[i - 1].author);
	printf("\n\n价格： %.1f\n", templist[i - 1].price);
}

void clean()
{
	system("cls");
	printf("\n\n\n");
}

int cout(bk templist[])
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