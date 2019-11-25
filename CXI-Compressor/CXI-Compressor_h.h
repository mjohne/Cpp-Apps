

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Fri Aug 07 11:50:58 2009
 */
/* Compiler settings for .\CXI-Compressor.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __CXI2DCompressor_h_h__
#define __CXI2DCompressor_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICXICompressor_FWD_DEFINED__
#define __ICXICompressor_FWD_DEFINED__
typedef interface ICXICompressor ICXICompressor;
#endif 	/* __ICXICompressor_FWD_DEFINED__ */


#ifndef __CXICompressor_FWD_DEFINED__
#define __CXICompressor_FWD_DEFINED__

#ifdef __cplusplus
typedef class CXICompressor CXICompressor;
#else
typedef struct CXICompressor CXICompressor;
#endif /* __cplusplus */

#endif 	/* __CXICompressor_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __CXICompressor_LIBRARY_DEFINED__
#define __CXICompressor_LIBRARY_DEFINED__

/* library CXICompressor */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_CXICompressor;

#ifndef __ICXICompressor_DISPINTERFACE_DEFINED__
#define __ICXICompressor_DISPINTERFACE_DEFINED__

/* dispinterface ICXICompressor */
/* [uuid] */ 


EXTERN_C const IID DIID_ICXICompressor;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E576B3FA-26A8-4403-A39B-A62179D5E1AA")
    ICXICompressor : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ICXICompressorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICXICompressor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICXICompressor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICXICompressor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICXICompressor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICXICompressor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICXICompressor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICXICompressor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ICXICompressorVtbl;

    interface ICXICompressor
    {
        CONST_VTBL struct ICXICompressorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICXICompressor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICXICompressor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICXICompressor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICXICompressor_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICXICompressor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICXICompressor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICXICompressor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICXICompressor_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CXICompressor;

#ifdef __cplusplus

class DECLSPEC_UUID("716F7118-EA54-4474-A134-CC153DA99D6E")
CXICompressor;
#endif
#endif /* __CXICompressor_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


