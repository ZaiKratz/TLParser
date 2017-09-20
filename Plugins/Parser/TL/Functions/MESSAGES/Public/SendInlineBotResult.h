#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class SendInlineBotResult : public TLBaseObject
{
public:
	SendInlineBotResult();
	SendInlineBotResult(bool silent, bool background, bool clear_draft, PRIVATE::InputPeer* peer, int32 reply_to_msg_id, unsigned long long random_id, unsigned long long query_id, FString id);

	~SendInlineBotResult();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool silent;
	 bool background;
	 bool clear_draft;
	 PRIVATE::InputPeer* peer;
	 int32 reply_to_msg_id;
	 unsigned long long random_id;
	 unsigned long long query_id;
	 FString id;
	COMMON::Updates* result;
};
} //end namespace block
