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

char* GetFNameNoExten(char* fNameNoExten, char* fName) //ȥ���ļ�������չ��
{
	char* index = strrchr(fName, '.'); //strrchr�����ַ����Һ���
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

char* GetFNameExten(char* exten, char* fName) //��ȡ�ļ�������չ��
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

void InitArg(char* rFName, char* sFName)       //���󲢶������
{
	fprintf(stdout, "Usage: <input file path> [output file path]\n");
	char input[MAX_PATH*3] = {'\0'};
	scanf("%[^\n]", input); //ע��scanf()���÷�,�����������

	char* r = rFName;
	char* s = sFName;
	char* in = input;

	while((*in != ' ') && (*in != '\0')) //��ȡ��һ������
	{
		*r++ = *in++;
	}
	*r = '\0';

	if('\0' == *in) //��һ�����������
	{
		GetFNameNoExten(sFName, rFName);
		strcat(sFName, ".dat");
	}
	else //��һ���������пո�
	{
		while(' ' == *in) in++; //�����ո� !!!ע��������д�������� while(' ' == *in++);
		if('\0' == *in) //�ո�����: δ���õڶ�������
		{
			GetFNameNoExten(sFName, rFName);
			strcat(sFName, ".dat");
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

char* GetDir(char* dir, char* path)  //���ļ�·����ȡ�ļ�����Ŀ¼
{
	char* index = strrchr(path, '/'); //strrchr�����ַ����Һ���
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

int CreateMultDir(const char* sPath) //�����༶Ŀ¼
{
	char dirName[MAX_PATH];   
	strcpy(dirName, sPath); 
	
	int i,len = strlen(dirName);
	
	if(0 == len) return 1; //���ַ���,����Ҫ����

	if(dirName[len-1] != '/') strcat(dirName, "/");  //��ʽ��
    
	len = strlen(dirName);   
    
	for(i=1; i<len; i++)   
	{   
		if('/' == dirName[i])   
		{   
			dirName[i] = '\0';  //��ʱ�ض�   
			if(access(dirName, NULL) != 0)   //�����ڣ���Ҫ����
			{   
				if(mkdir(dirName) == -1)   
				{    
					return 0; //����ʧ��   
				}   
			}   
			dirName[i] = '/'; //��ԭ  
		}   
	}   
    
	return 1; //�ɹ�   
}


#endif //_FUNC_H_