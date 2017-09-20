#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputPeerNotifySettings : public TLBaseObject
{
public:
	InputPeerNotifySettings();
	InputPeerNotifySettings(bool show_previews, bool silent, int32 mute_until, FString sound);

	~InputPeerNotifySettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool show_previews;
	 bool silent;
	 int32 mute_until;
	 FString sound;
};
} //end namespace block
