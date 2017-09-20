#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class DraftMessage : public TLBaseObject
{
public:
	DraftMessage();
	DraftMessage(bool no_webpage, int32 reply_to_msg_id, FString message, TArray<PRIVATE::MessageEntity*> entities, FDateTime date);

	~DraftMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool no_webpage;
	 int32 reply_to_msg_id;
	 FString message;
	 TArray<PRIVATE::MessageEntity*> entities;
	 FDateTime date;
};
} //end namespace block
