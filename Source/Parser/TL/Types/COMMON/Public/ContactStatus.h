#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ContactStatus : public TLBaseObject
{
public:
	ContactStatus();
	ContactStatus(int32 user_id, TLBaseObject* status);

	~ContactStatus();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	TLBaseObject*  Getstatus() const
	{
		 return this->status;
	}

private:
	int32 user_id;
	 TLBaseObject* status;
};
} //end namespace block
