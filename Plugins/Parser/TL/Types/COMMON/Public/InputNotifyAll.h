#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputNotifyPeer.h"

//begin namespace block
namespace COMMON
{
class InputNotifyAll : public TLBaseObject
{
public:
	InputNotifyAll();
	~InputNotifyAll();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
