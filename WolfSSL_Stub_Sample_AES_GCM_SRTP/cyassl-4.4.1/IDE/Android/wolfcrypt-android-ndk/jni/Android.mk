
TOP_PATH   := $(call my-dir)/../../../../

# Compile wolfSSL shared library
# Assumes wolfcrypt-android-ndk directory is placed at:
# <wolfssl_package>/IDE/Android/wolfcrypt-android-ndk
include $(CLEAR_VARS)
LOCAL_PATH              := $(TOP_PATH)
LOCAL_MODULE            := libwolfssl
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
LOCAL_C_INCLUDES        := $(LOCAL_PATH)
LOCAL_C_INCLUDES        += $(LOCAL_PATH)/../../platform/inc/
LOCAL_C_INCLUDES        += $(LOCAL_PATH)/../../build/kodiak/android/platform/inc
LOCAL_C_INCLUDES        += $(LOCAL_PATH)/../../GHdr
LOCAL_CFLAGS            := -DNO_DSA -DNO_PSK -DNO_MD4 -DNO_HC128 \
                           -DNO_RABBIT -DWOLFSSL_SHA512 -DWOLFSSL_SHA384 \
                           -DHAVE_AESGCM -DHAVE_HASHDRBG \
						   -DWOLFSSL_DTLS -DHAVE_SNI \
                           -DHAVE_TLS_EXTENSIONS -DWOLFSSL_STATIC_RSA \
						   -DMSI_E2E -DWOLFSSL_KEY_GEN -DWOLFSSL_AES_DIRECT -DHAVE_AES_KEYWRAP \
						   -DWOLFSSL_PUB_PEM_TO_DER -DHAVE_RSA4096_SUPPORT -DHAVE_PKCS7 -DHAVE_X963_KDF \
                           -DHAVE_ECC -DWOLFSSL_JNI -DUSE_FAST_MATH -DWOLFSSL_ALLOW_TLSV10 -DWOLFSSL_DTLS_ALLOW_FUTURE \
						   -DWOLFCRYPT_HAVE_ECCSI -DWOLFSSL_PUBLIC_MP -DWOLFCRYPT_HAVE_SAKKE \
						   -DWOLFSSL_HAVE_SP_ECC -DWOLFSSL_SP_1024 -DWOLFSSL_HAVE_SP_RSA -DWOLFSSL_HAVE_SP_DH \
						   -DWOLFSSL_SP_ASM \
						   -Wall -Wno-unused \
						   
ifeq ($(TARGET_ARCH),arm64)
LOCAL_CFLAGS +=-DWOLFSSL_SP_ARM64_ASM
endif 

ifeq ($(TARGET_ARCH),arm)
LOCAL_CFLAGS +=-DWOLFSSL_SP_ARM32_ASM
endif

$(info $(APP_ABI))
$(info $(TARGET_ARCH))
$(warning $(LOCAL_CFLAGS))

						   
LOCAL_SRC_FILES         := ctaocrypt/src/wolfcrypt_first.c \
                           ctaocrypt/src/hmac.c \
                           ctaocrypt/src/random.c \
                           ctaocrypt/src/sha256.c \
                           ctaocrypt/src/rsa.c \
                           ctaocrypt/src/aes.c \
                           ctaocrypt/src/des3.c \
                           ctaocrypt/src/sha.c \
                           ctaocrypt/src/sha512.c \
                           ctaocrypt/src/fips.c \
                           ctaocrypt/src/fips_test.c \
                           ctaocrypt/src/wolfcrypt_last.c \
                           wolfcrypt/src/hmac.c \
                           wolfcrypt/src/random.c \
                           wolfcrypt/src/sha256.c \
						   wolfcrypt/src/hash.c \
                           wolfcrypt/src/rsa.c \
                           wolfcrypt/src/aes.c \
                           wolfcrypt/src/des3.c \
                           wolfcrypt/src/sha.c \
                           wolfcrypt/src/sha512.c \
                           wolfcrypt/src/logging.c \
                           wolfcrypt/src/wc_encrypt.c \
                           wolfcrypt/src/wc_port.c \
                           wolfcrypt/src/error.c \
                           wolfcrypt/src/signature.c \
                           wolfcrypt/src/memory.c \
                           wolfcrypt/src/dh.c \
                           wolfcrypt/src/asn.c \
					       wolfcrypt/src/coding.c \
                           wolfcrypt/src/arc4.c \
                           wolfcrypt/src/md5.c \
                           wolfcrypt/src/tfm.c \
                           wolfcrypt/src/ecc.c \
			   			   wolfcrypt/src/wolfmath.c \
						   wolfcrypt/src/pwdbased.c \
						   wolfcrypt/src/pkcs7.c \
						   wolfcrypt/src/pkcs12.c \
						   wolfcrypt/src/eccsi.c \
						   wolfcrypt/src/sakke.c \
                           src/internal.c \
                           src/wolfio.c \
                           src/keys.c \
                           src/ssl.c \
                           src/tls.c \
						   port/src/kn_asn_port.c \
						   port/src/kn_src_port.c \
						   wolfcrypt/src/sp_arm64.c \
						   wolfcrypt/src/sp_arm32.c \
						   wolfcrypt/src/sp_c64.c \
						   wolfcrypt/src/sp_c32.c \
						   wolfcrypt/src/sp_int.c
						   
include $(BUILD_SHARED_LIBRARY)

## Build wolfmikey library
include $(CLEAR_VARS)
LOCAL_PATH       := $(TOP_PATH)/../wolfmikey-0.5.0/
LOCAL_MODULE     := libwolfmikey
LOCAL_EXPORT_C_INCLUDES := $(TOP_PATH)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/
LOCAL_SRC_FILES  := src/error.c \
					src/misc.c \
					src/wolfmikey.c \

LOCAL_CFLAGS := -DNO_DSA -DNO_PSK -DNO_MD4 -DNO_HC128 \
                           -DNO_RABBIT -DWOLFSSL_SHA512 -DWOLFSSL_SHA384 \
                           -DHAVE_AESGCM -DHAVE_HASHDRBG \
						   -DWOLFSSL_DTLS -DHAVE_SNI \
                           -DHAVE_TLS_EXTENSIONS -DWOLFSSL_STATIC_RSA \
						   -DMSI_E2E -DWOLFSSL_KEY_GEN -DWOLFSSL_AES_DIRECT -DHAVE_AES_KEYWRAP \
						   -DWOLFSSL_PUB_PEM_TO_DER -DHAVE_RSA4096_SUPPORT -DHAVE_PKCS7 -DHAVE_X963_KDF \
                           -DHAVE_ECC -DWOLFSSL_JNI -DUSE_FAST_MATH -DWOLFSSL_ALLOW_TLSV10 -DWOLFSSL_DTLS_ALLOW_FUTURE \
						   -DWOLFCRYPT_HAVE_ECCSI -DWOLFSSL_PUBLIC_MP -DWOLFCRYPT_HAVE_SAKKE \
						   -DWOLFSSL_HAVE_SP_ECC -DWOLFSSL_SP_1024 -DWOLFSSL_HAVE_SP_RSA -DWOLFSSL_HAVE_SP_DH \
						   -DWOLFSSL_SP_ASM \
						   -Wall -Wno-unused \

ifeq ($(TARGET_ARCH),arm64)
LOCAL_CFLAGS +=-DWOLFSSL_SP_ARM64_ASM
endif 

ifeq ($(TARGET_ARCH),arm)
LOCAL_CFLAGS +=-DWOLFSSL_SP_ARM32_ASM
endif

LOCAL_SHARED_LIBRARIES := libwolfssl
include $(BUILD_SHARED_LIBRARY)