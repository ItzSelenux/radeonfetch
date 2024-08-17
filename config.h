void readconf()
{
	if (home_dir == NULL)
	{
		fprintf(stderr, "Error: HOME environment variable is not set.\n");
		return;
	}

	char config_file_path[1024];
	snprintf(config_file_path, sizeof(config_file_path), "%s/.config/radeonfetch.conf", home_dir);

	FILE *file = fopen(config_file_path, "r");
	if (file == NULL)
	{
		return;
	}

	char line[ML];
	while (fgets(line, ML, file) != NULL)
	{
		char *entry = strtok(line, "=");
		char *value_str = strtok(NULL, "=");

		if (entry != NULL && value_str != NULL)
		{
			char *newline = strchr(value_str, '\n');
			if (newline)
				*newline = '\0';

			if (strcmp(entry, "DeviceNumber") == 0)
				devicenumber = atoi(value_str);
			else if (strcmp(entry, "ShowAsciiArt") == 0)
				showascii = atoi(value_str);
			else if (strcmp(entry, "DesiredAscii") == 0)
				strncpy(desiredascii, value_str, sizeof(desiredascii) - 1);

			else if (strcmp(entry, "ShowGPUName") == 0)
			{
				sname = atoi(value_str);
				if (sname)
				{
					infoOrder[infoOrderCount++] = INFO_GPU_NAME;
				}
			}
			else if (strcmp(entry, "ShowDriver") == 0)
			{
				sdriver = atoi(value_str);
				if (sdriver)
				{
					infoOrder[infoOrderCount++] = INFO_DRIVER;
				}
			}
			else if (strcmp(entry, "ShowPCIID") == 0)
			{
				spciid = atoi(value_str);
				if (spciid)
				{
					infoOrder[infoOrderCount++] = INFO_PCIE_ID;
				}
			}
			else if (strcmp(entry, "ShowVBios") == 0)
			{
				svbios = atoi(value_str);
				if (svbios)
				{
					infoOrder[infoOrderCount++] = INFO_VBIOS;
				}
			}
			else if (strcmp(entry, "ShowVendor") == 0)
			{
				svendor = atoi(value_str);
				if (svendor)
				{
					infoOrder[infoOrderCount++] = INFO_VENDOR;
				}
			}
			else if (strcmp(entry, "ShowDMAMask") == 0)
			{
				sdmamask = atoi(value_str);
				if (sdmamask)
				{
					infoOrder[infoOrderCount++] = INFO_DMA_MASK;
				}
			}
			else if (strcmp(entry, "ShowEnabled") == 0)
			{
				senabled = atoi(value_str);
				if (senabled)
				{
					infoOrder[infoOrderCount++] = INFO_ENABLED;
				}
			}
			else if (strcmp(entry, "ShowLinkSpeed") == 0)
			{
				slinkspeed = atoi(value_str);
				if (slinkspeed)
				{
					infoOrder[infoOrderCount++] = INFO_LINK_SPEED;
				}
			}
			else if (strcmp(entry, "ShowLinkWidth") == 0)
			{
				slinkwidth = atoi(value_str);
				if (slinkwidth)
				{
					infoOrder[infoOrderCount++] = INFO_LINK_WIDTH;
				}
			}
			else if (strcmp(entry, "ShowPerfMode") == 0)
			{
				sperfmode = atoi(value_str);
				if (sperfmode)
				{
					infoOrder[infoOrderCount++] = INFO_PERF_MODE;
				}
			}
			else if (strcmp(entry, "ShowPerfLevel") == 0)
			{
				sperflevel = atoi(value_str);
				if (sperflevel)
				{
					infoOrder[infoOrderCount++] = INFO_PERF_LEVEL;
				}
			}
			else if (strcmp(entry, "ShowUsage") == 0)
			{
				susage = atoi(value_str);
				if (susage)
				{
					infoOrder[infoOrderCount++] = INFO_USAGE;
				}
			}
			else if (strcmp(entry, "ShowMemGTUsage") == 0)
			{
				smemgtused = atoi(value_str);
				if (smemgtused)
				{
					infoOrder[infoOrderCount++] = INFO_MEM_GT_USAGE;
				}
			}
			else if (strcmp(entry, "ShowVramUsage") == 0)
			{
				svramused = atoi(value_str);
				if (svramused)
				{
					infoOrder[infoOrderCount++] = INFO_VRAM_USAGE;
				}
			}
			else if (strcmp(entry, "ShowTTL") == 0)
			{
				sttl = atoi(value_str);
				if (sttl)
				{
					infoOrder[infoOrderCount++] = INFO_TTL;
				}
			}
			else if (strcmp(entry, "ShowCurrentFreq") == 0)
			{
				sdpmsclk = atoi(value_str);
				if (sdpmsclk)
				{
					infoOrder[infoOrderCount++] = INFO_CURRENT_FREQ;
				}
			}
			else if (strcmp(entry, "ShowCurrentPCISpeed") == 0)
			{
				sdpmpcie = atoi(value_str);
				if (sdpmpcie)
				{
					infoOrder[infoOrderCount++] = INFO_CURRENT_PCISPEED;
				}
			}
			else if (strcmp(entry, "ShowCurrentMemSpeed") == 0)
			{
				sdpmmclk = atoi(value_str);
				if (sdpmmclk)
				{
					infoOrder[infoOrderCount++] = INFO_CURRENT_MEMSPEED;
				}
			}


			else if (strcmp(entry, "ShowPercentage") == 0)
				showpercentage = atoi(value_str);
			else if (strcmp(entry, "UseHumanValues") == 0)
				usehumanvalues = atoi(value_str);
			else if (strcmp(entry, "ShowSpeedIndex") == 0)
				showspeedindex = atoi(value_str);
			else if (strcmp(entry, "AliasGPUName") == 0)
			{
				strncpy(aname, value_str, sizeof(aname) - 1);
				aname[sizeof(aname) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasDriver") == 0)
			{
				strncpy(adriver, value_str, sizeof(adriver) - 1);
				adriver[sizeof(adriver) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasPCIID") == 0)
			{
				strncpy(apciid, value_str, sizeof(apciid) - 1);
				apciid[sizeof(apciid) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasVBios") == 0)
			{
				strncpy(avbios, value_str, sizeof(avbios) - 1);
				avbios[sizeof(avbios) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasVendor") == 0)
			{
				strncpy(avendor, value_str, sizeof(avendor) - 1);
				avendor[sizeof(avendor) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasDMAMask") == 0)
			{
				strncpy(admamask, value_str, sizeof(admamask) - 1);
				admamask[sizeof(admamask) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasEnabled") == 0)
			{
				strncpy(aenabled, value_str, sizeof(aenabled) - 1);
				aenabled[sizeof(aenabled) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasLinkSpeed") == 0)
			{
				strncpy(alinkspeed, value_str, sizeof(alinkspeed) - 1);
				alinkspeed[sizeof(alinkspeed) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasLinkWidth") == 0)
			{
				strncpy(alinkwidth, value_str, sizeof(alinkwidth) - 1);
				alinkwidth[sizeof(alinkwidth) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasPerfMode") == 0)
			{
				strncpy(aperfmode, value_str, sizeof(aperfmode) - 1);
				aperfmode[sizeof(aperfmode) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasPerfLevel") == 0)
			{
				strncpy(aperflevel, value_str, sizeof(aperflevel) - 1);
				aperflevel[sizeof(aperflevel) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasUsage") == 0)
			{
				strncpy(ausage, value_str, sizeof(ausage) - 1);
				ausage[sizeof(ausage) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasMemGTUsage") == 0)
			{
				strncpy(amemgtused, value_str, sizeof(amemgtused) - 1);
				amemgtused[sizeof(amemgtused) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasVramUsage") == 0)
			{
				strncpy(avramused, value_str, sizeof(avramused) - 1);
				avramused[sizeof(avramused) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasTTL") == 0)
			{
				strncpy(attl, value_str, sizeof(attl) - 1);
				attl[sizeof(attl) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasCurrentFreq") == 0)
			{
				strncpy(adpmsclk, value_str, sizeof(adpmsclk) - 1);
				adpmsclk[sizeof(adpmsclk) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasCurrentPCISpeed") == 0)
			{
				strncpy(adpmpcie, value_str, sizeof(adpmpcie) - 1);
				adpmpcie[sizeof(adpmpcie) - 1] = '\0';
			}
			else if (strcmp(entry, "AliasCurrentMemSpeed") == 0)
			{
				strncpy(adpmmclk, value_str, sizeof(adpmmclk) - 1);
				adpmmclk[sizeof(adpmmclk) - 1] = '\0';
			}
		}
	}
	fclose(file);
}