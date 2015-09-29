#ifndef _fixcomma_bridge
#define _fixcomma_bridge

#ifndef _WIN32
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_mimimao_eric_fixcomma_NdkJniUtils
 * Method:    getCLanguageString
 * Signature: ()Ljava/lang/String;
 */
  int test();


  typedef struct 
  {
		bool  (*GetItemBuf)( void * apThis,int nFixCode, unsigned char *pBuf, int nSize );

		bool  (*GetItemBuf2)(void * apThis, int nFixCode, char *pBuf, int nSize );

		bool   (*More)(void * apThis);

		bool   (*Link)( void * apThis,const char *pAddr_,  int iPort_ );  

		void   (*CreateHead) ( void * apThis,int nFunc); 

		bool   (*Close)(void * apThis);  

		void    (*SetTimeOut)(void * apThis, long nMaxSec ); 

		double	(*GetDouble)  ( void * apThis,int nFixCode );

		float	(*GetFloat)(void * apThis, int nFixCode);

		long	(*GetLong)    ( void * apThis,int nFixCode );

		int  (*GetString)   ( void * apThis,int nFixCode , char ** appBuffer, int * apBufferSize);

		int  (*GetItemString) ( void * apThis,int nFixCode , char ** appBuffer, int * apBufferSize ); 

		bool    (*SetItemDouble)(  void * apThis,int nFixCode , double      dValue   ); 

		bool    (*SetItemLong)(  void * apThis,int nFixCode , long        nValue   ); 

		bool    (*SetItemInt)( void * apThis, int nFixCode , int         nValue   );

		bool    (*SetItemString)( void * apThis, int nFixCode , const char *pszData ); // 设置某请求域字符串数据 -- 字符串

		bool	(*SetItemBuf)(  void * apThis,int nFixCode, char *pBuf, int nSize );

		bool	(*IsValidPointer)( void * apThis); //返回是否是合法的this指针


  }ICommInterFace__VTable ,* LP_ICommInterFace__VTable;
 
  typedef struct 
  {		
	  unsigned char  m_nMagicNumber;						//shouldNotUse
	  LP_ICommInterFace__VTable m_pVTable;
	  int    m_pFixCom;								//shouldNotUse
	  int    m_nFixComCheck;						//shouldNotUse
  } ICommInterFaceC , * LP_ICommInterFaceC;

  int CreateICommInterFaceC( ICommInterFaceC ** apData);

  int DeleteICommInterFaceC(ICommInterFaceC * apData);

#ifdef __cplusplus
}
#endif
#endif