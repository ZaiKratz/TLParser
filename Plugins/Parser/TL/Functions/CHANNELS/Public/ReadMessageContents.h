#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"

//begin namespace block
namespace CHANNELS
{
class ReadMessageContents : public TLBaseObject
{
public:
	ReadMessageContents();
	ReadMessageContents(COMMON::InputChannel* channel, TArray<int32> id);

	~ReadMessageContents();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	 TArray<int32> id;
	bool result;
};
} //end namespace block
