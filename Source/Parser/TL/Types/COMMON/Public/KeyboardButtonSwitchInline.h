#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/KeyboardButton.h"

//begin namespace block
namespace COMMON
{
class KeyboardButtonSwitchInline : public TLBaseObject
{
public:
	KeyboardButtonSwitchInline();
	KeyboardButtonSwitchInline(bool same_peer, FString text, FString query);

	~KeyboardButtonSwitchInline();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetSamePeer() const
	{
		 return this->same_peer;
	}

	FString Gettext() const
	{
		 return this->text;
	}

	FString Getquery() const
	{
		 return this->query;
	}

private:
	bool same_peer;
	 FString text;
	 FString query;
};
} //end namespace block
