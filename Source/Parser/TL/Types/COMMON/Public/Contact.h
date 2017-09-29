#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class Contact : public TLBaseObject
{
public:
	Contact();
	Contact(int32 user_id, bool mutual);

	~Contact();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	bool Getmutual() const
	{
		 return this->mutual;
	}

private:
	int32 user_id;
	 bool mutual;
};
} //end namespace block
