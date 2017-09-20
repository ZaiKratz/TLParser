#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class EditChatTitle : public TLBaseObject
{
public:
	EditChatTitle();
	EditChatTitle(int32 chat_id, FString title);

	~EditChatTitle();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	 FString title;
	COMMON::Updates* result;
};
} //end namespace block
