//jb commenting out currently for testing purposes
///*****************************************************************************
// * File Name : pal_osMem.c
// *
// * Brief	 : OsMEM Services Source File for BIOS
// *     This file implements OS abstraction services for variable length heap
// *   memory management operations. Essentially these APIs are wrapper functions
// *   for BIOS APIs.
// *
// * Copyright (C) 2009 -2010 Texas Instruments Incorporated - http://www.ti.com/ 
// * 
// * 
// *  Redistribution and use in source and binary forms, with or without 
// *  modification, are permitted provided that the following conditions 
// *  are met:
// *
// *    Redistributions of source code must retain the above copyright 
// *    notice, this list of conditions and the following disclaimer.
// *
// *    Redistributions in binary form must reproduce the above copyright
// *    notice, this list of conditions and the following disclaimer in the 
// *    documentation and/or other materials provided with the   
// *    distribution.
// *
// *    Neither the name of Texas Instruments Incorporated nor the names of
// *    its contributors may be used to endorse or promote products derived
// *    from this software without specific prior written permission.
// *
// *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *
//******************************************************************************/
//
//
//#include <std.h>
//#include "mem.h"
//#include "pal_os.h"
//#include "pal_osMem.h"
//
//#ifndef MEM_HEADERSIZE
//#define MEM_HEADERSIZE (sizeof(MEM_Header))
//#endif
//
///* Init PAL OSMEM module */
//PAL_Result PAL_osMemInit(Ptr param)
//{
//    if (NULL != param) {
//        param = param;
//    }
//
//    /* No bookkeep required */
//    return (PAL_SOK);
//}
//
///* Create/Define PAL OSMEM Segment
// *
// * Implementation Notes:
// * "name" parameter is ignored and not used
// * "attrs" parameter is ignored and not used
// */
///* ARGSUSED */
//PAL_Result PAL_osMemSegDefine(const char* name,
//                              Uint32 startAddr,
//                              Uint32 numBytes,
//                              PAL_OsMemAttrs * const attrs,
//                              Uint32 * const segId)
//{
//    MEM_Attrs   mem_attrs;
//    PAL_Result  status = PAL_OS_ERROR_INVALID_PARAM;
//
//    /* Check if the address is correct */
//    if ((startAddr != NULL) && (segId != NULL))
//    {
//        /* Check if the address & the length is aligned */
//        if((( 0 == (startAddr % MEM_HEADERSIZE))) && (0 == (numBytes % MEM_HEADERSIZE)))
//        {
//            *segId = MEM_define((Ptr) startAddr, numBytes, &mem_attrs);
//            status = PAL_SOK;
//        }
//
//    }
//
//    return (status);
//}
//
//
///* Delete/Undefine PAL OSMEM Segment
// * If segId=0, error is returned as default pool cannot be deleted
// */
//PAL_Result PAL_osMemSegUndefine(Uint32 segId)
//{
//    MEM_undefine(segId);
//
//    return (PAL_SOK);
//}
//
//
///* Allocate memory from a PAL OSMEM pool
// *
// * Implementation Notes:
// * "alignment" parameter is not explicitely honoured - it is assumed that
// * BIOS variable block allocator aligns memory by default to "int"
// */
//PAL_Result PAL_osMemAlloc(Uint32 segId,
//                          Uint32 numBytes,
//                          Uint16 alignment,
//                          Ptr * const memAddr)
//{
//    PAL_Result status = PAL_SOK;
//    Int         align = 0;
//
//    if(0 == alignment)
//    {
//        align = 1;
//    }
//    else
//    {
//        align = alignment;
//    }
//
//
//    if(NULL == memAddr)
//    {
//        status = PAL_OS_ERROR_INVALID_PARAM;
//    } else {
//        *memAddr = MEM_calloc(segId, numBytes, align);
//    }
//
//
//    return status;
//}
//
//
///* Free memory allocated from PAL OSMEM pool */
//PAL_Result PAL_osMemFree(Uint32 segId, Ptr memAddr, Uint32 numBytes)
//{
//    PAL_Result status = PAL_SOK;
//    Bool       mem_status = FALSE;
//
//    mem_status = MEM_free(segId, memAddr, numBytes);
//
//    if(TRUE != mem_status)
//    {
//        status = PAL_OS_ERROR_INVALID_PARAM;
//    }
//
//    return status;
//}
//
//
///* PAL OS Memory Copy */
//PAL_Result PAL_osMemCopy(Ptr dest, const Ptr src, Uint32 numBytes)
//{
//    Char        *tmp = (Char *) dest, *s = (Char *) src;
//    PAL_Result  retVal = PAL_SOK;
//
//    if (((0 == numBytes) || (NULL == dest)) || (NULL ==src))    {
//        retVal = PAL_OS_ERROR_INVALID_PARAM;
//    } else {
//        while (numBytes--)  {
//            *tmp = *s;
//            tmp++;
//            s++;
//        }
//    }
//    return (retVal);
//}
//
//
///* PAL OS Memory Set */
//PAL_Result PAL_osMemSet(Ptr memAddr, Char fillVal, Uint32 numBytes)
//{
//    Char *xs =  (Char *) memAddr;
//    PAL_Result  retVal = PAL_SOK;
//
//    if ((numBytes == 0) || (NULL == memAddr))   {
//        retVal = PAL_OS_ERROR_INVALID_PARAM;
//    } else {
//        while (numBytes--)  {
//            *xs++ = fillVal;
//        }
//    }
//    return (retVal);
//}
//
///* PAL OS Memory Lock
// * This function is not supported in PrOS and always returns PAL_OS_ERROR_NOT_SUPPORTED error
// */
///* ARGSUSED */
//PAL_Result PAL_osMemLock(Ptr memAddr, Uint32 byteLen, Uint32 * const cookie)
//{
//    return (PAL_OS_ERROR_NOT_SUPPORTED);
//}
//
///* PAL OS Memory Un-Lock
// * This function is not supported in PrOS and always returns PAL_OS_ERROR_NOT_SUPPORTED error
// */
///* ARGSUSED */
//PAL_Result PAL_osMemUnlock(Ptr memAddr, Uint32 byteLen, Uint32 * const cookie)
//{
//    return (PAL_OS_ERROR_NOT_SUPPORTED);
//}
//
//
///* PAL OS Memory Virtual To Physical
// *
// */
///* ARGSUSED */
//Uint32 PAL_osMemVirt2Phy(Ptr virtAddress)
//{
//    return ((Uint32)virtAddress);
//}
//
//
///* PAL OS Memory Physical To Virtual
// *
// */
//Ptr PAL_osMemPhy2Virt(Uint32 phyAddress)
//{
//    return ((Ptr)phyAddress);
//}
//
//
///* PAL OS Memory Report
// *
// */
///* ARGSUSED */
//PAL_Result PAL_osMemReport(const Uint32 segId, PAL_OsMemReport * const report, Char* const buf)
//{
//    return (PAL_OS_ERROR_NOT_SUPPORTED);
//}
