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
/**
 * @file		OemSocketExternal.h
 * @brief		This file defines the Socket API.
 * @author Ω≈≈¬»£, 0597, matrix@swc.sec.samsung.co.kr
 * @version 	1.0
 * @addtogroup	COMM_SOCKET_OEM
 * @{
 */

#ifndef _OEM_SOCKET_EXT_H_
#define _OEM_SOCKET_EXT_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

//For Target   _SHP_SIMUL is not defined.
#ifndef _SHP_SIMUL
#define __SHP_NXP_BASE__
#endif


// Define it for QTV integration. This modem feature must be removed. Jinyup Kim 2006/07/29.
#if !defined(FEATURE_SSDATAEXT_MOCHA) && !defined(_SHP_SIMUL)
#define FEATURE_SSDATAEXT_MOCHA
#endif // FEATURE_SSDATAEXT_MOCHA

#ifdef __SHP_NXP_BASE__

	#if defined(_SHP_PROTO_QCOM_DP)
	/* Socket type definition */
	#define SOCKET_TYPE_STREAM			SOCK_STREAM
	#define SOCKET_TYPE_DATAGRAM		SOCK_DGRAM 

	/* Socket protocol type */
	#define SOCKET_PROTO_IP			IPPROTO_IP  
	#define SOCKET_PROTO_TCP			IPPROTO_TCP
	#define SOCKET_PROTO_UDP			IPPROTO_UDP
	#define SOCKET_PROTO_SSL			18

	#elif defined(_SHP_PROTO_WINSOCK)
	/* Socket type definition */
	#	define SOCKET_TYPE_STREAM			SOCK_STREAM
	#	define SOCKET_TYPE_DATAGRAM			SOCK_DGRAM 

	/* Socket protocol type */
	#	define SOCKET_PROTO_IP 				IPPROTO_IP
	#	define SOCKET_PROTO_TCP				IPPROTO_TCP
	#	define SOCKET_PROTO_UDP				IPPROTO_UDP
	#	define SOCKET_PROTO_SSL				18

	#elif defined(_SHP_PROTO_SDP)
	/* Socket type definition */
	#	define SOCKET_TYPE_STREAM			SDP_SOCK_STREAM
	#	define SOCKET_TYPE_DATAGRAM			SDP_SOCK_DGRAM

	/* Socket protocol type */
	#	define SOCKET_PROTO_IP 				SDP_IPPROTO_IP
	#	define SOCKET_PROTO_TCP 			SDP_IPPROTO_TCP
	#	define SOCKET_PROTO_UDP 			SDP_IPPROTO_UDP
	#	define SOCKET_PROTO_SSL				18

	#else
	/* Socket type definition */
	#define SOCKET_TYPE_STREAM			1
	#define SOCKET_TYPE_DATAGRAM		2 

	/* Socket protocol type */
	#define SOCKET_PROTO_IP			    1  
	#define SOCKET_PROTO_TCP			2
	#define SOCKET_PROTO_UDP			3
	#define SOCKET_PROTO_SSL			4

	#endif /* _SHP_PROTO_WINSOCK */

#else /* __SHP_NXP_BASE__ */

	#if defined(FEATURE_SSDATAEXT_MOCHA)&& !defined(_SHP_PROTO_WINSOCK)
	/* Socket type definition */
	#define SOCKET_TYPE_STREAM	0     //SOCK_STREAM
	#define SOCKET_TYPE_DATAGRAM	1	//SOCK_DGRAM 

	/* Socket protocol type */
	#define SOCKET_PROTO_IP		4     //IPPROTO_IP
	#define SOCKET_PROTO_TCP		6	//IPPROTO_TCP
	#define SOCKET_PROTO_UDP		17	//IPPROTO_UDP
	#define SOCKET_PROTO_SSL		18

	#else // for windows
		#if defined(_SHP_PROTO_WINSOCK)
		/* Socket type definition */
		#	define SOCKET_TYPE_STREAM			SOCK_STREAM
		#	define SOCKET_TYPE_DATAGRAM			SOCK_DGRAM 

		/* Socket protocol type */
		#	define SOCKET_PROTO_IP 				IPPROTO_IP
		#	define SOCKET_PROTO_TCP				IPPROTO_TCP
		#	define SOCKET_PROTO_UDP				IPPROTO_UDP
		#	define SOCKET_PROTO_SSL				18

		#elif defined(_SHP_PROTO_SDP)
		/* Socket type definition */
		#	define SOCKET_TYPE_STREAM			SDP_SOCK_STREAM
		#	define SOCKET_TYPE_DATAGRAM			SDP_SOCK_DGRAM

		/* Socket protocol type */
		#	define SOCKET_PROTO_IP 				SDP_IPPROTO_IP
		#	define SOCKET_PROTO_TCP 			SDP_IPPROTO_TCP
		#	define SOCKET_PROTO_UDP 			SDP_IPPROTO_UDP
		#	define SOCKET_PROTO_SSL				18

		#else	// BELLINI_BUILD for the NXP
		/* Socket type definition */
		#define SOCKET_TYPE_STREAM			1
		#define SOCKET_TYPE_DATAGRAM		2 

		/* Socket protocol type */
		#define SOCKET_PROTO_IP			    1  
		#define SOCKET_PROTO_TCP			2
		#define SOCKET_PROTO_UDP			3
		#define SOCKET_PROTO_SSL			4

		#endif /* _SHP_PROTO_WINSOCK */

	#endif //FEATURE_SSDATAEXT_MOCHA

#endif /* __SHP_NXP_BASE__ */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* _OEM_SOCKET_EXT_H_ */
