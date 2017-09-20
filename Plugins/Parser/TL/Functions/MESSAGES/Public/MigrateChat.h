#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class MigrateChat : public TLBaseObject
{
public:
	MigrateChat();
	MigrateChat(int32 chat_id);

	~MigrateChat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	COMMON::Updates* result;
};
} //end namespace block
