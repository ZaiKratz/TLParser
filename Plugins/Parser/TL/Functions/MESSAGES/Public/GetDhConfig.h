#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/DhConfig.h"

//begin namespace block
namespace MESSAGES
{
class GetDhConfig : public TLBaseObject
{
public:
	GetDhConfig();
	GetDhConfig(int32 version, int32 random_length);

	~GetDhConfig();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 version;
	 int32 random_length;
	MESSAGES::DhConfig* result;
};
} //end namespace block
