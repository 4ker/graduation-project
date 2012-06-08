/********************************************************************
*																	*
* Author: keith70													*
* Date modified: 2012.04.06											*
* Description: Define some functions for ImageCutter            	*
*																	*
********************************************************************/
#ifndef _FUNC_H_
#define _FUNC_H_

#include <stdio.h>
#include <string.h>
#include <direct.h>
#include <io.h>

#ifndef MAX_PATH
#define MAX_PATH 255
#endif

//全局数据
char currentDir[MAX_PATH] = {'\0'};  //当前程序工作目录

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
} cutterHead;

char* GetDir(char* dir, char* path)  //从文件路径获取所在目录
{
	char* index = strrchr(path, '\\'); //strrchr逆向字符查找函数
	char* src = path;
	char* des = dir;
	if(NULL == strchr(path, ':'))
	{
		strcpy(des, currentDir);
		des += strlen(currentDir);
	}
	
	if(index != NULL)
	{
		while(src != index)
		{
			*des++ = *src++;
		}
		*des++ = '\\';
	}
	
	*des = '\0';
	strcat(dir, "cut\\"); //源文件目录自动新建cut目录
	return dir;
}

void InitArg(char* path, char* dir)  //请求并读入参数
{
	fprintf(stdout, "Usage: <input file path> [output dir]\n");
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
	}
	else //第一个参数后还有空格
	{
		while(' ' == *in) in++; //跳过空格
		if('\0' == *in) //空格后结束: 未设置第二个参数
		{
			GetDir(dir, path);
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

int SaveBitsPart(char* fileName, unsigned char* srcBits,  //要保存的文件名,源字节流
				unsigned srcWidth, unsigned srcHeight, //总体尺寸
				unsigned width, unsigned height, //分块尺寸
				unsigned x, unsigned y, //起点坐标(坐上角为原点,x->width,y->height),注意这里只是索引
				int excPixel, int ID)   //冗余度(像素), 块序号
{
	cutterHead head; //文件头部信息
	strcpy(head.mark, "ImgC");
	head.ID = ID;
	head.xStart = (0 == x) ? 0 : (x*width - excPixel);  //起点坐标x(实际像素坐标)
	head.yStart = (0 == y) ? 0 : (y*height - excPixel); //起点坐标y(实际像素坐标)
	
	head.top = (0 == y) ? 0 : excPixel;
	head.bottom = ((y+1)*height < srcHeight) ? excPixel : 0;
	head.left = (0 == x) ? 0 : excPixel;
	head.right = ((x+1)*width < srcWidth) ? excPixel : 0;

	if(0 == head.right) head.xLen = srcWidth - x*width + head.left;
	else head.xLen = width + head.left + head.right;

	if(0 == head.bottom) head.yLen = srcHeight - y*height + head.top;
	else head.yLen = height + head.top + head.bottom;


	FILE* fout = fopen(fileName, "wb+");
	if(NULL == fout)
	{
		return 0;
	}

	//写入40字节的头部信息
	fwrite(&head, sizeof(cutterHead), 1, fout);

	unsigned startPos = head.yStart*srcWidth + head.xStart;  //流中的起始位置
	unsigned char* pos = srcBits;
	pos += startPos;
	for(unsigned i=0; i < head.yLen; i++)
	{
		fwrite(pos, sizeof(unsigned char), head.xLen, fout);
		pos += srcWidth;
		
	}

	fclose(fout);
	return 1;
}


#endif //_FUNC_H_