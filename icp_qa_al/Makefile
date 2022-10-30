################################################################
# This file is provided under a dual BSD/GPLv2 license.  When using or 
#   redistributing this file, you may do so under either license.
# 
#   GPL LICENSE SUMMARY
# 
#   Copyright(c) 2007-2016 Intel Corporation. All rights reserved.
# 
#   This program is free software; you can redistribute it and/or modify 
#   it under the terms of version 2 of the GNU General Public License as
#   published by the Free Software Foundation.
# 
#   This program is distributed in the hope that it will be useful, but 
#   WITHOUT ANY WARRANTY; without even the implied warranty of 
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
#   General Public License for more details.
# 
#   You should have received a copy of the GNU General Public License 
#   along with this program; if not, write to the Free Software 
#   Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
#   The full GNU General Public License is included in this distribution 
#   in the file called LICENSE.GPL.
# 
#   Contact Information:
#   Intel Corporation
# 
#   BSD LICENSE 
# 
#   Copyright(c) 2007-2016 Intel Corporation. All rights reserved.
#   All rights reserved.
# 
#   Redistribution and use in source and binary forms, with or without 
#   modification, are permitted provided that the following conditions 
#   are met:
# 
#     * Redistributions of source code must retain the above copyright 
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright 
#       notice, this list of conditions and the following disclaimer in 
#       the documentation and/or other materials provided with the 
#       distribution.
#     * Neither the name of Intel Corporation nor the names of its 
#       contributors may be used to endorse or promote products derived 
#       from this software without specific prior written permission.
# 
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
#   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
#   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
#   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
#   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
#   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
#   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
#   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
#   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
#   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
#   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 
# 
#  version: QAT1.5.L.1.13.0-19
################################################################
obj-$(CONFIG_CRYPTO_DEV_QATHW15_LAC) += icp_qa_al.o
obj-$(CONFIG_CRYPTO_DEV_QATHW15_LAC_VF) += icp_qa_al_vf.o

icp_qa_al_common := icp_qa_module.o \
	adf/adf_lib.o \
	adf/accel_mgr/adf_cfg.o \
	adf/accel_mgr/adf_cfg_debug.o \
	adf/accel_mgr/adf_cfg_dp.o \
	adf/accel_mgr/adf_devmgr.o \
	adf/accel_mgr/adf_esram.o \
	adf/accel_mgr/adf_init.o \
	adf/accel_mgr/adf_user_proxy.o \
	adf/drivers/adf_bh.o \
	adf/drivers/adf_chr_drv.o \
	adf/drivers/adf_common_drv.o \
	adf/drivers/adf_ctl_drv.o \
	adf/drivers/adf_dev_csr.o \
	adf/drivers/adf_dev_processes.o \
	adf/drivers/adf_dev_ring.o \
	adf/drivers/adf_fw.o \
	adf/drivers/adf_gige_wd_drv.o \
	adf/drivers/adf_poll_tasklets.o \
	adf/drivers/adf_proc_debug.o \
	adf/dyn/adf_dyn_main.o \
	adf/dyn/adf_dyn_rings.o \
	adf/dyn/adf_dyn_events.o \
	adf/transport/adf_ETring_mgr.o \
	adf/transport/adf_ETring_mgr_dp.o \
	adf/transport/adf_poll_ctrl.o \
	adf/transport/adf_transport_ctrl.o \
	adf/transport/adf_transport_debug.o \
	adf/transport/adf_transport_dyn_pool.o \
	adf/wireless/adf_wireless_events.o \
	adf/wireless/adf_wireless_main.o \
	adf/wireless/adf_wireless_rings.o \
	lookaside/ctrl/sal_compression.o \
	lookaside/ctrl/sal_crypto.o \
	lookaside/ctrl/sal_create_services.o \
	lookaside/ctrl/sal_ctrl_services.o \
	lookaside/ctrl/sal_list.o \
	lookaside/compression/dc_datapath.o \
	lookaside/compression/dc_dp.o \
	lookaside/compression/dc_flattree.o \
	lookaside/compression/dc_header_footer.o \
	lookaside/compression/dc_session.o \
	lookaside/compression/dc_stats.o \
	lookaside/crypto/asym/diffie_hellman/lac_dh_control_path.o \
	lookaside/crypto/asym/diffie_hellman/lac_dh_data_path.o \
	lookaside/crypto/asym/diffie_hellman/lac_dh_interface_check.o \
	lookaside/crypto/asym/diffie_hellman/lac_dh_stats.o \
	lookaside/crypto/asym/dsa/lac_dsa.o \
	lookaside/crypto/asym/dsa/lac_dsa_interface_check.o \
	lookaside/crypto/asym/ecc/lac_ec.o \
	lookaside/crypto/asym/ecc/lac_ec_common.o \
	lookaside/crypto/asym/ecc/lac_ecdh.o \
	lookaside/crypto/asym/ecc/lac_ecdsa.o \
	lookaside/crypto/asym/large_number/lac_ln.o \
	lookaside/crypto/asym/large_number/lac_ln_interface_check.o \
	lookaside/crypto/asym/pke_common/lac_pke_mmp.o \
	lookaside/crypto/asym/pke_common/lac_pke_qat_comms.o \
	lookaside/crypto/asym/pke_common/lac_pke_utils.o \
	lookaside/crypto/asym/prime/lac_prime.o \
	lookaside/crypto/asym/prime/lac_prime_interface_check.o \
	lookaside/crypto/asym/rsa/lac_rsa.o \
	lookaside/crypto/asym/rsa/lac_rsa_control_path.o \
	lookaside/crypto/asym/rsa/lac_rsa_decrypt.o \
	lookaside/crypto/asym/rsa/lac_rsa_encrypt.o \
	lookaside/crypto/asym/rsa/lac_rsa_interface_check.o \
	lookaside/crypto/asym/rsa/lac_rsa_keygen.o \
	lookaside/crypto/asym/rsa/lac_rsa_stats.o \
	lookaside/crypto/sym/drbg/drbg_ht/lac_sym_drbg_ht_tests.o \
	lookaside/crypto/sym/drbg/lac_sym_drbg_api.o \
	lookaside/crypto/sym/drbg/lac_sym_drbg_cb.o \
	lookaside/crypto/sym/drbg/lac_sym_drbg_df.o \
	lookaside/crypto/sym/drbg/lac_sym_drbg_general.o \
	lookaside/crypto/sym/drbg/lac_sym_drbg_impl.o \
	lookaside/crypto/sym/drbg/lac_sym_drbg_nodf.o \
	lookaside/crypto/sym/drbg/lac_sym_drbg_rdrand.o \
	lookaside/crypto/sym/drbg/lac_sym_rdrand.o \
	lookaside/crypto/sym/key/lac_sym_key.o \
	lookaside/crypto/sym/lac_sym_alg_chain.o \
	lookaside/crypto/sym/lac_sym_api.o \
	lookaside/crypto/sym/lac_sym_auth_enc.o \
	lookaside/crypto/sym/lac_sym_cb.o \
	lookaside/crypto/sym/lac_sym_cipher.o \
	lookaside/crypto/sym/lac_sym_compile_check.o \
	lookaside/crypto/sym/lac_sym_dp.o \
	lookaside/crypto/sym/lac_sym_hash.o \
	lookaside/crypto/sym/lac_sym_hash_sw_precomputes.o \
	lookaside/crypto/sym/lac_sym_partial.o \
	lookaside/crypto/sym/lac_sym_queue.o \
	lookaside/crypto/sym/lac_sym_stats.o \
	lookaside/crypto/sym/nrbg/lac_sym_nrbg_api.o \
	lookaside/crypto/sym/qat/lac_sym_qat.o \
	lookaside/crypto/sym/qat/lac_sym_qat_cipher.o \
	lookaside/crypto/sym/qat/lac_sym_qat_hash.o \
	lookaside/crypto/sym/qat/lac_sym_qat_hash_defs_lookup.o \
	lookaside/crypto/sym/qat/lac_sym_qat_key.o \
	lookaside/qat_comms/sal_qat_cmn_msg.o \
	lookaside/qat_ctrl/qat_admin.o \
	lookaside/qat_ctrl/qat_init.o \
	lookaside/qat_ctrl/qat_rings.o \
	lookaside/utils/lac_buffer_desc.o \
	lookaside/utils/lac_mem.o \
	lookaside/utils/lac_mem_pools.o \
	lookaside/utils/lac_sync.o \
	lookaside/utils/sal_service_state.o \
	lookaside/utils/sal_statistics.o \
	lookaside/utils/sal_string_parse.o \
	lookaside/utils/sal_user_process.o \
	lookaside/utils/sal_versions.o \
	osal/OsalAtomic.o \
	osal/OsalBankE.o \
	osal/OsalCryptoInterface.o \
	osal/OsalDevOperations.o \
	osal/OsalMemMgmt.o \
	osal/OsalIOMMUMgmt.o \
	osal/OsalServices.o \
	osal/OsalSemaphore.o \
	osal/OsalSpinLock.o \
	osal/OsalThread.o \
	osal/OsalUsrKrlProxy.o \
	osal/OsalZlib.o \
	osalzlib/inflate.o \
	osalzlib/inftrees.o \
	osalzlib/adler32.o \
	osalzlib/inffast.o \
	osalzlib/zutil.o \
	osalzlib/crc32.o \
	utilities/downloader/halAe/halAe.o \
	utilities/downloader/halAe/halAeDrv.o \
	utilities/downloader/halAe/halAeHw.o \
	utilities/downloader/halAe/halMemScrub.o \
	utilities/downloader/halAe/halOSKern.o \
	utilities/downloader/halAe/icp_firml_interface.o \
	utilities/downloader/halAe/accelcomp/halAeChip.o \
	utilities/downloader/uclo/uclo.o \
	utilities/downloader/uclo/uclo_exp.o \
	utilities/downloader/uclo/uclo_helper.o \
	utilities/downloader/uclo/uclo_hw.o \
	utilities/downloader/uclo/uclo_ivd.o \
	utilities/downloader/uclo/uclo_kern.o \
	utilities/downloader/uclo/uclo_mof.o \
	utilities/downloader/uclo/uclo_overlay.o \
	utilities/downloader/uclo/uclo_suof.o

icp_qa_al-objs := $(icp_qa_al_common) \
	adf/accel_mgr/adf_vf2pf_ctrl.o \
	adf/accelengine/adf_ae.o \
	adf/accelengine/adf_ae_fw.o \
	adf/drivers/adf_vf_bh.o \
	adf/drivers/acceldev/adf_acceldev_aer.o \
	adf/drivers/acceldev/adf_acceldev_drv.o \
	adf/drivers/acceldev/adf_acceldev_isr.o \
	adf/drivers/acceldev/adf_acceldev_sriov_drv.o \
	adf/platform/acceldev/adf_acceldev_bank_bh_handlers.o \
	adf/platform/acceldev/adf_acceldev_sysmeminfo.o \
	adf/platform/acceldev/adf_c2xxx_hw_data.o \
	adf/platform/acceldev/adf_dh89xxcc_hw_data.o \
	adf/transport/acceldev/adf_ETring_ap_vf.o \
	adf/transport/acceldev/adf_transport_vf2pf_ctrl.o \
	lookaside/ctrl/acceldev/sal_ctrl_qat.o \
	lookaside/ctrl/acceldev/sal_qat_ctrl.o

icp_qa_al_vf-objs := $(icp_qa_al_common) \
	adf/accel_mgr/adf_pf2vf_ctrl.o \
	adf/accelenginevf/adf_ae_vf.o \
	adf/drivers/acceldevvf/adf_acceldev_drv.o \
	adf/drivers/acceldevvf/adf_acceldev_isr.o \
	adf/platform/acceldevvf/adf_acceldev_bank_bh_handlers.o \
	adf/platform/acceldevvf/adf_c2xxxiov_hw_data.o \
	adf/platform/acceldevvf/adf_dh89xxcciov_hw_data.o \
	adf/transport/acceldevvf/adf_transport_pf2vf_ctrl.o \
	adf/transport/acceldevvf/adf_ETring_ap.o \

# Unclear what some of these are, but it's what the upstream source does.
subdir-ccflags-y += -D__SMP__ -DSMP
subdir-ccflags-y += -DBANKE_WORKAROUND
subdir-ccflags-y += -DENABLE_SPINLOCK
subdir-ccflags-y += -DKERNEL_SPACE
subdir-ccflags-y += -DICP_NONBLOCKING_PARTIALS_PERFORM
subdir-ccflags-y += -DLAC_BYTE_ORDER=__LITTLE_ENDIAN
subdir-ccflags-y += -DONE_KO_RELEASE_PACKAGE=1

subdir-ccflags-$(CONFIG_CRYPTO_DEV_QATHW15_HOST) += -DADF_PLATFORM_ACCELDEV
subdir-ccflags-$(CONFIG_CRYPTO_DEV_QATHW15_HOST) += -DICP_SRIOV
subdir-ccflags-$(CONFIG_CRYPTO_DEV_QATHW15_GUEST) += -DADF_PLATFORM_ACCELDEVVF
subdir-ccflags-$(CONFIG_CRYPTO_DEV_QATHW15_GUEST) += -DICP_NUMA_MEM
subdir-ccflags-$(CONFIG_CRYPTO_DEV_QATHW15_NOIOMMU) += -DICP_WITHOUT_IOMMU

# lookaside/crypto/sym/drbg/lac_sym_drbg_general.c uses VLA
subdir-ccflags-y += -Wno-vla-extension

# zlib uses K&R style definitions and Clang is not a fan of them:
# https://github.com/madler/zlib/issues/633
subdir-ccflags-y += -Wno-deprecated-non-prototype

subdir-ccflags-y += -I$(src)/include
subdir-ccflags-y += -I$(src)/adf/include
subdir-ccflags-y += -I$(src)/adf/accel_mgr/include
subdir-ccflags-y += -I$(src)/adf/accelengine/include
subdir-ccflags-y += -I$(src)/adf/drivers/include
subdir-ccflags-y += -I$(src)/adf/dyn/include
subdir-ccflags-y += -I$(src)/adf/platform/include
subdir-ccflags-y += -I$(src)/adf/transport/include
subdir-ccflags-y += -I$(src)/adf/wireless/include
subdir-ccflags-y += -I$(src)/lookaside/include
subdir-ccflags-y += -I$(src)/lookaside/compression/include
subdir-ccflags-y += -I$(src)/lookaside/crypto/asym/include
subdir-ccflags-y += -I$(src)/lookaside/crypto/asym/diffie_hellman/include
subdir-ccflags-y += -I$(src)/lookaside/crypto/asym/rsa/include
subdir-ccflags-y += -I$(src)/lookaside/crypto/sym/include
subdir-ccflags-y += -I$(src)/lookaside/crypto/sym/drbg/drbg_ht/include
subdir-ccflags-y += -I$(src)/lookaside/firmware/include
subdir-ccflags-y += -I$(src)/lookaside/qat_ctrl/include
subdir-ccflags-y += -I$(src)/utilities/downloader/include
subdir-ccflags-y += -I$(src)/utilities/downloader/include/os/linux
subdir-ccflags-y += -I$(src)/utilities/downloader/include/platform/accelcomp
subdir-ccflags-y += -I$(src)/osal/include
subdir-ccflags-y += -I$(src)/osalzlib/include
subdir-ccflags-y += -I$(src)/utilities/downloader/halAe/include
subdir-ccflags-y += -I$(src)/utilities/downloader/halAe/include/linux
subdir-ccflags-y += -I$(src)/utilities/downloader/halAe/accelcomp/include
subdir-ccflags-y += -I$(src)/utilities/downloader/uclo/include
subdir-ccflags-y += -I$(src)/utilities/downloader/uclo/include/linux
