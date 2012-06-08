/*************************************************
*                                                *
* Author: keith70                                *
* Date modified: 2012.04.01                      *
* Description: Defines BmpReader class           *
*                                                *
*************************************************/

#ifndef _BMPREADER_H_
#define _BMPREADER_H_

#include <cstdio>
#include <cmath>
#include <malloc.h>
#include "integer.h"


//bmp文件头
typedef struct tagBITMAPFILEHEADER
{
	DWORD bfSize;       //文件大小
	WORD  bfReserved1;  //保留字，不考虑
	WORD  bfReserved2;  //保留字，同上
	DWORD bfOffBits;    //实际位图数据的偏移字节数
} BITMAPFILEHEADER;

//bmp信息头
typedef struct tagBITMAPINFOHEADER
{
	DWORD  biSize;                 //该结构大小，字节为单位
	LONG   biWidth;                //图形宽度以象素为单位
	LONG   biHeight;               //图形高度以象素为单位
	WORD   biPlanes;               //目标设备的级别，必须为1
	WORD   biBitcount;             //颜色深度，每个象素所需要的位数
	DWORD  biCompression;          //位图的压缩类型
	DWORD  biSizeImage;            //位图的大小，以字节为单位
	LONG   biXPelsPermeter;        //位图水平分辨率，每米像素数
	LONG   biYPelsPermeter;        //位图垂直分辨率，每米像素数
	DWORD  biClrUsed;              //位图实际使用的颜色表中的颜色数
	DWORD  biClrImportant;         //位图显示过程中重要的颜色数
} BITMAPINFOHEADER;

//调色板
typedef struct tagRGBQUAD
{
    BYTE  B;           //蓝
    BYTE  G;           //绿
    BYTE  R;           //红
	BYTE  reserved;
}RGBQUAD;

#ifndef _COEFF_
#define _COEFF_
//RGB->灰度化系数
typedef struct
{
	float B;
	float G;
	float R;
}COEFF;
#endif

class BmpReader
{
public:
	BmpReader(CHAR* filename);
	~BmpReader();
	INT SaveData(CHAR* saveFileName); //保存提取的数据
	LONG GetBmpWidth();
	LONG GetBmpHeight();
	void SetToGrayCoeff(float R, float G, float B); //设置灰度化系数

private:
	FILE* bmpFile;
	BITMAPFILEHEADER bmpFileHead;
	BITMAPINFOHEADER bmpInfoHead;
	bool readSuccess;
	COEFF coeff;
	INT ToGray(RGBQUAD* rgb); //灰度化
};

BmpReader::BmpReader(CHAR* filename)
{
	readSuccess = false; //初始化标志
	coeff.R = 0.11f, coeff.G = 0.59f, coeff.B = 0.30f;

	bmpFile = fopen(filename, "rb");
	if(bmpFile != NULL)
	{
		WORD fileType;
		fread(&fileType,1,sizeof(WORD),bmpFile);
		if(fileType != 0x4d42)    //判断是不是bmp格式文件
		{
			throw "file is not .bmp file!";
		}
	}
	else
	{
		throw "file open fail!";
	}

	fread(&bmpFileHead,sizeof(tagBITMAPFILEHEADER),1,bmpFile);
	fread(&bmpInfoHead,sizeof(tagBITMAPINFOHEADER),1,bmpFile);
	
	readSuccess = true; //读取成功
}

BmpReader::~BmpReader()
{
	if(bmpFile != NULL)
	{
		fclose(bmpFile);
	}
}

LONG BmpReader::GetBmpWidth()
{
	if(readSuccess)
	{
		return bmpInfoHead.biWidth;
	}
	else return 0;
}

LONG BmpReader::GetBmpHeight()
{
	if(readSuccess)
	{
		return bmpInfoHead.biHeight;
	}
	else return 0;
}

int BmpReader::SaveData(CHAR* saveFileName) //返回值 "1"->成功; "0"->失败
{
	if(readSuccess)
	{
		FILE* fout;
		fout = fopen(saveFileName, "wb+");
		if(fout == NULL)
		{
			throw "create output file fail";
		}
		char mark[5] = "ImgB"; //文件标识
		fwrite(mark, sizeof(CHAR), 4, fout);
		fwrite(&bmpInfoHead.biWidth, sizeof(UINT), 1, fout);
		fwrite(&bmpInfoHead.biHeight, sizeof(UINT), 1, fout);

		INT x, y; //x,y:像素坐标
		RGBQUAD* pRGB;
		RGBQUAD rgb;
		INT lineByte;
		UCHAR gray;
		lineByte = ((bmpInfoHead.biWidth * bmpInfoHead.biBitcount + 31) >> 5) << 2; //一行的字节数

		if(bmpInfoHead.biBitcount < 24) //非真彩色，读取调色板并填充到内存，方便后面索引
		{
			LONG nPlantNum = LONG(pow(2,double(bmpInfoHead.biBitcount))); // 色彩数;
			pRGB = (tagRGBQUAD*)malloc(nPlantNum * sizeof(tagRGBQUAD));
			memset(pRGB, 0, nPlantNum * sizeof(tagRGBQUAD));
			fseek(bmpFile, sizeof(tagBITMAPFILEHEADER) + sizeof(tagBITMAPINFOHEADER), 0);
			fread(pRGB, sizeof(tagRGBQUAD), nPlantNum, bmpFile);
		}
		
		for(x = bmpInfoHead.biHeight - 1; x >= 0; x--) //注意倒序
		{	
			//输出进度
			//fflush(stdout); 
			fprintf(stdout, "%d%%\n", (int)((bmpInfoHead.biHeight-1.0-x)/(bmpInfoHead.biHeight-1.0)*100));
			

			fseek(bmpFile, bmpFileHead.bfOffBits + (x * lineByte), 0);
			
			if(1 == bmpInfoHead.biBitcount) //biBitcount == 1
			{
				BYTE index;
				for(y = 0; y < bmpInfoHead.biWidth; y += 8)
				{	
					fread(&index,1,1,bmpFile);
					for(int i=7; i >=0; i--)
					{
						rgb = pRGB[(index>>i)&1];
						gray = (UCHAR)ToGray(&rgb);
						fwrite(&gray, sizeof(UCHAR), 1, fout);
					}	
				}
			}
			else if(4 == bmpInfoHead.biBitcount) //biBitcount == 4
			{
				BYTE index;
				for(y = 0; y < bmpInfoHead.biWidth; y += 2)
				{
					fread(&index,1,1,bmpFile);

					rgb = pRGB[index%0x10];
					gray = (UCHAR)ToGray(&rgb);
					fwrite(&gray, sizeof(UCHAR), 1, fout);

					rgb = pRGB[(index-index%0x10)/0x10];
					gray = (UCHAR)ToGray(&rgb);
					fwrite(&gray, sizeof(UCHAR), 1, fout);	
				}
			}
			else
			{
				for(y = 0; y < bmpInfoHead.biWidth; y++)
				{
					if(8 == bmpInfoHead.biBitcount) //biBitcount == 8
					{
						BYTE index;
						fread(&index,bmpInfoHead.biBitcount/8,1,bmpFile);
						rgb = pRGB[index];
					}
					else if(16 == bmpInfoHead.biBitcount) //biBitcount == 16
					{
						WORD index;
						fread(&index,bmpInfoHead.biBitcount/8,1,bmpFile);
						rgb = pRGB[index];
					}
					else  //直接读取RGB,biBitcount == 24或32
					{
						fread(&rgb, bmpInfoHead.biBitcount/8,1,bmpFile);
					}
	
					gray = (UCHAR)ToGray(&rgb);
					fwrite(&gray, sizeof(UCHAR), 1, fout);
				}				
			}
			
			rewind(bmpFile);
		}

		//完成
		//fflush(stdout);
		fprintf(stdout, "100%% Done!\n");

		if(pRGB != NULL) free(pRGB);  //释放动态申请的内存
		fclose(fout);
		fclose(bmpFile);
		return 1;
	}

	return 0;
}

void BmpReader::SetToGrayCoeff(float R, float G, float B)
{
	coeff.B = B;
	coeff.G = G;
	coeff.R = R;
}

int BmpReader::ToGray(RGBQUAD* rgb)
{
	return (INT)(rgb->B*coeff.B+rgb->G*coeff.G+rgb->R*coeff.R);
}

#endif