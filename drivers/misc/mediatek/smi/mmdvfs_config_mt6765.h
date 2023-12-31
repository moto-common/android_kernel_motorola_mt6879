/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2020 MediaTek Inc.
 */

#ifndef __MMDVFS_CONFIG_MT6765_H__
#define __MMDVFS_CONFIG_MT6765_H__

#include "mmdvfs_config_util.h"

/* Part I MMSVFS HW Configuration (OPP)*/
/* Define the number of mmdvfs, vcore and mm clks opps */
/* Max total MMDVFS opps of the profile support */
#define MT6765_MMDVFS_OPP_MAX 3
/* Max total CLK opps of the profile support */
#define MT6765_MMDVFS_CLK_OPP_MAX 3
/* Max total Vcore opps of the profile support */
#define MT6765_MMDVFS_VCORE_OPP_MAX 4

/* CLK source configuration */

/* CLK source IDs */
/* Define the internal index of each CLK source*/
#define MT6765_CLK_TOP_MMPLL_CK 0
#define MT6765_CLK_TOP_UNIVPLL1_D2_CK 1
#define MT6765_CLK_TOP_MMPLL_D2_CK 2
#define MT6765_CLK_SOURCE_NUM 3

/* CLK Source definiation */
/* Define the clk source description */
struct mmdvfs_clk_source_desc mt6765_clk_sources[MT6765_CLK_SOURCE_NUM] = {
		{NULL, "mmdvfs_clk_mmpll_ck", 457},
		{NULL, "mmdvfs_clk_univpll1_d2_ck", 312},
		{NULL, "mmdvfs_clk_mmpll_d2_ck", 228},
};

/*
 * B. CLK Change adaption configurtion
 * B.1 Define the clk change method and data of each MM CLK step
 * Field decscription:
 * 1. config_method:
 *     a. MMDVFS_CLK_CONFIG_BY_MUX
 *     b. MMDVFS_CLK_CONFIG_PLL
 *     c. MMDVFS_CLK_CONFIG_NONE
 * 2. pll_id: PLL ID, please set -1 if PLL hopping is not used
 * 3. clk mux desc {handle, name}, plz set -1
 *       and it will be initialized by driver automaticlly
 * 4. total step: the number of the steps supported by this sub sys
 * 5. hopping dss of each steps: please set -1 if it is not used
 * 6. clk sources id of each steps: please set -1 if it is not used
 */
struct mmdvfs_clk_hw_map mt6765_clk_hw_map_setting[MMDVFS_CLK_MUX_NUM] = {
		{MMDVFS_CLK_CONFIG_NONE,
			{NULL, "MMDVFS_CLK_MUX_TOP_SMI0_2X_SEL"}, -1, 3,
			{-1, -1, -1},
			{-1, -1, -1}
		},
		{MMDVFS_CLK_CONFIG_BY_MUX,
			{NULL, "MMDVFS_CLK_MUX_TOP_MM_SEL"}, -1, 3,
			{-1, -1},
			{MT6765_CLK_TOP_MMPLL_CK,
			MT6765_CLK_TOP_UNIVPLL1_D2_CK,
			MT6765_CLK_TOP_MMPLL_D2_CK}
		},
		{MMDVFS_CLK_CONFIG_NONE,
			{NULL, "MMDVFS_CLK_MUX_TOP_CAM_SEL"}, -1, 3,
			{-1, -1, -1},
			{-1, -1, -1}


		},
		{MMDVFS_CLK_CONFIG_NONE,
			{NULL, "MMDVFS_CLK_MUX_TOP_IMG_SEL"}, -1, 3,
			{-1, -1, -1},
			{-1, -1, -1}


		},
		{MMDVFS_CLK_CONFIG_NONE,
			{NULL, "MMDVFS_CLK_MUX_TOP_VENC_SEL"}, -1, 3,
			{-1, -1, -1},
			{-1, -1, -1}


		},
		{MMDVFS_CLK_CONFIG_NONE,
			{NULL, "MMDVFS_CLK_MUX_TOP_VDEC_SEL"}, -1, 3,
			{-1, -1, -1},
			{-1, -1, -1}


		},
		{MMDVFS_CLK_CONFIG_NONE,
			{NULL, "MMDVFS_CLK_MUX_TOP_MJC_SEL"}, -1, 3,
			{-1, -1, -1},
			{-1, -1, -1}

		},
		{MMDVFS_CLK_CONFIG_NONE,
			{NULL, "MMDVFS_CLK_MUX_TOP_VPU_IF_SEL"}, -1, 3,
			{-1, -1, -1},
			{-1, -1, -1}

		},
		{MMDVFS_CLK_CONFIG_NONE,
			{NULL, "MMDVFS_CLK_MUX_TOP_VPU_IF_SEL"}, -1, 3,
			{-1, -1, -1},
			{-1, -1, -1}

		},
		{MMDVFS_CLK_CONFIG_NONE,
			{NULL, "MMDVFS_CLK_MUX_TOP_VPU_SEL"}, -1, 3,
			{-1, -1, -1},
			{-1, -1, -1}

		}
};
struct mmdvfs_profile_mask qos_apply_profiles[] = {
/* #ifdef MMDVFS_QOS_SUPPORT */
	/* ISP for opp0 */
	{"ISP",
		SMI_BWC_SCEN_CAM_PV,
		MMDVFS_FINE_STEP_OPP0},
	{"ISP",
		SMI_BWC_SCEN_CAM_CP,
		MMDVFS_FINE_STEP_OPP0},
	{"ISP",
		SMI_BWC_SCEN_VR,
		MMDVFS_FINE_STEP_OPP0},
	/* ISP for opp1 */
	{"ISP",
		SMI_BWC_SCEN_CAM_PV,
		MMDVFS_FINE_STEP_OPP1},
	{"ISP",
		SMI_BWC_SCEN_CAM_CP,
		MMDVFS_FINE_STEP_OPP1},
	{"ISP",
		SMI_BWC_SCEN_VR,
		MMDVFS_FINE_STEP_OPP1},
	/* ISP for opp2 */
	{"ISP",
		SMI_BWC_SCEN_CAM_PV,
		MMDVFS_FINE_STEP_OPP2},
	{"ISP",
		SMI_BWC_SCEN_CAM_CP,
		MMDVFS_FINE_STEP_OPP2},
	{"ISP",
		SMI_BWC_SCEN_VR,
		MMDVFS_FINE_STEP_OPP2},
	/* ICFP for opp0 */
	{"ICFP",
		SMI_BWC_SCEN_ICFP,
		MMDVFS_FINE_STEP_OPP0},
	/* debug entry */
	{"DEBUG",
		0,
		MMDVFS_FINE_STEP_UNREQUEST },
};
/* Part II MMDVFS Scenario's Step Confuguration */
#define MT6765_MMDVFS_SENSOR_MIN (13000000)
#define MT6765_MMDVFS_SENSOR_MID (16000000)
/* A.1 [LP4 2-ch] Scenarios of each MM DVFS Step (force kicker) */
/* OPP 0 scenarios */
#define MT6765_MMDVFS_OPP0_NUM 1
struct mmdvfs_profile mt6765_mmdvfs_opp0_profiles[MT6765_MMDVFS_OPP0_NUM] = {
	{"ICFP", SMI_BWC_SCEN_ICFP, {0, 0, 0}, {0, 0, 0 } },
/*
 *	{"Camera Preview", SMI_BWC_SCEN_CAM_PV,
 *		{MT6765_MMDVFS_SENSOR_MID, 0, 0}, {0, 0, 0 } },
 *	{"Camera Capture", SMI_BWC_SCEN_CAM_CP,
 *		{MT6765_MMDVFS_SENSOR_MID, 0, 0}, {0, 0, 0 } },
 *	{"Video Recording", SMI_BWC_SCEN_VR,
 *		{MT6765_MMDVFS_SENSOR_MID, 0, 0}, {0, 0, 0 } },
 */
};
/* OPP 1 scenarios */
#define MT6765_MMDVFS_OPP1_NUM 0
struct mmdvfs_profile mt6765_mmdvfs_opp1_profiles[MT6765_MMDVFS_OPP1_NUM] = {
/*
 *	{"Camera Preview", SMI_BWC_SCEN_CAM_PV,
 *		{MT6765_MMDVFS_SENSOR_MIN, 0, 0}, {0, 0, 0 } },
 *	{"Camera Capture", SMI_BWC_SCEN_CAM_CP,
 *		{MT6765_MMDVFS_SENSOR_MIN, 0, 0}, {0, 0, 0 } },
 *	{"Video Recording", SMI_BWC_SCEN_VR,
 *		{MT6765_MMDVFS_SENSOR_MIN, 0, 0}, {0, 0, 0 } },
 */
};
/* OPP 2 scenarios */
#define MT6765_MMDVFS_OPP2_NUM 0
struct mmdvfs_profile mt6765_mmdvfs_opp2_profiles[MT6765_MMDVFS_OPP2_NUM] = {
/*
 *	{"Camera Preview", SMI_BWC_SCEN_CAM_PV, {0, 0, 0}, {0, 0, 0 } },
 *	{"Camera Capture", SMI_BWC_SCEN_CAM_CP, {0, 0, 0}, {0, 0, 0 } },
 *	{"Video Recording", SMI_BWC_SCEN_VR, {0, 0, 0}, {0, 0, 0 } },
 */
};

/* Defined the smi scenarios whose DVFS is controlled by low-level driver */
/* directly, not by BWC scenario change event */
#define MT6765_MMDVFS_USER_CONTROL_SCEN_MASK (1 << SMI_BWC_SCEN_VP)
struct mmdvfs_step_to_qos_step legacy_to_qos_step[MT6765_MMDVFS_OPP_MAX] = {
	{0, 0},
	{1, 1},
	{2, 2},
};
struct mmdvfs_step_profile mt6765_step_profile[MT6765_MMDVFS_OPP_MAX] = {
	{0, mt6765_mmdvfs_opp0_profiles, MT6765_MMDVFS_OPP0_NUM,
	{MMDVFS_FINE_STEP_OPP0,
		{MMDVFS_MMCLK_OPP0, MMDVFS_MMCLK_OPP0,
		MMDVFS_MMCLK_OPP0, MMDVFS_MMCLK_OPP0,
		MMDVFS_MMCLK_OPP0, MMDVFS_MMCLK_OPP0,
		MMDVFS_MMCLK_OPP0, MMDVFS_MMCLK_OPP0,
		MMDVFS_MMCLK_OPP0, MMDVFS_MMCLK_OPP0}, MMDVFS_CLK_MUX_NUM
		}
	},
	{1, mt6765_mmdvfs_opp1_profiles, MT6765_MMDVFS_OPP1_NUM,
	{MMDVFS_FINE_STEP_OPP0,
		{MMDVFS_MMCLK_OPP0, MMDVFS_MMCLK_OPP0,
		MMDVFS_MMCLK_OPP0, MMDVFS_MMCLK_OPP0,
		MMDVFS_MMCLK_OPP0, MMDVFS_MMCLK_OPP0,
		MMDVFS_MMCLK_OPP0, MMDVFS_MMCLK_OPP0,
		MMDVFS_MMCLK_OPP0, MMDVFS_MMCLK_OPP0}, MMDVFS_CLK_MUX_NUM
		}
	},
	{2, mt6765_mmdvfs_opp2_profiles, MT6765_MMDVFS_OPP2_NUM,
	{MMDVFS_FINE_STEP_OPP1,
		{MMDVFS_MMCLK_OPP1, MMDVFS_MMCLK_OPP1,
		MMDVFS_MMCLK_OPP1, MMDVFS_MMCLK_OPP1,
		MMDVFS_MMCLK_OPP1, MMDVFS_MMCLK_OPP1,
		MMDVFS_MMCLK_OPP1, MMDVFS_MMCLK_OPP1,
		MMDVFS_MMCLK_OPP1, MMDVFS_MMCLK_OPP1}, MMDVFS_CLK_MUX_NUM
		}
	},
};

/* Part III Scenario and MMSVFS HW configuration mapping */

/* Part IV VPU association */
/* There is no VPU DVFS in MT6765 */

/* Part V ISP DVFS configuration */


#define MMDVFS_ISP_THRESHOLD_NUM 3
int mt6765_isp_threshold_setting[MMDVFS_ISP_THRESHOLD_NUM] = {457, 312, 228};
int mt6765_isp_threshold_opp[MMDVFS_ISP_THRESHOLD_NUM] = {
	MMDVFS_FINE_STEP_OPP0, MMDVFS_FINE_STEP_OPP2, MMDVFS_FINE_STEP_OPP4};

struct mmdvfs_threshold_setting mt6765_mmdvfs_threshold_settings[MMDVFS_PMQOS_NUM] = {
	{ MMDVFS_PM_QOS_SUB_SYS_CAMERA, mt6765_isp_threshold_setting,
	mt6765_isp_threshold_opp,
	MMDVFS_ISP_THRESHOLD_NUM, MMDVFS_PMQOS_ISP},
};

#endif /* __MMDVFS_CONFIG_MT6765_H__ */
