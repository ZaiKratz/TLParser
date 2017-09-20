#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputPeer.h"

#include "../../../Types/Private/InputPeer.h"

//begin namespace block
namespace COMMON
{
class InputPeerSelf : public PRIVATE::InputPeer
{
public:
	InputPeerSelf();
	~InputPeerSelf();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
