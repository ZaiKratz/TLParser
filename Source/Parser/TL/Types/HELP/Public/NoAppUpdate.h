#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Help/Public/AppUpdate.h"

//begin namespace block
namespace HELP
{
class NoAppUpdate : public TLBaseObject
{
public:
	NoAppUpdate();
	~NoAppUpdate();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
