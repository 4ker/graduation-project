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

char* GetFNameNoExten(char* fNameNoExten, char* fName); //去除文件名的扩展名
char* GetFNameExten(char* exten, char* fName); //获取文件名的扩展名
void InitArg(char* rFName, char* sFName);       //请求并读入参数
char* GetDir(char* dir, char* path);  //由文件路径获取文件所在目录
int CreateMultDir(const char* sPath); //创建多级目录

int main(int argc,char *argv[])
{
	setvbuf(stdout, (char *)NULL, _IOLBF, 0); //行缓冲

	char imgReadFName[MAX_PATH] = {'\0'}; //main参数1: 输入文件路径
	char imgSaveFName[MAX_PATH] = {'\0'}; //main参数2: 输出文件路径
	char dirTmp[MAX_PATH] = {'\0'}; //用于目录确认

	switch(argc)
	{
	case 1: //直接运行
		InitArg(imgReadFName, imgSaveFName);
		break;
	case 2: //命令行调用,一个参数,保存文件名默认为*.dat
		strcpy(imgReadFName, argv[1]); 
		GetFNameNoExten(imgSaveFName, imgReadFName);
		strcat(imgSaveFName, ".dat");
		break;
	case 3: //命令行调用,两个参数
		strcpy(imgReadFName, argv[1]);
		strcpy(imgSaveFName, argv[2]);
		break;
	default: //错误
		fprintf(stderr, "Arguments Error!");
		return 0;
	}

	FILE* readFile = fopen(imgReadFName, "rb"); // 检查输入文件是否存在
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