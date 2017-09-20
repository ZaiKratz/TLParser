#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/Peer.h"
#include "../../../Types/Private/MessageAction.h"
#include "../../../Types/Common/Public/Message.h"

//begin namespace block
namespace COMMON
{
class MessageService : public TLBaseObject
{
public:
	MessageService();
	MessageService(bool out, bool mentioned, bool media_unread, bool silent, bool post, int32 id, int32 from_id, PRIVATE::Peer* to_id, int32 reply_to_msg_id, FDateTime date, PRIVATE::MessageAction* action);

	~MessageService();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool out;
	 bool mentioned;
	 bool media_unread;
	 bool silent;
	 bool post;
	 int32 id;
	 int32 from_id;
	 PRIVATE::Peer* to_id;
	 int32 reply_to_msg_id;
	 FDateTime date;
	 PRIVATE::MessageAction* action;
};
} //end namespace block
