#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PrivacyValueDisallowUsers : public TLBaseObject
{
public:
	PrivacyValueDisallowUsers();
	PrivacyValueDisallowUsers(TArray<int32> users);

	~PrivacyValueDisallowUsers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<int32>  Getusers() const
	{
		 return this->users;
	}

private:
	TArray<int32> users;
};
} //end namespace block
