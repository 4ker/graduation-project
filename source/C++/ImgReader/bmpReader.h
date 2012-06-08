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


//bmp�ļ�ͷ
typedef struct tagBITMAPFILEHEADER
{
	DWORD bfSize;       //�ļ���С
	WORD  bfReserved1;  //�����֣�������
	WORD  bfReserved2;  //�����֣�ͬ��
	DWORD bfOffBits;    //ʵ��λͼ���ݵ�ƫ���ֽ���
} BITMAPFILEHEADER;

//bmp��Ϣͷ
typedef struct tagBITMAPINFOHEADER
{
	DWORD  biSize;                 //�ýṹ��С���ֽ�Ϊ��λ
	LONG   biWidth;                //ͼ�ο��������Ϊ��λ
	LONG   biHeight;               //ͼ�θ߶�������Ϊ��λ
	WORD   biPlanes;               //Ŀ���豸�ļ��𣬱���Ϊ1
	WORD   biBitcount;             //��ɫ��ȣ�ÿ����������Ҫ��λ��
	DWORD  biCompression;          //λͼ��ѹ������
	DWORD  biSizeImage;            //λͼ�Ĵ�С�����ֽ�Ϊ��λ
	LONG   biXPelsPermeter;        //λͼˮƽ�ֱ��ʣ�ÿ��������
	LONG   biYPelsPermeter;        //λͼ��ֱ�ֱ��ʣ�ÿ��������
	DWORD  biClrUsed;              //λͼʵ��ʹ�õ���ɫ���е���ɫ��
	DWORD  biClrImportant;         //λͼ��ʾ��������Ҫ����ɫ��
} BITMAPINFOHEADER;

//��ɫ��
typedef struct tagRGBQUAD
{
    BYTE  B;           //��
    BYTE  G;           //��
    BYTE  R;           //��
	BYTE  reserved;
}RGBQUAD;

#ifndef _COEFF_
#define _COEFF_
//RGB->�ҶȻ�ϵ��
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
	INT SaveData(CHAR* saveFileName); //������ȡ������
	LONG GetBmpWidth();
	LONG GetBmpHeight();
	void SetToGrayCoeff(float R, float G, float B); //���ûҶȻ�ϵ��

private:
	FILE* bmpFile;
	BITMAPFILEHEADER bmpFileHead;
	BITMAPINFOHEADER bmpInfoHead;
	bool readSuccess;
	COEFF coeff;
	INT ToGray(RGBQUAD* rgb); //�ҶȻ�
};

BmpReader::BmpReader(CHAR* filename)
{
	readSuccess = false; //��ʼ����־
	coeff.R = 0.11f, coeff.G = 0.59f, coeff.B = 0.30f;

	bmpFile = fopen(filename, "rb");
	if(bmpFile != NULL)
	{
		WORD fileType;
		fread(&fileType,1,sizeof(WORD),bmpFile);
		if(fileType != 0x4d42)    //�ж��ǲ���bmp��ʽ�ļ�
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
	
	readSuccess = true; //��ȡ�ɹ�
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

int BmpReader::SaveData(CHAR* saveFileName) //����ֵ "1"->�ɹ�; "0"->ʧ��
{
	if(readSuccess)
	{
		FILE* fout;
		fout = fopen(saveFileName, "wb+");
		if(fout == NULL)
		{
			throw "create output file fail";
		}
		char mark[5] = "ImgB"; //�ļ���ʶ
		fwrite(mark, sizeof(CHAR), 4, fout);
		fwrite(&bmpInfoHead.biWidth, sizeof(UINT), 1, fout);
		fwrite(&bmpInfoHead.biHeight, sizeof(UINT), 1, fout);

		INT x, y; //x,y:��������
		RGBQUAD* pRGB;
		RGBQUAD rgb;
		INT lineByte;
		UCHAR gray;
		lineByte = ((bmpInfoHead.biWidth * bmpInfoHead.biBitcount + 31) >> 5) << 2; //һ�е��ֽ���

		if(bmpInfoHead.biBitcount < 24) //�����ɫ����ȡ��ɫ�岢��䵽�ڴ棬�����������
		{
			LONG nPlantNum = LONG(pow(2,double(bmpInfoHead.biBitcount))); // ɫ����;
			pRGB = (tagRGBQUAD*)malloc(nPlantNum * sizeof(tagRGBQUAD));
			memset(pRGB, 0, nPlantNum * sizeof(tagRGBQUAD));
			fseek(bmpFile, sizeof(tagBITMAPFILEHEADER) + sizeof(tagBITMAPINFOHEADER), 0);
			fread(pRGB, sizeof(tagRGBQUAD), nPlantNum, bmpFile);
		}
		
		for(x = bmpInfoHead.biHeight - 1; x >= 0; x--) //ע�⵹��
		{	
			//�������
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
					else  //ֱ�Ӷ�ȡRGB,biBitcount == 24��32
					{
						fread(&rgb, bmpInfoHead.biBitcount/8,1,bmpFile);
					}
	
					gray = (UCHAR)ToGray(&rgb);
					fwrite(&gray, sizeof(UCHAR), 1, fout);
				}				
			}
			
			rewind(bmpFile);
		}

		//���
		//fflush(stdout);
		fprintf(stdout, "100%% Done!\n");

		if(pRGB != NULL) free(pRGB);  //�ͷŶ�̬������ڴ�
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