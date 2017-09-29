#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelParticipantsFilter.h"

#include "../../../Types/Private/ChannelParticipantsFilter.h"

//begin namespace block
namespace COMMON
{
class ChannelParticipantsKicked : public PRIVATE::ChannelParticipantsFilter
{
public:
	ChannelParticipantsKicked();
	ChannelParticipantsKicked(FString q);

	~ChannelParticipantsKicked();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getq() const
	{
		 return this->q;
	}

private:
	FString q;
};
} //end namespace block
