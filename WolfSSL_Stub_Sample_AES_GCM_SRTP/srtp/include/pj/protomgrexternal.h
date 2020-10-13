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

#ifndef _PROTO_MGR_EXT_H_
#define _PROTO_MGR_EXT_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * Common data types used for portability across machine architectures
 * Note that this is written for an ARM7 using ARM C at the moment
 * Appropriate modification may need to be done for any other platform
 */
typedef	HObj		HProtocol;
typedef HObj		HSocket;
typedef UINT32		IPV4Addr;
typedef UINT8		IPV6Addr;
typedef UINT8		ServiceCodeAddr;
typedef UINT8 		MSISDNAddr;
typedef UINT16 		Port;
typedef UINT8		APN;

/* PACKED should be used to interface over FIFO. */
#if defined(_SHP_SIMUL)
#define PACKED
#else /* !_SHP_SIMUL */
#define PACKED __packed 
#endif /* _SHP_SIMUL */


/* Network/Bearer/Address Types */			 
typedef enum
{
	ANY_ANY_IPV4 						= 0x00,
	ANY_ANY_IPV6,
	GSM_USSD_MSISDN,
	GSM_SMS_MSISDN,
	IS136_GUTSRDATA_MSISDN,
	IS95CDMA_SMS_MSISDN,
	IS95CDMA_CSD_IPV4,
	IS95CDMA_PACKET_IPV4,
	IS136_CSD_IPV4,
	IS136_PACKET_IPV4,
	GSM_CSD_IPV4,
	GSM_GPRS_IPV4,
	GSM_USSD_IPV4,
	AMPS_CDPD_IPV4,
	PDC_CSD_IPV4,
	PDC_PACKET_IPV4,
	IDEN_SMS_MSISDN,
	IDEN_CSD_IPV4,
	IDEN_PACKET_IPV4,
	PAGER_FLEX_MSISDN,
	PHS_SMS_MSISDN,
	PHS_CSD_IPV4,
	GSM_USSD_SERVICECODE,
	TETRA_SDS_IDSI,
	TETRA_SDS_MSISDN,
	TETRA_PACKET_IPV4,
	ANY_CSD_IPV4,
	ANY_PSD_IPV4,
	ANY_SMS_MSISDN
} ProtoNBA;

/**
 * @brief	
 */
typedef PACKED union
{
	IPV4Addr			ipv4;											/**< Specifies an IPv4 address type. This type has four bytes. */
	IPV6Addr			ipv6[PROTO_IPV6_ADDR_LEN_MAX];					/**< Specifies an IPv6 address type. Tis type as 16 bytes. */
	/*WNChu_20041214; to get Orig Addr for Sharimar
	MSISDNAddr		msisdn[PROTO_MSISDN_ADDR_LEN_MAX+1];*/
	MSISDNAddr		msisdn[PROTO_MSISDN_ADDR_LEN_MAX*2+1];			/**< Used in SMS only. */
	ServiceCodeAddr	serviceCode[PROTO_SERVCODE_ADDR_LEN_MAX+1];	/**< Presents a service code used in GSM- USSD. */
	APN				apn[PROTO_APN_ADDR_LEN_MAX+1];					/**< Access point name used in GPRS APN */
	MSISDNAddr		szDialNumber[PROTO_DIAL_NUMBER_LEN_MAX+1];		/**< Pnone number in GSM CSD. Only digits and some special characters are allowed (e.g. '+').*/
} Address;

/**
 * @brief	Many of the socket functions work in terms of this structure. 
 * This type includes the address type, port name and Internet address(Network, Bearer and Address Type) of a socket.
 */
typedef PACKED struct
{
	ProtoNBA			type;						/**< Address type */
	Address 			address;						/**< Address including IPv4, IPv6, MSISDN, USSD and APN */
	Port				port;						/**< Specifies a network port - 16-bit data. */
} Socket;


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif // _PROTO_MGR_EXT_H_
