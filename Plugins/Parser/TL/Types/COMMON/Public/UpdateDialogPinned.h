#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Peer.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateDialogPinned : public PRIVATE::Update
{
public:
	UpdateDialogPinned();
	UpdateDialogPinned(bool pinned, PRIVATE::Peer* peer);

	~UpdateDialogPinned();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool pinned;
	 PRIVATE::Peer* peer;
};
} //end namespace block
