#include "stdafx.h"
#include "fixcom_bridge.h"
#include <FixCommA/FixCommA.h>
#include "BHKD_utilities.h"
#include "FixDef.h"
#include "FixDef_Field.h"
#include <vector>
#include <string>
#define RtlZeroMemory(Destination,Length) memset((Destination),0,(Length))
#define ZeroMemory RtlZeroMemory
using namespace BHKD;

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

int TestNew()
{
	int lnLoopCount = 0;

	while(1)
	{
		ICommInterFaceC * lpICommInterFaceC = NULL;

		int lnRet = CreateICommInterFaceC(&lpICommInterFaceC);

		if (!lnRet)
		{
			return 0;
		}
		
		

		 lnRet =  lpICommInterFaceC->m_pVTable->Link(lpICommInterFaceC,"192.168.1.107",17001);
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

			lpICommInterFaceC->m_pVTable->SetItemString(lpICommInterFaceC,FIELD_SYSTEM_COMPANY, "c");
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

	memcpy(appBuffer,lstrRet.c_str(),lstrRet.length()+1);

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

	memcpy(appBuffer,lstrRet.c_str(),lstrRet.length()+1);

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






