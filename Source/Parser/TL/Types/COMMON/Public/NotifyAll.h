#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/NotifyPeer.h"

//begin namespace block
namespace COMMON
{
class NotifyAll : public TLBaseObject
{
public:
	NotifyAll();
	~NotifyAll();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
