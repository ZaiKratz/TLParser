#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Messages/Public/Messages.h"

//begin namespace block
namespace MESSAGES
{
class GetHistory : public TLBaseObject
{
public:
	GetHistory();
	GetHistory(PRIVATE::InputPeer* peer, int32 offset_id, FDateTime offset_date, int32 add_offset, int32 limit, int32 max_id, int32 min_id);

	~GetHistory();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPeer* peer;
	 int32 offset_id;
	 FDateTime offset_date;
	 int32 add_offset;
	 int32 limit;
	 int32 max_id;
	 int32 min_id;
	MESSAGES::Messages* result;
};
} //end namespace block
