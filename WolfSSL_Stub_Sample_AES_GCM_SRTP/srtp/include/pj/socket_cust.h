#ifndef INET_SOCKET_H
#define INET_SOCKET_H

#ifdef __cplusplus
extern "C"
   {
#endif

//#include "uta_types.h"
//#include "uta_io.h"
//#include "uta_sock.h"
//#include"Kn_pj_plt_connection.h"
/**
@defgroup module_osfcomm_sockets Sockets Protocol Manager API.
@ingroup module_osfcomm

This is the API of the Sockets Protocol Manager.
For a high-level description of this PM, see @ref pg_sockets.
@{
*/

/*---------------------------- Global Defines: ---------------------------*/

#define  SOL_SOCKET  0xffff
#define IPPROTO_IP      0
#define IPPROTO_TCP     6
#define IPPROTO_UDP     17
#define IPPROTO_IPV6    41

/*
 * Options for level IPPROTO_IP
 */
#define IP_TOS       1
#define IP_TTL       2

#define IPTOS_TOS_MASK          0x1E
#define IPTOS_TOS(tos)          ((tos) & IPTOS_TOS_MASK)
#define IPTOS_LOWDELAY          0x10
#define IPTOS_THROUGHPUT        0x08
#define IPTOS_RELIABILITY       0x04
#define IPTOS_LOWCOST           0x02
#define IPTOS_MINCOST           IPTOS_LOWCOST

/*
 * Definitions for IP precedence (also in ip_tos) (hopefully unused)
 */
#define IPTOS_PREC_MASK                 0xe0
#define IPTOS_PREC(tos)                ((tos) & IPTOS_PREC_MASK)
#define IPTOS_PREC_NETCONTROL           0xe0
#define IPTOS_PREC_INTERNETCONTROL      0xc0
#define IPTOS_PREC_CRITIC_ECP           0xa0
#define IPTOS_PREC_FLASHOVERRIDE        0x80
#define IPTOS_PREC_FLASH                0x60
#define IPTOS_PREC_IMMEDIATE            0x40
#define IPTOS_PREC_PRIORITY             0x20
#define IPTOS_PREC_ROUTINE              0x00



/*
 * Additional options, not kept in so_options.
 */
#define SO_SNDBUF  0x1001    /* send buffer size */
#define SO_RCVBUF  0x1002    /* receive buffer size */
#define SO_SNDLOWAT  0x1003    /* send low-water mark */
#define SO_RCVLOWAT  0x1004    /* receive low-water mark */
#define SO_SNDTIMEO  0x1005    /* send timeout */
#define SO_RCVTIMEO  0x1006    /* receive timeout */
#define  SO_ERROR  0x1007    /* get error status and clear */
#define  SO_TYPE    0x1008    /* get socket type */
#define  SO_TCPWNDSCALE 0x1009

#define	TCP_NODELAY	   0x01	   /* don't delay send to coalesce packets */
#define TCP_KEEPALIVE  0x02    /* send KEEPALIVE probes when idle for pcb->keepalive miliseconds */
#define TCP_MAXSEG     0x04   /* Modify TCP Max Segment Size option */

/* Keepalive values */
#define  TCP_KEEPDEFAULT   7200000                       /* KEEPALIVE timer in miliseconds */
#define  TCP_KEEPINTVL     75000                         /* Time between KEEPALIVE probes in miliseconds */
#define  TCP_KEEPCNT       9                             /* Counter for KEEPALIVE probes */
#define  TCP_MAXIDLE       (TCP_KEEPCNT * TCP_KEEPINTVL)   /* Maximum KEEPALIVE probe time */

#define IP_MULTICAST_IF    0x20
#define IP_MULTICAST_TTL   0x21
#define IP_MULTICAST_LOOP  0x22
#define IP_ADD_MEMBERSHIP  0x23
#define IP_DROP_MEMBERSHIP 0x24

#define  SO_DEBUG  0x0001    /* turn on debugging info recording */
#define  SO_ACCEPTCONN  0x0002    /* socket has had listen() */
#define  SO_REUSEADDR  0x0004    /* allow local address reuse */
#define  SO_KEEPALIVE  0x0008    /* keep connections alive */
#define  SO_DONTROUTE  0x0010    /* just use interface addresses */
#define  SO_BROADCAST  0x0020    /* permit sending of broadcast msgs */
#define  SO_USELOOPBACK  0x0040    /* bypass hardware when possible */
#define  SO_LINGER  0x0080    /* linger on close if data present */
#define  SO_OOBINLINE  0x0100    /* leave received OOB data in line */
#define	 SO_REUSEPORT	0x0200		/* allow local address & port reuse */

#define SO_DONTLINGER   (int)(~SO_LINGER)


/**
@name Address families
*/
/*@{ */
#define AF_RESERVED      0      /**< Reserved address family.  */
#define AF_INET4          4      /**< Internet.  */
#define AF_INET6         6      /**< Internet 6.  */
/*@}*/

#define   PROF_IPV4_TYPE 0x0
#define   PROF_IPV6_TYPE 0x1
#define   PROF_IPV4V6_TYPE 0x2

/**
@name Protocol families
*/
/*@{ */
#define PF_RESERVED   AF_RESERVED   /**< @ref AF_RESERVED */
#define PF_INET       AF_INET   /**< @ref AF_INET */
#define PF_INET6      AF_INET6  /**< @ref AF_INET6 */
/*@}*/

/**
@name Protocol codes (standard IP protocol assigned numbers, excerpt)
*/
/*@{ */
#define IPPROTO_DEFAULT  0      /**< Default protocol for SocketOpen() */

#define IPPROTO_ICMP     1      /**< Internet Control Message Protocol */
#define IPPROTO_TCP      6      /**< Transmission Control Protocol     */
#define IPPROTO_UDP     17      /**< User Datagram Protocol            */
#define IPPROTO_ICMP6   58      /**< ICMPv6                            */
/*@}*/

/**
@name Useful address definitions
*/
/*@{ */
#define INADDR_ANY              ( ( UINT32 ) 0x00000000 )   /**< Any address. */
#define INADDR_NONE             ( ( UINT32 ) 0xFFFFFFFF )   /**< Bad address. */
#define INADDR_BROADCAST        ( ( UINT32 ) 0xFFFFFFFF )   /**< Broadcast. */
/*@}*/

/**
@name Socket types
*/
/*@{ */
#define SOCK_RESERVED    0      /**< Reserved socket. */
#define SOCK_STREAM      1      /**< Stream  socket. */
#define SOCK_DGRAM       2      /**< Dgram  socket. */
#define SOCK_RAW         3      /**< Raw socket. */
#define SOCK_RAW6        4      /**< Raw 6 socket. */
#define SOCK_IPC_STREAM  5      /**< IPC Stream  socket.*/
#define SOCK_IPC_DGRAM   6      /**< IPC Dgram  socket.*/
/*@}*/

/**
@name Friendly socket type aliases
*/
/*@{ */
#define SOCK_TCP         SOCK_STREAM   /**< TCP socket */
#define SOCK_UDP         SOCK_DGRAM /**< DGRAM socket */
#define SOCK_IPC_TCP         SOCK_IPC_STREAM   /**< TCP socket */
#define SOCK_IPC_UDP         SOCK_IPC_DGRAM /**< DGRAM socket */
#define SOCK_IPv4        SOCK_RAW   /**< RAW socket */
#define SOCK_IPv6        SOCK_RAW6  /**< RAW 6 socket */
/*@}*/

/**
@defgroup osfcomm_sockets_socket_states Socket state flags
These flags represent possible states a socket can be in.
The relevant bit of the state variable is set to denote a new state.
@{
*/
//JB  #define SOCK_STATE_OPENING      ( 1 << 0 )   /**< Open in progress. */
#define SOCK_STATE_OPENED       ( 1 << 1 )   /**<  Open confirmed.    */
//JB  #define SOCK_STATE_BINDING      ( 1 << 2 )   /**<  Bind in progress.  */
#define SOCK_STATE_BOUND        ( 1 << 3 )   /**<  Bind confirmed.    */
#define SOCK_STATE_CONNECTING   ( 1 << 4 )   /**<  Conn in progress. */
#define SOCK_STATE_CONNECTED    ( 1 << 5 )   /**<  Conn cnf -> Ready. */
#define SOCK_STATE_LISTENING    ( 1 << 6 )   /**<  Listen confirmed. */
#define SOCK_STATE_CLOSING      ( 1 << 7 )   /**<  Close in progress. */
#define SOCK_STATE_CLOSED       ( 1 << 8 )   /**<  Close confirmed.   */
#define SOCK_STATE_READABLE     ( 1 << 9 )   /**<  Ready & Rx !empty. */
#define SOCK_STATE_WRITABLE     ( 1 << 10 )  /**<  Ready & Tx !full.  */
/**@}*/

/**
 * Socket options  - derived from ipsock.h
 */
#define SO_TTL                   ( 1 << 0 )
//#define SO_KEEPALIVE             ( 1 << 1 )
#if defined (__SEC_INET_IFACE__)
/* ffr/061122: OCR00019985   "TCP/IP: Keep Alive not implemented" => SO_KEEPALIVE has been added => need to change defines below */
#define SO_SENDBUF               ( 1 << 2 )
#define SO_RCVBUF                ( 1 << 3 )
#define SO_LINGER                ( 1 << 4 )
#endif

#define SOCKET_LISTEN_BACKLOG_MAX          5

#define SOCKOP_SUCCESS                     0
#define SOCKERR_SOCKET_NOT_FOUND          -1
#define SOCKERR_UNDEFINED_OPERATION       -2
#define SOCKERR_BAD_SOCKET_TYPE           -3
#define SOCKERR_INCOMPATIBLE_SOCKET_TYPE  -4
#define SOCKERR_TOO_MANY_SOCKETS          -5
#define SOCKERR_BAD_DOMAIN                -6
#define SOCKERR_ALREADY_BOUND             -7
#define SOCKERR_ALREADY_CONNECTED         -8
#define SOCKERR_NOT_BOUND_AND_CONNECTED   -9
#define SOCKERR_NO_DATA                   -10
#define SOCKERR_SEND_BUFFER_FULL          -11
#define SOCKERR_BAD_ADDRESS_PARAMETER     -12
#define SOCKERR_BAD_BACKLOG_PARAMETER     -13
#define SOCKERR_UNKNOWN_SOCKET_TYPE       -14


/*
 * DNS status codes
 */
#define DNS_SUCCESS               0 /* no error */

/* Name Server error codes */
#define DNS_ERR_NODATA           -1 /* no relevant answer */
#define DNS_ERR_FORMERR          -2 /* data format error  */
#define DNS_ERR_SERVFAIL         -3 /* server failure     */
#define DNS_ERR_NXDOMAIN         -4 /* non existant domain */
#define DNS_ERR_NOTIMP           -5 /* not implemented    */
#define DNS_ERR_REFUSED          -6 /* query refused      */

/* Locally generated error codes */
#define DNS_ERR_NOTFOUND         -7 /* server not found   */
#define DNS_ERR_SOCKET           -8 /* socket error       */
#define DNS_ERR_TOOMANY          -9 /* too many queries   */
#define DNS_ERR_BADPARAM        -10 /* bad parameter      */
#define DNS_ERR_BADADDR         -11 /* bad address name   */
#define DNS_ERR_BADNAME         -12 /* bad host name      */
#define DNS_ERR_BADRESP         -13 /* bad response       */
#define DNS_ERR_UNREACH         -14 /* server unreachable */
#define DNS_ERR_TIMEOUT         -15 /* timeout, no answer */

#if defined (__SEC_INET_IFACE_CATFISH__)
/* Added in Catfish */
#define DNS_FAILURE             -1  /* DNS failed */
#define DNS_ERR_OUT_OF_MEMORY   -16 /* out of memory */
#endif

#if defined (__SEC_INET_IFACE__)
#define __DNS_CACHE__
#define __NEGATIVE_DNS_CACHE__
#endif


//typedef unsigned char UINT8;
//typedef unsigned short UINT16;
//typedef unsigned long UINT32;


/*
 * The (standard) structure containing a host entry
 */

  typedef struct HOSTENT
      {
      char *h_name;            /* official name of host */
      char **h_aliases;        /* alias list            */
      char h_addrtype;         /* host address type     */
      char h_length;           /* length of address     */
      char **h_addr_list;      /* list of addresses     */
      char i_cnt_aliases;
      }HOSTENT;

/*---------------------------- Global Typedefs: --------------------------*/

/**
Internet Address - IPv4.
*/

   struct In_Addr
      {
      unsigned int s_addr;            /**< 4 byte IPv4 address */
      };

/**
Internet Address - IPv6.
*/

   struct In6_Addr
      {
      unsigned int s6_addr[4];        /**< 4 byte IPv6 address */
      };


/**
Socket Internet Address - IPv4.
This is a common user-level type used with sockets.
*/
   struct SockAddr_In
      {
      unsigned short sin_family;        /**< AF_INET.  */
      unsigned short sin_port;          /**< Port No.   */
      struct In_Addr sin_addr;  /**< IPv4 addr */
      unsigned char _padding[16];   /**< Padding. */
      };

/* Socket address, internet style. */
/*
typedef struct UtaSockAddr_in {
     UtaUInt8 sin_len;
     UtaUInt8 sin_family;
     UtaUInt16 sin_port;
     struct In_Addr sin_addr;
     char sin_zero[8];
}   UtaSockAddr_in;
*/
/*
///< BSD compatible IPv4 internet address structure.
typedef struct UtaInetInAddr {
  UtaUInt32 s_addr;  ///< Binary IP address.
} UtaInetInAddr;

///<  Socket address structure for internet address family.
typedef struct UtaInetSockAddrIn {
  UtaSockAddr generic;
  UtaUInt16 sin_port;
  UtaInetInAddr sin_addr;
  UtaChar sin_zero[8];
} UtaInetSockAddrIn;
*/

/**
Socket Internet Address - IPv6.
This is a common user-level type used with sockets.
*/
   struct SockAddr_In6
      {
      unsigned short sin6_family;       /* AF_INET6  */
      unsigned short sin6_port;         /* Port No   */
      struct In6_Addr sin6_addr;/* IPv6 addr */
      };

/**
Generic Socket Address.
This is a common user-level type used with sockets.
*/
  typedef struct SockAddr
      {
     unsigned short sa_family;         /**< AF_INET, AF_INET6. */
     unsigned short sa_port;           /**< Port no. */
      unsigned char sa_addr[sizeof( struct SockAddr_In6 ) - 2 * sizeof(unsigned short )]; /**< Padding. */
      }SockAddr;


/**
Socket events.
Completed operations (confirmed) by IP stack.
*/

   typedef enum
      {
      SOCK_EV_DUMMY = 0,        /**< Dummy. */
      SOCK_EV_OPEN,             /**< Open completed.  */
      SOCK_EV_BIND,             /**< Bind completed.  */
      SOCK_EV_CONNECT,          /**< Connect  completed.      */
      SOCK_EV_LISTEN,           /**< Listen completed.     */
      SOCK_EV_ACCEPT,           /**< Accept completed.     */
      SOCK_EV_CLOSE,            /**< Close completed.      */

      SOCK_EV_PENDING           /**< There is a pending connection on a listening socket (to be accepted). */

      }     SOCKET_EVENT;


/**
Failure events.
Non-completed operations (rejected) by IP stack.
*/
   typedef enum
      {
      SOCK_ERR_DUMMY = 1,       /**< Dummy value. */
      SOCK_ERR_OPEN,            /**< Open failed.    */
      SOCK_ERR_BIND,            /**< Bind  failed.    */
      SOCK_ERR_CONNECT,         /**< Connect  failed.      */
      SOCK_ERR_LISTEN,          /**< Listen failed. */
      SOCK_ERR_ACCEPT,          /**< Accept failed.      */
      SOCK_ERR_CLOSE,           /**< Close failed.     */
      SOCK_ERR_SEND,            /**< Send(to) failed.  */
      SOCK_ERR_SETOPT,          /**< Setopt failed.      */

      SOCK_ERR_UNKNOWN,         /**< Unknown internal error.  */
      SOCK_ERR_FATAL,           /**< Fatal error.             */
      SOCK_ERR_NOSOCK,          /**< Socket unknown.          */
      SOCK_ERR_UNREACH,         /**< Destination unreachable. */
      SOCK_ERR_NOTCONN,         /**< Not connected.           */
      SOCK_ERR_ADDRINUSE,       /**< Address in use.          */
      SOCK_ERR_ABORT,           /**< Connection aborted.     */
      SOCK_ERR_ALREADY,         /**< Already connected.      */
      SOCK_ERR_REFUSED,         /**< Connection refused.      */
      SOCK_ERR_TIMEOUT,          /**< Connection timed out.    */
#if defined (__SEC_INET_IFACE_CATFISH__)
      SOCK_ERR_ACCESS      ,      /**< Permission denied.                         */
      SOCK_ERR_ADDRNOTAVAIL,     /**< Cannot assign requested address.           */
      SOCK_ERR_AFNOSUPPORT ,     /**<Address family not supported by protocol.   */
      SOCK_ERR_BADF        ,     /**< File descriptor in bad state.              */
      SOCK_ERR_CONNRESET   ,     /**<Connection reset by peer.                   */
      SOCK_ERR_DESTADDRREQ ,     /**< Destination address required.              */
      SOCK_ERR_FAULT       ,     /**< Bad address.                               */
      SOCK_ERR_HOSTDOWN    ,     /**< Host is down.                              */
      SOCK_ERR_HOSTUNREACH ,     /**< No route to host.                          */
      SOCK_ERR_INPROGRESS  ,     /**< Operation now in progress.                 */
      SOCK_ERR_INTR        ,     /**< Interrupted system call.                   */
      SOCK_ERR_INVAL       ,     /**<  Invalid argument.                         */
      SOCK_ERR_ISCONN      ,     /**< Transport endpoint is already connected.   */
      SOCK_ERR_MFILE       ,     /**< Too many open files.                       */
      SOCK_ERR_MSGSIZE     ,     /**< Message too long.                          */
      SOCK_ERR_NETDOWN     ,     /**< Network is down.                           */
      SOCK_ERR_NETRESET    ,     /**< Network dropped connection because of reset.  */
      SOCK_ERR_NETUNREACH  ,     /**<Network is unreachable.                     */
      SOCK_ERR_NOBUFS      ,     /**< No buffer space available.                 */
      SOCK_ERR_NOPROTOOPT  ,     /**< Protocol not available.                    */
      SOCK_ERR_NOTSOCK     ,     /**< Socket operation on non-socket.            */
      SOCK_ERR_OPNOTSUPP   ,     /**< Operation not supported on transport endpoint. */
      SOCK_ERR_PFNOSUPPORT ,     /**< Protocol family not supported.             */
      SOCK_ERR_PROTONOSUPPORT ,  /**< Protocol not supported.                    */
      SOCK_ERR_PROTOTYPE   ,     /**< Protocol wrong type for socket.            */
      SOCK_ERR_SHUTDOWN    ,     /**< Cannot send after transport endpoint shutdown. */
      SOCK_ERR_SOCKTNOSUPPORT ,  /**< Socket type not supported.                 */
      SOCK_ERR_WOULDBLOCK  ,     /**< Operation would block.                     */
#ifndef FEAT_SECURE_SOCKET
      SOCK_ERR_SPECIFIC    ,     /**< Last entry.                                */
#else
      SOCK_ERR_SEC_SSLERROR,     /**< A failure in the TLS library occurred, usually a protocol error */
      SOCK_ERR_SEC_ERRFILE,      /**< On file read failure                       */
      SOCK_ERR_SPECIFIC        /**< Last entry.                                */
#endif

#endif  //  __SEC_INET_IFACE_CATFISH__

}     SOCKET_ERROR;

/*---------------------------- Global Variables: -------------------------*/

/*----------------------- Global Function Prototypes: --------------------*/



/*------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*/

/**@}*/

#ifdef __cplusplus
   }

#endif

#endif                          /* SOCKET_H */
