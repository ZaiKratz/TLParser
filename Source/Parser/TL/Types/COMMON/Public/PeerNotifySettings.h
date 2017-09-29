#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PeerNotifySettings : public TLBaseObject
{
public:
	PeerNotifySettings();
	PeerNotifySettings(bool show_previews, bool silent, int32 mute_until, FString sound);

	~PeerNotifySettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetShowPreviews() const
	{
		 return this->show_previews;
	}

	bool Getsilent() const
	{
		 return this->silent;
	}

	int32 GetMuteUntil() const
	{
		 return this->mute_until;
	}

	FString Getsound() const
	{
		 return this->sound;
	}

private:
	bool show_previews;
	 bool silent;
	 int32 mute_until;
	 FString sound;
};
} //end namespace block
