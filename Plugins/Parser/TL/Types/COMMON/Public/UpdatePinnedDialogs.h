#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Peer.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdatePinnedDialogs : public PRIVATE::Update
{
public:
	UpdatePinnedDialogs();
	UpdatePinnedDialogs(TArray<PRIVATE::Peer*> order);

	~UpdatePinnedDialogs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<PRIVATE::Peer*> order;
};
} //end namespace block
