package com.mimimao.eric.fixcomma;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

/**
 * Created by eric on 2015/9/29.
 */
public class S_VibCharValue {
    float _fCharAll= .0f;   //通频特征值
    float _fCharHalf= .0f;  //1/2分频特征值
    float _fCharOne= .0f;   //1倍频特征值
    float _fCharTwo= .0f;   //2倍频特征值
    float _fCharThree= .0f; //3倍频特征值
    float _fCharRes= .0f;   //残振特征值
    float _fDC= .0f;        //直流量
    float _fGap= .0f;       //间隙值
    float _fPhaseHalf= .0f; //1/2分频相位
    float _fPhaseOne= .0f;  //1倍频相位
    float _fPhaseTwo= .0f;  //2倍频相位
    float _fPhaseThree= .0f;//3倍频相位
    int  _iSmpFreq= 0;   //采样频率
    int  _iSmpNum= 0;    //采样点数
    int  _iRev= 0;       //转速
    public byte[] getBytes()
    {
        ByteBuffer buffer = ByteBuffer.allocate(1000);
        buffer.order(ByteOrder.LITTLE_ENDIAN);
        buffer.putFloat(this._fCharAll);
        buffer.putFloat(this._fCharHalf);
        buffer.putFloat(this._fCharOne);
        buffer.putFloat(this._fCharTwo);
        buffer.putFloat(this._fCharThree);
        buffer.putFloat(this._fCharRes);
        buffer.putFloat(this._fDC);
        buffer.putFloat(this._fGap);
        buffer.putFloat(this._fPhaseHalf);
        buffer.putFloat(this._fPhaseOne);
        buffer.putFloat(this._fPhaseTwo);
        buffer.putFloat(this._fPhaseThree);
        buffer.putInt(this._iSmpFreq);
        buffer.putInt(this._iSmpNum);
        buffer.putInt(this._iRev);
        byte[] bytes = buffer.array();
        return bytes;
    }
}
