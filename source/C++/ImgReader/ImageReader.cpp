/****************************************************************
*																*
* Author: keith70												*
* Date modified: 2012.04.06										*
* Description: Read image form file using FreeImage library     *
*																*
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "bmpReader.h"
#include "jpgReader.h"
#include "func.h"

#ifndef MAX_PATH
#define MAX_PATH 255
#endif

char* GetFNameNoExten(char* fNameNoExten, char* fName); //ȥ���ļ�������չ��
char* GetFNameExten(char* exten, char* fName); //��ȡ�ļ�������չ��
void InitArg(char* rFName, char* sFName);       //���󲢶������
char* GetDir(char* dir, char* path);  //���ļ�·����ȡ�ļ�����Ŀ¼
int CreateMultDir(const char* sPath); //�����༶Ŀ¼

int main(int argc,char *argv[])
{
	setvbuf(stdout, (char *)NULL, _IOLBF, 0); //�л���

	char imgReadFName[MAX_PATH] = {'\0'}; //main����1: �����ļ�·��
	char imgSaveFName[MAX_PATH] = {'\0'}; //main����2: ����ļ�·��
	char dirTmp[MAX_PATH] = {'\0'}; //����Ŀ¼ȷ��

	switch(argc)
	{
	case 1: //ֱ������
		InitArg(imgReadFName, imgSaveFName);
		break;
	case 2: //�����е���,һ������,�����ļ���Ĭ��Ϊ*.dat
		strcpy(imgReadFName, argv[1]); 
		GetFNameNoExten(imgSaveFName, imgReadFName);
		strcat(imgSaveFName, ".dat");
		break;
	case 3: //�����е���,��������
		strcpy(imgReadFName, argv[1]);
		strcpy(imgSaveFName, argv[2]);
		break;
	default: //����
		fprintf(stderr, "Arguments Error!");
		return 0;
	}

	FILE* readFile = fopen(imgReadFName, "rb"); // ��������ļ��Ƿ����
	if(NULL == readFile)
	{
		fprintf(stderr, "Input file path not correct!");
		return 0;
	}
	else fclose(readFile);

	GetDir(dirTmp, imgSaveFName);
	if(0 == CreateMultDir(dirTmp))
	{
		fprintf(stderr, "Create save file directory failed!");
		return 0;
	}

	char bmp[4] = "bmp";
	char jpg[4] = "jpg";
	char jpeg[5] = "jpeg";
	char exten[5];
	GetFNameExten(exten, imgReadFName);

	try
	{
		if(0 == strcmp(exten, bmp))
		{
			BmpReader bReader(imgReadFName);
			bReader.SaveData(imgSaveFName);
		}
		else if(0 == strcmp(exten, jpg) || 0 == strcmp(exten, jpeg))
		{
			JpgReader jReader(imgReadFName);
			jReader.SaveData(imgSaveFName);
		}
		else
		{
			fprintf(stderr, "Image file format not support!");
			return 0;
		}
	}
	catch(const char* pszError)
	{
		fprintf(stderr, "Error!%s", pszError);
		return 0;
	}

	return 0;
}