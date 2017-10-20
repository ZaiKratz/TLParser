#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputPeerChat : public TLBaseObject
{
public:
	InputPeerChat();
	InputPeerChat(int32 chat_id);

	~InputPeerChat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

private:
	int32 chat_id;
};
} //end namespace block
