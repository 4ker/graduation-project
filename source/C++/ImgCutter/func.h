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

//ȫ������
char currentDir[MAX_PATH] = {'\0'};  //��ǰ������Ŀ¼

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

char* GetDir(char* dir, char* path)  //���ļ�·����ȡ����Ŀ¼
{
	char* index = strrchr(path, '\\'); //strrchr�����ַ����Һ���
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
	strcat(dir, "cut\\"); //Դ�ļ�Ŀ¼�Զ��½�cutĿ¼
	return dir;
}

void InitArg(char* path, char* dir)  //���󲢶������
{
	fprintf(stdout, "Usage: <input file path> [output dir]\n");
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
	}
	else //��һ���������пո�
	{
		while(' ' == *in) in++; //�����ո�
		if('\0' == *in) //�ո�����: δ���õڶ�������
		{
			GetDir(dir, path);
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

int SaveBitsPart(char* fileName, unsigned char* srcBits,  //Ҫ������ļ���,Դ�ֽ���
				unsigned srcWidth, unsigned srcHeight, //����ߴ�
				unsigned width, unsigned height, //�ֿ�ߴ�
				unsigned x, unsigned y, //�������(���Ͻ�Ϊԭ��,x->width,y->height),ע������ֻ������
				int excPixel, int ID)   //�����(����), �����
{
	cutterHead head; //�ļ�ͷ����Ϣ
	strcpy(head.mark, "ImgC");
	head.ID = ID;
	head.xStart = (0 == x) ? 0 : (x*width - excPixel);  //�������x(ʵ����������)
	head.yStart = (0 == y) ? 0 : (y*height - excPixel); //�������y(ʵ����������)
	
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

	//д��40�ֽڵ�ͷ����Ϣ
	fwrite(&head, sizeof(cutterHead), 1, fout);

	unsigned startPos = head.yStart*srcWidth + head.xStart;  //���е���ʼλ��
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