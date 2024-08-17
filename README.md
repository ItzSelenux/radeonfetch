# Radeonfetch

Fetch information about you Radeon/AMD GPU

## Why?

this project is highly inspired on gpufetch, but it doesn't work on AMD GPUs

# Features:

- [x] Display basic information (see below)

- [x] Do not depend on external libraries (may change in the future, maybe in favor of using libdrm)

- [x] Basic Ascii art display

- [x] Configurable

# Installation

- Clone this repo:
```bash
git clone https://github.com/ItzSelenux/radeonfetch
```
- Build
```bash
make
```
- Install (Optional)
```bash
make install
```

# Config:

# Fetch Details:

|  Name |                       Description                      | File | Requires additional parsing? |
|:-----:|:------------------------------------------------------:|------|------------------------------|
| name | GPU Name            |  /usr/share/hwdata/pci.ids |                             Yes, reading specific line based on pci id |
| driver | Get used driver by the kernel |     uevent |                Yes, to remove "DRIVER="              |
| pciid  | Get PCI ID                    |     device |       No                       |
| vbios  | Get VBIOS                   |     vbios |       No                       |
| vendor  | Get Vendor                   |     vendor |       No                       |
| dmamask  | Get DMA Mask                 |     dmamask |       No                       |
| enabled  | Get Enabled status                |     enabled |       No                       |
| linkwidth  | Get Link Width |     linkwidth |       No                       |
| linkspeed  | Get Link Speed |     linkspeed |       No                       |
| perfmode  | Get Performance mode |     power_dpm_state |       No                       |
| perflevel  | Get Performance level |     power_dpm_force_performance_level |       No, but supports toggling "Performance" after value                       |
| usage  | Get GPU Usage |     gpu_busy_percent |       No, but supports toggling "%" after value                      |
| memgtused  | Get Mem TG Used |     mem_info_gtt_used |       Yes, to convert to human readable units                     |
| memgttotal  | Get Mem TG Total |     mem_info_gtt_total |       Yes, to convert to human readable units                     |
| vramused  | Get used VRAM |     mem_info_vram_used |       Yes, to convert to human readable units                     |
| vramtotal  | Get total VRAM |     mem_info_vram_total |       Yes, to convert to human readable units                     |
| ttl  | Get Thermal Throttling Logging status |     thermal_throttling_logging |       Yes, to get a better output |
| dpmsclk  | Get current frequency |     pp_dpm_sclk |        No, but supports show speed index
| dpmpcie  | Get current PCI Speed |     pp_dpm_pcie |        No, but supports show speed index
| dpmmclk  | Get current memory speed |     pp_dpm_mclk |       No, but supports show speed index

Single filenames refers to a file in /sys/class/drm/card0/device/

# Configuration

- The configuration needs to be saved in `$HOME/.config/radeonfetch.conf`, otherwise default values ​​will be used

| Setting                 | Description                        | Default Value     |
|-------------------------|------------------------------------|-------------------|
| DeviceNumber            | Device number                      | 0                 |
| ShowGPUName             | Show GPU name                      | 1                 |
| ShowDriver              | Show driver                        | 1                 |
| ShowPCIID               | Show PCI ID                        | 1                 |
| ShowVBios               | Show VBios                         | 1                 |
| ShowVendor              | Show vendor                        | 1                 |
| ShowDMAMask             | Show DMA mask                      | 1                 |
| ShowEnabled             | Show enabled                       | 1                 |
| ShowLinkSpeed           | Show link speed                    | 1                 |
| ShowLinkWidth           | Show link width                    | 1                 |
| ShowPerfMode            | Show performance mode              | 1                 |
| ShowPerfLevel           | Show performance level             | 0                 |
| ShowUsage               | Show usage                         | 1                 |
| ShowMemGTUsage          | Show MEM (GT) usage                | 1                 |
| ShowVramUsage           | Show VRAM usage                    | 1                 |
| ShowTTL                 | Show TTL                           | 1                 |
| ShowCurrentFreq         | Show current frequency             | 1                 |
| ShowCurrentPCISpeed     | Show current PCI speed             | 1                 |
| ShowCurrentMemSpeed     | Show current MEM speed             | 1                 |
| ShowPercentage          | Show percentage                    | 1                 |
| UseHumanValues          | Use human values                   | 1                 |
| ShowSpeedIndex          | Show speed index                   | 0                 |
| AliasGPUName            | Alias for GPU name                 | Name:             |
| AliasDriver             | Alias for driver                   | Driver:           |
| AliasPCIID              | Alias for PCI ID                   | PCI ID:           |
| AliasVBios              | Alias for VBios                    | VBios:            |
| AliasVendor             | Alias for vendor                  | Vendor:           |
| AliasDMAMask            | Alias for DMA mask                 | DMA Bits:         |
| AliasEnabled            | Alias for enabled                  | Is Enabled:       |
| AliasLinkSpeed          | Alias for link speed               | Max Link Speed:   |
| AliasLinkWidth          | Alias for link width               | Max Link Width:   |
| AliasPerfMode           | Alias for performance mode         | Performance Mode: |
| AliasPerfLevel          | Alias for performance level        | Performance Level:|
| AliasUsage              | Alias for usage                    | Usage:            |
| AliasMemGTUsage         | Alias for MEM (GT) usage           | MEM (GT) Usage:   |
| AliasVramUsage          | Alias for VRAM usage               | VRAM Usage:       |
| AliasTTL                | Alias for TTL                      | TTL:              |
| AliasCurrentFreq        | Alias for current frequency        | Current Freq.:    |
| AliasCurrentPCISpeed    | Alias for current PCI speed        | Current PCI Speed:|
| AliasCurrentMemSpeed    | Alias for current MEM speed        | Current MEM Speed:|
| ShowAsciiArt            | Show ASCII art                     | 1                 |
| DesiredAscii            | Desired ASCII                      | radeon            |

All Show* options will be displayed in the order written in the configuration, so, you can customize the order of elements
