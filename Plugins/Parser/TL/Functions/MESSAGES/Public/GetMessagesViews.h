#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"

//begin namespace block
namespace MESSAGES
{
class GetMessagesViews : public TLBaseObject
{
public:
	GetMessagesViews();
	GetMessagesViews(PRIVATE::InputPeer* peer, TArray<int32> id, bool increment);

	~GetMessagesViews();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPeer* peer;
	 TArray<int32> id;
	 bool increment;
	TArray<int32> result;
};
} //end namespace block
