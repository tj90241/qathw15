/***************************************************************************
 *
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
 ***************************************************************************/

/**
 ***************************************************************************
 * @file icp_sal_poll.h
 *
 * @defgroup SalPoll
 *
 * @ingroup SalPoll
 *
 * @description
 *    Polling APIs for instance polling.
 *    These functions retrieve requests on appropriate response rings and
 *    dispatch the associated callbacks. Callbacks are called in the
 *    context of the polling function itself.
 *
 *
 ***************************************************************************/

#ifndef ICP_SAL_POLL_H
#define ICP_SAL_POLL_H


/*************************************************************************
  * @ingroup SalPoll
  * @description
  *    Poll a Cy logical instance to retrieve requests that are on the
  *    response rings associated with that instance and dispatch the
  *    associated callbacks.
  *
  * @context
  *      This functions is called from both the user and kernel context
  *
  * @assumptions
  *      None
  * @sideEffects
  *      None
  * @reentrant
  *      No
  * @threadSafe
  *      Yes
  *
  * @param[in] instanceHandle     Instance handle.
  * @param[in] response_quota     The maximum number of messages that
  *                               will be read in one polling. Setting
  *                               the response quota to zero means that
  *                               all messages on the ring will be read.
  *
  * @retval CPA_STATUS_SUCCESS    Successfully polled a ring with data
  * @retval CPA_STATUS_RETRY      There are no responses on the rings
  *                               associated with this instance
  * @retval CPA_STATUS_FAIL       Indicates a failure
  *************************************************************************/
CpaStatus
icp_sal_CyPollInstance(CpaInstanceHandle instanceHandle,
                       Cpa32U response_quota);

/*************************************************************************
  * @ingroup SalPoll
  * @description
  *    Poll the high priority symmetric response ring associated with a Cy
  *    logical instance to retrieve requests and dispatch the
  *    associated callbacks.
  *
  *    This API is recommended for data plane applications, in which the
  *    cost of offload - that is, the cycles consumed by the driver in
  *    sending requests to the hardware, and processing responses - needs
  *    to be minimized.  In particular, use of this API is recommended
  *    if the following constraints are acceptable to your application:
  *
  *    - Thread safety is not guaranteed.  Each software thread should
  *      have access to its own unique instance (CpaInstanceHandle) to
  *      avoid contention.
  *    - The "default" instance (@ref CPA_INSTANCE_HANDLE_SINGLE) is not
  *      supported on this API.  The specific handle should be obtained
  *      using the instance discovery functions (@ref cpaCyGetNumInstances,
  *      @ref cpaCyGetInstances).
  *
  *    This polling function should be used with the functions described
  *    in cpa_cy_sym_dp.h
  *
  * @context
  *      This functions is called from both the user and kernel context
  *
  * @assumptions
  *      None
  * @sideEffects
  *      None
  * @reentrant
  *      No
  * @threadSafe
  *      No
  *
  * @param[in] instanceHandle     Instance handle.
  * @param[in] response_quota     The maximum number of messages that
  *                               will be read in one polling. Setting
  *                               the response quota to zero means that
  *                               all messages on the ring will be read.
  *
  * @retval CPA_STATUS_SUCCESS    Successfully polled a ring with data
  * @retval CPA_STATUS_RETRY      There are no responses on the ring
  *                               associated with this instance
  * @retval CPA_STATUS_FAIL       Indicates a failure
  *************************************************************************/
CpaStatus
icp_sal_CyPollDpInstance(CpaInstanceHandle instanceHandle,
                         Cpa32U response_quota);

/*************************************************************************
  * @ingroup SalPoll
  * @description
  *    Poll a Dc logical instance to retrieve requests that are on the
  *    response ring associated with that instance and dispatch the
  *    associated callbacks.
  *
  * @context
  *      This function is called from both the user and kernel context
  *
  * @assumptions
  *      None
  * @sideEffects
  *      None
  * @reentrant
  *      No
  * @threadSafe
  *      Yes
  *
  * @param[in] instanceHandle     Instance handle.
  * @param[in] response_quota     The maximum number of messages that
  *                               will be read in one polling. Setting
  *                               the response quota to zero means that
  *                               all messages on the ring will be read.
  *
  * @retval CPA_STATUS_SUCCESS    Successfully polled a ring with data
  * @retval CPA_STATUS_RETRY      There are no responses on the ring
  *                               associated with this instance
  * @retval CPA_STATUS_FAIL       Indicates a failure
  *************************************************************************/
CpaStatus
icp_sal_DcPollInstance(CpaInstanceHandle instanceHandle,
                       Cpa32U response_quota);

/*************************************************************************
  * @ingroup SalPoll
  * @description
  *    Poll the response ring associated with a Dc logical instance to
  *    retrieve requests and dispatch the associated callbacks.
  *
  *    This API is recommended for data plane applications, in which the
  *    cost of offload - that is, the cycles consumed by the driver in
  *    sending requests to the hardware, and processing responses - needs
  *    to be minimized.  In particular, use of this API is recommended
  *    if the following constraints are acceptable to your application:
  *
  *    - Thread safety is not guaranteed.  Each software thread should
  *      have access to its own unique instance (CpaInstanceHandle) to
  *      avoid contention.
  *    - The "default" instance (@ref CPA_INSTANCE_HANDLE_SINGLE) is not
  *      supported on this API.  The specific handle should be obtained
  *      using the instance discovery functions (@ref cpaDcGetNumInstances,
  *      @ref cpaDcGetInstances).
  *
  *    This polling function should be used with the functions described
  *    in cpa_dc_dp.h

  *
  * @context
  *      This functions is called from both the user and kernel context
  *
  * @assumptions
  *      None
  * @sideEffects
  *      None
  * @reentrant
  *      No
  * @threadSafe
  *      No
  *
  * @param[in] instanceHandle     Instance handle.
  * @param[in] response_quota     The maximum number of messages that
  *                               will be read in one polling. Setting
  *                               the response quota to zero means that
  *                               all messages on the ring will be read.
  *
  * @retval CPA_STATUS_SUCCESS    Successfully polled a ring with data
  * @retval CPA_STATUS_RETRY      There are no responses on the ring
  *                               associated with this instance
  * @retval CPA_STATUS_FAIL       Indicates a failure
  *************************************************************************/
CpaStatus
icp_sal_DcPollDpInstance(CpaInstanceHandle dcInstance,
                         Cpa32U responseQuota);

/*************************************************************************
  * @ingroup SalPoll
  * @description
  *    This function polls the rings on the given bank to determine
  *    if any of the rings contain messages to be read. The
  *    response quota is per ring.
  *
  * @context
  *      This functions is called from both the user and kernel context
  *
  * @assumptions
  *      None
  * @sideEffects
  *      None
  * @reentrant
  *      No
  * @threadSafe
  *      Yes
  *
  * @param[in] accelId            Acceleration device Id, also known as
  *                               packageId. This can be obtained using
  *                               instance info functions (
  *                               @ref cpaCyInstanceGetInfo2
  *                               and @ref cpaDcInstanceGetInfo2)
  *
  * @param[in] bank_number        Bank number
  *
  * @param[in] response_quota     The maximum number of messages that
  *                               will be read in one polling. Setting
  *                               the response quota to zero means that
  *                               all messages on the ring will be read.
  *
  * @retval CPA_STATUS_SUCCESS    Successfully polled a ring with data
  * @retval CPA_STATUS_RETRY      There is no data on any ring on the bank
  *                               or the bank is already being polled
  * @retval CPA_STATUS_FAIL       Indicates a failure
  *************************************************************************/
CpaStatus icp_sal_pollBank(Cpa32U accelId,
                           Cpa32U bank_number,
                           Cpa32U response_quota);

/*************************************************************************
  * @ingroup SalPoll
  * @description
  *    This function polls the rings on all banks to determine
  *    if any of the rings contain messages to be read. The
  *    response quota is per ring.
  *
  * @context
  *      This functions is called from both the user and kernel context
  *
  * @assumptions
  *      None
  * @sideEffects
  *      None
  * @reentrant
  *      No
  * @threadSafe
  *      Yes
  *
  * @param[in] accelId            Acceleration device Id, also known as
  *                               packageId. This can be obtained using
  *                               instance info functions (
  *                               @ref cpaCyInstanceGetInfo2
  *                               and @ref cpaDcInstanceGetInfo2)
  *
  * @param[in] response_quota     The maximum number of messages that
  *                               will be read in one polling. Setting
  *                               the response quota to zero means that
  *                               all messages on the ring will be read.
  *
  * @retval CPA_STATUS_SUCCESS    Successfully polled a ring with data
  * @retval CPA_STATUS_RETRY      There is no data on any ring on any bank
  *                               or the banks are already being polled
  * @retval CPA_STATUS_FAIL       Indicates a failure
  *************************************************************************/
CpaStatus icp_sal_pollAllBanks(Cpa32U accelId,
                               Cpa32U response_quota);

/*************************************************************************
  * @ingroup SalPoll
  * @description
  *    This is a stub to get a file descriptor corresponding to a crypto
  *    instance.
  *
  * @context
  *      This functions is called from the user context only.
  *
  * @assumptions
  *      None
  * @sideEffects
  *      None
  * @reentrant
  *      No
  * @threadSafe
  *      Yes
  *
  * @param[in] instanceHandle     The instance handler
  *
  * @param[out] fd                The pointer to store the returned file
  *                               descriptor.
  *
  * @retval CPA_STATUS_SUCCESS    Successfully get a file descriptor.
  * @retval CPA_STATUS_FAIL       Failed
  *************************************************************************/
CpaStatus icp_sal_CyGetFileDescriptor(CpaInstanceHandle instanceHandle, int *fd);

/*************************************************************************
  * @ingroup SalPoll
  * @description
  *    This is a stub to put a file descriptor corresponding to a crypto
  *    instance.
  *
  * @context
  *      This functions is called from the user context only.
  *
  * @assumptions
  *      None
  * @sideEffects
  *      None
  * @reentrant
  *      No
  * @threadSafe
  *      Yes
  *
  * @param[in] instanceHandle     The instance handler
  *
  * @param[in] fd                 The file descriptor to put.
  *
  * @retval CPA_STATUS_SUCCESS    Successfully to put a file descriptor.
  * @retval CPA_STATUS_FAIL       Failed
  *************************************************************************/
CpaStatus icp_sal_CyPutFileDescriptor(CpaInstanceHandle instanceHandle, int fd);

/*************************************************************************
  * @ingroup SalPoll
  * @description
  *    This is a stub to get a file descriptor corresponding to a compression
  *    instance.
  *
  * @context
  *      This functions is called from the user context only.
  *
  * @assumptions
  *      None
  * @sideEffects
  *      None
  * @reentrant
  *      No
  * @threadSafe
  *      Yes
  *
  * @param[in] instanceHandle     The instance handler
  *
  * @param[out] fd                The pointer to store the returned file
  *                               descriptor.
  *
  * @retval CPA_STATUS_SUCCESS    Successfully get a file descriptor.
  * @retval CPA_STATUS_FAIL       Failed
  *************************************************************************/
CpaStatus icp_sal_DcGetFileDescriptor(CpaInstanceHandle instanceHandle, int *fd);

/*************************************************************************
  * @ingroup SalPoll
  * @description
  *    This is a stub to put a file descriptor corresponding to a compression
  *    instance.
  *
  * @context
  *      This functions is called from the user context only.
  *
  * @assumptions
  *      None
  * @sideEffects
  *      None
  * @reentrant
  *      No
  * @threadSafe
  *      Yes
  *
  * @param[in] instanceHandle     The instance handler
  *
  * @param[in] fd                 The file descriptor to put.
  *
  * @retval CPA_STATUS_SUCCESS    Successfully to put a file descriptor.
  * @retval CPA_STATUS_FAIL       Failed
  *************************************************************************/
CpaStatus icp_sal_DcPutFileDescriptor(CpaInstanceHandle instanceHandle, int fd);
#endif
