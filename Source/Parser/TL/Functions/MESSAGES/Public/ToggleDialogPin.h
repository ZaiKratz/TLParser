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

	bool Getpinned() const
	{
		 return this->pinned;
	}

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool pinned;
	 PRIVATE::InputPeer* peer;
	bool result;
};
} //end namespace block
