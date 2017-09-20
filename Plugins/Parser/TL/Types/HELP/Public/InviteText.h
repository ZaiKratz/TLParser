#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace HELP
{
class InviteText : public TLBaseObject
{
public:
	InviteText();
	InviteText(FString message);

	~InviteText();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString message;
};
} //end namespace block
