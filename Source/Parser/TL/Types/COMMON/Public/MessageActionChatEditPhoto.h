#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionChatEditPhoto : public PRIVATE::MessageAction
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
