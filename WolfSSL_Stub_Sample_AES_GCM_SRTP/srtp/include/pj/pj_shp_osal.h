/*
 * Mocha
 * Copyright (c) 2001, 2002 Software Center, Samsung Electronics, Inc.
 * All rights reserved.
 *
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung Electronics. 
 */


#ifndef PJ_SHP_OSAL_H
#define PJ_SHP_OSAL_H


/*
 * OS Objects' Handle
 */
typedef int HTask;
typedef int HMsgQueue;
typedef int HSemaphore;
typedef int HMutex;
typedef int HPartition;
typedef int HTimer;
typedef int HEventHandler;

typedef unsigned long DWORD;
typedef unsigned char		BYTE;
typedef unsigned long		ULONG;
typedef unsigned int		UINT32;
typedef unsigned int		DID;
#ifndef BOOL
typedef int					BOOL;
#endif // BOOL

#ifndef TRUE
#define TRUE				1
#endif // TRUE

#ifndef FALSE
#define FALSE				0
#endif // FALSE

#ifndef INFINITE
#define 	INFINITE	0xFFFFFFFF
#endif

#ifndef INVALID_HOBJ
#define 	INVALID_HOBJ	(-1)
#endif
/*---------
 * Critical Section
 */
typedef DWORD ShpCriticalSection;
					
typedef struct tagShpParam
{
    ULONG   NumberParams;
    ULONG   Params[1]; // rest of parameters follow
} ShpParam;

/*-----
 * Task
 */
typedef DWORD (*ShpTaskStartEntry)(DWORD param);

/*************OemOsTask.h*******************************/

/* * Priorities that the OS supports */
#define TASK_PRIO_MIN		1		/* 0 is reserved for IDLE task. */
#define TASK_PRIO_MAX		239		/* 244 ~ 255 are reserved for daemon tasks. */	

/**********************************************************/
/* Semaphore */
HSemaphore	ShpCreateSemaphoreEx(char* szSemName, int initCount, UINT32 maxCount);
BOOL		ShpWaitSemaphore(HSemaphore hSem, ULONG timeout);
BOOL		ShpReleaseSemaphore(HSemaphore hSem);
BOOL		ShpDeleteSemaphore(HSemaphore hSem);

/* Mutex */
HMutex		ShpCreateMutex(char* szMutexName);
BOOL		ShpAcquireMutex(HMutex hMutex);
BOOL		ShpReleaseMutex(HMutex hMutex);
BOOL 	    ShpDeleteMutex(HMutex hMutex);
BOOL		ShpTryAcquireMutex(HMutex hMutex);

/* Critical Section */
void		ShpEnterCriticalSection(ShpCriticalSection* pCS);
void		ShpLeaveCriticalSection(ShpCriticalSection* pCS);

HTask		ShpCreateTask(char* szTaskName, int priority, BYTE* pStack, ULONG stackSize, ShpTaskStartEntry startAddr, DID startDID, DWORD param);
int			ShpGetTaskPriority(HTask hTask);
BOOL		ShpStartTask(HTask hTask);
BOOL		ShpDeleteTask(HTask hTask);
void		ShpSuspendTask(HTask hTask);
void		ShpResumeTask(HTask hTask);
void		ShpSleep(int mSecs);
HTask		ShpGetCurrentTask(void);

/* OS Error */
unsigned int ShpGetLastError(void);
void ShpSetLastError(UINT32 err);

/*Logs*/
void PTTUtil_AddLogs(char* pLog);

#endif //PJ_SHP_OSAL_H

/*EOF*/
