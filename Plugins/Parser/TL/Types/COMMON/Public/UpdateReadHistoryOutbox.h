#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Peer.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateReadHistoryOutbox : public PRIVATE::Update
{
public:
	UpdateReadHistoryOutbox();
	UpdateReadHistoryOutbox(PRIVATE::Peer* peer, int32 max_id, int32 pts, int32 pts_count);

	~UpdateReadHistoryOutbox();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::Peer* peer;
	 int32 max_id;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
