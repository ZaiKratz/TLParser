#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"

//begin namespace block
namespace COMMON
{
class MessageActionChatEditPhoto : public TLBaseObject
{
public:
	MessageActionChatEditPhoto();
	MessageActionChatEditPhoto(COMMON::Photo* photo);

	~MessageActionChatEditPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Photo*  Getphoto() const
	{
		 return this->photo;
	}

private:
	COMMON::Photo* photo;
};
} //end namespace block
