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
private:
	int32 chat_id;
	 COMMON::InputChatPhoto* photo;
	COMMON::Updates* result;
};
} //end namespace block
