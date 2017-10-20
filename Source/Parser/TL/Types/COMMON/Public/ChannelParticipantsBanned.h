#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ChannelParticipantsBanned : public TLBaseObject
{
public:
	ChannelParticipantsBanned();
	ChannelParticipantsBanned(FString q);

	~ChannelParticipantsBanned();
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
