#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateUserTyping : public TLBaseObject
{
public:
	UpdateUserTyping();
	UpdateUserTyping(int32 user_id, TLBaseObject* action);

	~UpdateUserTyping();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	TLBaseObject*  Getaction() const
	{
		 return this->action;
	}

private:
	int32 user_id;
	 TLBaseObject* action;
};
} //end namespace block
