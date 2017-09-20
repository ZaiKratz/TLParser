#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelParticipantsFilter.h"

#include "../../../Types/Private/ChannelParticipantsFilter.h"

//begin namespace block
namespace COMMON
{
class ChannelParticipantsAdmins : public PRIVATE::ChannelParticipantsFilter
{
public:
	ChannelParticipantsAdmins();
	~ChannelParticipantsAdmins();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block