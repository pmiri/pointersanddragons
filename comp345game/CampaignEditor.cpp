//! @file 
//! @brief Implementation file for the CampaignEditor class  
//!
#include "CampaignEditor.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

CampaignEditor::CampaignEditor()
{

}

CampaignEditor::CampaignEditor(string fileName)
{
	loadCampaignFromFile(fileName);
}

void CampaignEditor::loadCampaignFromFile(string fileName)
{
	if (validCampaign(fileName))
		generateCampaign(fileName);
}

bool CampaignEditor::validCampaign(string fileName)
{
	currentCampaignLength = 0;
	ifstream campaignFile;
	campaignFile.open(fileName);
	string line;
	while (getline(campaignFile, line))
	{
		ifstream mapFile;
		mapFile.open(line);
		if (!mapFile.is_open())
		{
			cout << "Invalid campaign file " << fileName << ": file " << line << " not found\n";
			return false;
		}
		currentCampaignLength++;
	}
	return true;
}

Campaign CampaignEditor::generateCampaign(string fileName)
{
	ifstream campaignFile;
	campaignFile.open(fileName);
	string line;
	currentCampaign = new Campaign(currentCampaignLength);
	while (getline(campaignFile, line))
	{
		MapEditor* me = new MapEditor(line);
		if (me->validMapFile(line))
			currentCampaign->addMap(me->getCurrentMap());
		delete me;
	}
	return *currentCampaign;
}

Campaign CampaignEditor::getCampaign()
{
	return *currentCampaign;
}

int main()
{
	CampaignEditor* editor = new CampaignEditor("Maps/campaign.txt");
	delete editor;
	system("pause");
	return 0;
}