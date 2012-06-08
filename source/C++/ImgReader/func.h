/****************************************************************
*																*
* Author: keith70												*
* Date modified: 2012.04.06										*
* Description: define some functions for ImageReader            *
*																*
****************************************************************/
#ifndef _FUNC_H_
#define _FUNC_H_

#include <stdio.h>
#include <string.h>
#include <direct.h>
#include <io.h>

#ifndef MAX_PATH
#define MAX_PATH 255
#endif

char* GetFNameNoExten(char* fNameNoExten, char* fName) //去除文件名的扩展名
{
	char* index = strrchr(fName, '.'); //strrchr逆向字符查找函数
	char* src = fName;
	char* des = fNameNoExten;

	while(*src != '\0')
	{
		if(index != NULL && index == src) break;
		*des++ = *src++;
	}
	*des = '\0';
	return fNameNoExten;
}

char* GetFNameExten(char* exten, char* fName) //获取文件名的扩展名
{
	char* index = strrchr(fName, '.');
	char* p = exten;
	if(NULL == index)
	{
		*p = '\0';
		return exten;
	}

	index++;
	while(*index != '\0')
	{
		if('/' == *index) break;
		*p++ = *index++;
	}
	*p = '\0';
	return exten;
}

void InitArg(char* rFName, char* sFName)       //请求并读入参数
{
	fprintf(stdout, "Usage: <input file path> [output file path]\n");
	char input[MAX_PATH*3] = {'\0'};
	scanf("%[^\n]", input); //注意scanf()的用法,类似正则过滤

	char* r = rFName;
	char* s = sFName;
	char* in = input;

	while((*in != ' ') && (*in != '\0')) //读取第一个参数
	{
		*r++ = *in++;
	}
	*r = '\0';

	if('\0' == *in) //第一个参数后结束
	{
		GetFNameNoExten(sFName, rFName);
		strcat(sFName, ".dat");
	}
	else //第一个参数后还有空格
	{
		while(' ' == *in) in++; //跳过空格 !!!注意与这种写法的区别 while(' ' == *in++);
		if('\0' == *in) //空格后结束: 未设置第二个参数
		{
			GetFNameNoExten(sFName, rFName);
			strcat(sFName, ".dat");
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

char* GetDir(char* dir, char* path)  //由文件路径获取文件所在目录
{
	char* index = strrchr(path, '/'); //strrchr逆向字符查找函数
	char* src = path;
	char* des = dir;
	
	if(index != NULL)
	{
		while(src != index)
		{
			*des++ = *src++;
		}
	}

	*des = '\0';
	return dir;
}

int CreateMultDir(const char* sPath) //创建多级目录
{
	char dirName[MAX_PATH];   
	strcpy(dirName, sPath); 
	
	int i,len = strlen(dirName);
	
	if(0 == len) return 1; //空字符串,不需要处理

	if(dirName[len-1] != '/') strcat(dirName, "/");  //格式化
    
	len = strlen(dirName);   
    
	for(i=1; i<len; i++)   
	{   
		if('/' == dirName[i])   
		{   
			dirName[i] = '\0';  //暂时截断   
			if(access(dirName, NULL) != 0)   //不存在，需要创建
			{   
				if(mkdir(dirName) == -1)   
				{    
					return 0; //创建失败   
				}   
			}   
			dirName[i] = '/'; //还原  
		}   
	}   
    
	return 1; //成功   
}


#endif //_FUNC_H_