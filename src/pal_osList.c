////jb commenting out currently for testing purposes
///*****************************************************************************
// * File Name : pal_osList.c
// *
// * Brief	 : OsLIST Services Source File
// *    This file implements APIs for handling simple bi-directional linked
// *   list that works with arbitrary data objects in a thread-safe manner.
// *   Movement of elements within the OsLIST is FIFO mode.
// *
// *   Only requirement on Elements strung onto the OsLIST is that they
// *   must begin with an OsLIST header comprising of a forward and reverse
// *   pointers. No Memory allocation or freeing is performed by these APIs.
// *   Memory allocation/freeing must be handled outside by the caller
// *
// *   The functions are inherently protected from interrupts. A non protected version
// *   is also available (with _NP_ in the name)
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
//#include "pal_osList.h"
//#include "pal_osProtect.h"
//
///**************************************************
// * Protected functions
// **************************************************/
//
// #ifndef TRUE
// #define TRUE  (1U)
// #define FALSE (0U)
// #endif
//
///* PAL OS List Append */
//void PAL_osListAppend (Ptr hListHead, Ptr hNewNode)
//{
//    Uint32  imask = 0;
//
//	if ((NULL != hListHead) && (NULL != hNewNode)) {
//	    PAL_OsListNodeHeader *currNode = (PAL_OsListNodeHeader *)hNewNode;
//    	PAL_OsListNodeHeader *headNode = (PAL_OsListNodeHeader *)hListHead;
//	    PAL_OsListNodeHeader *tempNode;
//
//    	PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT,&imask);
//    	if((NULL    !=  currNode)&&(NULL    !=  headNode))    
//	    {
//    	    currNode->next = headNode;
//	        currNode->prev = headNode->prev;
//    	    tempNode = headNode->prev;
//	        tempNode->next = currNode;
//        	headNode->prev = currNode;
//    	}
//    	PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, imask);
//	}
//}
//
///* PAL OS List Remove Head */
//Ptr PAL_osListRemoveHead(Ptr hListHead)
//{
//    Uint32                      imask;
//    PAL_OsListNodeHeader*   hTempNode=  NULL;
//    Bool    removeHeadLoopFlag   =  FALSE;
//
//    do 
//    {
//        if (NULL == hListHead) {
//            break;
//        }
//
//        PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT,&imask);
//        hTempNode = PAL_osListDequeue(hListHead);
//        PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, imask);
//        removeHeadLoopFlag  =   FALSE;
//    } while(removeHeadLoopFlag);
//
//    return ((Ptr)hTempNode);
//}
//
///* PAL OS List Insert */
//void PAL_osListInsert (Ptr hListNode, Ptr hNewNode)
//{
//    Uint32  cookie;   
//
//    PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT,&cookie);
//    if((NULL    !=  hListNode)&&(NULL    !=  hNewNode))
//    {
//		PAL_OsListNodeHeader *currNode = (PAL_OsListNodeHeader *)hNewNode;
//	    PAL_OsListNodeHeader *prevNode = (PAL_OsListNodeHeader *)hListNode;
//    	PAL_OsListNodeHeader *tempNode;
//        if(NULL != prevNode->prev)
//        {
//            currNode->prev = prevNode;
//            currNode->next = prevNode->next;
//            prevNode->next= currNode;
//            tempNode = currNode->next;
//            tempNode->prev = currNode;
//        }
//    }
//    PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//	return;
//}
//
///* PAL OS List Remove */
//Ptr PAL_osListRemove(Ptr hListNode)
//{
//    Uint32  imask;
//
//    PAL_OsListNodeHeader *tempNode;
//    PAL_OsListNodeHeader *retNode;
//    PAL_OsListNodeHeader *currNode = (PAL_OsListNodeHeader *)hListNode;
//    Bool    listremoveLoopFlag  =   FALSE;
//    PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT,&imask);
//    do 
//    {
//        if(NULL ==  currNode)
//        {
//            retNode =   NULL;
//            break;
//        }
//        if (currNode->next == currNode)
//        {
//            retNode =   currNode;
//            break;
//        }
//        if((NULL != currNode->next) && (NULL != currNode->prev))
//        {
//            retNode = currNode->next;
//            tempNode = currNode->prev;
//            tempNode->next = currNode->next;
//            tempNode = currNode->next;
//            tempNode->prev = currNode->prev;
//            currNode->next = currNode->prev = currNode;
//        }    
//        listremoveLoopFlag  =   FALSE;  
//    } while(listremoveLoopFlag);
//
//    PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, imask);
//
//    return ((Ptr)retNode);
//}
//
///* PAL OS List Prepend */
//Ptr PAL_osListPrepend (Ptr hListHead, Ptr hNewNode)
//{
//    Uint32  imask;
//
//    PAL_OsListNodeHeader *tempNode;
//    PAL_OsListNodeHeader *currNode = (PAL_OsListNodeHeader *)hNewNode;
//    PAL_OsListNodeHeader *headNode = (PAL_OsListNodeHeader *)hListHead;
//
//    PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT,&imask);
//    if(NULL !=  currNode)
//    {
//        if(NULL ==  headNode)
//        {
//            currNode->next = currNode->prev = currNode;
//        }
//        else
//        {
//            if(NULL != headNode->prev)
//            {
//                tempNode        = headNode->prev;
//                tempNode->next  = currNode;
//                currNode->next  = headNode;
//                currNode->prev  = headNode->prev;
//                headNode->prev  = currNode;
//            }
//        }
//    }
//    PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, imask);
//    return ((Ptr)currNode);
//}
//
///* PAL OS List Enqueue */
//void PAL_osListEnqueue(PAL_OsListNodeHeader * const queue, Ptr elem)
//{
//    Uint32  imask;
//    PAL_OsListNodeHeader    *enqueuePrev    =   NULL;
//
//    PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT,&imask);
//    if(NULL !=  queue)
//    {
//        enqueuePrev = queue->prev;
//    }
//    if((NULL    !=  enqueuePrev)&&(NULL != elem))
//    {
//        if(NULL != enqueuePrev->next)
//        {
//            ((PAL_OsListNodeHeader *)elem)->next = (Ptr) queue;
//            ((PAL_OsListNodeHeader *)elem)->prev = enqueuePrev;
//            enqueuePrev->next = (PAL_OsListNodeHeader *)elem;
//            queue->prev = (PAL_OsListNodeHeader *)elem;
//        }
//    }
//    PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, imask);
//}
//
///* PAL OS List Dequeue */
//Ptr PAL_osListDequeue(PAL_OsListNodeHeader * const queue)
//{
//    Uint32  imask;
//    PAL_OsListNodeHeader    *dequeueElem = NULL;
//    PAL_OsListNodeHeader    *dequeueNext;
//
//    PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT,&imask);
//    if(NULL !=  queue)
//    {
//        if(NULL != queue->next)
//        {
//            dequeueElem = queue->next;
//			if (NULL != dequeueElem) {
//	            if(NULL != dequeueElem->next)
//	            {
//	                dequeueNext = dequeueElem->next;
//	                queue->next = dequeueNext;
//	                dequeueNext->prev = (Ptr)queue;
//	            }
//			}
//        }
//    }
//    PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, imask);
//
//    return ((Ptr)dequeueElem);
//}
//
///* PAL OS List Empty? */
//Bool PAL_osListIsEmpty(Ptr hListHead)
//{
//    Uint32  imask;
//    Bool listIsEmptyretCode;
//
//    PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT,&imask);
//    if(NULL !=  hListHead)
//    {
//        if (((PAL_OsListNodeHeader*) hListHead)->next == ((PAL_OsListNodeHeader*) hListHead)) {
//            listIsEmptyretCode = TRUE;
//        } else {
//            listIsEmptyretCode = FALSE;
//        }
//    }
//    PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, imask);
//    return (listIsEmptyretCode);
//}
//
///**************************************************
// * Non - Protected functions
// **************************************************/
//
///* PAL OS List Append */
//void PAL_osList_NP_Append (Ptr hListHead, Ptr hNewNode)
//{
//    PAL_OsListNodeHeader *appendCurrNode = (PAL_OsListNodeHeader *)hNewNode;
//    PAL_OsListNodeHeader *appendHeadNode = (PAL_OsListNodeHeader *)hListHead;
//    PAL_OsListNodeHeader *appendTempNode;
//    if((NULL    !=  appendHeadNode)&&(NULL  !=  appendCurrNode))
//    {
//        appendCurrNode->next = appendHeadNode;
//        appendCurrNode->prev = appendHeadNode->prev;
//        appendTempNode = appendHeadNode->prev;
//        appendTempNode->next = appendCurrNode;
//        appendHeadNode->prev = appendCurrNode;
//    }
//}
//
///* PAL OS List Remove Head */
//Ptr PAL_osList_NP_RemoveHead(Ptr hListHead)
//{
//    PAL_OsListNodeHeader    *hRemoveHeadTempNode;
//    Bool    NPremoveHeadLoopFlag    =   FALSE;
//    do 
//    {
//        if (NULL == hListHead) {
//            hRemoveHeadTempNode =   NULL;
//            break;
//        }
//
//        hRemoveHeadTempNode = PAL_osList_NP_Dequeue(hListHead);
//        NPremoveHeadLoopFlag    =   FALSE;
//    
//    } while(NPremoveHeadLoopFlag);
//
//    return ((Ptr)hRemoveHeadTempNode);
//}
//
///* PAL OS List Insert */
//void PAL_osList_NP_Insert (Ptr hListNode, Ptr hNewNode)
//{
//    PAL_OsListNodeHeader *insertCurrNode = (PAL_OsListNodeHeader *)hNewNode;
//    PAL_OsListNodeHeader *insertPrevNode = (PAL_OsListNodeHeader *)hListNode;
//    PAL_OsListNodeHeader *insertTempNode;
//
//    if((NULL    !=  insertCurrNode) &&  (NULL   !=  insertPrevNode))
//    {
//        if(NULL != insertPrevNode->prev)
//        {
//            insertCurrNode->prev = insertPrevNode;
//            insertCurrNode->next = insertPrevNode->next;
//            insertPrevNode->next= insertCurrNode;
//            insertTempNode = insertCurrNode->next;
//            insertTempNode->prev = insertCurrNode;
//        }
//    }
//}
//
///* PAL OS List Remove */
//Ptr PAL_osList_NP_Remove(Ptr hListNode)
//{
//    PAL_OsListNodeHeader *removeTempNode;
//    PAL_OsListNodeHeader *removeRetNode;
//    PAL_OsListNodeHeader *removeCurrNode = (PAL_OsListNodeHeader *)hListNode;
//    Bool    NPremoveLoopFlag    =   FALSE;
//
//    do {
//        if(NULL ==  removeCurrNode)
//        {
//            removeRetNode   =   NULL;
//            break;
//        }
//        if (removeCurrNode->next == removeCurrNode)
//        {
//            removeRetNode = removeCurrNode;
//            break;
//        }
//        if((NULL != removeCurrNode->next) && (NULL != removeCurrNode->prev))
//        {
//            removeRetNode = removeCurrNode->next;
//            removeTempNode = removeCurrNode->prev;
//            removeTempNode->next = removeCurrNode->next;
//            removeTempNode = removeCurrNode->next;
//            removeTempNode->prev = removeCurrNode->prev;
//            removeCurrNode->next = removeCurrNode->prev = removeCurrNode;
//        }
//        NPremoveLoopFlag    =   FALSE;
//    } while(NPremoveLoopFlag);
//
//    return ((Ptr)removeRetNode);
//}
//
///* PAL OS List Prepend */
//Ptr PAL_osList_NP_Prepend (Ptr hListHead, Ptr hNewNode)
//{
//    PAL_OsListNodeHeader *prePendTempNode;
//    PAL_OsListNodeHeader *prePendCurrNode = (PAL_OsListNodeHeader *)hNewNode;
//    PAL_OsListNodeHeader *prePendHeadNode = (PAL_OsListNodeHeader *)hListHead;
//
//    if(NULL !=  prePendCurrNode)
//    {
//        if(NULL ==  prePendHeadNode)
//        {
//            prePendCurrNode->next = prePendCurrNode->prev = prePendCurrNode;
//        }
//        else
//        {
//            if(NULL != prePendHeadNode->prev)
//            {
//                prePendTempNode        = prePendHeadNode->prev;
//                prePendTempNode->next  = prePendCurrNode;
//                prePendCurrNode->next  = prePendHeadNode;
//                prePendCurrNode->prev  = prePendHeadNode->prev;
//                prePendHeadNode->prev  = prePendCurrNode;
//            }
//        }
//    }
//    return ((Ptr)prePendCurrNode);
//}
//
///* PAL OS List Enqueue */
//void PAL_osList_NP_Enqueue(PAL_OsListNodeHeader * const queue, Ptr elem)
//{
//    PAL_OsListNodeHeader    *prev;
//
//    if((NULL    !=  queue) && (NULL !=  elem))
//    {
//        prev = queue->prev;
//		if (NULL != prev) {
//	        if(NULL != prev->next)
//	        {
//	            ((PAL_OsListNodeHeader *)elem)->next = (PAL_OsListNodeHeader *)queue;
//	            ((PAL_OsListNodeHeader *)elem)->prev = prev;
//	            prev->next = (PAL_OsListNodeHeader *)elem;
//	            queue->prev = (PAL_OsListNodeHeader *)elem;
//	        }
//		}
//    }
//}
//
///* PAL OS List Dequeue */
//Ptr PAL_osList_NP_Dequeue(PAL_OsListNodeHeader *  const queue)
//{
//    PAL_OsListNodeHeader    *elem = NULL;
//    PAL_OsListNodeHeader    *next;
//
//    if(NULL !=  queue)
//    {
//        if(NULL != queue->next)
//        {
//            elem = queue->next;
//			if (NULL != elem) {
//	            if(NULL != elem->next)
//	            {
//	                next = elem->next;
//	                queue->next = next;
//	                next->prev = queue;
//	            } else {
//					elem = NULL;
//				}
//			}
//        }
//    }
//
//    return ((Ptr)elem);
//}
//
///* PAL OS List Empty? */
//Bool PAL_osList_NP_IsEmpty(Ptr hListHead)
//{
//    Bool NPIsEmptyretCode;
//
//    if(NULL !=  hListHead)
//    {
//        if (((PAL_OsListNodeHeader*) hListHead)->next == ((PAL_OsListNodeHeader*) hListHead)) {
//            NPIsEmptyretCode = TRUE;
//        } else {
//            NPIsEmptyretCode = FALSE;
//        }
//    }
//    return (NPIsEmptyretCode);
//}
