#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/DataJSON.h"
#include "../../../Types/Common/Public/DataJSON.h"

//begin namespace block
namespace BOTS
{
class SendCustomRequest : public TLBaseObject
{
public:
	SendCustomRequest();
	SendCustomRequest(FString custom_method, COMMON::DataJSON* params);

	~SendCustomRequest();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString custom_method;
	 COMMON::DataJSON* params;
	COMMON::DataJSON* result;
};
} //end namespace block