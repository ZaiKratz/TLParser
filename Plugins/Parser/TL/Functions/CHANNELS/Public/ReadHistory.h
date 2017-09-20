#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"

//begin namespace block
namespace CHANNELS
{
class ReadHistory : public TLBaseObject
{
public:
	ReadHistory();
	ReadHistory(COMMON::InputChannel* channel, int32 max_id);

	~ReadHistory();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	 int32 max_id;
	bool result;
};
} //end namespace block
