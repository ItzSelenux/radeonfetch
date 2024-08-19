#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ML 256

// Config variables
unsigned int sname = 1, spciid = 1, scores = 1, svbios = 1, susage = 1, svendor = 1, slinkspeed = 1,
	slinkwidth = 1, sdmamask = 1, senabled = 1, smemgtused = 1, smemgttotal = 1, svramused = 1, 
	svramtotal = 1, sdriver = 1, sttl = 1, sdpmsclk = 1, sdpmpcie = 1, sdpmmclk = 1, sperfmode = 1,
	sperflevel = 0, devicenumber = 0,

	showmb = 1, showlevel = 1, showspeedindex = 0, showpercentage = 1, usehumanvalues = 1,
	showascii = 1;

char *mb = "Mb", *lvl = "performance", *perc = "\%", *home_dir;

// Alias
char aname[ML] = "GPU:";
char apciid[ML] = "PCI ID:";
char acores[ML] = "Cores:";
char avbios[ML] = "Vbios:";
char ausage[ML] = "Usage:";
char avendor[ML] = "Vendor:";
char alinkspeed[ML] = "Link Speed:";
char alinkwidth[ML] = "Link Width:";
char admamask[ML] = "DMA Mask:";
char aenabled[ML] = "Enabled:";
char amemgtused[ML] = "MEM (TG):";
char amemgttotal[ML] = "MEM (TG):";
char avramused[ML] = "VRAM:";
char avramtotal[ML] = "Total VRAM:";
char adriver[ML] = "Driver:";
char attl[ML] = "TTL:";
char adpmsclk[ML] = "Current Freq.:";
char adpmpcie[ML] = "Current PCI Speed:";
char adpmmclk[ML] = "Current MEM Speed:";
char aperfmode[ML] = "Performance Mode:";
char aperflevel[ML] = "Performance Level:";
char desiredascii[ML] = "radeon";

// Path of readed files
char *fname, *fpciid = "device",
	*fcores, *fvbios = "vbios_version",
	*fusage = "gpu_busy_percent", *fvendor = "vendor",
	*flinkspeed = "max_link_speed", *flinkwidth ="max_link_width",
	*fdmamask = "dma_mask_bits", *fenabled = "enable",
	*fmemgtused = "mem_info_gtt_used", *fmemgttotal = "mem_info_gtt_total",
	*fvramused = "mem_info_vram_used", *fvramtotal = "mem_info_vram_total",
	*fdriver = "uevent", *fttl = "thermal_throttling_logging",
	*fdpmsclk = "pp_dpm_sclk", *fdpmpcie = "pp_dpm_pcie",
	*fdpmmclk = "pp_dpm_mclk", *fperfmode = "power_dpm_state",
	*fperflevel = "power_dpm_force_performance_level";

char fprefix[512];

// Final Values
char *name, *pciid, *cores, *vbios, *usage, *vendor, *linkspeed, *linkwidth, *dmamask,
	*enabled, *memgtused, *memgttotal, *vramused, *vramtotal, *driver, *ttl, *dpmsclk, *dpmpcie,
	*dpmmclk, *perfmode, *perflevel;

// Main enumeration
typedef enum {
	INFO_GPU_NAME,
	INFO_DRIVER,
	INFO_PCIE_ID,
	INFO_VBIOS,
	INFO_VENDOR,
	INFO_DMA_MASK,
	INFO_ENABLED,
	INFO_LINK_WIDTH,
	INFO_LINK_SPEED,
	INFO_PERF_MODE,
	INFO_PERF_LEVEL,
	INFO_USAGE,
	INFO_MEM_GT_USAGE,
	INFO_VRAM_USAGE,
	INFO_TTL,
	INFO_CURRENT_FREQ,
	INFO_CURRENT_PCISPEED,
	INFO_CURRENT_MEMSPEED,
	INFO_COUNT
} InfoType;

#define MAX_INFO_TYPES 32

InfoType infoOrder[MAX_INFO_TYPES];
int infoOrderCount = 0;

#include "ascii.h"
#include "fetch.h"
#include "map.h"
#include "config.h"
#include "output.h"