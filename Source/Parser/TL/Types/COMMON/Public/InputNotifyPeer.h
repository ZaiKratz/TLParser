#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputNotifyPeer : public TLBaseObject
{
public:
	InputNotifyPeer();
	InputNotifyPeer(TLBaseObject* peer);

	~InputNotifyPeer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

private:
	TLBaseObject* peer;
};
} //end namespace block
