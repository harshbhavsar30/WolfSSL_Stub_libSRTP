/*
 * Samsung Data Protocol 
 * Developed by UMTS team 
 * 
 * Copyright 2001 by Software Center, Samsung Electronics, Inc., 
 * 599-4 Shinsa-Dong, Kangnam-Gu, Seoul, Korea. 
 * All rights reserved.
 *
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung Electronics. 
 */

 
#ifndef _SDP_SOCK_EXT_H_
#define _SDP_SOCK_EXT_H_

#ifdef  __cplusplus
extern "C" {
#endif

/* These protocols must absolutely keep in sync with SdpIp.h & SdpIpHelp.h */
#define SDP_IPPROTO_IP					0
#define SDP_IPPROTO_TCP					6
#define SDP_IPPROTO_UDP					17
/* Level number for (get/set)sockopt() to apply to socket itself. */
#define SDP_SOL_SOCKET      			10000
/* Level for ProtoMgr */
#define SDP_SOL_PROTO					10001

/* recv/send flags */
#define SDP_MSG_OOB         			0x1		/* process out-of-band data */
#define SDP_MSG_PEEK        			0x2     /* peek at incoming message */
#define SDP_MSG_DONTROUTE   			0x4     /* send without using routing tables */

/* ------ Types ------ */
#define SDP_SOCK_STREAM    				1	/* stream socket */
#define SDP_SOCK_DGRAM     				2	/* datagram socket */
#define SDP_SOCK_RAW       				3	/* raw-protocol s16erface */

#ifdef  __cplusplus
}
#endif

#endif  /* _SDP_SOCK_EXT_H_ */
