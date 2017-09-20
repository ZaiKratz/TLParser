#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"

//begin namespace block
namespace MESSAGES
{
class ToggleDialogPin : public TLBaseObject
{
public:
	ToggleDialogPin();
	ToggleDialogPin(bool pinned, PRIVATE::InputPeer* peer);

	~ToggleDialogPin();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool pinned;
	 PRIVATE::InputPeer* peer;
	bool result;
};
} //end namespace block
