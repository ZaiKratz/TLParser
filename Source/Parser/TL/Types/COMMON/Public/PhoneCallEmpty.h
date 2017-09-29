#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhoneCall.h"

//begin namespace block
namespace COMMON
{
class PhoneCallEmpty : public TLBaseObject
{
public:
	PhoneCallEmpty();
	PhoneCallEmpty(unsigned long long id);

	~PhoneCallEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

private:
	unsigned long long id;
};
} //end namespace block
