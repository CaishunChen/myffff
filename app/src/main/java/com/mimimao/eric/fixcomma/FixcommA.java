package com.mimimao.eric.fixcomma;

/**
 * Created by eric on 2015/9/29.
 */
public class FixcommA {

    static {
        System.loadLibrary("JFixCommA");	//defaultConfig.ndk.moduleName
    }

    FixcommA()
    {
        synchronized (this)
        {
            this.m_nNativeObject = this._CreateObject();
        }
    }


    private int m_nNativeObject = 0;

    private native synchronized int _CreateObject();

    private native int _DeleteObject(int anObj);

    private native synchronized  byte[] _GetItemBuf(int anObj,int nFixCode);

    private native synchronized boolean _Link( int anObj, String astrIP,  int iPort_ );

    private native  synchronized  void   _CreateHead ( int anObj,int nFunc);

    private native synchronized  boolean  _Close( int anObj);

    private native synchronized  boolean  _More( int anObj);

    private native  synchronized  void   _SetTimeOut(int anObj, int nMaxSec );

    private native synchronized   double	_GetDouble  (int anObj,int nFixCode );

    private native synchronized  float	_GetFloat (int anObj, int nFixCode);

    private native synchronized  long	_GetLong ( int anObj, int nFixCode);

    private native synchronized  String	_GetString ( int anObj, int nFixCode);

    private native synchronized  String  _GetItemString( int anObj, int nFixCode );

    private native synchronized boolean   _SetItemDouble(  int anObj,int nFixCode , double      dValue   );

    private native synchronized boolean   _SetItemInt( int anObj,int nFixCode  , int  nValue   );

    private native synchronized boolean   _SetItemString( int anObj,int nFixCode   , String astrData );

    private native synchronized boolean   _SetItemBuf( int anObj,int nFixCode  , byte[] apData );

    public synchronized int DeleteObject()
    {
        this.Close();

        int lnRet =  this._DeleteObject(this.m_nNativeObject);

        this.m_nNativeObject = 0;

        return lnRet;
    }

    private synchronized void CheckObj()
    {
        if (this.m_nNativeObject ==0)
        {
            this.m_nNativeObject = this._CreateObject();
        }
    }

    public synchronized  byte[] GetItemBuf(int nFixCode)
    {
        this.CheckObj();

        byte[] lpRet =  this._GetItemBuf(this.m_nNativeObject,nFixCode);

        if(null == lpRet)
        {
            lpRet = new byte[0];
        }

        return lpRet;
    };

    public synchronized boolean Link(  String astrIP,  int iPort )
    {
        this.CheckObj();

        this.Close();

        return this._Link(this.m_nNativeObject,astrIP,iPort);
    };

    public  synchronized  void   CreateHead ( int nFunc)
    {
        this.CheckObj();

        this._CreateHead(this.m_nNativeObject,nFunc);
    };

    public synchronized  boolean  Close()
    {
        this.CheckObj();

        return  this._Close(this.m_nNativeObject);
    };

    public  synchronized  void   SetTimeOut( int nMaxSec )
    {
        this.CheckObj();

        this._SetTimeOut(this.m_nNativeObject,nMaxSec);
    };

    public synchronized   double	GetDouble  (int nFixCode )
    {
        this.CheckObj();

        return this._GetDouble(this.m_nNativeObject,nFixCode);
    };

    public synchronized  float	GetFloat ( int nFixCode)
    {
        this.CheckObj();

        return this._GetFloat(this.m_nNativeObject,nFixCode);
    };

    public synchronized  long	GetLong (  int nFixCode)
    {
        this.CheckObj();

        return this._GetLong(this.m_nNativeObject,nFixCode);
    };

    public synchronized  String	GetString (  int nFixCode)
    {
        this.CheckObj();

        return this._GetString(this.m_nNativeObject,nFixCode);
    };

    public synchronized  String  GetItemString(  int nFixCode )
    {
        this.CheckObj();

        return this._GetItemString(this.m_nNativeObject,nFixCode);
    };

    public synchronized boolean   SetItemDouble(  int nFixCode , double      dValue   )
    {
        this.CheckObj();

        return this._SetItemDouble(this.m_nNativeObject,nFixCode,dValue);
    };

    public synchronized boolean   SetItemInt( int nFixCode  , int  nValue   )
    {
        this.CheckObj();

        return this._SetItemInt(this.m_nNativeObject,nFixCode,nValue);
    };

    public synchronized boolean   SetItemString( int nFixCode   , String astrData )
    {
        this.CheckObj();

        return this._SetItemString(this.m_nNativeObject,nFixCode,astrData);

    };

    public synchronized boolean   SetItemBuf( int nFixCode  , byte[] apData )
    {
        this.CheckObj();

        if (apData == null || apData.length ==0)
        {
            return false;
        }

        return this._SetItemBuf(this.m_nNativeObject,nFixCode,apData);
    };

    public synchronized boolean   More()
    {
        this.CheckObj();

        return  this._More(this.m_nNativeObject);
    }
}
