#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputChannel : public TLBaseObject
{
public:
	InputChannel();
	InputChannel(int32 channel_id, unsigned long long access_hash);

	~InputChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 channel_id;
	 unsigned long long access_hash;
};
} //end namespace block
