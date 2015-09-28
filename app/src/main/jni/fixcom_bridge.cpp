#include "fixcom_bridge.h"
#include <FixCommA/FixCommA.h>
#include "BHKD_utilities.h"
#include "FixDef.h"
#include "FixDef_Field.h"
#include <vector>
using namespace BHKD;
int test()
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
				if (lnLoopCount++>100)
				{
					return 1;
				}
				
			}

		}
	}

	return 0;
}