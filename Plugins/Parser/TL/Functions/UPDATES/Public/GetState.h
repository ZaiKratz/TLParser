#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Updates/Public/State.h"

//begin namespace block
namespace UPDATES
{
class GetState : public TLBaseObject
{
public:
	GetState();
	~GetState();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	UPDATES::State* result;
};
} //end namespace block
