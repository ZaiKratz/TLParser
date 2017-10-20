#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class ExportChatInvite : public TLBaseObject
{
public:
	ExportChatInvite();
	ExportChatInvite(int32 chat_id);

	~ExportChatInvite();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	int32 chat_id;
	TLBaseObject* result;
};
} //end namespace block
