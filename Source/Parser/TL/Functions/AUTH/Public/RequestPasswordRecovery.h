#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/PasswordRecovery.h"

//begin namespace block
namespace AUTH
{
class RequestPasswordRecovery : public TLBaseObject
{
public:
	RequestPasswordRecovery();
	~RequestPasswordRecovery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	AUTH::PasswordRecovery* GetResult() const
	{
		 return this->result;
	}

private:
	AUTH::PasswordRecovery* result;
};
} //end namespace block
