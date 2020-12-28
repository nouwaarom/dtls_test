/**
 * mbedtls config for dtls
 */
#ifndef MBEDTLS_CONFIG_H
#define MBEDTLS_CONFIG_H

/* System support */
//#define MBEDTLS_HAVE_TIME /* Optionally used in Hello messages */
/* Other MBEDTLS_HAVE_XXX flags irrelevant for this configuration */

#define MBEDTLS_DEBUG_C

/* mbed TLS feature support */
//#define MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
//#define MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED

#define MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED
//#define MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED
//ECDHE-RSA-AES128-GCM-SHA256

//#define MBEDTLS_ECP_DP_SECP256R1_ENABLED
//#define MBEDTLS_ECP_DP_SECP384R1_ENABLED
#define MBEDTLS_ECP_DP_BP384R1_ENABLED

#define MBEDTLS_SSL_PROTO_TLS1_2
#define MBEDTLS_SSL_PROTO_DTLS
#define MBEDTLS_SSL_DTLS_HELLO_VERIFY

/* mbed TLS modules */
#define MBEDTLS_RSA_C
#define MBEDTLS_AES_C
//#define MBEDTLS_CCM_C
#define MBEDTLS_GCM_C
#define MBEDTLS_ECP_C
#define MBEDTLS_ECDH_C
#define MBEDTLS_ECDSA_C
#define MBEDTLS_CIPHER_C
#define MBEDTLS_CIPHER_MODE_CBC
#define MBEDTLS_CTR_DRBG_C
#define MBEDTLS_ENTROPY_C
#define MBEDTLS_MD_C
#define MBEDTLS_NET_C
#define MBEDTLS_SHA256_C
#define MBEDTLS_SSL_CLI_C
#define MBEDTLS_SSL_SRV_C
#define MBEDTLS_SSL_TLS_C
#define MBEDTLS_ASN1_PARSE_C
#define MBEDTLS_ASN1_WRITE_C

#define MBEDTLS_SSL_COOKIE_C
#define MBEDTLS_X509_CRT_PARSE_C
#define MBEDTLS_X509_USE_C
#define MBEDTLS_ASN1_PARSE_C
#define MBEDTLS_PK_PARSE_C
#define MBEDTLS_PK_C

#define MBEDTLS_RSA_C
#define MBEDTLS_BIGNUM_C
#define MBEDTLS_OID_C
#define MBEDTLS_PKCS1_V15
#define MBEDTLS_PKCS1_V21

#define MBEDTLS_CERTS_C
#define MBEDTLS_PEM_PARSE_C
#define MBEDTLS_TIMING_C
#define MBEDTLS_BASE64_C

#define MBEDTLS_CIPHER_MODE_CBC
#define MBEDTLS_CIPHER_MODE_CTR

/* Save RAM at the expense of ROM */
#define MBEDTLS_AES_ROM_TABLES

/* Save some RAM by adjusting to your exact needs */
#define MBEDTLS_PSK_MAX_LEN    16 /* 128-bits keys are generally enough */

/*
 * You should adjust this to the exact number of sources you're using: default
 * is the "platform_entropy_poll" source, but you may want to add other ones
 * Minimum is 2 for the entropy test suite.
 */
#define MBEDTLS_ENTROPY_MAX_SOURCES 2

/*
 * Use only CCM_8 ciphersuites, and
 * save ROM and a few bytes of RAM by specifying our own ciphersuite list
 */
/* #define MBEDTLS_SSL_CIPHERSUITES MBEDTLS_TLS_PSK_WITH_AES_256_CCM_8 MBEDTLS_TLS_PSK_WITH_AES_128_CCM_8 */

/*
 * Save RAM at the expense of interoperability: do this only if you control
 * both ends of the connection!  (See comments in "mbedtls/ssl.h".)
 * The optimal size here depends on the typical size of records.
 */
#define MBEDTLS_SSL_MAX_CONTENT_LEN             2048

#include "mbedtls/check_config.h"

#endif /* MBEDTLS_CONFIG_H */
