#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"

//begin namespace block
namespace COMMON
{
class InputPrivacyValueAllowUsers : public TLBaseObject
{
public:
	InputPrivacyValueAllowUsers();
	InputPrivacyValueAllowUsers(TArray<COMMON::InputUser*> users);

	~InputPrivacyValueAllowUsers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::InputUser*>  Getusers() const
	{
		 return this->users;
	}

private:
	TArray<COMMON::InputUser*> users;
};
} //end namespace block
