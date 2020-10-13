/* $Id: string.h 3553 2011-05-05 06:14:19Z nanang $ */
/* 
 * Copyright (C) 2008-2011 Teluu Inc. (http://www.teluu.com)
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
#ifndef __PJ_COMPAT_STRING_H__
#define __PJ_COMPAT_STRING_H__

/**
 * @file string.h
 * @brief Provides string manipulation functions found in ANSI string.h.
 */


#if defined(PJ_HAS_STRING_H) && PJ_HAS_STRING_H != 0
#if _MSC_VER>1600
#define __STDC_WANT_SECURE_LIB__ 0
#endif

#   include <string.h>
#else

    PJ_DECL(int) strcasecmp(const char *s1, const char *s2);
    PJ_DECL(int) strncasecmp(const char *s1, const char *s2, pj_size_t len);

#endif

/* For sprintf family */
#ifndef POC_CDE_BREW
#include <stdio.h>
#endif

/* On WinCE, string stuffs are declared in stdlib.h */
#if defined(PJ_HAS_STDLIB_H) && PJ_HAS_STDLIB_H!=0
#if defined KN_IOS_BTR_OPT
#   include <stdlib.h>
#endif
#endif

#if defined(_MSC_VER) && !(defined POC_CDE_BREW)
#   define strcasecmp	_stricmp
#   define strncasecmp	_strnicmp
#   define snprintf	_snprintf
#   define vsnprintf	_vsnprintf
#   define snwprintf	_snwprintf
#   define wcsicmp	_wcsicmp
#   define wcsnicmp	_wcsnicmp
#else
#   define stricmp	strcasecmp
#   define strnicmp	strncasecmp

#   if defined(PJ_NATIVE_STRING_IS_UNICODE) && PJ_NATIVE_STRING_IS_UNICODE!=0
#	error "Implement Unicode string functions"
#   endif
#endif

#ifdef PJ_MTK
#include "_kn_plt_cstd_lib_wrap.h"
#define pj_ansi_strcmp		KN_STRCMP
#define pj_ansi_strncmp		KN_STRNCMP
#define pj_ansi_strlen		KN_STRLEN
#define pj_ansi_strcpy		KN_STRCPY
#define pj_ansi_strncpy		KN_STRNCPY
#define pj_ansi_strcat		KN_STRCAT
#define pj_ansi_strstr		KN_STRSTR
#define pj_ansi_strchr		KN_STRCHR
#define pj_ansi_strtok		KN_STRTOK
#define pj_ansi_atoi		KN_ATOI
#define pj_ansi_snprintf	KN_SNPRINTF
#define pj_ansi_sprintf		KN_SPRINTF
#define pj_ansi_stricmp		KN_STRICMP
#define pj_ansi_strnicmp	KN_STRNICMP

#elif defined (PJ_RTKE) || defined (PJ_THREADX)
	#include "_kn_plt_cstd_lib_wrap.h"
    #define pj_ansi_strlen		KN_STRLEN
    #define pj_ansi_strcmp		KN_STRCMP
    #define pj_ansi_stricmp		KN_STRICMP
    #define pj_ansi_atoi		KN_ATOI
    #define pj_ansi_strncmp		KN_STRNCMP
    #define pj_ansi_strchr		KN_STRCHR
    #define pj_ansi_strcpy		KN_STRCPY
    #define pj_ansi_strncpy		KN_STRNCPY
    #define pj_ansi_strcat		KN_STRCAT
    #define pj_ansi_strtok		KN_STRTOK
    #define pj_ansi_strstr		KN_STRSTR
    #define pj_ansi_strnicmp	KN_STRNICMP
    #define pj_ansi_strcasecmp	KN_STRICMP
    #define pj_ansi_strncasecmp	KN_STRNICMP
    #define pj_ansi_sprintf		KN_SPRINTF
    #define pj_ansi_snprintf    KN_SNPRINTF

    #define strcmp			KN_STRCMP
    #define strncmp			KN_STRNCMP
    #define strlen			KN_STRLEN
    #define strcpy			KN_STRCPY
    #define strncpy			KN_STRNCPY
    #define strcat			KN_STRCAT
    #define strstr			KN_STRSTR
    #define strchr			KN_STRCHR
    #define strtok			KN_STRTOK
    
    #define	memcmp			KN_MEMCMP
    #define memset			KN_MEMSET
    #define memcpy  		KN_MEMCPY
    #define memchr			KN_MEMCHR
    #define memmove			KN_MEMMOVE
#elif defined (POC_CDE_BREW) && POC_CDE_BREW != 0
	#include "poc_cde_vendor_wrapper.h"
#define pj_ansi_strlen		psptt_strlen
#define pj_ansi_strcmp		psptt_strcmp
#define pj_ansi_stricmp		psptt_stricmp
#define pj_ansi_atoi		psptt_atoi
#define pj_ansi_strncmp		psptt_strncmp
#define pj_ansi_strchr		psptt_strchr
#define pj_ansi_strcpy		psptt_strcpy
#define pj_ansi_strncpy		psptt_strncpy
#define pj_ansi_strcat		psptt_strcat
#define pj_ansi_strtok		psptt_strtok
#define pj_ansi_strstr		psptt_strstr
#define pj_ansi_strnicmp	psptt_strnicmp
#define pj_ansi_strcasecmp	psptt_stricmp
#define pj_ansi_strncasecmp	psptt_strnicmp
#define pj_ansi_sprintf		psptt_sprintf
#define pj_ansi_snprintf    psptt_snprintf

#define strcmp			psptt_strcmp
#define strncmp			psptt_strncmp
#define strlen			psptt_strlen
#define strcpy			psptt_strcpy
    #define strncpy			psptt_strncpy
#define strcat			psptt_strcat
#define strstr			psptt_strstr
#define strchr			psptt_strchr
#define strtok			psptt_strtok
    
#define	memcmp			psptt_memcmp
#define memset			psptt_memset
#define memcpy  		psptt_memcpy
#define memchr			psptt_memchr
    #define memmove			psptt_memmove
#else
#define pj_ansi_strcmp		strcmp
#define pj_ansi_strncmp		strncmp
#define pj_ansi_strlen		strlen
#define pj_ansi_strcpy		strcpy
#define pj_ansi_strncpy		strncpy
#define pj_ansi_strcat		strcat
#define pj_ansi_strstr		strstr
#define pj_ansi_strchr		strchr
#define pj_ansi_strtok		strtok
#define pj_ansi_atoi		atoi
#define pj_ansi_strcasecmp	strcasecmp
#define pj_ansi_stricmp		strcasecmp
#define pj_ansi_strncasecmp	strncasecmp
#define pj_ansi_strnicmp	strncasecmp
#define pj_ansi_snprintf	snprintf
#define pj_ansi_sprintf		sprintf

#endif

#ifndef POC_CDE_BREW
#define pj_ansi_vsprintf	vsprintf
#define pj_ansi_vsnprintf	vsnprintf
#else
#define pj_ansi_vsprintf	psptt_sprintf
#define pj_ansi_vsnprintf	psptt_vsnprintf
#endif

#if defined(PJ_HAS_NO_SNPRINTF) && PJ_HAS_NO_SNPRINTF != 0
#   include <pj/types.h>
#   include <pj/compat/stdarg.h>
    PJ_BEGIN_DECL
    PJ_DECL(int) snprintf(char*s1, pj_size_t len, const char*s2, ...);
    PJ_DECL(int) vsnprintf(char*s1, pj_size_t len, const char*s2, va_list arg);
    PJ_END_DECL
#endif
    
//#define pj_ansi_snprintf	snprintf
//#define pj_ansi_vsprintf	vsprintf
//#define pj_ansi_vsnprintf	vsnprintf

#define pj_unicode_strcmp	wcscmp
#define pj_unicode_strncmp	wcsncmp
#define pj_unicode_strlen	wcslen
#define pj_unicode_strcpy	wcscpy
#define	pj_unicode_strncpy	wcsncpy
#define pj_unicode_strcat	wcscat
#define pj_unicode_strstr	wcsstr
#define pj_unicode_strchr	wcschr
#define pj_unicode_strcasecmp	wcsicmp
#define pj_unicode_stricmp	wcsicmp
#define pj_unicode_strncasecmp	wcsnicmp
#define pj_unicode_strnicmp	wcsnicmp
#define pj_unicode_sprintf	swprintf
#define pj_unicode_snprintf	snwprintf
#define pj_unicode_vsprintf	vswprintf
#define pj_unicode_vsnprintf	vsnwprintf

#if defined(PJ_NATIVE_STRING_IS_UNICODE) && PJ_NATIVE_STRING_IS_UNICODE!=0
#   define pj_native_strcmp	    pj_unicode_strcmp
#   define pj_native_strncmp	    pj_unicode_strncmp
#   define pj_native_strlen	    pj_unicode_strlen
#   define pj_native_strcpy	    pj_unicode_strcpy
#   define pj_native_strncpy	    pj_unicode_strncpy
#   define pj_native_strcat	    pj_unicode_strcat
#   define pj_native_strstr	    pj_unicode_strstr
#   define pj_native_strchr	    pj_unicode_strchr
#   define pj_native_strcasecmp	    pj_unicode_strcasecmp
#   define pj_native_stricmp	    pj_unicode_stricmp
#   define pj_native_strncasecmp    pj_unicode_strncasecmp
#   define pj_native_strnicmp	    pj_unicode_strnicmp
#   define pj_native_sprintf	    pj_unicode_sprintf
#   define pj_native_snprintf	    pj_unicode_snprintf
#   define pj_native_vsprintf	    pj_unicode_vsprintf
#   define pj_native_vsnprintf	    pj_unicode_vsnprintf
#else
#   define pj_native_strcmp	    pj_ansi_strcmp
#   define pj_native_strncmp	    pj_ansi_strncmp
#   define pj_native_strlen	    pj_ansi_strlen
#   define pj_native_strcpy	    pj_ansi_strcpy
#   define pj_native_strncpy	    pj_ansi_strncpy
#   define pj_native_strcat	    pj_ansi_strcat
#   define pj_native_strstr	    pj_ansi_strstr
#   define pj_native_strchr	    pj_ansi_strchr
#   define pj_native_strcasecmp	    pj_ansi_strcasecmp
#   define pj_native_stricmp	    pj_ansi_stricmp
#   define pj_native_strncasecmp    pj_ansi_strncasecmp
#   define pj_native_strnicmp	    pj_ansi_strnicmp
#   define pj_native_sprintf	    pj_ansi_sprintf
#   define pj_native_snprintf	    pj_ansi_snprintf
#   define pj_native_vsprintf	    pj_ansi_vsprintf
#   define pj_native_vsnprintf	    pj_ansi_vsnprintf
#endif


#endif	/* __PJ_COMPAT_STRING_H__ */
