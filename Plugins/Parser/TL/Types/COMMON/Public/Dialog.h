#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/Peer.h"
#include "../../../Types/Common/Public/PeerNotifySettings.h"
#include "../../../Types/Common/Public/DraftMessage.h"

//begin namespace block
namespace COMMON
{
class Dialog : public TLBaseObject
{
public:
	Dialog();
	Dialog(bool pinned, PRIVATE::Peer* peer, int32 top_message, int32 read_inbox_max_id, int32 read_outbox_max_id, int32 unread_count, int32 unread_mentions_count, COMMON::PeerNotifySettings* notify_settings, int32 pts, COMMON::DraftMessage* draft);

	~Dialog();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool pinned;
	 PRIVATE::Peer* peer;
	 int32 top_message;
	 int32 read_inbox_max_id;
	 int32 read_outbox_max_id;
	 int32 unread_count;
	 int32 unread_mentions_count;
	 COMMON::PeerNotifySettings* notify_settings;
	 int32 pts;
	 COMMON::DraftMessage* draft;
};
} //end namespace block
