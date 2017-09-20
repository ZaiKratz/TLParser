#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"

//begin namespace block
namespace CHANNELS
{
class CheckUsername : public TLBaseObject
{
public:
	CheckUsername();
	CheckUsername(COMMON::InputChannel* channel, FString username);

	~CheckUsername();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	 FString username;
	bool result;
};
} //end namespace block
