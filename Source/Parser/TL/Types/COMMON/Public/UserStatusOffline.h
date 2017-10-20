#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UserStatusOffline : public TLBaseObject
{
public:
	UserStatusOffline();
	UserStatusOffline(FDateTime was_online);

	~UserStatusOffline();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FDateTime GetWasOnline() const
	{
		 return this->was_online;
	}

private:
	FDateTime was_online;
};
} //end namespace block
