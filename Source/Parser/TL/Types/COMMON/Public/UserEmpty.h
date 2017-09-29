#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace COMMON
{
class UserEmpty : public TLBaseObject
{
public:
	UserEmpty();
	UserEmpty(int32 id);

	~UserEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getid() const
	{
		 return this->id;
	}

private:
	int32 id;
};
} //end namespace block
