#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/PeerDialogs.h"

//begin namespace block
namespace MESSAGES
{
class GetPinnedDialogs : public TLBaseObject
{
public:
	GetPinnedDialogs();
	~GetPinnedDialogs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	MESSAGES::PeerDialogs* result;
};
} //end namespace block
