#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class DiscardEncryption : public TLBaseObject
{
public:
	DiscardEncryption();
	DiscardEncryption(int32 chat_id);

	~DiscardEncryption();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	int32 chat_id;
	bool result;
};
} //end namespace block
