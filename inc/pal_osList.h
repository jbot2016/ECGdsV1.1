#ifndef PAL_OSLIST_H_
#define PAL_OSLIST_H_

/*****************************************************************************
 * File Name : pal_oslist.h 
 *
 * Brief	 : OsLIST Services Header File 
 *
 * Copyright (C) 2009 -2010 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
******************************************************************************/

//#ifndef __PAL_OSLIST_H__
//#define __PAL_OSLIST_H__

#include "psp_common.h"

/**
 * \defgroup PalOSList PAL OS List Interface
 *
 * PAL OS List Interface
 * \{
 */

/** \name PAL OS List Interface (Protected)
 *  PAL OS List Interface (Protected)
 * \{
 */

/**
 * \brief List Node Header
 *
 * List node header used by all elements as the first member
 */
typedef struct
{
    Ptr next;       /**< pointer to next node on the list */
    Ptr prev;       /**< pointer to previous node on the list */
} PAL_OsListNodeHeader;

/**
 * \def   PAL_OSLIST_MKNODE(hNode)
 *
 *      This macro stitches link pointers of given node to
 *      reset conditions whereby the node can serve as
 *      seed for constructing a fresh list
 * \param   hNode is pointer to a arbitrary data object whose first
 *      member is of type PAL_OsListNodeHeader.
 * \warning This macro does NOT allocate memory for the new node.
 *      Caller must define the object elsewhere and only pass its
 *      pointer to the macro.
 */
#define PAL_OSLIST_MKNODE(hNode)\
{\
    ((PAL_OsListNodeHeader*)(hNode))->next = (Ptr)(hNode); \
    ((PAL_OsListNodeHeader*)(hNode))->prev = (Ptr)(hNode); \
}

/**
 * \brief   PAL OS List Append (Protected)
 *
 * This function "appends" the new node at tail end of list
 *
 * \param   hListHead is pointer to head of the list
 * \param   hNewNode is pointer to new element to be placed on the list
 * \return  nil return value
 */
void PAL_osListAppend(Ptr hListHead, Ptr hNewNode);

/**
 * \brief   PAL OS List Remove Head (Protected)
 *
 * This function "chops" and returns the node at head of list
 * \param   hListHead is pointer to head of the list
 * \return  pointer to node that was extracted from head of list
 */
Ptr PAL_osListRemoveHead(Ptr hListHead);


/**
 * \brief   PAL OS List Insert (Protected)
 *
 *      This function inserts the new node "after" the specified
 *      node on the list
 * \param   hListNode is pointer to node already on list "after" which
 *      new node is to be inserted
 * \param   hNewNode is pointer to new node to be placed on list
 * \return  nil return value
 */
void PAL_osListInsert(Ptr hListNode, Ptr hNewNode);


/**
 * \brief   PAL OS List Remove (Protected)
 *
 *      This function pulls out the specified node from the list.
 *      Rest of nodes will continue to remain normally on list
 * \param   hListNode is pointer of specific node to be removed
 * \warning No memory is freed up by this call
 * \return  nil return value
 */
Ptr PAL_osListRemove(Ptr hListNode);

/**
 * \brief   PAL OS List Prepend (Protected)
 *
 *      This function prepends the specified node "ahead" of the
 *      current header node on the given list
 * \param   hListHead is pointer to head of the list
 * \param   hNewNode is pointer to new node to be placed at front
 *      of the current list
 * \return  Pointer to new head of list
 */
Ptr PAL_osListPrepend(Ptr hListHead, Ptr hNewNode);

/**
 * \brief   PAL OS List Enqueue (Protected)
 *
 *      This function enqueues the node to the list
 * \param   queue is pointer to head of the list
 * \param   elem is pointer to new node to be enqueued
 * \return  none
 */
void PAL_osListEnqueue(PAL_OsListNodeHeader * const queue, Ptr elem);

/**
 * \brief   PAL OS List Dequeue (Protected)
 *
 *      This function de-queues the node from the list
 * \param   queue is pointer to head of the list
 * \return  removed node
 */
Ptr PAL_osListDequeue(PAL_OsListNodeHeader * const queue);

/**
 * \brief   PAL OS List Check Empty (Protected)
 *
 *      This function checks if list is empty
 * \param   hListHead is pointer to head of the list
 * \return  True if list is empty else False
 */
Bool PAL_osListIsEmpty(Ptr hListHead);

/*\}*/

/** \name PAL OS List Interface (Non Protected)
 *  PAL OS List Interface (Non Protected)
 * \{
 */

 /**
 * \brief   PAL OS List Append (Non Protected)
 *
 * This function "appends" the new node at tail end of list
 *
 * \param   hListHead is pointer to head of the list
 * \param   hNewNode is pointer to new element to be placed on the list
 * \return  nil return value
 */
void PAL_osList_NP_Append(Ptr hListHead, Ptr hNewNode);

/**
 * \brief   PAL OS List Remove Head (Non Protected)
 *
 * This function "chops" and returns the node at head of list
 * \param   hListHead is pointer to head of the list
 * \return  pointer to node that was extracted from head of list
 */
Ptr PAL_osList_NP_RemoveHead(Ptr hListHead);

/**
 * \brief   PAL OS List Insert (Non Protected)
 *
 *      This function inserts the new node "after" the specified
 *      node on the list
 * \param   hListNode is pointer to node already on list "after" which
 *      new node is to be inserted
 * \param   hNewNode is pointer to new node to be placed on list
 * \return  nil return value
 */
void PAL_osList_NP_Insert(Ptr hListNode, Ptr hNewNode);

/**
 * \brief   PAL OS List Remove (Non protected)
 *
 *      This function pulls out the specified node from the list.
 *      Rest of nodes will continue to remain normally on list
 * \param   hListNode is pointer of specific node to be removed
 * \warning No memory is freed up by this call
 * \return  nil return value
 */
Ptr PAL_osList_NP_Remove(Ptr hListNode);

/**
 * \brief   PAL OS List Prepend (Non Protected)
 *
 *      This function prepends the specified node "ahead" of the
 *      current header node on the given list
 * \param   hListHead is pointer to head of the list
 * \param   hNewNode is pointer to new node to be placed at front
 *      of the current list
 * \return  Pointer to new head of list
 */
Ptr PAL_osList_NP_Prepend(Ptr hListHead, Ptr hNewNode);

/**
 * \brief   PAL OS List Enqueue (Non Protected)
 *
 *      This function enqueues the node to the list
 * \param   queue is pointer to head of the list
 * \param   elem is pointer to new node to be enqueued
 * \return  none
 */
void PAL_osList_NP_Enqueue(PAL_OsListNodeHeader * const queue, Ptr elem);

/**
 * \brief   PAL OS List Dequeue (Non Protected)
 *
 *      This function de-queues the node from the list
 * \param   queue is pointer to head of the list
 * \return  removed node
 */
Ptr PAL_osList_NP_Dequeue(PAL_OsListNodeHeader * const queue);

/**
 * \brief   PAL OS List Check Empty (Non Protected)
 *
 *      This function checks if list is empty
 * \param   hListHead is pointer to head of the list
 * \return  True if list is empty else False
 */
Bool PAL_osList_NP_IsEmpty(Ptr hListHead);

/*\}*/

/*\}*/

//#endif /* _PAL_OSLIST_H_ */


#endif /*PAL_OSLIST_H_*/
