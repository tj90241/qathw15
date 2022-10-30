/**
 **************************************************************************
 * @file uof_platform.h
 *
 * @description
 *      This is the header file for uCode Object File
 *
 * @par 
 * This file is provided under a dual BSD/GPLv2 license.  When using or 
 *   redistributing this file, you may do so under either license.
 * 
 *   GPL LICENSE SUMMARY
 * 
 *   Copyright(c) 2007-2016 Intel Corporation. All rights reserved.
 * 
 *   This program is free software; you can redistribute it and/or modify 
 *   it under the terms of version 2 of the GNU General Public License as
 *   published by the Free Software Foundation.
 * 
 *   This program is distributed in the hope that it will be useful, but 
 *   WITHOUT ANY WARRANTY; without even the implied warranty of 
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
 *   General Public License for more details.
 * 
 *   You should have received a copy of the GNU General Public License 
 *   along with this program; if not, write to the Free Software 
 *   Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *   The full GNU General Public License is included in this distribution 
 *   in the file called LICENSE.GPL.
 * 
 *   Contact Information:
 *   Intel Corporation
 * 
 *   BSD LICENSE 
 * 
 *   Copyright(c) 2007-2016 Intel Corporation. All rights reserved.
 *   All rights reserved.
 * 
 *   Redistribution and use in source and binary forms, with or without 
 *   modification, are permitted provided that the following conditions 
 *   are met:
 * 
 *     * Redistributions of source code must retain the above copyright 
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright 
 *       notice, this list of conditions and the following disclaimer in 
 *       the documentation and/or other materials provided with the 
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its 
 *       contributors may be used to endorse or promote products derived 
 *       from this software without specific prior written permission.
 * 
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * 
 *  version: QAT1.5.L.1.13.0-19
 *
 **************************************************************************/ 

/*
 ****************************************************************************
 * Doxygen group definitions
 ****************************************************************************/

/**
 *****************************************************************************
 * @file uof_platform.h
 * 
 * @defgroup UOF Microcode File Format Definition
 *
 * @description
 *      This header file that contains the definitions of micorcode file 
 *      format used by linker and loader.
 *
 *****************************************************************************/

#ifndef __UOF_PLATFORM_H__
#define __UOF_PLATFORM_H__

#ifdef __cplusplus
extern "C"{
#endif

#define UOF_PLATFORM_MINVER      0x11         /**< UOF minor version */

struct uof_strTab_S{
   unsigned int tableLen;               /**< length of table */
   unsigned int          reserved;      /**< reserved for future use */
   uint64                strings;       /**< pointer to string table. NULL terminated strings */
};

struct uof_importVar_S{
   unsigned int     name;               /**< import var name string-table offset */
   unsigned char    valueAttrs;         /**< bit<0> (Scope: 0=global), bit<1> (init: 0=no, 1=yes) */
   unsigned char    reserved1;          /**< reserved for future use */
   unsigned short   reserved2;          /**< reserved for future use */
   uint64           value;              /**< 64-bit imported value */
};

struct uof_uWordBlock_S{
    unsigned int startAddr;             /**< start address */
    unsigned int numWords;              /**< number of microwords */
    unsigned int uwordOffset;           /**< offset to the uwords */
    unsigned int reserved;              /**< reserved for future use */
};

#define MAX_USTORE_PER_SEG      0x4000              /**< 16k ustore size per segment */
#define ARCH_ALIGN     (unsigned long)

#ifdef __cplusplus
}
#endif

#endif  /* __UOF_PLATFORM_H__ */
