#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/Chats.h"

//begin namespace block
namespace CHANNELS
{
class GetAdminedPublicChannels : public TLBaseObject
{
public:
	GetAdminedPublicChannels();
	~GetAdminedPublicChannels();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	MESSAGES::Chats* result;
};
} //end namespace block
