#ifdef _WIN32

#include "stdafx.h"

#else

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#endif // _WIN32

#include "BHKD_utilities.h"
#include <vector>


#include <float.h>
using namespace std;





namespace BHKD{

	float int_as_float( int in )
	{

		float lndata = *( ( float* ) &in );
		return lndata;

	}
	BOOL IsFloatValid(float f)
	{
#ifdef _WIN32
		int lnResult = _fpclass(f);
		switch (lnResult)
		{
		case _FPCLASS_SNAN:
		case _FPCLASS_QNAN:
		case _FPCLASS_NINF:
		case _FPCLASS_ND:
		case _FPCLASS_PD:
		case _FPCLASS_PINF:
			return FALSE;
			break;
		default:
			return TRUE;
		}
#else
	 
		 return TRUE;
	 
#endif // _WIN32

	}

	BOOL IsFloatZero(float f)
	{
		if (f < 0.000001 && f > -0.000001)
		{
			return TRUE;
		}

		return FALSE;
	}
	int float_as_int( float in )
	{
		int lndata = *( ( int* ) &in );
		return lndata;
	}

	CChannAlarmParam::CChannAlarmParam()
	{
		_bCharTrend=false;
		_bPhaseTrend=false;
		_bRegular=false;
		_bCharSlow=false;
		_bCharFast=false;
		_bPhaseSlow=false;
		_bPhaseFast=false;
		_fAlarmHH=.3;
		_fAlarmHL=.2;
		_fAlarmLH=.1;
		_fAlarmLL=.0;
		_iRegJudgeType=0;
		_iRegCharType=E_TH_ALLCHAR;
		_iRegAlarmSingleOrMulti=0;
		_fAlarm1= .1;
		_fAlarm2= .1;
		_fAlarm3= .1;
		_iResv1 = 0;
	}

	CChannAlarmParam& CChannAlarmParam::operator=(const CChannAlarmParam& chAlarmParam_)
	{
		_bCharTrend=chAlarmParam_._bCharTrend;
		_bPhaseTrend=chAlarmParam_._bPhaseTrend;
		_bRegular=chAlarmParam_._bRegular;
		_bCharSlow=chAlarmParam_._bCharSlow;
		_bCharFast=chAlarmParam_._bCharFast;
		_bPhaseSlow=chAlarmParam_._bPhaseSlow;
		_bPhaseFast=chAlarmParam_._bPhaseFast;
		for (int nloop=0;nloop<D_BHKD_ALARM_CHARTYPE_NUM;++nloop)
		{
			_pThLearnParamS[nloop]=chAlarmParam_._pThLearnParamS[nloop];
			_pThLearnParamF[nloop]=chAlarmParam_._pThLearnParamF[nloop];
			_pTrendParam[nloop]=chAlarmParam_._pTrendParam[nloop];
		}
		_fAlarmHH=chAlarmParam_._fAlarmHH;
		_fAlarmHL=chAlarmParam_._fAlarmHL;
		_fAlarmLH=chAlarmParam_._fAlarmLH;
		_fAlarmLL=chAlarmParam_._fAlarmLL;
		_iRegJudgeType=chAlarmParam_._iRegJudgeType;
		_iRegAlarmSingleOrMulti=chAlarmParam_._iRegAlarmSingleOrMulti;
		_iRegCharType=chAlarmParam_._iRegCharType;

		_fAlarm1=chAlarmParam_._fAlarm1;
		_fAlarm2=chAlarmParam_._fAlarm2;
		_fAlarm3=chAlarmParam_._fAlarm3;
		_iResv1=chAlarmParam_._iResv1;
		return *this;
	}


CAxisAlarmParam::CAxisAlarmParam()
{
	_bCheckF=false;
	_bCheckS=false;
	_bCheckTrend=false;
}

CAxisAlarmParam::~CAxisAlarmParam()
{

}

CAxisAlarmParam& CAxisAlarmParam::operator=(const CAxisAlarmParam& aParam_)
{
	_bCheckTrend=aParam_._bCheckTrend;
	_bCheckS=aParam_._bCheckS;
	_bCheckF=aParam_._bCheckF;
	_thLearnParamS=aParam_._thLearnParamS;
	_thLearnParamF=aParam_._thLearnParamF;
	_trendCheckParam=aParam_._trendCheckParam;
	return *this;
}

S_SetInfo::S_SetInfo()
{
	_iID=0;
	memset(_cCompany,0,D_BHKD_COMPANYNAME_LEN);
	memset(_cFactory,0,D_BHKD_FACTORYNAME_LEN);
	memset(_cSetID,0,D_BHKD_SETID_LEN);
	memset(_cIP,0,D_BHKD_IP_LEN);
	_iPort=7001;
	_iSendInterval=5;
	_iIfSend=-1;
	_iSudSendInterval=-1;
	_iAlarmSendInterval=-1;
	memset(_cTmIP,0,D_BHKD_IP_LEN);
	_iTmPort=7001;
	memset(_cParentID,0,D_BHKD_SETID_LEN);
	_iChildFlag=-1;
}

S_SetInfo& S_SetInfo::operator =(const S_SetInfo& sSetInfo_)
{
	_iID=sSetInfo_._iID;
	strncpy(_cCompany,sSetInfo_._cCompany,D_BHKD_COMPANYNAME_LEN-1);
	strncpy(_cFactory,sSetInfo_._cFactory,D_BHKD_FACTORYNAME_LEN-1);
	strncpy(_cSetID,sSetInfo_._cSetID,D_BHKD_SETID_LEN-1);
	strncpy(_cParentID,sSetInfo_._cParentID,D_BHKD_SETID_LEN-1);
	strncpy(_cIP,sSetInfo_._cIP,D_BHKD_IP_LEN-1);
	strncpy(_cTmIP,sSetInfo_._cTmIP,D_BHKD_IP_LEN-1);
	_iPort=sSetInfo_._iPort;
	_iTmPort=sSetInfo_._iTmPort;
	_iSendInterval=sSetInfo_._iSendInterval;
	_iIfSend=sSetInfo_._iIfSend;
	_iSudSendInterval=sSetInfo_._iSudSendInterval;
	_iAlarmSendInterval=sSetInfo_._iAlarmSendInterval;
	_iChildFlag=sSetInfo_._iChildFlag;
	return *this;
}


///////////////////////////////////////////////////////////////////////////

CCustomParamInfo::CCustomParamInfo()
{
	memset(_cSetID,0,D_BHKD_SETID_LEN);
	memset(_cFactory,0,D_BHKD_FACTORYNAME_LEN);
	memset(_cCompany,0,D_BHKD_COMPANYNAME_LEN);
	memset(_cTempletID,0,20);
	memset(_cSegName,0,100);
	_eDataType = E_CUSTOMPARAM_TIMEDOMAIN;
	_eUnitType= E_CUSTOMPARAM_TIME;
	_eSigAnaType= E_CUSTOMPARAM_TIMEWAVE;
	_eCharType = E_CUSTOMPARAM_PEAKVALUE;
	_iID = 0;
	_iSegNum = 0;
	_iSegStartNo = 0;
	_iPreProcType   = 0;
	_fDataStartValue = .0;
	_fDataEndValue  = .0;
	_fBandStartValue = .0;
	_fBandEndValue   = .0;
	this->_fPREPROC_B = .0;
	this->_fPREPROC_K = 1;
}

CCustomParamInfo::~CCustomParamInfo()
{
}

CCustomParamInfo& CCustomParamInfo::operator=(const CCustomParamInfo& customParamInfo_)
{
	strncpy(_cCompany,customParamInfo_._cCompany,D_BHKD_COMPANYNAME_LEN-1);
	strncpy(_cFactory, customParamInfo_._cFactory,D_BHKD_FACTORYNAME_LEN-1);
	strncpy(_cSetID, customParamInfo_._cSetID,D_BHKD_SETID_LEN-1);
	strncpy(_cTempletID, customParamInfo_._cTempletID,sizeof(_cTempletID)-1);
	strncpy(_cSegName, customParamInfo_._cSegName,sizeof(_cSegName)-1);
	_eDataType = customParamInfo_._eDataType;
	_eUnitType= customParamInfo_._eUnitType;
	_eSigAnaType= customParamInfo_._eSigAnaType;
	_eCharType = customParamInfo_._eCharType;
	_iID = customParamInfo_._iID;
	_iSegNum = customParamInfo_._iSegNum;
	_iSegStartNo = customParamInfo_._iSegStartNo;
	_iPreProcType   = customParamInfo_._iPreProcType;
	_fDataStartValue = customParamInfo_._fDataStartValue;
	_fDataEndValue  = customParamInfo_._fDataEndValue;
	_fBandStartValue = customParamInfo_._fBandStartValue;
    _fBandEndValue   = customParamInfo_._fBandEndValue;
	return *this;
}


//////////////////////////////////////////////////////////////////////////
CCustomAlarmParamInfo::CCustomAlarmParamInfo()
{
	memset(_cSegName,0,100);
	memset(_cSetID,0,D_BHKD_SETID_LEN);
	memset(_cFactory,0,D_BHKD_FACTORYNAME_LEN);
	memset(_cCompany,0,D_BHKD_COMPANYNAME_LEN);
	memset(_cAlarmTempletID,0,20);
	_iID = 0;
	_iSegNum=0;
	_iSegStartNo=0;
	_iJudgeType=0;
	_iAlarmType=0;
	_iIF_Alarm=0;
	_iAlarmGroup=0;
	_fAlarmLTH=.0;
	_fAlarmHTH=.0;
}
CCustomAlarmParamInfo::~CCustomAlarmParamInfo()
{
}
CCustomAlarmParamInfo& CCustomAlarmParamInfo::operator=(const CCustomAlarmParamInfo & customAlarmParamInfo_)
{
	strncpy(_cCompany,customAlarmParamInfo_._cCompany,D_BHKD_COMPANYNAME_LEN-1);
	strncpy(_cFactory, customAlarmParamInfo_._cFactory,D_BHKD_FACTORYNAME_LEN-1);
	strncpy(_cSetID, customAlarmParamInfo_._cSetID,D_BHKD_SETID_LEN-1);
	strncpy(_cAlarmTempletID, customAlarmParamInfo_._cAlarmTempletID,sizeof(_cAlarmTempletID)-1);
	strncpy(_cSegName, customAlarmParamInfo_._cSegName,sizeof(_cSegName)-1);
	_iID        =customAlarmParamInfo_._iID;
	_iSegStartNo=customAlarmParamInfo_._iSegStartNo;
	_iSegNum    =customAlarmParamInfo_._iSegNum;
	_iJudgeType =customAlarmParamInfo_._iJudgeType;
	_iAlarmType =customAlarmParamInfo_._iAlarmType;
	_iAlarmGroup=customAlarmParamInfo_._iAlarmGroup;
	_iIF_Alarm  =customAlarmParamInfo_._iIF_Alarm;
	_fAlarmLTH  =customAlarmParamInfo_._fAlarmLTH;
	_fAlarmHTH  =customAlarmParamInfo_._fAlarmHTH;
	return *this;
}



//////////////////////////////////////////////////////////////////////////

CChannLocations::CChannLocations()
{
	memset(_cCompany,0,D_BHKD_COMPANYNAME_LEN);
	memset(_cFactory,0,D_BHKD_FACTORYNAME_LEN);
	memset(_cSetID,0,D_BHKD_SETID_LEN);
	memset(_cPlantNo,0,D_BHKD_PLANTNO_LEN);
	memset(_cLocationName,0,100);
	memset(_cComment,0,100);
	_iBearingIDX=0;
	_iShaftNumber=0;
	_iSectionIDX=0;
	_iLocationIDX=0;
	_iBearingTblType=0;
}
CChannLocations::~CChannLocations()
{
}
CChannLocations& CChannLocations::operator=(const CChannLocations& channLocations_)
{
	strncpy(_cCompany,channLocations_._cCompany,D_BHKD_COMPANYNAME_LEN-1);
	strncpy(_cFactory, channLocations_._cFactory,D_BHKD_FACTORYNAME_LEN-1);
	strncpy(_cSetID, channLocations_._cSetID,D_BHKD_SETID_LEN-1);
	strncpy(_cPlantNo, channLocations_._cPlantNo,D_BHKD_PLANTNO_LEN-1);
	strncpy(_cLocationName, channLocations_._cLocationName,sizeof(_cLocationName)-1);
	strncpy(_cComment, channLocations_._cComment,sizeof(_cComment)-1);
	_iBearingIDX=channLocations_._iBearingIDX;
	_iShaftNumber=channLocations_._iShaftNumber;
	_iSectionIDX=channLocations_._iSectionIDX;
	_iLocationIDX=channLocations_._iLocationIDX;
	_iBearingTblType=channLocations_._iBearingTblType;
	return *this;
}



//////////////////////////////////////////////////////////////////////////
CChannSections::CChannSections()
{
	memset(_cCompany,0,D_BHKD_COMPANYNAME_LEN);
	memset(_cFactory,0,D_BHKD_FACTORYNAME_LEN);
	memset(_cSetID,0,D_BHKD_SETID_LEN);
	memset(_cPlantNo,0,D_BHKD_PLANTNO_LEN);
	memset(_cSectionName,0,100);
	memset(_cComment,0,100);
	_iSectionIDX=-1;
	_iGearBoxIDX=-1;
}
CChannSections::~CChannSections()
{
}
CChannSections& CChannSections::operator=(const CChannSections& channSections_)
{
	strncpy(_cCompany,channSections_._cCompany,D_BHKD_COMPANYNAME_LEN-1);
	strncpy(_cFactory, channSections_._cFactory,D_BHKD_FACTORYNAME_LEN-1);
	strncpy(_cSetID, channSections_._cSetID,D_BHKD_SETID_LEN-1);
	strncpy(_cPlantNo, channSections_._cPlantNo,D_BHKD_PLANTNO_LEN-1);
	strncpy(_cSectionName, channSections_._cSectionName,sizeof(_cSectionName)-1);
	strncpy(_cComment, channSections_._cComment,sizeof(_cComment)-1);
	_iSectionIDX=channSections_._iSectionIDX;
	_iGearBoxIDX=channSections_._iGearBoxIDX;
	return *this;
}


//////////////////////////////////////////////////////////////////////////
CBearingParamInfo::CBearingParamInfo()
{
	memset(_cBearingName,0,100);
	memset(_cComment,0,100);
	_fPitchDiameter=.0;
	_fElementDiameter=.0;
	_fContactAngle=.0;
	_fHousingDiameter=.0;
	_fBoreDiameter=.0;
	_iBearingIDX=0;
	_iBearingType=0;
	_iRowsNum=0;
	_iElementsNum=0;
	_iBearingCode=0;
}
CBearingParamInfo::~CBearingParamInfo()
{
}
CBearingParamInfo& CBearingParamInfo::operator=(const CBearingParamInfo& bearingParamInfo_)
{
	strncpy(_cBearingName, bearingParamInfo_._cBearingName,sizeof(_cBearingName)-1);
	strncpy(_cComment, bearingParamInfo_._cComment,sizeof(_cComment)-1);
	_fPitchDiameter=bearingParamInfo_._fPitchDiameter;
	_fElementDiameter=bearingParamInfo_._fElementDiameter;
	_fContactAngle=bearingParamInfo_._fContactAngle;
	_fHousingDiameter=bearingParamInfo_._fHousingDiameter;
	_fBoreDiameter=bearingParamInfo_._fBoreDiameter;
	_iBearingIDX=bearingParamInfo_._iBearingIDX;
	_iBearingType=bearingParamInfo_._iBearingType;
	_iRowsNum=bearingParamInfo_._iRowsNum;
	_iElementsNum=bearingParamInfo_._iElementsNum;
	_iBearingCode=bearingParamInfo_._iBearingCode;
	return *this;
}


//////////////////////////////////////////////////////////////////////////
CGearBoxParamInfo::CGearBoxParamInfo()
{
	memset(_cCompany,0,D_BHKD_COMPANYNAME_LEN);
	memset(_cFactory,0,D_BHKD_FACTORYNAME_LEN);
	memset(_cSetID,0,D_BHKD_SETID_LEN);
	memset(_cPlantNo,0,D_BHKD_PLANTNO_LEN);
	memset(_cGearBoxName,0,100);
	memset(_cComment,0,100);
	_iGearBoxIDX=0;
	_iGearBoxLevel=0;
	_iGearBoxType=0;
	_iDriverType=0;
	_iPlanetNum=0;
	_iGearNumSun=0;
	_iGearNumPlanet=0;
	_iGearNumGalaxy=0;
	_iIsSync=0;
	_iGearNumZ12=0;
	_iGearNumZ21=0;
	_iGearNumZ22=0;
	_iGearNumZ31=0;
	_iGearNumZ32=0;
	_iGearNumZ41=0;
	_iGearNumZ42=0;
	_iGearNumZ51=0;
	_iGearNumZ52=0;
	_iGearNumZ61=0;
}
CGearBoxParamInfo::~CGearBoxParamInfo()
{
}
CGearBoxParamInfo& CGearBoxParamInfo::operator=(const CGearBoxParamInfo& gearBoxParamInfo_)
{
	strncpy(_cCompany,gearBoxParamInfo_._cCompany,(D_BHKD_COMPANYNAME_LEN-1));
	strncpy(_cFactory, gearBoxParamInfo_._cFactory,(D_BHKD_FACTORYNAME_LEN-1));
	strncpy(_cSetID, gearBoxParamInfo_._cSetID,(D_BHKD_SETID_LEN-1));
	strncpy(_cPlantNo, gearBoxParamInfo_._cPlantNo,(D_BHKD_PLANTNO_LEN-1));
	strncpy(_cGearBoxName, gearBoxParamInfo_._cGearBoxName,sizeof(_cGearBoxName)-1);
	strncpy(_cComment, gearBoxParamInfo_._cComment,sizeof(_cComment)-1);
	_iGearBoxIDX=gearBoxParamInfo_._iGearBoxIDX;
	_iGearBoxLevel=gearBoxParamInfo_._iGearBoxLevel;
	_iGearBoxType=gearBoxParamInfo_._iGearBoxType;
	_iDriverType=gearBoxParamInfo_._iDriverType;
	_iPlanetNum=gearBoxParamInfo_._iPlanetNum;
	_iGearNumSun=gearBoxParamInfo_._iGearNumSun;
	_iGearNumPlanet=gearBoxParamInfo_._iGearNumPlanet;
	_iGearNumGalaxy=gearBoxParamInfo_._iGearNumGalaxy;
	_iIsSync=gearBoxParamInfo_._iIsSync;
	_iGearNumZ12=gearBoxParamInfo_._iGearNumZ12;
	_iGearNumZ21=gearBoxParamInfo_._iGearNumZ21;
	_iGearNumZ22=gearBoxParamInfo_._iGearNumZ22;
	_iGearNumZ31=gearBoxParamInfo_._iGearNumZ31;
	_iGearNumZ32=gearBoxParamInfo_._iGearNumZ32;
	_iGearNumZ41=gearBoxParamInfo_._iGearNumZ41;
	_iGearNumZ42=gearBoxParamInfo_._iGearNumZ42;
	_iGearNumZ51=gearBoxParamInfo_._iGearNumZ51;
	_iGearNumZ52=gearBoxParamInfo_._iGearNumZ52;
	_iGearNumZ61=gearBoxParamInfo_._iGearNumZ61;
	return *this;
}


/************************************************************************/
/*                                                                      */
/************************************************************************/

S_ChannInfo::S_ChannInfo()
{
	memset(_cChannID,0,D_BHKD_CHANNID_LEN);
	memset(_cChannNo,0,D_BHKD_CHANNNO_LEN);
	memset(_cFactory,0,D_BHKD_FACTORYNAME_LEN);
	memset(_cPlantNo,0,D_BHKD_PLANTNO_LEN);
	memset(_cCompany,0,D_BHKD_COMPANYNAME_LEN);
	memset(_cChannAlias,0,D_BHKD_CHANNALIAS_LEN);
	memset(_cAlarmTempID,0,20);
	memset(_cTempID ,0,20);
	memset(_cUnit ,0,20);	

	_iDataSource = 0;
	_charInfo.clear();
	_iLocationNo = -1;
	_iLocationIdx =-1;
	this->_iChannType = -1;
}

S_ChannInfo::S_ChannInfo(const S_ChannInfo& chInfo_)
{
	_iID=chInfo_._iID;
	strncpy(_cCompany,chInfo_._cCompany,D_BHKD_COMPANYNAME_LEN-1);
	strncpy(_cFactory,chInfo_._cFactory,D_BHKD_FACTORYNAME_LEN-1);
	strncpy(_cPlantNo,chInfo_._cPlantNo,D_BHKD_PLANTNO_LEN-1);
	strncpy(_cChannID,chInfo_._cChannID,D_BHKD_CHANNID_LEN-1);
	strncpy(_cChannNo,chInfo_._cChannNo,D_BHKD_CHANNNO_LEN-1);
	strncpy(_cChannAlias,chInfo_._cChannAlias,D_BHKD_CHANNALIAS_LEN-1);
	strncpy(_cUnit,chInfo_._cUnit,sizeof(_cUnit)-1);
	_iChannType=chInfo_._iChannType;
	_fSensitivity=chInfo_._fSensitivity;
	_fSensitivity1=chInfo_._fSensitivity1;
	_iList=chInfo_._iList;
	_iSensorType=chInfo_._iSensorType;
	_iRevType=chInfo_._iRevType;
	_bKeyIF=chInfo_._bKeyIF;
	_chAlarmParam=chInfo_._chAlarmParam;
	_fGapVoltage=chInfo_._fGapVoltage;
	_iCylinderNo=chInfo_._iCylinderNo;
	_iLocationIdx=chInfo_._iLocationIdx;
	_iMeassureDirection=chInfo_._iMeassureDirection;
	strncpy(_cTempID,chInfo_._cTempID,sizeof(_cTempID)-1);
	strncpy(_cAlarmTempID,chInfo_._cAlarmTempID,sizeof(_cAlarmTempID)-1);
	_iInfoType = chInfo_._iInfoType;
	if(chInfo_._charInfo.size() > 0)
		_charInfo = chInfo_._charInfo;
	else
		_charInfo.clear();
	_iDataSource = chInfo_._iDataSource;
	_iDataType   = chInfo_._iDataType;
	_fDCAmp      = chInfo_._fDCAmp;
	_fACAmp      = chInfo_._fACAmp;
	_iLocationIdx = chInfo_._iLocationIdx;
	_iLocationNo = chInfo_._iLocationNo;
}

S_ChannInfo::S_ChannInfo(const S_OldChannInfo & chInfo_)
{
	_iID=chInfo_._iID;
	strncpy(_cCompany,chInfo_._cCompany,(D_BHKD_COMPANYNAME_LEN-1));
	strncpy(_cFactory,chInfo_._cFactory,(D_BHKD_FACTORYNAME_LEN-1));
	strncpy(_cPlantNo,chInfo_._cPlantNo,(D_BHKD_PLANTNO_LEN-1));
	strncpy(_cChannID,chInfo_._cChannID,(D_BHKD_CHANNID_LEN-1));
	strncpy(_cChannNo,chInfo_._cChannNo,D_BHKD_PLANTNO_LEN-1);
	strncpy(_cChannAlias,chInfo_._cChannAlias,D_BHKD_CHANNALIAS_LEN-1);
	strncpy(_cUnit,chInfo_._cUnit,sizeof(_cUnit)-1);
	_iChannType=chInfo_._iChannType;
	_fSensitivity=chInfo_._fSensitivity;
	_fSensitivity1=chInfo_._fSensitivity1;
	_iList=chInfo_._iList;
	_iSensorType=chInfo_._iSensorType;
	_iRevType=chInfo_._iRevType;
	_bKeyIF=chInfo_._bKeyIF;
	_chAlarmParam=chInfo_._chAlarmParam;
	_fGapVoltage=chInfo_._fGapVoltage;
	_iCylinderNo=chInfo_._iCylinderNo;
	_iLocationIdx=chInfo_._iLocationIdx;
	_iMeassureDirection=chInfo_._iMeassureDirection;
	strncpy(_cTempID,chInfo_._cTempID,sizeof(_cTempID)-1);
	strncpy(_cAlarmTempID,chInfo_._cAlarmTempID,sizeof(_cAlarmTempID)-1);
	_iInfoType = chInfo_._iInfoType;
	_iDataSource = GE_DATA_SOURCE_ONLINE;
	_iDataType   = 0;
	_fDCAmp      = .0;
	_fACAmp      = .0;	
	_iLocationNo = -1;
	_iLocationIdx =-1;
	_charInfo.clear();
}

S_ChannInfo::S_ChannInfo(const S_ChannInfo * pChannInfo)
{
	_iID=pChannInfo->_iID;
	strncpy(_cCompany,pChannInfo->_cCompany,D_BHKD_COMPANYNAME_LEN-1);
	strncpy(_cFactory,pChannInfo->_cFactory,D_BHKD_FACTORYNAME_LEN-1);
	strncpy(_cPlantNo,pChannInfo->_cPlantNo,D_BHKD_PLANTNO_LEN-1);
	strncpy(_cChannID,pChannInfo->_cChannID,D_BHKD_CHANNID_LEN-1);
	strncpy(_cChannNo,pChannInfo->_cChannNo,D_BHKD_CHANNNO_LEN-1);
	strncpy(_cChannAlias,pChannInfo->_cChannAlias,D_BHKD_CHANNALIAS_LEN-1);
	strncpy(_cUnit,pChannInfo->_cUnit,sizeof(_cUnit)-1);
	_iChannType=pChannInfo->_iChannType;
	_fSensitivity=pChannInfo->_fSensitivity;
	_fSensitivity1 = pChannInfo->_fSensitivity1;
	_iList=pChannInfo->_iList;
	_iSensorType=pChannInfo->_iSensorType;
	_iRevType=pChannInfo->_iRevType;
	_bKeyIF=pChannInfo->_bKeyIF;
	_chAlarmParam=pChannInfo->_chAlarmParam;
	_fGapVoltage=pChannInfo->_fGapVoltage;
	_iCylinderNo=pChannInfo->_iCylinderNo;
	_iLocationIdx=pChannInfo->_iLocationIdx;
	_iMeassureDirection=pChannInfo->_iMeassureDirection;
	strncpy(_cTempID,pChannInfo->_cTempID,sizeof(_cTempID)-1);
	strncpy(_cAlarmTempID,pChannInfo->_cAlarmTempID,sizeof(_cAlarmTempID)-1);
	_iInfoType = pChannInfo->_iInfoType;
	_iDataSource = pChannInfo->_iDataSource;
	_iDataType   = pChannInfo->_iDataType;
	_fDCAmp      = pChannInfo->_fDCAmp;
	_fACAmp      = pChannInfo->_fACAmp;
	_iLocationIdx = pChannInfo->_iLocationIdx;
	_iLocationNo = pChannInfo->_iLocationNo;
	_charInfo.clear();
}

S_ChannInfo& S_ChannInfo::operator=(const S_ChannInfo& chInfo_)
{
	if(this == &chInfo_)
		return *this;

	_iID=chInfo_._iID;
	strncpy(_cCompany,chInfo_._cCompany,D_BHKD_COMPANYNAME_LEN-1);
	strncpy(_cFactory,chInfo_._cFactory,D_BHKD_FACTORYNAME_LEN-1);
	strncpy(_cPlantNo,chInfo_._cPlantNo,D_BHKD_PLANTNO_LEN-1);
	strncpy(_cChannID,chInfo_._cChannID,D_BHKD_CHANNID_LEN-1);
	strncpy(_cChannNo,chInfo_._cChannNo,D_BHKD_CHANNNO_LEN-1);
	strncpy(_cChannAlias,chInfo_._cChannAlias,D_BHKD_CHANNALIAS_LEN-1);
	strncpy(_cUnit,chInfo_._cUnit,sizeof(_cUnit)-1);
	_iChannType=chInfo_._iChannType;
	_fSensitivity=chInfo_._fSensitivity;
	_fSensitivity1 = chInfo_._fSensitivity1;
	_iList=chInfo_._iList;
	_iSensorType=chInfo_._iSensorType;
	_iRevType=chInfo_._iRevType;
	_bKeyIF=chInfo_._bKeyIF;
	_chAlarmParam=chInfo_._chAlarmParam;
	_fGapVoltage=chInfo_._fGapVoltage;
	_iCylinderNo=chInfo_._iCylinderNo;
	_iLocationIdx=chInfo_._iLocationIdx;
	_iMeassureDirection=chInfo_._iMeassureDirection;
	strncpy(_cTempID,chInfo_._cTempID,sizeof(_cTempID)-1);
	strncpy(_cAlarmTempID,chInfo_._cAlarmTempID,sizeof(_cAlarmTempID)-1);
	_iInfoType = chInfo_._iInfoType;
	if(chInfo_._charInfo.size() > 0)
		_charInfo = chInfo_._charInfo;
	else
		_charInfo.clear();
	_iDataSource = chInfo_._iDataSource;
	_iDataType   = chInfo_._iDataType;
	_fDCAmp      = chInfo_._fDCAmp;
	_fACAmp      = chInfo_._fACAmp;
	_iLocationIdx = chInfo_._iLocationIdx;
	_iLocationNo = chInfo_._iLocationNo;
	return *this;
}




S_CharInfo::S_CharInfo(int charIndex_, const string& charName_, const string& charUnit_) :
	_iCharIndex(charIndex_),
	_sCharName(charName_),
	_sCharUnit(charUnit_)
{
}

S_CharInfo::S_CharInfo(const S_CharInfo & charInfo_)
{
	_iCharIndex = charInfo_._iCharIndex;
	_sCharName  = charInfo_._sCharName;
	_sCharUnit  = charInfo_._sCharUnit;
}

S_CharInfo & S_CharInfo::operator=(const S_CharInfo & charInfo_)
{
	if(this == &charInfo_)
		return *this;

	_iCharIndex = charInfo_._iCharIndex;
	_sCharName  = charInfo_._sCharName;
	_sCharUnit  = charInfo_._sCharUnit;

	return *this;
}

int    S_CharInfo::GetCharIndex() const
{
	return _iCharIndex;
}

string S_CharInfo::GetCharName() const
{
	return _sCharName;
}

string S_CharInfo::GetCharUnit() const
{
	return _sCharUnit;
}

CAxisChannInfo::CAxisChannInfo()
{

}

CAxisChannInfo::~CAxisChannInfo()
{
}


CAxisChannInfo& CAxisChannInfo::operator=(const CAxisChannInfo& aChannInfo_)
{
	_iID=aChannInfo_._iID;
	strncpy(_cCompany,aChannInfo_._cCompany,D_BHKD_COMPANYNAME_LEN-1);
	strncpy(_cFactory,aChannInfo_._cFactory,D_BHKD_FACTORYNAME_LEN-1);
	strncpy(_cPlantNo,aChannInfo_._cPlantNo,D_BHKD_PLANTNO_LEN-1);
	strncpy(_cVerChann,aChannInfo_._cVerChann,D_BHKD_CHANNNO_LEN-1);
	strncpy(_cHorChann,aChannInfo_._cHorChann,D_BHKD_CHANNNO_LEN-1);
	_iLocationType=aChannInfo_._iLocationType;
	_iRotateDirection=aChannInfo_._iRotateDirection;
	_fAxisDia=aChannInfo_._fAxisDia;
	strncpy(_cLocation,aChannInfo_._cLocation,D_BHKD_CHANNALIAS_LEN-1);
	_axisAlarmParam=aChannInfo_._axisAlarmParam;
	return *this;
}

//--------------------------------------------------------//
S_AxisData::S_AxisData()
{
	_bCalc=false;
	_fCoorX=.0;
	_fCoorY=.0;
	_fHorDC=.0;
	_fHorGap=.0;
	_fRev=.0;
	_fVerDC=.0;
	_fVerGap=.0;
}

S_AxisData& S_AxisData::operator =(const S_AxisData& axisData_)
{
	_bCalc=axisData_._bCalc;
	_fCoorX=axisData_._fCoorX;
	_fCoorY=axisData_._fCoorY;
	_fHorDC=axisData_._fHorDC;
	_fHorGap=axisData_._fHorGap;
	_fVerDC=axisData_._fVerDC;
	_fVerGap=axisData_._fVerGap;
	_fRev=axisData_._fRev;
	return *this;
}

//---------------------------------------------------------//
S_PlantInfo::S_PlantInfo()
{
	memset(_cCompany, 0, D_BHKD_COMPANYNAME_LEN);
	memset(_cFactory, 0, D_BHKD_FACTORYNAME_LEN);
	memset(_cManufacturer, 0, 100);
	memset(_cSetID,   0, D_BHKD_SETID_LEN);
	memset(_cPlantID, 0, D_BHKD_PLANTID_LEN);
	memset(_cPlantNo, 0, D_BHKD_PLANTNO_LEN);
	_iVibChannNum=0;         //振动测点数目
	_iSmpFreq=1024;             //采样频率
	_iSmpNum=2048;              //采样点数
	_iDynChannNum=0;           //动态通道数目
	 _iProcChannNum=0;        //过程量测点数目
	 _piRev[0]=3000;                //额定转速1
	 _piRev[1]=3000;                //额定转速2
	 _piRev[2]=3000;
	 _piRev[3]=3000;
     _piRev[4]=3000;
	 _iGraphType=-1;           //概貌图类型
	 _iMachineType=1;         //设备类型
	 _iDriverType=1;          //驱动机类型
	 _iConnType=1;            //联结类型（联轴节类型）
	 _iBearingType=1;         //轴承类型
	 _iRotorType=1;           //转子类型
	 _iSealType=1;            //密封类型
	 _iWorkRevType=1;         //工作转速类型,是处于一阶临界转速附近
	 _iCritSpeed1st=500;        //一阶临界转速
	 _iCritSpeed2nd=1000;        //二阶临界转速
	 _iGraphBuffBytes=0;         //自制概貌图的字节数
	 _pGraphBuff=NULL;         //自制概貌图的BUFF指针
	 memset(_sVersion, 0, D_BHKD_VERSION_LEN);
	 strncpy(_sVersion, "1.0.0.0", D_BHKD_VERSION_LEN - 1);             //版本信息
     _iCylinderNum = 0;         //气缸数目
     _iDataSource = 0;
	 m_nDbId = 0;
}

S_PlantInfo::~S_PlantInfo()
{
	if(NULL!=_pGraphBuff)
		delete _pGraphBuff;
}



S_PlantInfo& S_PlantInfo::operator =(const S_PlantInfo& sPlantInfo_)
{
	strncpy(_cCompany,sPlantInfo_._cCompany, D_BHKD_COMPANYNAME_LEN - 1);
	strncpy(_cSetID,sPlantInfo_._cSetID, D_BHKD_SETID_LEN - 1);
	strncpy(_cPlantID,sPlantInfo_._cPlantID, D_BHKD_PLANTID_LEN - 1);
	strncpy(_cPlantNo,sPlantInfo_._cPlantNo, D_BHKD_PLANTNO_LEN - 1);
	strncpy(_cFactory,sPlantInfo_._cFactory, D_BHKD_FACTORYNAME_LEN - 1);
	strncpy(_cManufacturer,sPlantInfo_._cManufacturer, 100 - 1);
	_iVibChannNum=sPlantInfo_._iVibChannNum;
	_iDynChannNum=sPlantInfo_._iDynChannNum;
	_iSmpFreq=sPlantInfo_._iSmpFreq;
	_iSmpNum=sPlantInfo_._iSmpNum;
	_iProcChannNum=sPlantInfo_._iProcChannNum;
	memcpy(_piRev,sPlantInfo_._piRev,sizeof(int)*5);
	_iGraphType=sPlantInfo_._iGraphType;
	_iMachineType=sPlantInfo_._iMachineType;
	_iDriverType=sPlantInfo_._iDriverType;
	_iConnType=sPlantInfo_._iConnType;
	_iBearingType=sPlantInfo_._iBearingType;
	_iRotorType=sPlantInfo_._iRotorType;
	_iSealType=sPlantInfo_._iSealType;
	_iWorkRevType=sPlantInfo_._iWorkRevType;
	_iCritSpeed1st=sPlantInfo_._iCritSpeed1st;
	_iCritSpeed2nd=sPlantInfo_._iCritSpeed2nd;
	//_firstRunT=sPlantInfo_._firstRunT;
	_iCylinderNum=sPlantInfo_._iCylinderNum;
	_sRecipComprParam=sPlantInfo_._sRecipComprParam;
	_iDataSource = sPlantInfo_._iDataSource;
	strncpy(_sVersion, sPlantInfo_._sVersion, D_BHKD_VERSION_LEN - 1);
	return *this;
}

S_PlantInfoParam_Deprecated::S_PlantInfoParam_Deprecated()
{
	_fCrankShaftDia=0.1;
	_fConnRodLength=0.1;///连杆长度
	_fPistonDia=0.1;    ///活塞直径
	_fTotalPower=0.1;   ///总功率
	_fNomPi=0.1;        ///名义进气压力
	_fNomPo=0.1;        ///名义出气压力
	_fClv=0.1;          ///余隙（clearance）容积
	_fRes1=0.1;
	_fRes2=0.1;
	_iRes1=-1;
}

S_PlantInfoParam_Deprecated & S_PlantInfoParam_Deprecated::operator =(const S_PlantInfoParam_Deprecated& sPlantInfoParam_)
{
	_fCrankShaftDia=sPlantInfoParam_._fCrankShaftDia;
	_fConnRodLength=sPlantInfoParam_._fConnRodLength;///连杆长度
	_fPistonDia=sPlantInfoParam_._fPistonDia;    ///活塞直径
	_fTotalPower=sPlantInfoParam_._fTotalPower;   ///总功率
	_fNomPi=sPlantInfoParam_._fNomPi;        ///名义进气压力
	_fNomPo=sPlantInfoParam_._fNomPo;        ///名义出气压力
	_fClv=sPlantInfoParam_._fClv;          ///余隙（clearance）容积
	_fRes1=sPlantInfoParam_._fRes1;
	_fRes2=sPlantInfoParam_._fRes2;
	_iRes1=sPlantInfoParam_._iRes1;
	return *this;
}

S_PlantInfoParam::S_PlantInfoParam()
{
	_fCrankShaftDia=0.1;
	_fConnRodLength=0.1;///连杆长度
	_fPistonDia=0.1;    ///活塞直径
	_fTotalPower=0.1;   ///总功率
	_fNomPi=0.1;        ///名义进气压力
	_fNomPo=0.1;        ///名义出气压力
	_fClv=0.1;          ///余隙（clearance）容积
	_fRes1=0.1;
	_fRes2=0.1;
	_iRes1=0;

	_fPistonRodLength                  = 0.5;
	_fPistonThickness                  = 0.05;

	_fPistonCylinderWallGap            = 0.1;
	_fSensorLocation                   = 0.4;
	_fPistonCylinderWallGap_Deflection = 0.1;
	_fSensorLocation_Deflection        = 0.4;
}

S_PlantInfoParam::S_PlantInfoParam(const S_PlantInfoParam_Deprecated & sDeprecated_)
{
	_fCrankShaftDia         = sDeprecated_._fCrankShaftDia;
	_fConnRodLength         = sDeprecated_._fConnRodLength;///连杆长度
	_fPistonDia             = sDeprecated_._fPistonDia;    ///活塞直径
	_fTotalPower            = sDeprecated_._fTotalPower;   ///总功率
	_fNomPi                 = sDeprecated_._fNomPi;        ///名义进气压力
	_fNomPo                 = sDeprecated_._fNomPo;        ///名义出气压力
	_fClv                   = sDeprecated_._fClv;          ///余隙（clearance）容积
	_fRes1                  = sDeprecated_._fRes1;
	_fRes2                  = sDeprecated_._fRes2;
	_iRes1                  = sDeprecated_._iRes1;
	_fPistonRodLength                  = 0.5;
	_fPistonThickness                  = 0.05;
	_fPistonCylinderWallGap            = 0.1;
	_fSensorLocation                   = 0.4;
	_fPistonCylinderWallGap_Deflection = 0.1;
	_fSensorLocation_Deflection        = 0.4;
}

S_PlantInfoParam&S_PlantInfoParam::operator =(const S_PlantInfoParam& sPlantInfoParam_)
{
	_fCrankShaftDia=sPlantInfoParam_._fCrankShaftDia;
	_fConnRodLength=sPlantInfoParam_._fConnRodLength;///连杆长度
	_fPistonDia=sPlantInfoParam_._fPistonDia;    ///活塞直径
	_fTotalPower=sPlantInfoParam_._fTotalPower;   ///总功率
	_fNomPi=sPlantInfoParam_._fNomPi;        ///名义进气压力
	_fNomPo=sPlantInfoParam_._fNomPo;        ///名义出气压力
	_fClv=sPlantInfoParam_._fClv;          ///余隙（clearance）容积
	_fRes1=sPlantInfoParam_._fRes1;
	_fRes2=sPlantInfoParam_._fRes2;
	_iRes1=sPlantInfoParam_._iRes1;

	_fPistonRodLength                  = sPlantInfoParam_._fPistonRodLength;
	_fPistonThickness                  = sPlantInfoParam_._fPistonThickness;
	_fPistonCylinderWallGap            = sPlantInfoParam_._fPistonCylinderWallGap;
	_fSensorLocation                   = sPlantInfoParam_._fSensorLocation;
	_fPistonCylinderWallGap_Deflection =
		sPlantInfoParam_._fPistonCylinderWallGap_Deflection;
	_fSensorLocation_Deflection        =
		sPlantInfoParam_._fSensorLocation_Deflection;

	return *this;
}


S_RecipComprParam_Deprecated::S_RecipComprParam_Deprecated()
{
	/// 在_sPlantInfoParam 上原地依次调用S_PlantInfoParam_Deprecated的构建函数
	for (int nloop=0;nloop<PLANTINFO_PARAM_NUM;++nloop)
	{
		new(_sPlantInfoParam + nloop) S_PlantInfoParam_Deprecated();
	}
}


S_RecipComprParam_Deprecated & S_RecipComprParam_Deprecated::operator =(const S_RecipComprParam_Deprecated& sRecipComprParam_)
{
	for (int nloop=0;nloop<PLANTINFO_PARAM_NUM;++nloop)
	{
		_sPlantInfoParam[nloop]=sRecipComprParam_._sPlantInfoParam[nloop];
	}
	return *this;
}

S_RecipComprParam::S_RecipComprParam()
{
	/// 在_sPlantInfoParam 上原地依次调用S_PlantInfoParam的构建函数
	for (int nloop=0;nloop<PLANTINFO_PARAM_NUM;++nloop)
	{
		new(_sPlantInfoParam + nloop) S_PlantInfoParam();
	}
}

S_RecipComprParam::S_RecipComprParam(const S_RecipComprParam_Deprecated & sDeprecated_)
{
	/// 在_sPlantInfoParam 上原地依次调用S_PlantInfoParam(deprecated)的构建函数
	for (int nloop=0;nloop<PLANTINFO_PARAM_NUM;++nloop)
	{
		new(_sPlantInfoParam + nloop) S_PlantInfoParam(sDeprecated_._sPlantInfoParam[nloop]);
	}
}

S_RecipComprParam&S_RecipComprParam::operator =(const S_RecipComprParam& sRecipComprParam_)
{
	for (int nloop=0;nloop<PLANTINFO_PARAM_NUM;++nloop)
	{
		_sPlantInfoParam[nloop]=sRecipComprParam_._sPlantInfoParam[nloop];
	}
	return *this;
}






//---------------------------------------------------------//
CThreshold& CThreshold::operator =(const CThreshold& th_)
{
	_fThreshold1=th_._fThreshold1;
	_fThreshold2=th_._fThreshold2;
	_fThreshold3=th_._fThreshold3;
	_fThreshold4=th_._fThreshold4;
	_fThreshold5=th_._fThreshold5;
	_bThreshhold1=th_._bThreshhold1;
	return *this;
}

CThreshold::CThreshold()
{
	this->_bThreshhold1 = false;

	this->_fThreshold1 = 0;

	this->_fThreshold2 = 0;

	this->_fThreshold3 = 0;

	this->_fThreshold4 = 0;

	this->_fThreshold5 = 0;
	
}

CTrendCheckParam::CTrendCheckParam()
{
	_fParam1=.0;
	_fParam2=.0;
	_fParam3=.0;
	_fParam4=.0;
	_fParam5=.0;
}

CTrendCheckParam& CTrendCheckParam::operator=(const CTrendCheckParam& tParam_)
{
	_fParam1=tParam_._fParam1;
	_fParam2=tParam_._fParam2;
	_fParam3=tParam_._fParam3;
	_fParam4=tParam_._fParam4;
	_fParam5=tParam_._fParam5;
	return *this;
}


CThresholdLearnParam::CThresholdLearnParam()
{
	_fParam1=.1;
	_fParam2=.1;
	_fParam3=.1;
	_fParam4=.1;
	_fParam5=.1;
}

CThresholdLearnParam& CThresholdLearnParam::operator=(const CThresholdLearnParam& thLParam_)
{
	_fParam1=thLParam_._fParam1;
	_fParam2=thLParam_._fParam2;
	_fParam3=thLParam_._fParam3;
	_fParam4=thLParam_._fParam4;
	_fParam5=thLParam_._fParam5;
	return *this;
}

//-------------------------------------------//

S_VibCharValue::S_VibCharValue()
{
	_fCharAll=0;
	_fCharHalf=0;
	_fCharOne=0;
	_fCharTwo=0;
	_fCharThree=0;
	_fCharRes=0;
	_fDC=0;
	_fGap=0;
	_fPhaseHalf=0;
	_fPhaseOne=0;
	_fPhaseTwo=0;
	_fPhaseThree=0;
	_iSmpFreq=0;
	_iSmpNum=0;
	_iRev=0;
}

S_VibCharValue::~S_VibCharValue()
{
}


DATATYPE_CHAR S_VibCharValue::GetSpecTypeData(int iCharType_)
{
	float lfRet = 0;
	switch(iCharType_)
	{
	case GE_ALLCHAR:
		lfRet = _fCharAll;
		break;
	case GE_HALFCHAR:
		lfRet = _fCharHalf;
		break;
	case GE_ONECHAR:
		lfRet =  _fCharOne;
		break;
	case GE_TWOCHAR:
		lfRet = _fCharTwo;
		break;
	case GE_THREECHAR:
		lfRet = _fCharThree;
		break;
	case GE_DCCHAR:
		lfRet =  _fDC;
		break;
	case GE_GAP:
		lfRet = _fGap;
		break;
	case GE_RESCHAR:
		lfRet = _fCharRes;
		break;
	case GE_PHASECHARONE:
		lfRet =  _fPhaseOne;
		break;
	case GE_PHASECHARTWO:
		lfRet = _fPhaseTwo;
		break;
	case GE_PHASECHARTHREE:
		lfRet = _fPhaseThree;
		break;
	case GE_PHASECHARHALF:
		lfRet =  _fPhaseHalf;
		break;
	case GE_SAMPLEFREQ:
		lfRet =  _iSmpFreq;
		break;
	case GE_SAMPLENUM:
		lfRet = _iSmpNum;
		break;
	case GE_REV:
		lfRet = _iRev;
		break;
	default:
		lfRet = _fCharAll;
		break;
	}
	
	return lfRet;
}

void S_VibCharValue::SetSpecTypeData(float fData_,int iCharType_/* =GE_ALLCHAR */)
{
	if (!IsFloatValid(fData_))
	{


		fData_ = 0;
	}
	switch(iCharType_)
	{
	case GE_ALLCHAR:
		_fCharAll=fData_;
		break;
	case GE_HALFCHAR:
		_fCharHalf=fData_;
		break;
	case GE_ONECHAR:
		_fCharOne=fData_;
		break;
	case GE_TWOCHAR:
		_fCharTwo=fData_;
		break;
	case GE_THREECHAR:
		_fCharThree=fData_;
		break;
	case GE_DCCHAR:
		_fDC=fData_;
		break;
	case GE_GAP:
		_fGap=fData_;
		break;
	case GE_RESCHAR:
		_fCharRes=fData_;
		break;
	case GE_PHASECHARONE:
		_fPhaseOne=fData_;
		break;
	case GE_PHASECHARTWO:
		_fPhaseTwo=fData_;
		break;
	case GE_PHASECHARTHREE:
		_fPhaseThree=fData_;
		break;
	case GE_PHASECHARHALF:
		_fPhaseHalf=fData_;
		break;
	case GE_SAMPLEFREQ:
		_iSmpFreq = (int)fData_;
		break;
	case GE_SAMPLENUM:
//		ASSERT(fData_>0);
		_iSmpNum  = (int)fData_;
		break;
	case GE_REV:
		_iRev= (int)fData_;
		break;

	}
}

S_VibCharValue &S_VibCharValue::operator =(const S_VibCharValue& vibValue_)
{
	_fCharAll=vibValue_._fCharAll;
	_fCharHalf=vibValue_._fCharHalf;
	_fCharOne=vibValue_._fCharOne;
	_fCharTwo=vibValue_._fCharTwo;
	_fCharThree=vibValue_._fCharThree;
	_fCharRes=vibValue_._fCharRes;
	_fDC=vibValue_._fDC;
	_fGap=vibValue_._fGap;
	_fPhaseHalf=vibValue_._fPhaseHalf;
	_fPhaseOne=vibValue_._fPhaseOne;
	_fPhaseTwo=vibValue_._fPhaseTwo;
	_fPhaseThree=vibValue_._fPhaseThree;
	_iSmpFreq=vibValue_._iSmpFreq;
//	ASSERT(vibValue_._iSmpNum>0);
	_iSmpNum=vibValue_._iSmpNum;
	_iRev=vibValue_._iRev;
	return *this;
}
//------------------------------------------//





}

