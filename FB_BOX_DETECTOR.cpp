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

#include "FB_BOX_DETECTOR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_BOX_DETECTOR_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_FB_BOX_DETECTOR, g_nStringIdFB_BOX_DETECTOR)

const CStringDictionary::TStringId FORTE_FB_BOX_DETECTOR::scm_anDataInputNames[] = {g_nStringIdHIGH_SENSOR, g_nStringIdLOW_SENSOR};

const CStringDictionary::TStringId FORTE_FB_BOX_DETECTOR::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_FB_BOX_DETECTOR::scm_anDataOutputNames[] = {g_nStringIdBIG_BOX, g_nStringIdSMALL_BOX};

const CStringDictionary::TStringId FORTE_FB_BOX_DETECTOR::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TDataIOID FORTE_FB_BOX_DETECTOR::scm_anEIWith[] = {0, 1, 255};
const TForteInt16 FORTE_FB_BOX_DETECTOR::scm_anEIWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_FB_BOX_DETECTOR::scm_anEventInputNames[] = {g_nStringIdEI1, g_nStringIdRESET};

const TDataIOID FORTE_FB_BOX_DETECTOR::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_FB_BOX_DETECTOR::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FB_BOX_DETECTOR::scm_anEventOutputNames[] = {g_nStringIdCNF};


const SFBInterfaceSpec FORTE_FB_BOX_DETECTOR::scm_stFBInterfaceSpec = {
  2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  2, scm_anDataInputNames, scm_anDataInputTypeIds,
  2, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_FB_BOX_DETECTOR::setInitialValues() {
}

void FORTE_FB_BOX_DETECTOR::alg_BIG(void) {
  st_BIG_BOX() = true;
  st_SMALL_BOX() = false;
}

void FORTE_FB_BOX_DETECTOR::alg_SMALL(void) {
  st_BIG_BOX() = false;
  st_SMALL_BOX() = true;
}

void FORTE_FB_BOX_DETECTOR::alg_RESET(void) {
  st_BIG_BOX() = false;
  st_SMALL_BOX() = false;
}


void FORTE_FB_BOX_DETECTOR::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_BOX_DETECTOR::enterStateBig_Box(void) {
  m_nECCState = scm_nStateBig_Box;
  alg_BIG();
  sendOutputEvent(scm_nEventCNFID);
}

void FORTE_FB_BOX_DETECTOR::enterStateSmall_Box(void) {
  m_nECCState = scm_nStateSmall_Box;
  alg_SMALL();
  sendOutputEvent(scm_nEventCNFID);
}

void FORTE_FB_BOX_DETECTOR::enterStateReset(void) {
  m_nECCState = scm_nStateReset;
  alg_RESET();
  sendOutputEvent(scm_nEventCNFID);
}


void FORTE_FB_BOX_DETECTOR::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(((st_HIGH_SENSOR() == true) && (st_LOW_SENSOR() == true)))
          enterStateBig_Box();
        else
        if(((st_HIGH_SENSOR() == false) && (st_LOW_SENSOR() == true)))
          enterStateSmall_Box();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateBig_Box:
        if(scm_nEventRESETID == pa_nEIID)
          enterStateReset();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSmall_Box:
        if(scm_nEventRESETID == pa_nEIID)
          enterStateReset();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateReset:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; // 0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(bTransitionCleared);
}


