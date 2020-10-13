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
 * @file		SocketExternal.h
 * @brief		This file defines the Socket API.
 * @author Ω≈≈¬»£, 0597, matrix@swc.sec.samsung.co.kr
 * @author	Jinyup Kim	(kjy9411@samsung.com)
 * @author  Hyoung-Su Kim  (hs0207.kim@samsung.com)
 * @version	1.0
 * @addtogroup	SEC_COMM_SOCKET
 * @{
 */
 /* This file is implemented by Samsung and to be used as reference only. */
//#if defined WIN32
#include "kn_pj_plt_connection.h"
#include"socket_cust.h"
#ifndef _SOCKET_EXT_H_
#define _SOCKET_EXT_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define PTT_FD_SETSIZE   33
#define SOCKET_FD_SETSIZE			64

#define SOCK_AF_INET				1
#define SOCK_OSERR_EWOULDBLOCK		-1
#define SOCK_OSERR_EINPROGRESS		-1
#define SOCK_OSERR_ECONNRESET		-1
#define SOCK_OSERR_ENOTCONN			-1

#define HObj int
typedef UINT32		IPV4Addr;
//typedef int		HObj;
typedef	HObj	HDnsTr;
typedef HObj	HSocket;
typedef HObj	HProtocol;
	
/*	typedef unsigned long  UINT32;
	typedef unsigned short UINT16;
	typedef int 	BOOL;
	typedef int		HObj;
	typedef	int  	HDnsTr;
	typedef HObj	HSocket;
	typedef HObj	HProtocol;
	typedef signed short  INT16;   // 16-bit integer
	typedef int           INT32;   // 32-bit integer
	typedef int           BOOL;
	typedef int           KN_VOID;
	typedef int		   KN_SOCK;
	typedef int		   KN_INT32;
	typedef int		   KN_INT;
	typedef long          KN_SOCKLEN;
	typedef int           size_t;
	#define KN_INT16 short		
	#define KN_UINT16 unsigned short
	#define KN_CHAR char	 
 #define KN_TRUE (1)	
 #define KN_FALSE (0)	
 #define KN_ULONG unsigned long
 	
*/
        typedef struct
         {
	   UINT	 socketCount;
	   HSocket	hSocket[SOCKET_FD_SETSIZE];
         } SocketFdSet;
  

	typedef unsigned short 	Port;
	typedef enum
	{
		ANY_ANY_IPV4 = 0x00,
	}AddressType;
	typedef  union
	{
		IPV4Addr		ipv4;
	} Address;
	typedef struct
		{
			Address 	address;
			Port		port;
			AddressType	type;
		}Socket;

	/*	
		typedef struct __KN_SOCK_ADDR_IN{
        KN_INT16  iFamily; //should be AF_INET 
        KN_UINT16 iPort;
        KN_IN_ADDR sAddr;
        KN_CHAR    cZero[8]; 
		}KN_SOCK_ADDR_IN;
		
		
		typedef struct __KN_IN_ADDR{
			KN_ULONG sInAddr;
			}KN_IN_ADDR;
*/
		
	/* Socket Descriptor Structure */
	typedef struct pttFdSet {
          unsigned char fd_bits [(PTT_FD_SETSIZE+7)/8];
        } PTTFdSet;
		
	/* Timeout Structure */
	typedef struct PTTTimeVal {
			long    sec;         /* seconds */
			long    usec;        /* and microseconds */
					}PTTTimeVal;
					


  
//	typedef struct _SockAddr 				/* generic socket address structure */
//	{
//		UINT16 		sa_family;				/* socket address family */
//		unsigned char	sa_data[14];			/* address data */
//	}SockAddr;


	/* This structure is used in calls to GetAddrInfo and GetNameInfo. */
	typedef struct SocketAddrInfo
	{ 
		int 					ai_flags;		/* Any of SDP_AI_NUMERICHOST, SDP_AI_ADDRCONFIG */
		int 					ai_family;		/* Any of AF_INET, AF_INET6, AF_UNSPEC. */
		int					socktype;		/* SOCK_XXX */
		int					ai_protocol;	/* 0 or IPPROTO_XXX. */
		int					ai_addrlen;		/* Length of ai_addr. */
		char 				*ai_canonname;	/* Canonical name of nodename. */
		SockAddr 	  		 *ai_addr;		/* binary address. */
		struct SocketAddrInfo 	*ai_next;		/* next structure in Linked List. */
	} SocketAddrInfo;

	
	
	
	
	/**
	 * @enum  SocketIoctlCmd	
	 *  the command enumeration to control  I/O mode of a socket
	 */
	 //this is not to be used done only to remove the compilation errors from Kodiak

	typedef enum
	{
		SOCKET_IOCTLCMD_NONE	= -1,
		SOCKET_FIONBIO			= 0x00, /**< For nonblocking mode*/
		SOCKET_FIONREAD,				     /**< For the amount of data pending in the network's input buffer that can be read from socket hSocket*/
		SOCKET_FIONWRITE, 				     /**< For the amount of data pending in the network's output buffer that can be wrriten to socket hSocket*/
		SOCKET_SIOCATMARK,			     /**< For returning throught the integer pointed to by the third arbument a nonzero value if the socket's read pointer is currently at the out-of-band mark*/
		SOCKET_IOCTLCMD_MAX
	} SocketIoctlCmd;

	//typedef struct
	//{
	//	UINT	socketCount;
	//	HSocket	hSocket[SOCKET_FD_SETSIZE];
	//} SocketFdSet;

	//typedef struct
	//{
	//	int		sec;		/* Seconds */
	//	int		usec;		/* Micro seconds */
	//} SocketTimeval;

	/**
	 * @enum  SocketOptLevel 
	 * The level enumeration at which the current value for a socket option is defined (See SocketSetSockOpt)	
	 */
	//typedef enum
	//{
	//	SOCKET_OPTLEVEL_NONE	= -1,
	//	SOCKET_IPPROTO_TCP		= 0x00, /**< TCP level*/
	//	SOCKET_IPPROTO_IP,			            /**< IP level*/
	//#if defined (_SHP_PROTO_IPV6)
	//	SOCKET_IPPROTO_IPV6,			     /**< IPv6  level*/
	//#endif // _SHP_PROTO_IPV6
	//	SOCKET_SOL_SOCKET,			    /**< Socket  level*/
	//	SOCKET_SOL_PROTO,				     /**<ProtoMgr level*/
	//	SOCKET_OPTLEVEL_MAX
	//} SocketOptLevel;


	/**
	 * @enum  SocketOptName 		
	 * The option enumeration for a socket (See SocketSetSockOpt)
	 */
#if 0
	typedef enum
	{
		SOCKET_OPTNAME_NONE		= -1,
		SOCKET_TCP_NODELAY		= 0x00,	/**<For being disable the Nagle algorithm for send coalescing*/   /* SOCKET_IPPROTO_TCP - SocketSetSockOpt()/SocketGetSockOpt() */
		SOCKET_TCP_SACK,         /* TCP with SACK donpin.lee@samsung.com */
#if defined(_SHP_OPERATOR_CINGULAR) /* PHILLIT-BROWSER-JHKANG-20111101-TCP window scale option */
		SOCKET_TCP_WND_SCALEOPT,  /* TCP with Window Scale Option*/
#endif
		SOCKET_IP_TTL,					/**<time-to-live*/   /* SOCKET_IPPROTO_IP - SocketSetSockOpt()/SocketGetSockOpt() */
		SOCKET_IP_TOS,					/**<type-of-service and precedence*/   /* SOCKET_IPPROTO_IP - SocketSetSockOpt()/SocketGetSockOpt() */
		SOCKET_SO_LINGER,				/**<linger on close if dat to send*/   /* SOCKET_SOL_SOCKET - SocketSetSockOpt()/SocketGetSockOpt() */
		SOCKET_SO_DONTLINGER,		/**<For being disable the linger*/	/* SOCKET_SOL_SOCKET - SocketSetSockOpt()/SocketGetSockOpt() */
		SOCKET_RCVTIMEO,				/**<receive timeout*/   /* SOCKET_SOL_SOCKET - SocketSetSockOpt() */
		SOCKET_SNDTIMEO,				/**<send timeout*/  /* SOCKET_SOL_SOCKET - SocketSetSockOpt() */
		SOCKET_SO_ACCEPTCONN,		/**<SOCKET_SO_ACCEPTCONN*/	/* SOCKET_SOL_SOCKET - SocketGetSockOpt() */
		SOCKET_SO_ERROR,				/**<For getting pending error and clear*/ /* SOCKET_SOL_SOCKET - SocketGetSockOpt() */
		SOCKET_SO_RCVBUF,				/**<receive buffer size*/ /* SOCKET_SOL_SOCKET - SocketGetSockOpt() */
		SOCKET_SO_SNDBUF,				/**<send buffer size*/ /* SOCKET_SOL_SOCKET - SocketGetSockOpt() */
		SOCKET_SO_MAX_MSG_SIZE,		/**<SOCKET_SO_MAX_MSG_SIZE*/	/* SOCKET_SOL_SOCKET - SocketGetSockOpt() */
		SOCKET_SO_TYPE,				/**<For getting socket type*/		/* SOCKET_SOL_SOCKET - SocketGetSockOpt() */
		SOCKET_SO_PROTOBEARER,		/**<SOCKET_SO_PROTOBEARER*/	/* SOCKET_SOL_PROTO - SocketSetSockOpt()/SocketGetSockOpt() */
		SOCKET_SO_KEEPALIVE,			/**<For setting as keepalive mode.*/ /* SOCKET_SOL_SOCKET - SocketSetSockOpt()/SocketGetSockOpt()*/
		SOCKET_SO_REUSEADDR,			/**<For allowing local accress reuse*/ /* SOCKET_SOL_SOCKET - SocketSetSockOpt()/SocketGetSockOpt() */

		SOCKET_SO_WS_TRICK,			/**< For High Speed of download*/ 	/* SOCKET_SOL_SOCKET - SocketSetSockOpt() For High Speed of download, Added new socket option about WS trick changed by HS.Kim. 17/07/2007. Sydney*/
		SOCKET_SO_TIMER_POLLING,		/**< For High Speed of download*/  /* SOCKET_SOL_SOCKET - SocketSetSockOpt() For High Speed of download, Added by HS.Kim. 07/03/2007. San Diego*/
		SOCKET_SO_IP_ADD_MEMBERSHIP,	/**< For joining multicast group */ /* SOCKET_IPPROTO_IP - SocketSetSockOpt() For multicast joining by sy3280.lee */
		SOCKET_SO_IP_DROP_MEMBERSHIP,	/**< For leaving multicast group*/ /* SOCKET_IPPROTO_IP - SocketSetSockOpt() For multicast leaving by sy3280.lee */
		SOCKET_SO_TCP_MAXSEG, 			/**< To specify MSS(Maximum Segment Size) for TCP /* SOCKET_IPPROTO_TCP, changsoon */
#if defined (_SHP_PROTO_IPV6)		// Options for IPv6 Stack
		SOCKET_IPV6_UNICAST_HOPS,        /**< default unicast hop limit (IPv6)*/ /**< SOCKET_IPV6_UNICAST_HOPS*/
		SOCKET_IPV6_RTHDR,			  /**< For receiving source route (IPv6)*/
		SOCKET_IPV6_HOPOPTS,			  /**< For receiving hop-by-hop options (IPv6)*/
		SOCKET_IPV6_DSTOPTS,			  /**< For receiving destination options (IPv6)*/
		SOCKET_IPV6_PKTOPTIONS,		  /**< For specifying packet options (IPv6)*/

		// MultiCast Options
		SOCKET_MCAST_JOIN_GROUP,		/**< For joining multicast group (IPv6)*/
		SOCKET_MCAST_BLOCK_SOURCE,
		SOCKET_MCAST_UNBLOCK_SOURCE,
		SOCKET_MCAST_LEAVE_GROUP,    /**< For leaving multicast group (IPv6) */
		SOCKET_MCAST_JOIN_SOURCE_GROUP,
		SOCKET_MCAST_LEAVE_SOURCE_GROUP,
#endif // _SHP_PROTO_IPV6

		SOCKET_SO_SSLVERSION,				/**< For setting the version of SSL*/ /* SOCKET_SOL_SOCKET - SocketSetSockOpt()/SocketGetSockOpt() */
		SOCKET_SO_SSLSESSIONLIFETIME,	/**< For setting the time of SSL session*/	/* SOCKET_SOL_SOCKET - SocketSetSockOpt() */
		SOCKET_SO_SSLCONNECTIONWAITTIME,	/**< For setting the waiting time for SSL connection establishment.*/	/* SOCKET_SOL_SOCKET - SocketSetSockOpt() */
		SOCKET_SO_SSLCONNECTIONSTATE,		/**< SOCKET_SO_SSLCONNECTIONSTATE*//* SOCKET_SOL_SOCKET - SocketGetSockOpt() */
		SOCKET_SO_SSLCIPHERSUITENAME,		/**< SOCKET_SO_SSLCIPHERSUITENAME*//* SOCKET_SOL_SOCKET - SocketGetSockOpt() */
		SOCKET_SO_SSLCIPHERSUITEID,			/**< For setting the cyper suite id for SSL connection establishment.*//* SOCKET_SOL_SOCKET - SocketSetSockOpt()/SocketGetSockOpt() */
		SOCKET_SO_SSLCERTVERIFY,			/**< SOCKET_SO_SSLCERTVERIFY*//* SOCKET_SOL_SOCKET - SocketSetSockOpt() */ /* Changsoon, 20080312 */
		SOCKET_OPTNAME_MAX
	} SocketOptName;
#endif

	/* structure for Socket DNS APIs, coded by hskim.*/
#define SOCKET_HOSTINFO_LEN_MAX				3
#define SOCKET_HOSTINFO_ALIAS_SIZE_MAX		64
	/**
	 * @enum  SocketDnsError	
	 * DNS error enumeration 
	 */
	//typedef enum
	//{
	//	SOCKET_DNS_SUCCESS					= 0x00, /**< SUCCESS */
	//	SOCKET_DNS_ERROR_INPROGRESS,				/**< INPROGRESS */
	//	SOCKET_DNS_ERROR_INVALIDSERVER,     /**< INVALIDSERVER */
	//	SOCKET_DNS_ERROR_INVALIDDOMAIN,		  /**< INVALIDDOMAIN */
	//	SOCKET_DNS_ERROR_NETWORKDOWN, 			/**< NETWORKDOWN */
	//	SOCKET_DNS_ERROR_OUTOFMEMORY, 			/**< OUTOFMEMORY */
	//	SOCKET_DNS_ERROR_INVALIDPARAM, 			/**< INVALIDPARAM */
	//	SOCKET_DNS_ERROR_TIMEOUT, 					/**< TIMEOUT */
	//	SOCKET_DNS_ERROR_NORESPONSE, 				/**< NORESPONSE */
	//	SOCKET_DNS_ERROR_NOTFOUND 					/**< NOTFOUND */
	//} SocketDnsError;

	//typedef struct _SocketHostInfo
	//{
	//	int			addrCount;
	//#ifdef _SHP_PROTO_IPV6
	//	Address		addr6[SOCKET_HOSTINFO_LEN_MAX];
	//#endif
	//	IPV4Addr	addr[SOCKET_HOSTINFO_LEN_MAX];
	//	int			aliasCount;
	//	char		szAlias[SOCKET_HOSTINFO_LEN_MAX][SOCKET_HOSTINFO_ALIAS_SIZE_MAX+1];
	//}SocketHostInfo;

	/* ProtoType of DNS callback function*/
	/*typedef void (*SocketDnsCallback)(HDnsTr hDnsTr, SocketDnsError error, const SocketHostInfo* pHostInfo);
#ifdef _SHP_PROTO_IPV6
	typedef void (*SocketDnsGetAddrInfoCb)(HDnsTr hDnsTr, SocketDnsError error, const SocketAddrInfo* pHostInfo);
#endif*/



	HSocket	psptt_SocketCreate(int af, int type, int protocol);
	BOOL	psptt_SocketBind(HSocket hSocket, SockAddr *bindAddr);
	BOOL	psptt_SocketConnect(HSocket hSocket,SockAddr *peerAddr);
	BOOL	psptt_SocketClose(HSocket hSocket);

	/* Data */
	int		psptt_SocketSendTo(HSocket hSocket, char* pBuf, int bufLen, UINT32 option, SockAddr *destAddr);
	int		psptt_SocketRecvFrom(HSocket hSocket, char* pBuf, int bufLen, UINT32 option, SockAddr* pSourceAddr);
	int		psptt_SocketSend(HSocket hSocket, char* pBuf, int bufLen, UINT32 option);
	int		psptt_SocketRecv(HSocket hSocket, char* pBuf, int bufLen, UINT32 option);
      
	/* Socket I/O control, options and names */
	BOOL	psptt_SocketIoctl(HSocket hSocket, SocketIoctlCmd cmd, UINT32* pArg);
	int		psptt_SocketSelect(int width, SocketFdSet * pReadSet, SocketFdSet * pWriteSet, SocketFdSet * pExceptSet, const PTTTimeVal * pTimeout);


	BOOL	psptt_SocketSetSockOpt(HSocket hSocket, int level, int optName, const char* pOptVal, int optLen);
	BOOL	psptt_SocketGetSockOpt(HSocket hSocket, int level, int optName, char* pOptVal, int* pOptLen);
	BOOL	psptt_SocketGetSockName(HSocket hSocket, SockAddr* pSockName, int* pNameLen);
	BOOL	psptt_SocketGetPeerName(HSocket hSocket, SockAddr* pSockName, int* pNameLen);

	HDnsTr psptt_SocketGetHostByName(const char* szHostName, HOSTENT* pHostInfo);
	//HDnsTr psptt_SocketGetHostByAddr(HProtocol hProtocol, const Socket* pAddr, SocketDnsCallback dnsResInd);


	/* Convert an (Ipv4) Internet network address into a string, vice versa. */
	IPV4Addr	psptt_SocketInetAddr(char* szIpAddr);
	void		psptt_SocketInetNtoa(IPV4Addr sourceAddr, char* szIpAddr);

	/* Byte Order */
	UINT16	psptt_SocketHtons(UINT16 hostInt);
	UINT32	psptt_SocketHtonl(UINT32 hostInt);
	UINT16	psptt_SocketNtohs(UINT16 netInt);
	UINT32	psptt_SocketNtohl(UINT32 netInt);

	/* Server */
	BOOL	psptt_SocketListen(HSocket hSocket, int backLog);
	HSocket	psptt_SocketAccept(HSocket hSocket, SockAddr* pPeerAddr);
	BOOL	psptt_SocketGetPhoneIP(Socket* pSockName, int* pNameLen);

	
	void FD_ZERO(void* pSet);
	void shp_fd_set(int fd, void* pSet);
	void FD_CLR(int fd, void* pSet);
	int FD_ISSET(int fd, void* pSet);
	
#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif // _SOCKET_EXT_H_
//#endif
