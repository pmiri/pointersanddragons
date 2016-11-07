//! @file 
//! @brief Implementation file for the CampaignEditor class  
//! The CampaignEditor class generates a Campaign class from a .txt file
//!
#pragma once

using namespace std;
#include "MapEditor.h"
#include "Campaign.h"

class CampaignEditor
{
public:
	CampaignEditor();
	CampaignEditor(string);
	void loadCampaignFromFile(string);
	bool validCampaign(string);
	Campaign generateCampaign(string);
	Campaign getCampaign();
private:
	Campaign* currentCampaign;
	int currentCampaignLength;
};
