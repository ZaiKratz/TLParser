#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"

//begin namespace block
namespace COMMON
{
class InputNotifyPeer : public TLBaseObject
{
public:
	InputNotifyPeer();
	InputNotifyPeer(PRIVATE::InputPeer* peer);

	~InputNotifyPeer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

private:
	PRIVATE::InputPeer* peer;
};
} //end namespace block
