/* $Id: os_brew.h,v 1.1.2.1 2014-12-16 14:51:19 dsadanand Exp $ */
/* 
 * Copyright (C) 2008-2009 Teluu Inc. (http://www.teluu.com)
 * Copyright (C) 2003-2008 Benny Prijono <benny@prijono.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */
#ifndef __PJ_COMPAT_OS_BREW_H__
#define __PJ_COMPAT_OS_BREW_H__

/**
 * @file os_brew.h
 * @brief Describes Brew operating system specifics.
 */


#if defined(__arm)
#undef __cplusplus
#define PJ_M_ARMV4 1
#endif

#define PJ_BREW 1

#define PJ_OS_NAME		    "brew"

#define PJ_HAS_ARPA_INET_H	    0
#define PJ_HAS_ASSERT_H		    0
#define PJ_HAS_CTYPE_H		    0
#define PJ_HAS_ERRNO_H		    0
#define PJ_HAS_LINUX_SOCKET_H	0
#define PJ_HAS_MALLOC_H		    0
#define PJ_HAS_NETDB_H		    0
#define PJ_HAS_NETINET_IN_H	    0
#define PJ_HAS_SETJMP_H		    0
#define PJ_HAS_STDARG_H		    1
#define PJ_HAS_STDDEF_H		    0
#define PJ_HAS_STDIO_H		    0
#define PJ_HAS_STDLIB_H		    0
#define PJ_HAS_STRING_H		    0
#define PJ_HAS_SYS_IOCTL_H	    0
#define PJ_HAS_SYS_SELECT_H	    0
#define PJ_HAS_SYS_SOCKET_H	    0
#define PJ_HAS_SYS_TIME_H	    0
#define PJ_HAS_SYS_TIMEB_H	    0
#define PJ_HAS_SYS_TYPES_H	    0
#define PJ_HAS_TIME_H		    0
#define PJ_HAS_UNISTD_H		    0
#define PJ_HAS_SEMAPHORE_H	    0

#define PJ_HAS_MSWSOCK_H	    0
#define PJ_HAS_WINSOCK_H	    0
#define PJ_HAS_WINSOCK2_H	    0

#define PJ_SOCK_HAS_INET_ATON	0

/* Set 1 if native sockaddr_in has sin_len member. 
 * Default: 0
 */
#define PJ_SOCKADDR_HAS_LEN	    0

#define PJ_SELECT_NEEDS_NFDS	0
/* Is errno a good way to retrieve OS errors?
 */
#define PJ_HAS_ERRNO_VAR	    1

/* When this macro is set, getsockopt(SOL_SOCKET, SO_ERROR) will return
 * the status of non-blocking connect() operation.
 */
#define PJ_HAS_SO_ERROR             0

/* This value specifies the value set in errno by the OS when a non-blocking
 * socket recv() can not return immediate daata.
 */
#define PJ_BLOCKING_ERROR_VAL       0

/* This value specifies the value set in errno by the OS when a non-blocking
 * socket connect() can not get connected immediately.
 */
#define PJ_BLOCKING_CONNECT_ERROR_VAL   0

/* Default threading is enabled, unless it's overridden. */

#  define PJ_HAS_THREADS	    1


#define PJ_HAS_HIGH_RES_TIMER	    1
#define PJ_HAS_MALLOC               0
#ifndef PJ_OS_HAS_CHECK_STACK
#   define PJ_OS_HAS_CHECK_STACK    0
#endif
#define PJ_NATIVE_STRING_IS_UNICODE 0

#define PJ_ATOMIC_VALUE_TYPE	    long

/* If 1, use Read/Write mutex emulation for platforms that don't support it */
#define PJ_EMULATE_RWMUTEX	    0

/* If 1, pj_thread_create() should enforce the stack size when creating 
 * threads.
 * Default: 0 (let OS decide the thread's stack size).
 */
#define PJ_THREAD_SET_STACK_SIZE    	0

/* If 1, pj_thread_create() should allocate stack from the pool supplied.
 * Default: 0 (let OS allocate memory for thread's stack).
 */
#define PJ_THREAD_ALLOCATE_STACK    	0

/* Linux has socklen_t */
#define PJ_HAS_SOCKLEN_T		0

//#define PJ_SOCK_HAS_GETADDRINFO 0

#endif	/* __PJ_COMPAT_OS_BREW_H__ */

