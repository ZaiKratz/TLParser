#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Private/MessagesFilter.h"
#include "../../../Types/Messages/Public/Messages.h"

//begin namespace block
namespace MESSAGES
{
class Search : public TLBaseObject
{
public:
	Search();
	Search(PRIVATE::InputPeer* peer, FString q, COMMON::InputUser* from_id, PRIVATE::MessagesFilter* filter, FDateTime min_date, FDateTime max_date, int32 offset_id, int32 add_offset, int32 limit, int32 max_id, int32 min_id);

	~Search();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPeer* peer;
	 FString q;
	 COMMON::InputUser* from_id;
	 PRIVATE::MessagesFilter* filter;
	 FDateTime min_date;
	 FDateTime max_date;
	 int32 offset_id;
	 int32 add_offset;
	 int32 limit;
	 int32 max_id;
	 int32 min_id;
	MESSAGES::Messages* result;
};
} //end namespace block
