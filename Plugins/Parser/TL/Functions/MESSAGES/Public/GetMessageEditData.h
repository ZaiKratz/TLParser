#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Messages/Public/MessageEditData.h"

//begin namespace block
namespace MESSAGES
{
class GetMessageEditData : public TLBaseObject
{
public:
	GetMessageEditData();
	GetMessageEditData(PRIVATE::InputPeer* peer, int32 id);

	~GetMessageEditData();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPeer* peer;
	 int32 id;
	MESSAGES::MessageEditData* result;
};
} //end namespace block
