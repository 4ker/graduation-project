/*************************************************
*                                                *
* Author: keith70                                *
* Date modified: 2012.04.01                      *
* Description: Defines JpgReader class           *
*                                                *
*************************************************/

#ifndef _JPGREADER_H_
#define _JPGREADER_H_

#include <cstdio>
#include <cstring>
#include "jpglib.h"
#include "integer.h"

/* User defined device identifier */
typedef struct {
    FILE *fp;      /* File pointer for input function */
    BYTE *fbuf;    /* Pointer to the frame buffer for output function */
    UINT wfbuf;    /* Width of the frame buffer [pix] */
} IODEV;

UINT in_func (JDEC* jd, BYTE* buff, UINT nbyte)
{
    IODEV *dev = (IODEV*)jd->device;   /* Device identifier for the session (5th argument of jd_prepare function) */


    if (buff) {
        /* Read bytes from input stream */
        return (UINT)fread(buff, 1, nbyte, dev->fp);
    } else {
        /* Remove bytes from input stream */
        return fseek(dev->fp, nbyte, SEEK_CUR) ? 0 : nbyte;
    }
}

UINT out_func (JDEC* jd, void* bitmap, JRECT* rect)
{
    IODEV *dev = (IODEV*)jd->device;
    BYTE *src, *dst;
    UINT y, bws, bwd;


    /* Put progress indicator
    if (rect->left == 0) {
        printf("\r%lu%%", (rect->top << jd->scale) * 100UL / jd->height);
    } */

    /* Copy the decompressed RGB rectanglar to the frame buffer (assuming RGB888 cfg) */
    src = (BYTE*)bitmap;
    dst = dev->fbuf + 3 * (rect->top * dev->wfbuf + rect->left);  /* Left-top of destination rectangular */
    bws = 3 * (rect->right - rect->left + 1);     /* Width of source rectangular [byte] */
    bwd = 3 * dev->wfbuf;                         /* Width of frame buffer [byte] */
    for (y = rect->top; y <= rect->bottom; y++) {
        memcpy(dst, src, bws);   /* Copy a line */
        src += bws; dst += bwd;  /* Next line */
    }

    return 1;    /* Continue to decompress */
}

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

class JpgReader
{
public:
	JpgReader(CHAR* filename);
	~JpgReader();
	INT SaveData(CHAR* saveFileName); //保存提取的数据
	LONG GetJpgWidth();
	LONG GetJpgHeight();
	void SetToGrayCoeff(float R, float G, float B); //设置灰度化系数

private:
	bool readSuccess;
	COEFF coeff;

	void *work;       /* Pointer to the decompressor work area */
    JDEC jdec;        /* Decoder object */
    JRESULT res;      /* Result code of TJpgDec API */
    IODEV devid;      /* User defined device identifier */

	void write_data(const char* fname,BYTE* buf,UINT width,UINT heigh); //写入数据到文件
};

JpgReader::JpgReader(CHAR* filename)
{
	readSuccess = false;
	coeff.R = 0.11f, coeff.G = 0.59f, coeff.B = 0.30f;

	devid.fp = fopen(filename, "rb"); //打开JPEG文件
	if(!devid.fp)
	{
		throw "open file fail";
	}
	
	work = malloc(3100); //分配工作空间
	res = jd_prepare(&jdec, in_func, work, 3100, &devid); //初始化
	if (res == JDR_OK) 
	{		
        devid.fbuf = (UCHAR*)malloc(3 * jdec.width * jdec.height); 
        devid.wfbuf = jdec.width;
		readSuccess = true;    
    } 
	else 
	{
		free(work);
		throw "Failed to prepare";
	}
}

JpgReader::~JpgReader()
{
	if(work != NULL) free(work);
}

LONG JpgReader::GetJpgWidth()
{
	if(readSuccess)
	{
		return jdec.width;
	}
	else return 0;
}

LONG JpgReader::GetJpgHeight()
{
	if(readSuccess)
	{
		return jdec.height;
	}
	else return 0;
}

INT JpgReader::SaveData(CHAR* saveFileName)
{
	if(!readSuccess)
	{
		throw "file read fail";
	}
	
	res = jd_decomp(&jdec, out_func, 0);  //开始解析
	if (res == JDR_OK) 
	{    
		//保存数据到文件
		write_data(saveFileName, devid.fbuf, jdec.width, jdec.height);
	} 
	else 
	{
		throw "Failed to decompress"; 
	}		
	free(devid.fbuf);  //释放内存
	fclose(devid.fp);
	return 1;
}

void JpgReader::write_data(const char* fname, BYTE* buf, UINT width, UINT height)
{
	FILE* fout;
	BYTE R,G,B;
	LONG index;
	UCHAR gray;
	fout = fopen(fname, "wb+");
	if(fout == NULL)
	{
		throw "create output file fail";
	}
	char mark[5] = "ImgB"; //文件标识
	fwrite(mark, sizeof(CHAR), 4, fout);
	fwrite(&width, sizeof(UINT), 1, fout);
	fwrite(&height, sizeof(UINT), 1, fout);

	for(UINT i=0; i < height; i++)
	{
		//输出进度
		//fflush(stdout);
		fprintf(stdout, "%d%%\n", (int)(i/(height-1.0)*100));

		index = i*width*3;
		for(UINT j=0; j < width; j++)
		{
			R = buf[index + j*3];
			G = buf[index + j*3 + 1]; 
			B = buf[index + j*3 + 2];
			gray = (UCHAR)(R*coeff.R+G*coeff.G+B*coeff.B);
			fwrite(&gray, sizeof(UCHAR), 1, fout);
		}
	}
	fclose(fout);
	//完成
	//fflush(stdout);
	fprintf(stdout, "100%% Done!\n");
}

void JpgReader::SetToGrayCoeff(float R, float G, float B)
{
	coeff.R = R;
	coeff.G = G;
	coeff.B = B;
}

#endif
