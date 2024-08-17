void PrintInfo() {

const char **ascii_art;
int alimit;
if (strcmp(desiredascii, "vega") == 0)
{
	ascii_art = ascii_vega;
	alimit = 15;
}
else
{
	ascii_art = ascii_radeon;
	alimit = 18;
}

	for (int i = 0; i < alimit; i++)
	{
		int index = (i < alimit) ? i : (alimit - 1);
		printf("%-10s   ", ascii_art[index]);

		InfoType type;
		if (i < infoOrderCount)
		{
			type = infoOrder[i];
		}
		else
		{
			type = INFO_COUNT;
		}

		switch (type)
		{
			case INFO_GPU_NAME:
				if (sname)
				{
					getvalues(fpciid, &pciid);
					mapgpu();
					printf("%s %s\n", aname, name);
				}
				else
				{
					printf("\n");
				}
				break;

			case INFO_DRIVER:
				if (sdriver)
				{
					getvalues(fdriver, &driver);
					mapdriver();
					printf("%s %s\n", adriver, driver);
				}
				break;

			case INFO_PCIE_ID:
				if (spciid)
				{
					getvalues(fpciid, &pciid);
					printf("%s %s\n", apciid, pciid);
				}
				break;

			case INFO_VBIOS:
				if (svbios)
				{
					getvalues(fvbios, &vbios);
					printf("%s %s\n", avbios, vbios);
				}
				break;

			case INFO_VENDOR:
				if (svendor)
				{
					getvalues(fvendor, &vendor);
					printf("%s %s\n", avendor, vendor);
				}
				break;

			case INFO_DMA_MASK:
				if (sdmamask)
				{
					getvalues(fdmamask, &dmamask);
					printf("%s %s\n", admamask, dmamask);
				}
				break;

			case INFO_ENABLED:
				if (senabled) {
					getvalues(fenabled, &enabled);
					printf("%s %s\n", aenabled, enabled);
				}
				break;

			case INFO_LINK_WIDTH:
				if (slinkwidth)
				{
					getvalues(flinkwidth, &linkwidth);
					printf("%s %s\n", alinkwidth, linkwidth);
				}
				break;

			case INFO_LINK_SPEED:
				if (slinkspeed) {
					getvalues(flinkspeed, &linkspeed);
					printf("%s %s\n", alinkspeed, linkspeed);
				}
				break;

			case INFO_PERF_MODE:
				if (sperfmode)
				{
					getvalues(fperfmode, &perfmode);
					printf("%s %s\n", aperfmode, perfmode);
				}
				break;

			case INFO_PERF_LEVEL:
				if (sperflevel)
				{
					getvalues(fperflevel, &perflevel);
					printf("%s %s %s\n", aperflevel, perflevel, lvl);
				}
				break;

			case INFO_USAGE:
				if (susage)
				{
					getvalues(fusage, &usage);
					printf("%s %s%s\n", ausage, usage, perc);
				}
				break;

			case INFO_MEM_GT_USAGE:
				if (smemgtused)
				{
					getvalues(fmemgtused, &memgtused);
					mapmem(memgtused);
					getvalues(fmemgttotal, &memgttotal);
					mapmem(memgttotal);
					printf("%s %s%s / %s%s\n", amemgtused, memgtused, mb, memgttotal, mb);
				}
				break;

			case INFO_VRAM_USAGE:
				if (svramused)
				{
					getvalues(fvramused, &vramused);
					mapmem(vramused);
					getvalues(fvramtotal, &vramtotal);
					mapmem(vramtotal);
					printf("%s %s%s / %s%s\n", avramused, vramused, mb, vramtotal, mb);
				}
				break;

			case INFO_TTL:
				if (sttl)
				{
					getvalues(fttl, &ttl);
					mapttl();
					printf("%s %s\n", attl, ttl);
				}
				break;

			case INFO_CURRENT_FREQ:
				if (sdpmsclk)
				{
					getvalues(fdpmsclk, &dpmsclk);
					mappwr(dpmsclk, fdpmsclk);
					printf("%s %s\n", adpmsclk, dpmsclk);
				}
				break;

			case INFO_CURRENT_PCISPEED:
				if (sdpmpcie)
				{
					getvalues(fdpmpcie, &dpmpcie);
					mappwr(dpmpcie, fdpmpcie);
					printf("%s %s\n", adpmpcie, dpmpcie);
				}
				break;

			case INFO_CURRENT_MEMSPEED:
				if (sdpmmclk)
				{
					getvalues(fdpmmclk, &dpmmclk);
					mappwr(dpmmclk, fdpmmclk);
					printf("%s %s\n", adpmmclk, dpmmclk);
				}
				break;

			default:
				printf("\n");
				break;
		}
	}
}