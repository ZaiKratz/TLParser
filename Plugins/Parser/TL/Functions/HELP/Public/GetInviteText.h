#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Help/Public/InviteText.h"

//begin namespace block
namespace HELP
{
class GetInviteText : public TLBaseObject
{
public:
	GetInviteText();
	~GetInviteText();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	HELP::InviteText* result;
};
} //end namespace block
