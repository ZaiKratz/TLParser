#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/DataJSON.h"

//begin namespace block
namespace COMMON
{
class InputPaymentCredentials : public TLBaseObject
{
public:
	InputPaymentCredentials();
	InputPaymentCredentials(bool save, COMMON::DataJSON* data);

	~InputPaymentCredentials();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool save;
	 COMMON::DataJSON* data;
};
} //end namespace block
