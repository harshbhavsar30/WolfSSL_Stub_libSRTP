
typedef void* Hsema;
typedef void* Hmutex;
typedef void* Hthread;
typedef void (*ThreadEntry)(void);

//UtaCommonReturnCodes utaoserror;
extern int utaoserror;
/* Uta OS Error */
 int UtaGetLastError(void);

void UtaSetLastError(int err);

Hsema PJUtaOsSemCreate(const char* name, unsigned initial);

int PJUtaOsSemDelete(Hsema sem);

int PJUtaOsSemRelease(Hsema sem);

int PJUtaOsSemObtain(Hsema sem);

int PJUtaOsSemObtainTry(Hsema sem);

int PJUtaOsSemObtainWaitFor(Hsema sem,unsigned waittime);

Hmutex PJUtaOsMutexCreate(const char *name);

int PJUtaOsMutexDestroy(Hmutex mutex);

int PJUtaOsMutexLock(Hmutex mutex);

int PJUtaOsMutexTryLock(Hmutex mutex);

int PJUtaOsMutexUnlock(Hmutex mutex);


Hthread PJUtaOsThreadCreate(const char* thread_name, unsigned stack_size,ThreadEntry func,void* arg,void** stk_adr_p);

int PJUtaOsThreadStart(Hthread thread);

int PJUtaOsThreadDelete(Hthread thread,void* stk_ptr);

int PJGetThreadState(Hthread thread);

int PJUtaOsThreadGetCurrent(void** thr_ptr);

int PJUtaOsThreadGetPriority(Hthread thread);

void PJUtaOsSleep(unsigned msec);

int PJUtaOsThreadResume(Hthread thread);


