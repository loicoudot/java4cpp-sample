#ifndef JAVA4CPPTHREAD_H
#define JAVA4CPPTHREAD_H

#ifdef _WIN32
#   include <windows.h>
#   define callback_t                       unsigned long __stdcall
#   define thread_t                         HANDLE
#   define thread_create(thrd, fct, param)  (thrd) = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(fct),(param),0,NULL)
#   define thread_delete(thrd)              CloseHandle(thrd);
#   define thread_wait_close(thrd)          WaitForSingleObject(thrd, INFINITE)

#   define mutex_t                          CRITICAL_SECTION
#   define mutex_init(mutex)                InitializeCriticalSection(mutex)
#   define mutex_lock(mutex)                EnterCriticalSection(mutex)
#   define mutex_unlock(mutex)              LeaveCriticalSection(mutex)
#   define mutex_delete(mutex)              DeleteCriticalSection(mutex)

#else
#   include <pthread.h>
#   define callback_t                       void *
#   define thread_t                         pthread_t
#   define thread_create(thrd, fct, param)  pthread_create(&(thrd), NULL, (fct), (param))
#   define thread_delete(thrd)
#   define thread_wait_close(thrd)          pthread_join(thrd, NULL)

#   include <semaphore.h>
#   define mutex_t                          pthread_mutex_t
#   define mutex_init(mutex)                pthread_mutex_init(&(mutex), NULL)
#   define mutex_lock(mutex)                pthread_mutex_lock(&(mutex))
#   define mutex_unlock(mutex)              pthread_mutex_unlock(&(mutex))
#   define mutex_delete(mutex)              pthread_mutex_destroy(&(mutex));

#endif
#endif
