#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelParticipantsFilter.h"

#include "../../../Types/Private/ChannelParticipantsFilter.h"

//begin namespace block
namespace COMMON
{
class ChannelParticipantsSearch : public PRIVATE::ChannelParticipantsFilter
{
public:
	ChannelParticipantsSearch();
	ChannelParticipantsSearch(FString q);

	~ChannelParticipantsSearch();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString q;
};
} //end namespace block
