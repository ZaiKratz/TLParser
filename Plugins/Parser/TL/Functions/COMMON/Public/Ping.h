#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Pong.h"

//begin namespace block
namespace COMMON
{
class Ping : public TLBaseObject
{
public:
	Ping();
	Ping(unsigned long long ping_id);

	~Ping();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long ping_id;
	COMMON::Pong* result;
};
} //end namespace block
