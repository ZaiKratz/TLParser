#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Peer.h"
#include "../../../Types/Common/Public/DraftMessage.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateDraftMessage : public PRIVATE::Update
{
public:
	UpdateDraftMessage();
	UpdateDraftMessage(PRIVATE::Peer* peer, COMMON::DraftMessage* draft);

	~UpdateDraftMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::Peer* peer;
	 COMMON::DraftMessage* draft;
};
} //end namespace block
