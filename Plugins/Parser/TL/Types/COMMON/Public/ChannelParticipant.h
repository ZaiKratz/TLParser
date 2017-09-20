#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ChannelParticipant : public TLBaseObject
{
public:
	ChannelParticipant();
	ChannelParticipant(int32 user_id, FDateTime date);

	~ChannelParticipant();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 FDateTime date;
};
} //end namespace block
