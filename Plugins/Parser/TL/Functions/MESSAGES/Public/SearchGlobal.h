#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Messages/Public/Messages.h"

//begin namespace block
namespace MESSAGES
{
class SearchGlobal : public TLBaseObject
{
public:
	SearchGlobal();
	SearchGlobal(FString q, FDateTime offset_date, PRIVATE::InputPeer* offset_peer, int32 offset_id, int32 limit);

	~SearchGlobal();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString q;
	 FDateTime offset_date;
	 PRIVATE::InputPeer* offset_peer;
	 int32 offset_id;
	 int32 limit;
	MESSAGES::Messages* result;
};
} //end namespace block
