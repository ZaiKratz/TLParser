#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChatPhoto.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class EditChatPhoto : public TLBaseObject
{
public:
	EditChatPhoto();
	EditChatPhoto(int32 chat_id, COMMON::InputChatPhoto* photo);

	~EditChatPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	COMMON::InputChatPhoto*  Getphoto() const
	{
		 return this->photo;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	int32 chat_id;
	 COMMON::InputChatPhoto* photo;
	COMMON::Updates* result;
};
} //end namespace block
