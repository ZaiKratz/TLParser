#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class DhConfig : public TLBaseObject
{
public:
	DhConfig();
	DhConfig(int32 g, TArray<uint8> p, int32 version, TArray<uint8> random);

	~DhConfig();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 g;
	 TArray<uint8> p;
	 int32 version;
	 TArray<uint8> random;
};
} //end namespace block
