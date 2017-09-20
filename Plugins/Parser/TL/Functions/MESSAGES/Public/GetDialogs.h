#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Messages/Public/Dialogs.h"

//begin namespace block
namespace MESSAGES
{
class GetDialogs : public TLBaseObject
{
public:
	GetDialogs();
	GetDialogs(bool exclude_pinned, FDateTime offset_date, int32 offset_id, PRIVATE::InputPeer* offset_peer, int32 limit);

	~GetDialogs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool exclude_pinned;
	 FDateTime offset_date;
	 int32 offset_id;
	 PRIVATE::InputPeer* offset_peer;
	 int32 limit;
	MESSAGES::Dialogs* result;
};
} //end namespace block
