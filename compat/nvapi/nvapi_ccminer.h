#pragma once

#include "nvapi.h"

NvAPI_Status nvapi_dll_init();

typedef struct {
	NvU32 version;
	NvU32 flags;
	struct
	{
		NvU32 pstate; // Assumption
		NvU32 unknown1[2];
		NvU32 min_power;
		NvU32 unknown2[2];
		NvU32 def_power;
		NvU32 unknown3[2];
		NvU32 max_power;
		NvU32 unknown4; // 0
	} entries[4];
} NVAPI_GPU_POWER_INFO;
#define NVAPI_GPU_POWER_INFO_VER MAKE_NVAPI_VERSION(NVAPI_GPU_POWER_INFO, 1)

typedef struct {
	NvU32 version;
	NvU32 flags;
	struct {
		NvU32 unknown1;
		NvU32 unknown2;
		NvU32 power; // percent * 1000
		NvU32 unknown4;
	} entries[4];
} NVAPI_GPU_POWER_STATUS;
#define NVAPI_GPU_POWER_STATUS_VER MAKE_NVAPI_VERSION(NVAPI_GPU_POWER_STATUS, 1)

typedef struct {
	NvU32 version;
	NvU32 count;
	struct {
		NvU32 unknown1;
		NvU32 unknown2;
		NvU32 power; // unsure ?? 85536 to 95055 on 1080, 104825+ on 970
		NvU32 unknown4;
	} entries[4];
} NVAPI_GPU_POWER_TOPO;
#define NVAPI_GPU_POWER_TOPO_VER MAKE_NVAPI_VERSION(NVAPI_GPU_POWER_TOPO, 1)

typedef struct {
	NvU32 version;
	NvU32 flags;
	struct {
		NvU32 controller;
		NvU32 unknown;
		NvS32 min_temp;
		NvS32 def_temp;
		NvS32 max_temp;
		NvU32 defaultFlags;
	} entries[4];
} NVAPI_GPU_THERMAL_INFO;
#define NVAPI_GPU_THERMAL_INFO_VER MAKE_NVAPI_VERSION(NVAPI_GPU_THERMAL_INFO, 2)

typedef struct {
	NvU32 version;
	NvU32 flags;
	struct {
		NvU32 controller;
		NvU32 value;
		NvU32 flags;
	} entries[4];
} NVAPI_GPU_THERMAL_LIMIT;
#define NVAPI_GPU_THERMAL_LIMIT_VER MAKE_NVAPI_VERSION(NVAPI_GPU_THERMAL_LIMIT, 2)

typedef struct {
	NvU32 version;
	NvU32 flags;
	struct {
		NvU32 voltage_domain;
		NvU32 current_voltage;
	} entries[16];
} NVIDIA_GPU_VOLTAGE_DOMAINS_STATUS;
#define NVIDIA_GPU_VOLTAGE_DOMAINS_STATUS_VER MAKE_NVAPI_VERSION(NVIDIA_GPU_VOLTAGE_DOMAINS_STATUS, 1)

typedef struct {
	NvU32 version;
	NvU32 numClocks; // unsure
	NvU32 nul[8];
	struct {
		NvU32 a;
		NvU32 clockType;
		NvU32 c;
		NvU32 d;
		NvU32 e;
		NvU32 f;
		NvU32 g;
		NvU32 h;
		NvU32 i;
		NvU32 j;
		NvS32 rangeMax;
		NvS32 rangeMin;
		NvS32 tempMax; // ? unsure
		NvU32 n;
		NvU32 o;
		NvU32 p;
		NvU32 q;
		NvU32 r;
	} entries[32]; // NVAPI_MAX_GPU_CLOCKS ?
} NVAPI_CLOCKS_RANGE; // 2344 bytes
#define NVAPI_CLOCKS_RANGE_VER MAKE_NVAPI_VERSION(NVAPI_CLOCKS_RANGE, 1)

// seems to return a clock table mask
typedef struct {
	NvU32 version;
	NvU32 mask[4]; // 80 bits mask
	NvU32 buf0[8];
	struct {
		NvU32 a;
		NvU32 b;
		NvU32 c;
		NvU32 d;
		NvU32 memDelta; // 1 for mem
		NvU32 gpuDelta; // 1 for gpu
	} clocks[80 + 23];
	NvU32 buf1[916];
} NVAPI_CLOCK_MASKS; // 6188 bytes
#define NVAPI_CLOCK_MASKS_VER MAKE_NVAPI_VERSION(NVAPI_CLOCK_MASKS, 1)

// contains the gpu/mem clocks deltas
typedef struct {
	NvU32 version;
	NvU32 mask[4]; // 80 bits mask
	NvU32 buf0[12];
	struct {
		NvU32 a;
		NvU32 b;
		NvU32 c;
		NvU32 d;
		NvU32 e;
		NvS32 freqDelta; // 84000 = +84MHz
		NvU32 g;
		NvU32 h;
		NvU32 i;
	} gpuDeltas[80];
	NvU32 memFilled[23]; // maybe only 4 max
	NvS32 memDeltas[23];
	NvU32 buf1[1529];
} NVAPI_CLOCK_TABLE; // 9248 bytes
#define NVAPI_CLOCK_TABLE_VER MAKE_NVAPI_VERSION(NVAPI_CLOCK_TABLE, 1)

typedef struct {
	NvU32 version;
	NvU32 mask[4]; // 80 bits mask
	NvU32 buf0[12];
	struct {
		NvU32 a; // 0
		NvU32 freq_kHz;
		NvU32 volt_uV;
		NvU32 d;
		NvU32 e;
		NvU32 f;
		NvU32 g;
	} gpuEntries[80];
	struct {
		NvU32 a;  // 1 for idle values ?
		NvU32 freq_kHz;
		NvU32 volt_uV;
		NvU32 d;
		NvU32 e;
		NvU32 f;
		NvU32 g;
	} memEntries[23];
	NvU32 buf1[1064];
} NVAPI_VFP_CURVE; // 7208 bytes (1-1c28)
#define NVAPI_VFP_CURVE_VER MAKE_NVAPI_VERSION(NVAPI_VFP_CURVE, 1)

typedef struct {
	NvU32 version;
	NvU32 flags;
	NvU32 count; // unsure
	NvU32 unknown;
	NvU32 value_uV;
	NvU32 buf1[30];
} NVAPI_VOLT_STATUS; // 140 bytes (1-008c)
#define NVAPI_VOLT_STATUS_VER MAKE_NVAPI_VERSION(NVAPI_VOLT_STATUS, 1)

NvAPI_Status NvAPI_DLL_GetInterfaceVersionString(NvAPI_ShortString string);

NvAPI_Status NvAPI_DLL_ClientPowerPoliciesGetInfo(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_GPU_POWER_INFO*);
NvAPI_Status NvAPI_DLL_ClientPowerPoliciesGetStatus(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_GPU_POWER_STATUS*);
NvAPI_Status NvAPI_DLL_ClientPowerPoliciesSetStatus(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_GPU_POWER_STATUS*);
NvAPI_Status NvAPI_DLL_ClientPowerTopologyGetStatus(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_GPU_POWER_TOPO*); // EDCF624E 1-0048

NvAPI_Status NvAPI_DLL_ClientThermalPoliciesGetInfo(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_GPU_THERMAL_INFO*);
NvAPI_Status NvAPI_DLL_ClientThermalPoliciesGetLimit(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_GPU_THERMAL_LIMIT*);
NvAPI_Status NvAPI_DLL_ClientThermalPoliciesSetLimit(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_GPU_THERMAL_LIMIT*);

NvAPI_Status NvAPI_DLL_GetVoltageDomainsStatus(NvPhysicalGpuHandle hPhysicalGpu, NVIDIA_GPU_VOLTAGE_DOMAINS_STATUS*);

// Pascal GTX only
NvAPI_Status NvAPI_DLL_GetClockBoostRanges(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_CLOCKS_RANGE*);
NvAPI_Status NvAPI_DLL_GetClockBoostMask(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_CLOCK_MASKS*); // 0x507B4B59
NvAPI_Status NvAPI_DLL_GetClockBoostTable(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_CLOCK_TABLE*); // 0x23F1B133
NvAPI_Status NvAPI_DLL_GetVFPCurve(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_VFP_CURVE*); // 0x21537AD4

// Maxwell ?
NvAPI_Status NvAPI_DLL_GetVoltageDomainsStatus(NvPhysicalGpuHandle hPhysicalGpu, NVAPI_VOLT_STATUS*); // 0xC16C7E2C

NvAPI_Status NvAPI_DLL_GetPerfClocks(NvPhysicalGpuHandle hPhysicalGpu, void* pFreqs);

NvAPI_Status NvAPI_DLL_GetSerialNumber(NvPhysicalGpuHandle handle, NvAPI_ShortString serial);

NvAPI_Status NvAPI_DLL_SetPstates20v1(NvPhysicalGpuHandle handle, NV_GPU_PERF_PSTATES20_INFO_V1 *pSet);
NvAPI_Status NvAPI_DLL_SetPstates20v2(NvPhysicalGpuHandle handle, NV_GPU_PERF_PSTATES20_INFO_V2 *pSet);

NvAPI_Status NvAPI_DLL_Unload();

#define NV_ASSERT(x) { NvAPI_Status ret = x; if(ret != NVAPI_OK) return ret; }
