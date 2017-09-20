#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class UnregisterDevice : public TLBaseObject
{
public:
	UnregisterDevice();
	UnregisterDevice(int32 token_type, FString token);

	~UnregisterDevice();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 token_type;
	 FString token;
	bool result;
};
} //end namespace block
