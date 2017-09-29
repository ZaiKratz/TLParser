#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelParticipantsFilter.h"

#include "../../../Types/Private/ChannelParticipantsFilter.h"

//begin namespace block
namespace COMMON
{
class ChannelParticipantsRecent : public PRIVATE::ChannelParticipantsFilter
{
public:
	ChannelParticipantsRecent();
	~ChannelParticipantsRecent();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
