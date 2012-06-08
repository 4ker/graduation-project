/********************************************************************
*																	*
* Author: keith70													*
* Date modified: 2012.04.06											*
* Description: Combine images(generated by "ImageCutter") together	*
*																	*
********************************************************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "func.h"

#ifndef MAX_PATH
#define MAX_PATH 255
#endif

char* GetDir(char* dir, char* path); //���ļ�·����ȡ����Ŀ¼
void InitArg(char* path, char* dir); //���󲢶������
int CreateMultDir(const char* sPath); //�����༶Ŀ¼
unsigned GetConfNumByStr(char* str);  //�������ļ���ĳһ���ַ����л�ȡ��ֵ
void GetConfPathByStr(char* path, char* str); //�������ļ���ĳһ���ַ����л�ȡ·��
int FillBits(unsigned char*** bits, char* path, unsigned** size);   //��ȡС���ļ�����������ݵ��ڴ�

int main(int argc, char *argv[])
{
	setvbuf(stdout, (char *)NULL, _IONBF, 0);  //���û���

	char cfgReadPath[MAX_PATH] = {'\0'};   //main����1: ���������ļ�·��
	char imgSavePath[MAX_PATH] = {'\0'};   //main����2: ���ͼ���ļ�·��
	FILE* saveFile;   //���ͼ���ļ�ָ��
	FILE* cfgFile;    //���������ļ�ָ��
	imgSize partSize;  //С���׼�ߴ�(����������)
	imgSize entireSize; //����ߴ�
	unsigned partExc;   //�����(����)
	unsigned partCount; //С����Ŀ
	char** partsPath;   //���С��·��
	unsigned char*** allBits; //���С������(����Ϊ��λ)
	unsigned** allSize; //���С��ʵ�ʳߴ� 

	switch(argc)
	{
	case 1: //ֱ������
		InitArg(cfgReadPath, imgSavePath);
		break;
	case 2: //�����е���,һ������,����·��Ĭ��Ϊ:����Ŀ¼\combine\out.dat
		strcpy(cfgReadPath, argv[1]); 
		GetDir(imgSavePath, cfgReadPath);
		strcat(imgSavePath, "combine/out.dat");
		break;
	case 3: //�����е���,��������
		strcpy(cfgReadPath, argv[1]);
		strcpy(imgSavePath, argv[2]);
		break;
	default: //����
		fprintf(stderr, "Arguments Error!");
		return 0;
	}

	//������config�ļ�
	char* index = strrchr(cfgReadPath, '.');
	if(strcmp(index, ".conf") != 0)
	{
		fprintf(stderr, "config file format not correct!");
		return 0;
	}
	cfgFile = fopen(cfgReadPath, "r");
	if(NULL == cfgFile)
	{
		fprintf(stderr, "Open config file failed!");
		return 0;
	}

	//��/��������ļ�
	char tmp[MAX_PATH] = {'\0'};
	GetDir(tmp, imgSavePath); 
	if(0 == CreateMultDir(tmp))
	{
		fprintf(stderr, "Create save file directory failed!");
		return 0;
	}
	saveFile = fopen(imgSavePath, "wb+");
	if(NULL == saveFile)
	{
		fprintf(stderr, "Create save file failed!");
		return 0;
	}

	//���������ļ�
	char *one_line;
	one_line = (char*)malloc((MAX_PATH*2)*sizeof(char));

	//��ȡ������Ϣ
	fgets(one_line, MAX_PATH*2, cfgFile); //��1��
	fgets(one_line, MAX_PATH*2, cfgFile); //��2��
	fgets(one_line, MAX_PATH*2, cfgFile); //��3��
	entireSize.width = GetConfNumByStr(one_line);
	fgets(one_line, MAX_PATH*2, cfgFile); //��4��
	entireSize.height = GetConfNumByStr(one_line);
	fgets(one_line, MAX_PATH*2, cfgFile); //��5��
	partSize.width = GetConfNumByStr(one_line);
	fgets(one_line, MAX_PATH*2, cfgFile); //��6��
	partSize.height = GetConfNumByStr(one_line);
	fgets(one_line, MAX_PATH*2, cfgFile); //��7��
	partExc = GetConfNumByStr(one_line);
	fgets(one_line, MAX_PATH*2, cfgFile); //��8��
	partCount = GetConfNumByStr(one_line);
	fgets(one_line, MAX_PATH*2, cfgFile); //��9��

	//��ȡ��������
	partsPath = (char**)malloc(partCount * sizeof(char*));
	allBits = (unsigned char***)malloc(partCount * sizeof(unsigned char**));
	allSize = (unsigned**)malloc(partCount * sizeof(unsigned*));
	for(unsigned i=0; i < partCount; i++)
	{
		//�������
		//fflush(stdout);
		fprintf(stdout, "%d%%\n", (int)(i/(partCount-1.0)*50));

		partsPath[i] = (char*)malloc((MAX_PATH*2) * sizeof(char));
		fgets(one_line, MAX_PATH*2, cfgFile);
		GetConfPathByStr(partsPath[i], one_line);
		if(0 == FillBits(&allBits[i], partsPath[i], &allSize[i])) //��ȡС���ļ�����������䵽allBits
		{
			fprintf(stderr, "Read file \"%s\" failed!", partsPath[i]);
			return 0;
		}
	}

	//���ϸ������ݲ�����
	fwrite("ImgA", sizeof(char), 4, saveFile);  
	fwrite(&entireSize, sizeof(imgSize), 1, saveFile);
	
	unsigned xNum = (entireSize.width + partSize.width/2) / partSize.width;  //����С����Ŀ
	unsigned yNum = (entireSize.height + partSize.height/2) / partSize.height; //����С����Ŀ


	for(unsigned m=0; m < yNum; m++)
	{
		//�������
		//fflush(stdout);
		fprintf(stdout, "%d%%\n", (int)(m/(yNum-1.0)*50) + 50);

		for(unsigned n=0; n < allSize[m*xNum][1]; n++)
		{	
			for(unsigned k=0; k < xNum; k++)
			{		
				fwrite(allBits[m*xNum + k][n], allSize[m*xNum + k][0], 1, saveFile);
			}
		}
	}

	//���
	//fflush(stdout);
	fprintf(stdout, "100%% Done!\n");

	fclose(cfgFile);
	fclose(saveFile);
	return 0;
}