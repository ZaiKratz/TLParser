#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateUserBlocked : public TLBaseObject
{
public:
	UpdateUserBlocked();
	UpdateUserBlocked(int32 user_id, bool blocked);

	~UpdateUserBlocked();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	bool Getblocked() const
	{
		 return this->blocked;
	}

private:
	int32 user_id;
	 bool blocked;
};
} //end namespace block
