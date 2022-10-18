/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FB_BOX_DETECTOR
 *** Description: Template for a Basic Function Block Type
 *** Version:
***     1.0: 2022-10-13/AK123957 -  - 
 *************************************************************************/

#ifndef _FB_BOX_DETECTOR_H_
#define _FB_BOX_DETECTOR_H_

#include "basicfb.h"
#include "forte_bool.h"
#include "forte_array_at.h"


class FORTE_FB_BOX_DETECTOR: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_FB_BOX_DETECTOR)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventEI1ID = 0;
  static const TEventID scm_nEventRESETID = 1;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventCNFID = 0;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

virtual void setInitialValues();
  CIEC_BOOL &st_HIGH_SENSOR() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  }
  
  CIEC_BOOL &st_LOW_SENSOR() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  }
  
  CIEC_BOOL &st_BIG_BOX() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  
  CIEC_BOOL &st_SMALL_BOX() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  }
  

  void alg_BIG(void);
  void alg_SMALL(void);
  void alg_RESET(void);

  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateBig_Box = 1;
  static const TForteInt16 scm_nStateSmall_Box = 2;
  static const TForteInt16 scm_nStateReset = 3;
  
  void enterStateSTART(void);
  void enterStateBig_Box(void);
  void enterStateSmall_Box(void);
  void enterStateReset(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(1, 2, 2, 0, 0);

public:
  FORTE_FB_BOX_DETECTOR(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_FB_BOX_DETECTOR() = default;
};

#endif // _FB_BOX_DETECTOR_H_


