#include "stdafx.h"
#include "fixcom_bridge.h"
#include <FixCommA/FixCommA.h>
#include "BHKD_utilities.h"
#include "FixDef.h"
#include "FixDef_Field.h"
#include <vector>
#include <string>
#include <iconv.h>
#define RtlZeroMemory(Destination,Length) memset((Destination),0,(Length))
#define ZeroMemory RtlZeroMemory
using namespace BHKD;

#ifndef _WIN32
#define __iconv_open iconv_open
#define __iconv_close iconv_close
#define __iconv iconv
#else
#define __iconv_open libiconv_open
#define __iconv_close libiconv_close
#define __iconv libiconv
#endif

int code_convert(char *from_charset,
				 char *to_charset,
				 char *inbuf,
				 unsigned int  *inlen,
				 char *outbuf,
				 unsigned int  *outlen) 
{ 
	if (inlen == NULL || inbuf == NULL || from_charset == NULL || to_charset == NULL)
	{
		return -1;
	}

	if (outlen == NULL)
	{
		return -1;
	}

	iconv_t cd;

	int rc; 

	const char **pin = (const char **)&inbuf; 

	char **pout = &outbuf; 

	cd = __iconv_open(to_charset,from_charset); 

	if (cd<0)
	{
		return -1;
	}; 

	memset(outbuf,0,*outlen); 

	if (__iconv(cd,pin,(size_t *)inlen,pout,(size_t *)outlen)==-1) 
	{
		__iconv_close(cd); 

		return -1; 
	}

	__iconv_close(cd); 

	return 1; 
} 

int convert(char *inbuf,
			size_t * inlen,
			char *outbuf,
			size_t * outlen,
			__STRING__LANG__SUPPORTTED src,
			__STRING__LANG__SUPPORTTED dst)
{
	std::string CODE_PAGE_GBK = "GBK";

	std::string CODE_PAGE_UTF_8= "UTF-8";

	std::string CODE_PAGE_UTF_16= "UTF-16";

	char * lpEncSrc = NULL;

	char  * lpEncDst = NULL;

	switch(src)
	{
	case __STRING__LANG__SUPPORTTED_ASCII_GBK:
	case __STRING__LANG__SUPPORTTED_ASCII_GB2312:
	case __STRING__LANG__SUPPORTTED_ASCII_CP936:
		lpEncSrc = (char *)CODE_PAGE_GBK.c_str();
		break;
	case __STRING__LANG__SUPPORTTED_UTF_16:
		lpEncSrc = (char *)CODE_PAGE_UTF_16.c_str();
		break;
	case __STRING__LANG__SUPPORTTED_UTF_8:
		lpEncSrc = (char *)CODE_PAGE_UTF_8.c_str();
		break;
	default:
		return -1;		
	}

	switch(dst)
	{
	case __STRING__LANG__SUPPORTTED_ASCII_GBK:
	case __STRING__LANG__SUPPORTTED_ASCII_GB2312:
	case __STRING__LANG__SUPPORTTED_ASCII_CP936:
		lpEncDst = (char *)CODE_PAGE_GBK.c_str();
		break;
	case __STRING__LANG__SUPPORTTED_UTF_16:
		lpEncDst = (char *)CODE_PAGE_UTF_16.c_str();
		break;
	case __STRING__LANG__SUPPORTTED_UTF_8:
		lpEncDst = (char *)CODE_PAGE_UTF_8.c_str();
		break;
	default:
		return -1;		
	}

	int lnRet = code_convert(lpEncSrc,lpEncDst,inbuf,inlen,outbuf,outlen);

	return lnRet;
}

#ifndef _WIN32
#include <pthread.h>
#include <unistd.h>

#define Sleep usleep



#endif

int TestOriginal()
{
	int lnLoopCount = 0;

	while(1)
	{
		CFixCommA arefFixCom;
		int lnRet =  arefFixCom.Link("192.168.1.107",17001);
		if(lnRet>0)
		{
			std::vector<S_VibCharValue> loVibs;
			std::vector<DATATYPE_WAVE> loWaves;

			for (int i=0;i<2;i++)
			{
				S_VibCharValue loValue;
				loValue._fCharAll = 12.34;
				loValue._fCharHalf = 0;
				loValue._fPhaseHalf = 0;

				loValue._fCharOne = 0;
				loValue._fPhaseOne = 0;

				loValue._fCharTwo =0;
				loValue._fPhaseTwo = 0;

				loValue._fCharThree =0;
				loValue._fPhaseThree = 0;
				loValue._iRev = 1000;
				loValue._fGap = 0;
				loValue._iSmpFreq = 1024;
				loValue._iSmpNum = 4096;

				for (int i=0;i<loValue._iSmpNum;i++)
				{
					short lnData = 100;

					loWaves.push_back(lnData);
				}
				loVibs.push_back(loValue);	
			}


			arefFixCom.CreateHead(24000);
			arefFixCom.SetItem(FIELD_SYSTEM_COMPANY, "c");
			arefFixCom.SetItem(FIELD_SYSTEM_FACTORY, "f");
			arefFixCom.SetItem(FIELD_SERVICE_PLANTID,"p");		
			arefFixCom.SetItem(FIELD_SERVICE_ON_SEND_STARTID, 0);
			arefFixCom.SetItem(FIELD_SERVICE_ON_SEND_VIBCHANNNUM,2);
			arefFixCom.SetItem(FIELD_SERVICE_ON_SEND_WAVEPOINTNUM, (int)loWaves.size());
			arefFixCom.SetItem(FIELD_SERVICE_SEND_END, 1);
			arefFixCom.SetItemBuf(FIELD_SERVICE_ON_SEND_ALLCHARVALUE, (char *)&loVibs.front(), sizeof(S_VibCharValue)*loVibs.size());
			char *pWave = (char *)&loWaves.front();
			int lnBufferSize = loWaves.size()*sizeof(DATATYPE_WAVE);
			arefFixCom.SetItemBuf(FIELD_SERVICE_ON_SEND_VIBWAVE, pWave, lnBufferSize);
			arefFixCom.SetItem(FIELD_SERVICE_ZIPWAVE_BYTESNUM, -1);		
			arefFixCom.SetItem(FIELD_SERVICE_TIME, "1900-01-01 17:00:00");
			arefFixCom.SetItem(FIELD_SERVICE_MICROSECOND, 123);

			if (arefFixCom.More())
			{
				Sleep(100);
				
				if (lnLoopCount++>100)
				{
					return 1;
				}

			}

		}
	}

	return 0;
}

int Test20025()
{
	ICommInterFaceC * lpICommInterFaceC = NULL;

	int lnRet = CreateICommInterFaceC(&lpICommInterFaceC);

	lnRet =  lpICommInterFaceC->m_pVTable->Link(lpICommInterFaceC,"127.0.0.1",17001);

	lpICommInterFaceC->m_pVTable->CreateHead(lpICommInterFaceC,20025);

	while(lpICommInterFaceC->m_pVTable->More(lpICommInterFaceC))
	{
		std::vector<char> loBuffer(1024);

		char * lpBuffer = &loBuffer.front();

		int lnSize = 0;

		lpICommInterFaceC->m_pVTable->GetItemStringEnc(lpICommInterFaceC,
														10013,
														NULL,
														&lnSize,
														__STRING__LANG__SUPPORTTED_ASCII_GBK,
														__STRING__LANG__SUPPORTTED_UTF_8);

		lpICommInterFaceC->m_pVTable->GetItemStringEnc(lpICommInterFaceC,
			10013,
			lpBuffer,
			&lnSize,
			__STRING__LANG__SUPPORTTED_ASCII_GBK,
			__STRING__LANG__SUPPORTTED_UTF_8);
#ifdef _WIN32
		CString lstrData = lpBuffer;
#endif // _WIN32

		
	}

	return 0;
}

int TestNew()
{
	Test20025();
	int lnLoopCount = 0;

	while(1)
	{
		ICommInterFaceC * lpICommInterFaceC = NULL;

		int lnRet = CreateICommInterFaceC(&lpICommInterFaceC);

		if (!lnRet)
		{
			return 0;
		}
		
		

		 lnRet =  lpICommInterFaceC->m_pVTable->Link(lpICommInterFaceC,"127.0.0.1",17001);
		if(lnRet>0)
		{
			std::vector<S_VibCharValue> loVibs;
			std::vector<DATATYPE_WAVE> loWaves;

			for (int i=0;i<2;i++)
			{
				S_VibCharValue loValue;
				loValue._fCharAll = 12.34;
				loValue._fCharHalf = 0;
				loValue._fPhaseHalf = 0;

				loValue._fCharOne = 0;
				loValue._fPhaseOne = 0;

				loValue._fCharTwo =0;
				loValue._fPhaseTwo = 0;

				loValue._fCharThree =0;
				loValue._fPhaseThree = 0;
				loValue._iRev = 1000;
				loValue._fGap = 0;
				loValue._iSmpFreq = 1024;
				loValue._iSmpNum = 4096;

				for (int i=0;i<loValue._iSmpNum;i++)
				{
					short lnData = 100;

					loWaves.push_back(lnData);
				}
				loVibs.push_back(loValue);	
			}


			lpICommInterFaceC->m_pVTable->CreateHead(lpICommInterFaceC,24000);

			lpICommInterFaceC->m_pVTable->SetItemStringEnc(lpICommInterFaceC,FIELD_SYSTEM_COMPANY, "c",__STRING__LANG__SUPPORTTED_UTF_8,__STRING__LANG__SUPPORTTED_ASCII_GBK);
			lpICommInterFaceC->m_pVTable->SetItemString(lpICommInterFaceC,FIELD_SYSTEM_FACTORY, "f");
			lpICommInterFaceC->m_pVTable->SetItemString(lpICommInterFaceC,FIELD_SERVICE_PLANTID,"p");		
			lpICommInterFaceC->m_pVTable->SetItemLong(lpICommInterFaceC,FIELD_SERVICE_ON_SEND_STARTID, 0);
			lpICommInterFaceC->m_pVTable->SetItemLong(lpICommInterFaceC,FIELD_SERVICE_ON_SEND_VIBCHANNNUM,2);
			lpICommInterFaceC->m_pVTable->SetItemLong(lpICommInterFaceC,FIELD_SERVICE_ON_SEND_WAVEPOINTNUM, (int)loWaves.size());
			lpICommInterFaceC->m_pVTable->SetItemLong(lpICommInterFaceC,FIELD_SERVICE_SEND_END, 1);
			lpICommInterFaceC->m_pVTable->SetItemBuf(lpICommInterFaceC,FIELD_SERVICE_ON_SEND_ALLCHARVALUE, (char *)&loVibs.front(), sizeof(S_VibCharValue)*loVibs.size());
			char *pWave = (char *)&loWaves.front();
			int lnBufferSize = loWaves.size()*sizeof(DATATYPE_WAVE);
			lpICommInterFaceC->m_pVTable->SetItemBuf(lpICommInterFaceC,FIELD_SERVICE_ON_SEND_VIBWAVE, pWave, lnBufferSize);
			lpICommInterFaceC->m_pVTable->SetItemLong(lpICommInterFaceC,FIELD_SERVICE_ZIPWAVE_BYTESNUM, -1);		
			lpICommInterFaceC->m_pVTable->SetItemString(lpICommInterFaceC,FIELD_SERVICE_TIME, "1900-01-01 17:00:00");
			lpICommInterFaceC->m_pVTable->SetItemLong(lpICommInterFaceC,FIELD_SERVICE_MICROSECOND, 123);

			if (lpICommInterFaceC->m_pVTable->More(lpICommInterFaceC))
			{
				Sleep(1000);

				if (lnLoopCount++>100)
				{
					DeleteICommInterFaceC(lpICommInterFaceC);

					return 1;
				}

			}

			DeleteICommInterFaceC(lpICommInterFaceC);

		}
	}

	return 0;
}
int test()
{
	return TestNew();

}

#define _ICOMMINTERFACEC_CHECK_MAGIC_ 233
 //返回是否是合法的this指针
bool	IsValidPointer( void * apThis)
{	
	if (NULL==apThis)
	{
		return false;
	}

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	if (lpComm->m_nMagicNumber != _ICOMMINTERFACEC_CHECK_MAGIC_)
	{
		return false;
	}

	if (lpComm->m_pFixCom == 0)
	{
		return false;
	}

	if (lpComm->m_nFixComCheck != (lpComm->m_pFixCom^lpComm->m_nMagicNumber))
	{
		return false;
	}

	return true;
}

#define CHECK_POINTER(p)	if (IsValidPointer(p)!=true)\
							{\
								return false;\
							};\

#define CHECK_POINTER_NO_RETURN(p)	if (IsValidPointer(p)!=true)\
									{\
										return ;\
									};\

#define CHECK_POINTER_RETURN(p,y)	if (IsValidPointer(p)!=true)\
									{\
										return y;\
									};\

bool  GetItemBuf( void * apThis,int nFixCode, unsigned char *pBuf, int nSize )
{
	
	CHECK_POINTER(apThis);
	
	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	bool lnRet  = lpFixComm->GetItemBuf(nFixCode,pBuf,nSize);

	return lnRet;
}

bool  GetItemBuf2(void * apThis, int nFixCode, char *pBuf, int nSize )
{
	CHECK_POINTER(apThis);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	bool lnRet  = lpFixComm->GetItemBuf(nFixCode,pBuf,nSize);

	return lnRet;
}

bool   More(void * apThis)
{
	CHECK_POINTER(apThis);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	bool lnRet  = lpFixComm->More();

	return lnRet;
}

bool Link( void * apThis,const char *pAddr_,  int iPort_ )
{
	CHECK_POINTER(apThis);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	bool lnRet  = lpFixComm->Link(pAddr_,iPort_);

	return lnRet;
}

void CreateHead ( void * apThis,int nFunc)
{
	CHECK_POINTER_NO_RETURN(apThis);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	lpFixComm->CreateHead(nFunc);

}



bool Close(void * apThis)
{
	CHECK_POINTER(apThis);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	bool lnRet  = lpFixComm->Close();

	return lnRet;
}


void   SetTimeOut(void * apThis, long nMaxSec )
{
	CHECK_POINTER_NO_RETURN(apThis);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	lpFixComm->SetTimeOut(nMaxSec);
}

double	GetDouble  ( void * apThis,int nFixCode)
{
	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	double ldblRet = lpFixComm->GetDouble(nFixCode);

	return ldblRet;
}

float	GetFloat(void * apThis, int nFixCode )
{
	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	float ldblRet = lpFixComm->GetFloat(nFixCode);

	return ldblRet;
}

long	GetLong ( void * apThis,int nFixCode )
{
	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	long ldblRet = lpFixComm->GetLong(nFixCode);

	return ldblRet;
}


int  GetString( void * apThis,int nFixCode , char * appBuffer, int * apBufferSize)
{
	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	std::string lstrRet = lpFixComm->Get(nFixCode);

	if (appBuffer == NULL || apBufferSize == NULL || *apBufferSize <= lstrRet.length())
	{
		if (apBufferSize == NULL)
		{
			return 0;
		}

		*apBufferSize = lstrRet.length()+1;

		return 0;
	}

	memset(appBuffer,0,lstrRet.length()+1);

	memcpy(appBuffer,lstrRet.c_str(),lstrRet.length());

	return lstrRet.length()+1;
};

int  GetItemString( void * apThis,int nFixCode, char * appBuffer, int * apBufferSize )
{
	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	std::string lstrRet = lpFixComm->Get(nFixCode);

	if (appBuffer == NULL || apBufferSize == NULL || *apBufferSize <= lstrRet.length())
	{
		if (apBufferSize == NULL)
		{
			return 0;
		}

		*apBufferSize = lstrRet.length()+1;

		return 0;
	}

	memset(appBuffer,0,lstrRet.length()+1);

	memcpy(appBuffer,lstrRet.c_str(),lstrRet.length());	

	return lstrRet.length()+1;

}

bool  SetItemDouble(  void * apThis,int nFixCode , double      dValue   )
{
	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	bool ldblRet = lpFixComm->SetItem(nFixCode,dValue);

	return ldblRet;
};

bool  SetItemLong(  void * apThis,int nFixCode , long        nValue   )
{
	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	bool ldblRet = lpFixComm->SetItem(nFixCode,nValue);

	return ldblRet;
}

bool SetItemInt( void * apThis, int nFixCode , int         nValue   )
{
	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	bool ldblRet = lpFixComm->SetItem(nFixCode,nValue);

	return ldblRet;
}



bool SetItemString( void * apThis, int nFixCode , const char *pszData )
{
	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	if (NULL == pszData )
	{
		return 0;
	}

	bool ldblRet = lpFixComm->SetItem(nFixCode,pszData);

	return ldblRet;
}


bool SetItemBuf(  void * apThis,int nFixCode, char *pBuf, int nSize )
{
	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	bool ldblRet = lpFixComm->SetItemBuf(nFixCode,pBuf,nSize);

	return ldblRet;
}

int  GetItemStringEnc (	void * apThis,
					   int nFixCode , 
					   char * appBuffer, 
					   int * apBufferSize,
					   __STRING__LANG__SUPPORTTED encSrc, 
					   __STRING__LANG__SUPPORTTED encDst)
{

	CHECK_POINTER_RETURN(apThis,0);

	if (apBufferSize == NULL)
	{
		return 0;
	}

	unsigned int lnDataSize = 0;

	int lnRet = GetItemString(apThis,nFixCode,NULL,(int *)&lnDataSize);

	if (lnDataSize<=0)
	{
		return 0;
	}

	std::vector<char> loBuffer(lnDataSize+2);

	char * lpBuffer =  &loBuffer.front();

	lnRet = GetItemString(apThis,nFixCode,lpBuffer,(int *)&lnDataSize);

	std::vector<char> loBufferOut(lnDataSize*5);

	char * lpBufferOut = &loBufferOut.front();

	unsigned int lnBufferOut = loBufferOut.size();

	if (lnRet>0)
	{
		lnRet = convert(lpBuffer,&lnDataSize,lpBufferOut,&lnBufferOut,encSrc,encDst);

		if (lnRet>=0)
		{
			if(*apBufferSize<(loBufferOut.size()-lnBufferOut+1))
			{
				*apBufferSize = loBufferOut.size() - lnBufferOut+1;

				return 0;
			}

			memcpy(appBuffer,lpBufferOut,(loBufferOut.size() - lnBufferOut+1));
			
		}
		
	}

	if (lnRet<0)
	{
		lnRet =0;
	}

	return lnRet;

}

bool  SetItemStringEnc( void * apThis, 
					   int nFixCode , 
					   const char *pszData ,
					   __STRING__LANG__SUPPORTTED encSrc, 
					   __STRING__LANG__SUPPORTTED encDst)
{


	CHECK_POINTER_RETURN(apThis,0);

	ICommInterFaceC * lpComm = (ICommInterFaceC *)apThis;

	CFixCommA * lpFixComm = (CFixCommA *)lpComm->m_pFixCom;

	if (NULL == pszData)
	{
		return 0;
	}

	size_t lnStrLength = strlen(pszData);

	size_t lnDataSize = (int)lnStrLength;

	if (lnDataSize==0 || lnDataSize > 409600)
	{
		return 0;
	}

	std::vector<char> loOutBuffer(lnDataSize*4+2);

	char * lpBufferOut = &loOutBuffer.front();

	size_t lnOutSize = loOutBuffer.size();

	size_t lnOutLeft = lnOutSize;

	int lnRet = convert((char *)pszData,&lnDataSize,lpBufferOut,&lnOutSize,encSrc,encDst);

	if (lnRet<0)
	{
		return 0;
	}
	
	bool ldblRet = lpFixComm->SetItem(nFixCode,(const char *)lpBufferOut);

	return ldblRet;

}


int CreateICommInterFaceC( ICommInterFaceC ** apData )
{
	if (NULL == apData)
	{
		return FALSE;
	}

	if (*apData != NULL)
	{
		return FALSE;
	}

	*apData = new ICommInterFaceC();

	CFixCommA * lpFixCom = new CFixCommA();

	(*apData)->m_nMagicNumber = _ICOMMINTERFACEC_CHECK_MAGIC_;

	(*apData)->m_pFixCom = (int)lpFixCom;

	(*apData)->m_nFixComCheck = (*apData)->m_pFixCom^_ICOMMINTERFACEC_CHECK_MAGIC_;

	(*apData)->m_pVTable = new ICommInterFace__VTable();
	
	 ZeroMemory((*apData)->m_pVTable,sizeof(LP_ICommInterFace__VTable));

	(*apData)->m_pVTable->IsValidPointer = IsValidPointer;

	(*apData)->m_pVTable->Close = Close;

	(*apData)->m_pVTable->CreateHead = CreateHead;

	(*apData)->m_pVTable->GetDouble = GetDouble;

	(*apData)->m_pVTable->GetFloat = GetFloat;

	(*apData)->m_pVTable->GetItemBuf = GetItemBuf;

	(*apData)->m_pVTable->GetItemBuf2 = GetItemBuf2;

	(*apData)->m_pVTable->GetItemString = GetItemString;

	(*apData)->m_pVTable->GetLong = GetLong;

	(*apData)->m_pVTable->GetString = GetString;

	(*apData)->m_pVTable->Link = Link;

	(*apData)->m_pVTable->More = More;

	(*apData)->m_pVTable->SetItemBuf = SetItemBuf;

	(*apData)->m_pVTable->SetItemDouble = SetItemDouble;

	(*apData)->m_pVTable->SetItemInt = SetItemInt;

	(*apData)->m_pVTable->SetItemLong = SetItemLong;

	(*apData)->m_pVTable->SetItemString =  SetItemString;

	(*apData)->m_pVTable->SetTimeOut = SetTimeOut;

	(*apData)->m_pVTable->GetItemStringEnc = GetItemStringEnc;

	(*apData)->m_pVTable->SetItemStringEnc = SetItemStringEnc;
	
	return TRUE;
}

int DeleteICommInterFaceC( ICommInterFaceC * apData )
{
	if (NULL == apData)
	{
		return FALSE;
	}

	if (apData->m_nFixComCheck != (apData->m_pFixCom^_ICOMMINTERFACEC_CHECK_MAGIC_))
	{
		return FALSE;
	}

	if (apData->m_nMagicNumber!= _ICOMMINTERFACEC_CHECK_MAGIC_)
	{
		return FALSE;
	}

	CFixCommA * lpFixComm = (CFixCommA *)apData->m_pFixCom;

	if (lpFixComm!=NULL)
	{
		lpFixComm->Close();

		delete lpFixComm;
	}

	apData->m_pFixCom = 0;

	delete apData;

	return TRUE;

}





