#ifndef RTN_H
#define RTN_H

#include "basic_types.h"
#include "instrumentation_arguments.h"
#include "pin_objs.h"
//#include "reg32.h"
//#include "img.h"
//#include "sec.h"
//#include "sym.h"

typedef VOID(* RTN_INSTRUMENT_CALLBACK )(RTN rtn, VOID *v);

SEC RTN_Sec (RTN x);
RTN RTN_Next (RTN x);
RTN RTN_Prev (RTN x);
RTN RTN_Invalid (VOID);
BOOL RTN_Valid (RTN x);
void RTN_Name (RTN x, CHAR *name);
SYM RTN_Sym (RTN x);
AFUNPTR RTN_Funptr (RTN x);
INT32 RTN_Id (RTN x);
VOID RTN_AddInstrumentFunction (RTN_INSTRUMENT_CALLBACK fun, VOID *val);
USIZE RTN_Range (RTN rtn);
USIZE RTN_Size (RTN rtn);
//LOCALFUN RTN CreateRtnOriginatedFromIfunc (ADDRINT actualFuncAddr, string name);
VOID RTN_FindNameByAddress (ADDRINT address, CHAR *name);
RTN RTN_FindByAddress (ADDRINT address);
RTN RTN_FindByName (IMG img, const CHAR *name);
VOID RTN_Open (RTN rtn);
VOID RTN_Close (RTN rtn);
INS RTN_InsHead (RTN rtn);
INS RTN_InsHeadOnly (RTN rtn);
INS RTN_InsTail (RTN rtn);
UINT32 RTN_NumIns (RTN rtn);
VOID RTN_InsertCall (RTN rtn, IPOINT action, AFUNPTR funptr,...);
ADDRINT RTN_Address (RTN rtn);
RTN RTN_CreateAt (ADDRINT address, CHAR *name);
BOOL RTN_IsDynamic (RTN rtn);
VOID DeleteRtnCheckHistory (VOID);
BOOL RTN_IsSafeForProbedInsertion (RTN rtn);
//BOOL RTN_IsSafeForProbedInsertionEx (RTN rtn, PROBE_MODE mode);
//BOOL RTN_IsSafeForProbedReplacement (RTN rtn);
//BOOL RTN_IsSafeForProbedReplacementEx (RTN rtn, PROBE_MODE mode);
AFUNPTR RTN_ReplaceSignatureProbed (RTN replacedRtn, AFUNPTR replacementFun,...);
//AFUNPTR RTN_ReplaceSignatureProbedEx (RTN replacedRtn, PROBE_MODE mode, AFUNPTR replacementFun,...);
VOID RTN_InsertCallProbed (RTN orgRtn, IPOINT action, AFUNPTR funptr,...);
//VOID RTN_InsertCallProbedEx (RTN orgRtn, IPOINT action, PROBE_MODE mode, AFUNPTR funptr,...);
//INT32 RTN_CodeRangesProbed (RTN rtn, INT32 num, PIN_CODE_RANGE *buffer);
AFUNPTR RTN_Replace (RTN replacedRtn, AFUNPTR replacementFun);
AFUNPTR RTN_ReplaceSignature (RTN replacedRtn, AFUNPTR replacementFun,...);
AFUNPTR RTN_ReplaceProbed (RTN replacedRtn, AFUNPTR replacementFun);
//AFUNPTR RTN_ReplaceProbedEx (RTN replacedRtn, PROBE_MODE mode, AFUNPTR replacementFun);


#endif
