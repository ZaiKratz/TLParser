#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/DhConfig.h"

//begin namespace block
namespace MESSAGES
{
class DhConfigNotModified : public TLBaseObject
{
public:
	DhConfigNotModified();
	DhConfigNotModified(TArray<uint8> random);

	~DhConfigNotModified();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<uint8> random;
};
} //end namespace block
