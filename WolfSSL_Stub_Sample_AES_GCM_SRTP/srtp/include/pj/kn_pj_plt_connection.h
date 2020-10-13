/*    The program (s) may be used or copied only with the permission of
 *                          SISO.
 *****************************************************************************
 *****************************************************************************
 NAME            : kn_pj_plt_connection.h
 REVISION        : 0.1
 DATE            : 12/01/2011
 AUTHOR          : 
 DESCRIPTION     : Has wrappers for socket related functions
 FILE TYPE       : C Header File
 *******************************************************************************
                                MODIFICATION HISTORY
 *******************************************************************************
  DATE            BASE              BUG#        AUTHOR          DESCRIPTION
  12/01/11						     sbiswambar          Initial Creation
 *******************************************************************************   
 ******************************************************************************/
#ifndef __KN_PJ_PLT_CONNECTIONS_H__
#define __KN_PJ_PLT_CONNECTIONS_H__

#ifdef _SHP_SIMUL_BUILD
#define _SHP_SIMUL 0 //TBD
#endif


#include "kn_plt_cstd_lib_wrap.h"
//#include "OemSocketExternal.h"
//#include "SdpSockExternal.h"

typedef signed char			INT8;
typedef unsigned char		UINT8;
typedef short				INT16;
typedef unsigned short		UINT16;
typedef unsigned int		UINT32;
typedef unsigned int		UINT;
typedef int					BOOL;

#define HObj int

#define FALSE 0
#define PROTO_IPV6_ADDR_LEN_MAX 16
#define PROTO_MSISDN_ADDR_LEN_MAX 21
#define PROTO_SERVCODE_ADDR_LEN_MAX 21
#define PROTO_APN_ADDR_LEN_MAX 64
#define PROTO_DIAL_NUMBER_LEN_MAX 32

//#include "ProtoMgrExternal.h"
#include "SocketExternal.h"
#include "socket_cust.h"


struct ptt_hostent {
  char    *h_name;	      /* official name of host */
  char    **h_aliases;    /* alias list */
  int     h_addrtype;     /* host address type */
  int     h_length;	      /* length of address */
  char    **h_addr_list;  /* list of addresses */
};

typedef SocketFdSet ptt_fd_set;
//typedef SocketTimeval SocketTimeval;

/*// Socket Type
#define SHP_SOCKET_TYPE_STREAM 	    SOCKET_TYPE_STREAM
#define SHP_SOCKET_TYPE_DATAGRAM    SOCKET_TYPE_DATAGRAM
#define SHP_SOCKET_TYPE_RAW	        SDP_SOCK_RAW

//Socket protocol type
#define SHP_SOCKET_PROTO_IP     SOCKET_PROTO_IP
#define SHP_SOCKET_PROTO_TCP	SOCKET_PROTO_TCP

//SocketLevels 
//#define SHP_SOCKET_SOL_SOCKET   SOCKET_SOL_SOCKET
//#define SHP_SOCKET_SOL_IP    	SOCKET_IPPROTO_IP
//#define SHP_SOCKET_SOL_PROTO_TCP SOCKET_IPPROTO_TCP
//#define SHP_SOCKET_PROTO_UDP    SOCKET_IPPROTO_TCP
//#define SHP_SOCKET_SOL_PROTO    SOCKET_SOL_PROTO
//#define SHP_SOCKET_PROTO_IPV6   0xFFFF*/

//int GetHostName(char *name, KN_UINT32 len);
//int  GetAddrInfo (const char * hostname, const char * servname, 
//const SocketAddrInfo * hints, SocketAddrInfo ** res);
//struct ptt_hostent *GetHostByName(const char *hostname);
//void FreeAddrInfo( SocketAddrInfo *ai);

#endif // __KN_PJ_PLT_CONNECTIONS_H__
