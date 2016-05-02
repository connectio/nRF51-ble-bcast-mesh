/***********************************************************************************
Copyright (c) Nordic Semiconductor ASA
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

  3. Neither the name of Nordic Semiconductor ASA nor the names of other
  contributors to this software may be used to endorse or promote products
  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
************************************************************************************/
#ifndef BOOTLOADER_INFO_H__
#define BOOTLOADER_INFO_H__
#include <stdint.h>
#include <stdbool.h>
#include "dfu_types_mesh.h"

#define DFU_PUBLIC_KEY_LEN      (64)
#define DFU_SIGNATURE_LEN       (64)

#define BL_INFO_LEN_PUBLIC_KEY  (DFU_PUBLIC_KEY_LEN)
#define BL_INFO_LEN_SEGMENT     (9)
#define BL_INFO_LEN_FWID        (14)
#define BL_INFO_LEN_JOURNAL     ((2 * PAGE_COUNT) / 8)
#define BL_INFO_LEN_FLAGS       (1)
#define BL_INFO_LEN_SIGNATURE   (DFU_SIGNATURE_LEN)


typedef struct
{
    struct
    {
        uint8_t metadata_len; /* in bytes */
        uint8_t entry_header_length; /* in bytes */
        uint8_t entry_len_length;  /* in bits */
        uint8_t entry_type_length; /* in bits */
    } metadata;
    uint8_t data[];
} bootloader_info_t;

uint32_t bootloader_info_init(uint32_t* p_bl_info_page);
bl_info_entry_t* bootloader_info_entry_get(uint32_t* p_bl_info_page, bl_info_type_t type);


#endif /* BOOTLOADER_INFO_H__ */
