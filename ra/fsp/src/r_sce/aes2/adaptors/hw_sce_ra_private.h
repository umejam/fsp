/***********************************************************************************************************************
 * Copyright [2020-2023] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#ifndef HW_SCE_RA_PRIVATE_HEADER_FILE
#define HW_SCE_RA_PRIVATE_HEADER_FILE

#include "hw_sce_aes_private.h"

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

#define SIZE_AES_GCM_IN_DATA_BYTES                       (256)
#define SIZE_AES_GCM_IN_DATA_IV_LEN_BYTES                (16)
#define SIZE_AES_GCM_IN_DATA_IV_GCM_LEN_BYTES            (128)
#define SIZE_AES_GCM_IN_DATA_AAD_LEN_BYTES               (128)

#define SCE_AES_IN_DATA_CMD_ECB_ENCRYPTION               (0x00000000U)
#define SCE_AES_IN_DATA_CMD_ECB_DECRYPTION               (0x00000001U)
#define SCE_AES_IN_DATA_CMD_CBC_ENCRYPTION               (0x00000002U)
#define SCE_AES_IN_DATA_CMD_CBC_DECRYPTION               (0x00000003U)
#define SCE_AES_IN_DATA_CMD_CTR_ENCRYPTION_DECRYPTION    (0x00000004U)

/* Wrapped keys not supported on RA2; these definitions are added to let the code compile. */
#define SIZE_AES_128BIT_KEYLEN_BITS_WRAPPED              (1)
#define SIZE_AES_128BIT_KEYLEN_BYTES_WRAPPED             ((SIZE_AES_128BIT_KEYLEN_BITS_WRAPPED) / 8)
#define SIZE_AES_128BIT_KEYLEN_WORDS_WRAPPED             ((SIZE_AES_128BIT_KEYLEN_BITS_WRAPPED) / 32)

#define SIZE_AES_192BIT_KEYLEN_BITS_WRAPPED              (2) /* 192 not supported on SCE5 */
#define SIZE_AES_192BIT_KEYLEN_BYTES_WRAPPED             ((SIZE_AES_192BIT_KEYLEN_BITS_WRAPPED) / 8)
#define SIZE_AES_192BIT_KEYLEN_WORDS_WRAPPED             ((SIZE_AES_192BIT_KEYLEN_BITS_WRAPPED) / 32)

#define SIZE_AES_256BIT_KEYLEN_BITS_WRAPPED              (3)
#define SIZE_AES_256BIT_KEYLEN_BYTES_WRAPPED             ((SIZE_AES_256BIT_KEYLEN_BITS_WRAPPED) / 8)
#define SIZE_AES_256BIT_KEYLEN_WORDS_WRAPPED             ((SIZE_AES_256BIT_KEYLEN_BITS_WRAPPED) / 32)

#define R_AES_AESCNTH_INIT                               (0x8000UL) /*!< AESCNTH initialization: Initialization AES Circuit                                                               */
#define R_AES_AESCNTH_DEINIT                             (0x0000UL) /*!< AESCNTH deinitialization: Don’t Initialize AES Circuit                                                           */
#define R_AES_AESCNTL_GCM_MODE                           (0x00A0UL) /*!< AESCNTL: Assign bit of Cipher use Mode: GCM mode                                                                 */
#define R_AES_AESCNTL_128_DEC                            (0x0008UL) /*!< AESCNTL: Decryption 128 bit (Bit 0-3 Selection bit of Encryption/Decryption and Key Length)                      */

#define R_AES_AESCNTL_CBC_128_ENC                        (0x0000UL) /*!< AESCNTL: Encryption - CBC mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CBC_192_ENC                        (0x0002UL) /*!< AESCNTL: Encryption - CBC mode - 192 bits                                                                        */
#define R_AES_AESCNTL_CBC_256_ENC                        (0x0004UL) /*!< AESCNTL: Encryption - CBC mode - 256 bits                                                                        */
#define R_AES_AESCNTL_CBC_128_DEC                        (0x0008UL) /*!< AESCNTL: Decryption - CBC mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CBC_192_DEC                        (0x000AUL) /*!< AESCNTL: Decryption - CBC mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CBC_256_DEC                        (0x000CUL) /*!< AESCNTL: Decryption - CBC mode - 128 bits                                                                        */

#define R_AES_AESCNTL_ECB_128_ENC                        (0x0010UL) /*!< AESCNTL: Encryption - ECB mode - 128 bits                                                                        */
#define R_AES_AESCNTL_ECB_192_ENC                        (0x0012UL) /*!< AESCNTL: Encryption - ECB mode - 192 bits                                                                        */
#define R_AES_AESCNTL_ECB_256_ENC                        (0x0014UL) /*!< AESCNTL: Encryption - ECB mode - 256 bits                                                                        */
#define R_AES_AESCNTL_ECB_128_DEC                        (0x0018UL) /*!< AESCNTL: Decryption - ECB mode - 128 bits                                                                        */
#define R_AES_AESCNTL_ECB_192_DEC                        (0x001AUL) /*!< AESCNTL: Decryption - ECB mode - 128 bits                                                                        */
#define R_AES_AESCNTL_ECB_256_DEC                        (0x001CUL) /*!< AESCNTL: Decryption - ECB mode - 128 bits                                                                        */

#define R_AES_AESCNTL_CTR_128_ENC                        (0x0040UL) /*!< AESCNTL: Encryption - CTR mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CTR_192_ENC                        (0x0042UL) /*!< AESCNTL: Encryption - CTR mode - 192 bits                                                                        */
#define R_AES_AESCNTL_CTR_256_ENC                        (0x0044UL) /*!< AESCNTL: Encryption - CTR mode - 256 bits                                                                        */
#define R_AES_AESCNTL_CTR_128_DEC                        (0x0048UL) /*!< AESCNTL: Decryption - CTR mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CTR_192_DEC                        (0x004AUL) /*!< AESCNTL: Decryption - CTR mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CTR_256_DEC                        (0x004CUL) /*!< AESCNTL: Decryption - CTR mode - 128 bits                                                                        */

#define R_AES_AESCNTL_CMAC_128_ENC                       (0x0080UL) /*!< AESCNTL: Encryption - CMAC mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CMAC_192_ENC                       (0x0082UL) /*!< AESCNTL: Encryption - CMAC mode - 192 bits                                                                        */
#define R_AES_AESCNTL_CMAC_256_ENC                       (0x0084UL) /*!< AESCNTL: Encryption - CMAC mode - 256 bits                                                                        */
#define R_AES_AESCNTL_CMAC_128_DEC                       (0x0088UL) /*!< AESCNTL: Decryption - CMAC mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CMAC_192_DEC                       (0x008AUL) /*!< AESCNTL: Decryption - CMAC mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CMAC_256_DEC                       (0x008CUL) /*!< AESCNTL: Decryption - CMAC mode - 128 bits                                                                        */

#define R_AES_AESCNTL_GCM_128_ENC                        (0x00A0UL) /*!< AESCNTL: Encryption - GCM mode - 128 bits                                                                        */
#define R_AES_AESCNTL_GCM_192_ENC                        (0x00A2UL) /*!< AESCNTL: Encryption - GCM mode - 192 bits                                                                        */
#define R_AES_AESCNTL_GCM_256_ENC                        (0x00A4UL) /*!< AESCNTL: Encryption - GCM mode - 256 bits                                                                        */
#define R_AES_AESCNTL_GCM_128_DEC                        (0x00A8UL) /*!< AESCNTL: Decryption - GCM mode - 128 bits                                                                        */
#define R_AES_AESCNTL_GCM_192_DEC                        (0x00AAUL) /*!< AESCNTL: Decryption - GCM mode - 128 bits                                                                        */
#define R_AES_AESCNTL_GCM_256_DEC                        (0x00ACUL) /*!< AESCNTL: Decryption - GCM mode - 128 bits                                                                        */

#define R_AES_AESCNTL_CCM_128_ENC                        (0x00C0UL) /*!< AESCNTL: Encryption - CCM mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CCM_192_ENC                        (0x00C2UL) /*!< AESCNTL: Encryption - CCM mode - 192 bits                                                                        */
#define R_AES_AESCNTL_CCM_256_ENC                        (0x00C4UL) /*!< AESCNTL: Encryption - CCM mode - 256 bits                                                                        */
#define R_AES_AESCNTL_CCM_128_DEC                        (0x00C8UL) /*!< AESCNTL: Decryption - CCM mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CCM_192_DEC                        (0x00CAUL) /*!< AESCNTL: Decryption - CCM mode - 128 bits                                                                        */
#define R_AES_AESCNTL_CCM_256_DEC                        (0x00CCUL) /*!< AESCNTL: Decryption - CCM mode - 128 bits                                                                        */

#define R_AES_AESDCNTL_ASSIGN_DATA_DISABLE               (0x0004UL) /*!< AESDCNTL: Bit to assign Data to update/no-update                                                                 */
#define R_AES_AESDCNTL_BIT_2_3_MODE_1                    (0x0008UL) /*!< AESDCNTL: Key update assign bit: Enable + First block contents control assign bit: Use (AES-ECB, AES-GCM)        */
#define R_AES_AESDCNTL_BIT_2_3_MODE_2                    (0x000CUL) /*!< AESDCNTL: Key update assign bit: Enable + First block contents control assign bit: Not use (AES-CBC, AES-CTR)    */
#define R_AES_AESDCNTL_CALCULATE_START                   (0x0003UL) /*!< AESDCNTL: Start AES calculation - Start reflect AES Encryption/Decryption calculation result to AESODATnRegister.*/
#define R_AES_AESDCNTL_BIT_2                             (0x0004UL) /*!< AESDCNTL: Bit 2                                                                                                  */
#define R_AES_AESDCNTL_BIT_4                             (0x0010UL) /*!< AESDCNTL: Bit 4                                                                                                  */
#define R_AES_AESDCNTL_BIT_5                             (0x0020UL) /*!< AESDCNTL: Bit 5                                                                                                  */
#define R_AES_AESDCNTL_BIT_6                             (0x0040UL) /*!< AESDCNTL: Bit 6                                                                                                  */
#define R_AES_AESSTSL_BIT_5                              (0x0020UL) /*!< AESSTSL: Bit 5: Status Bit to show AES operation status                                                          */
#define R_AES_AESSTSL_CALCULATE_COMPLETED                (0x0003UL) /*!< AESSTSL: Bit 0-1: Status Bit to show AES Encryption/Decryption completion                                        */
#define R_AES_AESSTSCL_DATA_CLEAN                        (0x0003UL) /*!< AESSTSCL: Bit 0-1: clear bit1.0 state in AES Status Register                                                     */

/**********************************************************************************************************************
 * Global Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * External global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions
 *********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/
uint32_t  change_endian_long(uint32_t data);
void      tc_aes_set_key(uint8_t * key, uint32_t KeyLen);
void      tc_aes_set_iv(uint8_t * initialize_vetor);
void      tc_aes_start(uint8_t * input, uint8_t * output, uint32_t block);
fsp_err_t tc_gcm_calculation(uint8_t * input,
                             uint8_t * output,
                             uint32_t  data_len,
                             uint8_t * atag,
                             uint8_t * initial_vector,
                             uint32_t  iv_len,
                             uint8_t * aad,
                             uint32_t  aad_len);
fsp_err_t HW_SCE_Aes128EncryptDecryptInitSub(const uint32_t * InData_KeyType,
                                             const uint32_t * InData_Cmd,
                                             const uint32_t * InData_KeyIndex,
                                             const uint32_t * InData_IV);
void HW_SCE_Aes128EncryptDecryptUpdateSub(const uint32_t * InData_Text,
                                          uint32_t       * OutData_Text,
                                          const uint32_t   MAX_CNT);
fsp_err_t HW_SCE_Aes128EncryptDecryptFinalSub(void);

fsp_err_t HW_SCE_Aes192EncryptDecryptInitSub(const uint32_t * InData_Cmd,
                                             const uint32_t * InData_KeyIndex,
                                             const uint32_t * InData_IV);
void HW_SCE_Aes192EncryptDecryptUpdateSub(const uint32_t * InData_Text,
                                          uint32_t       * OutData_Text,
                                          const uint32_t   MAX_CNT);
fsp_err_t HW_SCE_Aes192EncryptDecryptFinalSub(void);
fsp_err_t HW_SCE_Aes256EncryptDecryptInitSub(const uint32_t * InData_KeyType,
                                             const uint32_t * InData_Cmd,
                                             const uint32_t * InData_KeyIndex,
                                             const uint32_t * InData_IV);
void HW_SCE_Aes256EncryptDecryptUpdateSub(const uint32_t * InData_Text,
                                          uint32_t       * OutData_Text,
                                          const uint32_t   MAX_CNT);
fsp_err_t HW_SCE_Aes256EncryptDecryptFinalSub(void);

fsp_err_t HW_SCE_Aes128GcmEncryptInitSub(uint32_t * InData_KeyType, uint32_t * InData_KeyIndex, uint32_t * InData_IV);
void      HW_SCE_Aes128GcmEncryptUpdateAADSub(uint32_t * InData_DataA, uint32_t MAX_CNT);
void      HW_SCE_Aes128GcmEncryptUpdateTransitionSub(void);
void      HW_SCE_Aes128GcmEncryptUpdateSub(uint32_t * InData_Text, uint32_t * OutData_Text, uint32_t MAX_CNT);
fsp_err_t HW_SCE_Aes128GcmEncryptFinalSub(uint32_t * InData_Text,
                                          uint32_t * InData_DataALen,
                                          uint32_t * InData_TextLen,
                                          uint32_t * OutData_Text,
                                          uint32_t * OutData_DataT);
fsp_err_t HW_SCE_Aes128GcmDecryptInitSub(uint32_t * InData_KeyType, uint32_t * InData_KeyIndex, uint32_t * InData_IV);
void      HW_SCE_Aes128GcmDecryptUpdateAADSub(uint32_t * InData_DataA, uint32_t MAX_CNT);
void      HW_SCE_Aes128GcmDecryptUpdateTransitionSub(void);
void      HW_SCE_Aes128GcmDecryptUpdateSub(uint32_t * InData_Text, uint32_t * OutData_Text, uint32_t MAX_CNT);
fsp_err_t HW_SCE_Aes128GcmDecryptFinalSub(uint32_t * InData_Text,
                                          uint32_t * InData_DataT,
                                          uint32_t * InData_DataALen,
                                          uint32_t * InData_TextLen,
                                          uint32_t * InData_DataTLen,
                                          uint32_t * OutData_Text);

fsp_err_t HW_SCE_Aes192GcmEncryptInitSub(uint32_t * InData_KeyType, uint32_t * InData_KeyIndex, uint32_t * InData_IV);
void      HW_SCE_Aes192GcmEncryptUpdateAADSub(uint32_t * InData_DataA, uint32_t MAX_CNT);
void      HW_SCE_Aes192GcmEncryptUpdateTransitionSub(void);
void      HW_SCE_Aes192GcmEncryptUpdateSub(uint32_t * InData_Text, uint32_t * OutData_Text, uint32_t MAX_CNT);
fsp_err_t HW_SCE_Aes192GcmEncryptFinalSub(uint32_t * InData_Text,
                                          uint32_t * InData_DataALen,
                                          uint32_t * InData_TextLen,
                                          uint32_t * OutData_Text,
                                          uint32_t * OutData_DataT);
fsp_err_t HW_SCE_Aes192GcmDecryptInitSub(uint32_t * InData_KeyType, uint32_t * InData_KeyIndex, uint32_t * InData_IV);
void      HW_SCE_Aes192GcmDecryptUpdateAADSub(uint32_t * InData_DataA, uint32_t MAX_CNT);
void      HW_SCE_Aes192GcmDecryptUpdateTransitionSub(void);
void      HW_SCE_Aes192GcmDecryptUpdateSub(uint32_t * InData_Text, uint32_t * OutData_Text, uint32_t MAX_CNT);
fsp_err_t HW_SCE_Aes192GcmDecryptFinalSub(uint32_t * InData_Text,
                                          uint32_t * InData_DataT,
                                          uint32_t * InData_DataALen,
                                          uint32_t * InData_TextLen,
                                          uint32_t * InData_DataTLen,
                                          uint32_t * OutData_Text);

fsp_err_t HW_SCE_Aes256GcmEncryptInitSub(uint32_t * InData_KeyType, uint32_t * InData_KeyIndex, uint32_t * InData_IV);
void      HW_SCE_Aes256GcmEncryptUpdateAADSub(uint32_t * InData_DataA, uint32_t MAX_CNT);
void      HW_SCE_Aes256GcmEncryptUpdateTransitionSub(void);
void      HW_SCE_Aes256GcmEncryptUpdateSub(uint32_t * InData_Text, uint32_t * OutData_Text, uint32_t MAX_CNT);
fsp_err_t HW_SCE_Aes256GcmEncryptFinalSub(uint32_t * InData_Text,
                                          uint32_t * InData_DataALen,
                                          uint32_t * InData_TextLen,
                                          uint32_t * OutData_Text,
                                          uint32_t * OutData_DataT);
fsp_err_t HW_SCE_Aes256GcmDecryptInitSub(uint32_t * InData_KeyType, uint32_t * InData_KeyIndex, uint32_t * InData_IV);
void      HW_SCE_Aes256GcmDecryptUpdateAADSub(uint32_t * InData_DataA, uint32_t MAX_CNT);
void      HW_SCE_Aes256GcmDecryptUpdateTransitionSub(void);
void      HW_SCE_Aes256GcmDecryptUpdateSub(uint32_t * InData_Text, uint32_t * OutData_Text, uint32_t MAX_CNT);
fsp_err_t HW_SCE_Aes256GcmDecryptFinalSub(uint32_t * InData_Text,
                                          uint32_t * InData_DataT,
                                          uint32_t * InData_DataALen,
                                          uint32_t * InData_TextLen,
                                          uint32_t * InData_DataTLen,
                                          uint32_t * OutData_Text);
fsp_err_t HW_SCE_AES_128CtrEncrypt(const uint32_t * InData_Key,
                                   const uint32_t * InData_IV,
                                   const uint32_t   num_words,
                                   const uint32_t * InData_Text,
                                   uint32_t       * OutData_Text,
                                   uint32_t       * OutData_IV);
fsp_err_t HW_SCE_AES_192CtrEncrypt(const uint32_t * InData_Key,
                                   const uint32_t * InData_IV,
                                   const uint32_t   num_words,
                                   const uint32_t * InData_Text,
                                   uint32_t       * OutData_Text,
                                   uint32_t       * OutData_IV);
fsp_err_t HW_SCE_AES_256CtrEncrypt(const uint32_t * InData_Key,
                                   const uint32_t * InData_IV,
                                   const uint32_t   num_words,
                                   const uint32_t * InData_Text,
                                   uint32_t       * OutData_Text,
                                   uint32_t       * OutData_IV);
fsp_err_t HW_SCE_AES_128CtrDecrypt(const uint32_t * InData_Key,
                                   const uint32_t * InData_IV,
                                   const uint32_t   num_words,
                                   const uint32_t * InData_Text,
                                   uint32_t       * OutData_Text);
fsp_err_t HW_SCE_AES_192CtrDecrypt(const uint32_t * InData_Key,
                                   const uint32_t * InData_IV,
                                   const uint32_t   num_words,
                                   const uint32_t * InData_Text,
                                   uint32_t       * OutData_Text);
fsp_err_t HW_SCE_AES_256CtrDecrypt(const uint32_t * InData_Key,
                                   const uint32_t * InData_IV,
                                   const uint32_t   num_words,
                                   const uint32_t * InData_Text,
                                   uint32_t       * OutData_Text);

#endif                                 /* HW_SCE_RA_PRIVATE_HEADER_FILE */
