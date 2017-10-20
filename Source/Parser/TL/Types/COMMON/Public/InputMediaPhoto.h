#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoto.h"

//begin namespace block
namespace COMMON
{
class InputMediaPhoto : public TLBaseObject
{
public:
	InputMediaPhoto();
	InputMediaPhoto(COMMON::InputPhoto* id, FString caption, int32 ttl_seconds);

	~InputMediaPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputPhoto*  Getid() const
	{
		 return this->id;
	}

	FString Getcaption() const
	{
		 return this->caption;
	}

	int32 GetTtlSeconds() const
	{
		 return this->ttl_seconds;
	}

private:
	COMMON::InputPhoto* id;
	 FString caption;
	 int32 ttl_seconds;
};
} //end namespace block
