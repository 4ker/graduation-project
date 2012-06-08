/********************************************************************
*																	*
* Author: keith70													*
* Date modified: 2012.04.06											*
* Description: Define some functions for ImageCombiner            	*
*																	*
********************************************************************/

#ifndef _FUNC_H_
#define _FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <io.h>

#ifndef MAX_PATH
#define MAX_PATH 255
#endif

typedef struct
{
	unsigned width;
	unsigned height;
}imgSize;

typedef struct
{
	char mark[4];
	unsigned ID;
	unsigned xLen;
	unsigned yLen;
	unsigned xStart;
	unsigned yStart;
	unsigned top;
	unsigned bottom;
	unsigned left;
	unsigned right;
} partHead;

char* GetDir(char* dir, char* path)  //从文件路径获取所在目录
{
	char* index = strrchr(path, '\\'); //strrchr逆向字符查找函数
	char* src = path;
	char* des = dir;
	
	if(index != NULL)
	{
		while(src != index)
		{
			*des++ = *src++;
		}
		*des++ = '\\';
	}
	
	*des = '\0';
	return dir;
}

void InitArg(char* path, char* dir)  //请求并读入参数
{
	fprintf(stderr, "Usage: <input file path> [output file path]\n");
	char input[MAX_PATH*3] = {'\0'};
	scanf("%[^\n]", input); //注意scanf()的用法,类似正则过滤

	char* r = path;
	char* s = dir;
	char* in = input;

	while((*in != ' ') && (*in != '\0')) //读取第一个参数
	{
		*r++ = *in++;
	}
	*r = '\0';

	if('\0' == *in) //第一个参数后结束
	{
		GetDir(dir, path);
		strcat(dir, "combine\\out.dat");
	}
	else //第一个参数后还有空格
	{
		while(' ' == *in) in++; //跳过空格
		if('\0' == *in) //空格后结束: 未设置第二个参数
		{
			GetDir(dir, path);
			strcat(dir, "combine\\out.dat");
		}
		else //读取第二个参数
		{
			while((*in != ' ') && (*in != '\0'))
			{
				*s++ = *in++;
			}
			*s = '\0';
		}
	}
}

int CreateMultDir(const char* sPath) //创建多级目录
{
	char dirName[MAX_PATH];   
	strcpy(dirName, sPath); 
	
	int i,len = strlen(dirName);
	
	if(0 == len) return 1; //空字符串,不需要处理

	if(dirName[len-1] != '\\') strcat(dirName, "\\");  //格式化
    
	len = strlen(dirName);   
    
	for(i=1; i<len; i++)   
	{   
		if('\\' == dirName[i])   
		{   
			dirName[i] = '\0';  //暂时截断   
			if(access(dirName, NULL) != 0)   //不存在，需要创建
			{   
				if(mkdir(dirName) == -1)   
				{    
					return 0; //创建失败   
				}   
			}   
			dirName[i] = '\\'; //还原  
		}   
	}   
    
	return 1; //成功   
}

unsigned GetConfNumByStr(char* str)   //从配置文件中某一行字符串中获取数值
{
	char s[10] = {'\0'};
	char* des = s;
	char* src = strrchr(str, '=');
	if(NULL == src)
	{
		return 0;
	}
	src++;
	while(*src != '\n' && *src != '\0')
	{
		*des++ = *src++;
	}
	return atoi(s);
}

void GetConfPathByStr(char* path, char* str) //从配置文件中某一行字符串中获取路径
{
	char* des = path;
	char* src = strrchr(str, '=');
	if(src != NULL)
	{
		src++;
		while(*src != '\n' && *src != '\0')
		{
			*des++ = *src++;
		}
	}
	*des = '\0';
}

int FillBits(unsigned char*** bits, char* path, unsigned** size) //读取小块文件并将填充数据到内存
{
	FILE* file = fopen(path, "rb");
	if(NULL == file) return 0; //文件打开失败

	partHead* head;
	head = (partHead*)malloc(sizeof(partHead));
	fread(head, sizeof(partHead), 1, file);

	imgSize trueSize; //小块实际尺寸
	trueSize.width = head->xLen - head->left - head->right;
	trueSize.height = head->yLen - head->top - head->bottom;

	unsigned interval = head->left + head->right;  //去除冗余后每行在文件中的间距

	(*bits) = (unsigned char**)malloc(trueSize.height * sizeof(unsigned char*));
	(*size) = (unsigned*)malloc(2 * sizeof(unsigned));
	(*size)[0] = trueSize.width;
	(*size)[1] = trueSize.height;

	fseek(file, head->top * head->xLen + head->left, 1);
	for(unsigned i = 0; i < trueSize.height; i++)
	{
		(*bits)[i] = (unsigned char*)malloc(trueSize.width * sizeof(unsigned char));
		fread((*bits)[i], trueSize.width * sizeof(unsigned char), 1, file);
		fseek(file, interval, 1); //从当前位置开始移动
	}

	free(head);
	fclose(file);
	return 1;
}


#endif //_FUNC_H_