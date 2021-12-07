#include "Sound.h"

MCI_OPEN_PARMS mOpenBgm = {};

void Sound::Init(eSoundStyle eForm, const char* fileName,
	const char* fileFormat, bool bSwitch)
{
	switch (eForm)
	{
	case Sound::eSoundStyle::Bgm:
		mOpenBgm.lpstrElementName = fileName;
		mOpenBgm.lpstrDeviceType = fileFormat;
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mOpenBgm);
		dwID = mOpenBgm.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mOpenBgm);
		break;

	/*case Sound::eSoundStyle::eff:
		mvOpenEff.lpstrElementName = fileName;
		mvOpenEff.lpstrDeviceType = fileFormat;
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mvOpenEff);
		dwID = mvOpenEff.wDeviceID;
		if (!bEffSwitch)
		{
			mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mvOpenEff);
		}
		break;
		*/
	}
}


