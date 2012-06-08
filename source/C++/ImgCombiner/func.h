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

char* GetDir(char* dir, char* path)  //���ļ�·����ȡ����Ŀ¼
{
	char* index = strrchr(path, '\\'); //strrchr�����ַ����Һ���
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

void InitArg(char* path, char* dir)  //���󲢶������
{
	fprintf(stderr, "Usage: <input file path> [output file path]\n");
	char input[MAX_PATH*3] = {'\0'};
	scanf("%[^\n]", input); //ע��scanf()���÷�,�����������

	char* r = path;
	char* s = dir;
	char* in = input;

	while((*in != ' ') && (*in != '\0')) //��ȡ��һ������
	{
		*r++ = *in++;
	}
	*r = '\0';

	if('\0' == *in) //��һ�����������
	{
		GetDir(dir, path);
		strcat(dir, "combine\\out.dat");
	}
	else //��һ���������пո�
	{
		while(' ' == *in) in++; //�����ո�
		if('\0' == *in) //�ո�����: δ���õڶ�������
		{
			GetDir(dir, path);
			strcat(dir, "combine\\out.dat");
		}
		else //��ȡ�ڶ�������
		{
			while((*in != ' ') && (*in != '\0'))
			{
				*s++ = *in++;
			}
			*s = '\0';
		}
	}
}

int CreateMultDir(const char* sPath) //�����༶Ŀ¼
{
	char dirName[MAX_PATH];   
	strcpy(dirName, sPath); 
	
	int i,len = strlen(dirName);
	
	if(0 == len) return 1; //���ַ���,����Ҫ����

	if(dirName[len-1] != '\\') strcat(dirName, "\\");  //��ʽ��
    
	len = strlen(dirName);   
    
	for(i=1; i<len; i++)   
	{   
		if('\\' == dirName[i])   
		{   
			dirName[i] = '\0';  //��ʱ�ض�   
			if(access(dirName, NULL) != 0)   //�����ڣ���Ҫ����
			{   
				if(mkdir(dirName) == -1)   
				{    
					return 0; //����ʧ��   
				}   
			}   
			dirName[i] = '\\'; //��ԭ  
		}   
	}   
    
	return 1; //�ɹ�   
}

unsigned GetConfNumByStr(char* str)   //�������ļ���ĳһ���ַ����л�ȡ��ֵ
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

void GetConfPathByStr(char* path, char* str) //�������ļ���ĳһ���ַ����л�ȡ·��
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

int FillBits(unsigned char*** bits, char* path, unsigned** size) //��ȡС���ļ�����������ݵ��ڴ�
{
	FILE* file = fopen(path, "rb");
	if(NULL == file) return 0; //�ļ���ʧ��

	partHead* head;
	head = (partHead*)malloc(sizeof(partHead));
	fread(head, sizeof(partHead), 1, file);

	imgSize trueSize; //С��ʵ�ʳߴ�
	trueSize.width = head->xLen - head->left - head->right;
	trueSize.height = head->yLen - head->top - head->bottom;

	unsigned interval = head->left + head->right;  //ȥ�������ÿ�����ļ��еļ��

	(*bits) = (unsigned char**)malloc(trueSize.height * sizeof(unsigned char*));
	(*size) = (unsigned*)malloc(2 * sizeof(unsigned));
	(*size)[0] = trueSize.width;
	(*size)[1] = trueSize.height;

	fseek(file, head->top * head->xLen + head->left, 1);
	for(unsigned i = 0; i < trueSize.height; i++)
	{
		(*bits)[i] = (unsigned char*)malloc(trueSize.width * sizeof(unsigned char));
		fread((*bits)[i], trueSize.width * sizeof(unsigned char), 1, file);
		fseek(file, interval, 1); //�ӵ�ǰλ�ÿ�ʼ�ƶ�
	}

	free(head);
	fclose(file);
	return 1;
}


#endif //_FUNC_H_