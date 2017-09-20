#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Messages/Public/AffectedHistory.h"

//begin namespace block
namespace MESSAGES
{
class DeleteHistory : public TLBaseObject
{
public:
	DeleteHistory();
	DeleteHistory(bool just_clear, PRIVATE::InputPeer* peer, int32 max_id);

	~DeleteHistory();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool just_clear;
	 PRIVATE::InputPeer* peer;
	 int32 max_id;
	MESSAGES::AffectedHistory* result;
};
} //end namespace block
