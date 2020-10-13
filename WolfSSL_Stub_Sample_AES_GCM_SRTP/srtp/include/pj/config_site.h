// Kodiak POC changes on PJSip stack
#define PJSIP_HAS_KODIAK_POC_CHANGE   1
#define KODIAK_POC_EXTNS 1

/* Activate Android specific settings in the 'config_site_sample.h' */
//#define PJ_CONFIG_ANDROID 1
/*=====Mahantesh changes starts======*/
#ifdef MC_VIDEO_CHANGES
#if defined(PJ_ANDROID)
#define PJ_CONFIG_ANDROID 1
#elif defined(KN_IOS_BTR_OPT)
//#define PJ_CONFIG_IPHONE 1
#endif
#ifdef PJ_HAS_VIDEO
#define PJMEDIA_HAS_VIDEO 1
//#define PJMEDIA_HAS_OPENH264_CODEC 1
//#define PJMEDIA_HAS_LIBYUV 1
//#define PJMEDIA_VIDEO_DEV_HAS_SDL 1
//#define PJMEDIA_VIDEO_DEV_HAS_DSHOW 1
#endif
#endif
/*=====Mahantesh changes ends======*/

#include <pj/config_site_sample.h>

//MS-POCRADIO
//#define KN_MAX_SIMULATENOUS_SESSIONS 16
//#define KN_MAX_VIDEO_SESSIONS 2
#define PJSUA_MAX_CALLS			(KN_MAX_SIMULATENOUS_SESSIONS+KN_MAX_VIDEO_SESSIONS) /* Max Simultaneous calls to be supported */

/*=====Mahantesh changes starts======*/
#ifdef MC_VIDEO_CHANGES
#define KN_MAX_SIMULATENOUS_VIDEO_CALL_COUNT KN_MAX_SIMULATENOUS_SESSIONS
#endif
/*=====Mahantesh changes ends======*/

/* MUST use switchboard rather than the conference bridge */
#define PJMEDIA_CONF_USE_SWITCH_BOARD	1

/* To define Passthrough_dev.c file */
#define PJMEDIA_AUDIO_DEV_HAS_PASSTHRU_DEV 1

/* Only WMME supports the "direct" feature */
#define PJMEDIA_AUDIO_DEV_HAS_PORTAUDIO	0

/* To define usage of Third Party Voice Age codec */
#ifdef WIN32
#ifndef DISPATCHER_CHANGES
#define THIRD_PARTY_VOICE_AGE_CODEC_LICENSE 1
#endif
//#define THIRD_PARTY_VOICE_AGE_CODEC 1//Is disabled for using Kodiak PV AMR NB Codec

#define KODIAK_PV_AMR_NB_CODEC 0   /* Code added for integration of Kodiak PV AMR NB Codec */
#else
/* START - [64_BIT_PORTING : WIN-64 Adding]   */
#if !defined(WIN64)
//#define THIRD_PARTY_VOICE_AGE_CODEC_LICENSE 1
//#define THIRD_PARTY_VOICE_AGE_CODEC 0//Is disabled for using Kodiak PV AMR NB Codec

#define KODIAK_PV_AMR_NB_CODEC 1   /* Code added for integration of Kodiak PV AMR NB Codec */
#endif 
/* END - [64_BIT_PORTING : WIN-64 Adding]   */
#endif 
/* Enable passthrough codec framework */
#define PJMEDIA_HAS_PASSTHROUGH_CODECS	1

/* Only PCMA and PCMU are supported by WMME-direct */
#define PJMEDIA_HAS_PASSTHROUGH_CODEC_PCMU	0
#define PJMEDIA_HAS_PASSTHROUGH_CODEC_PCMA	0
#define PJMEDIA_HAS_PASSTHROUGH_CODEC_AMR	1
#define PJMEDIA_HAS_PASSTHROUGH_CODEC_G729	0
#define PJMEDIA_HAS_PASSTHROUGH_CODEC_ILBC	0
#define PJMEDIA_HAS_PASSTHROUGH_CODEC_OPUS	1
//Disable the Following Codecs
    #define PJMEDIA_HAS_L16_CODEC               0
    #define PJMEDIA_HAS_ILBC_CODEC              0
    #define PJMEDIA_HAS_G722_CODEC              0
    #define PJMEDIA_HAS_SPEEX_CODEC             0
#define PJMEDIA_HAS_GSM_CODEC              0

    /* For CPU reason, disable speex AEC and use the echo suppressor. */
    #define PJMEDIA_HAS_SPEEX_AEC               0

#ifdef WIN32
#ifndef POC_CDE_BREW
#define PJ_WIN32 1
#else
#define PJ_BREW 1
#undef WIN32
#undef PJ_WIN32
#endif 
#endif
/* START - [64_BIT_PORTING : WIN-64 Adding]   */
#ifdef WIN64
#ifndef POC_CDE_BREW
#define PJ_WIN64 1
#else
#define PJ_BREW 1
#undef WIN64
#undef PJ_WIN64
#endif
#endif 
/* END - [64_BIT_PORTING : WIN-64 Adding]   */

#define KN_SECURE_TRANSPORT		1
#ifdef KN_SECURE_TRANSPORT
#define PJMEDIA_HAS_SECURE_TRANSPORT_TLS_DTLS 1
#endif 

/*=====Mahantesh changes starts======*/
#ifdef MC_VIDEO_CHANGES
#define KN_MAX_SIMULATENOUS_VIDEO_CALL_COUNT KN_MAX_SIMULATENOUS_SESSIONS
#endif
//#define PJSUA_MAX_CALLS			KN_MAX_SIMULATENOUS_SESSIONS  /* Max Simultaneous calls to be supported */



/*=====Mahantesh changes ends======*/

#ifdef TICK_SOUND_ISSUE_FIX
#define TRACK_WITHOUT_THREAD_DESTROY 1
#endif 

#define IMSE_DEBUG  1

#define KN_DISCONNECT_CALL_ID_RECORD_ID_MATCH 0 //Code commented as Call Id and Record Id coming in TBCP DISCONNECT are wrong.

//#define PJ_MTK 1
